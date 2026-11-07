import os
import sys

import pytest

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
sys.path.insert(0, os.path.join(ROOT, "saturn-recomp", "src"))
import draft  # noqa: E402
import gen  # noqa: E402
import machine  # noqa: E402
import modules  # noqa: E402
import status  # noqa: E402


@pytest.mark.parametrize("name, base, prefix, folder", [
    pytest.param("KRNL", 0x06006000, "", "src", id="the default module"),
    pytest.param("BOOT", 0x06010000, "boot_", os.path.join("src", "boot"), id="a module over KRNL's addresses"),
    pytest.param("FLD", 0x00200000, "fld_", os.path.join("src", "fld"), id="a module in the second work RAM"),
])
def test_a_module_has_its_base_prefix_and_folder_of_c(name, base, prefix, folder):
    module = modules.load(name)
    assert (module.base, module.prefix, module.src) == (base, prefix, os.path.join(ROOT, "decomp", folder))


def test_the_environment_names_the_module_the_tools_work_on(monkeypatch):
    monkeypatch.delenv("DECOMP_MODULE", raising=False)
    assert modules.current().name == "KRNL"
    monkeypatch.setenv("DECOMP_MODULE", "IP")
    assert modules.current().name == "IP"


def test_a_module_game_toml_does_not_have_is_refused():
    with pytest.raises(SystemExit, match="no module NOPE"):
        modules.load("NOPE")


def test_a_function_of_another_module_is_wrapped_under_the_modules_prefix():
    sig = gen.Signature(0x06010510, "int", ["int"], prefix="boot_")
    assert gen.wrapper(sig) == "void swap_boot_f06010510(SH2Context& c) { InSwap in(c); c.r[0] = (uint32_t)boot_f06010510((int)c.r[4]); }"
    assert gen.declaration(sig) == "int boot_f06010510(int);"


def test_the_replace_block_names_the_other_modules_wrappers():
    block = gen.render_block([0x06006B38], [("BOOT", 0x06010510)])
    assert 'module = "KRNL"\nat = 0x06006B38\nsymbol = "swap_f06006B38"' in block
    assert 'module = "BOOT"\nat = 0x06010510\nsymbol = "swap_boot_f06010510"' in block


def test_the_names_header_defines_every_function_the_c_of_a_module_names(tmp_path, monkeypatch):
    (tmp_path / "boot_0601.c").write_text("int f06010510(void) { return f06010520(); }\nint f06010520(void) { return 0; }\n")
    monkeypatch.setattr(modules.Module, "src", property(lambda self: str(tmp_path)))
    assert "#define f06010510 boot_f06010510\n#define f06010520 boot_f06010520\n" in gen.render_names(modules.load("BOOT"))


def test_a_source_file_is_named_after_its_module_and_the_top_half_of_the_address(monkeypatch):
    monkeypatch.setenv("DECOMP_MODULE", "BOOT")
    assert os.path.basename(status.source_for(0x06010510)) == "boot_0601.c"
    monkeypatch.setenv("DECOMP_MODULE", "FLD")
    assert os.path.basename(status.source_for(0x002001BE)) == "fld_0020.c"


def test_the_interpreter_loads_a_module_based_in_the_second_work_ram(tmp_path):
    file = tmp_path / "fld.bin"
    file.write_bytes(bytes([0x00, 0x09]))
    cpu = machine.load(str(file), machine.WRAML)
    assert cpu.mem.read(machine.WRAML, 2) == 0x0009 and cpu.mem.read(machine.WRAM, 2) == 0


def test_the_drafts_of_chunks_are_placed_in_the_files_of_the_module(tmp_path, monkeypatch):
    monkeypatch.setenv("DECOMP_MODULE", "IP")
    monkeypatch.setattr(modules.Module, "src", property(lambda self: str(tmp_path / "src")))
    chunks = tmp_path / "chunks"
    chunks.mkdir()
    (chunks / "0.out").write_text("#### 06002348 ok\nvoid f06002348(void)\n{\n}\n#### 06002100 refused: a jump table\n")
    assert draft.place(str(chunks)) == {0x06002100: "a jump table"}
    assert "void f06002348(void)" in (tmp_path / "src" / "ip_0600.c").read_text()
    assert draft.place(str(chunks)) == {0x06002100: "a jump table"}
    assert (tmp_path / "src" / "ip_0600.c").read_text().count("void f06002348(void)") == 1


def test_a_function_made_void_keeps_its_body_and_returns_nothing():
    import voidify
    text = "int f06010820(int r4)\n{\n    int r0;\n\n    r0 = GCALL2(0x060106BC, r4, 1);\n    return r0;\n}\n\nint f06010830(void)\n{\n    return 1;\n}\n"
    assert voidify.voidify(text, 0x06010820) == text.replace("int f06010820", "void f06010820").replace("return r0;", "return;")


@pytest.mark.parametrize("params, body, expected", [
    pytest.param("int r4, int r5", "    r1 = LD32(r4 + 20);\n    ST16((r5 + 2), r1);\n", (0, 1), id="loads and stores"),
    pytest.param("int r4, int r5", "    r1 = LD32(0x340 + r4);\n    return r1 + r5;\n", (0,), id="an offset before the base"),
    pytest.param("int r4, int r5", "    v4 = r4;\n    r1 = LD16(v4);\n", (0,), id="a copy of the parameter"),
    pytest.param("int r4", "    r1 = LD32(0x0600);\n    return r1 + r4;\n", (), id="a parameter outside the address"),
    pytest.param("void", "    return 0;\n", (), id="no parameters"),
])
def test_a_parameter_the_body_loads_or_stores_through_is_addressed(params, body, expected):
    assert gen.addressed(params, body) == expected

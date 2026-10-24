import os
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(ROOT, "decomp"))
import merge  # noqa: E402

FILE = '''#include "krnl.h"

#define LIMIT 4

void f06006100(void)
{
    ST8(0x060C0000, 1);
}

/* the second */
int f06006200(int n)
{
    return n;
}
'''


def test_a_new_function_goes_in_address_order():
    text = merge.merge(FILE, {0x06006150: "void f06006150(void)\n{\n}\n"})
    assert text.index("f06006100") < text.index("f06006150") < text.index("f06006200")


def test_a_function_replaces_the_one_at_its_address_and_keeps_what_lay_before_it():
    text = merge.merge(FILE, {0x06006100: "void f06006100(void)\n{\n    ST8(0x060C0000, 2);\n}\n"})
    assert "#define LIMIT 4" in text and "ST8(0x060C0000, 2);" in text and "ST8(0x060C0000, 1);" not in text


def test_a_replacement_brings_its_own_comment_and_drops_the_old_one():
    text = merge.merge(FILE, {0x06006200: "/* now the third */\nint f06006200(int n)\n{\n    return n + 1;\n}\n"})
    assert "/* now the third */" in text and "/* the second */" not in text and text.count("f06006200") == 1


def test_a_comment_above_a_function_stays_with_it_when_another_goes_in_before_it():
    text = merge.merge(FILE, {0x06006150: "void f06006150(void)\n{\n}\n"})
    assert text.index("/* the second */") + len("/* the second */\n") == text.index("int f06006200")


def test_merging_nothing_changes_nothing():
    assert merge.merge(FILE, {}) == FILE


def test_a_worker_file_gives_its_definitions_and_the_rest_apart():
    other, defined = merge.functions('#include "krnl.h"\n\ntypedef struct { int a; } T;\n\n' + FILE.split("\n\n", 2)[2])
    assert sorted(defined) == [0x06006100, 0x06006200] and "typedef struct" in other and "f06006100" not in other


def test_a_file_with_no_function_yet_takes_the_first():
    assert merge.merge('#include "krnl.h"\n', {0x06006100: "void f06006100(void)\n{\n}\n"}).endswith("void f06006100(void)\n{\n}\n")

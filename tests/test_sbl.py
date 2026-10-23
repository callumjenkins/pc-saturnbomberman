import csv
import os

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def rows(name: str) -> list[dict[str, str]]:
    with open(os.path.join(ROOT, "decomp", name), encoding="utf-8", newline="") as f:
        return list(csv.DictReader(f, delimiter="\t"))


def test_every_sbl_match_is_the_name_of_its_function_in_the_status_table():
    named = {row["address"]: row["name"].split("/") for row in rows("status.tsv") if row["module"] == "KRNL"}
    missing = [row["name"] for row in rows("sbl.tsv") if row["name"] not in named.get(row["address"], [])]
    assert missing == []


def test_no_sbl_match_is_below_nine_tenths_alike():
    assert all(0.9 <= float(row["similarity"]) <= 1.0 for row in rows("sbl.tsv"))

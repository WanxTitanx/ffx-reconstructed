#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Spot-verify bin_ps3psv classifications: decode diff regions of selected
pairs (obj_ps3 = 'a' vs obj_psv = 'b') with ±context, using the same
decoder/index parser as bin_ps3psv_diff.py."""
import difflib
import os
import sys

sys.path.insert(0, "/home/wanderson/Documents/ffx-editor-main/research_tools/QA")
import bin_ps3psv_diff as B

CANDS = [
    ("new_uspc", "azit0600", "VITA_SAVEWARN"),
    ("new_depc", "maca0100", "VITA_SAVEWARN"),
    ("new_chpc", "azit0600", "INSERT_TEXT/VITA_SAVEWARN-mech"),
    ("new_chpc", "azit0700", "TEXT_EDIT/VITA_SAVEWARN-mech"),
    ("new_uspc", "luca0100", "PLAYGO_STUB"),
    ("new_uspc", "bika0300", "PLAYGO_STUB"),
    ("new_depc", "kino0700", "STUB_ON_PS3 (inverted)"),
    ("new_uspc", "lchb1200", "SNDTRK_REMOVED"),
    ("new_uspc", "test20",    "SNDTRK_REMOVED"),
    ("new_uspc", "bltz0201", "ICON_PARAM"),
    ("new_uspc", "bltz0200", "TEXT_EDIT w/ point diffs"),
    ("new_uspc", "bika0100", "TEXT_EDIT"),
    ("new_uspc", "genk0600", "INSERT_TEXT"),
    ("new_depc", "bika0400", "INSERT_TEXT"),
    ("new_uspc", "kami0000", "DELETE_TEXT"),
    ("new_uspc", "nagi0000", "MINIGAME_HUD"),
    ("new_sppc", "lchb1200", "SNDTRK_REMOVED (sp)"),
]

CTX = 48  # bytes of equal context shown around each hunk


def rel_for(tree, name):
    return f"event/obj_ps3/{name[:2]}/{name}/{name}.bin", \
           f"event/obj_psv/{name[:2]}/{name}/{name}.bin"


def show(tree, name, note):
    rel3, rel5 = rel_for(tree, name)
    loc = B.TREE2LOC[tree]
    dloc = "us" if loc in ("de", "fr", "it", "sp") else loc
    a = open(os.path.join(B.ROOT, tree, rel3), "rb").read()
    b = open(os.path.join(B.ROOT, tree, rel5), "rb").read()
    ia, ib = B.parse_index(a), B.parse_index(b)
    print("=" * 100)
    print(f"{tree} {name}  [{note}]   ps3={len(a)}B psv={len(b)}B "
          f"idx_ps3={ia[0] if ia else '?'} idx_psv={ib[0] if ib else '?'}")
    if not (ia and ib):
        print("  NON pair-format"); return
    idxA, idxB = ia[0], ib[0]
    # index entry diffs (logical)
    la = [f"{e & 0xFFFF:04x}|{e >> 16:04x}" for e in ia[1]]
    lb = [f"{e & 0xFFFF:04x}|{e >> 16:04x}" for e in ib[1]]
    smi = difflib.SequenceMatcher(None, la, lb, autojunk=False)
    idx_diffs = [op for op in smi.get_opcodes() if op[0] != "equal"]
    if idx_diffs:
        print("  index-entry diffs (off|flag):")
        for tag, i1, i2, j1, j2 in idx_diffs[:8]:
            print(f"    {tag} a[{i1}:{i2}]={la[i1:i2][:4]} -> "
                  f"b[{j1}:{j2}]={lb[j1:j2][:4]}")
    pay_a, pay_b = a[idxA:], b[idxB:]
    sm = difflib.SequenceMatcher(None, pay_a, pay_b, autojunk=False)
    for tag, i1, i2, j1, j2 in sm.get_opcodes():
        if tag == "equal":
            continue
        pre_a = B.decode(pay_a[max(0, i1 - CTX):i1], dloc)
        post_a = B.decode(pay_a[i2:i2 + CTX], dloc)
        seg_a = B.decode(pay_a[i1:i2], dloc)
        seg_b = B.decode(pay_b[j1:j2], dloc)
        print(f"  -- {tag} a@{idxA + i1}+{i2 - i1}  b@{idxB + j1}+{j2 - j1}")
        print(f"     ctxA: ...{pre_a} ⮞HERE⮜ {post_a}...")
        print(f"     PS3 : {seg_a!r}")
        print(f"     PSV : {seg_b!r}")


for tree, name, note in CANDS:
    try:
        show(tree, name, note)
    except OSError as e:
        print(f"{tree} {name}: {e}")

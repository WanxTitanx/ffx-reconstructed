#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""y5_b24_gate_rerun.py — X5 tier-B pass-3 lane (2026-09-16): re-run the b24
gates with the versioned validator research_tools/Task11Y5/
y5_batcher_validate_tierb.py UNMODIFIED, under the post-ab0ce2d0 environment.

Why this harness exists
-----------------------
Commit ab0ce2d0 (work/ -> research_tools/ migration, 2026-09-16) link-rewrote
the working-tree atlas docs/reverse/FFX_STRUCTURE_COMPLETE_2026-08-17.md; it
now hashes 9947FE02... and no longer matches the chain pin F5439414.... The
versioned b24 validator reads that working-tree path and would FATAL on the
pin check. This harness loads the versioned module and repoints ONLY the
module-level ATLAS_PATH constant to the pinned bytes (sha-verified
F5439414..., identical to the committed copy
artifacts/2026-09-14/qa-win/FFX_STRUCTURE_COMPLETE_2026-08-17.md). Every check
in the battery is the versioned code, unmodified.

Usage:
  python3 y5_b24_gate_rerun.py                      # draft gate
  python3 y5_b24_gate_rerun.py --candidate <path>   # + promotion gate
"""
import importlib.util
import sys

REPO = "/home/wanderson/Documents/ffx-editor-main"
VALIDATOR = f"{REPO}/research_tools/Task11Y5/y5_batcher_validate_tierb.py"
PINNED_ATLAS = (f"{REPO}/work/_x5_tierb3/pins/"
                f"FFX_STRUCTURE_COMPLETE_2026-08-17.F5439414.md")


def main() -> int:
    spec = importlib.util.spec_from_file_location(
        "y5_batcher_validate_tierb", VALIDATOR)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    # repoint the atlas pin; all other constants (ART=nvme mirror, SEED,
    # QUEUE, B24) keep their versioned values
    mod.ATLAS_PATH = PINNED_ATLAS
    return mod.main()


if __name__ == "__main__":
    sys.exit(main())

#!/usr/bin/env python3
"""survey_comments_canon.py — survey na CANONICA (com qexit)."""
import sys

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe")
import survey_comments  # noqa: E402

if __name__ == "__main__":
    survey_comments.main()
    import ida_pro
    ida_pro.qexit(0)

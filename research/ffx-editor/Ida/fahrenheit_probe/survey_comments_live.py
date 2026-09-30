#!/usr/bin/env python3
"""survey_comments_live.py — survey na COPY aberta (sem qexit)."""
import sys

sys.path.insert(0, r"C:\Users\wande\Documents\ffx-editor-main\work\_fahrenheit_probe")
import ida_pro  # noqa: E402

ida_pro.qexit = lambda code: print(f"(qexit ignorado: {code})", flush=True)
import survey_comments  # noqa: E402

if __name__ == "__main__":
    survey_comments.main()
    print("SURVEY LIVE OK", flush=True)

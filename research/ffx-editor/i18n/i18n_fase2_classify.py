#!/usr/bin/env python3
"""Classify Fase-2 i18n migration items into safe-to-automate vs needs-review.

Reads work/i18n_s*_result.json. For each item with text != en:
  - locates the literal in the source file (by content near reported line)
  - classifies:
      AUTO   -> log literal, no {..} format, text != en: direct EN swap, pure literal.
      UI-KEY -> ui literal -> needs a Strings.* key + resx entry (slower, per-item).
      REVIEW -> ambiguous (string.Format / interpolation braces / inside path / dup).
Writes a JSON report. READ-ONLY — never edits source.
"""
import json, glob, os, re, sys, collections

sys.stdout.reconfigure(encoding="utf-8")
OUT = r"C:\Users\wande\Documents\ffx-editor-main\work\i18n_fase2_classify.json"

def has_fmt_braces(t):
    # string.Format tokens {0} or interpolation braces {x}
    return bool(re.search(r"\{[0-9a-zA-Z_\.\?]+\}", t))

def load_files():
    d = []
    for fp in glob.glob(r"C:\Users\wande\Documents\ffx-editor-main\work\i18n_s*_result.json"):
        d.extend(json.load(open(fp, encoding="utf-8")))
    return d

def main():
    data = load_files()
    report = {"AUTO": [], "UI_KEY": [], "REVIEW": [], "ALREADY_EN": []}
    for it in data:
        txt, en = it.get("text",""), it.get("en","")
        typ = it.get("type")
        if txt == en:
            report["ALREADY_EN"].append(it); continue
        f = it.get("file").replace("/", os.sep)
        full = os.path.join(r"C:\Users\wande\Documents\ffx-editor-main", f)
        exists = os.path.exists(full)
        line = int(it.get("line",0))
        hit_line = None
        if exists:
            lines = open(full, encoding="utf-8").read().splitlines()
            # prefer exact-line hit, else first file-wide hit with the literal
            if 1 <= line <= len(lines) and txt in lines[line-1]:
                hit_line = line
            else:
                for i,l in enumerate(lines,1):
                    if txt in l:
                        hit_line = i; break
        rec = dict(file=it["file"], line=line, text=txt, en=en, type=typ,
                   exists=exists, hit_line=hit_line)
        risk = not exists or hit_line is None or has_fmt_braces(txt) or has_fmt_braces(en)
        is_ui = (typ == "ui")
        if risk:
            report["REVIEW"].append(rec)
        elif is_ui:
            report["UI_KEY"].append(rec)
        else:
            report["AUTO"].append(rec)

    with open(OUT, "w", encoding="utf-8") as f:
        json.dump(report, f, ensure_ascii=False, indent=1)
    for k in ("AUTO","UI_KEY","REVIEW","ALREADY_EN"):
        print(f"{k}: {len(report[k])}")
    # per-topic breakdown for the REVIEW bucket
    rev_types = collections.Counter((r["type"], not r["exists"], r["hit_line"] is None,
                                     has_fmt_braces(r["text"])) for r in report["REVIEW"])
    print("\nREVIEW reasons (type,missing-file,no-literal,fmt-braces):")
    for k,v in rev_types.most_common():
        print("  ", k, v)

if __name__ == "__main__":
    main()

#!/bin/bash
# Batch py_compile of all .py in the 3 target dirs; results to TSV
OUT=/home/wanderson/Documents/ffx-editor-main/work/_val_bmsq/pycompile_results.tsv
: > "$OUT"
for dir in BattleMap Save QA; do
  while IFS= read -r f; do
    if python3 -m py_compile "$f" 2>/tmp/pyc_err.txt; then
      echo -e "$f\tOK" >> "$OUT"
    else
      echo -e "$f\tFAIL\t$(head -c 300 /tmp/pyc_err.txt | tr '\n' ' ' | tr -d '\t')" >> "$OUT"
    fi
  done < <(find /home/wanderson/Documents/ffx-editor-main/research_tools/$dir -name "*.py" -type f | sort)
done
echo "=== TOTALS ==="
cut -f2 "$OUT" | sort | uniq -c
echo "=== FAILURES ==="
grep -P "\tFAIL" "$OUT" || echo "(none)"

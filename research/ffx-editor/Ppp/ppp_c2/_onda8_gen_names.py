import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# ONDA 8 (GOAL 8h): gera o catálogo embutido de nomes de efeitos (589 nomes)
# no MagicEffectNameCatalog — fallback offline em produção (sem work/).
d = json.load(open(r"work/noclip_reference/magic_id_names_pc_20260731.json", encoding="utf-8"))

# normaliza: "magic_0003.dll" -> ("0003", "Cheer")
entries = []
for dll, meta in sorted(d.items()):
    name = (meta.get("name_ps2") or "").strip() if isinstance(meta, dict) else str(meta).strip()
    if not name:
        continue
    id_part = dll.replace("magic_", "").replace(".dll", "").lstrip("0") or "0"
    entries.append((id_part, name))

lines = []
for id_part, name in entries:
    esc = name.replace("\\", "\\\\").replace("\"", "\\\"")
    lines.append(f'            {{ "{id_part}", "{esc}" }},')

body = "\n".join(lines)
content = f'''using System;
using System.Collections.Generic;

namespace FFXProjectEditor.Modules.MagicDllEditor
{{
    /// <summary>
    /// Catálogo embutido de nomes de efeitos (fonte noclip.website, 2026-07-31).
    /// Fallback offline do JSON em work/noclip_reference/ (gitignored) — garante que o
    /// editor resolva nomes ("Power Break", "Cheer"...) mesmo em produção sem a pasta work.
    /// Gerado por work/ppp_c2/_onda8_gen_names.py em 2026-08-02 ({len(entries)} nomes).
    /// </summary>
    internal static partial class MagicEffectNameCatalog
    {{
        private static readonly IReadOnlyDictionary<string, string> EmbeddedNames =
            new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase)
            {{
{body}
            }};
    }}
}}
'''
out = r"FFXProjectEditor/Modules/MagicDllEditor/MagicEffectNameCatalog.Embedded.cs"
open(out, "w", encoding="utf-8", newline="\n").write(content)
print(f"gerado: {out} ({len(entries)} nomes)")

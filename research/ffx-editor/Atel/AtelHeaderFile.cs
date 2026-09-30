// ============================================================================
// AtelHeaderFile — reference parser for FFX2/FFX PS2 `.ath` / `.atd` ATEL headers
// PURPOSE : parse the TEXT `.ath` C-header files that define ATEL function/command
//           IDs (btlatel.ath, atelcam.ath, command.ath, monmagic.ath, monster.ath,
//           item.ath, a_ability.ath, btlmap.ath, btlmapalias.ath, btlmot.ath, ...)
//           and expose the name <-> ID mapping plus namespace math.
// WHY     : the editor has NO real .ath parser — MonsterAthAnimCatalog is a static
//           data table imported from the Fahrenheit project (LGPL), not a parser.
//           This file is the standalone reference implementation (research only).
// EVIDENCE: docs/reverse/FFX_ATEL_HEADERS_ATH_ATD_2026-08-19.md; real files at
//           D:\FFX Extracted\FFX2\ffx_ps2\ffx2\master\jppc\battle\header\*.ath
//           and D:\FFX Extracted\FFX2\ffx_ps2\ffx2\master\jppc\lastmiss\kernel\*.ath.
// MAINT   : self-contained (no editor deps). Namespace mirrors the FfxLib convention
//           used by the other work/research_tools/* files. Do NOT move into
//           FFXProjectEditor/ — this is a research artifact, not product code.
// ============================================================================
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;

namespace FFXProjectEditor.FfxLib.Atel
{
    /// <summary>
    /// One parsed entry of an ATEL header file.
    /// </summary>
    public sealed record AtelHeaderEntry
    {
        /// <summary>Symbol name as written in the file (may contain Japanese, e.g. "pcom_アイテム").</summary>
        public string Name { get; init; } = "";

        /// <summary>Full ATEL id (namespace &lt;&lt; 12 | index). Null for pure aliases and guard defines.</summary>
        public int? Id { get; init; }

        /// <summary>Namespace = id &gt;&gt; 12 (the funcspace). Null when no id.</summary>
        public int? Namespace { get; init; }

        /// <summary>Index within the namespace = id &amp; 0xFFF. Null when no id.</summary>
        public int? Index { get; init; }

        /// <summary>True when the line was a #alias or a #define whose value is another symbol (camera.ath lowercase aliases).</summary>
        public bool IsAlias { get; init; }

        /// <summary>For aliases: the target symbol name. Null otherwise.</summary>
        public string? AliasTarget { get; init; }

        /// <summary>Trailing // comment text (often the Japanese description), stripped of the marker.</summary>
        public string? Comment { get; init; }

        /// <summary>1-based source line number.</summary>
        public int SourceLine { get; init; }

        /// <summary>Raw trimmed line as it appears in the file.</summary>
        public string RawLine { get; init; } = "";

        /// <summary>True when the id was COMPUTED from a funcspace function declaration (btlatel.ath style).</summary>
        public bool IsComputedId { get; init; }

        /// <summary>True when the id was EXPLICIT in a #define (command.ath style).</summary>
        public bool IsExplicitId { get; init; }

        public override string ToString() =>
            Id.HasValue ? $"{Name} = 0x{Id.Value:X5} (ns {Namespace}, idx {Index})" : $"{Name} (no id)";
    }

    /// <summary>
    /// Parsed representation of one `.ath` header file.
    /// </summary>
    public sealed class AtelHeaderFile
    {
        /// <summary>All entries in file order.</summary>
        public List<AtelHeaderEntry> Entries { get; } = new();

        /// <summary>Source path (empty when parsed from a string).</summary>
        public string SourcePath { get; set; } = "";

        /// <summary>funcspace values seen in order (e.g. [7] for btlatel.ath, [6] for atelcam.ath).</summary>
        public List<int> Funcspaces { get; } = new();

        /// <summary>Count of entries that carry an id (explicit or computed).</summary>
        public int IdCount => Entries.Count(e => e.Id.HasValue);

        /// <summary>Count of alias entries.</summary>
        public int AliasCount => Entries.Count(e => e.IsAlias);

        /// <summary>Entries grouped by namespace (id &gt;&gt; 12).</summary>
        public Dictionary<int, List<AtelHeaderEntry>> ByNamespace =>
            Entries.Where(e => e.Namespace.HasValue)
                   .GroupBy(e => e.Namespace!.Value)
                   .ToDictionary(g => g.Key, g => g.ToList());

        /// <summary>Lookup name -&gt; entry (case-insensitive).</summary>
        public Dictionary<string, AtelHeaderEntry> ByName =>
            Entries.Where(e => e.Name.Length > 0)
                   .GroupBy(e => e.Name, StringComparer.OrdinalIgnoreCase)
                   .ToDictionary(g => g.Key, g => g.First(), StringComparer.OrdinalIgnoreCase);

        /// <summary>Lookup id -&gt; entry.</summary>
        public Dictionary<int, AtelHeaderEntry> ById =>
            Entries.Where(e => e.Id.HasValue)
                   .GroupBy(e => e.Id!.Value)
                   .ToDictionary(g => g.Key, g => g.First());

        /// <summary>Resolve a symbol name to its full ATEL id, or null when unknown.</summary>
        public int? Resolve(string name) =>
            ByName.TryGetValue(name, out AtelHeaderEntry? e) ? e.Id : null;

        /// <summary>Resolve a full ATEL id (e.g. 0x7001) to its symbol name, or null.</summary>
        public string? ResolveId(int id) =>
            ById.TryGetValue(id, out AtelHeaderEntry? e) ? e.Name : null;

        // ── Parsing ────────────────────────────────────────────────────────────

        /// <summary>Parse an .ath file from disk. Returns null on I/O failure.</summary>
        public static AtelHeaderFile? ParseFile(string path)
        {
            try { return ParseText(File.ReadAllText(path), path); }
            catch { return null; }
        }

        /// <summary>
        /// Parse .ath text. Handles both dialects found in the game:
        ///  (1) funcspace function-list (btlatel.ath / atelcam.ath): id = funcspace&lt;&lt;12 | index-in-list
        ///  (2) #define constant list (command.ath / monmagic.ath / monster.ath / item.ath / ...):
        ///      explicit hex/decimal ids, parenthesized values, and symbol aliases.
        /// Also handles #alias lines (btlmapalias.ath) and skips guards/includes/local blocks.
        /// </summary>
        public static AtelHeaderFile ParseText(string text, string sourcePath = "")
        {
            var file = new AtelHeaderFile { SourcePath = sourcePath };
            int currentFuncspace = 0;
            int funcspaceIndex = 0;          // running index within the current funcspace
            bool inLocalBlock = false;       // local { ... } blocks in .src files
            bool inLineBlock = false;        // line NAME { ... } blocks in .src files

            string[] lines = text.Replace("\r\n", "\n").Split('\n');
            for (int i = 0; i < lines.Length; i++)
            {
                string raw = lines[i];
                string line = StripComment(raw, out string? comment);
                string trimmed = line.Trim();
                int lineNo = i + 1;
                if (trimmed.Length == 0) continue;

                // Block state machine for .src files (local { } / line NAME { })
                if (trimmed.StartsWith("local", StringComparison.Ordinal) && trimmed.Contains("{"))
                { inLocalBlock = true; continue; }
                if (trimmed.StartsWith("line", StringComparison.Ordinal) && trimmed.Contains("{"))
                { inLineBlock = true; continue; }
                if (trimmed == "}")
                { inLocalBlock = false; inLineBlock = false; continue; }
                if (inLocalBlock || inLineBlock) continue;

                // Preprocessor guards / includes — skip, but track funcspace changes.
                if (trimmed.StartsWith("#ifndef", StringComparison.Ordinal) ||
                    trimmed.StartsWith("#ifdef", StringComparison.Ordinal) ||
                    trimmed.StartsWith("#if ", StringComparison.Ordinal) ||
                    trimmed.StartsWith("#else", StringComparison.Ordinal) ||
                    trimmed.StartsWith("#endif", StringComparison.Ordinal) ||
                    trimmed.StartsWith("#include", StringComparison.Ordinal) ||
                    trimmed.StartsWith("#pragma", StringComparison.Ordinal))
                    continue;

                // funcspace N — switches the namespace for subsequent function declarations.
                Match fs = Regex.Match(trimmed, @"^funcspace\s+([0-9A-Fa-fx]+)\s*$");
                if (fs.Success)
                {
                    currentFuncspace = ParseInt(fs.Groups[1].Value);
                    funcspaceIndex = 0;
                    file.Funcspaces.Add(currentFuncspace);
                    continue;
                }

                // #alias name target  (btlmapalias.ath)
                Match al = Regex.Match(trimmed, @"^#alias\s+(\S+)\s+(\S+)\s*$");
                if (al.Success)
                {
                    file.Entries.Add(new AtelHeaderEntry
                    {
                        Name = al.Groups[1].Value,
                        IsAlias = true,
                        AliasTarget = al.Groups[2].Value,
                        Comment = comment,
                        SourceLine = lineNo,
                        RawLine = raw.Trim(),
                    });
                    continue;
                }

                // #define NAME VALUE
                Match def = Regex.Match(trimmed, @"^#define\s+(\S+)\s*(.*)$");
                if (def.Success)
                {
                    string name = def.Groups[1].Value;
                    string value = def.Groups[2].Value.Trim();

                    // Guard-style define with no value (e.g. #define __ATEL_FUNCTION_LIST_7__) — skip.
                    if (value.Length == 0) continue;

                    // Strip surrounding parentheses: ( 0x1fc35513 ) / ( 1025 )
                    string inner = value;
                    if (inner.StartsWith("(", StringComparison.Ordinal) && inner.EndsWith(")", StringComparison.Ordinal))
                        inner = inner.Substring(1, inner.Length - 2).Trim();

                    if (TryParseInt(inner, out int id))
                    {
                        file.Entries.Add(new AtelHeaderEntry
                        {
                            Name = name,
                            Id = id,
                            Namespace = id >> 12,
                            Index = id & 0xFFF,
                            IsExplicitId = true,
                            Comment = comment,
                            SourceLine = lineNo,
                            RawLine = raw.Trim(),
                        });
                    }
                    else
                    {
                        // Value is another symbol → alias (camera.ath: #define camsleep camSleep).
                        file.Entries.Add(new AtelHeaderEntry
                        {
                            Name = name,
                            IsAlias = true,
                            AliasTarget = inner,
                            Comment = comment,
                            SourceLine = lineNo,
                            RawLine = raw.Trim(),
                        });
                    }
                    continue;
                }

                // Function declaration in a funcspace list:  int btlTerminateAction(); / float btlGetWater();
                Match fn = Regex.Match(trimmed, @"^(int|float|void|char|short|long)\s+([A-Za-z_][A-Za-z0-9_]*)\s*\(");
                if (fn.Success)
                {
                    int id = (currentFuncspace << 12) | (funcspaceIndex & 0xFFF);
                    file.Entries.Add(new AtelHeaderEntry
                    {
                        Name = fn.Groups[2].Value,
                        Id = id,
                        Namespace = currentFuncspace,
                        Index = funcspaceIndex & 0xFFF,
                        IsComputedId = true,
                        Comment = comment,
                        SourceLine = lineNo,
                        RawLine = raw.Trim(),
                    });
                    funcspaceIndex++;
                    continue;
                }

                // Unknown line — record nothing (keeps parser resilient to .src boilerplate).
            }

            return file;
        }

        // ── Helpers ────────────────────────────────────────────────────────────

        /// <summary>Strip a trailing // comment, returning the code part and the comment text.</summary>
        static string StripComment(string line, out string? comment)
        {
            int idx = line.IndexOf("//", StringComparison.Ordinal);
            if (idx < 0) { comment = null; return line; }
            comment = line.Substring(idx + 2).Trim();
            return line.Substring(0, idx);
        }

        static bool TryParseInt(string s, out int value)
        {
            s = s.Trim();
            if (s.StartsWith("0x", StringComparison.OrdinalIgnoreCase))
                return int.TryParse(s.Substring(2), System.Globalization.NumberStyles.HexNumber, null, out value);
            return int.TryParse(s, out value);
        }

        static int ParseInt(string s) => TryParseInt(s, out int v) ? v : 0;

        // ── Verification ───────────────────────────────────────────────────────

        /// <summary>
        /// Self-test against the real game files. Returns a human-readable report.
        /// Pass the battle/header directory of the FFX2 extraction, e.g.
        /// "D:\FFX Extracted\FFX2\ffx_ps2\ffx2\master\jppc\battle\header".
        /// </summary>
        public static string SelfTest(string battleHeaderDir)
        {
            var sb = new System.Text.StringBuilder();
            string[] files = { "btlatel.ath", "atelcam.ath", "command.ath", "monmagic.ath",
                               "monster.ath", "item.ath", "ply_save.ath", "setype.ath",
                               "btlmot.ath", "btlmap.ath", "btlmapalias.ath", "camera.ath" };
            foreach (string f in files)
            {
                string path = Path.Combine(battleHeaderDir, f);
                AtelHeaderFile? h = ParseFile(path);
                if (h == null) { sb.AppendLine($"{f}: PARSE FAILED"); continue; }
                sb.AppendLine($"{f}: {h.IdCount} ids, {h.AliasCount} aliases, funcspaces [{string.Join(",", h.Funcspaces)}]");
                if (h.Entries.Any(e => e.Id.HasValue))
                {
                    var first = h.Entries.First(e => e.Id.HasValue);
                    var last = h.Entries.Last(e => e.Id.HasValue);
                    sb.AppendLine($"    first: {first.Name} = 0x{first.Id:X5}   last: {last.Name} = 0x{last.Id:X5}");
                }
                else if (h.Entries.Count > 0)
                {
                    sb.AppendLine($"    first: {h.Entries[0].Name} (alias -> {h.Entries[0].AliasTarget})");
                }
            }
            return sb.ToString();
        }
    }
}

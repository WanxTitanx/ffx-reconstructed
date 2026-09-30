using System;
using System.Linq;
using ResearchTools.Menu;

class Program
{
    // FIX 2026-09-15 (VALIDADOR-Restantes): optional CLI override of the corpus
    // base dir (arg 0) so the tool can run on any mount/machine; the hardcoded
    // Windows path remains the default when no argument is given.
    static void Main(string[] args)
    {
        string baseDir = args.Length > 0 ? args[0] : @"D:/FFX Extracted/FFX/ffx_ps2/ffx/master/jppc";

        // CLP
        var clp = Ps2ClpReader.Read(baseDir + "/menu/menu.clp");
        Console.WriteLine($"=== CLP menu.clp: {clp.Count} blocks ===");
        foreach (var b in clp)
        {
            Console.WriteLine($"  block {b.BlockIndex} @0x{b.FileOffset:X}: header={string.Join(",", b.Header.Select(h => h.ToString("X")))}, sections={b.Sections.Count}");
            if (b.Sections.Count > 0 && b.Sections[0].EntryCount > 0)
            {
                var s0 = b.Sections[0];
                Console.WriteLine($"    section0: {s0.EntryCount} entries, first={s0.Entries[0]}, last={s0.Entries[^1]}");
            }
        }

        // DCP
        var dcp = Ps2DcpReader.Read(baseDir + "/menu/macrodic.dcp");
        Console.WriteLine($"\n=== DCP macrodic.dcp: {dcp.FileSize} bytes, {dcp.Chunks.Count} chunks ===");
        foreach (var c in dcp.Chunks)
            Console.WriteLine($"  chunk slot{c.SlotIndex} @0x{c.FileOffset:X}: {c.EntryCount} entries");

        // FMT
        var fmt = Ps2FmtReader.Read(baseDir + "/menu/battle.fmt");
        Console.WriteLine($"\n=== FMT battle.fmt: {fmt.FileSize} bytes, {fmt.GlyphCount} glyphs ===");
        Console.WriteLine($"  glyph0 shape='{fmt.Glyphs[0].AsciiShape}' nz1={fmt.Glyphs[0].NonZeroZone1} nz2={fmt.Glyphs[0].NonZeroZone2}");
        Console.WriteLine($"  glyph1 shape='{fmt.Glyphs[1].AsciiShape}' nz1={fmt.Glyphs[1].NonZeroZone1} nz2={fmt.Glyphs[1].NonZeroZone2}");

        // SPS2
        var sps2 = Ps2Sps2Reader.Read(baseDir + "/help/dvdcopy.sps2");
        Console.WriteLine($"\n=== SPS2 dvdcopy.sps2: {sps2.FileSize} bytes, magic={sps2.Magic}, count={sps2.Count} ===");
        Console.WriteLine($"  page_table=0x{sps2.PageTableOffset:X} clip_offset=0x{sps2.ClipOffset:X} offsets_offset=0x{sps2.OffsetsOffset:X}");
        Console.WriteLine($"  clips: {sps2.Clips.Count}");
        foreach (var c in sps2.Clips) Console.WriteLine($"    {c}");
        Console.WriteLine($"  offsets: {sps2.Offsets.Length}");
        Console.WriteLine($"  pages: {sps2.Pages.Count}");
        foreach (var p in sps2.Pages)
            Console.WriteLine($"    page {p.Index} @0x{p.FileOffset:X} count={p.Count} header=[{string.Join(",", p.HeaderWords.Select(h => h.ToString("X")))}] clips={p.Clips.Count}");
    }
}

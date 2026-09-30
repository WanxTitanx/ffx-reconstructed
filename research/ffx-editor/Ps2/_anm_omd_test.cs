using System;
using System.IO;
// FIX 2026-09-15 (FFX-STRUCTURES / ANM-OMD-FIX): updated all 9 reader calls to the
// CURRENT reader API. The old static wrappers (Ps2AnmAnimationReader.ReadAn2File /
// ReadAnmFile, Ps2OmdModelReader.ReadFile) no longer exist: the readers are now
// result classes Ps2An2File / Ps2AnmFile / Ps2OmdFile with static .Read(string|byte[]).
// Two API deltas beyond bare signatures, both intentional per the current readers:
//   1) .Read THROWS InvalidDataException on bad input instead of returning null,
//      so each call is wrapped in try/catch to keep the harness ok/fail accounting.
//   2) The old dump members (Blocks/Field0/ConstA/ConstB/UvPattern/Tail/Summary/
//      Uv1/Uv2/Tokens) were replaced by the documented model (An2Frame, UvData/
//      Table/UvGeometry, Vertices/RefVertices/Sections); the sample dumps were
//      rewritten against that model.
// Corpus defaults point at the Linux mount (current host); the same tree lives at
// "D:\FFX Extracted\FFX\ffx_ps2\ffx" on Windows.
using Ps2;

internal static class Program
{
    static int Main(string[] args)
    {
        string anmDir = args.Length > 0 ? args[0] : @"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/eiichi_abmap_data/anm";
        string mahoDir = args.Length > 1 ? args[1] : @"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/eiichi_abmap_data/maho/anm";
        string yonishiDir = args.Length > 2 ? args[2] : @"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/yonishi_data/dat_et/bat_eff/anm";
        string omdDir = args.Length > 3 ? args[3] : @"/mnt/nvme-samsung/FFX Extracted/FFX/ffx_ps2/ffx/eiichi_abmap_data/omd";

        int ok = 0, fail = 0;
        foreach (string f in Files(anmDir, "*.an2"))
        {
            try { Ps2An2File.Read(f); ok++; }
            catch (Exception ex) { Console.WriteLine("FAIL an2 " + Path.GetFileName(f) + ": " + ex.Message); fail++; }
        }
        foreach (string f in Files(mahoDir, "*.an2"))
        {
            try { Ps2An2File.Read(f); ok++; }
            catch (Exception ex) { Console.WriteLine("FAIL an2 " + Path.GetFileName(f) + ": " + ex.Message); fail++; }
        }
        foreach (string f in Files(yonishiDir, "*.an2"))
        {
            try { Ps2An2File.Read(f); ok++; }
            catch (Exception ex) { Console.WriteLine("FAIL an2 " + Path.GetFileName(f) + ": " + ex.Message); fail++; }
        }
        foreach (string f in Files(mahoDir, "*.anm"))
        {
            try { Ps2AnmFile.Read(f); ok++; }
            catch (Exception ex) { Console.WriteLine("FAIL anm " + Path.GetFileName(f) + ": " + ex.Message); fail++; }
        }
        foreach (string f in Files(yonishiDir, "*.anm"))
        {
            try { Ps2AnmFile.Read(f); ok++; }
            catch (Exception ex) { Console.WriteLine("FAIL anm " + Path.GetFileName(f) + ": " + ex.Message); fail++; }
        }
        foreach (string f in Files(omdDir, "*.omd"))
        {
            try
            {
                var m = Ps2OmdFile.Read(f);
                Console.WriteLine("OK  omd  " + Path.GetFileName(f) + "  entries=" + m.EntryCount + " verts=" + m.VertexCount + " type=" + m.EntryType + " sections=" + m.Sections.Length + " refVerts=" + m.RefVertices.Length);
                ok++;
            }
            catch (Exception ex) { Console.WriteLine("FAIL omd " + Path.GetFileName(f) + ": " + ex.Message); fail++; }
        }

        // Sample dumps against the CURRENT documented model (see header note).
        try
        {
            var sample = Ps2An2File.Read(Path.Combine(anmDir, "back00.an2"));
            Console.WriteLine("back00.an2: fc=" + sample.FrameCount + " fileSize=0x" + sample.FileSize.ToString("X4") + " firstFrameOff=0x" + sample.FirstFrameOffset.ToString("X4") + " frames=" + sample.Frames.Length);
            if (sample.Frames.Length > 0)
            {
                var b = sample.Frames[0];
                Console.WriteLine("  frame0: c0=0x{0:X4} c1=0x{1:X4} c2=0x{2:X4} c3=0x{3:X4} scaleA={4} scaleB={5}", b.C0, b.C1, b.C2, b.C3, b.ScaleA, b.ScaleB);
                Console.WriteLine("  frame0 rect: min=({0},{1}) max=({2},{3}) rgba0=#{4:X2}{5:X2}{6:X2}{7:X2}", b.MinX, b.MinY, b.MaxX, b.MaxY, b.R0, b.G0, b.B0, b.A0);
            }
        }
        catch (Exception ex) { Console.WriteLine("SKIP back00.an2 dump: " + ex.Message); }
        try
        {
            var sampAnm = Ps2AnmFile.Read(Path.Combine(mahoDir, "m2_128.anm"));
            Console.WriteLine("m2_128.anm: tex=" + sampAnm.TextureName + " fc=" + sampAnm.FrameCount + " flag=0x" + sampAnm.UnknownFlag.ToString("X4")
                + " uv=[" + string.Join(",", Array.ConvertAll(sampAnm.UvData, x => x.ToString("X4"))) + "]"
                + " table=" + sampAnm.Table.Length + " uvGeo=" + sampAnm.UvGeometry.Length);
        }
        catch (Exception ex) { Console.WriteLine("SKIP m2_128.anm dump: " + ex.Message); }
        try
        {
            var sampOmd = Ps2OmdFile.Read(Path.Combine(omdDir, "sph_hg.omd"));
            if (sampOmd.Vertices.Length > 0)
                Console.WriteLine("sph_hg.omd V0=" + sampOmd.Vertices[0] + " Vlast=" + sampOmd.Vertices[sampOmd.Vertices.Length - 1]
                    + " sectionTypes=" + string.Join(",", Array.ConvertAll(sampOmd.Sections, s => s.Type.ToString()))
                    + " refVerts=" + sampOmd.RefVertices.Length);
        }
        catch (Exception ex) { Console.WriteLine("SKIP sph_hg.omd dump: " + ex.Message); }

        Console.WriteLine("TOTAL ok=" + ok + " fail=" + fail);
        return fail == 0 ? 0 : 1;
    }

    // Missing corpus dir => warn once + empty set (harness keeps running, exit code
    // still reflects parse failures only).
    static string[] Files(string dir, string pattern)
    {
        if (!Directory.Exists(dir)) { Console.WriteLine("WARN missing dir: " + dir); return Array.Empty<string>(); }
        return Directory.GetFiles(dir, pattern);
    }
}

// Validation harness for Ps2RsdModelReader, Ps2PlyModelReader, Ps2Ma2MaterialReader.
// Tests all 230 .rsd/.ply/.ma2 file sets in ffx_ps2/yonishi_data/.
using System;
using System.IO;
using Ps2;

internal static class Program
{
    static int Main(string[] args)
    {
        string root = args.Length > 0
            ? args[0]
            : @"D:\FFX Extracted\FFX\ffx_ps2";

        int rsdOk = 0, rsdFail = 0;
        int plyOk = 0, plyFail = 0;
        int ma2Ok = 0, ma2Fail = 0;
        int linkOk = 0, linkFail = 0;

        string[] rsdFiles = Directory.GetFiles(root, "*.rsd", SearchOption.AllDirectories);
        Console.WriteLine($"Found {rsdFiles.Length} .rsd files");

        foreach (string rsdPath in rsdFiles)
        {
            // --- RSD ---
            var rsd = Ps2RsdManifest.Read(rsdPath);
            if (rsd == null) { rsdFail++; Console.WriteLine($"FAIL rsd: {rsdPath}"); continue; }
            rsdOk++;

            // --- PLY ---
            string plyName = rsd.PlyName;
            if (plyName.Length == 0) { Console.WriteLine($"SKIP ply: {Path.GetFileName(rsdPath)} (no PLY=)"); }
            else
            {
                string? plyPath = rsd.ResolveSiblingPath(plyName);
                if (plyPath == null) { plyPath = rsd.ResolveSiblingPath(plyName.ToLowerInvariant()); }
                if (plyPath != null)
                {
                    var ply = Ps2PlyModel.Read(plyPath);
                    if (ply == null) { plyFail++; Console.WriteLine($"FAIL ply: {plyPath}"); }
                    else
                    {
                        plyOk++;
                        // Validate polygon count matches .ma2 item count later
                    }
                }
                else { plyFail++; Console.WriteLine($"MISS ply: {plyName} from {rsdPath}"); }
            }

            // --- MA2 ---
            string ma2Name = rsd.MatName;
            if (ma2Name.Length == 0) { Console.WriteLine($"SKIP ma2: {Path.GetFileName(rsdPath)} (no MAT=)"); }
            else
            {
                string? ma2Path = rsd.ResolveSiblingPath(ma2Name);
                if (ma2Path == null) { ma2Path = rsd.ResolveSiblingPath(ma2Name.ToLowerInvariant()); }
                if (ma2Path != null)
                {
                    var ma2 = Ps2Ma2File.Read(ma2Path);
                    if (ma2 == null) { ma2Fail++; Console.WriteLine($"FAIL ma2: {ma2Path}"); }
                    else
                    {
                        ma2Ok++;
                        // Cross-validate: MA2 item count == PLY polygon count
                        string? plyPath2 = rsd.ResolveSiblingPath(plyName)
                                          ?? rsd.ResolveSiblingPath(plyName.ToLowerInvariant());
                        if (plyPath2 != null)
                        {
                            var ply2 = Ps2PlyModel.Read(plyPath2);
                            if (ply2 != null)
                            {
                                if (ply2.PolygonCount == ma2.ItemCount) linkOk++;
                                else { linkFail++; Console.WriteLine($"LINK FAIL: {Path.GetFileName(rsdPath)} ply={ply2.PolygonCount} ma2={ma2.ItemCount}"); }
                            }
                        }
                    }
                }
                else { ma2Fail++; Console.WriteLine($"MISS ma2: {ma2Name} from {rsdPath}"); }
            }
        }

        Console.WriteLine();
        Console.WriteLine($"RSD: {rsdOk} OK, {rsdFail} FAIL");
        Console.WriteLine($"PLY: {plyOk} OK, {plyFail} FAIL");
        Console.WriteLine($"MA2: {ma2Ok} OK, {ma2Fail} FAIL");
        Console.WriteLine($"LINK (ply.NP == ma2.count): {linkOk} OK, {linkFail} FAIL");

        // Spot-check: read enc_001 and print details
        Console.WriteLine();
        Console.WriteLine("=== Spot-check: enc_001 ===");
        string rsdSpot = FindFirst(root, "enc_001.rsd");
        if (rsdSpot.Length > 0)
        {
            var rsd = Ps2RsdManifest.Read(rsdSpot)!;
            Console.WriteLine($"  RSD magic: {rsd.Magic}");
            Console.WriteLine($"  PLY: {rsd.PlyName}, MAT: {rsd.MatName}, GRP: {rsd.GrpName}, VGR: {rsd.VgrName}");
            Console.WriteLine($"  NTEX: {rsd.TextureCount}, TEX: [{string.Join(", ", rsd.TextureNames)}]");

            string? plyP = rsd.ResolveSiblingPath(rsd.PlyName) ?? rsd.ResolveSiblingPath(rsd.PlyName.ToLowerInvariant());
            if (plyP != null)
            {
                var ply = Ps2PlyModel.Read(plyP)!;
                Console.WriteLine($"  PLY: V={ply.VertexCount} N={ply.NormalCount} P={ply.PolygonCount}");
                if (ply.Vertices.Count > 0) Console.WriteLine($"  V[0] = ({ply.Vertices[0].X:F6}, {ply.Vertices[0].Y:F6}, {ply.Vertices[0].Z:F6})");
                if (ply.Polygons.Count > 0)
                {
                    var p0 = ply.Polygons[0];
                    Console.WriteLine($"  P[0]: flag={p0.Flag} ({(p0.IsQuad ? "quad" : "tri")}) v=({p0.V0},{p0.V1},{p0.V2},{p0.V3}) n=({p0.N0},{p0.N1},{p0.N2},{p0.N3})");
                }
            }

            string? ma2P = rsd.ResolveSiblingPath(rsd.MatName) ?? rsd.ResolveSiblingPath(rsd.MatName.ToLowerInvariant());
            if (ma2P != null)
            {
                var ma2 = Ps2Ma2File.Read(ma2P)!;
                Console.WriteLine($"  MA2: {ma2.Magic}, {ma2.ItemCount} items");
                if (ma2.Items.Count > 0)
                {
                    var m0 = ma2.Items[0];
                    Console.WriteLine($"  M[0]: idx={m0.Index} texFlag={m0.TextureFlag} size={m0.CompiledSize} texId=0x{m0.TextureIdHex}");
                    Console.WriteLine($"  M[0]: f1={m0.Flag1} f2={m0.Flag2} sep={m0.Separator} textured={m0.IsTextured}");
                    Console.WriteLine($"  M[0]: uv0=({m0.Uv0.U},{m0.Uv0.V}) rgba0=({m0.Rgba0.R},{m0.Rgba0.G},{m0.Rgba0.B},{m0.Rgba0.A})");
                }
            }
        }

        // Count parsed items
        int totalItems = 0;
        foreach (string f in Directory.GetFiles(root, "*.ma2", SearchOption.AllDirectories))
        {
            var ma2 = Ps2Ma2File.Read(f);
            if (ma2 != null) totalItems += ma2.Items.Count;
        }
        Console.WriteLine($"\nTotal .ma2 items parsed: {totalItems} (expected 2348)");

        return rsdFail + plyFail + ma2Fail + linkFail > 0 ? 1 : 0;
    }

    static string FindFirst(string root, string name)
    {
        var files = Directory.GetFiles(root, name, SearchOption.AllDirectories);
        return files.Length > 0 ? files[0] : "";
    }
}

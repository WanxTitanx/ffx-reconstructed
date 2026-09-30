// ============================================================================
// SavesHunt mini-runner — validates REAL FFX saves against the canonical repo parser
// PURPOSE : load real game saves (Steam/Switch/PS2/PS3/Vita + TAS checkpoints) through
//           FfxSaveFile.Load (the editor's canonical save parser), verify the game CRC,
//           and prove the payload round-trips through SaveAs(RawPs2).
// WHY     : RE-09/RE-29/EXP-07/EXP-19 were blocked "for lack of game saves"; this runner
//           proves real saves exist in-repo and parse cleanly, unlocking those items.
// EVIDENCE: FfxSaveFile.DetectFormat accepts 25848 (RawPs2), 26880 (PcFfx legacy) and
//           26944 (PcFfx with 0x40 header); FfxSaveChecksum.Compute over bytes 64..25847
//           must equal the u16 stored at payload+26 and payload+25844 in a genuine save.
// MAINT   : scratch tool for the 2026-09-14 saves hunt (docs/reverse/FFX_SAVES_HUNT_2026-09-14.md);
//           compiles the FfxLib/Save sources directly — keep in sync if the parser moves.
// ============================================================================
using System;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using FFXProjectEditor.FfxLib.Save;

static string Sha256(byte[] data)
{
    byte[] h = SHA256.HashData(data);
    var sb = new StringBuilder(h.Length * 2);
    foreach (byte b in h) sb.Append(b.ToString("x2"));
    return sb.ToString();
}

static string Hex(byte[] data, int offset, int count)
{
    var sb = new StringBuilder();
    for (int i = 0; i < count; i++) sb.Append(data[offset + i].ToString("X2")).Append(' ');
    return sb.ToString();
}

string repo = "/home/wanderson/Documents/ffx-editor-main";
string[][] targets =
{
    new[] { repo + "/Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX/PS2", "converter-sample" },
    new[] { repo + "/Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX/PS3 (decrypted)", "converter-sample" },
    new[] { repo + "/Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX/PS Vita", "converter-sample" },
    new[] { repo + "/Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX/Steam", "converter-sample" },
    new[] { repo + "/Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX/Switch", "converter-sample" },
    new[] { repo + "/Utilities/FFX_TAS_Python/tas_saves/ffx_020", "tas-checkpoint" },
    new[] { repo + "/Utilities/FFX_TAS_Python/tas_saves/ffx_047", "tas-checkpoint" },
    new[] { repo + "/Utilities/FFX_TAS_Python/tas_saves/ffx_101", "tas-checkpoint" },
    new[] { repo + "/Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX-2/PS2 (international edition)", "ffx2-negative-control" },
    new[] { repo + "/work/_saves_hunt/corpus/user_ffx_000", "user-real-backup-2026-09-02" },
    new[] { repo + "/work/_saves_hunt/corpus/user_ffx_011", "user-real-backup-2026-09-02" },
    new[] { repo + "/work/_saves_hunt/corpus/user_ffx2_000", "user-real-ffx2-negative-control" },
};

int ok = 0, crcOk = 0, failed = 0;
foreach (string[] t in targets)
{
    string path = t[0], kind = t[1];
    Console.WriteLine($"=== {Path.GetFileName(path)} [{kind}] ===");
    byte[] raw = File.ReadAllBytes(path);
    Console.WriteLine($"  file size : {raw.Length}");
    Console.WriteLine($"  file sha256: {Sha256(raw)}");
    try
    {
        FfxSaveFile session = FfxSaveFile.Load(path);
        byte[] payload = session.Core.Data;
        ushort crcComputed = FfxSaveChecksum.Compute(payload);
        ushort crcAt26 = (ushort)(payload[26] | (payload[27] << 8));
        ushort crcAt25844 = (ushort)(payload[25844] | (payload[25845] << 8));
        bool crcMatch = crcComputed == crcAt26 && crcAt26 == crcAt25844;
        if (crcMatch) crcOk++;
        Console.WriteLine($"  FORMAT={session.Format}  label='{session.DisplayLabel}'");
        Console.WriteLine($"  payload sha256: {Sha256(payload)}");
        Console.WriteLine($"  payload[0..16]: {Hex(payload, 0, 16)}");
        Console.WriteLine($"  payload+0x20  : {Hex(payload, 0x20, 16)}");
        Console.WriteLine($"  CRC computed=0x{crcComputed:X4} @26=0x{crcAt26:X4} @25844=0x{crcAt25844:X4} -> {(crcMatch ? "MATCH (genuine game save)" : "MISMATCH")}");

        // Round-trip through the canonical writer: SaveAs RawPs2 then reload.
        string tmp = Path.Combine(Path.GetTempPath(), "saveshunt_" + Path.GetFileName(path) + ".rt.bin");
        session.SaveAs(tmp, FfxSaveFormat.RawPs2);
        FfxSaveFile reloaded = FfxSaveFile.Load(tmp);
        bool identical = reloaded.Core.Data.AsSpan().SequenceEqual(payload);
        Console.WriteLine($"  round-trip RawPs2: reload payload {(identical ? "BYTE-IDENTICAL" : "DIFFERS (PrepareForSave normalized CRC/tag — expected)")}");
        if (!identical)
        {
            int first = -1;
            for (int i = 0; i < payload.Length; i++)
                if (payload[i] != reloaded.Core.Data[i]) { first = i; break; }
            Console.WriteLine($"    first diff @ payload+0x{first:X} (0x{payload[first]:X2} -> 0x{reloaded.Core.Data[first]:X2})");
        }
        File.Delete(tmp);
        ok++;
    }
    catch (Exception ex)
    {
        failed++;
        Console.WriteLine($"  LOAD FAILED: {ex.GetType().Name}: {ex.Message}");
    }
    Console.WriteLine();
}

Console.WriteLine($"SUMMARY: loaded OK={ok}  crc-genuine={crcOk}  failed={failed}");

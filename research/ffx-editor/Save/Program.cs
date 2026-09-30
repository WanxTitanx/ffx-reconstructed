// ============================================================================
// SaveExp mini-runner — EXP-07/EXP-19 experiments over the REAL save corpus
// PURPOSE : (EXP-07) corpus-wide load + ValidateGameChecksum + Save round-trip must be
//           BYTE-IDENTICAL for every accessible genuine save (12 user Steam slots +
//           3 converter references + 66 TAS checkpoints), including the PS2 25848
//           RawPs2 path; (EXP-19) a CONTROLLED single-field edit (gil / item qty) must
//           stamp the FFXED tamper tag, recompute the game CRC at both storage
//           locations, keep the file size/format, and leave every other byte stable.
// WHY     : these two experiment items were blocked for weeks "for lack of game saves";
//           the 2026-09-14 hunt (docs/reverse/FFX_SAVES_HUNT_2026-09-14.md) located and
//           CRC-authenticated the corpus, and commit 704e6186 fixed the loader — this
//           runner measures the post-fix behavior against that real corpus.
// EVIDENCE: FfxSaveItems offsets (GilOffset=15752, TypeBase=16140, QuantityBase=16652,
//           SlotCount=112) are inlined below because FfxSaveItems.cs pulls
//           CommunityToolkit.Mvvm; the constants were copied verbatim from that file.
//           Tamper tag bytes copied verbatim from FfxSaveCore.TamperTag (FFXED "C.e").
// MAINT   : scratch tool for the 2026-09-14 experiments (docs/reverse/FFX_SAVE_EXP_2026-09-14.md);
//           compiles the FfxLib/Save sources directly — keep in sync if the parser moves.
// ============================================================================
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using FFXProjectEditor.FfxLib.Save;

// ── Constants mirrored from FfxSaveItems.cs (avoid CommunityToolkit.Mvvm dependency) ──
const int GilOffset = 15752;        // FfxSaveItems.GilOffset
const int ItemTypeBase = 16140;     // FfxSaveItems.TypeBase
const int ItemQtyBase = 16652;      // FfxSaveItems.QuantityBase

// FfxSaveCore.TamperTag (FFXED "C.e" written on every edited save) — plain local:
// top-level statements cannot declare static/readonly locals; captured by RunEditCase.
byte[] TamperTag = { 84, 115, 120, 131, 116, 115, 58, 113, 136, 58, 85, 85, 103, 84, 83 };

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

// Game-style CRC check on raw payload bytes (mirrors FfxSaveFile.ValidateGameChecksum,
// usable directly on file bytes without a session).
static bool GameCrcMatches(byte[] payload)
{
    byte[] copy = (byte[])payload.Clone();
    copy[26] = 0; copy[27] = 0; copy[25844] = 0; copy[25845] = 0;
    ushort computed = FfxSaveChecksum.Compute(copy);
    ushort stored26 = (ushort)(payload[26] | (payload[27] << 8));
    ushort storedTail = (ushort)(payload[25844] | (payload[25845] << 8));
    return stored26 == computed && stored26 == storedTail;
}

string repo = "/home/wanderson/Documents/ffx-editor-main";
string userDir = "/mnt/disco-velho/Backup C 2026-09-02/Users/wande/Documents/SQUARE ENIX/FINAL FANTASY X&X-2 HD Remaster/FINAL FANTASY X";
string convDir = repo + "/Utilities/Final-Fantasy-X-HD-Cross-platform-Save-Converter/Extracted Saves/FFX";
string tasDir = repo + "/Utilities/FFX_TAS_Python/tas_saves";
string tmpDir = repo + "/work/_saves_exp/tmp";
string outDir = repo + "/work/_saves_exp/out";
Directory.CreateDirectory(tmpDir);
Directory.CreateDirectory(outDir);

var results = new List<object>();
int totalOk = 0, totalFail = 0;
var histogram16384 = new SortedDictionary<string, int>();

// ══════════════════════════════════════════════════════════════════════════
// CASE A (EXP-07) — corpus-wide load + game-CRC validate + Save round-trip
// ══════════════════════════════════════════════════════════════════════════
Console.WriteLine("=== CASE A (EXP-07): load + ValidateGameChecksum + Save round-trip ===");

List<(string path, string group)> targetsA = new();
for (int i = 0; i <= 11; i++)
    targetsA.Add((Path.Combine(userDir, $"ffx_{i:D3}"), "user"));
targetsA.Add((Path.Combine(convDir, "Steam"), "converter"));
targetsA.Add((Path.Combine(convDir, "Switch"), "converter"));
targetsA.Add((Path.Combine(convDir, "PS2"), "converter"));
foreach (string f in Directory.GetFiles(tasDir))
    targetsA.Add((f, "tas"));

var groupCounts = new SortedDictionary<string, (int ok, int fail)>();
foreach ((string path, string group) in targetsA)
{
    string name = group + ":" + Path.GetFileName(path);
    bool ok = true;
    string error = null;
    string format = "-", crcValid = "-", byteIdentical = "-", reloadOk = "-", legacy = "-";
    try
    {
        byte[] original = File.ReadAllBytes(path);
        FfxSaveFile session = FfxSaveFile.Load(path);

        format = session.Format.ToString();
        legacy = session.PcFfxLegacyEditorLayout.ToString();
        crcValid = session.ValidateGameChecksum().ToString();
        if (session.Format != (original.Length == 25848 ? FfxSaveFormat.RawPs2 : FfxSaveFormat.PcFfx)) { ok = false; error = "unexpected format " + format; }
        if (session.PcFfxLegacyEditorLayout) { ok = false; error = "legacy layout flag set"; }
        if (!session.ValidateGameChecksum()) { ok = false; error = "game CRC mismatch"; }

        string tmp = Path.Combine(tmpDir, "rt_" + group + "_" + Path.GetFileName(path));
        session.Save(tmp);
        byte[] saved = File.ReadAllBytes(tmp);
        byteIdentical = saved.AsSpan().SequenceEqual(original).ToString();
        if (saved.Length != original.Length || !saved.AsSpan().SequenceEqual(original)) { ok = false; error = "round-trip NOT byte-identical"; }

        FfxSaveFile reloaded = FfxSaveFile.Load(tmp);
        reloadOk = (reloaded.Core.Data.AsSpan().SequenceEqual(session.Core.Data) && reloaded.ValidateGameChecksum()).ToString();
        if (reloaded.Core.Data.AsSpan().SequenceEqual(session.Core.Data) == false || !reloaded.ValidateGameChecksum()) { ok = false; error = "reload check failed"; }

        File.Delete(tmp);

        // corpus measurement: byte @16384 (PrepareForSave stamps 0xFE there on edit)
        string key = "0x" + original[16384].ToString("X2");
        histogram16384.TryGetValue(key, out int c);
        histogram16384[key] = c + 1;

        Console.WriteLine($"{(ok ? "PASS" : "FAIL")} {name,-22} size={original.Length} fmt={format,-6} crc={crcValid,-5} identical={byteIdentical,-5} reload={reloadOk}");
    }
    catch (Exception ex)
    {
        ok = false;
        error = ex.GetType().Name + ": " + ex.Message;
        Console.WriteLine($"FAIL {name,-22} EXC {error}");
    }
    var (gok, gfail) = groupCounts.TryGetValue(group, out var g) ? g : (0, 0);
    groupCounts[group] = ok ? (gok + 1, gfail) : (gok, gfail + 1);
    if (ok) totalOk++; else totalFail++;
    results.Add(new { id = name, size = new FileInfo(path).Length, format, crcValid, legacy, byteIdentical, reloadOk, ok, error });
}
Console.WriteLine($"CASE A totals: user={groupCounts["user"].ok}/{groupCounts["user"].ok + groupCounts["user"].fail} " +
                  $"converter={groupCounts["converter"].ok}/{groupCounts["converter"].ok + groupCounts["converter"].fail} " +
                  $"tas={groupCounts["tas"].ok}/{groupCounts["tas"].ok + groupCounts["tas"].fail} " +
                  $"TOTAL={totalOk}/{totalOk + totalFail}");
Console.WriteLine("corpus byte@16384 histogram: " + string.Join(", ", histogram16384));

// ══════════════════════════════════════════════════════════════════════════
// CASE C (EXP-07, PS2 leg) — converter_ps2 25848 load/save RawPs2 (explicit)
// ══════════════════════════════════════════════════════════════════════════
Console.WriteLine();
Console.WriteLine("=== CASE C (PS2 25848): converter_ps2 load/save RawPs2 ===");
string ps2Path = Path.Combine(convDir, "PS2");
byte[] ps2Original = File.ReadAllBytes(ps2Path);
FfxSaveFile ps2Session = FfxSaveFile.Load(ps2Path);
string ps2Tmp = Path.Combine(tmpDir, "ps2_saveas_rawps2");
ps2Session.SaveAs(ps2Tmp, FfxSaveFormat.RawPs2);
byte[] ps2Saved = File.ReadAllBytes(ps2Tmp);
bool cFormat = ps2Session.Format == FfxSaveFormat.RawPs2;
bool cSize = ps2Saved.Length == 25848;
bool cCrc = ps2Session.ValidateGameChecksum();
bool cIdentical = ps2Saved.AsSpan().SequenceEqual(ps2Original);
bool cReload = FfxSaveFile.Load(ps2Tmp).ValidateGameChecksum();
File.Delete(ps2Tmp);
Console.WriteLine($"format={cFormat} size25848={cSize} crc={cCrc} SaveAs(RawPs2)-identical={cIdentical} reload-crc={cReload}");
results.Add(new { id = "caseC_ps2_rawps2", formatOk = cFormat, sizeOk = cSize, crcOk = cCrc, byteIdentical = cIdentical, reloadCrcOk = cReload, ok = cFormat && cSize && cCrc && cIdentical && cReload });
bool caseCok = cFormat && cSize && cCrc && cIdentical && cReload;

// ══════════════════════════════════════════════════════════════════════════
// CASE B (EXP-19) — controlled single-field edits
// ══════════════════════════════════════════════════════════════════════════
Console.WriteLine();
Console.WriteLine("=== CASE B (EXP-19): controlled edit -> FFXED tag + CRC + byte stability ===");

// B-help: run one controlled edit and verify everything about the output file.
// editOffsets = payload offsets the edit itself is allowed to touch (the intended change).
// Returns a report dictionary; caller prints + appends to results.
object RunEditCase(string caseId, string srcPath, string outName, Action<FfxSaveCore> edit,
                   int[] editOffsets, int expectedSize)
{
    byte[] original = File.ReadAllBytes(srcPath);
    FfxSaveFile s = FfxSaveFile.Load(srcPath);
    int payloadLen = 25848;
    int footerStart = original.Length == 26880 ? payloadLen : -1; // PcFfx only

    edit(s.Core);
    string outPath = Path.Combine(outDir, outName);
    s.Save(outPath);
    byte[] saved = File.ReadAllBytes(outPath);

    // expected diff set: the intended edit + CRC@26/27 + CRC@25844/25845 + tamper tag@32..46
    // (+ byte 16384 stamped 0xFE by PrepareForSave — only when the original differs)
    var expected = new SortedSet<int>(editOffsets) { 26, 27, 25844, 25845 };
    for (int i = 32; i < 32 + TamperTag.Length; i++) expected.Add(i);
    if (original[16384] != 0xFE) expected.Add(16384);

    var actual = new SortedSet<int>();
    for (int i = 0; i < Math.Min(original.Length, saved.Length); i++)
        if (original[i] != saved[i]) actual.Add(i);

    bool sizeOk = saved.Length == expectedSize;
    bool tagOk = true;
    for (int i = 0; i < TamperTag.Length; i++) if (saved[32 + i] != TamperTag[i]) tagOk = false;
    ushort crc26 = (ushort)(saved[26] | (saved[27] << 8));
    ushort crcTail = (ushort)(saved[25844] | (saved[25845] << 8));
    bool crcBothPlaces = crc26 == crcTail;
    bool crcValid = GameCrcMatches(saved);
    bool crcChanged = original.Length >= 25848 && crc26 != (ushort)(original[26] | (original[27] << 8));
    // WHY subset semantics: an arithmetic edit (gil+1) only flips the bytes the carry
    // reaches — e.g. 0x...F698+1 changes ONLY the LSB. The contract is: no byte outside
    // the allowed set (edit + CRC + tag + 0xFE stamp @16384) may change, and the
    // mandatory stamps (both CRC locations + tag start) must be present.
    var extra = actual.Except(expected);
    bool diffSubsetOk = !extra.Any();
    bool stampsPresent = actual.Contains(26) && actual.Contains(27) && actual.Contains(25844) && actual.Contains(25845) && actual.Contains(32);
    var missingStamps = new List<int>();
    if (!actual.Contains(26)) missingStamps.Add(26);
    if (!actual.Contains(27)) missingStamps.Add(27);
    if (!actual.Contains(25844)) missingStamps.Add(25844);
    if (!actual.Contains(25845)) missingStamps.Add(25845);
    if (!actual.Contains(32)) missingStamps.Add(32);
    bool footerStable = footerStart < 0 ||
        saved.AsSpan(footerStart, saved.Length - footerStart).SequenceEqual(original.AsSpan(footerStart, original.Length - footerStart));

    FfxSaveFile r = FfxSaveFile.Load(outPath);
    bool reloadValidate = r.ValidateGameChecksum();
    bool reloadFormat = r.Format == (expectedSize == 25848 ? FfxSaveFormat.RawPs2 : FfxSaveFormat.PcFfx);

    bool allOk = sizeOk && tagOk && crcBothPlaces && crcValid && crcChanged && diffSubsetOk && stampsPresent && footerStable && reloadValidate && reloadFormat;

    Console.WriteLine($"{caseId}: size={sizeOk} tagFFXED={tagOk} crcBothPlaces={crcBothPlaces} crcGameValid={crcValid} crcChanged={crcChanged} " +
                      $"diffSubset={diffSubsetOk} stampsPresent={stampsPresent} footerStable={footerStable} reloadValidate={reloadValidate} reloadFormat={reloadFormat} => {(allOk ? "PASS" : "FAIL")}");
    Console.WriteLine($"    diff offsets: [{string.Join(",", actual.Select(x => "0x" + x.ToString("X")))}]");
    if (extra.Any()) Console.WriteLine($"    UNEXPECTED diffs: [{string.Join(",", extra.Select(x => "0x" + x.ToString("X")))}]");
    if (missingStamps.Count > 0) Console.WriteLine($"    MISSING stamps: [{string.Join(",", missingStamps)}]");
    Console.WriteLine($"    artifact: {outPath} sha256={Sha256(saved)}");

    return new
    {
        id = caseId,
        source = srcPath,
        artifact = outPath,
        artifactSha256 = Sha256(saved),
        sizeOk, tagOk, crcBothPlaces, crcValid, crcChanged, diffSubsetOk, stampsPresent, footerStable, reloadValidate, reloadFormat,
        diffOffsets = actual.Select(x => x).ToArray(),
        unexpectedDiffs = extra.Select(x => x).ToArray(),
        ok = allOk,
    };
}

// B1: gil +1 on user_ffx_000 (genuine Steam 26880). Header mirror @0x14 measured BEFORE.
byte[] b1Orig = File.ReadAllBytes(Path.Combine(userDir, "ffx_000"));
uint gilBefore = BitConverter.ToUInt32(b1Orig, GilOffset);
uint mirrorBefore = BitConverter.ToUInt32(b1Orig, 20);
Console.WriteLine($"B1 pre-state: gil@15752={gilBefore} (0x{gilBefore:X8})  header@0x14 mirror={mirrorBefore} (0x{mirrorBefore:X8})  mirror==gil: {gilBefore == mirrorBefore}");
object b1 = RunEditCase("B1_gil_user_ffx_000", Path.Combine(userDir, "ffx_000"), "edited_gil_user_ffx_000",
    core => core.WriteInt32Le(GilOffset, (int)(gilBefore + 1), 4),
    new[] { GilOffset, GilOffset + 1, GilOffset + 2, GilOffset + 3 }, 26880);
byte[] b1Saved = File.ReadAllBytes(Path.Combine(outDir, "edited_gil_user_ffx_000"));
uint gilAfter = BitConverter.ToUInt32(b1Saved, GilOffset);
uint mirrorAfter = BitConverter.ToUInt32(b1Saved, 20);
Console.WriteLine($"B1 post-state: gil={gilAfter} (expected {gilBefore + 1}: {gilAfter == gilBefore + 1})  header@0x14 mirror={mirrorAfter} (STALE: {mirrorAfter != gilAfter} — editor does not touch the header preview mirror; documented finding)");
results.Add(b1);
results.Add(new { id = "B1_gil_values", gilBefore, gilAfter, gilOk = gilAfter == gilBefore + 1, headerMirrorBefore = mirrorBefore, headerMirrorAfter = mirrorAfter, headerMirrorStale = mirrorAfter != gilAfter });

// B2: item slot 0 quantity +1 (1 byte @16652) on user_ffx_000
byte[] b2Orig = File.ReadAllBytes(Path.Combine(userDir, "ffx_000"));
int qtyBefore = b2Orig[ItemQtyBase];
Console.WriteLine($"B2 pre-state: item slot0 type@16140=0x{b2Orig[ItemTypeBase]:X2} qty@16652={qtyBefore}");
object b2 = RunEditCase("B2_itemqty_user_ffx_000", Path.Combine(userDir, "ffx_000"), "edited_itemqty_user_ffx_000",
    core => core.WriteInt32Le(ItemQtyBase, qtyBefore + 1, 1),
    new[] { ItemQtyBase }, 26880);
byte[] b2Saved = File.ReadAllBytes(Path.Combine(outDir, "edited_itemqty_user_ffx_000"));
Console.WriteLine($"B2 post-state: qty={b2Saved[ItemQtyBase]} (expected {qtyBefore + 1}: {b2Saved[ItemQtyBase] == qtyBefore + 1})");
results.Add(b2);
results.Add(new { id = "B2_item_values", qtyBefore, qtyAfter = (int)b2Saved[ItemQtyBase], qtyOk = b2Saved[ItemQtyBase] == (byte)(qtyBefore + 1) });

// B3: gil +1 on converter PS2 (25848 RawPs2) — save back as RawPs2
byte[] b3Orig = File.ReadAllBytes(ps2Path);
uint gil3Before = BitConverter.ToUInt32(b3Orig, GilOffset);
Console.WriteLine($"B3 pre-state: gil@15752={gil3Before} (0x{gil3Before:X8}) byte@16384=0x{b3Orig[16384]:X2} (expect 0xFE stamp to appear in diff)");
object b3 = RunEditCase("B3_gil_converter_ps2_rawps2", ps2Path, "edited_gil_converter_ps2",
    core => core.WriteInt32Le(GilOffset, (int)(gil3Before + 1), 4),
    new[] { GilOffset, GilOffset + 1, GilOffset + 2, GilOffset + 3 }, 25848);
byte[] b3Saved = File.ReadAllBytes(Path.Combine(outDir, "edited_gil_converter_ps2"));
Console.WriteLine($"B3 post-state: gil={BitConverter.ToUInt32(b3Saved, GilOffset)} (expected {gil3Before + 1}: {BitConverter.ToUInt32(b3Saved, GilOffset) == gil3Before + 1}) byte@16384=0x{b3Saved[16384]:X2}");
results.Add(b3);

// ── Final summary ──
var jsonOptions = new JsonSerializerOptions { WriteIndented = true };
File.WriteAllText(repo + "/work/_saves_exp/results.json", JsonSerializer.Serialize(results, jsonOptions));
Console.WriteLine();
Console.WriteLine($"SUMMARY: EXP-07 caseA total={totalOk}/{totalOk + totalFail} (user={groupCounts["user"].ok}/12 converter={groupCounts["converter"].ok}/3 tas={groupCounts["tas"].ok}/{groupCounts["tas"].ok + groupCounts["tas"].fail}) caseC={caseCok}");
Console.WriteLine($"         results.json written; edited artifacts kept in work/_saves_exp/out/");

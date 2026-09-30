using System;
using FFXProjectEditor.FfxLib.Atel;

class Harness
{
    static int Main(string[] args)
    {
        string dir = args.Length > 0 ? args[0] : @"D:\FFX Extracted\FFX2\ffx_ps2\ffx2\master\jppc\battle\header";
        Console.WriteLine(AtelHeaderFile.SelfTest(dir));

        // Spot checks
        var btlatel = AtelHeaderFile.ParseFile(System.IO.Path.Combine(dir, "btlatel.ath"));
        Console.WriteLine("btlatel funcspace=" + string.Join(",", btlatel.Funcspaces));
        Console.WriteLine("btlTerminateAction -> 0x" + btlatel.Resolve("btlTerminateAction").Value.ToString("X5"));
        Console.WriteLine("btlSetRandPosFlag -> 0x" + btlatel.Resolve("btlSetRandPosFlag").Value.ToString("X5"));
        Console.WriteLine("0x7001 -> " + btlatel.ResolveId(0x7001));

        var cmd = AtelHeaderFile.ParseFile(System.IO.Path.Combine(dir, "command.ath"));
        Console.WriteLine("command ns3 count=" + cmd.ByNamespace[3].Count);
        Console.WriteLine("pcom_アイテム -> 0x" + cmd.Resolve("pcom_アイテム").Value.ToString("X5"));
        Console.WriteLine("0x03000 -> " + cmd.ResolveId(0x3000));

        var mon = AtelHeaderFile.ParseFile(System.IO.Path.Combine(dir, "monmagic.ath"));
        Console.WriteLine("monmagic ns4 count=" + mon.ByNamespace[4].Count);
        Console.WriteLine("0x04000 -> " + mon.ResolveId(0x4000));

        var alias = AtelHeaderFile.ParseFile(System.IO.Path.Combine(dir, "btlmapalias.ath"));
        Console.WriteLine("btlmapalias aliases=" + alias.AliasCount + " first=" + alias.Entries[0].Name + " -> " + alias.Entries[0].AliasTarget);

        var cam = AtelHeaderFile.ParseFile(System.IO.Path.Combine(dir, "camera.ath"));
        Console.WriteLine("camera aliases=" + cam.AliasCount);

        var map = AtelHeaderFile.ParseFile(System.IO.Path.Combine(dir, "btlmap.ath"));
        Console.WriteLine("btlmap ids=" + map.IdCount + " first=" + map.Entries[0].Name + "=0x" + map.Entries[0].Id.Value.ToString("X5"));

        return 0;
    }
}

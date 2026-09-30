using System;
using System.IO;
using System.Security.Cryptography;
using FFXResearchTools.Claims;
using FFXResearchTools.Reporting;

static class P
{
    static void Main(string[] a)
    {
        string root = a.Length > 0 ? a[0] : ".";
        byte[] groups = File.ReadAllBytes(Path.Combine(root, "seed-claim-groups-v6-vnext.json"));
        byte[] claims = File.ReadAllBytes(Path.Combine(root, "seed-claims-v6-vnext.json"));
        byte[] deferred = File.ReadAllBytes(Path.Combine(root, "deferred-atlas-fact-seeds.json"));
        ClaimLedger ledger = ClaimLedgerSeedLoader.LoadAndValidate(groups, claims, deferred);
        byte[] canonical = CanonicalJson.SerializeUtf8(ledger);
        string sha = Convert.ToHexString(SHA256.HashData(canonical));
        Console.WriteLine($"bytes={canonical.Length} sha256={sha}");
        Console.WriteLine($"groups={ledger.Groups.Count} claims={ledger.Claims.Count} deferred={ledger.DeferredAtlasFacts.Count}");
        if (a.Length > 1) File.WriteAllBytes(a[1], canonical);
    }
}

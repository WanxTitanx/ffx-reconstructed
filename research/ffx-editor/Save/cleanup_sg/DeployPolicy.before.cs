namespace FFXProjectEditor.FfxLib.SphereGrid;

/// <summary>
/// Guards live project deployment of Sphere Grid layouts.
///
/// Historical note (corrected 2026-08-01): the "no-hook 861/882 crashes FFX on exit" finding came from
/// RT2 runs of the retired True New Node v5 hook stack (manifest CSV + sidecar + SEH), never from a
/// clean editor-only deploy. With today's RE the engine is header-driven (NodeCount flows dat header →
/// lpamng), the static LpAbilityMapEngine holds 1024 nodes / 1024 links / 128 clusters, and the native
/// save holds 1280/1280 — so counts ≤ 1024 need NO hook. The suspected real ceiling is the RENDER path
/// (FFX_Menu2D_InitBatchBuffers_NoTextureFallback@0x681DB0 buffers 861×48 + DrawQuadIndexedBatch@0x7F4900
/// gate `n861 >= 861`), which was never isolated in a clean test. See
/// docs/reverse/FFX_GHIDRA_FAHRENHEIT_SYMBOL_IMPORT_2026-07-31.md §sphere.bin / §próximos passos.
/// </summary>
public static class SphereGridDeployPolicy
{
    /// <summary>
    /// Deploy is allowed when counts are untouched, OR when the user explicitly opts into a clean
    /// no-hook runtime test (builder.AllowRuntimeTestDeploy) — disposable save + RT2 observation required.
    /// </summary>
    public static bool CanDeployToProject(SphereGridLayoutBuilder builder) =>
        !builder.HasRuntimeUnprovenTopologyCountChange || builder.AllowRuntimeTestDeploy;

    public static string BlockReason(SphereGridLayoutBuilder builder) =>
        $"🚫 RUNTIME-UNPROVEN: counts {builder.SeededClusterCount}/{builder.SeededNodeCount}/{builder.SeededLinkCount} " +
        $"→ {builder.ClusterCount}/{builder.NodeCount}/{builder.LinkCount}. " +
        "Deploy limpo sem hook ainda não foi testado (o crash 861/882 antigo foi com o hook v5). " +
        "Ative 'Permitir deploy de teste RT2' apenas com save descartável, ou use Save Copy / Export Square.";
}

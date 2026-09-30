using System;
using System.Globalization;
using System.IO;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;

namespace FFXProjectEditor.FfxLib.SphereGrid
{
    /// <summary>
    /// Square Mode sidecars: full dat pair publish metadata (SHA256, counts, human report).
    /// See docs/reverse/FFX_SPHEREGRID_SQUARE_MODE_FULL_REAUTHOR_PLAN_2026-06-18.md
    /// </summary>
    public static class SphereGridSquarePackageWriter
    {
        public sealed record SquarePackageResult(
            string ManifestJsonPath,
            string ReportPath,
            string LayoutSha256,
            string ContentsSha256);

        public static SquarePackageResult Emit(
            string configDir,
            string gridKindLabel,
            string layoutFileName,
            string contentsFileName,
            byte[] layoutBytes,
            byte[] contentsBytes,
            int clusterCount,
            int nodeCount,
            int linkCount,
            int? retailClusterCount,
            int? retailNodeCount,
            int? retailLinkCount)
        {
            Directory.CreateDirectory(configDir);
            string layoutSha = Sha256Hex(layoutBytes);
            string contentsSha = Sha256Hex(contentsBytes);
            string timestamp = DateTimeOffset.UtcNow.ToString("O", CultureInfo.InvariantCulture);

            var manifest = new
            {
                schema = 2,
                square_mode = 1,
                grid_kind = gridKindLabel,
                layout_file = layoutFileName,
                contents_file = contentsFileName,
                cluster_count = clusterCount,
                node_count = nodeCount,
                link_count = linkCount,
                layout_sha256 = layoutSha,
                contents_sha256 = contentsSha,
                layout_bytes = layoutBytes.Length,
                contents_bytes = contentsBytes.Length,
                generated_utc = timestamp,
                retail_baseline = retailClusterCount.HasValue
                    ? new
                    {
                        clusters = retailClusterCount.Value,
                        nodes = retailNodeCount!.Value,
                        links = retailLinkCount!.Value,
                    }
                    : null,
            };

            string manifestPath = Path.Combine(configDir, "square_grid_manifest.json");
            File.WriteAllText(manifestPath, JsonSerializer.Serialize(manifest, new JsonSerializerOptions { WriteIndented = true }), Encoding.UTF8);

            string reportPath = Path.Combine(configDir, "square_grid_report.txt");
            File.WriteAllText(reportPath, BuildReport(
                gridKindLabel, layoutFileName, contentsFileName,
                clusterCount, nodeCount, linkCount,
                layoutBytes.Length, contentsBytes.Length,
                layoutSha, contentsSha, timestamp,
                retailClusterCount, retailNodeCount, retailLinkCount), Encoding.UTF8);

            return new SquarePackageResult(manifestPath, reportPath, layoutSha, contentsSha);
        }

        public static void WriteDeployReadme(string exportDir, string gridKindLabel, string layoutFileName, string contentsFileName)
        {
            string readme = $"""
                FFX Sphere Grid — Square Mode export ({gridKindLabel})
                Generated: {DateTimeOffset.UtcNow:yyyy-MM-dd HH:mm:ss} UTC

                Files:
                  {layoutFileName}  — full layout (topology header + clusters/nodes/links)
                  {contentsFileName} — 1 byte per node contents
                  square_grid_manifest.json — SHA256 + counts

                Deploy:
                  1. This export is RESEARCH/INSPECTION ONLY when node or link counts differ from retail vanilla.
                  2. Do NOT deploy a count-changing pair to a live project abmap: 861 nodes / 882 links
                     was confirmed to crash FFX on Sphere Grid exit.
                  3. A proven in-process runtime path is required before topology growth can be deployed.

                """;
            File.WriteAllText(Path.Combine(exportDir, "README_deploy.txt"), readme, Encoding.UTF8);
        }

        private static string BuildReport(
            string gridKind,
            string layoutFile,
            string contentsFile,
            int clusters,
            int nodes,
            int links,
            int layoutLen,
            int contentsLen,
            string layoutSha,
            string contentsSha,
            string timestamp,
            int? retailClusters,
            int? retailNodes,
            int? retailLinks)
        {
            var sb = new StringBuilder();
            sb.AppendLine("FFX Sphere Grid — Square Mode publish report");
            sb.AppendLine($"generated_utc: {timestamp}");
            sb.AppendLine($"grid_kind: {gridKind}");
            sb.AppendLine($"layout: {layoutFile} ({layoutLen} bytes) sha256={layoutSha}");
            sb.AppendLine($"contents: {contentsFile} ({contentsLen} bytes) sha256={contentsSha}");
            sb.AppendLine($"counts: clusters={clusters} nodes={nodes} links={links}");
            if (retailClusters.HasValue)
            {
                sb.AppendLine($"retail_baseline: clusters={retailClusters} nodes={retailNodes} links={retailLinks}");
                sb.AppendLine($"delta: clusters={clusters - retailClusters:+0;-#} nodes={nodes - retailNodes:+0;-#} links={links - retailLinks:+0;-#}");
                if (nodes < retailNodes || links < retailLinks)
                    sb.AppendLine("WARN: counts below retail — mid-game save migration unlikely without ply_save work.");
            }
            sb.AppendLine("policy: full asset substitution (Square offline reauthor), not incremental +1 append.");
            return sb.ToString();
        }

        private static string Sha256Hex(byte[] data)
        {
            byte[] hash = SHA256.HashData(data);
            return Convert.ToHexString(hash).ToLowerInvariant();
        }
    }
}

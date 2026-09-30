# Dump hex das linhas com chars suspeitos (0x20AC EUR, 0x201A low-quote, 0x161 s-caron, 0x2122 TM, 0xE6 ae, 0xE5 aa, 0xC6 AE, 0x2030 permille, 0x2020 dagger)
$root = 'C:\Users\wande\Documents\ffx-editor-main\FFXProjectEditor'
$suspects = @(0x20AC, 0x201A, 0x161, 0x2122, 0xE6, 0xE5, 0xC6, 0x2030, 0x2020)
$files = @(
  'FfxLib\Ai\AiValidator.cs',
  'FfxLib\Ps3\MagicDllRt2VerdictCatalog.cs',
  'Controls\EnvironmentHealthCard.axaml',
  'Modules\Main\Main_Window.axaml.cs',
  'FfxLib\MagicDll\MagicSlot.cs',
  'Modules\SphereGridBuilder\SphereGridBuilder_DataModel.cs',
  'Modules\MagicDllEditor\MagicDllDocument_Wrapper.cs',
  'FfxLib\Encoding\FfxEncoding.us.cs',
  'Modules\SaveEditor\SaveEditorHub_Control.axaml.cs',
  'Modules\SaveEditor\SaveEditor_DataModel.cs',
  'Modules\MonsterAiEditor\MonsterAiEditor_DataModel.Behavior.cs',
  'Modules\MonsterAiEditor\MonsterAiPhaseRotationAdvanced_Window.axaml',
  'Styles\StudioIcons.axaml',
  'Converters\IconKeyToGeometryConverter.cs',
  'Modules\MonsterAiEditor\MonsterAiCompositeAction_Window.axaml',
  'Modules\Extras\MagicDllBrowser_DataModel.cs',
  'Modules\FormationEditor\FormationEditor_DataModel.cs',
  'FfxLib\MagicDll\MagicProgram.cs',
  'Modules\CustomBossCreator\CustomBossCreator_Control.axaml',
  'Core\LLM\ProposalToPlanMapper.cs',
  'Modules\Main\ModuleCatalogPolicy.cs',
  'FfxLib\Ai\AiScript_File.cs',
  'Modules\MagicDllEditor\MagicDllEditor_ViewModel.cs'
)
foreach ($f in $files) {
    $p = Join-Path $root $f
    if (-not (Test-Path $p)) { continue }
    $lines = [System.IO.File]::ReadAllLines($p)
    for ($i = 0; $i -lt $lines.Length; $i++) {
        $bad = @()
        foreach ($cp in $suspects) {
            $ch = [char]$cp
            if ($lines[$i].Contains($ch)) { $bad += ('U+{0:X4}' -f $cp) }
        }
        if ($bad.Count -gt 0) {
            $bytes = [System.Text.Encoding]::UTF8.GetBytes($lines[$i])
            $hex = ($bytes | ForEach-Object { $_.ToString('X2') }) -join ' '
            if ($hex.Length -gt 300) { $hex = $hex.Substring(0, 300) + '...' }
            "$f : line $($i+1) [$($bad -join ',')]"
            "  HEX: $hex"
        }
    }
}
"SCAN DONE"

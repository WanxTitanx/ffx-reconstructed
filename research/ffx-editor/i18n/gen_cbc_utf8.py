# -*- coding: utf-8 -*-
import io

# (key, EN, PT)
KEYS = [
 ("U_CBC_SelectBaseMonster", "Select a base monster to begin.", "Selecione um monstro base para começar."),
 ("U_CBC_ProjectNotLoaded", "(project not loaded)", "(projeto não carregado)"),
 ("U_CBC_InvalidId", "(invalid ID)", "(ID inválido)"),
 ("U_CBC_PreviewBaseMissing", "Preview: base file not found: {0}", "Preview: arquivo base não encontrado: {0}"),
 ("U_CBC_LootNoLootFile", "Final loot: m{0:D3} {1} has no LootFile; Create will fail in this mode.", "Loot final: m{0:D3} {1} não tem LootFile; Criar vai falhar nesse modo."),
 ("U_CBC_LootFileMissing", "Final loot: file of m{0:D3} {1} not found; Create will fail in this mode.", "Loot final: arquivo de m{0:D3} {1} não encontrado; Criar vai falhar nesse modo."),
 ("U_CBC_StatStrength", "Strength", "Força"),
 ("U_CBC_StatMagicDefense", "Magic Def.", "Def. Mágica"),
 ("U_CBC_StatEvasion", "Evasion", "Evasão"),
 ("U_CBC_StatAccuracy", "Accuracy", "Precisão"),
 ("U_CBC_LootOverridesNone", "Loot overrides: final LootFile missing; overrides will not be applied.", "Loot overrides: LootFile final inexistente; overrides não serão aplicados."),
 ("U_CBC_Changes", "Changes:", "Mudanças:"),
 ("U_CBC_InvalidInherit", "Invalid inherited fields:", "Campos inválidos que herdam:"),
 ("U_CBC_PreviewUnavailable", "Preview unavailable: {0}", "Preview indisponível: {0}"),
 ("U_CBC_TargetExists", "m{0:D3}.bin already exists. Choose a free ID.", "m{0:D3}.bin já existe. Escolha um ID livre."),
 ("U_CBC_BaseFileMissing", "Base file not found: {0}", "Arquivo base não encontrado: {0}"),
 ("U_CBC_PresetCannon", "Cannon", "Canhão"),
 ("U_CBC_SourceFileMissing", "Source file not found: {0}", "Arquivo fonte não encontrado: {0}"),
 ("U_CBC_NextSteps", "Next steps:\\n", "Próximos passos:\\n"),
 ("U_CBC_UnsupportedSchema", "Unsupported recipe schema: {0}", "Schema de receita não suportado: {0}"),
 ("U_CBC_UnsupportedVersion", "Unsupported recipe version: {0}", "Versão de receita não suportada: {0}"),
 ("U_CBC_BaseMonsterMissing", "Base monster m{0:D3} does not exist in the loaded project.", "Monstro base m{0:D3} não existe no projeto carregado."),
 ("U_CBC_AiSourceFileMissing", "AI source file not found: {0}", "Arquivo da fonte de IA não encontrado: {0}"),
 ("U_CBC_AiNoFile", "m{0:D3} has no AiFile to copy.", "m{0:D3} não tem AiFile para copiar."),
 ("U_CBC_AiValidationFailed", "AI of m{0:D3} failed ATEL validation: {1}", "IA de m{0:D3} falhou validação ATEL: {1}"),
 ("U_CBC_LootSourceFileMissing", "Loot source file not found: {0}", "Arquivo da fonte de loot não encontrado: {0}"),
 ("U_CBC_LootNoFile", "m{0:D3} has no LootFile to copy.", "m{0:D3} não tem LootFile para copiar."),
("U_CBC_AiFilePending", "AI: {0} m{1:D3} {2}; file not found yet.", "IA: {0} m{1:D3} {2}; arquivo ainda não encontrado."),
 ("U_CBC_AiNoRealFile", "AI: {0} m{1:D3} {2}; this monster has no real AiFile.", "IA: {0} m{1:D3} {2}; este monstro não tem AiFile real."),
 ("U_CBC_AiReadFailed", "AI: could not read m{0:D3} {1}: {2}", "IA: não foi possível ler m{0:D3} {1}: {2}"),
 ("U_CBC_LootFilePending", "Loot: {0} m{1:D3} {2}; file not found yet.", "Loot: {0} m{1:D3} {2}; arquivo ainda não encontrado."),
 ("U_CBC_LootNoRealFile", "Loot: {0} m{1:D3} {2}; this monster has no real LootFile.", "Loot: {0} m{1:D3} {2}; este monstro não tem LootFile real."),
 ("U_CBC_LootReadFailed", "Loot: could not read m{0:D3} {1}: {2}", "Loot: não foi possível ler m{0:D3} {1}: {2}"),
 ("U_CBC_RecipeOutputInvalid", "Recipe: invalid output directory; sidecar not written.", "Receita: diretório de saída inválido; sidecar não gravado."),
 ("U_CBC_RecipePath", "Recipe: {0}", "Receita: {0}"),
 ("U_CBC_RecipeWriteFailed", "Recipe: failed to write .bossrecipe.json ({0}).", "Receita: falha ao gravar .bossrecipe.json ({0})."),
 ("U_CBC_AiSourceMissing", "AI source m{0:D3} does not exist in the loaded project.", "Fonte de IA m{0:D3} não existe no projeto carregado."),
 ("U_CBC_LootSourceMissing", "Loot source m{0:D3} does not exist in the loaded project.", "Fonte de loot m{0:D3} não existe no projeto carregado."),
 ("U_CBC_PreviewNoMonster", "Preview: select a base monster.", "Preview: selecione um monstro base."),
 ("U_CBC_AiInherit", "AI: inherited from the selected base monster.", "IA: herdada do monstro base selecionado."),
 ("U_CBC_LootInherit", "Loot: inherited from the selected base monster.", "Loot: herdado do monstro base selecionado."),
 ("U_CBC_InheritAiBase", "Inherit AI from base", "Herdar IA da base"),
 ("U_CBC_InheritLootBase", "Inherit loot from base", "Herdar loot da base"),
 ("U_CBC_FinalLootInherit", "Final loot: inherit from m{0:D3} {1}.", "Loot final: herdar de m{0:D3} {1}."),
 ("U_CBC_FinalLootCopyBlock", "Final loot: copy full block from m{0:D3} {1}.", "Loot final: copiar bloco inteiro de m{0:D3} {1}."),
 ("U_CBC_LootFileCopy", "LootFile: copy drops/steal/gear/rewards from m{0:D3} {1}", "LootFile: copiar drops/steal/gear/recompensas de m{0:D3} {1}"),
]


def esc_xml(s):
    return s.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;')


def esc_cs(s):
    return s.replace('\\', '\\\\').replace('"', '\\"')


# Strings.cs
cs_lines = []
for k, en, pt in KEYS:
    cs_lines.append('    public static string {0} => Get(nameof({0}));'.format(k))
cs_block = '\n'.join(cs_lines)
cs = io.open('FFXProjectEditor/Resources/Strings.cs', encoding='utf-8').read()
insert_at = cs.rfind('\n}')
cs = cs[:insert_at] + '\n    // ── CustomBossCreator UI (String.Format on {0..N} placeholders) PT→EN 2026-08-18.\n' + cs_block + cs[insert_at:]
io.open('FFXProjectEditor/Resources/Strings.cs', 'w', encoding='utf-8', newline='').write(cs)
print('Strings.cs added', len(KEYS))

# resx neutro (EN)
en_lines = ['  <!-- CustomBossCreator UI PT->EN 2026-08-18 -->']
for k, en, pt in KEYS:
    en_lines.append('  <data name="{0}" xml:space="preserve"><value>{1}</value></data>'.format(k, esc_xml(en)))
resx = io.open('FFXProjectEditor/Resources/Strings.resx', encoding='utf-8').read()
resx = resx.rstrip()
resx = resx[:resx.rfind('</root>')] + '\n' + '\n'.join(en_lines) + '\n</root>\n'
io.open('FFXProjectEditor/Resources/Strings.resx', 'w', encoding='utf-8', newline='').write(resx)
print('resx EN added', len(KEYS))

# resx PT satellite
pt_lines = ['  <!-- CustomBossCreator UI PT->EN 2026-08-18 -->']
for k, en, pt in KEYS:
    pt_lines.append('  <data name="{0}" xml:space="preserve"><value>{1}</value></data>'.format(k, esc_xml(pt)))
resp = io.open('FFXProjectEditor/Resources/Strings.pt.resx', encoding='utf-8').read()
resp = resp.rstrip()
resp = resp[:resp.rfind('</root>')] + '\n' + '\n'.join(pt_lines) + '\n</root>\n'
io.open('FFXProjectEditor/Resources/Strings.pt.resx', 'w', encoding='utf-8', newline='').write(resp)
print('resx PT added', len(KEYS))
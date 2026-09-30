# -*- coding: utf-8 -*-
"""
Onda 2 da migracao i18n (Jarvis-IFRIT, 2026-08-02):
1) 50 chaves Common* nos 9 resx (EN neutro + PT traduzido + ES/FR/DE/IT/JA/KO/ZH = EN,
   sem corpus oficial para UI do editor).
2) Reuso de chaves existentes: 'Session Controls'->SessionControls, 'Salvar'->ActionSave.
3) Varredura em TODOS os .axaml de Modules (exceto MonsterAiEditor2* — regra dura)
   com substituicao exata (atributo, valor) -> {x:Static res:Strings.Chave}.
"""
import json, os, re, sys

ROOT = r"C:\Users\wande\Documents\ffx-editor-main"
RESX_DIR = os.path.join(ROOT, "FFXProjectEditor", "Resources")
MODULES_DIR = os.path.join(ROOT, "FFXProjectEditor", "Modules")

# (chave, EN, PT)
COMMON = [
    ("CommonInherited", "Inherited", "herdado"),
    ("CommonClose", "Close", "Fechar"),
    ("CommonValue", "Value", "valor"),
    ("CommonSourceRoot", "Source Root", "Source Root"),
    ("CommonApply", "Apply", "Aplicar"),
    ("CommonInterpretation", "Interpretation", "Interpretation"),
    ("CommonRequiredItem", "Required Item", "Required Item"),
    ("CommonWarnings", "Warnings", "Warnings"),
    ("CommonHeadHex", "Head Hex", "Head Hex"),
    ("CommonFocus", "Focus", "Foco"),
    ("CommonName", "Name", "Name"),
    ("CommonSummary", "Summary", "Summary"),
    ("CommonPreviewApply", "Apply Preview", "Preview de apply"),
    ("CommonHumanPreview", "Human Preview", "Pr\u00e9via humana"),
    ("CommonValidation", "Validation", "Validation"),
    ("CommonKind", "Kind", "Kind"),
    ("CommonType", "Type", "Type"),
    ("CommonEvidenceGuardrail", "Evidence / Guardrail", "Evidence / Guardrail"),
    ("CommonBibleOfSpira", "BIBLE OF SPIRA", "BIBLE OF SPIRA"),
    ("CommonNoWriter", "no writer", "sem writer"),
    ("CommonCategoryLower", "category", "categoria"),
    ("CommonTargetLower", "target", "alvo"),
    ("CommonStatusLower", "status", "status"),
    ("CommonSearchAbilityByHex", "Search ability by name or hex", "Pesquisar habilidade por nome ou hex"),
    ("CommonClear", "Clear", "Limpar"),
    ("CommonFocusFromV2", "Focus from V2", "Foco vindo do V2"),
    ("CommonTarget", "Target", "Target"),
    ("CommonDescription", "Description", "Description"),
    ("CommonPendingDiff", "Pending Diff", "Pending Diff"),
    ("CommonOffset", "Offset", "Offset"),
    ("CommonField", "Field", "Field"),
    ("CommonQuantity", "Quantity", "Quantity"),
    ("CommonPower", "Power", "Power"),
    ("CommonKernelRecipes", "Kernel Recipes", "Kernel Recipes"),
    ("CommonRecipeEditor", "Recipe Editor", "Recipe Editor"),
    ("CommonRecipeMode", "Recipe Mode", "Recipe Mode"),
    ("CommonExtension", "Extension", "Extension"),
    ("CommonCategory", "Category", "Category"),
    ("CommonStats", "Stats", "Stats"),
    ("CommonHonestRead", "Honest read", "Leitura honesta"),
    ("CommonPlantFieldStat", "Plant field/stat", "Plantar field/stat"),
    ("CommonNewAbilityTarget", "New ability target", "alvo da habilidade nova"),
    ("CommonApplyToMonster", "Apply to monster", "Aplicar no monstro"),
    ("CommonPlusCommonPhase", "+ common phase", "+ fase comum"),
    ("CommonPlusLastPhase", "+ last phase", "+ \u00faltima fase"),
    ("CommonRemovePhase", "remove phase", "remover fase"),
    ("CommonRequireHpLess", "Require HP &lt;", "Exigir HP &lt;"),
    ("CommonCommandHex", "Command (0x####)", "Comando (0x####)"),
    ("CommonPosX", "PosX", "PosX"),
    ("CommonPosY", "PosY", "PosY"),
    ("CommonUsDescription", "US Description", "US Description"),
]

# reuso de chaves existentes: (atributo, valor) -> chave
REUSE = {
    ("Text", "Session Controls"): "SessionControls",
    ("Header", "Session Controls"): "SessionControls",
    ("Content", "Session Controls"): "SessionControls",
    ("Text", "Salvar"): "ActionSave",
    ("Header", "Salvar"): "ActionSave",
    ("Content", "Salvar"): "ActionSave",
}

RESX_FILES = {
    "": "Strings.resx", "pt": "Strings.pt.resx", "es": "Strings.es.resx",
    "fr": "Strings.fr.resx", "de": "Strings.de.resx", "it": "Strings.it.resx",
    "ja": "Strings.ja.resx", "ko": "Strings.ko.resx", "zh": "Strings.zh.resx",
}

ATTRS = ("Text", "Content", "Header", "Watermark", "ToolTip.Tip")


def write_utf8(path, text, had_bom):
    with open(path, "w", encoding="utf-8-sig" if had_bom else "utf-8", newline="") as f:
        f.write(text)

def update_resx():
    for suffix, fname in RESX_FILES.items():
        path = os.path.join(RESX_DIR, fname)
        with open(path, "rb") as f:
            had_bom = f.read(3) == b"\xef\xbb\xbf"
        raw = open(path, encoding="utf-8-sig").read()
        body = raw.rstrip()
        assert body.endswith("</root>"), f"{fname}: </root> nao encontrado"
        body = body[: -len("</root>")].rstrip()

        lines = ["", "  <!-- ===== Common UI terms — Onda 2 i18n (v2.214.2.0, Jarvis-IFRIT) ===== -->"]
        for key, en, pt in COMMON:
            v = pt if suffix == "pt" else en
            lines.append(f'  <data name="{key}" xml:space="preserve"><value>{v}</value></data>')
        write_utf8(path, body + "\n" + "\n".join(lines) + "\n</root>\n", had_bom)
        print(f"[resx] {fname}: +{len(COMMON)} chaves")


def iter_axaml():
    for root, dirs, files in os.walk(MODULES_DIR):
        for fn in files:
            if not fn.endswith(".axaml"):
                continue
            if "MonsterAiEditor2" in fn:  # regra dura: descontinuado
                continue
            yield os.path.join(root, fn)


def update_axaml():
    total = 0
    files_touched = 0
    for path in sorted(iter_axaml()):
        with open(path, "rb") as f:
            had_bom = f.read(3) == b"\xef\xbb\xbf"
        txt = open(path, encoding="utf-8-sig").read()
        orig = txt
        count = 0
        # reuso
        for (attr, val), key in REUSE.items():
            txt, n = re.compile(re.escape(f'{attr}="{val}"')).subn(
                f'{attr}="{{x:Static res:Strings.{key}}}"', txt)
            count += n
        # chaves comuns
        for key, en, pt in COMMON:
            for attr in ATTRS:
                txt, n = re.compile(re.escape(f'{attr}="{en}"')).subn(
                    f'{attr}="{{x:Static res:Strings.{key}}}"', txt)
                count += n
            if pt != en:
                for attr in ATTRS:
                    txt, n = re.compile(re.escape(f'{attr}="{pt}"')).subn(
                        f'{attr}="{{x:Static res:Strings.{key}}}"', txt)
                    count += n
        if "xmlns:res=" not in txt and 'mc:Ignorable' in txt:
            txt = txt.replace("mc:Ignorable",
                              'xmlns:res="clr-namespace:FFXProjectEditor.Resources"\n             mc:Ignorable', 1)
        if txt != orig:
            write_utf8(path, txt, had_bom)
            total += count
            files_touched += 1
            print(f"[axaml] {os.path.relpath(path, MODULES_DIR)}: {count}")
    print(f"[axaml] TOTAL: {total} substituicoes em {files_touched} arquivos")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--resx-only":
        update_resx()
    elif len(sys.argv) > 1 and sys.argv[1] == "--axaml-only":
        update_axaml()
    else:
        update_resx()
        update_axaml()


# -*- coding: utf-8 -*-
"""
Onda 1 da migracao i18n (Jarvis-CLINE, assumida 2026-08-02):
1) Gera as 25 chaves Term* nos 9 resx (EN neutro + PT + ES/FR/DE/IT com
   traducoes OFICIAIS do jogo via E:\\Text\\terms_latin.json; JA/KO/ZH = EN,
   font-bank pendente). IT com lacuna 'Niente' cai para EN (fallback honesto).
2) Substitui literais hardcoded exatos nos .axaml dos modulos ATIVOS por
   {x:Static res:Strings.TermX} e garante xmlns:res no header.

Seguranca: MonsterAiEditor2 DESCONTINUADO -> nunca tocar; substituicao exata
por atributo+valor (nao pega 'Cost Overdrive' nem 'statusCheck'); PT preserva
EN (sem corpus PT oficial; UI atual nao muda).
"""
import json, os, re, sys

ROOT = r"C:\Users\wande\Documents\ffx-editor-main"
RESX_DIR = os.path.join(ROOT, "FFXProjectEditor", "Resources")
MODULES_DIR = os.path.join(ROOT, "FFXProjectEditor", "Modules")
TERMS_JSON = r"E:\Text\terms_latin.json"

TERMS = [
    ("TermWeapon", "Weapon"), ("TermArmor", "Armor"), ("TermStatus", "Status"),
    ("TermOverdrive", "Overdrive"), ("TermScan", "Scan"),
    ("TermDistillPower", "Distill Power"), ("TermDistillMana", "Distill Mana"),
    ("TermDistillSpeed", "Distill Speed"), ("TermDistillAbility", "Distill Ability"),
    ("TermShield", "Shield"), ("TermBoost", "Boost"), ("TermEject", "Eject"),
    ("TermCurse", "Curse"), ("TermDefend", "Defend"), ("TermGuard", "Guard"),
    ("TermSentinel", "Sentinel"), ("TermDoom", "Doom"), ("TermLuck", "Luck"),
    ("TermEquipment", "Equipment"), ("TermKeyItems", "Key Items"),
    ("TermFormation", "Formation"), ("TermTidus", "Tidus"), ("TermRikku", "Rikku"),
    ("TermAbilities", "Abilities"), ("TermItems", "Items"),
]

RESX_FILES = {
    "": "Strings.resx", "pt": "Strings.pt.resx", "es": "Strings.es.resx",
    "fr": "Strings.fr.resx", "de": "Strings.de.resx", "it": "Strings.it.resx",
    "ja": "Strings.ja.resx", "ko": "Strings.ko.resx", "zh": "Strings.zh.resx",
}

REPLACEMENTS = [
    ("Text", "Weapon", "TermWeapon"), ("Text", "Armor", "TermArmor"),
    ("Text", "Status", "TermStatus"), ("Header", "Status", "TermStatus"),
    ("Text", "Overdrive", "TermOverdrive"), ("Content", "Scan", "TermScan"),
    ("Content", "Distill Power", "TermDistillPower"),
    ("Content", "Distill Mana", "TermDistillMana"),
    ("Content", "Distill Speed", "TermDistillSpeed"),
    ("Content", "Distill Ability", "TermDistillAbility"),
    ("Content", "Shield", "TermShield"), ("Content", "Boost", "TermBoost"),
    ("Content", "Eject", "TermEject"), ("Content", "Curse", "TermCurse"),
    ("Content", "Defend", "TermDefend"), ("Content", "Guard", "TermGuard"),
    ("Content", "Sentinel", "TermSentinel"), ("Content", "Doom", "TermDoom"),
    ("Content", "Luck", "TermLuck"), ("Header", "Equipment", "TermEquipment"),
    ("Header", "Key Items", "TermKeyItems"), ("Text", "Formation", "TermFormation"),
    ("Header", "Tidus", "TermTidus"), ("Header", "Rikku", "TermRikku"),
    ("Text", "Abilities", "TermAbilities"), ("Text", "Items", "TermItems"),
]

AXAML_TARGETS = [
    r"BattleKernel\Commands\KernelCommands_Control.axaml",
    r"MonEditor\MonEditor_Control.axaml",
    r"CustomBossCreator\CustomBossCreator_Control.axaml",
    r"InventoryTracker\InventoryTracker_Control.axaml",
    r"LiveBattleLab\LiveBattleLab_Control.axaml",
    r"MonsterAiEditor\MonsterAiEditor_Control.axaml",
    r"SaveEditor\SaveEditorCharacter_Control.axaml",
    r"SaveEditor\SaveEditorItems_Control.axaml",
    r"WeaponGear\WeaponGear_Control.axaml",
]


def write_utf8(path, text, had_bom):
    with open(path, "w", encoding="utf-8-sig" if had_bom else "utf-8", newline="") as f:
        f.write(text)

def update_resx():
    terms = json.load(open(TERMS_JSON, encoding="utf-8"))
    for suffix, fname in RESX_FILES.items():
        path = os.path.join(RESX_DIR, fname)
        with open(path, "rb") as f:
            had_bom = f.read(3) == b"\xef\xbb\xbf"
        raw = open(path, encoding="utf-8-sig").read()
        assert raw.rstrip().endswith("</root>"), f"{fname}: </root> nao encontrado"

        lines = ["", "  <!-- ===== Game terms — Onda 1 i18n (v2.214.1.0, Jarvis-CLINE) ===== -->"]
        for key, en in TERMS:
            if suffix in ("es", "fr", "de", "it"):
                v = terms.get(en, {}).get(suffix, en)
                if v == "Niente":  # lacuna IT de slot -> fallback EN honesto
                    v = en
            else:
                v = en  # neutro/PT/JA/KO/ZH: EN (PT sem corpus oficial; JA/KO/ZH font-bank pendente)
            lines.append(f'  <data name="{key}" xml:space="preserve"><value>{v}</value></data>')
        block = "\n".join(lines)
        # remove o </root> original (raw ainda o contem) e reinsere com o bloco
        body = raw.rstrip()
        assert body.endswith("</root>"), f"{fname}: </root> nao encontrado"
        body = body[: -len("</root>")].rstrip()
        write_utf8(path, body + "\n" + block + "\n</root>\n", had_bom)
        print(f"[resx] {fname}: +{len(TERMS)} chaves")


def update_axaml():
    total = 0
    for rel in AXAML_TARGETS:
        path = os.path.join(MODULES_DIR, rel)
        with open(path, "rb") as f:
            had_bom = f.read(3) == b"\xef\xbb\xbf"
        txt = open(path, encoding="utf-8-sig").read()
        orig = txt
        count = 0
        for attr, val, key in REPLACEMENTS:
            pattern = re.compile(re.escape(f'{attr}="{val}"'))
            txt, n = pattern.subn(f'{attr}="{{x:Static res:Strings.{key}}}"', txt)
            count += n
        if "xmlns:res=" not in txt and 'mc:Ignorable' in txt:
            txt = txt.replace("mc:Ignorable",
                              'xmlns:res="clr-namespace:FFXProjectEditor.Resources"\n             mc:Ignorable', 1)
        if txt != orig:
            write_utf8(path, txt, had_bom)
            total += count
            print(f"[axaml] {rel}: {count} substituicoes")
        else:
            print(f"[axaml] {rel}: (sem mudancas)")
    print(f"[axaml] TOTAL: {total} substituicoes")


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--resx-only":
        update_resx()
    elif len(sys.argv) > 1 and sys.argv[1] == "--axaml-only":
        update_axaml()
    else:
        update_resx()
        update_axaml()


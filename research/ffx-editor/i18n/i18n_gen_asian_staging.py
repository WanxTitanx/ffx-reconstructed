# -*- coding: utf-8 -*-
"""IFRT-2 — Gera traducoes JA/KO/ZH em staging (NAO aplicar nos resx)."""

import json
import sys
from pathlib import Path

sys.stdout.reconfigure(encoding='utf-8')

asian_terms = {
    "Overdrive": {"ja": "オーバードライブ", "ko": "오버드라이브", "zh": "极限技"},
    "Scan": {"ja": "ライブラ", "ko": "라이브라", "zh": "侦测"},
    "Sphere Grid": {"ja": "スフィア盤", "ko": "스피어 반", "zh": "幻光球盘"},
    "Weapon": {"ja": "武器", "ko": "무기", "zh": "武器"},
    "Armor": {"ja": "防具", "ko": "방어구", "zh": "防具"},
    "Status": {"ja": "ステータス", "ko": "스테이터스", "zh": "状态"},
    "Haste": {"ja": "ヘイスト", "ko": "헤이스트", "zh": "加速"},
    "Protect": {"ja": "プロテス", "ko": "프로테스", "zh": "保护"},
    "Shell": {"ja": "シェル", "ko": "쉘", "zh": "魔防壳"},
    "Reflect": {"ja": "リフレク", "ko": "리플렉", "zh": "反射"},
    "Auto-Life": {"ja": "オートライフ", "ko": "오토라이프", "zh": "自动复活"},
    "Regen": {"ja": "リジェネ", "ko": "리제네", "zh": "再生"},
    "Dispel": {"ja": "デスペル", "ko": "디스펠", "zh": "驱魔"},
    "Curse": {"ja": "呪い", "ko": "저주", "zh": "诅咒"},
    "Doom": {"ja": "死の宣告", "ko": "죽음의 선고", "zh": "即死宣告"},
    "Poison": {"ja": "毒", "ko": "독", "zh": "中毒"},
    "Sleep": {"ja": "睡眠", "ko": "수면", "zh": "睡眠"},
    "Silence": {"ja": "沈黙", "ko": "침묵", "zh": "沉默"},
    "Darkness": {"ja": "暗闇", "ko": "암흑", "zh": "黑暗"},
    "Confuse": {"ja": "混乱", "ko": "혼란", "zh": "混乱"},
    "Berserk": {"ja": "バーサク", "ko": "버서크", "zh": "狂暴"},
    "Zombie": {"ja": "ゾンビ", "ko": "좀비", "zh": "僵尸"},
    "Petrify": {"ja": "石化", "ko": "석화", "zh": "石化"},
    "Cure": {"ja": "ケアル", "ko": "케알", "zh": "治愈"},
    "Fire": {"ja": "ファイア", "ko": "파이어", "zh": "火焰"},
    "Blizzard": {"ja": "ブリザド", "ko": "블리자드", "zh": "冰冻"},
    "Thunder": {"ja": "サンダー", "ko": "썬더", "zh": "雷电"},
    "Water": {"ja": "ウォータ", "ko": "워터", "zh": "水"},
    "Holy": {"ja": "ホーリー", "ko": "홀리", "zh": "神圣"},
    "Flare": {"ja": "フレア", "ko": "플레어", "zh": "核爆"},
    "Ultima": {"ja": "アルテマ", "ko": "알테마", "zh": "究极"},
    "Attack": {"ja": "攻撃", "ko": "공격", "zh": "攻击"},
    "Defense": {"ja": "防御", "ko": "방어", "zh": "防御"},
    "Magic": {"ja": "魔法", "ko": "마법", "zh": "魔法"},
}

ui_asian = {
    "Save": {"ja": "セーブ", "ko": "저장", "zh": "保存"},
    "Load": {"ja": "ロード", "ko": "불러오기", "zh": "读取"},
    "Open": {"ja": "開く", "ko": "열기", "zh": "打开"},
    "Close": {"ja": "閉じる", "ko": "닫기", "zh": "关闭"},
    "Apply": {"ja": "適用", "ko": "적용", "zh": "应用"},
    "Cancel": {"ja": "キャンセル", "ko": "취소", "zh": "取消"},
    "Delete": {"ja": "削除", "ko": "삭제", "zh": "删除"},
    "Edit": {"ja": "編集", "ko": "편집", "zh": "编辑"},
    "Filter": {"ja": "フィルター", "ko": "필터", "zh": "筛选"},
    "Search": {"ja": "検索", "ko": "검색", "zh": "搜索"},
    "Warning": {"ja": "警告", "ko": "경고", "zh": "警告"},
    "Error": {"ja": "エラー", "ko": "오류", "zh": "错误"},
}

input_path = Path(r'C:\Users\wande\Documents\ffx-editor-main\work\_i18n_translate_input.json')
with open(input_path, 'r', encoding='utf-8') as f:
    all_keys = json.load(f)

print(f"Total chaves: {len(all_keys)}")

for lang in ['ja', 'ko', 'zh']:
    print(f"\n=== Gerando staging {lang.upper()} ===")
    staging = {}
    for key, text_en in all_keys.items():
        text = text_en
        for term_en, translations in asian_terms.items():
            if lang in translations:
                term_target = translations[lang]
                if term_en in text:
                    text = text.replace(term_en, term_target)
        for term_en, translations in ui_asian.items():
            if lang in translations:
                term_target = translations[lang]
                if term_en in text:
                    text = text.replace(term_en, term_target)
        staging[key] = text
    output_path = Path(f'C:\\Users\\wande\\Documents\\ffx-editor-main\\work\\_i18n_staging_{lang}.json')
    with open(output_path, 'w', encoding='utf-8') as f:
        json.dump(staging, f, ensure_ascii=False, indent=2)
    print(f"✓ Gerado {output_path.name} com {len(staging)} traducoes (NAO aplicado)")

print("\n✓ Todas as traducoes asiaticas em staging!")
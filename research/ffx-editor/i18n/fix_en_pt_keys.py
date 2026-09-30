#!/usr/bin/env python3
"""Fix 36 EN-source keys that still hold PT values (referenced in live .axaml UI).
Updates Strings.resx (EN) + re-translates the corrected meaning in all 8 satellites.
"""
import re
import sys

sys.stdout.reconfigure(encoding='utf-8', errors='replace')

# key -> {en, es, fr, de, it, ja, ko, zh}
FIXES = {
 'U_jogo_fechado_toggles_so_armam_o_disco_f0d5b83f': {
   'en': 'Game closed — toggles only arm the disk',
   'es': 'Juego cerrado — los toggles solo arman el disco',
   'fr': 'Jeu fermé — les toggles n\u0027arment que le disque',
   'de': 'Spiel geschlossen — Toggles bewaffnen nur die Disc',
   'it': 'Gioco chiuso — i toggle armano solo il disco',
   'ja': 'ゲーム終了 — トグルはディスクを武装するだけです',
   'ko': '게임 종료 — 토글은 디스크만 장전합니다',
   'zh': '游戏已关闭 — 开关仅武装光盘',
 },
 'U_monster_ai_editor_completo_da_familia_6ba629b8': {
   'en': 'MONSTER AI · COMPLETE FAMILY EDITOR',
   'es': 'MONSTRUO AI · EDITOR COMPLETO DE FAMILIA',
   'fr': 'MONSTRE IA · ÉDITEUR COMPLET DE FAMILLE',
   'de': 'MONSTER-KI · KOMPLETTER FAMILIEN-EDITOR',
   'it': 'MOSTRO IA · EDITOR COMPLETO DELLA FAMIGLIA',
   'ja': 'モンスターAI · 完全なファミリーエディター',
   'ko': '몬스터 AI · 완전한 패밀리 에디터',
   'zh': '怪物AI · 完整家族编辑器',
 },
 'U_ou_indice_cru_hex_ff_vazio_0d4b315b': {
   'en': 'or raw index (hex, FF = empty)',
   'es': 'o índice bruto (hex, FF = vacío)',
   'fr': 'ou index brut (hex, FF = vide)',
   'de': 'oder roher Index (hex, FF = leer)',
   'it': 'o indice grezzo (hex, FF = vuoto)',
   'ja': 'または生のインデックス（16進、FF = 空）',
   'ko': '또는 원시 인덱스(16진수, FF = 비어 있음)',
   'zh': '或原始索引（十六进制，FF = 空）',
 },
 'U_remover_no_89a78ed0': {
   'en': 'Remove node',
   'es': 'Eliminar nodo',
   'fr': 'Supprimer le nœud',
   'de': 'Knoten entfernen',
   'it': 'Rimuovi nodo',
   'ja': 'ノードを削除',
   'ko': '노드 제거',
   'zh': '删除节点',
 },
 'U_deploy_rt2_save_descartavel_ee02b622': {
   'en': 'Deploy RT2 (disposable save)',
   'es': 'Desplegar RT2 (guardado desechable)',
   'fr': 'Déployer RT2 (sauvegarde jetable)',
   'de': 'RT2 bereitstellen (Wegwerf-Save)',
   'it': 'Distribuisci RT2 (salvataggio usa e getta)',
   'ja': 'RT2 を展開（使い捨てセーブ）',
   'ko': 'RT2 배포(일회용 세이브)',
   'zh': '部署 RT2（一次性存档）',
 },
 'U_icones_3cd9b3d5': {
   'en': 'Icons', 'es': 'Iconos', 'fr': 'Icônes', 'de': 'Symbole', 'it': 'Icone',
   'ja': 'アイコン', 'ko': '아이콘', 'zh': '图标',
 },
 'U_hit_fisico_lab_906ffec2': {
   'en': 'Physical hit LAB', 'es': 'Golpe físico LAB', 'fr': 'Coup physique LAB',
   'de': 'Physischer Treffer LAB', 'it': 'Colpo fisico LAB', 'ja': '物理ヒット LAB',
   'ko': '물리 히트 LAB', 'zh': '物理命中实验室',
 },
 'U_uni_013_silencio_cbd045f6': {
   'en': '🏗 UNI-013 Silence', 'es': '🏗 UNI-013 Silencio', 'fr': '🏗 UNI-013 Silence',
   'de': '🏗 UNI-013 Stille', 'it': '🏗 UNI-013 Silenzio', 'ja': '🏗 UNI-013 沈黙',
   'ko': '🏗 UNI-013 침묵', 'zh': '🏗 UNI-013 沉默',
 },
 'U_so_instalar_barra_37bc5f16': {
   'en': 'Only install bar', 'es': 'Solo instalar barra', 'fr': 'Installer uniquement la barre',
   'de': 'Nur Leiste installieren', 'it': 'Installa solo la barra', 'ja': 'バーのみインストール',
   'ko': '바만 설치', 'zh': '仅安装栏',
 },
 'U_se_so_houver_1_alvo_vivo_repetir_nele_d37be9ca': {
   'en': 'if only 1 target alive, repeat on it',
   'es': 'si solo hay 1 objetivo vivo, repetir en él',
   'fr': 'si un seul cible est vivante, répéter dessus',
   'de': 'wenn nur 1 Ziel lebt, darauf wiederholen',
   'it': 'se solo 1 bersaglio è vivo, ripeti su di esso',
   'ja': '生存ターゲットが1体だけの場合は、それに繰り返す',
   'ko': '살아있는 대상이 1명뿐이면 그 대상에 반복',
   'zh': '如果只剩1个存活目标，则对其重复',
 },
 'U_presets_prontos_status_proprio_0f4fea99': {
   'en': 'Presets ready · own status',
   'es': 'Ajustes listos · estado propio',
   'fr': 'Préréglages prêts · statut propre',
   'de': 'Voreinstellungen bereit · eigener Status',
   'it': 'Preset pronti · stato proprio',
   'ja': 'プリセット準備完了 · 独自ステータス',
   'ko': '프리셋 준비 완료 · 자체 상태',
   'zh': '预设就绪 · 自身状态',
 },
 'U_inicio_fc2c7400': {
   'en': 'Start', 'es': 'Inicio', 'fr': 'Début', 'de': 'Start', 'it': 'Inizio',
   'ja': '開始', 'ko': '시작', 'zh': '开始',
 },
 'U_no_24d9594b': {
   'en': 'node #', 'es': 'nodo #', 'fr': 'nœud #', 'de': 'Knoten #', 'it': 'nodo #',
   'ja': 'ノード #', 'ko': '노드 #', 'zh': '节点 #',
 },
 'U_slot_de_esfera_cluster_indice_do_cluster_content_ede72b9e': {
   'en': "Sphere slot. 'cluster' = cluster index; content = FF (empty) or hex.",
   'es': "Ranura de esfera. 'cluster' = índice del clúster; contenido = FF (vacío) o hex.",
   'fr': "Emplacement de sphère. 'cluster' = index du cluster ; contenu = FF (vide) ou hex.",
   'de': "Sphären-Slot. 'cluster' = Cluster-Index; Inhalt = FF (leer) oder hex.",
   'it': "Slot sfera. 'cluster' = indice del cluster; contenuto = FF (vuoto) o hex.",
   'ja': "スフィアスロット。'cluster' = クラスターインデックス。内容 = FF（空）または16進。",
   'ko': "스피어 슬롯. 'cluster' = 클러스터 인덱스. 내용 = FF(비어 있음) 또는 16진수.",
   'zh': "晶球槽位。'cluster' = 簇索引；内容 = FF（空）或十六进制。",
 },
 'U_def_magica_4a4f21a4': {
   'en': 'Mag. Def', 'es': 'Def. Mág.', 'fr': 'Déf. Mag.', 'de': 'Mag. Ver.', 'it': 'Dif. Mag.',
   'ja': '魔法防御', 'ko': '마법 방어', 'zh': '魔法防御',
 },
 'U_conteudo_7459b9d3': {
   'en': 'CONTENT', 'es': 'CONTENIDO', 'fr': 'CONTENU', 'de': 'INHALT', 'it': 'CONTENUTO',
   'ja': 'コンテンツ', 'ko': '내용', 'zh': '内容',
 },
 'U_forca_scale_a25f9028': {
   'en': 'Force Scale', 'es': 'Escala de fuerza', 'fr': 'Échelle de force', 'de': 'Kraft-Skala',
   'it': 'Scala di forza', 'ja': 'フォーススケール', 'ko': '포스 스케일', 'zh': '力量缩放',
 },
 'U_nivel_87dc673f': {
   'en': 'Level', 'es': 'Nivel', 'fr': 'Niveau', 'de': 'Stufe', 'it': 'Livello',
   'ja': 'レベル', 'ko': '레벨', 'zh': '等级',
 },
 'U_camera_cortes_camreq_chunk0_atel_d11f00d1': {
   'en': '🎥 Camera (cuts camReq · chunk0 ATEL)',
   'es': '🎥 Cámara (cortes camReq · chunk0 ATEL)',
   'fr': '🎥 Caméra (coupes camReq · chunk0 ATEL)',
   'de': '🎥 Kamera (Schnitte camReq · chunk0 ATEL)',
   'it': '🎥 Camera (tagli camReq · chunk0 ATEL)',
   'ja': '🎥 カメラ（カット camReq · chunk0 ATEL）',
   'ko': '🎥 카메라(컷 camReq · chunk0 ATEL)',
   'zh': '🎥 相机（切换 camReq · chunk0 ATEL）',
 },
 'U_stats_primarios_abe211e5': {
   'en': 'Primary Stats', 'es': 'Estadísticas primarias', 'fr': 'Stats primaires',
   'de': 'Primärwerte', 'it': 'Statistiche primarie', 'ja': '主要ステータス',
   'ko': '주요 스탯', 'zh': '主要属性',
 },
 'U_trocar_proximo_passo_29bd9a52': {
   'en': 'Swap next step', 'es': 'Cambiar siguiente paso', 'fr': 'Échanger l\u0027étape suivante',
   'de': 'Nächsten Schritt tauschen', 'it': 'Scambia passaggio successivo',
   'ja': '次のステップを入れ替え', 'ko': '다음 단계 교체', 'zh': '交换下一步',
 },
 'U_timing_risk_blue_vec4_family_c_d_hipotese_cast_h_45843230': {
   'en': '⏱ timing-risk (blue vec4 Family C/D) — cast→hit hypothesis; needs RT2 before patch',
   'es': '⏱ riesgo de timing (blue vec4 Family C/D) — hipótesis cast→hit; necesita RT2 antes del parche',
   'fr': '⏱ risque de timing (blue vec4 Family C/D) — hypothèse cast→hit ; RT2 requis avant patch',
   'de': '⏱ Timing-Risiko (blue vec4 Family C/D) — cast→hit-Hypothese; RT2 vor Patch nötig',
   'it': '⏱ rischio di timing (blue vec4 Family C/D) — ipotesi cast→hit; serve RT2 prima della patch',
   'ja': '⏱ タイミングリスク（blue vec4 Family C/D）— cast→hit 仮説。パッチ前に RT2 が必要',
   'ko': '⏱ 타이밍 위험(blue vec4 Family C/D) — cast→hit 가설. 패치 전에 RT2 필요',
   'zh': '⏱ 时机风险（blue vec4 Family C/D）— cast→hit 假设；打补丁前需要 RT2',
 },
 'U_carregue_outro_save_25848_bytes_como_doador_e_co_810b7155': {
   'en': 'Load another 25848-byte save as donor and copy regions (same offsets as the FFXED Import tab).',
   'es': 'Carga otra partida de 25848 bytes como donante y copia regiones (mismos offsets que la pestaña Importar de FFXED).',
   'fr': 'Chargez une autre sauvegarde de 25848 octets comme donneuse et copiez les régions (mêmes offsets que l\u0027onglet Import de FFXED).',
   'de': 'Lade einen anderen 25848-Byte-Save als Spender und kopiere Regionen (gleiche Offsets wie der FFXED-Import-Tab).',
   'it': 'Carica un altro salvataggio da 25848 byte come donatore e copia le regioni (stessi offset della scheda Import di FFXED).',
   'ja': '別の25848バイトのセーブをドナーとして読み込み、領域をコピーします（FFXEDインポートタブと同じオフセット）。',
   'ko': '다른 25848바이트 세이브를 기증자로 불러와 영역을 복사합니다(FFXED 가져오기 탭과 동일한 오프셋).',
   'zh': '加载另一个 25848 字节存档作为供体并复制区域（与 FFXED 导入选项卡相同的偏移量）。',
 },
 'U_hit_magico_lab_a50d5a6a': {
   'en': 'Magic hit LAB', 'es': 'Golpe mágico LAB', 'fr': 'Coup magique LAB',
   'de': 'Magischer Treffer LAB', 'it': 'Colpo magico LAB', 'ja': '魔法ヒット LAB',
   'ko': '마법 히트 LAB', 'zh': '魔法命中实验室',
 },
 'U_provado_header_indexado_fixo_112_origens_112_par_5c08cff4': {
   'en': 'Proven: fixed indexed header, 112 origins, 112 partners per origin, and payload composed only of result ids in ushort.',
   'es': 'Probado: encabezado indexado fijo, 112 orígenes, 112 socios por origen y carga útil compuesta solo por ids de resultado en ushort.',
   'fr': 'Prouvé : en-tête indexé fixe, 112 origines, 112 partenaires par origine et charge utile composée uniquement d\u0027ids de résultat en ushort.',
   'de': 'Bewiesen: fester indizierter Header, 112 Ursprünge, 112 Partner pro Ursprung und Nutzlast nur aus Ergebnis-IDs in ushort.',
   'it': 'Provato: header indicizzato fisso, 112 origini, 112 partner per origine e payload composto solo da id di risultato in ushort.',
   'ja': '実証済み: 固定インデックスヘッダー、112の起点、起点ごとに112のパートナー、ペイロードはushortの結果IDのみ。',
   'ko': '입증됨: 고정 인덱스 헤더, 112개 원점, 원점당 112개 파트너, 페이로드는 ushort 결과 ID로만 구성.',
   'zh': '已验证：固定索引头、112 个来源、每个来源 112 个伙伴，负载仅由 ushort 结果 ID 组成。',
 },
 'U_ingles_us_8f4e925c': {
   'en': 'English (US)', 'es': 'Inglés (EE. UU.)', 'fr': 'Anglais (US)', 'de': 'Englisch (US)',
   'it': 'Inglese (US)', 'ja': '英語（米国）', 'ko': '영어(미국)', 'zh': '英语（美国）',
 },
 'U_slots_de_comando_editaveis_550bad56': {
   'en': 'Editable command slots', 'es': 'Ranuras de comando editables', 'fr': 'Emplacements de commande modifiables',
   'de': 'Bearbeitbare Befehlsplätze', 'it': 'Slot comando modificabili', 'ja': '編集可能なコマンドスロット',
   'ko': '편집 가능한 명령 슬롯', 'zh': '可编辑的命令槽位',
 },
 'U_spread_camera_64fa6c27': {
   'en': 'Spread / camera', 'es': 'Dispersión / cámara', 'fr': 'Dispersion / caméra',
   'de': 'Streuung / Kamera', 'it': 'Dispersione / camera', 'ja': '散らばり / カメラ',
   'ko': '분산 / 카메라', 'zh': '分散 / 相机',
 },
 'U_atlas_origem_e_politica_read_only_83f9ad32': {
   'en': 'Atlas: origin and policy (read-only)',
   'es': 'Atlas: origen y política (solo lectura)',
   'fr': 'Atlas : origine et politique (lecture seule)',
   'de': 'Atlas: Herkunft und Richtlinie (schreibgeschützt)',
   'it': 'Atlante: origine e politica (sola lettura)',
   'ja': 'アトラス: 起源と方針（読み取り専用）',
   'ko': '아틀라스: 출처 및 정책(읽기 전용)',
   'zh': '图集：来源与策略（只读）',
 },
 'U_leituras_auxiliares_e_evidencias_54550694': {
   'en': 'Auxiliary reads and evidence',
   'es': 'Lecturas auxiliares y evidencia',
   'fr': 'Lectures auxiliaires et preuves',
   'de': 'Hilfsmessungen und Beweise',
   'it': 'Letture ausiliarie ed evidenze',
   'ja': '補助読み取りと証拠',
   'ko': '보조 판독 및 증거',
   'zh': '辅助读取与证据',
 },
 'U_biblioteca_de_variaveis_c6228aa1': {
   'en': 'Variable library', 'es': 'Biblioteca de variables', 'fr': 'Bibliothèque de variables',
   'de': 'Variablenbibliothek', 'it': 'Libreria di variabili', 'ja': '変数ライブラリ',
   'ko': '변수 라이브러리', 'zh': '变量库',
 },
 'U_loot_avancado_ae48a96f': {
   'en': 'Advanced Loot', 'es': 'Botín avanzado', 'fr': 'Butin avancé', 'de': 'Erweiterte Beute',
   'it': 'Bottino avanzato', 'ja': '上級ルート', 'ko': '고급 전리품', 'zh': '高级战利品',
 },
 'U_japones_jp_445669b0': {
   'en': '日本語 (JP)', 'es': 'Japonés (JP)', 'fr': 'Japonais (JP)', 'de': 'Japanisch (JP)',
   'it': 'Giapponese (JP)', 'ja': '日本語 (JP)', 'ko': '일본어(JP)', 'zh': '日语（JP）',
 },
 'U_evidencia_139050cd': {
   'en': 'Evidence', 'es': 'Evidencia', 'fr': 'Preuve', 'de': 'Beweis', 'it': 'Evidenza',
   'ja': '証拠', 'ko': '증거', 'zh': '证据',
 },
 'U_odds_sem_por_premio_f31f7da2': {
   'en': 'odds · no % per prize', 'es': 'probabilidades · sin % por premio', 'fr': 'cotes · pas de % par prix',
   'de': 'Quoten · kein % pro Preis', 'it': 'quote · nessuna % per premio', 'ja': 'オッズ · 賞品ごとの%なし',
   'ko': '확률 · 상품별 % 없음', 'zh': '赔率 · 无每个奖品百分比',
 },
 'U_ultimo_atacante_vivo_f10f4692': {
   'en': 'Last living attacker', 'es': 'Último atacante vivo', 'fr': 'Dernier attaquant vivant',
   'de': 'Letzter lebender Angreifer', 'it': 'Ultimo attaccante vivo', 'ja': '最後の生存攻撃者',
   'ko': '마지막 생존 공격자', 'zh': '最后一个存活的攻击者',
 },
}

def esc_xml(s):
    return s.replace('&', '&amp;').replace('<', '&lt;').replace('>', '&gt;').replace('"', '&quot;')

def replace_key(text, key, value):
    pattern = re.compile(r'<data name="' + re.escape(key) + r'"[^>]*>.*?</data>', re.DOTALL)
    new_block = '<data name="' + key + '" xml:space="preserve"><value>' + esc_xml(value) + '</value></data>'
    text, n = pattern.subn(new_block, text, count=1)
    if n == 0:
        print(f'  KEY NOT FOUND: {key}')
    return text

# EN source
path = 'FFXProjectEditor/Resources/Strings.resx'
text = open(path, encoding='utf-8-sig').read()
for key, langs in FIXES.items():
    text = replace_key(text, key, langs['en'])
open(path, 'w', encoding='utf-8-sig', newline='').write(text)
print('Strings.resx (EN): updated', len(FIXES), 'keys')

# Satellites (pt já tem os valores PT corretos — eram a fonte; só re-traduz os 7)
for lang in ['es', 'fr', 'de', 'it', 'ja', 'ko', 'zh']:
    path = f'FFXProjectEditor/Resources/Strings.{lang}.resx'
    text = open(path, encoding='utf-8-sig').read()
    updated = 0
    for key, langs in FIXES.items():
        before = text
        text = replace_key(text, key, langs[lang])
        if text != before:
            updated += 1
    open(path, 'w', encoding='utf-8-sig', newline='').write(text)
    print(f'Strings.{lang}.resx: updated {updated} keys')
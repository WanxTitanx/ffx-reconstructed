import json, sys
sys.stdout.reconfigure(encoding="utf-8", errors="replace")

# Gera docs/reverse/PPP_FAMILIES_VISUAL_SEMANTICS_20260802.md
tbl = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/noclip_reference/instruction_table_20260802.json"))
fm = json.load(open(r"C:/Users/wande/Documents/ffx-editor-main/work/magic_editor/field_map.json", encoding="utf-8"))
pc = {k: v for k, v in fm["families"].items() if v.get("payload_consumer")}

# familia -> (classe_noclip, confianca, comportamento_visual)
MAP = {
    "pppAccele": ("Velocity", "ALTA", "Acumula velocidade (double-layer: layerB += delta; layerA += layerB). Visual: particula ganha velocidade constante na direcao do vetor."),
    "pppMove": ("Velocity", "ALTA", "Movimento/translacao (byte-idêntico ao Accele). Visual: translada por frame."),
    "pppSclMove": ("PosScale", "ALTA", "Movimento de escala acumulado em X/Y/Z. Visual: cresce/encolhe continuamente (T4 provado no Power Break)."),
    "pppSclAccele": ("PosScale", "ALTA", "Aceleracao de escala (double-layer). Visual: crescimento acelerado."),
    "pppAngMove": ("SetValue", "MEDIA", "Movimento angular (int32 acumulado em graus). Visual: rotacao continua."),
    "pppAngMoveLoop": ("LoopStep", "ALTA", "Movimento angular em LOOP (int32[3]) — bate com LoopStep vecP/ivecP. Visual: rotacao ciclica repetida."),
    "pppAngAccele": ("SetValue", "MEDIA", "Aceleracao angular (mira/tracking — T4 observado). Visual: rotacao acelera ate travar no alvo."),
    "pppAngle": ("SetValue", "ALTA", "Angulo/rotacao (acumulador por frame — T4 observado). Visual: rotacao animada."),
    "pppAngleLoop": ("LoopStep", "ALTA", "Angulo em LOOP com init de handle. Visual: rotacao ciclica."),
    "pppPoint": ("SetPos", "ALTA", "Posicao/ponto (single-layer; maior corpus). Visual: posiciona/teleporta a particula."),
    "pppColMove": ("ColorVelocity", "ALTA", "Movimento de cor (u16[4]). Visual: cor muda continuamente."),
    "pppColAccele": ("ColorVelocity", "MEDIA", "Aceleracao de cor (handler byte-idêntico ao ColMove)."),
    "pppColor": ("ColorVelocity", "MEDIA", "Cor direta (regra de ouro: fora da fila)."),
    "pppDrawMdlTs": ("SimpleGeo", "ALTA", "Draw de textura: 6x f32 deltas init + indice de recurso (x32 na tabela de descritores). Visual: modelo/textura com pos/rot/scale animados."),
    "pppDrawMdlTs2": ("SimpleGeo", "MEDIA", "Variante Ts (TypeE)."),
    "pppDrawMdlTs3": ("SimpleGeo", "MEDIA", "Variante Ts (Locale)."),
    "pppDrawMdlLoop": ("SimpleGeo", "MEDIA", "Draw em LOOP (INIT + flags). Visual: modelo repetido em ciclo."),
    "pppDrawMdlLoopZ": ("SimpleGeo", "MEDIA", "Draw loop com magic-id checks (Z)."),
    "pppDrawMdlLoopDisPos": ("SimpleGeo", "MEDIA", "Draw loop sem translacao (DisPos)."),
    "pppDrawMdlCameraLoop": ("SimpleGeo", "MEDIA", "Draw loop com camera (fmod 32768). Visual: orientado a camera."),
    "pppDrawMdlSemi": ("SimpleGeo", "MEDIA", "Draw semi (so resource key 4B). Visual: modelo com blend semi-transparente."),
    "pppDrawMdl3": ("SimpleGeo", "MEDIA", "Draw tipo 3 (so key)."),
    "pppDrawMdlSea": ("SimpleGeo", "BAIXA", "Draw sea (so key; HIPO)."),
    "pppDrawFilter": ("WrapUVScrollGeo", "ALTA", "Filtro de projecao: wrap X/Y (<<8) + clamp [0, wrap<<8) — sem match word. Visual: projecao com wraparound (bate com WrapUVScrollGeo)."),
    "pppKeTh": ("ChildSetup", "MEDIA", "Thread de animacao (RenderSceneObject): 16 canais u16 de bone + 9 f32 + angulo deg->rad + flags. Visual: scene object (mesh) com animacao de ossos."),
    "pppKeThSft": ("ChildSetup", "MEDIA", "Shift de thread (AcumulateAnimationDelta): 16x u16 canais + 4 f32 + flag. Visual: acumula deltas de ossos."),
    "pppKeMdlTfd": ("UVScrollGeo", "MEDIA", "Transform de modelo (9 f32 em X/Y/Z + flags; double-layer). Visual: transforma/desloca UVs."),
    "pppKeMdlTfd2": ("UVScrollGeo", "MEDIA", "Transform tipo 2 (5 f32 + u8s — NAO segue o padrao do base 49B)."),
    "pppKeMdlTfd3": ("UVScrollGeo", "MEDIA", "Transform tipo 3 (5 f32 + u8s ate +33)."),
    "pppKeMdlTfdUv": ("UVScrollGeo", "MEDIA", "Transform UV (49B, handler compartilhado com o base)."),
    "pppKeMdlTfdUv2": ("UVScrollGeo", "MEDIA", "Transform UV tipo 2 (49B provado)."),
    "pppRandChar": ("RandomStep", "ALTA", "Random char (u8 seed + flag; RNG real srand/RandomFloat01). Visual: valor aleatorio u8 no alvo por frame."),
    "pppRandUpChar": ("RandomStep.range(POSITIVE)", "ALTA", "Random char clamp POSITIVO."),
    "pppRandDownChar": ("RandomStep.range(NEGATIVE)", "ALTA", "Random char clamp NEGATIVO."),
    "pppRandShort": ("RandomStep", "ALTA", "Random short (u16 value + flag — 7B)."),
    "pppRandUpShort": ("RandomStep.range(POSITIVE)", "ALTA", "Random short clamp up."),
    "pppRandDownShort": ("RandomStep.range(NEGATIVE)", "ALTA", "Random short clamp down."),
    "pppRandInt": ("RandomStep", "ALTA", "Random int (u32 value + flag — 9B)."),
    "pppRandUpInt": ("RandomStep.range(POSITIVE)", "ALTA", "Random int clamp up."),
    "pppRandDownInt": ("RandomStep.range(NEGATIVE)", "ALTA", "Random int clamp down."),
    "pppRandCV": ("RandomCube", "MEDIA", "Random color vector (4x s8). Visual: cor aleatoria (4 componentes)."),
    "pppRandUpCV": ("RandomCube.range(POSITIVE)", "MEDIA", "Random CV clamp up."),
    "pppRandDownCV": ("RandomCube.range(NEGATIVE)", "MEDIA", "Random CV clamp down."),
    "pppRandHCV": ("RandomCube", "MEDIA", "Random half-color (4x s16 + flag; RNG real)."),
    "pppEiWindFun": ("Velocity", "MEDIA", "Vento: 6 f32 init + 3 f32 deltas + magnitude/norm. Visual: particula arrastada por campo de vento."),
    "pppNeiPointLight": ("PointLight", "ALTA", "Point light de vizinhanca (3 f32 + handles). Visual: luz pontual ilumina vizinhos (bate com PointLight/PointLightGroup)."),
}
print("mapas:", len(MAP))
json.dump(MAP, open(r"C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/visual_map_20260802.json", "w"), ensure_ascii=False, indent=1)
print("visual_map salvo")

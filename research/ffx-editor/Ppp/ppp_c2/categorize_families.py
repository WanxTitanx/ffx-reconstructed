#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Categoriza as 184 familias PPP por uso (nome + semantica provada + crossref noclip)."""
import glob, json, collections

files = glob.glob(r"C:/Users/wande/Documents/ffx-editor-main/work/ppp_c2/families/*.json")
ops = sorted(json.load(open(f, encoding="utf-8-sig"))["opcode"] for f in files)

USOS = {
    # prefixo -> (categoria, uso descritivo)
    "pppKeThRes": ("KeTh/Recursos", "aloca cadeia de nodes (NxS) para dados de thread/efeito; KeThRes32/48 = allocators"),
    "pppKeTh": ("KeTh/Thread", "thread de animacao: 16 canais u16 de bone + 4 floats + flag; propaga node0->node1"),
    "pppKeGrv": ("Ke/Gravidade", "gravidade/efeito de campo (Eff) ou target (Tgt)"),
    "pppKeBorn": ("Ke/Nascimento", "randomizacao de nascimento de particulas (Rnd2/3/5/6 = variantes)"),
    "pppKeHit": ("Ke/Impacto", "hit/colisao (HitBall, HitChkPxB = check por pixel)"),
    "pppKeLns": ("Ke/Lentes", "efeito de lente (Arnd=around, Clm=column, Crn=corner, Fls=flash, Lp=loop)"),
    "pppKeShp": ("Ke/Shape", "shape/tail de forma (Tail2/3/X, Dtt=dot)"),
    "pppKeDMat": ("Ke/Matriz", "matriz de draw (DMat, DMatFr, DMatPht, DMatPhtFr)"),
    "pppKeZCrct": ("Ke/CorrecaoZ", "correcao de profundidade Z (Crct, CrctShp)"),
    "pppKeDrct": ("Ke/Direcao", "direcao"),
    "pppKeMdl": ("Ke/Modelo", "modelo (Dtt, Tfd)"),
    "pppKeMatSN": ("Ke/MatrizSN", "matriz special"),
    "pppKeMvYp": ("Ke/MoveYp", "movimento Y"),
    "pppDrawMdl": ("Draw/Modelo", "draw de modelo/textura: Ts (texture slot), Loop, Camera, Sea, Semi, 2/3 = variantes"),
    "pppDrawShape": ("Draw/Shape", "draw de shape geometrico (X, Rev, Field, Camera, Spd = variantes)"),
    "pppDrawMatrix": ("Draw/Matriz", "matriz de draw (Front, Loop, NoRot, Wood)"),
    "pppDrawFilter": ("Draw/Filtro", "filtro de projecao com wrap X/Y (clamp)"),
    "pppDrawRain": ("Draw/Chuva", "chuva"),
    "pppMatrix": ("Matriz", "transformacao matriz (XYZ, XZY, YXZ, ZXY = ordens Euler; Loc=local; Scl=escala; Loop)"),
    "pppParMatrix": ("Matriz/Parent", "matriz do parent"),
    "pppRand": ("Rand", "random: FV=float vector, IV=int vector, HCV=half color vector, Down/Up = decrescente/crescente"),
    "pppSRand": ("Rand/S", "random suavizado (mesma familia, variantes S)"),
    "pppFpPointLight": ("Light", "point light de campo (Model, Vsf, Scl = variantes)"),
    "pppNeiPointLight": ("Light", "point light de vizinhanca (acumula acc/vel/pos)"),
    "pppNeiLightEikyo": ("Light", "efeito de luz de vizinhanca"),
    "pppVertex": ("Vertex", "vertex: Ap=apply, At=at, DisPos=deslocado, Lc=local, Attend=atenua"),
    "pppVtMime": ("Vertex", "vertex mime"),
    "pppScl": ("U1/Escala", "escala: SclMove (movimento), SclAccele (aceleracao), SclMoveLoop"),
    "pppScale": ("U1/Escala", "escala (single-layer acumulador do bone)"),
    "pppScaleLoop": ("U1/Escala", "escala em loop"),
    "pppMove": ("U1/Movimento", "movimento/translacao (double-layer)"),
    "pppAccele": ("U1/Aceleracao", "aceleracao (double-layer)"),
    "pppPoint": ("U1/Ponto", "posicao/ponto (single-layer)"),
    "pppPointLoop": ("U1/Ponto", "ponto em loop"),
    "pppPointAp": ("U1/Ponto", "aplica ponto"),
    "pppAng": ("U1/Angulo", "angulo: AngMove, AngAccele, AngMoveLoop (int32)"),
    "pppAngle": ("U1/Angulo", "angulo (single-layer, int32)"),
    "pppAngleLoop": ("U1/Angulo", "angulo em loop (com init)"),
    "pppCol": ("U1/Cor", "cor: ColMove (u16[4]), ColAccele"),
    "pppColor": ("U1/Cor", "cor (fora do caminho critico - regra de ouro)"),
    "pppEi": ("U1/Vento", "vento/efeitos: EiWindFun (velocidade do vento), EiWfacc, EiZCrctDisPos"),
    "pppFaceAp": ("U1/Face", "face/aparencia"),
    "pppOverlay": ("Draw/Overlay", "overlay de tela"),
}

cats = collections.defaultdict(list)
for op in ops:
    matched = False
    for prefix, (cat, uso) in sorted(USOS.items(), key=lambda kv: -len(kv[0])):
        if op.startswith(prefix):
            cats[cat].append(op)
            matched = True
            break
    if not matched:
        cats["Outros"].append(op)

out = []
for cat, items in sorted(cats.items()):
    out.append(f"{cat} ({len(items)}): {', '.join(items)}")
print("\n".join(out))

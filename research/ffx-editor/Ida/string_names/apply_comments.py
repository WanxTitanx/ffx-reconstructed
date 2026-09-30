#!/usr/bin/env python3
"""Evidence comments for string-naming sweep (leva 7). [DEVIN-STR] tag."""
import json, sys
sys.path.insert(0, '.')
from mcp import Mcp

C = []
def cmt(a, s): C.append({"addr": a, "comment": s})

T = "[DEVIN-STR L7] "

# ---- renamed, with evidence ----
cmt("0x7dcd90", T+"CONFIRMADO: formata path de MOTION SRC de monstro 'host0:/home/%s/battle/%s/mon/_m%03d/mt%03d.src' (era 'FormatCameraSrcPath' — errado).")
cmt("0x7dd4f0", T+"CONFIRMADO: gera arquivo de macros de motion ('// player motion macro at %s', '#macro player_%02d_motion_set($1)', 'summon_%02d_motion_set') — authoring/debug. Era 'Camera_FieldApplyEventLookat' — errado.")
cmt("0x76ba80", T+"CONFIRMADO: instalado no slot de callback 'cd_read' por FFX_Mscd_RegisterCallbacks (libmscd.c). Enfileira pedido de leitura CD/fila Mscd (64 regs x 56B em 0x1127CB0). Era 'FieldMap_WalkStruct_SkyData'.")
cmt("0x76c080", T+"CONFIRMADO: variante estendida do cd_read (resolve DVD FILE/HDD FILE, setor=a3/2048+ResolveFileEntry). Slot 0x2310CD0. Era 'FieldMap_WalkStruct_LightSource'.")
cmt("0x70e3b0", T+"CONFIRMADO: FmodShout::initData — strings 'FmodShout::initData: NULL == mShoutFsb'/'eventSystem' + FmodShout.cpp. Carrega ffx_{us,jp}_voice_btl_iop_bank00.fsb (shouts de batalha).")
cmt("0x70e560", T+"CONFIRMADO: metodo FmodShout (FmodShout.cpp). Toca subsound nomeado do banco shout (header 'ML'+tabela de pares id->nome, getSubSound).")
cmt("0x70e4e0", T+"CONFIRMADO: metodo FmodShout (FmodShout.cpp:217) — Channel::setVolume se getVolume==0.")
cmt("0x70e530", T+"CONFIRMADO: metodo FmodShout (FmodShout.cpp:133) — Sound::release.")
cmt("0x708e30", T+"CONFIRMADO: helper de FmodMusic::initData (chamado 2x p/ ffx_music.fev + ffx_music_PS2.fev). Descarrega projeto atual, EventSystem::load(.fev), pega categoria 'music'. String: 'FmodMusic::initData: NULL == mEventProject!'.")
cmt("0x708810", T+"CONFIRMADO: metodo FmodMusic (FmodMusic.cpp:349). Libera+zera UM slot de evento de 60B se ev!=0 && f4==0 && state!=1. Era 'SoundCmd_HandlerCmd23'.")
cmt("0x708900", T+"CONFIRMADO: metodo FmodMusic — varre 182 slots x 60B liberando os idle (f4==0 && state!=1). Era 'SoundCmd_HandlerCmd2D'.")
cmt("0x708be0", T+"CONFIRMADO: metodo FmodMusic (FmodMusic.cpp:853) — libera TODOS os slots nao-nulos. Era 'SoundCmd_HandlerCmd3E'.")
cmt("0x7089f0", T+"CONFIRMADO: metodo FmodMusic — comando play: marca slot+24=1, +28=arg, checa parada do atual, ReadEventByRuntimeId+PlayTrackByIndex; caminho alt = pause+fade (SetEventVolume/FadeEventVolume). Era 'SoundCmd_HandlerCmd2F'.")
cmt("0x708f40", T+"CONFIRMADO: metodo FmodMusic — tick por frame dos 182 slots: SetEventVolumeByState, countdown de fade (+36/+40), auto StopEventByIndex+ReleaseEventSlot ao fim. Era 'SoundCmd_HandlerCmd4D'.")
cmt("0x7e0f20", T+"CONFIRMADO: init do pre-processador de field script (monta tabela char-class '#0123.._/\"'/;/*' + hash '#include' + zera skip-stack 16B). Chamado por PositionEditorHandler antes de ParseFile.")
cmt("0x7e1500", T+"CONFIRMADO: dispatcher de diretivas do pre-processador (case1=#include->ParseFile recursivo; case2/3=#define->DefineMacro; case6/7=skip push/pop; case8=#undef; case9=...). Tokens '%s : '/'%d : '.")
cmt("0x7e2180", T+"CONFIRMADO: loop por arquivo do pre-processador: OpenAndReadToBuffer, emite linemarkers '# %d \"%s\"', parse linha a linha -> HandleDirective/ExpandMacro.")
cmt("0x7e2680", T+"CONFIRMADO: registra macro #define (args: nome, parametros, corpo, funcLike=n2!=2) na tabela hash. Chamado por HandleDirective cases 2/3.")
cmt("0x7e2970", T+"CONFIRMADO: lookup de identificador via ComputeStringDoubleHash + expansao recursiva de macro (chama a si mesma).")
cmt("0x7d7fc0", T+"CONFIRMADO: handler de 17 comandos (0x8001-0x8011) da janela debug de posicoes; cria text elements '<','>' etc; case que chama ParserInit+ParseFile p/ ler 'BattlePos <%s>'/'%d:%d' de arquivo ('read %s'/'not found %s').")
cmt("0x6dd4e0", T+"CONFIRMADO: dump debug de VRAM -> 'WIN32_%s_%s_%lld.csv' ('addr,size,memtype,desc', '[MemoryDebug] Dump vram details'). Nada a ver com HUD gauge. So PC/Win32 (msg diz que dump real so PS3/PSV).")
cmt("0x86e540", T+"CONFIRMADO: aplica flags de visibilidade do ator de campo (+0x33b6=show -> SetVisibilityConditional(1), +0x38b12='TK:Force Disable Hide:%d' -> hide; garante motion residente via +0x36b14/b13; copia ray-result +0x9C->+0xA4).")
cmt("0x7e7f40", T+"CONFIRMADO: implementacao do op 'op_m_normalize' (math.c) — debug print '*** Calling op_m_normalize() math.c:%d ***'.")
cmt("0x7e8a10", T+"CONFIRMADO: implementacao do op 'op_mul_m33' (math.c) — M33 (3x3), NAO M44 como dizia o nome antigo. Operandos via GlobalSetter C8F548/C8F54C.")
cmt("0x8409a0", T+"CONFIRMADO (chr/cache.c): evictor de overflow do cache — varre tabela de entries 0x1302F58..0x13030E8 escolhendo o de menor prioridade (nibble&7 < limiar), loga 'Memory overflow!! [CHR/MOT/MAP/BGM :%s:%d] disposed from Cache' e chama ResourceCache_FreeEntry.")
cmt("0x7e45c0", T+"CONFIRMADO: e o op ATEL 'op_oef2_clut_load' — string 'Virtuos ERROR: CLUTINFO was null in Yonishi op_oef2_clut_load'.")
cmt("0x80b960", T+"CONFIRMADO: op original 'opu_part_run' (u_15.c, npart) — FIXME 'osu->malloc is NULL in opu_part_run() u_15.c from yonishi'. Opcode 0xDD do magic VM.")
cmt("0x80bea0", T+"CONFIRMADO: 'opp_main' — WARNING 'Yonishi effect func ptr in opp_main() is NULL!! skipping..'. Runner principal de programas de particula (ms_effect_from_magicfile, work buffer 1024).")
cmt("0x814610", T+"CONFIRMADO: op 'opu_bind2' — '(op)\\topu_bind2\\t\\tno ground id(%d)'. Opcode 0xD4, bind de particula a ground id.")
cmt("0x814b60", T+"CONFIRMADO: op 'u_file_tc' — '(op)\\tu_file_tc[]\\ttexture clut data write file chrno(0x%x)'; dump debug de CLUT p/ 'host0:/home/yonishi/ffx/dat/t_%4x_%d.txc'. Opcode 0xDF.")
cmt("0x665390", T+"CONFIRMADO: carrega shader 'PS3Data/Shaders/GCM/MenuDefaultShaderNA.cgfx.phyre' (PStreamReaderFile + Shader_LoadFromPath + ResolveAndRefStrings em this+16034). Era 'ComputeBlendBlockTextureUv' — errado.")

# ---- _structural drops ----
for a, ev in [
    ("0x6657f0", "carrega TexList.txt de dat_et/bat_eff/et_tex/tex e et_ffx/tex (paths literais)."),
    ("0x6714a0", "registra entradas de tex list; strings 'NNNNN_19_0_0_1_1.dds.phyre'."),
    ("0x6e7180", "alterna icone keyboard_icon.dds.phyre/pad_icon.dds.phyre."),
    ("0x6e7430", "idem (variancia por estado)."),
    ("0x7cd730", "grava arquivo de texto de menu: 'write file <%s>'/'error file <%s>'/'%s\\n%d\\n'."),
    ("0x7d1e80", "tabela debug de tags de camera '%2d:%2d'/'HEI %%'/'len %%'."),
    ("0x7d7a50", "print debug 'ply %d ply %d %fm'/'ply %d mon %d %fm'."),
    ("0x7d9620", "display debug de slots 'NULL:%3d'/'%4d:%3d'."),
    ("0x7dcdd0", "formata paths 'host0:/home/%s/program/mk/%s/mot_%s.src' (+battle/mot_w_ variants)."),
    ("0x7dce80", "monta linhas 'motion_type_attack_run_00_01'/'_miss'/'_return' etc p/ setstat debug."),
    ("0x7dd390", "emite '// monster %03d motion macro at %s'."),
    ("0x7dd7a0", "monitor debug: '<save:%s>'/'ply_%02d'/'mon_%03d'."),
    ("0x7e1da0", "le argumento '(...)' do script (inicia em char 40='(')."),
    ("0x7e5b20", "'can't open file %s' + le arquivo p/ buffer alocado."),
    ("0x7e5be0", "'can't open file %s' + tamanho do arquivo."),
    ("0x7e6a60", "hex dump '(op)\\tmem(size=%d byte)\\t[%s]($%8x)' + linhas 8x'%8x'."),
    ("0x7ff280", "carrega 'dat_et/et_ffx.bin'+'dat_et/bat_eff/et_tex.bin'; erro 'odat_et_ffx file could not be found, path: %s'."),
    ("0x7e37b0", "'OEF2 SET DATA particle data for VFX!! group=%d particle offset=%d'."),
    ("0x7e3a80", "reloc secoes OEF2: 'op_oef2_set error : '/'Final particle ofset=%d'/'pppDataHeader - table'."),
    ("0x713870", "'Virtuos Error: Have not load the vfx texture %d!/%s!' + '99999_19_0_0_128_128.dds.phyre'."),
    ("0x715bd0", "idem; monta nomes '%d_%d_0_0_%d_%d.dds.phyre' (15040_19_0_0_128_128.dds.phyre)."),
    ("0x81f320", "init/reset da fila SPU (zera bloco de globals; dump '%s %d, %4d, %4d : %8.8X')."),
    ("0x825ac0", "model browser debug: '/ffx/proj2/chr/prot/%s/%s' + '[%s:%s]VIEWCHRDATA'."),
    ("0x826f20", "init CHR: '/ffx/proj2/chr/common/%s.tbl' + 'sizeof(CHR)=%x'."),
    ("0x829f70", "load CHR async: '[%s:%s]CHRDATA'/'SG:RomRead:%s %x'."),
    ("0x8405f0", "'Can't find cache yet=%d id=%s:%d [%s]' — marca estado de leitura do cache."),
    ("0x8406f0", "'CacheData isn't red yet.\\ntype=%x\\nid=%x\\nptr=%x' — aviso de pendencia."),
    ("0x843260", "'SG:dma8_loss=%d dma1_loss=%d' — checkpoint DMA sync."),
    ("0x843360", "timeout VIF1 DMA: 'SG:Mainloop DmaSync(1ch) Timeout' + dump VIF1_STAT/D1_CHCR/FBRST/MADR/ERR/QWC."),
    ("0x86dde0", "pop float da VM de campo: 'TK:float:STACKP:%d'/'TK:ID:%dPC:%x'."),
    ("0x8781b0", "'Read: group = %d/ index = %d/adrs = 0x%x' — le grupo de encounter da save stack."),
    ("0xa445f0", "'abiritymap_debug(%d)' — handler debug da ability map (FuncD000 CALL)."),
    ("0xa79980", "'chReadSystemMGRP %04x %x fin' — callback de fim de leitura MGRP."),
    ("0x7810f0", "monta '/usr/local/ffx/%s/ps2/sound' + '%s_%02d' e carrega grupo/formacao de encounter enfileirados."),
    ("0x7a4930", "print debug de batalha '***** %d : %x : c%02d *****' (ATEL CALL)."),
    ("0x7a4a80", "print debug '##### %d : %x : c%02d #####' (ATEL CALL)."),
    ("0x80b7d0", "op 0xDC draw: 'particle data address in effect overlay was NULL. trying to skip effect' + escala por altura do ator."),
    ("0x81bcd0", "op 0x8F transform: 'anmm should never be NULL in original PS2 version' — escreve ctx de transform em records 40B."),
    ("0x80cd60", "loop principal do runtime PPP/magic; guarda 'skipping overlay function ptr call ... ef2->unit NULL osu->ucom=0x%X'."),
    ("0x7d9b40", "blit de marcadores de loc: '%3d:%3d'/'FLST%d S%d %1d:%1d:%1d:%1d:%1d'."),
    ("0x7e1c60", "lexer: le proximo token do field script (usado por HandleDirective/ReadParenthesizedArg)."),
    ("0x7e1b40", "le chunk de string e faz trim (field script parser)."),
    ("0x7e11e0", "monta tabela de classes de char do lexer ('#.._ a-z', quote, '\"', ';/*', ' \\\\t', '\\\\()', ',')."),
    ("0x7e2ca0", "monta hash de keywords/diretivas (seed '#include' em FFX_Field_Global_C44A40)."),
    ("0x7e10b0", "double-hash de identificador usado p/ lookup de macro do field script."),
    ("0x7e2de0", "abre arquivo e le todo p/ buffer (util usado por FieldScript_ParseFile)."),
    ("0x7de610", "append de string em block-buffer (usado pelo gerador de macros de motion)."),
]:
    cmt(a, T + "CONFIRMADO p/ string: " + ev)

# ---- comment-only (evidencia fraca / ja correto) ----
cmt("0x76eb40", T+"stub PC: 'Movie on Windows, PS3 & PS Vita is not impelemented yet! Call back by the movie_status_resultinfo'. INTRET da funcspace Movie B002.")
cmt("0x76ebe0", T+"stub PC: callback 'movie_pause_resultinfo' (movie nao implementado no PC).")
cmt("0x76ebf0", T+"stub PC: callback 'movie_ch_resultinfo'.")
cmt("0x76ec00", T+"stub PC: callback 'movie_vol_resultinfo'.")
cmt("0x76ec10", T+"stub PC: 'movie_start_debug_init' callback.")
cmt("0x76ec20", T+"stub PC: 'movie_start_debug_exec' callback.")
cmt("0x76ec30", T+"stub PC: 'movie_start_debug_resultinfo' callback.")
cmt("0x76ed50", T+"FuncB00B INTRET: 'Force destroy fmv player for movieId:%d' — force-destroy do player FMV.")
cmt("0x76edd0", T+"stub PC: 'movie_op_frame_draw_acc_path3_resultinfo' callback.")
cmt("0x76ede0", T+"stub PC: 'movie_frame_pal_resultinfo' callback.")
cmt("0x76f960", T+"FuncB088 CALL: controle de playback FMV (2.7KB; 'w=%d h=%d').")
cmt("0x770540", T+"FuncB088 FLOATRET: dump de estado 'ffx_hddmode=%d/cd_read.m_mode=%d/sa_menu.file_module_no=%d/sbin size=%d'.")
cmt("0x73aca0", T+"evidencia: referencia 'trxtex_%d_%d_%d.dds.phyre' — frames de texture-anim (face). Nome plausivel, mantido _structural.")
cmt("0x6f4a40", T+"evidencia fraca: referencia '.dae.phyre' — provavel load de anim de gauge via Collada-ish. Mantido _structural.")
cmt("0x6dca00", T+"evidencia: formata no '%s(%d)%s' e insere ordenado via HudGaugeCompare. Mantido _structural.")
cmt("0x67ad90", T+"probe sobre tabela resId->str terminando em 'menu/D3D11/meswin.dds.phyre'; sem efeito visivel (noop honesto).")
cmt("0x7cf820", T+"formatter debug 'free   %10d' (campo da tabela menu-def).")
cmt("0x7cf8a0", T+"formatter debug 'malloc %10d' (campo da tabela menu-def).")
cmt("0x7cfc00", T+"formatter debug 'refSetPos(%f,%f,%f)'/'camSetPos(%f,%f,%f)'/'REF %s'/'CAM %s'/'X%.4f' — dump de posicoes ref/cam.")
cmt("0x8f27b0", T+"evidencia fraca: '%5d/%5d'/'%4d/%4d' — provavel format de tempo do sistema de save. Mantido _structural.")
cmt("0x6deb62", T+"ilha de codigo SEM funcao: fprintf(stderr,'Error! Do not have enough memory in dynamic geometry memory... DynGeoMemManager.cpp') — tail da alloc.")

# ---- ilhas de codigo nao-funcao (func starts perdidos pela auto-analise) ----
MISSED = [
    ("0x927570", "rcPacket.c — allocs 0x40B via Heap_AllocGameArena p/ packet (ffx RcPacket_Alloc/Create)."),
    ("0x927590", "rcPacket.c — setter: PushVertex16 + grava field+4 (packet vertex push)."),
    ("0x93a720", "rcbgLoadText.c — alloc 0x10000 + loop 20x DMA-upload de fonte/texto debug (DmaTextureStub)."),
    ("0x6deb40", "DynGeoMemManager.cpp — BUMP ALLOC do dyn-geo (cursor this+8 alinhado 16B; erro 'not enough memory in dynamic geometry memory')."),
    ("0x840b00", "chr/cache.c — aging pass do cache: decrementa nibble de idade (+8>>3), coleta entries livres p/ lista 0x13030E8, SgMem_CoalesceMainHeap + ResourceCache_SortBySize."),
    ("0x70ec70", "SfxEvent.cpp — metodo: getChannelGroup->getChannel(0)->Channel::getPan = GetEventPan."),
    ("0x70ece0", "SfxEvent.cpp — metodo: Event::getVolume = GetEventVolume."),
    ("0x70ec20", "SfxEvent.cpp — metodo: InitEventState + Event::getInfo = GetEventInfo."),
    ("0x7090a0", "FmodMusic.cpp — metodo: idx<=0xB5, slot 60B, se ev!=0 && state!=1 -> Event::setPaused(flag) = SetEventPaused."),
    ("0x88e490", "tklib.c — free TkVoicePtr + heap-check + alloc 0x8000 -> TkVoicePtr = TkVoice_Alloc/Init."),
    ("0x88e4e0", "tklib.c — init: TkInitAlarm + ClearSaveValidationFlags + RenderEngine_NotifyFrameBegin + TkVoicePtr=0 = TkInit (chamado por AnimatedBg_LoadInit)."),
    ("0x92cdd0", "rcbgDebug.c — le gmobjdata.bin do mapa: AtelGetNowEventJumpMapNo -> Dbg_LoadCsvMapData -> sprintf 'host:/ffx/proj/map/master/%c%c%c%c/%s/bin/gmobjdata.bin'."),
]
for a, s in MISSED:
    cmt(a, T + "FUNC-START nao analisado (0 code xrefs; IDA nao criou funcao): " + s)

m = Mcp()
# chunk to be safe
for i in range(0, len(C), 40):
    r = m.call('append_comments', {'items': C[i:i+40]})
    print(i, r[:600])
print('total comments:', len(C))

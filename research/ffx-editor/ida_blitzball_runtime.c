// ============================================================================
// FFX.exe Blitzball RUNTIME - batch decompile (2026-08-19)
// DB: F:/ffx-reconstructed/extras/ffxoficial.exe.i64 (FFX.exe, imagebase 0x400000)
// Lane: PURE RESEARCH - nothing in FFXProjectEditor/ modified
// ============================================================================

// 1. FFX_SceneState_GetBase @ 0x785300 (size 6)
//    proto: struct FFX_SaveRamBlock *()
mov eax, offset save_ram   ; &0x112CA90 (25848-byte save payload base)
retn

// 2. FFX_Atel_DispatchNativeCall @ 0x877720 (size 73)
//    op>>12 = funcspace channel; op&0xFFF = func index. NO blitzball channel.
push ebp; mov ebp, esp
mov ecx, [ebp+arg_0]      ; n1024 opcode
mov eax, ecx; shr eax, 0Ch;  ; channel ID
mov esi, [ebp+arg_4]      ; vmContext
cmp eax, 6; jnz short L1  ; channel 6 special path
L1: mov eax, dword ptr AtelCallTargets[eax*4]
and ecx, 0FFFh; add ecx, ecx; mov eax, [eax+ecx*8]
test eax, eax; jz short L2
push [ebp+arg_C]; push [ebp+arg_8]; push esi; call eax
L2: pop esi; pop ebp; retn

// 3. FFX_Atel_FetchOpcode @ 0x869D00 (size 64)
//    bit7=0: 1-byte opcode (<<24). bit7=1: 3-byte (b1&0x7F)<<24 | b3<<8 | b2.
mov eax, [ebp+ctx]; mov eax, [eax+18h]  ; PC
mov dl, [eax]; test dl, dl; js short L3
xor ecx, ecx; movzx eax, dl; shl eax, 18h; or eax, ecx; retn
L3: movzx ecx, byte ptr [eax+2]; movzx eax, byte ptr [eax+1]
shl cx, 8; or cx, ax; and dl, 7Fh; shl eax, 18h; or eax, ecx; retn

// 4. FFX_Save_ValidateChecksum @ 0x647F20 (size 90)
//    CRC16 over 25784 bytes from save+0x40 vs stored CRC @ save+0x1A.
call instance; mov ecx, eax; call getRefBuffer
mov esi, eax; movzx edi, word ptr [esi+1Ah]
cmp dword ptr ds:0CCB9A4h, 0; jz short L4   ; debug override
L4: cmp edi, [esi+64F4h]; jnz short L5
lea eax, [esi+40h]; push eax; push 64B8h; call FFX_Save_ComputeCrc16
cmp ax, di; jz short L6
L5: xor eax, eax; retn; L6: mov eax, 1; retn

// 5. FFX_Save_ComputeCrc16 @ 0x8B1400 (size 368)
//    CRC-16/IBM-3740 poly 0x1021, accumulator 0xFFFF.
// [0x8b1440] LUT gen 8-fold shift; [0x8b1530] table-based CRC loop.

// 6. FFX_Save_ReadFile_CHAPPU @ 0x646CE0 (size 368)
//    PS3Data/saves/%02d.SAV; fopen rb; fread; ValidateChecksum.

// 7. FFX_Event_LoadObjResources @ 0x872E90 (size 1546)
//    Event loader, 251-case switch. bltz scenes loaded here.

// 8. FFX_DebugUI_SystemStatusFormat @ 0x6B9E10 (size 323)
//    "Full Blitz:	" @0x6b9e6e; "Blitz Cheat:	" @0x6b9e78.

// 9. FFX_DebugFieldMapUI_Init @ 0x6B9F60 (size 680)
//    "bltz" filter @0x6b9fab for debug field-map selector.

// 10. FFX_Ps3Data_ResolveEventObjectTexListPath @ 0x874BE0 (size 820)
//     bltz scenes bltz0000/0005/0006/0200/0201; switch 11 cases.

// 11. FFX_Atel_InitVmAndRegisterFuncspaces @ 0x86D660 (size 618)
//     PROVES NO BLITZBALL FUNCSPACE. 11 funcspaces:
//     [0]=Common [1]=Math [4]=SgEvent [5]=ChEvent [6]=Camera
//     [7]=Battle [8]=Map [9]=Mount [11]=Movie [12]=Debug [13]=AbilityMap

// 12. FFX_Field_EventParser_structural @ 0x864180 (size 4208)
//     ATEL interpreter, 123 opcode cases. Blitzball logic runs through this.

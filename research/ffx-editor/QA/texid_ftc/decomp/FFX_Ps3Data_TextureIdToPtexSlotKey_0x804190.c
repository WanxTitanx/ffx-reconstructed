// FFX Ps3Data: Texture ID to PTEX slot key
int __cdecl FFX_Ps3Data_TextureIdToPtexSlotKey(int a1, int a2)
{
  int v2; // ebx
  int v3; // esi
  __int16 v4; // ax
  int n0x2000; // eax
  int v6; // esi
  char i; // al
  int v9; // esi
  unsigned __int8 v10; // cl
  char v11; // al
  int n3; // ebx
  _DWORD *p_os_omdc_cue; // eax
  int n8; // ecx
  unsigned __int8 *v15; // ecx
  __int16 *v16; // edi
  int v17; // eax
  unsigned __int8 *v18; // ebx
  int v19; // edi
  __int64 v20; // [esp-3Ch] [ebp-70h]
  __int16 *v21; // [esp-20h] [ebp-54h]
  __int64 v22; // [esp-10h] [ebp-44h]
  __int64 v23; // [esp+8h] [ebp-2Ch]
  _DWORD v24[3]; // [esp+1Ch] [ebp-18h] BYREF
  int v25; // [esp+28h] [ebp-Ch]
  int v26; // [esp+2Ch] [ebp-8h]
  unsigned __int8 *v27; // [esp+30h] [ebp-4h]
  int savedregs; // [esp+34h] [ebp+0h] BYREF

  v2 = *(_DWORD *)(a1 + 544); /*0x80419c*/
  v27 = (unsigned __int8 *)v2; /*0x8041a2*/
  v3 = owu_chr_hd[*(unsigned __int8 *)(v2 + 24)]; /*0x8041a9*/
  v4 = *(_WORD *)(a1 + 538); /*0x8041b0*/
  v26 = v3; /*0x8041b7*/
  n0x2000 = v4 & 0xF000; /*0x8041ba*/
  if ( n0x2000 ) /*0x8041bf*/
  {
    if ( n0x2000 == 4096 ) /*0x8041ca*/
    {
      v9 = *(_DWORD *)(v2 + 168); /*0x804257*/
      FFX_Ps3Data_CommitSlotRecords(v26); /*0x804263*/
      FFX_Ps3Data_ResolveTextureSlot(v26); /*0x80426b*/
      FFX_Ps3Data_CommitTextureSlotDrawable(v9, (int)v27, a1 + 640, a1 + 704, *(__int16 *)(a1 + 530)); /*0x80428b*/
      FFX_MagicCoreOp_SetFlagByte112C9D6(1); /*0x804292*/
      v27[178] |= 1u; /*0x804297*/
      return a2 + 2; /*0x8042a4*/
    }
    else if ( n0x2000 == 0x2000 ) /*0x8041d5*/
    {
      FFX_ChrInstance_GetMagicAttachSlotB(v3, -1, -1); /*0x8041e0*/
      FFX_ChrInstance_GetMagicAttachSlotA(v3, -1, -1); /*0x8041ea*/
      HIDWORD(v22) = v2; /*0x8041f2*/
      LODWORD(v22) = 0; /*0x8041f3*/
      FFX_TextureSlot_ReleaseByKey(v22); /*0x8041f5*/
      v6 = *(char *)(v2 + 173); /*0x8041fa*/
      Engine_Thunk_6FB7A0((char *)*(&unk_12F2064 + v6)); /*0x804208*/
      *(&unk_12F2064 + v6) = 0; /*0x804210*/
      for ( i = 1; v6 > 0; i *= 2 ) /*0x80421f*/
        --v6; /*0x804221*/
      *(_BYTE *)(a1 + 827) &= ~i; /*0x80422a*/
      *(_BYTE *)(v2 + 178) &= ~1u; /*0x804230*/
      if ( !*(_BYTE *)(a1 + 827) ) /*0x804237*/
        FFX_MagicCoreOp_SetFlagByte112C9D6(0); /*0x804242*/
      return a2 + 2; /*0x80424f*/
    }
    else
    {
      return a2; /*0x8042cb*/
    }
  }
  else
  {
    v10 = *(_BYTE *)(a1 + 827); /*0x8042ae*/
    v11 = 1; /*0x8042b4*/
    n3 = 0; /*0x8042b6*/
    while ( (v10 & (unsigned __int8)v11) != 0 ) /*0x8042ba*/
    {
      ++n3; /*0x8042bc*/
      v11 *= 2; /*0x8042bd*/
      if ( n3 >= 3 ) /*0x8042c2*/
      {
        *(_BYTE *)(a1 + 528) = 1; /*0x8042c4*/
        return a2; /*0x8042c4*/
      }
    }
    *(_BYTE *)(a1 + 827) = v11 | v10; /*0x8042de*/
    v25 = FFX_Heap_Alloc(0x120000u, (void *)0x10); /*0x8042f1*/
    *(&unk_12F2064 + n3) = (void *)v25; /*0x8042f4*/
    FFX_ChrInstance_GetMagicAttachSlotB(v3, -1, 15360); /*0x8042fb*/
    FFX_ChrInstance_GetMagicAttachSlotA(v3, -1, 12000); /*0x804308*/
    FFX_Chr_SetFlagBit0(v3, 1u); /*0x804310*/
    FFX_Ps3Data_BuildSlotRecordForDrawOpInverted((int)TOMenuAbilitymapWorkAdrs, v3, 0, *(_DWORD *)(a1 + 808)); /*0x804323*/
    p_os_omdc_cue = &os_omdc_cue; /*0x80432b*/
    n8 = 0; /*0x804330*/
    while ( *p_os_omdc_cue != v3 ) /*0x804334*/
    {
      ++n8; /*0x804336*/
      p_os_omdc_cue += 4; /*0x804337*/
      if ( n8 >= 8 ) /*0x80433d*/
        goto LABEL_20; /*0x80433d*/
    }
    *p_os_omdc_cue = 0; /*0x804341*/
LABEL_20:
    v15 = v27; /*0x804347*/
    v16 = (__int16 *)(a2 + *(__int16 *)(a2 + 2)); /*0x804351*/
    v17 = v25; /*0x804353*/
    v27[173] = n3; /*0x804356*/
    *((_DWORD *)v15 + 42) = v17; /*0x80435f*/
    FFX_Magic_TransformDrawDispatchForScene( /*0x804385*/
      COERCE_FLOAT(&savedregs),
      (void *)a1,
      v15[24],
      *((float *)v15 + 15),
      (int)(v15 + 48),
      (int)(v15 + 144),
      *(char *)(a1 + 542));
    FFX_Chr_GetBoneTransform4(v26, 16, (float *)(a1 + 64)); /*0x804393*/
    v24[0] = a1; /*0x804398*/
    v18 = v27; /*0x80439b*/
    v24[1] = a1 + 64; /*0x80439e*/
    *(float *)&v24[2] = FFX_MagicHost_GetActorRuntimeScalar(v27[24]); /*0x8043af*/
    v21 = v16; /*0x8043b2*/
    v19 = v25; /*0x8043b3*/
    FFX_Ps3Data_ProcessSlotRecordChain(TOMenuAbilitymapWorkAdrs, v25, v21, (int)v24); /*0x8043bc*/
    HIDWORD(v20) = v18; /*0x8043cf*/
    LODWORD(v20) = 0; /*0x8043d0*/
    if ( FFX_Ps3Data_BuildTextureFilePath((int)v18, v20, v19, v26, 0x4000) ) /*0x8043d2*/
    {
      HIDWORD(v23) = v18; /*0x8043de*/
      LODWORD(v23) = 0; /*0x8043df*/
      FFX_TextureSlot_ValidateGeometry(v23); /*0x8043e1*/
    }
    return a2 + 4; /*0x8043ee*/
  }
}
// FFX: Field draws background animation geometry structural — draws field background animation
// FFX Field: Draw BG anim geometry
unsigned __int16 *__cdecl FFX_Field_DrawBgAnimGeometry_structural(_DWORD *a1, unsigned __int16 *a2)
{
  unsigned __int16 *v2; // edi
  char *v3; // esi
  unsigned int n12288; // eax
  int *v5; // eax
  int v7; // eax
  int v8; // esi
  int v9; // ebx
  __int64 v10; // rax
  unsigned int v11; // ecx
  __int16 *v12; // ebx
  char *v13; // eax
  unsigned __int16 *v14; // esi
  Address *Address; // esi
  void *hudContext; // edx
  FFX_CharacterId charId; // ecx
  int v18; // ebx
  __int64 v19; // rax
  __int16 *v20; // ebx
  int v21; // ecx
  _DWORD *v22; // [esp+18h] [ebp-40h]
  int v23; // [esp+1Ch] [ebp-3Ch]
  float v24; // [esp+1Ch] [ebp-3Ch]
  char *v25; // [esp+20h] [ebp-38h]
  int v26; // [esp+20h] [ebp-38h]
  int v27; // [esp+34h] [ebp-24h]
  int v28; // [esp+34h] [ebp-24h]
  __int16 n1006632960; // [esp+36h] [ebp-22h]
  int v30; // [esp+38h] [ebp-20h]
  __int16 v31; // [esp+46h] [ebp-12h]
  int savedregs; // [esp+58h] [ebp+0h] BYREF

  v2 = a2; /*0x81c61c*/
  v23 = a1[136]; /*0x81c61f*/
  v22 = (_DWORD *)a1[*(unsigned __int8 *)(v23 + 30) + 216]; /*0x81c63b*/
  v3 = FFX_MagicHost_SelectRuntimeTableSlice(v22, 4, a2[1]); /*0x81c643*/
  n12288 = *((_WORD *)a1 + 269) & 0xF000; /*0x81c64c*/
  v25 = v3; /*0x81c654*/
  if ( n12288 <= 0x3000 ) /*0x81c65c*/
  {
    if ( n12288 == 12288 ) /*0x81c662*/
    {
      nullsub_200(); /*0x81c706*/
      return a2 + 4; /*0x81c723*/
    }
    if ( (*((_WORD *)a1 + 269) & 0xF000) != 0 ) /*0x81c66a*/
    {
      if ( n12288 == 4096 ) /*0x81c671*/
      {
        FFX_Magic_UnlinkNodeFromDList(a1[234], (int)v3); /*0x81c6a8*/
        return a2 + 2; /*0x81c6c5*/
      }
      if ( n12288 != 0x2000 ) /*0x81c678*/
        return v2; /*0x81c678*/
      v5 = (int *)FFX_MagicHost_SelectRuntimeTableSlice(v22, 2, a2[2]); /*0x81c689*/
      FFX_Model_DecompressVertexAnim16k((int)v3, *v5); /*0x81c694*/
    }
    else
    {
      v7 = FFX_FieldBgAnim_CalcOpMdSize((int)v3); /*0x81c6c7*/
      v8 = FFX_Magic_OpHeapAllocRecord(a1[234], v7); /*0x81c6d8*/
      FFX_FieldBgAnim_CopyOpMdBlock(v25, v8); /*0x81c6de*/
      FFX_Magic_Oef2SetParticleData_structural((int)v22, 4, (__int16)a2[2], v8); /*0x81c6ee*/
    }
LABEL_18:
    v2 += 3; /*0x81cb19*/
    return v2; /*0x81cb1f*/
  }
  if ( n12288 == 0x4000 ) /*0x81c729*/
  {
    v18 = (__int16)a2[2]; /*0x81c991*/
    v19 = *(__int16 *)((char *)a2 + v18); /*0x81c999*/
    v20 = (__int16 *)((char *)a2 + v18); /*0x81c99a*/
    *(_QWORD *)&n1006632960 = v19; /*0x81c9a0*/
    *(_QWORD *)&n1006632960_0 = v20[2]; /*0x81c9b1*/
    n1006632960 = n1006632960_0; /*0x81c9c1*/
    v21 = v20[1]; /*0x81ca17*/
    *(_QWORD *)&n1006632960 = v20[1]; /*0x81ca19*/
    v31 = v20[3] >> 15; /*0x81ca36*/
    HIWORD(n1006632960) = v20[3]; /*0x81ca39*/
    *(_QWORD *)&n1006632960_0 = SHIWORD(n1006632960); /*0x81ca3f*/
    *((_WORD *)&n1006632960 + 3) = v31; /*0x81ca48*/
    *((_WORD *)&n16 + 3) = SHIWORD(n1006632960) >> 15; /*0x81ca5e*/
    *((_WORD *)&n1006632960 + 2) = HIWORD(v21); /*0x81ca6b*/
    *((_WORD *)&n16 + 2) = (unsigned __int64)v21 >> 48; /*0x81ca81*/
    HIWORD(n16) = (unsigned __int64)SHIWORD(n1006632960) >> 32; /*0x81ca95*/
    LOWORD(n16) = v21 >> 31; /*0x81ca9f*/
    LOWORD(n1006632960) = v21; /*0x81caab*/
    HIWORD(v30) = HIWORD(n1006632960); /*0x81caf1*/
    LOWORD(v30) = n1006632960; /*0x81caf9*/
    HIWORD(v28) = v21; /*0x81cb00*/
    LOWORD(v28) = v19; /*0x81cb04*/
    FFX_FieldBgAnim_ApplyDrawParamToOps((int)v3, v28, v30); /*0x81cb0e*/
    v2 = a2; /*0x81cb13*/
    goto LABEL_18; /*0x81cb13*/
  }
  if ( n12288 != 20480 ) /*0x81c734*/
  {
    if ( n12288 == 24576 ) /*0x81c73f*/
    {
      v9 = (__int16)a2[3]; /*0x81c745*/
      v10 = *(__int16 *)((char *)a2 + v9); /*0x81c74d*/
      v11 = *(__int16 *)((char *)a2 + v9); /*0x81c74e*/
      v12 = (__int16 *)((char *)a2 + v9); /*0x81c750*/
      *(_QWORD *)&n1006632960 = __PAIR64__(HIDWORD(v10), v11); /*0x81c754*/
      *(_QWORD *)&n1006632960_0 = v12[2]; /*0x81c765*/
      LODWORD(v10) = v12[1]; /*0x81c7be*/
      *(_QWORD *)&n1006632960 = v12[1]; /*0x81c7cd*/
      HIWORD(n1006632960) = v12[3]; /*0x81c7ea*/
      *(_QWORD *)&n1006632960_0 = SHIWORD(n1006632960); /*0x81c7f0*/
      *((_WORD *)&n1006632960 + 3) = SHIWORD(n1006632960) >> 15; /*0x81c7fc*/
      *((_WORD *)&n16 + 3) = SHIWORD(n1006632960) >> 15; /*0x81c812*/
      *((_WORD *)&n1006632960 + 2) = WORD1(v10); /*0x81c81f*/
      *((_WORD *)&n16 + 2) = (unsigned __int64)(int)v10 >> 48; /*0x81c835*/
      HIWORD(n16) = (unsigned __int64)SHIWORD(n1006632960) >> 32; /*0x81c84f*/
      LOWORD(n16) = (int)v10 >> 31; /*0x81c856*/
      LOWORD(n1006632960) = v10; /*0x81c870*/
      HIWORD(v27) = v10; /*0x81c8a2*/
      LOWORD(v27) = v11; /*0x81c8a6*/
      FFX_Field_DrawBgAnim_ApplyTextureSlices(v22, (__int16)a2[1], (__int16)a2[2], v27); /*0x81c8b6*/
      return a2 + 4; /*0x81c8d3*/
    }
    return v2; /*0x81c73f*/
  }
  v13 = FFX_MagicHost_SelectRuntimeTableSlice(v22, 4, a2[1]); /*0x81c8df*/
  v26 = (int)v13; /*0x81c8ee*/
  if ( !unk_12F40D8 ) /*0x81c8f1*/
  {
    FFX_Ps3Data_BuildSlotRecord((int)v13, (_WORD *)0x6800000, (unsigned __int16 *)0x6C00000); /*0x81c8fe*/
    ++unk_12F40D8; /*0x81c906*/
  }
  v14 = (unsigned __int16 *)v23; /*0x81c90c*/
  v24 = *(float *)(v23 + 60) * 0.000000476837158203125; /*0x81c919*/
  FFX_Math_UniformScaleMatrix44((float *)a1, v24); /*0x81c923*/
  Address = (float *)FFX_Magic_ResolveRecordTargetAddress(a1, v14); /*0x81c93d*/
  FFX_Magic_CopyRuntimeTransformMatricesToGlobals_structural((float *)a1 + 16, &qword_113FCF0, &os_mat_wv); /*0x81c93f*/
  FFX_Magic_CopyRuntimeTransformMatricesToGlobals_structural((float *)a1 + 48, Address, (float *)a1); /*0x81c950*/
  FFX_Magic_CopyRuntimeTransformMatricesToGlobals_structural((float *)a1 + 48, &qword_113FCF0, (float *)a1 + 48); /*0x81c95c*/
  FFX_Field_BgAnimGeometryRotation((int)&savedregs, hudContext, charId, v26, (int)(a1 + 48), (float *)a1); /*0x81c970*/
  return a2 + 2; /*0x81c6b5*/
}
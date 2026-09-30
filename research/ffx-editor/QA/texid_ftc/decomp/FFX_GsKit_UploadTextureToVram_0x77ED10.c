// FFX GsKit: Upload texture to VRAM
void __cdecl FFX_GsKit_UploadTextureToVram(
        int a1,
        int n2,
        int a3,
        int a4,
        int n16,
        int n16a,
        int n512,
        int SlotWord,
        int a9,
        int a10,
        int a11)
{
  int v11; // ebx
  int v12; // ecx
  int n16b_1; // eax
  int n2_1; // edi
  int n512a_4; // ecx
  int n512a_2; // eax
  unsigned int *v17; // esi
  int v18; // edx
  int v19; // edi
  int n512a_1; // ecx
  BOOL v21; // ebx
  int *v22; // esi
  int v23; // edx
  int v24; // [esp+Ch] [ebp-Ch]
  int v25; // [esp+10h] [ebp-8h]
  int n512a_5; // [esp+14h] [ebp-4h]
  int v27; // [esp+30h] [ebp+18h]
  int n16b; // [esp+34h] [ebp+1Ch]
  int n512a; // [esp+38h] [ebp+20h]
  int v30; // [esp+44h] [ebp+2Ch]
  int n512a_3; // [esp+48h] [ebp+30h]

  v11 = n16 >> 4; /*0x77ed26*/
  v24 = n16 >> 4; /*0x77ed2b*/
  n512a_5 = n16a >> 4; /*0x77ed2e*/
  FlushCache(); /*0x77ed31*/
  v12 = a11; /*0x77ed39*/
  n16b_1 = a10 != 0 ? 512 : 1024;
  n16b = n16b_1; /*0x77ed4d*/
  if ( !a11 ) /*0x77ed52*/
  {
    FFX_Virtuos_AsmNotImplemented_rgb32_to_24_asm(); /*0x77ed5b*/
    v12 = 0; /*0x77ed60*/
    n16b_1 = 768; /*0x77ed63*/
    n16b = 768; /*0x77ed6b*/
  }
  v25 = n16b_1 / 16; /*0x77ed77*/
  if ( a10 ) /*0x77ed8d*/
    n2_1 = 2; /*0x77ed9d*/
  else
    n2_1 = v12 == 0; /*0x77ed99*/
  FFX_GsKit_PackGifTag2Words((unsigned int *)(a1 | 0x20000000), 0, 0, 0, 1, 0, 3); /*0x77edb8*/
  FFX_GsKit_BuildPrimitiveGifTag((int *)((a1 | 0x20000000) + 16), 14, 0, 1, 0, 0, 0, 0, 2); /*0x77edd1*/
  FFX_GsKit_BuildTexFlushGifTag((a1 | 0x20000000) + 32, SlotWord, n512 / 64, n2_1, a11); /*0x77ede7*/
  FFX_GsKit_BuildGifTagClut((_DWORD *)((a1 | 0x20000000) + 48), 16, 16); /*0x77edf4*/
  n512a_4 = n512a_5; /*0x77edf9*/
  n512a_2 = 0; /*0x77edfc*/
  v17 = (unsigned int *)((a1 | 0x20000000) + 64); /*0x77ee01*/
  n512a_3 = 0; /*0x77ee04*/
  if ( n512a_5 > 0 ) /*0x77ee09*/
  {
    v18 = 0; /*0x77ee0f*/
    v27 = 0; /*0x77ee11*/
    do /*0x77ef00*/
    {
      v19 = 0; /*0x77ee14*/
      if ( v11 > 0 ) /*0x77ee18*/
      {
        n512a_1 = n512a_4 - 1; /*0x77ee21*/
        v30 = a3; /*0x77ee22*/
        n512a_2 = n512a_3; /*0x77ee25*/
        n512a = n512a_1; /*0x77ee28*/
        do /*0x77eede*/
        {
          v21 = n512a_2 == n512a_1 && v19 == v11 - 1; /*0x77ee3b*/
          FFX_GsKit_PackGifTag2Words(v17, 0, 0, 0, 1, 0, 4); /*0x77ee51*/
          v22 = (int *)(v17 + 4); /*0x77ee64*/
          FFX_GsKit_BuildPrimitiveGifTag(v22, 14, 0, 1, 0, 0, 0, 0, 2); /*0x77ee6a*/
          v22 += 4; /*0x77ee78*/
          FFX_GsKit_BuildTexCoordGifTag((int)v22, 0, v30, a4 + v27); /*0x77ee82*/
          v22 += 4; /*0x77ee87*/
          FFX_GsKit_BuildGifTagDefault(v22, 0); /*0x77ee8d*/
          v22 += 4; /*0x77eea1*/
          FFX_GsKit_BuildPrimitiveGifTag(v22, 0, 0, 0, 2, 0, 0, v21, v25); /*0x77eea7*/
          v22 += 4; /*0x77eeb7*/
          FFX_GsKit_PackGifTag2Words((unsigned int *)v22, 0, n2, 0, 3, 0, v23); /*0x77eebd*/
          v30 += 16; /*0x77eec5*/
          n512a_2 = n512a_3; /*0x77eec9*/
          n512a_1 = n512a; /*0x77eecc*/
          n2 += n16b; /*0x77eecf*/
          v11 = v24; /*0x77eed2*/
          ++v19; /*0x77eed5*/
          v17 = (unsigned int *)(v22 + 4); /*0x77eed9*/
        }
        while ( v19 < v24 ); /*0x77eede*/
        v18 = v27; /*0x77eee4*/
        n512a_4 = n512a_5; /*0x77eee7*/
      }
      if ( a9 ) /*0x77eeee*/
        a4 += 16; /*0x77eef0*/
      ++n512a_2; /*0x77eef4*/
      v18 += 16; /*0x77eef5*/
      n512a_3 = n512a_2; /*0x77eef8*/
      v27 = v18; /*0x77eefb*/
    }
    while ( n512a_2 < n512a_4 ); /*0x77ef00*/
  }
  FFX_GsKit_PackGifTag2Words(v17, 0, 0, 0, 7, 0, 0); /*0x77ef13*/
  FlushCache(); /*0x77ef1a*/
}
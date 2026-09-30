// FFX FieldMap: Rasterize encounter poly batch
int __cdecl FFX_FieldMap_RasterizeEncounterPolyBatch_structural(int a1, int a2, int a3, _DWORD *RenderContextPtr)
{
  _DWORD *RenderContextPtr_1; // ebx
  int v5; // eax
  int v6; // esi
  int v7; // eax
  unsigned __int16 v8; // cx
  _DWORD *RenderContextPtr_2; // edi
  int n4; // ecx
  __int16 *v11; // ebx
  int v12; // eax
  int v13; // esi
  int v14; // ecx
  int v15; // edx
  int v16; // eax
  int v17; // ecx
  int n4_1; // ecx
  int v19; // esi
  int v20; // eax
  int result; // eax
  int v22; // [esp-4h] [ebp-60h]
  int v23; // [esp+1Ch] [ebp-40h]
  unsigned __int16 v24; // [esp+20h] [ebp-3Ch]
  float v25[4]; // [esp+28h] [ebp-34h] BYREF
  float v26[4]; // [esp+38h] [ebp-24h] BYREF
  float v27[4]; // [esp+48h] [ebp-14h] BYREF

  RenderContextPtr_1 = RenderContextPtr; // [Jarvis naming goal 2026-06-17] structural name from aggressive-honest FFX.exe pass. /*0x8447b4*/
  RenderContextPtr[4] = 1; /*0x8447ba*/
  RenderContextPtr[5] = 0x10000000; /*0x8447c1*/
  RenderContextPtr[6] = &unk_EEEEEE; /*0x8447c8*/
  RenderContextPtr[7] = 0; /*0x8447cf*/
  RenderContextPtr[8] = 460794; /*0x8447d6*/
  RenderContextPtr[9] = 0; /*0x8447dd*/
  RenderContextPtr[10] = 71; /*0x8447e4*/
  RenderContextPtr[11] = 0; /*0x8447eb*/
  RenderContextPtr[12] = 0; /*0x8447f2*/
  RenderContextPtr[13] = 0; /*0x8447f9*/
  v5 = RenderContextPtr[13]; /*0x844800*/
  RenderContextPtr[12] |= 0x8000u; /*0x844803*/
  v6 = a1; /*0x84480b*/
  RenderContextPtr[13] = v5 & 0x3FFF | 0x6005C000; /*0x844818*/
  RenderContextPtr[14] = 4276545; /*0x84481f*/
  RenderContextPtr[15] = 0; /*0x844826*/
  v22 = *(_DWORD *)(a2 + 12); /*0x84482d*/
  RenderContextPtr_2 = RenderContextPtr; /*0x844839*/
  n4_62 = 4; /*0x84483f*/
  v7 = Std_IdentityFunc(v22); /*0x844849*/
  v8 = 0; /*0x844850*/
  v27[3] = 1.0; /*0x844852*/
  v26[3] = 1.0; /*0x844857*/
  v25[3] = 1.0; /*0x84485d*/
  RenderContextPtr_2 = (_DWORD *)RenderContextPtr_2; /*0x844864*/
  v24 = 0; /*0x84486a*/
  v23 = 0; /*0x84486d*/
  if ( *(__int16 *)(a2 + 8) > 0 ) /*0x844870*/
  {
    n4 = n4_62; /*0x844876*/
    v11 = (__int16 *)(v7 + 4); /*0x84487c*/
    do /*0x844a3e*/
    {
      v25[0] = (float)*(__int16 *)(v6 + 8 * *(v11 - 2)); /*0x844891*/
      v25[1] = (float)*(__int16 *)(v6 + 8 * *(v11 - 2) + 2); /*0x8448a3*/
      v25[2] = (float)*(__int16 *)(v6 + 8 * *(v11 - 2) + 4); /*0x8448c2*/
      if ( FFX_FieldMap_ProjectVertexToScreen(&RenderContextPtr_2[4 * n4 + 4], (int)v25, a3) /*0x84497d*/
        || (v26[0] = (float)*(__int16 *)(v6 + 8 * *(v11 - 1)),
            v26[1] = (float)*(__int16 *)(v6 + 8 * *(v11 - 1) + 2),
            v26[2] = (float)*(__int16 *)(v6 + 8 * *(v11 - 1) + 4),
            FFX_FieldMap_ProjectVertexToScreen((int *)(RenderContextPtr_2 + 16 * (n4_62 + 3)), (int)v26, a3))
        || (v27[0] = (float)*(__int16 *)(v6 + 8 * *v11),
            v27[1] = (float)*(__int16 *)(v6 + 8 * *v11 + 2),
            v27[2] = (float)*(__int16 *)(v6 + 8 * *v11 + 4),
            FFX_FieldMap_ProjectVertexToScreen((int *)(RenderContextPtr_2 + 16 * (n4_62 + 5)), (int)v27, a3)) )
      {
        RenderContextPtr_2 = (_DWORD *)RenderContextPtr_2; /*0x844a1f*/
        n4 = n4_62; /*0x844a25*/
      }
      else
      {
        v12 = FFX_FieldMap_DecodeEncounterGroupFromPolyMeta(*((_DWORD *)v11 + 2)); /*0x844990*/
        RenderContextPtr_2 = (_DWORD *)RenderContextPtr_2; /*0x844995*/
        v13 = v12; /*0x84499b*/
        v14 = 8 * (v12 & 0x1F); /*0x8449a7*/
        v15 = 2 * n4_62; /*0x8449ac*/
        v16 = n4_62 + 2; /*0x8449ae*/
        *(_DWORD *)(RenderContextPtr_2 + 8 * v15 + 8) = v14; /*0x8449b1*/
        RenderContextPtr_2[2 * v15 + 1] = v14; /*0x8449b5*/
        RenderContextPtr_2[2 * v15] = v14; /*0x8449b9*/
        RenderContextPtr_2[2 * v15 + 3] = 128; /*0x8449be*/
        v17 = (v13 >> 2) & 0xF8; /*0x8449c9*/
        RenderContextPtr_2[2 * v15 + 10] = v17; /*0x8449cf*/
        RenderContextPtr_2[2 * v15 + 9] = v17; /*0x8449d3*/
        RenderContextPtr_2[4 * v16] = v17; /*0x8449dc*/
        n4_1 = n4_62; /*0x8449df*/
        v19 = (v13 >> 7) & 0xF8; /*0x8449e5*/
        RenderContextPtr_2[2 * v15 + 11] = 128; /*0x8449eb*/
        RenderContextPtr_2[2 * v15 + 18] = v19; /*0x8449f6*/
        v20 = 2 * (n4_1 + 4); /*0x8449fa*/
        RenderContextPtr_2[2 * v15 + 17] = v19; /*0x8449fc*/
        n4 = n4_1 + 6; /*0x844a00*/
        RenderContextPtr_2[2 * v20] = v19; /*0x844a03*/
        v6 = a1; /*0x844a06*/
        ++v24; /*0x844a0c*/
        RenderContextPtr_2[2 * v15 + 19] = 128; /*0x844a0f*/
        n4_62 = n4; /*0x844a17*/
      }
      v11 += 8; /*0x844a36*/
      ++v23; /*0x844a39*/
    }
    while ( v23 < *(__int16 *)(a2 + 8) ); /*0x844a3e*/
    RenderContextPtr_1 = RenderContextPtr; /*0x844a44*/
    v8 = v24; /*0x844a47*/
  }
  RenderContextPtr_1[12] ^= (v8 ^ (unsigned __int16)RenderContextPtr_1[12]) & 0x7FFF; /*0x844a57*/
  RenderContextPtr_2[1] = 0; /*0x844a5c*/
  RenderContextPtr_2[2] = 0; /*0x844a5f*/
  RenderContextPtr_2[3] = 0; /*0x844a62*/
  result = (n4_62 - 1) | 0x70000000; /*0x844a6b*/
  *RenderContextPtr_2 = result; /*0x844a70*/
  return result; /*0x844a4f*/
}
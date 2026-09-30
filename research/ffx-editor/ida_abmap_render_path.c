// FFX Abmap: Render path nodes
void __usercall FFX_Abmap_RenderPathNodes(int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg@<ebp>)
{
  unsigned int v1; // edi
  unsigned int lpamng; // ecx
  int v3; // esi
  double v4; // st7
  double v5; // st7
  int v6; // eax
  double v7; // st5
  double v8; // st6
  double v9; // rt1
  double v10; // st5
  int n0x4000; // eax
  int n0x10000; // edx
  float v13; // [esp+10h] [ebp-160h]
  float v14; // [esp+14h] [ebp-15Ch]
  int v15; // [esp+18h] [ebp-158h]
  int v16; // [esp+1Ch] [ebp-154h]
  int v17; // [esp+20h] [ebp-150h]
  float v18; // [esp+20h] [ebp-150h]
  float v19; // [esp+20h] [ebp-150h]
  float v20; // [esp+20h] [ebp-150h]
  float n0x4000_1; // [esp+20h] [ebp-150h]
  _DWORD p_n4[2]; // [esp+24h] [ebp-14Ch] BYREF
  __int16 n72; // [esp+2Ch] [ebp-144h]
  char v24; // [esp+2Eh] [ebp-142h]
  int v25; // [esp+30h] [ebp-140h]
  int v26; // [esp+34h] [ebp-13Ch]
  int v27; // [esp+38h] [ebp-138h]
  int v28; // [esp+3Ch] [ebp-134h]
  int v29; // [esp+40h] [ebp-130h]
  _BYTE *v30; // [esp+44h] [ebp-12Ch]
  unsigned int v31; // [esp+48h] [ebp-128h]
  unsigned int v32; // [esp+4Ch] [ebp-124h]
  float *v33; // [esp+50h] [ebp-120h]
  int v34; // [esp+5Ch] [ebp-114h]
  int v35; // [esp+60h] [ebp-110h]
  int v36; // [esp+64h] [ebp-10Ch]
  __int64 *p_n1006632960; // [esp+68h] [ebp-108h]
  char v38; // [esp+70h] [ebp-100h]
  char v39; // [esp+71h] [ebp-FFh]
  _BYTE v40[64]; // [esp+9Ch] [ebp-D4h] BYREF
  float v41[16]; // [esp+DCh] [ebp-94h] BYREF
  __int64 n1006632960; // [esp+11Ch] [ebp-54h] BYREF
  FFX_CharacterId FFX_Render_SharedTransformContext; // [esp+124h] [ebp-4Ch]
  float v44; // [esp+128h] [ebp-48h]
  __int64 n1006632960_1; // [esp+12Ch] [ebp-44h]
  FFX_CharacterId FFX_Render_SharedTransformContext_1; // [esp+134h] [ebp-3Ch]
  float v47; // [esp+138h] [ebp-38h]
  __int64 n1006632960_2; // [esp+13Ch] [ebp-34h]
  FFX_CharacterId FFX_Render_SharedTransformContext_2; // [esp+144h] [ebp-2Ch]
  float v50; // [esp+148h] [ebp-28h]
  __int64 n1006632960_3; // [esp+14Ch] [ebp-24h]
  FFX_CharacterId FFX_Render_SharedTransformContext_3; // [esp+154h] [ebp-1Ch]
  float v53; // [esp+158h] [ebp-18h]
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1; // [esp+164h] [ebp-Ch]
  void *v55; // [esp+168h] [ebp-8h]
  void *retaddr; // [esp+170h] [ebp+0h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0xa5029c*/
  v55 = retaddr; /*0xa502a0*/
  v17 = *(__int16 *)(lpamng + 2); /*0xa502c8*/
  v15 = unk_23057F4; /*0xa502d3*/
  v30 = v40; /*0xa502df*/
  p_n1006632960 = &n1006632960; /*0xa502ef*/
  v1 = lpamng + 2056; /*0xa502f6*/
  v33 = v41; /*0xa50308*/
  FFX_Render_SharedTransformContext = FFX_Render_SharedTransformContext; /*0xa50313*/
  FFX_Render_SharedTransformContext_1 = FFX_Render_SharedTransformContext; /*0xa50316*/
  FFX_Render_SharedTransformContext_2 = FFX_Render_SharedTransformContext; /*0xa50319*/
  FFX_Render_SharedTransformContext_3 = FFX_Render_SharedTransformContext; /*0xa5031c*/
  lpamng = lpamng; /*0xa5031f*/
  v44 = MEMORY[0xC8F514][0]; /*0xa50328*/
  v53 = 1.0; /*0xa5032b*/
  v47 = MEMORY[0xC8F514][0]; /*0xa5032e*/
  v50 = MEMORY[0xC8F514][0]; /*0xa50331*/
  v32 = 0; /*0xa50334*/
  v31 = 0; /*0xa5033e*/
  n1006632960 = n1006632960_1; /*0xa50348*/
  n1006632960_1 = n1006632960_1; /*0xa5034b*/
  n1006632960_2 = n1006632960_1; /*0xa5034e*/
  n1006632960_3 = n1006632960_1; /*0xa50351*/
  v29 = 0; /*0xa50354*/
  v24 = 0; /*0xa5035e*/
  v35 = 0; /*0xa50365*/
  v34 = 0; /*0xa5036f*/
  p_n4[1] = byte_1740830; /*0xa50379*/
  v25 = 0; /*0xa50383*/
  v26 = 0; /*0xa5038d*/
  v27 = 0; /*0xa50397*/
  v36 = 0; /*0xa503a1*/
  v3 = v17; /*0xa503b7*/
  v16 = 0; /*0xa503cf*/
  v14 = 65536.0 / *(float *)(lpamng + 71072); /*0xa503d9*/
  v4 = *(float *)(lpamng + 71072) * *(float *)(lpamng + 71072); /*0xa503e5*/
  v32 = lpamng + 70944; /*0xa503e7*/
  v31 = lpamng + 71008; /*0xa503f3*/
  v13 = v4 * 0.5; /*0xa503ff*/
  if ( v17 ) /*0xa50407*/
  {
    v5 = 1.299999952316284; /*0xa5040d*/
    do /*0xa505ab*/
    {
      v6 = *(unsigned __int16 *)(v1 + 6); /*0xa50418*/
      --v3; /*0xa5041c*/
      if ( (_WORD)v6 != 0xFFFF ) /*0xa50420*/
      {
        v18 = v5 * *(float *)(lpamng + 48 * v6 + 63544); /*0xa50439*/
        FFX_Abmap_BuildNodePlacementMatrix((int)v41, (__int16 *)v1, v18); /*0xa5044a*/
        lpamng = lpamng; /*0xa5044f*/
        v7 = *(float *)(lpamng + 70944) - v41[12]; /*0xa50473*/
        v8 = *(float *)(lpamng + 70952) - v41[14]; /*0xa50473*/
        v9 = v7 * v7; /*0xa50477*/
        v10 = *(float *)(lpamng + 70948) - v41[13]; /*0xa50477*/
        v19 = v9 + v10 * v10 + v8 * v8; /*0xa50481*/
        if ( v13 <= (double)v19 ) /*0xa5049a*/
        {
          v39 = 0; /*0xa505c8*/
        }
        else
        {
          p_n4[0] = 68; /*0xa504a2*/
          v20 = sqrt(fabs(v19)); /*0xa504b1*/
          n0x4000_1 = v20 * v14; /*0xa504c3*/
          n0x4000 = (int)n0x4000_1; /*0xa504cf*/
          n0x10000 = n0x4000; /*0xa504d4*/
          if ( n0x4000 >= 0x4000 || (n0x10000 = 4 * (20480 - n0x4000), n0x10000 < 0x10000) ) /*0xa504f0*/
          {
            if ( ++v16 > 25 ) /*0xa50506*/
              return; /*0xa50506*/
            *(float *)&FFX_Render_SharedTransformContext_3 = 5.0; /*0xa50519*/
            v28 = -2139062144; /*0xa5051c*/
            HIBYTE(v28) = (unsigned __int8)((unsigned int)(96 * (0x10000 - n0x10000)) >> 16) >> 3; /*0xa50534*/
            n72 = 72; /*0xa5053f*/
            v38 = 0; /*0xa50561*/
            v39 = 2 * ((unsigned int)(96 * (0x10000 - n0x10000)) >> 16); /*0xa50568*/
            FFX_Menu2D_ProjectNodeCoords_structural((int)v40, lpamng + 70624, (int)v41); /*0xa5056e*/
            FFX_Menu2D_RenderCaptureNoTexture(v15, (int)p_n4); /*0xa5058d*/
          }
          lpamng = lpamng; /*0xa50595*/
        }
        v5 = 1.299999952316284; /*0xa5059b*/
      }
      v1 += 40; /*0xa505a6*/
    }
    while ( v3 ); /*0xa505ab*/
  }
}

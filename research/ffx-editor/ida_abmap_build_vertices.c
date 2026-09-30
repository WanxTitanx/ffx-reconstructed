// FFX Abmap: Sphere grid build vertices
// ABMAP Sphere Grid build vertices (1.4KB). Builds vertex data for Sphere Grid rendering. Creates nodes, links, and stat bonus indicators. Uses ABMAP data from ps3data/menu/abmap/.
int __usercall FFX_Abmap_SphereGridBuildVertices@<eax>(
        int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg@<ebp>)
{
  double v1; // st7
  unsigned int lpamng; // edi
  int result; // eax
  double v4; // st6
  double v5; // st5
  double v6; // st4
  unsigned int v7; // ecx
  int v8; // eax
  int v9; // eax
  unsigned __int8 v10; // al
  int v11; // eax
  double v12; // st6
  unsigned __int8 v13; // cl
  int n7_2; // esi
  float *j_1; // ecx
  int v16; // eax
  void *hudContext_2; // edx
  FFX_CharacterId charId_2; // ecx
  int n7_1; // esi
  float *i_1; // eax
  void *hudContext_1; // edx
  FFX_CharacterId charId_1; // ecx
  int n7; // esi
  void *hudContext; // edx
  FFX_CharacterId charId; // ecx
  float v26; // [esp+0h] [ebp-1A0h]
  int v27; // [esp+14h] [ebp-18Ch]
  int v28; // [esp+18h] [ebp-188h]
  int v29; // [esp+1Ch] [ebp-184h]
  int v30; // [esp+20h] [ebp-180h]
  int v31; // [esp+24h] [ebp-17Ch]
  int v32; // [esp+28h] [ebp-178h]
  int n7_3; // [esp+2Ch] [ebp-174h]
  int v34; // [esp+30h] [ebp-170h]
  int v35; // [esp+34h] [ebp-16Ch]
  int v36; // [esp+38h] [ebp-168h]
  __int16 *v37; // [esp+40h] [ebp-160h]
  int v38; // [esp+44h] [ebp-15Ch]
  int v39; // [esp+44h] [ebp-15Ch]
  int v40; // [esp+48h] [ebp-158h]
  float *j; // [esp+48h] [ebp-158h]
  float *i; // [esp+48h] [ebp-158h]
  __int16 *v43; // [esp+4Ch] [ebp-154h]
  unsigned __int8 v44; // [esp+53h] [ebp-14Dh]
  _DWORD v45[2]; // [esp+54h] [ebp-14Ch] BYREF
  __int16 v46; // [esp+5Ch] [ebp-144h]
  char v47; // [esp+5Eh] [ebp-142h]
  int v48; // [esp+60h] [ebp-140h]
  int v49; // [esp+64h] [ebp-13Ch]
  int v50; // [esp+68h] [ebp-138h]
  unsigned int v51; // [esp+6Ch] [ebp-134h]
  int v52; // [esp+70h] [ebp-130h]
  _BYTE *v53; // [esp+74h] [ebp-12Ch]
  unsigned int v54; // [esp+78h] [ebp-128h]
  unsigned int v55; // [esp+7Ch] [ebp-124h]
  _BYTE *v56; // [esp+80h] [ebp-120h]
  int v57; // [esp+8Ch] [ebp-114h]
  int v58; // [esp+90h] [ebp-110h]
  int v59; // [esp+94h] [ebp-10Ch]
  __int64 *p_n1006632960; // [esp+98h] [ebp-108h]
  _BYTE v61[64]; // [esp+CCh] [ebp-D4h] BYREF
  _BYTE v62[64]; // [esp+10Ch] [ebp-94h] BYREF
  __int64 n1006632960; // [esp+14Ch] [ebp-54h] BYREF
  FFX_CharacterId FFX_Render_SharedTransformContext; // [esp+154h] [ebp-4Ch]
  float v65; // [esp+158h] [ebp-48h]
  __int64 n1006632960_1; // [esp+15Ch] [ebp-44h]
  FFX_CharacterId FFX_Render_SharedTransformContext_1; // [esp+164h] [ebp-3Ch]
  float v68; // [esp+168h] [ebp-38h]
  __int64 n1006632960_2; // [esp+16Ch] [ebp-34h]
  FFX_CharacterId FFX_Render_SharedTransformContext_2; // [esp+174h] [ebp-2Ch]
  float v71; // [esp+178h] [ebp-28h]
  __int64 n1006632960_3; // [esp+17Ch] [ebp-24h]
  FFX_CharacterId FFX_Render_SharedTransformContext_3; // [esp+184h] [ebp-1Ch]
  float v74; // [esp+188h] [ebp-18h]
  int [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1; // [esp+194h] [ebp-Ch]
  void *v76; // [esp+198h] [ebp-8h]
  void *retaddr; // [esp+1A0h] [ebp+0h]

  [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg_1 = [Jarvis_naming_goal_2026_06_17]_proved/navigation_name_from_agg; /*0xa505ec*/
  v76 = retaddr; /*0xa505f0*/
  v1 = 1.0; /*0xa50607*/
  lpamng = lpamng; /*0xa5060a*/
  v38 = *(__int16 *)(lpamng + 2); /*0xa5061a*/
  v43 = (__int16 *)(lpamng + 2056); /*0xa50632*/
  v31 = *(_DWORD *)(lpamng + 71320) << 11; /*0xa50641*/
  v53 = v61; /*0xa5064d*/
  p_n1006632960 = &n1006632960; /*0xa50656*/
  v56 = v62; /*0xa50662*/
  v65 = MEMORY[0xC8F514][0]; /*0xa50670*/
  v68 = MEMORY[0xC8F514][0]; /*0xa50673*/
  v74 = 1.0; /*0xa50676*/
  v71 = MEMORY[0xC8F514][0]; /*0xa50679*/
  v55 = lpamng + 70944; /*0xa50682*/
  v54 = lpamng + 71008; /*0xa5068e*/
  result = v38; /*0xa50694*/
  v52 = 0; /*0xa5069a*/
  v47 = 0; /*0xa506a4*/
  v58 = 0; /*0xa506ab*/
  v57 = 0; /*0xa506b5*/
  v45[1] = byte_1740830; /*0xa506bf*/
  v48 = 0; /*0xa506c9*/
  v49 = 0; /*0xa506d3*/
  v50 = 0; /*0xa506dd*/
  v59 = 0; /*0xa506e7*/
  n1006632960 = n1006632960_1; /*0xa506f1*/
  FFX_Render_SharedTransformContext = FFX_Render_SharedTransformContext; /*0xa506f7*/
  n1006632960_1 = n1006632960_1; /*0xa506fa*/
  FFX_Render_SharedTransformContext_1 = FFX_Render_SharedTransformContext; /*0xa50700*/
  n1006632960_2 = n1006632960_1; /*0xa50703*/
  FFX_Render_SharedTransformContext_2 = FFX_Render_SharedTransformContext; /*0xa50709*/
  n1006632960_3 = n1006632960_1; /*0xa5070c*/
  FFX_Render_SharedTransformContext_3 = FFX_Render_SharedTransformContext; /*0xa50712*/
  if ( v38 ) /*0xa50717*/
  {
    v4 = 0.1500000059604645; /*0xa50723*/
    v5 = -96.0; /*0xa50729*/
    v36 = v30; /*0xa5072f*/
    v6 = 6.0; /*0xa5073b*/
    v35 = v29; /*0xa50741*/
    v32 = v28; /*0xa5074d*/
    v34 = v27; /*0xa50759*/
    v7 = lpamng + 2056; /*0xa5075f*/
    while ( 1 ) /*0xa50771*/
    {
      v39 = result - 1; /*0xa50771*/
      v8 = *(unsigned __int16 *)(v7 + 6); /*0xa50777*/
      if ( (_WORD)v8 == 0xFFFF ) /*0xa5077e*/
      {
        n7 = 0; /*0xa50a7a*/
        while ( 1 ) /*0xa50a87*/
        {
          v26 = v1; /*0xa50a87*/
          FFX_Abmap_BuildNodePlacementMatrix((int)v62, (__int16 *)v7, v26); /*0xa50a8c*/
          FFX_Menu2D_ProjectNodeCoords_structural((int)v61, lpamng + 70624, (int)v62); /*0xa50aa6*/
          *(float *)&FFX_Render_SharedTransformContext_3 = -1.0; /*0xa50ab6*/
          v51 = 0; /*0xa50ab9*/
          FFX_Menu2D_BuildNoTextureVertices( /*0xa50add*/
            charId,
            hudContext,
            dword_23057EC,
            (int)v45,
            *(__int16 *)(lpamng + 2) - v39 - 1,
            n7++);
          if ( n7 >= 7 ) /*0xa50ae9*/
            break; /*0xa50ae9*/
          lpamng = lpamng; /*0xa50aeb*/
          v1 = 1.0; /*0xa50af1*/
          v7 = (unsigned int)v43; /*0xa50af3*/
        }
      }
      else
      {
        v9 = 48 * v8; /*0xa50787*/
        v40 = v9; /*0xa5079a*/
        v37 = (__int16 *)(v9 + lpamng + 63548); /*0xa507a0*/
        if ( *v37 == 4096 ) /*0xa507ab*/
        {
          n7_1 = 0; /*0xa509dc*/
          i_1 = (float *)(lpamng + v9 + 63544); /*0xa509e0*/
          for ( i = i_1; ; i_1 = i ) /*0xa509e4*/
          {
            FFX_Abmap_BuildNodePlacementMatrix((int)v62, (__int16 *)v7, *i_1); /*0xa509fe*/
            FFX_Menu2D_ProjectNodeCoords_structural((int)v61, lpamng + 70624, (int)v62); /*0xa50a18*/
            *(float *)&FFX_Render_SharedTransformContext_3 = -1.0; /*0xa50a28*/
            v51 = 0; /*0xa50a2b*/
            FFX_Menu2D_BuildNoTextureVertices( /*0xa50a4f*/
              charId_1,
              hudContext_1,
              dword_23057EC,
              (int)v45,
              *(__int16 *)(lpamng + 2) - v39 - 1,
              n7_1++);
            if ( n7_1 >= 7 ) /*0xa50a5b*/
              break; /*0xa50a5b*/
            lpamng = lpamng; /*0xa50a61*/
            v7 = (unsigned int)v43; /*0xa50a67*/
          }
        }
        else
        {
          v10 = *(_BYTE *)(v7 + 33) & *(_BYTE *)(lpamng + 71113); /*0xa507b7*/
          v44 = v10; /*0xa507ba*/
          if ( v10 ) /*0xa507c0*/
          {
            v11 = (int)(v4 * eff_sin_t[((v31 + *(unsigned __int16 *)(v7 + 38)) >> 4) & 0xFFF] * v5); /*0xa507e5*/
            v12 = v6; /*0xa507f1*/
            v1 = 1.0; /*0xa507f1*/
            v13 = 108 - v11; /*0xa507f3*/
            v10 = v44; /*0xa507f5*/
            v36 = v13; /*0xa50801*/
            v34 = v13; /*0xa50807*/
            v32 = v13; /*0xa5080d*/
            v35 = v13; /*0xa50813*/
          }
          else
          {
            v12 = v6; /*0xa508f3*/
          }
          v46 = -32668; /*0xa5081f*/
          n7_2 = 0; /*0xa50826*/
          j_1 = (float *)(lpamng + v40 + 63544); /*0xa5082e*/
          n7_3 = 0; /*0xa50830*/
          for ( j = j_1; ; j_1 = j ) /*0xa50836*/
          {
            if ( (v10 & 1) != 0 ) /*0xa5083e*/
            {
              v16 = FFX_Abmap_Global_C8659C[n7_2]; /*0xa50844*/
              j_1 = j; /*0xa508ba*/
              n7_2 = n7_3; /*0xa508d4*/
              v51 = ((unsigned int)&unk_1FFFFFF & ((v34 * (unsigned __int8)v16) >> 7)) /*0xa508da*/
                  + ((((unsigned int)&unk_1FFFFFF & ((v32 * BYTE1(v16)) >> 7))
                    + ((((unsigned int)&unk_1FFFFFF & ((v35 * BYTE2(v16)) >> 7))
                      + (((unsigned int)&unk_1FFFFFF & ((v36 * HIBYTE(v16)) >> 7)) << 8)) << 8)) << 8);
              HIBYTE(v51) = 0x80; /*0xa508e0*/
              v45[0] = 44; /*0xa508e7*/
            }
            else
            {
              v1 = v12; /*0xa50903*/
              v51 = FFX_Abmap_Global_C86644[n7_2]; /*0xa50905*/
              v45[0] = 36; /*0xa5090b*/
            }
            *(float *)&FFX_Render_SharedTransformContext_3 = v1; /*0xa50916*/
            FFX_Abmap_BuildNodePlacementMatrix((int)v62, v43, *j_1); /*0xa5092b*/
            FFX_Abmap_BuildNodeTransformMatrix((int)v62, v43, v37, 0.00079999998); /*0xa5094f*/
            FFX_Menu2D_ProjectNodeCoords_structural((int)v61, lpamng + 70624, (int)v62); /*0xa50969*/
            FFX_Menu2D_BuildNoTextureVertices( /*0xa5098d*/
              charId_2,
              hudContext_2,
              dword_23057EC,
              (int)v45,
              *(__int16 *)(lpamng + 2) - v39 - 1,
              n7_2);
            v37 += 2; /*0xa50998*/
            ++n7_2; /*0xa5099f*/
            v10 = v44 >> 1; /*0xa509a0*/
            n7_3 = n7_2; /*0xa509a5*/
            v44 >>= 1; /*0xa509ab*/
            if ( n7_2 >= 7 ) /*0xa509b4*/
              break; /*0xa509b4*/
            v1 = 1.0; /*0xa509ba*/
            lpamng = lpamng; /*0xa509bc*/
            v12 = 6.0; /*0xa509c2*/
          }
        }
      }
      result = v39; /*0xa50b01*/
      v7 = (unsigned int)(v43 + 20); /*0xa50b07*/
      v43 += 20; /*0xa50b0a*/
      if ( !v39 ) /*0xa50b12*/
        break; /*0xa50b12*/
      v1 = 1.0; /*0xa50b14*/
      lpamng = lpamng; /*0xa50b16*/
      v5 = -96.0; /*0xa5076c*/
      v6 = 6.0; /*0xa5076e*/
      v4 = 0.1500000059604645; /*0xa5076e*/
    }
  }
  return result; /*0xa50b49*/
}

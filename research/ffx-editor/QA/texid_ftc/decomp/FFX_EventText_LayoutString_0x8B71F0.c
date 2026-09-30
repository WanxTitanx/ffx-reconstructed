// FFX: EventText layouts string — layouts event text string for display
// FFX EventText: Layout string
// Event text layout. Lays out event dialogue text with formatting codes (color, size, position). Uses PBitmapFont SDF system for text rendering. Fonts loaded from ps3data/fonts/.
unsigned __int8 *__cdecl FFX_EventText_LayoutString(unsigned __int8 *a1, int a2)
{
  int v2; // ecx
  unsigned __int8 *v3; // esi
  int n1040; // ebx
  __int16 n15360; // di
  int v6; // ecx
  int CurrentId; // eax
  int v8; // eax
  unsigned __int8 n0x28; // al
  int CurrentTextSlot; // eax
  int SlotGlyphMeta; // eax
  int v12; // ecx
  int v13; // ecx
  double v14; // st7
  int v15; // ecx
  int v16; // edi
  double v17; // st7
  double v18; // st7
  int v19; // edi
  double v20; // st7
  double v21; // st7
  int v23; // eax
  int v24; // ecx
  int v25; // ebx
  int v26; // ecx
  double v27; // st7
  int v28; // ecx
  double v29; // st7
  int v30; // edi
  int v31; // ebx
  int v32; // ecx
  int v33; // ecx
  double v34; // st7
  int v35; // ecx
  double v36; // st7
  double v37; // st6
  int v38; // ecx
  int v39; // ecx
  int v40; // ecx
  int v41; // ecx
  int v42; // ecx
  double v43; // st7
  int v44; // ecx
  double v45; // st7
  int SlotGlyphMeta_1; // [esp+18h] [ebp-4h]
  int v48; // [esp+24h] [ebp+8h]
  float v49; // [esp+24h] [ebp+8h]
  float v50; // [esp+24h] [ebp+8h]
  float v51; // [esp+24h] [ebp+8h]
  float v52; // [esp+24h] [ebp+8h]
  int v53; // [esp+24h] [ebp+8h]
  float v54; // [esp+24h] [ebp+8h]
  float v55; // [esp+24h] [ebp+8h]
  int v56; // [esp+24h] [ebp+8h]
  float v57; // [esp+24h] [ebp+8h]
  float v58; // [esp+24h] [ebp+8h]
  float v59; // [esp+24h] [ebp+8h]
  int v60; // [esp+24h] [ebp+8h]
  float v61; // [esp+24h] [ebp+8h]
  float v62; // [esp+24h] [ebp+8h]

  v3 = a1; /*0x8b71f8*/
  n1040 = 0; /*0x8b71fb*/
  if ( toMenuActiveFlag != 1 || FFX_Locale_GetCurrentId(v2) )
    n15360 = 15360; /*0x8b722c*/
  else
    n15360 = FFX_ReturnZero() != 0 ? 15680 : 15360;
  if ( !FFX_Locale_GetCurrentId(v2) && !FFX_ReturnZero() && *a1 >= 0x5Cu && *a1 <= 0x5Eu ) /*0x8b724b*/
    goto LABEL_83; /*0x8b724b*/
  CurrentId = FFX_Locale_GetCurrentId(v6); /*0x8b7251*/
  if ( CurrentId ) /*0x8b7259*/
  {
    v8 = CurrentId - 9; /*0x8b725b*/
    if ( v8 ) /*0x8b725e*/
    {
      if ( v8 == 1 ) /*0x8b7261*/
      {
        if ( *a1 == 4 ) /*0x8b726d*/
        {
          n1040 = 1040; /*0x8b726f*/
          v3 = a1 + 1; /*0x8b7274*/
        }
        n15360 = 15632; /*0x8b7275*/
      }
      else
      {
        n15360 = 15680; /*0x8b7263*/
      }
    }
    else
    {
      if ( *a1 == 4 ) /*0x8b727f*/
      {
        n1040 = 1040; /*0x8b7281*/
        v3 = a1 + 1; /*0x8b7286*/
      }
      n15360 = 15664; /*0x8b7287*/
    }
  }
  else
  {
    n15360 = 15360; /*0x8b728e*/
  }
  n0x28 = *v3; /*0x8b7293*/
  if ( *v3 >= 0x2Cu ) /*0x8b7297*/
  {
    CurrentTextSlot = FFX_Font_GetCurrentTextSlot(); /*0x8b729d*/
    SlotGlyphMeta = FFX_Font_GetSlotGlyphMeta(CurrentTextSlot); /*0x8b72a3*/
    LOBYTE(v12) = *v3; /*0x8b72a8*/
    SlotGlyphMeta_1 = SlotGlyphMeta; /*0x8b72ad*/
    if ( *v3 < 0x30u ) /*0x8b72b3*/
    {
      n1040 += 208 * ((unsigned __int8)v12 - 43); /*0x8b72c1*/
      ++v3; /*0x8b72c3*/
    }
    v48 = n1040 - 48 + *v3; /*0x8b72cf*/
    *(_WORD *)a2 = n15360; /*0x8b72d7*/
    *(_WORD *)(a2 + 2) = 20; /*0x8b72da*/
    if ( FFX_Locale_GetCurrentId(v12) == 10 ) /*0x8b72e6*/
    {
      v14 = -1.0; /*0x8b72e8*/
    }
    else if ( FFX_Locale_GetCurrentId(v13) <= 0 || FFX_Locale_GetCurrentId(v15) >= 9 ) /*0x8b7301*/
    {
      v14 = 0.0; /*0x8b7307*/
    }
    else
    {
      v14 = 1.0; /*0x8b7303*/
    }
    v16 = v48; /*0x8b7309*/
    *(float *)(a2 + 24) = v14; /*0x8b730c*/
    *(float *)(a2 + 28) = (double)*(char *)(SlotGlyphMeta_1 + v48) * 0.25; /*0x8b7328*/
    if ( *v3 == 58 ) /*0x8b732e*/
    {
      if ( FFX_EventText_IsValidSeparatorChar((int)v3) ) /*0x8b7331*/
        v17 = 5.0; /*0x8b733d*/
      else
        v17 = *(float *)(a2 + 28); /*0x8b7345*/
      v49 = v17; /*0x8b7348*/
      *(float *)(a2 + 28) = v49; /*0x8b734e*/
    }
    *(float *)(a2 + 32) = 18.0; /*0x8b735e*/
    v50 = (float)(14 * (v16 % 18 / 2)); /*0x8b7395*/
    v18 = v50; /*0x8b739e*/
    *(float *)(a2 + 8) = v50; /*0x8b73a1*/
    v51 = (float)(18 * (v16 / 18)); /*0x8b73a7*/
    *(_WORD *)(a2 + 4) = v16 & 1; /*0x8b73ad*/
    *(float *)(a2 + 12) = v51; /*0x8b73b7*/
    *(float *)(a2 + 16) = v18 + *(float *)(a2 + 28); /*0x8b73c1*/
    *(float *)(a2 + 20) = v51 + 18.0; /*0x8b73ca*/
    if ( *a1 == 71 ) /*0x8b73d0*/
    {
      v19 = 0; /*0x8b73d6*/
      if ( *v3 == 71 ) /*0x8b73db*/
      {
        do /*0x8b73e5*/
          ++v19; /*0x8b73e0*/
        while ( v3[v19] == 71 ); /*0x8b73e5*/
        if ( v19 > 1 ) /*0x8b73ed*/
        {
          v52 = (float)v19; /*0x8b73fc*/
          if ( FFX_Font_GetCurrentTextSlot() == 4 ) /*0x8b73fa*/
          {
            v20 = v52 * *(float *)(a2 + 28); /*0x8b7402*/
            v21 = v20 + v20; /*0x8b7405*/
          }
          else
          {
            v21 = v52 * *(float *)(a2 + 28); /*0x8b740f*/
          }
          *(float *)(a2 + 28) = v21; /*0x8b7412*/
          *(float *)(a2 + 8) = *(float *)(a2 + 8) + 4.0; /*0x8b7422*/
          *(float *)(a2 + 16) = *(float *)(a2 + 16) - 4.0; /*0x8b7428*/
        }
      }
      return &v3[v19]; /*0x8b7437*/
    }
    return v3 + 1; /*0x8b7853*/
  }
  if ( n0x28 < 0x2Au || n0x28 > 0x2Bu ) /*0x8b7442*/
  {
    if ( n0x28 >= 0x28u && n0x28 <= 0x29u ) /*0x8b755c*/
    {
      v30 = a2; /*0x8b7576*/
      v56 = FFX_Font_GetSlotGlyphMeta(2); /*0x8b7582*/
      v31 = 208 * *v3 + v3[1] - 8368; /*0x8b7585*/
      *(_DWORD *)a2 = 1326336; /*0x8b7587*/
      if ( FFX_Locale_GetCurrentId(v32) == 10 ) /*0x8b7595*/
      {
        v34 = -1.0; /*0x8b7597*/
      }
      else if ( FFX_Locale_GetCurrentId(v33) <= 0 || FFX_Locale_GetCurrentId(v35) >= 9 ) /*0x8b75b0*/
      {
        v34 = 0.0; /*0x8b75b6*/
      }
      else
      {
        v34 = 1.0; /*0x8b75b2*/
      }
LABEL_62:
      *(float *)(v30 + 24) = v34; /*0x8b75b8*/
      *(float *)(v30 + 28) = (double)*(char *)(v56 + v31) * 0.25; /*0x8b75db*/
      *(float *)(v30 + 32) = 18.0; /*0x8b75e9*/
      v57 = (float)(14 * (v31 % 18 / 2)); /*0x8b7613*/
      v36 = v57; /*0x8b761c*/
      *(float *)(v30 + 8) = v57; /*0x8b761f*/
      v58 = (float)(18 * (v31 / 18)); /*0x8b7625*/
      v37 = v58; /*0x8b7628*/
LABEL_63:
      v59 = v37; /*0x8b762b*/
      *(_WORD *)(v30 + 4) = v31 & 1; /*0x8b7634*/
      *(float *)(v30 + 12) = v59; /*0x8b7638*/
      *(float *)(v30 + 16) = v36 + *(float *)(v30 + 28); /*0x8b7645*/
      *(float *)(v30 + 20) = v59 + 18.0; /*0x8b764e*/
      return v3 + 2; /*0x8b7657*/
    }
    if ( n0x28 >= 0x26u && n0x28 <= 0x27u ) /*0x8b7662*/
    {
      v30 = a2; /*0x8b767c*/
      v56 = FFX_Font_GetSlotGlyphMeta(3); /*0x8b7688*/
      v31 = 208 * *v3 + v3[1] - 7952; /*0x8b768b*/
      *(_DWORD *)a2 = 1326337; /*0x8b768d*/
      if ( FFX_Locale_GetCurrentId(v38) == 10 ) /*0x8b769b*/
      {
        v34 = -1.0; /*0x8b769d*/
      }
      else if ( FFX_Locale_GetCurrentId(v39) <= 0 || FFX_Locale_GetCurrentId(v40) >= 9 ) /*0x8b76b6*/
      {
        v34 = 0.0; /*0x8b76bc*/
      }
      else
      {
        v34 = 1.0; /*0x8b76b8*/
      }
      goto LABEL_62; /*0x8b76a3*/
    }
    if ( n0x28 == 6 ) /*0x8b7738*/
    {
      v31 = v3[1] - 48; /*0x8b7744*/
      v30 = a2; /*0x8b774c*/
      v60 = FFX_Font_GetSlotGlyphMeta(5); /*0x8b7752*/
      *(_DWORD *)a2 = 1326432; /*0x8b7755*/
      if ( FFX_Locale_GetCurrentId(v41) == 10 ) /*0x8b7763*/
      {
        v43 = -1.0; /*0x8b7765*/
      }
      else if ( FFX_Locale_GetCurrentId(v42) <= 0 || FFX_Locale_GetCurrentId(v44) >= 9 ) /*0x8b777e*/
      {
        v43 = 0.0; /*0x8b7784*/
      }
      else
      {
        v43 = 1.0; /*0x8b7780*/
      }
      *(float *)(a2 + 24) = v43; /*0x8b7789*/
      if ( v60 ) /*0x8b778e*/
        v45 = (double)*(char *)(v60 + v31) * 0.25; /*0x8b77a0*/
      else
        v45 = 14.0; /*0x8b77a8*/
      *(float *)(a2 + 28) = v45; /*0x8b77b3*/
      *(float *)(a2 + 32) = 18.0; /*0x8b77be*/
      v61 = (float)(14 * (v31 % 18 / 2)); /*0x8b77ed*/
      v36 = v61; /*0x8b77f6*/
      *(float *)(a2 + 8) = v61; /*0x8b77f9*/
      v62 = (float)(18 * (v31 / 18)); /*0x8b77ff*/
      v37 = v62; /*0x8b7802*/
      goto LABEL_63; /*0x8b7805*/
    }
LABEL_83:
    *(float *)(a2 + 24) = 0.0; /*0x8b780a*/
    *(_WORD *)a2 = n15360; /*0x8b7818*/
    *(float *)(a2 + 28) = 10.0; /*0x8b781b*/
    *(_DWORD *)(a2 + 2) = 20; /*0x8b781e*/
    *(float *)(a2 + 32) = 18.0; /*0x8b782b*/
    *(float *)(a2 + 8) = 70.0; /*0x8b7834*/
    *(float *)(a2 + 12) = 0.0; /*0x8b7837*/
    *(float *)(a2 + 16) = 80.0; /*0x8b7840*/
    *(float *)(a2 + 20) = 18.0 + 0.0; /*0x8b784f*/
    return v3 + 1; /*0x8b784f*/
  }
  v23 = FFX_Font_GetSlotGlyphMeta(1); /*0x8b744a*/
  v24 = 208 * *v3; /*0x8b7456*/
  v53 = v23; /*0x8b7468*/
  v25 = v24 + v3[1] - 8784; /*0x8b746b*/
  *(_DWORD *)a2 = 1326336; /*0x8b746d*/
  if ( FFX_Locale_GetCurrentId(v24) == 10 ) /*0x8b747b*/
  {
    v27 = -1.0; /*0x8b747d*/
  }
  else if ( FFX_Locale_GetCurrentId(v26) <= 0 || FFX_Locale_GetCurrentId(v28) >= 9 ) /*0x8b7496*/
  {
    v27 = 0.0; /*0x8b749c*/
  }
  else
  {
    v27 = 1.0; /*0x8b7498*/
  }
  *(float *)(a2 + 24) = v27; /*0x8b74a1*/
  *(float *)(a2 + 28) = (double)*(char *)(v53 + v25) * 0.25; /*0x8b74c1*/
  *(float *)(a2 + 32) = 18.0; /*0x8b74cf*/
  v54 = (float)(14 * (v25 % 18 / 2)); /*0x8b74fe*/
  v29 = v54; /*0x8b7507*/
  *(float *)(a2 + 8) = v54; /*0x8b750a*/
  v55 = (float)(18 * (v25 / 18)); /*0x8b7510*/
  *(_WORD *)(a2 + 4) = v25 & 1; /*0x8b7516*/
  *(float *)(a2 + 12) = v55; /*0x8b7520*/
  *(float *)(a2 + 16) = v29 + *(float *)(a2 + 28); /*0x8b752a*/
  *(float *)(a2 + 20) = v55 + 18.0; /*0x8b7533*/
  if ( unk_18714F4 ) /*0x8b753d*/
    *(_WORD *)(a2 + 4) = 1; /*0x8b7544*/
  return v3 + 2; /*0x8b742e*/
}
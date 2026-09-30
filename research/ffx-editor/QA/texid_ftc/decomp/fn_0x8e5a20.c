// FFX Save: System save game
int __cdecl FFX_Save_SystemSaveGame(
        float *a1,
        float *a2,
        float *a3,
        float *a4,
        float *a5,
        float *a6,
        float *a7,
        float *a8)
{
  double v8; // st6
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  bool v14; // c0
  bool v15; // c3
  double v16; // st7
  double v17; // st6
  float v18; // [esp+8h] [ebp-4h]
  float v19; // [esp+8h] [ebp-4h]
  float v20; // [esp+8h] [ebp-4h]
  float v21; // [esp+8h] [ebp-4h]
  float v22; // [esp+8h] [ebp-4h]
  float v23; // [esp+8h] [ebp-4h]
  float v24; // [esp+8h] [ebp-4h]

  if ( unk_1871690 != 1 ) /*0x8e5a2d*/
    return 1; /*0x8e5a2d*/
  if ( unk_1871694 == 1 ) /*0x8e5a3a*/
  {
    v18 = (*a3 - *a1) * y_font_adjust / x_font_adjust + *a1; /*0x8e5a58*/
    *a3 = v18; /*0x8e5a5e*/
    v8 = MEMORY[0x18716B8]; /*0x8e5a60*/
    if ( MEMORY[0x18716B8] >= (double)v18 || unk_18716C0 <= (double)*a1 ) /*0x8e5a80*/
      return 0; /*0x8e5a80*/
    if ( *a1 >= v8 ) /*0x8e5a9f*/
    {
      v10 = unk_18716C0; /*0x8e5ad8*/
    }
    else
    {
      v10 = unk_18716C0; /*0x8e5aa1*/
      if ( v18 > v8 ) /*0x8e5aaa*/
      {
        v19 = (v8 - *a1) / (*a3 - *a1); /*0x8e5ab6*/
        *a5 = v19 * (*a7 - *a5) + *a5; /*0x8e5ac4*/
        *a1 = MEMORY[0x18716B8]; /*0x8e5acc*/
        v10 = unk_18716C0; /*0x8e5ace*/
      }
    }
    if ( *a1 < v10 && *a3 > v10 ) /*0x8e5af2*/
    {
      v20 = (*a3 - v10) / (*a3 - *a1); /*0x8e5b02*/
      *a7 = *a7 - v20 * (*a7 - *a5); /*0x8e5b10*/
      *a3 = unk_18716C0; /*0x8e5b18*/
    }
    *a3 = (*a3 - *a1) * x_font_adjust / y_font_adjust + *a1; /*0x8e5b30*/
  }
  else
  {
    v11 = MEMORY[0x18716B8]; /*0x8e5b46*/
    if ( MEMORY[0x18716B8] >= (double)*a3 || unk_18716C0 <= (double)*a1 ) /*0x8e5b65*/
      return 0; /*0x8e5b65*/
    if ( *a1 >= v11 || *a3 <= v11 ) /*0x8e5b85*/
    {
      v12 = unk_18716C0; /*0x8e5bb1*/
    }
    else
    {
      v21 = (v11 - *a1) / (*a3 - *a1); /*0x8e5b91*/
      *a5 = v21 * (*a7 - *a5) + *a5; /*0x8e5b9f*/
      *a1 = MEMORY[0x18716B8]; /*0x8e5ba7*/
      v12 = unk_18716C0; /*0x8e5ba9*/
    }
    if ( *a1 < v12 && *a3 > v12 ) /*0x8e5bc7*/
    {
      v22 = (*a3 - v12) / (*a3 - *a1); /*0x8e5bd7*/
      *a7 = *a7 - v22 * (*a7 - *a5); /*0x8e5be5*/
      *a3 = unk_18716C0; /*0x8e5bed*/
    }
  }
  v13 = *a2; /*0x8e5bf6*/
  v14 = unk_18716C4 < v13; /*0x8e5bfe*/
  v15 = unk_18716C4 == v13; /*0x8e5bfe*/
  v16 = unk_18716C4; /*0x8e5c02*/
  if ( v14 || v15 ) /*0x8e5c04*/
    return 0; /*0x8e5a8f*/
  v17 = unk_18716BC; /*0x8e5c1c*/
  if ( unk_18716BC >= (double)*a4 ) /*0x8e5c21*/
    return 0; /*0x8e5c2e*/
  if ( *a2 < v17 && *a4 > v17 ) /*0x8e5c49*/
  {
    v23 = (v17 - *a2) / (*a4 - *a2); /*0x8e5c55*/
    *a6 = v23 * (*a8 - *a6) + *a6; /*0x8e5c63*/
    *a2 = unk_18716BC; /*0x8e5c6b*/
    v16 = unk_18716C4; /*0x8e5c6d*/
  }
  if ( *a2 >= v16 || *a4 <= v16 ) /*0x8e5c8b*/
    return 1; /*0x8e5cc1*/
  v24 = (*a4 - v16) / (*a4 - *a2); /*0x8e5ca0*/
  *a8 = *a8 - v24 * (*a8 - *a6); /*0x8e5cae*/
  *a4 = unk_18716C4; /*0x8e5cb8*/
  return 1; /*0x8e5a8b*/
}
// Function: sub_8E5A20
// Address: 0x8e5a20
int __cdecl sub_8E5A20(float *a1, float *a2, float *a3, float *a4, float *a5, float *a6, float *a7, float *a8)
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

  if ( unk_1871690 != 1 )
    return 1;
  if ( unk_1871694 == 1 )
  {
    v18 = (*a3 - *a1) * unk_187166C / unk_1871668 + *a1;
    *a3 = v18;
    v8 = unk_18716B8;
    if ( unk_18716B8 >= (double)v18 || unk_18716C0 <= (double)*a1 )
      return 0;
    if ( *a1 >= v8 )
    {
      v10 = unk_18716C0;
    }
    else
    {
      v10 = unk_18716C0;
      if ( v18 > v8 )
      {
        v19 = (v8 - *a1) / (*a3 - *a1);
        *a5 = v19 * (*a7 - *a5) + *a5;
        *a1 = unk_18716B8;
        v10 = unk_18716C0;
      }
    }
    if ( *a1 < v10 && *a3 > v10 )
    {
      v20 = (*a3 - v10) / (*a3 - *a1);
      *a7 = *a7 - v20 * (*a7 - *a5);
      *a3 = unk_18716C0;
    }
    *a3 = (*a3 - *a1) * unk_1871668 / unk_187166C + *a1;
  }
  else
  {
    v11 = unk_18716B8;
    if ( unk_18716B8 >= (double)*a3 || unk_18716C0 <= (double)*a1 )
      return 0;
    if ( *a1 >= v11 || *a3 <= v11 )
    {
      v12 = unk_18716C0;
    }
    else
    {
      v21 = (v11 - *a1) / (*a3 - *a1);
      *a5 = v21 * (*a7 - *a5) + *a5;
      *a1 = unk_18716B8;
      v12 = unk_18716C0;
    }
    if ( *a1 < v12 && *a3 > v12 )
    {
      v22 = (*a3 - v12) / (*a3 - *a1);
      *a7 = *a7 - v22 * (*a7 - *a5);
      *a3 = unk_18716C0;
    }
  }
  v13 = *a2;
  v14 = unk_18716C4 < v13;
  v15 = unk_18716C4 == v13;
  v16 = unk_18716C4;
  if ( v14 || v15 )
    return 0;
  v17 = unk_18716BC;
  if ( unk_18716BC >= (double)*a4 )
    return 0;
  if ( *a2 < v17 && *a4 > v17 )
  {
    v23 = (v17 - *a2) / (*a4 - *a2);
    *a6 = v23 * (*a8 - *a6) + *a6;
    *a2 = unk_18716BC;
    v16 = unk_18716C4;
  }
  if ( *a2 >= v16 || *a4 <= v16 )
    return 1;
  v24 = (*a4 - v16) / (*a4 - *a2);
  *a8 = *a8 - v24 * (*a8 - *a6);
  *a4 = unk_18716C4;
  return 1;
}

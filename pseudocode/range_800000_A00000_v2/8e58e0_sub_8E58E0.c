// Function: sub_8E58E0
// Address: 0x8e58e0
int __cdecl sub_8E58E0(float *a1, float *a2, float *a3, float *a4)
{
  double v4; // st7
  double v5; // st6
  bool v6; // c0
  bool v7; // c3
  double v8; // st6
  double v9; // st5
  double v10; // st7
  int result; // eax

  if ( unk_1871690 != 1 )
    return 1;
  v4 = unk_18716B8;
  if ( unk_18716B8 >= (double)*a3
    || (v5 = *a1, v6 = unk_18716C0 < v5, v7 = unk_18716C0 == v5, v8 = unk_18716C0, v6 || v7)
    || unk_18716C4 <= (double)*a2
    || (v9 = unk_18716BC, unk_18716BC >= (double)*a4) )
  {
    *a1 = -100000.0;
    *a2 = -100000.0;
    *a3 = -100000.0;
    *a4 = -100000.0;
    v4 = unk_18716B8;
    v9 = unk_18716BC;
    v8 = unk_18716C0;
  }
  if ( *a1 >= v4 || *a3 <= v4 )
  {
    v10 = v9;
  }
  else
  {
    *a1 = v4;
    v8 = unk_18716C0;
    v10 = unk_18716BC;
  }
  if ( *a1 < v8 && *a3 > v8 )
  {
    *a3 = v8;
    v10 = unk_18716BC;
  }
  if ( *a2 < v10 && *a4 > v10 )
    *a2 = v10;
  if ( unk_18716C4 <= (double)*a2 )
    return 1;
  result = 1;
  if ( *a4 > (double)unk_18716C4 )
    *a4 = unk_18716C4;
  return result;
}

// Function: sub_910270
// Address: 0x910270
BOOL __cdecl sub_910270(float *i, float *ia)
{
  double v2; // st7
  double v3; // st6
  double v4; // st5
  double v5; // st4
  double v6; // st3
  double v7; // st1
  double v8; // st7
  double ib_1; // st4
  double ib_2; // st6
  float v12; // [esp+0h] [ebp-4h]
  float v13; // [esp+Ch] [ebp+8h]
  float ib; // [esp+10h] [ebp+Ch]

  v2 = i[10] - i[2];
  v3 = i[4] - *i;
  v4 = i[6] - i[2];
  v5 = i[8] - *i;
  v12 = v3 * v2 - v5 * v4;
  v6 = *ia - *i;
  v7 = ia[2] - i[2];
  v13 = v2 * v6 - v5 * v7;
  ib = v6 * -v4 + v3 * v7;
  v8 = v13;
  ib_1 = ib;
  if ( v13 > 0.0 && ib_1 > 0.0 && ib_1 + v8 < v12 )
    return 1;
  ib_2 = ib;
  return v8 < 0.0 && ib_2 < 0.0 && v12 < v8 + ib_2;
}

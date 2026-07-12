// Function: sub_8F1770
// Address: 0x8f1770
int __cdecl sub_8F1770(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  double v8; // st7
  double v10; // st6
  double v11; // st5
  double v12; // rt0
  double v13; // st6
  double v14; // st7
  int v15; // esi
  double v16; // [esp+1Ch] [ebp-10h]
  double v17; // [esp+24h] [ebp-8h]

  v8 = (double)a3;
  if ( a8 <= a7 )
    return a1;
  v10 = (double)(a5 + a3);
  v11 = (v10 - v8) / (double)a8;
  v16 = (double)a6 * v11 + v8;
  v17 = v11 * (double)a7 + v16;
  if ( a6 )
  {
    v14 = v10;
  }
  else
  {
    v12 = v10;
    v13 = v8;
    v14 = v12;
    v16 = v13;
  }
  if ( a6 + a7 >= a8 )
    v17 = v14;
  v15 = sub_8EC250(a1, a2, a3, a2 + a4, a5 + a3, 17, 17, 17, 128);
  return sub_8EC250(v15, (int)(double)(a2 + 1), (int)v16, (int)(double)(a2 + a4 - 1), (int)v17, 240, 240, 240, 128);
}

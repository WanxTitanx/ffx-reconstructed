// Function: sub_A93410
// Address: 0xa93410
// Size: 0x133
// Prototype: int __thiscall(void *)

int __fastcall sub_A93410(int *a1, int *a2)
{
  double X; // xmm0_8
  double X_2; // xmm0_8
  double v6; // st7
  double X_1; // [esp+14h] [ebp-8h]

  memset(a1, 0, 0x38u);
  a1[3] = (int)a2;
  a1[1] = a2[1];
  a1[2] = a2[1];
  *a1 = *a2;
  a1[5] = (int)sub_A92A60(a2[2], a2[1], 0);
  a1[11] = sub_A929C0(a2);
  X = (double)(a2[4] & 0x1FFFFF);
  if ( a2[4] < 0 )
    X = -X;
  X_1 = (float)((float)ldexp(X, ((a2[4] >> 21) & 0x3FFu) - 788) + 0.5);
  a1[12] = (int)floor(X_1);
  X_2 = (double)(a2[5] & 0x1FFFFF);
  if ( a2[5] < 0 )
    X_2 = -X_2;
  v6 = ldexp(X_2, ((a2[5] >> 21) & 0x3FFu) - 788);
  a1[13] = (int)floor((float)((float)v6 + 0.5));
  return 0;
}


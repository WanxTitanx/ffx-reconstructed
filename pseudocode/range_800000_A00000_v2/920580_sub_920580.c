// Function: sub_920580
// Address: 0x920580
void __cdecl sub_920580(int a1)
{
  int n2; // edi
  int v3; // eax
  int v4; // eax
  double v5; // st7
  float v6; // [esp+8h] [ebp-8h]
  float v7; // [esp+Ch] [ebp-4h]
  float v8; // [esp+18h] [ebp+8h]

  n2 = *(_DWORD *)(a1 + 220);
  if ( n2 )
  {
    v8 = flt_C44BE0[((int)(*(float *)(a1 + 236) * 65536.0 / 6.283185482025146) >> 4) & 0xFFF];
    if ( n2 == 2 )
    {
      v3 = *(_DWORD *)(a1 + 228);
      if ( v3 > 0 )
      {
        v7 = (float)(v3 - *(_DWORD *)(a1 + 240));
        v6 = (float)v3;
        v8 = v7 / v6 * v8;
      }
    }
    v4 = *(_DWORD *)(a1 + 228);
    v5 = *(float *)(a1 + 232) * v8;
    ++*(_DWORD *)(a1 + 240);
    *(float *)(a1 + 172) = v5;
    *(float *)(a1 + 236) = *(float *)(a1 + 224) + *(float *)(a1 + 236);
    if ( v4 > 0 && *(_DWORD *)(a1 + 240) >= v4 )
      sub_920650(a1);
    sub_920C00(a1);
  }
}

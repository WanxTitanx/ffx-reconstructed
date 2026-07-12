// Function: sub_A756E0
// Address: 0xa756e0
// Size: 0x145
// Prototype: 

int __cdecl sub_A756E0(int a1, int a2)
{
  int v2; // esi
  int v3; // ecx
  double v4; // st7
  int v5; // edi
  int v6; // esi
  double v7; // st7
  int v9; // [esp-8h] [ebp-60h]
  float v10; // [esp+8h] [ebp-50h]
  int v11; // [esp+Ch] [ebp-4Ch]
  float Src; // [esp+10h] [ebp-48h] BYREF
  _BYTE v13[64]; // [esp+14h] [ebp-44h] BYREF

  v2 = *(_DWORD *)(a1 + 544);
  v11 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      v3 = sub_800F80(a1 + 768, v2, *(unsigned __int16 *)(a2 + 2));
      if ( *(float *)(v3 + 68) >= 0.0 )
        v4 = *(float *)(v3 + 68) * 0.00390625;
      else
        v4 = 0.0;
      v10 = v4;
      v5 = v2 + 208;
      v9 = v2 + 208;
      v6 = v2 + 224;
      sub_63A470(v11, v6, v9);
      sub_826B00(v13, v11);
      sub_7E78B0(v5, v13, v5);
      sub_7E78B0(v6, v13, v6);
      v7 = *(float *)(v5 + 20);
      Src = v7 - *(float *)(v5 + 4);
      Src = v7 - Src * v10;
      Src = fabs(Src);
      sub_63DA30(v11, (int)"center", &Src);
      if ( v10 >= 1.0 )
        sub_63DA20();
      return a2 + 14;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    sub_63D9C0(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]), 0);
    FFX_BtlActor_ResetEffectStateFlags(*(_BYTE *)(v2 + 24), 1);
    return a2 + 4;
  }
}


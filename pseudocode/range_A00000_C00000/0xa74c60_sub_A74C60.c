// Function: sub_A74C60
// Address: 0xa74c60
// Size: 0xd0
// Prototype: 

int __cdecl sub_A74C60(int a1, int a2)
{
  int v2; // edi
  int v4; // [esp-4h] [ebp-Ch]

  v2 = *(_DWORD *)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      v4 = *(_DWORD *)(a1 + 808);
      *(_DWORD *)a1 = unk_C8F508[0];
      *(float *)(a1 + 4) = flt_C8F50C;
      *(float *)(a1 + 8) = flt_C8F510;
      *(float *)(a1 + 12) = flt_C8F514[0];
      *(float *)a1 = 2048.0;
      *(float *)(a1 + 4) = 2048.0;
      sub_A75170(a1, v2, *(_DWORD *)(v2 + 188), v2 + 144, v4);
      return a2 + 2;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    *(_DWORD *)(v2 + 188) = sub_7FF6A0(*(_DWORD *)(a1 + 936), 163360);
    *(_DWORD *)a1 = unk_C8F508[0];
    *(float *)(a1 + 4) = flt_C8F50C;
    *(float *)(a1 + 8) = flt_C8F510;
    *(float *)(a1 + 12) = flt_C8F514[0];
    *(float *)a1 = 0.0;
    *(float *)(a1 + 4) = 0.0;
    sub_A753F0(*(_DWORD *)(v2 + 188), a1);
    return a2 + 2;
  }
}


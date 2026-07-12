// Function: sub_A56330
// Address: 0xa56330
// Size: 0x73
// Prototype: 

int __cdecl sub_A56330(int a1, int a2, int a3, int a4)
{
  int result; // eax

  if ( !a4 )
    return sub_A5B930();
  result = a3;
  if ( a3 )
  {
    if ( a3 == 1 )
    {
      FFX_BtlEffect_Enable(-2147483647);
      return sub_A598A0();
    }
  }
  else
  {
    FFX_BtlEffect_Enable(-2147483567);
    sub_A5B7B0();
    result = unk_1A86108;
    *(_BYTE *)(unk_1A86108 + 5859) = 1;
    *(_DWORD *)(result + 5866) = &unk_1640030;
    *(_DWORD *)(result + 5870) = 1310800;
    *(_BYTE *)(result + 5874) = 0;
    *(_DWORD *)(result + 5876) = sub_A5A080;
  }
  return result;
}


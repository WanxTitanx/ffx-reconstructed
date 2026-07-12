// Function: sub_A56060
// Address: 0xa56060
// Size: 0x6d
// Prototype: 

int __cdecl sub_A56060(int a1, int a2, int a3, int a4)
{
  int result; // eax

  *(_BYTE *)(unk_1A86108 + 8355) = 0;
  if ( !a4 || a3 )
  {
    FFX_BtlEffect_Enable(-2147483644);
    result = unk_1A86108;
    if ( !*(_BYTE *)(unk_1A86108 + 5027) || *(_DWORD *)(unk_1A86108 + 5044) )
    {
      *(_BYTE *)(unk_1A86108 + 5033) = 0;
      *(_DWORD *)(result + 5044) = sub_A5A270;
    }
  }
  else
  {
    FFX_Abmap_SaveMenuRuntimeToSphereGridState();
    FFX_Abmap_RecomputePartyStatsAndLearnedMoves();
    result = sub_8E27E0();
    unk_1A85F70 = 0;
  }
  return result;
}


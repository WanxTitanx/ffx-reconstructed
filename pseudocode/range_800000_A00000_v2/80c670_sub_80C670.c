// Function: sub_80C670
// Address: 0x80c670
int __cdecl sub_80C670(int a1, int a2)
{
  unsigned int n36864; // eax
  int v3; // esi

  n36864 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n36864 > 0x3000 )
  {
    if ( n36864 == 0x8000 )
    {
      v3 = a2;
      if ( sub_800F80((_DWORD *)(a1 + 768), *(_DWORD *)(a1 + 544), *(_WORD *)(a2 + 2)) == *(_DWORD *)(a1 + 800) )
        return v3 + 4;
    }
    else
    {
      if ( n36864 != 36864 )
        return a2;
      v3 = a2;
      if ( unk_11A004B )
        return a2 + 2;
    }
    *(_BYTE *)(a1 + 528) = 1;
    return v3;
  }
  else
  {
    if ( n36864 != 12288 )
    {
      if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
      {
        *(_BYTE *)(a1 + 528) = sub_7E5C60(*(__int16 *)(a2 + 2));
        return a2 + 4;
      }
      if ( n36864 == 4096 )
      {
        *(_BYTE *)(a1 + 528) = sub_800CC0(*(_DWORD *)(a1 + 544)) * *(_BYTE *)(a2 + 2);
        return a2 + 4;
      }
      if ( n36864 == 0x2000 )
      {
        v3 = a2;
        *(_BYTE *)(a1 + 528) = (int)*(float *)(*(__int16 *)(a2 + 2) + *(_DWORD *)(a1 + 544));
        return v3 + 4;
      }
      return a2;
    }
    v3 = a2;
    if ( (int)sub_7FE9C0(*(__int16 *)(a2 + 2)) >= 0 )
      return v3 + 4;
    *(_BYTE *)(a1 + 528) = 1;
    return a2;
  }
}

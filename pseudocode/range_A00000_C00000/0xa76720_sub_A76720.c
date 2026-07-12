// Function: sub_A76720
// Address: 0xa76720
// Size: 0x49
// Prototype: 

int __cdecl sub_A76720(int a1, int a2)
{
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      sub_A76770(a1, *(_DWORD *)(a1 + 544));
      return a2 + 2;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    *(_WORD *)(*(_DWORD *)(a1 + 544) + 192) = 0;
    return a2 + 2;
  }
}


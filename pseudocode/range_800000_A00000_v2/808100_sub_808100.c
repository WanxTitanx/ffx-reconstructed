// Function: sub_808100
// Address: 0x808100
int __cdecl sub_808100(int a1, int a2)
{
  int v2; // edx

  v2 = *(_DWORD *)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0x1000 )
    {
      nullsub_107(*(_DWORD *)(a1 + 544));
      return a2 + 2;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    *(_BYTE *)(v2 + 187) = 7;
    *(_WORD *)(v2 + 168) = 0;
    sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
    return a2 + 2;
  }
}

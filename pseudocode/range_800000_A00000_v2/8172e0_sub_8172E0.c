// Function: sub_8172E0
// Address: 0x8172e0
int __cdecl sub_8172E0(int a1, int a2)
{
  int v2; // esi
  int v3; // ecx
  char n17; // al
  int v6; // edx
  unsigned int v7; // eax

  v2 = *(_DWORD *)(a1 + 544);
  v3 = sub_800F80((_DWORD *)(a1 + 768), v2, *(_WORD *)(a2 + 2));
  n17 = *(_BYTE *)(v3 + 187);
  if ( n17 == 10 )
  {
    if ( v2 == v3 )
    {
      v6 = 1;
      LOWORD(v7) = 0;
    }
    else
    {
      v6 = 0;
      v7 = (unsigned int)(v2 - *(_DWORD *)(a1 + 800)) >> 8;
    }
    if ( !*(_WORD *)(a1 + 530) )
      sub_7E6020(*(_DWORD *)(v3 + 188), v2 + 144, v6, v7);
  }
  else if ( n17 == 17 && !*(_WORD *)(a1 + 530) )
  {
    sub_7E6020(*(_DWORD *)(v2 + 188), v2 + 144, 0, 0);
    return a2 + 4;
  }
  return a2 + 4;
}

// Function: sub_A47560
// Address: 0xa47560
// Size: 0xd0
// Prototype: 

int __cdecl sub_A47560(unsigned __int16 a1, int a2)
{
  int v2; // ebx
  unsigned __int16 v3; // dx
  int v4; // ecx
  int n5; // eax
  int *v6; // edi
  int v7; // esi
  char v8; // cl
  __int16 v9; // ax
  int n5_1; // [esp+10h] [ebp+Ch]

  v2 = *(_DWORD *)&word_1A86100 + a2;
  if ( (unsigned __int16)(word_1A86100 + a2) > unk_1A860FC )
    return 1;
  v3 = a1;
  v4 = 40 * a1;
  if ( *(_WORD *)(v4 + unk_2305834 + 2092) <= (unsigned __int16)v2 )
    return 1;
  *(_WORD *)(v4 + unk_2305834 + 2092) = v2;
  n5 = 5;
  v6 = (int *)(v4 + unk_2305834 + 2068);
  n5_1 = 5;
  do
  {
    v7 = *v6++;
    if ( !v7 )
      break;
    v8 = *(_BYTE *)(v7 + 14);
    if ( (v8 & 3) == 0 )
    {
      *(_DWORD *)&word_1A86100 = (char)(unk_1A86104 & *(_BYTE *)(v7 + 12)) != 0 ? 1 : 4;
      v9 = *(_WORD *)v7;
      *(_BYTE *)(v7 + 14) = v8 | 5;
      if ( v9 == v3 )
        v9 = *(_WORD *)(v7 + 2);
      if ( sub_A47560(v9, v2) )
        *(_BYTE *)(v7 + 14) &= ~4u;
      *(_BYTE *)(v7 + 14) &= ~1u;
      n5 = n5_1;
      v3 = a1;
    }
    n5_1 = --n5;
  }
  while ( n5 );
  return 0;
}


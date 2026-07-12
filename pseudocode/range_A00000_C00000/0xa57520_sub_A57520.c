// Function: sub_A57520
// Address: 0xa57520
// Size: 0xb7
// Prototype: 

int __cdecl sub_A57520(int a1, __int16 *a2)
{
  char n64; // al
  __int16 n4096; // ax
  unsigned __int16 v4; // cx
  __int16 v5; // dx
  int result; // eax
  _BYTE *v7; // ecx
  int n16; // ebx

  *a2 = sub_8BE410();
  if ( a1 )
    goto LABEL_7;
  n64 = sub_8BE420(0, 0, 3) + 0x80;
  if ( n64 < -64 )
  {
    n4096 = 4096;
LABEL_6:
    *a2 |= n4096;
    goto LABEL_7;
  }
  if ( n64 > 64 )
  {
    n4096 = 0x4000;
    goto LABEL_6;
  }
LABEL_7:
  v4 = *a2;
  a2[1] = *a2 & ~a2[2];
  a2[2] = v4;
  v5 = 1;
  result = 0;
  v7 = a2 + 13;
  *(_DWORD *)(a2 + 3) = 0;
  n16 = 16;
  do
  {
    if ( ((unsigned __int16)v5 & (unsigned __int16)a2[1]) != 0 )
    {
      a2[3] |= v5;
      a2[4] |= v5;
      goto LABEL_18;
    }
    if ( ((unsigned __int16)v5 & (unsigned __int16)*a2) == 0 )
    {
      *(v7 - 16) = 0;
LABEL_17:
      *v7 = 0;
      goto LABEL_18;
    }
    if ( ++*(v7 - 16) >= 6u )
    {
      *(v7 - 16) = 6;
      a2[3] |= v5;
      if ( !*v7 )
        a2[4] |= v5;
      if ( ++*v7 >= 3u )
        goto LABEL_17;
    }
LABEL_18:
    ++v7;
    v5 *= 2;
    --n16;
  }
  while ( n16 );
  return result;
}


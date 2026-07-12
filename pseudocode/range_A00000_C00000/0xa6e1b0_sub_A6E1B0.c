// Function: sub_A6E1B0
// Address: 0xa6e1b0
// Size: 0x7e
// Prototype: 

int __cdecl sub_A6E1B0(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  _WORD *buf; // edi
  int v6; // eax
  _WORD *v7; // edi
  int i; // ecx

  v4 = a4;
  *(_WORD *)a1 = a4;
  *(_WORD *)(a1 + 2) = 0;
  *(_WORD *)(a1 + 4) = sub_A6A2B0(a2);
  buf = (_WORD *)(a1 + 48);
  if ( a4 > 0 )
  {
    do
    {
      buf[6] = -1;
      buf += 48;
      --v4;
    }
    while ( v4 );
  }
  *(_DWORD *)(a1 + 12) = buf;
  v6 = sub_A6A2B0(a2);
  if ( v6 > 0 )
  {
    memset(buf, 0xFFu, 4 * ((unsigned int)v6 >> 1));
    v7 = &buf[2 * ((unsigned int)v6 >> 1)];
    for ( i = v6 & 1; i; --i )
      *v7++ = -1;
  }
  return sub_A6A0C0(a2, a3, (float *)(a1 + 16), (float *)(a1 + 32));
}


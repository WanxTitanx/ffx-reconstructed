// Function: sub_A474D0
// Address: 0xa474d0
// Size: 0x87
// Prototype: 

int __cdecl sub_A474D0(__int16 a1, unsigned __int16 a2, char a3)
{
  int v3; // eax
  int v4; // ecx
  _WORD *v5; // eax
  int v6; // ecx
  _BYTE *v7; // eax

  v3 = unk_2305834;
  v4 = *(__int16 *)(unk_2305834 + 2);
  if ( *(_WORD *)(unk_2305834 + 2) )
  {
    v5 = (_WORD *)(unk_2305834 + 2092);
    do
    {
      --v4;
      if ( *(v5 - 15) != 0xFFFF )
        *v5 = -1;
      v5 += 20;
    }
    while ( v4 );
    v3 = unk_2305834;
  }
  v6 = *(__int16 *)(v3 + 4);
  if ( *(_WORD *)(v3 + 4) )
  {
    v7 = (_BYTE *)(v3 + 43030);
    do
    {
      *v7 &= 0xF0u;
      v7 += 20;
      --v6;
    }
    while ( v6 );
  }
  sub_A58DF0(2);
  unk_1A860FC = 4 * a2;
  unk_1A86100 = 0;
  unk_1A86104 = 1 << a3;
  return sub_A47560(a1, 0);
}


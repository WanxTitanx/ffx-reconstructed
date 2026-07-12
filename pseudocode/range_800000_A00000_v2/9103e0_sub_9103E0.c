// Function: sub_9103E0
// Address: 0x9103e0
int __cdecl sub_9103E0(int a1, int a2, unsigned int a3, int a4)
{
  _DWORD *v4; // eax
  int n3; // ecx
  _BYTE *v6; // ecx
  _WORD *v7; // edx
  int result; // eax

  *(_WORD *)(a1 + 18) = 0;
  if ( a3 < a3 + 3 )
  {
    v4 = (_DWORD *)(a2 + 16 * a3 + 12);
    n3 = 3;
    do
    {
      *v4 = 127;
      v4 += 4;
      --n3;
    }
    while ( n3 );
  }
  v6 = (_BYTE *)(a2 + 16 * a3);
  *(_BYTE *)a1 = *v6;
  *(_BYTE *)(a1 + 1) = v6[4];
  *(_BYTE *)(a1 + 2) = v6[8];
  *(_BYTE *)(a1 + 3) = v6[12];
  *(_BYTE *)(a1 + 4) = v6[16];
  *(_BYTE *)(a1 + 5) = v6[20];
  *(_BYTE *)(a1 + 6) = v6[24];
  *(_BYTE *)(a1 + 7) = v6[28];
  *(_BYTE *)(a1 + 8) = *(_BYTE *)(a2 + 16 * (a3 + 2));
  *(_BYTE *)(a1 + 9) = v6[36];
  *(_BYTE *)(a1 + 10) = v6[40];
  *(_BYTE *)(a1 + 11) = v6[44];
  v7 = (_WORD *)(a2 + 16 * a4);
  *(_WORD *)(a1 + 20) = *v7;
  *(_WORD *)(a1 + 22) = v7[2];
  *(_WORD *)(a1 + 24) = v7[8];
  *(_WORD *)(a1 + 26) = v7[10];
  *(_WORD *)(a1 + 28) = *(_WORD *)(a2 + 16 * (a4 + 2));
  result = (unsigned __int16)v7[18];
  *(_WORD *)(a1 + 30) = result;
  return result;
}

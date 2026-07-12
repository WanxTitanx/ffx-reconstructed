// Function: sub_910340
// Address: 0x910340
int __cdecl sub_910340(int a1, int a2, unsigned int a3)
{
  _DWORD *v3; // eax
  int n3; // ecx
  _BYTE *v5; // ecx
  int result; // eax

  *(_WORD *)(a1 + 18) = 0;
  if ( a3 < a3 + 3 )
  {
    v3 = (_DWORD *)(a2 + 16 * a3 + 12);
    n3 = 3;
    do
    {
      *v3 = 128;
      v3 += 4;
      --n3;
    }
    while ( n3 );
  }
  v5 = (_BYTE *)(a2 + 16 * a3);
  *(_BYTE *)a1 = *v5;
  *(_BYTE *)(a1 + 1) = v5[4];
  *(_BYTE *)(a1 + 2) = v5[8];
  *(_BYTE *)(a1 + 3) = v5[12];
  *(_BYTE *)(a1 + 4) = v5[16];
  *(_BYTE *)(a1 + 5) = v5[20];
  *(_BYTE *)(a1 + 6) = v5[24];
  *(_BYTE *)(a1 + 7) = v5[28];
  *(_BYTE *)(a1 + 8) = *(_BYTE *)(a2 + 16 * (a3 + 2));
  *(_BYTE *)(a1 + 9) = v5[36];
  *(_BYTE *)(a1 + 10) = v5[40];
  result = (unsigned __int8)v5[44];
  *(_BYTE *)(a1 + 11) = result;
  return result;
}

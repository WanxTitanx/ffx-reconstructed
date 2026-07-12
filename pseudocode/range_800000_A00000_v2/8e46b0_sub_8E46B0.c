// Function: sub_8E46B0
// Address: 0x8e46b0
int __cdecl sub_8E46B0(int a1, int a2, int a3, int n2, int a5)
{
  int n357; // ecx
  __int16 n48; // cx

  n357 = 357;
  if ( MEMORY[0x23CC128] )
    n357 = *(__int16 *)(MEMORY[0x23CC128] + 78)
         - *(_DWORD *)(MEMORY[0x23CC128] + 12 * (*(__int16 *)(MEMORY[0x23CC128] + 72) + 8))
         - 24;
  unk_23CC124 = sub_8E4790(a1, a2, a3, n2, n357, a5);
  *(_WORD *)(unk_23CC124 + 70) = 0;
  *(_BYTE *)(unk_23CC124 + 62) = 3;
  *(_BYTE *)(unk_23CC124 + 63) = 0;
  *(_DWORD *)(unk_23CC124 + 20) = sub_8E4A90;
  *(_DWORD *)(unk_23CC124 + 16) = sub_8E4140;
  if ( MEMORY[0x23CC128] )
    n48 = *(_WORD *)(MEMORY[0x23CC128] + 74) + *(_WORD *)(MEMORY[0x23CC128] + 78) - *(_WORD *)(unk_23CC124 + 78);
  else
    n48 = 48;
  *(_DWORD *)(unk_23CC124 + 148) = 1;
  *(_WORD *)(unk_23CC124 + 74) = n48;
  *(_WORD *)(unk_23CC124 + 76) = 37;
  *(_DWORD *)(unk_23CC124 + 144) = -1;
  return unk_23CC124;
}

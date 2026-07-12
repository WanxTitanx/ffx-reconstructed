// Function: sub_800DD0
// Address: 0x800dd0
int __cdecl sub_800DD0(int a1, int a2, int a3)
{
  int result; // eax

  *(_DWORD *)(a2 + 48) = *(_DWORD *)(a3 + 48);
  *(_DWORD *)(a2 + 52) = *(_DWORD *)(a3 + 52);
  *(_DWORD *)(a2 + 56) = *(_DWORD *)(a3 + 56);
  *(_DWORD *)(a2 + 60) = *(_DWORD *)(a3 + 60);
  *(_DWORD *)(a2 + 64) = *(_DWORD *)(a3 + 64);
  *(_DWORD *)(a2 + 68) = *(_DWORD *)(a3 + 68);
  *(_DWORD *)(a2 + 72) = *(_DWORD *)(a3 + 72);
  *(_DWORD *)(a2 + 76) = *(_DWORD *)(a3 + 76);
  *(_DWORD *)(a2 + 144) = *(_DWORD *)(a3 + 144);
  *(_DWORD *)(a2 + 148) = *(_DWORD *)(a3 + 148);
  *(_DWORD *)(a2 + 152) = *(_DWORD *)(a3 + 152);
  *(_DWORD *)(a2 + 156) = *(_DWORD *)(a3 + 156);
  *(_WORD *)(a2 + 28) = (unsigned int)(a3 - *(_DWORD *)(a1 + 32)) >> 8;
  *(_BYTE *)(a2 + 30) = *(_BYTE *)(a3 + 30);
  *(_WORD *)(a2 + 20) = *(_WORD *)(a3 + 20);
  *(_BYTE *)(a2 + 24) = *(_BYTE *)(a3 + 24);
  *(_BYTE *)(a2 + 186) = *(_BYTE *)(a3 + 186);
  result = *(unsigned __int8 *)(a3 + 179);
  *(_BYTE *)(a2 + 179) = result;
  return result;
}

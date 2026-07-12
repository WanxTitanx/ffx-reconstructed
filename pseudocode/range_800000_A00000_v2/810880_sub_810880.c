// Function: sub_810880
// Address: 0x810880
int __cdecl sub_810880(int a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // edx

  v4 = *(_DWORD *)(a2 + 32) + (*(unsigned __int16 *)(a4 + 76) << 8);
  v5 = *(_DWORD *)(a2 + 4 * *(unsigned __int8 *)(v4 + 30) + 96);
  *(_DWORD *)(a4 + 4) = *(_DWORD *)(*(_DWORD *)(v5 + 16) + 4 * *(__int16 *)(a3 + 2) + v5);
  *(_DWORD *)(a4 + 8) = -16711680;
  *(_BYTE *)(a4 + 8) = *(_BYTE *)(v4 + 179);
  *(_DWORD *)(a4 + 12) = 256;
  *(_DWORD *)(a4 + 28) = -2139062144;
  *(_DWORD *)(a4 + 44) = 0;
  *(_DWORD *)(a4 + 60) = 0;
  return a3 + 4;
}

// Function: sub_80E2C0
// Address: 0x80e2c0
int __cdecl sub_80E2C0(int a1, int a2, int a3, int a4, int a5)
{
  *(_DWORD *)(a1 + 28) = *(_DWORD *)(a4 + 200);
  *(_BYTE *)(a1 + 31) = 0;
  *(_WORD *)(a1 + 25) = -32640;
  *(_BYTE *)(a1 + 24) = 0x80;
  *(_BYTE *)(a1 + 27) = *(_BYTE *)(a4 + 203);
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)a1 = *(unsigned __int16 *)(a4 + 192);
  *(_DWORD *)(a1 + 4) = *(_DWORD *)(a3 + 40);
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 64) = *(_DWORD *)(a4 + 196);
  *(_DWORD *)(a1 + 56) = 0;
  *(_DWORD *)(a1 + 60) = 0;
  *(_WORD *)(a1 + 76) = -32640;
  *(_DWORD *)(a1 + 52) = *(_DWORD *)(a3 + 84);
  *(_WORD *)(a1 + 8) = *(_WORD *)(a4 + 194);
  *(_DWORD *)(a1 + 40) = a2 + 64;
  *(_DWORD *)(a1 + 44) = a2 + 128;
  *(_DWORD *)(a1 + 36) = a2;
  *(_DWORD *)(a1 + 32) = a2 + 192;
  *(_DWORD *)(a1 + 68) = 0;
  if ( a5 == -1 )
    return 0;
  else
    return sub_7E3720(*(_DWORD *)(a3 + 4 * *(unsigned __int8 *)(a4 + 30) + 96), 4, a5);
}

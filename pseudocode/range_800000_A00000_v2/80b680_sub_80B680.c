// Function: sub_80B680
// Address: 0x80b680
int __cdecl sub_80B680(int a1, int a2, int a3, int a4, int a5)
{
  __int16 v5; // ax
  int n0xFF80; // ebx
  int v8; // eax
  int v9; // edx
  _BYTE dst[76]; // [esp-4Ch] [ebp-A8h] BYREF
  _DWORD src[19]; // [esp+Ch] [ebp-50h] BYREF
  int v12; // [esp+58h] [ebp-4h]

  v5 = sub_801620(a1, a4);
  if ( v5 < 0 )
    return 0;
  n0xFF80 = *(_DWORD *)(a1 + 32) + (v5 << 8);
  v12 = v5;
  sub_801120((_DWORD *)n0xFF80);
  sub_800DD0(a1, n0xFF80, a2);
  *(_WORD *)(n0xFF80 + 26) = (*(_WORD *)(a1 + 2))++;
  if ( *(_WORD *)(a1 + 2) >= 0xFFF0u )
    *(_WORD *)(a1 + 2) = 0x8000;
  v8 = unknown_libname_742(a3);
  v9 = v12;
  *(_DWORD *)n0xFF80 = v8;
  src[0] = a2;
  src[1] = n0xFF80;
  src[2] = a1;
  src[3] = v9;
  src[5] = a5;
  if ( a4 == 1 )
  {
    qmemcpy(dst, src, sizeof(dst));
    nullsub_106(v9);
  }
  return n0xFF80;
}

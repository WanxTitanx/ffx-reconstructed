// Function: sub_890340
// Address: 0x890340
void __cdecl sub_890340(int a1, int a2, int a3, int a4)
{
  int v4; // eax
  unsigned __int64 v5; // rt0
  unsigned int v6; // esi
  int v7; // eax
  int v8; // [esp-Ch] [ebp-20h]

  v4 = unknown_libname_741(*dword_133C88C);
  *(_DWORD *)(v4 + 16) = 32769;
  *(_DWORD *)(v4 + 20) = 0x20000000;
  *(_DWORD *)(v4 + 24) = 254;
  *(_DWORD *)(v4 + 28) = 0;
  v5 = a2 | (unsigned __int64)((__int64)(a2 + a4) << 16);
  *(_DWORD *)(v4 + 40) = 65;
  *(_DWORD *)(v4 + 44) = 0;
  *(_DWORD *)(v4 + 48) = 0;
  *(_DWORD *)(v4 + 52) = 0;
  *(_DWORD *)(v4 + 56) = 0;
  *(_DWORD *)(v4 + 60) = 0;
  *(_QWORD *)(v4 + 32) = __PAIR64__(
                           (a1 >> 31) | (unsigned int)(((a1 + a3) | (v5 << 16)) >> 16),
                           a1 | (((unsigned int)(a1 + a3) | ((_DWORD)v5 << 16)) << 16));
  v6 = v4 + 64;
  *(_WORD *)v4 = 3;
  *(_WORD *)(v4 + 2) = 4096;
  *(_DWORD *)(v4 + 4) = 0;
  *(_DWORD *)(v4 + 8) = 0;
  *(_DWORD *)(v4 + 12) = 1342177283;
  v7 = unknown_libname_742(v4 + 64);
  v8 = dword_133C88C[3];
  *dword_133C88C = v7;
  if ( v6 > unknown_libname_741(v8) )
    nullsub_34();
}

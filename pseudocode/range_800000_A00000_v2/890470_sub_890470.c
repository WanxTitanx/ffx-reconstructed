// Function: sub_890470
// Address: 0x890470
void __cdecl sub_890470(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // edi
  int v9; // eax
  int v10; // esi
  __int64 v11; // rax
  int v12; // edi
  int v13; // ecx
  __int64 v14; // rax
  int v15; // eax
  int v16; // [esp-Ch] [ebp-28h]
  int v17; // [esp+Ch] [ebp-10h]
  int v18; // [esp+10h] [ebp-Ch]
  int v19; // [esp+14h] [ebp-8h]
  int v20; // [esp+24h] [ebp+8h]
  int v21; // [esp+28h] [ebp+Ch]

  v19 = unk_133C8C8;
  if ( a1 )
  {
    v8 = unk_133C8CC;
    v9 = unk_133C8C4;
  }
  else
  {
    v8 = unk_133C8C4;
    v9 = unk_133C8CC;
  }
  v18 = v9;
  v10 = 16 * a2;
  v21 = (int)unk_23CC014;
  v20 = (int)unk_23CC010;
  v17 = unknown_libname_741(*dword_133C88C);
  *(_DWORD *)(v17 + 40) = v8;
  *(_DWORD *)(v17 + 16) = 32769;
  *(_DWORD *)(v17 + 20) = -2080374784;
  *(_DWORD *)(v17 + 24) = -183167728;
  *(_DWORD *)(v17 + 28) = 0;
  *(_DWORD *)(v17 + 32) = 843;
  *(_DWORD *)(v17 + 36) = 0;
  *(_DWORD *)(v17 + 44) = 0;
  v11 = v21 + 16 * a3;
  v12 = (v10 & 0xFFFFFF0) << 12;
  *(_DWORD *)(v17 + 48) = v11 | ((v12 | (v20 + 16 * a4)) << 16);
  *(_DWORD *)(v17 + 56) = v19;
  *(_DWORD *)(v17 + 52) = HIDWORD(v11) | ((((unsigned __int64)(v10 & 0xFFFFFF0) << 12) | (v20 + 16 * a4)) >> 16);
  *(_DWORD *)(v17 + 60) = 0;
  *(_DWORD *)(v17 + 64) = (v21 + 16 * a5) | ((v12 | (v20 + 16 * a6)) << 16);
  *(_DWORD *)(v17 + 72) = v18;
  *(_DWORD *)(v17 + 68) = ((v21 + 16 * a5) >> 31)
                        | ((((unsigned __int64)(v10 & 0xFFFFFF0) << 12) | (v20 + 16 * a6)) >> 16);
  *(_DWORD *)(v17 + 76) = 0;
  v13 = v12 | (v20 + 16 * a8);
  v14 = v21 + 16 * a7;
  *(_DWORD *)(v17 + 80) = v14 | (v13 << 16);
  *(_DWORD *)(v17 + 88) = 0;
  *(_DWORD *)(v17 + 92) = 0;
  *(_DWORD *)(v17 + 84) = HIDWORD(v14) | (__PAIR64__(((v10 & 0xFFFFFF0u) >> 20) | ((v20 + 16 * a8) >> 31), v13) >> 16);
  *(_WORD *)v17 = 5;
  *(_WORD *)(v17 + 2) = 4096;
  *(_DWORD *)(v17 + 4) = 0;
  *(_DWORD *)(v17 + 8) = 0;
  *(_DWORD *)(v17 + 12) = 1342177285;
  v15 = unknown_libname_742(v17 + 96);
  v16 = dword_133C88C[3];
  *dword_133C88C = v15;
  if ( v17 + 96 > (unsigned int)unknown_libname_741(v16) )
    nullsub_34();
}

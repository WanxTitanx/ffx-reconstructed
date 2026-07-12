// Function: sub_9A3350
// Address: 0x9a3350
_DWORD *__userpurge sub_9A3350@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        _DWORD *a3,
        _DWORD *a4,
        int a5,
        int a6,
        __int16 a7,
        __int16 a8,
        int a9,
        int a10)
{
  int v11; // eax
  _DWORD *v12; // esi
  int v13; // eax
  int v14; // ecx
  int v15; // eax
  int v17; // [esp-4Ch] [ebp-58h]
  _DWORD src[10]; // [esp-30h] [ebp-3Ch] BYREF
  int v19[2]; // [esp-8h] [ebp-14h] BYREF
  _DWORD v20[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v20[0] = a2;
  v20[1] = retaddr;
  v11 = sub_9D4CE0(64, 16);
  v12 = (_DWORD *)v11;
  if ( v11 )
  {
    *(_DWORD *)v11 = a6;
    *(_WORD *)(v11 + 4) = a7;
    *(_WORD *)(v11 + 6) = a8;
    *(_DWORD *)(v11 + 16) = *a3;
    *(_DWORD *)(v11 + 20) = a3[1];
    *(_DWORD *)(v11 + 24) = a3[2];
    *(_DWORD *)(v11 + 28) = a3[3];
    *(_DWORD *)(v11 + 32) = *a4;
    *(_DWORD *)(v11 + 36) = a4[1];
    *(_DWORD *)(v11 + 40) = a4[2];
    *(_DWORD *)(v11 + 44) = a4[3];
    *(_DWORD *)(v11 + 8) = 0;
    *(_DWORD *)(v11 + 56) = 0;
    *(_DWORD *)(v11 + 52) = 0;
  }
  else
  {
    v12 = 0;
  }
  src[0] = *a3;
  src[1] = a3[1];
  src[2] = a3[2];
  src[3] = a3[3];
  src[4] = *a4;
  src[5] = a4[1];
  src[6] = a4[2];
  src[7] = a4[3];
  v12[15] = *(_DWORD *)(a1 + 104);
  v12[3] = ++*(_DWORD *)(a1 + 148);
  v12[12] = sub_988CC0((_DWORD *)(a1 + 4), src, (__int32)v12);
  v13 = *(_DWORD *)(a1 + 104);
  v12[13] = 0;
  v14 = a1 + 4 * v13;
  v12[14] = *(_DWORD *)(v14 + 84);
  v15 = *(_DWORD *)(v14 + 84);
  if ( v15 )
    *(_DWORD *)(v15 + 52) = v12;
  *(_DWORD *)(v14 + 84) = v12;
  if ( !*(_BYTE *)(a1 + 153) )
  {
    v17 = *(_DWORD *)(a1 + 4);
    v19[0] = a1;
    v19[1] = (int)v12;
    sub_9A22C0((int)v20, v17, src, v19);
    sub_9A22C0((int)v20, *(_DWORD *)(a1 + 44), src, v19);
  }
  return v12;
}

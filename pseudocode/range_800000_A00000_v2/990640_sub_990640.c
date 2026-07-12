// Function: sub_990640
// Address: 0x990640
_DWORD *__userpurge sub_990640@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4)
{
  bool v4; // zf
  int v5; // edx
  int *v6; // esi
  int v7; // edi
  int v8; // eax
  int v9; // edx
  _DWORD *result; // eax
  int v11; // ecx
  int v12; // edx
  const void *src_1; // esi
  int v14; // edx
  _BYTE dst[64]; // [esp-60h] [ebp-6Ch] BYREF
  void *src; // [esp-14h] [ebp-20h]
  int v17; // [esp-10h] [ebp-1Ch]
  int v18; // [esp-8h] [ebp-14h]
  int v19; // [esp-4h] [ebp-10h]
  int v20; // [esp+0h] [ebp-Ch]
  void *v21; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v20 = a2;
  v21 = retaddr;
  v4 = *(_BYTE *)(a1 + 72) == 0;
  v19 = a1;
  if ( v4 )
  {
    v12 = *(_DWORD *)(a1 + 88);
    src = (void *)(v12 + (a3 << 6));
    qmemcpy(dst, src, sizeof(dst));
    src_1 = (const void *)((a4 << 6) + v12);
    v14 = v19;
    qmemcpy(src, src_1, 0x40u);
    qmemcpy((void *)((a4 << 6) + *(_DWORD *)(v14 + 88)), dst, 0x40u);
    return (_DWORD *)(a4 << 6);
  }
  else
  {
    v5 = *(_DWORD *)(a1 + 128);
    v6 = (int *)(v5 + 16 * a3);
    v7 = *v6;
    v18 = v6[1];
    v17 = v6[2];
    src = (void *)v6[3];
    *v6 = *(_DWORD *)(16 * a4 + v5);
    v6[1] = *(_DWORD *)(16 * a4 + v5 + 4);
    v6[2] = *(_DWORD *)(16 * a4 + v5 + 8);
    v8 = *(_DWORD *)(16 * a4 + v5 + 12);
    v9 = v19;
    v6[3] = v8;
    result = (_DWORD *)(16 * a4 + *(_DWORD *)(v9 + 128));
    v11 = v18;
    *result = v7;
    result[1] = v11;
    result[2] = v17;
    result[3] = src;
  }
  return result;
}

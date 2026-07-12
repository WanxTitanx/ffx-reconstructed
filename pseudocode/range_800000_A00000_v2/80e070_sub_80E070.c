// Function: sub_80E070
// Address: 0x80e070
int __cdecl sub_80E070(int a1, _DWORD *a2)
{
  int v2; // ebx
  __int16 *v3; // edi
  int v4; // eax
  int v5; // esi
  int result; // eax
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(__int16 **)(v2 + 168);
  n1065353216 = *(_DWORD *)(v2 + 48);
  unk_C8F52C = *(_DWORD *)(v2 + 52);
  unk_C8F530 = *(_DWORD *)(v2 + 56);
  unk_C8F534 = *(_DWORD *)(v2 + 60);
  *(_DWORD *)a1 = n1065353216;
  *(_DWORD *)(a1 + 4) = unk_C8F52C;
  *(_DWORD *)(a1 + 8) = unk_C8F530;
  *(_DWORD *)(a1 + 12) = unk_C8F534;
  *(float *)a1 = 0.0;
  sub_8061E0(
    COERCE_FLOAT(&savedregs),
    (void *)(a1 + 128),
    *(unsigned __int8 *)(v2 + 24),
    *(float *)(v2 + 60),
    a1,
    v2 + 144,
    *(char *)(a1 + 542));
  v4 = sub_801E20((_DWORD *)a1, (unsigned __int16 *)v2);
  sub_7E82C0(a1 + 192, v4, a1 + 128);
  sub_7E82C0(a1 + 192, a1 + 704, a1 + 192);
  v5 = sub_80E2C0(a1 + 256, a1, (int)a2, v2, *v3);
  sub_80E450(a1 + 256, a1, a2, (float *)v2, (int)v3);
  result = sub_A68C90(v5, a1 + 256, a1 + 128, a1 + 640);
  a2[21] = result;
  return result;
}

// Function: sub_9A38B0
// Address: 0x9a38b0
int __thiscall sub_9A38B0(int *this, float *a2, int a3, int a4, float *a5, float *a6)
{
  float v7; // [esp+0h] [ebp-24h]
  int v9; // [esp+20h] [ebp-4h] BYREF
  int savedregs; // [esp+24h] [ebp+0h] BYREF

  v7 = *(float *)(a4 + 44);
  v9 = a4;
  sub_9A2570((int)&savedregs, *(this + 1), a2, a3, (float *)(a4 + 16), (_DWORD *)(a4 + 32), v7, a5, a6, &v9);
  return sub_9A2570(
           (int)&savedregs,
           *(this + 11),
           a2,
           a3,
           (float *)(a4 + 16),
           (_DWORD *)(a4 + 32),
           *(float *)(a4 + 44),
           a5,
           a6,
           &v9);
}

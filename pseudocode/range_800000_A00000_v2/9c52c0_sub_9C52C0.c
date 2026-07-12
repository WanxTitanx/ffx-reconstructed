// Function: sub_9C52C0
// Address: 0x9c52c0
int __userpurge sub_9C52C0@<eax>(int a1@<ecx>, int a2@<ebp>, int *a3)
{
  int v4; // edi
  int v5; // edx
  _DWORD *v6; // ecx
  int v8; // [esp-60h] [ebp-6Ch]
  int v9; // [esp-54h] [ebp-60h]
  _DWORD v10[23]; // [esp-50h] [ebp-5Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v10[20] = a2;
  v10[21] = retaddr;
  sub_6035C0(v10);
  v4 = a3[1];
  v5 = *a3;
  v9 = a3[3];
  v8 = a3[2];
  v6 = *(_DWORD **)(a1 + 8);
  v6[4] = v10[0];
  v6[5] = v10[1];
  v6[6] = v10[2];
  v6[7] = v10[3];
  v6[8] = v10[4];
  v6[9] = v10[5];
  v6[10] = v10[6];
  v6[11] = v10[7];
  v6[12] = v10[8];
  v6[13] = v10[9];
  v6[14] = v10[10];
  v6[15] = v10[11];
  v6[16] = v5;
  v6[17] = v4;
  v6[18] = v8;
  v6[19] = v9;
  return v9;
}

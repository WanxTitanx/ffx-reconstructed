// Function: sub_98B5F0
// Address: 0x98b5f0
// bad sp value at call has been detected, the output may be wrong!
float *__userpurge sub_98B5F0@<eax>(int *a1@<ecx>, int a2@<ebp>, float *a3, float *a4)
{
  int v5; // eax
  float v6; // ecx
  _DWORD v8[4]; // [esp-100h] [ebp-10Ch] BYREF
  _DWORD v9[4]; // [esp-F0h] [ebp-FCh] BYREF
  float v10[16]; // [esp-E0h] [ebp-ECh] BYREF
  float v11[39]; // [esp-A0h] [ebp-ACh] BYREF
  int v12; // [esp-4h] [ebp-10h]
  int v13; // [esp+0h] [ebp-Ch]
  void *v14; // [esp+4h] [ebp-8h]
  int v15; // [esp+8h] [ebp-4h] BYREF
  void *retaddr; // [esp+Ch] [ebp+0h]

  v13 = a2;
  v14 = retaddr;
  v12 = -1;
  LODWORD(v11[38]) = &loc_AD8EFB;
  v11[37] = *(float *)&NtCurrentTeb()->NtTib.ExceptionList;
  LODWORD(v11[36]) = &v15;
  sub_6035C0(v10);
  sub_98AD30(v11, a4, v10);
  v5 = *a1;
  v12 = 0;
  v8[0] = 1566444395;
  v8[1] = 1566444395;
  v8[2] = 1566444395;
  v8[3] = 0;
  v9[0] = -581039253;
  v9[1] = -581039253;
  v9[2] = -581039253;
  v9[3] = 0;
  (*(void (__thiscall **)(int *, float *, _DWORD *, _DWORD *))(v5 + 56))(a1, v11, v9, v8);
  v6 = v11[5];
  *a3 = v11[4];
  a3[1] = v6;
  a3[2] = v11[6];
  a3[3] = v11[7];
  v12 = -1;
  sub_98ACB0(v11);
  return a3;
}

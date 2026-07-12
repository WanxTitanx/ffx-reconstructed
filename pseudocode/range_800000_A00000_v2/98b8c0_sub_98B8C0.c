// Function: sub_98B8C0
// Address: 0x98b8c0
float *__usercall sub_98B8C0@<eax>(float *this@<ecx>, int a2@<ebp>)
{
  int n3; // edi
  float v4; // eax
  int (__thiscall *v5)(float *, int *, _BYTE *); // eax
  _DWORD *v6; // eax
  double v7; // st7
  float *result; // eax
  int v9; // [esp-40h] [ebp-4Ch] BYREF
  _DWORD v10[4]; // [esp-30h] [ebp-3Ch] BYREF
  _BYTE v11[28]; // [esp-20h] [ebp-2Ch] BYREF
  float *v12; // [esp-4h] [ebp-10h]
  int v13; // [esp+0h] [ebp-Ch]
  void *v14; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v13 = a2;
  v14 = retaddr;
  v12 = this + 4;
  n3 = 0;
  do
  {
    v4 = *this;
    memset(v11, 0, 16);
    *(_DWORD *)&v11[n3 * 4] = 1065353216;
    (*(void (__thiscall **)(float *, _DWORD *, _BYTE *))(LODWORD(v4) + 60))(this, v10, v11);
    v12[4] = *(float *)&v10[n3] + *(this + 3);
    v5 = *(int (__thiscall **)(float *, int *, _BYTE *))(*(_DWORD *)this + 60);
    *(_DWORD *)&v11[n3 * 4] = -1082130432;
    v6 = (_DWORD *)v5(this, &v9, v11);
    v10[0] = *v6;
    v10[1] = v6[1];
    v10[2] = v6[2];
    v10[3] = v6[3];
    v7 = *(float *)&v10[n3++] - *(this + 3);
    result = v12 + 1;
    *v12 = v7;
    v12 = result;
  }
  while ( n3 < 3 );
  return result;
}

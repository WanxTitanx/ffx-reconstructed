// Function: sub_985990
// Address: 0x985990
double __userpurge sub_985990@<st0>(int a1@<ecx>, int a2@<ebp>, _DWORD *a3, _DWORD *a4, float a5, int a6, int a7)
{
  double result; // st7
  float *v8; // esi
  _DWORD v9[18]; // [esp-50h] [ebp-5Ch] BYREF
  _DWORD v10[5]; // [esp-8h] [ebp-14h] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v10[2] = a2;
  v10[3] = retaddr;
  result = a5;
  v10[0] = a6;
  v8 = *(float **)(a1 + 224);
  v10[1] = a7;
  if ( v8[1] >= (double)a5 )
  {
    v9[0] = *(_DWORD *)(a1 + 228);
    v9[1] = v10;
    v9[4] = *a3;
    v9[5] = a3[1];
    v9[6] = a3[2];
    v9[7] = a3[3];
    v9[8] = *a4;
    v9[9] = a4[1];
    v9[10] = a4[2];
    v9[11] = a4[3];
    *(float *)&v9[12] = a5;
    (*(void (__thiscall **)(float *, _DWORD *, _DWORD))(*(_DWORD *)v8 + 8))(v8, v9, 0);
  }
  return result;
}

// Function: sub_8EAD90
// Address: 0x8ead90
_DWORD *__cdecl sub_8EAD90(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  float *v5; // eax
  int v6; // ebx
  _DWORD *result; // eax
  int v8; // [esp-Ch] [ebp-1Ch]
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v5 = FFX_Btl_LookupCommandDataById(a2, &v9);
  v6 = v9 + *(unsigned __int16 *)v5;
  v8 = *((unsigned __int8 *)v5 + 20);
  dword_187168C = a1;
  dword_187168C = (_DWORD *)sub_8EB240(a1, a3 + 3, a4 + 1, v8);
  result = (_DWORD *)sub_8ED0A0(dword_187168C, v6, a3 + 22, a4, a5);
  dword_187168C = result;
  return result;
}

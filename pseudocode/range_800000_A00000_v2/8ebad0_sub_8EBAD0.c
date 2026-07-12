// Function: sub_8EBAD0
// Address: 0x8ebad0
_DWORD *__cdecl sub_8EBAD0(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v5; // ebx
  _DWORD *v6; // edx
  char v7; // cl
  _DWORD *result; // eax
  _BYTE v9[4]; // [esp+Ch] [ebp-8h] BYREF
  _BYTE *v10; // [esp+10h] [ebp-4h]

  v10 = (_BYTE *)sub_7ABBF0(a2, v9);
  v5 = sub_7ABE10(a2);
  dword_187168C = a1;
  dword_187168C = (_DWORD *)sub_8EB240(a1, a3 + 3, a4 + 1, (unsigned __int8)(v10[5] + 2 * v10[4] + 1));
  v6 = (_DWORD *)sub_8ED0A0(dword_187168C, v5, a3 + 22, a4, a5);
  v7 = v10[4];
  dword_187168C = v6;
  if ( v7 != v10[6] )
    return v6;
  result = (_DWORD *)sub_8EB240(v6, a3 + 3, a4 + 1, 49);
  dword_187168C = result;
  return result;
}

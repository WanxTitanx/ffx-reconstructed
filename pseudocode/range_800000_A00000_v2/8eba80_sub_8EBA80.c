// Function: sub_8EBA80
// Address: 0x8eba80
_DWORD *__cdecl sub_8EBA80(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v5; // ebx
  _DWORD *result; // eax

  v5 = sub_8AC800(a2);
  dword_187168C = a1;
  dword_187168C = (_DWORD *)sub_8EB240(a1, a3 + 3, a4 + 1, 19);
  result = (_DWORD *)sub_8EA000(dword_187168C, v5, a3 + 22, a4, a5);
  dword_187168C = result;
  return result;
}

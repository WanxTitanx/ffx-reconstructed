// Function: sub_987660
// Address: 0x987660
int __cdecl sub_987660(int a1, int a2)
{
  int v2; // esi
  int result; // eax
  _DWORD *i; // edi

  v2 = a1;
  result = sub_987C00(a1);
  for ( i = (_DWORD *)(a1 + 40); *(_DWORD *)(v2 + 40); i = (_DWORD *)(v2 + 40) )
  {
    sub_987660(*(_DWORD *)(v2 + 36), a2);
    v2 = *i;
    result = sub_987C00(*i);
  }
  return result;
}

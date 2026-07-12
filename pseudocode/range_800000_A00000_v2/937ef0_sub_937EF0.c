// Function: sub_937EF0
// Address: 0x937ef0
int __cdecl sub_937EF0(_DWORD *a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int result; // eax
  int v10; // eax

  if ( *a1 )
    return sub_84B250(*a1);
  v10 = sub_84A920(a2, a3, a4, a5, a6, a7);
  *a1 = v10;
  sub_84B6A0(v10);
  result = a9;
  if ( a9 )
    return sub_84B660(*a1, a9);
  return result;
}

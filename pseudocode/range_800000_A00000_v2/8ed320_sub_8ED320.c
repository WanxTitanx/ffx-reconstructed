// Function: sub_8ED320
// Address: 0x8ed320
int __cdecl sub_8ED320(int a1, _BYTE *a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int result; // eax
  _BYTE *v10; // esi
  int v11; // edi

  result = unknown_libname_654(a1);
  v10 = a2;
  v11 = result;
  if ( *a2 )
  {
    do
    {
      v11 = sub_8EE9C0(v11, v10, a3, a4, a5, a6, a7, a8, a9);
      a3 += 12;
      v10 = (_BYTE *)sub_8DFD70(v10);
    }
    while ( *v10 );
    return v11;
  }
  return result;
}

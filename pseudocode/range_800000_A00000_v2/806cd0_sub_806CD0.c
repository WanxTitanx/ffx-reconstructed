// Function: sub_806CD0
// Address: 0x806cd0
_DWORD *__cdecl sub_806CD0(_DWORD *a1)
{
  _DWORD *v1; // ecx
  int *v2; // eax

  v1 = a1;
  v2 = (int *)*a1;
  if ( !*(_BYTE *)(*a1 + 13) )
  {
    do
    {
      v1 = v2;
      v2 = (int *)*v2;
    }
    while ( !*((_BYTE *)v2 + 13) );
  }
  return v1;
}

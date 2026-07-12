// Function: sub_A334D0
// Address: 0xa334d0
// Size: 0x61
// Prototype: 

_DWORD *__cdecl sub_A334D0(int a1, _DWORD *a2, int a3)
{
  _DWORD *result; // eax
  int v4; // edx
  _DWORD *v6; // ecx
  int v7; // edi
  _DWORD *v8; // edx

  if ( !a1 )
    return 0;
  result = (_DWORD *)sub_42FC60(4 * a1, 4);
  if ( result )
  {
    v4 = a3;
    v6 = result;
    if ( a3 )
    {
      v7 = a3;
      do
      {
        v8 = v6++;
        if ( v8 )
          *v8 = *a2++;
        --v7;
      }
      while ( v7 );
      v4 = a3;
    }
    if ( a1 != v4 )
      memset(&result[v4], 0, 4 * (a1 - v4));
  }
  return result;
}


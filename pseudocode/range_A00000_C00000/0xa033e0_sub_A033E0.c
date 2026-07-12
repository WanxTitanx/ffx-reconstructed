// Function: sub_A033E0
// Address: 0xa033e0
// Size: 0x4f
// Prototype: 

_DWORD *__cdecl sub_A033E0(int a1, _DWORD *a2)
{
  int v2; // esi
  _DWORD *result; // eax
  _DWORD *v5; // ecx
  _DWORD *v6; // edx

  v2 = a1;
  if ( !a1 )
    return 0;
  result = (_DWORD *)sub_42FC60(4 * a1, 4);
  if ( result )
  {
    v5 = result;
    do
    {
      v6 = v5++;
      if ( v6 )
        *v6 = *a2++;
      --v2;
    }
    while ( v2 );
  }
  return result;
}


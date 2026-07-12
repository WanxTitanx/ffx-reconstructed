// Function: sub_A419B0
// Address: 0xa419b0
// Size: 0x1e

_DWORD *__cdecl sub_A419B0(_DWORD *a1)
{
  _DWORD *v1; // ecx
  int *v2; // eax

  v1 = a1; /*0xa419b3*/
  v2 = (int *)*a1; /*0xa419b6*/
  if ( !*(_BYTE *)(*a1 + 13) ) /*0xa419b8*/
  {
    do /*0xa419c8*/
    {
      v1 = v2; /*0xa419c0*/
      v2 = (int *)*v2; /*0xa419c2*/
    }
    while ( !*((_BYTE *)v2 + 13) ); /*0xa419c8*/
  }
  return v1; /*0xa419cc*/
}
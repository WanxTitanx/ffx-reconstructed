// Function: sub_A03470
// Address: 0xa03470
// Size: 0x61

_DWORD *__cdecl sub_A03470(int a1, _DWORD *a2, int a3)
{
  _DWORD *result; // eax
  int v4; // edx
  _DWORD *v6; // ecx
  int v7; // edi
  _DWORD *v8; // edx

  if ( !a1 ) /*0xa03478*/
    return 0; /*0xa034cd*/
  result = (_DWORD *)sub_42FC60(4 * a1, 4); /*0xa03481*/
  if ( result ) /*0xa0348d*/
  {
    v4 = a3; /*0xa0348f*/
    v6 = result; /*0xa03497*/
    if ( a3 ) /*0xa0349b*/
    {
      v7 = a3; /*0xa0349d*/
      do /*0xa034b1*/
      {
        v8 = v6++; /*0xa034a0*/
        if ( v8 ) /*0xa034a7*/
          *v8 = *a2++; /*0xa034ab*/
        --v7; /*0xa034b0*/
      }
      while ( v7 ); /*0xa034b1*/
      v4 = a3; /*0xa034b3*/
    }
    if ( a1 != v4 ) /*0xa034bb*/
      memset(&result[v4], 0, 4 * (a1 - v4)); /*0xa034c4*/
  }
  return result; /*0xa034cb*/
}
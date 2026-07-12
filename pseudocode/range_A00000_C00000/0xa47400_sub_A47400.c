// Function: sub_A47400
// Address: 0xa47400
// Size: 0x33
// Prototype: _DWORD __cdecl(char n252)

_BYTE *__cdecl sub_A47400(char n252)
{
  _BYTE *result; // eax
  int v2; // ecx

  result = (_BYTE *)unk_2305834; /*0xa47403*/
  v2 = *(__int16 *)(unk_2305834 + 2); /*0xa47408*/
  if ( *(_WORD *)(unk_2305834 + 2) ) /*0xa47408*/
  {
    result = (_BYTE *)(unk_2305834 + 2090); /*0xa47414*/
    do /*0xa4742e*/
    {
      --v2; /*0xa47420*/
      if ( *((_WORD *)result - 14) != 0xFFFF ) /*0xa47425*/
        *result &= n252; /*0xa47427*/
      result += 40; /*0xa47429*/
    }
    while ( v2 ); /*0xa4742e*/
  }
  return result; /*0xa47431*/
}
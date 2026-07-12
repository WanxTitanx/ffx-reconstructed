// Function: sub_A473D0
// Address: 0xa473d0
// Size: 0x22
// Prototype: _DWORD __cdecl(char n240)

_BYTE *__cdecl sub_A473D0(char n240)
{
  _BYTE *result; // eax
  int v2; // ecx

  result = (_BYTE *)unk_2305834; /*0xa473d3*/
  v2 = *(__int16 *)(unk_2305834 + 4); /*0xa473d8*/
  if ( *(_WORD *)(unk_2305834 + 4) ) /*0xa473d8*/
  {
    result = (_BYTE *)(unk_2305834 + 43030); /*0xa473e3*/
    do /*0xa473ee*/
    {
      *result &= n240; /*0xa473e8*/
      result += 20; /*0xa473ea*/
      --v2; /*0xa473ed*/
    }
    while ( v2 ); /*0xa473ee*/
  }
  return result; /*0xa473f0*/
}
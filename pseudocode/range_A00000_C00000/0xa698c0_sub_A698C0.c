// Function: sub_A698C0
// Address: 0xa698c0
// Size: 0x76

int __cdecl sub_A698C0(int a1)
{
  char v1; // cl
  int v2; // edx
  int n240; // eax

  v1 = *(_BYTE *)(a1 + 33); /*0xa698c7*/
  v2 = a1 + 32; /*0xa698ca*/
  n240 = v1 & 0xF0; /*0xa698d0*/
  if ( n240 != 16 ) /*0xa698d8*/
  {
    while ( n240 != 32 ) /*0xa698e3*/
    {
      if ( n240 == 240 ) /*0xa698ea*/
        return (v2 + 6 * (*(__int16 *)(a1 + 18) + *(__int16 *)(a1 + 20)) - a1 + 31) & 0x7FFFFFF0; /*0xa6992e*/
      v2 += dword_C88AA8[v1 & 7] * *(__int16 *)(v2 + 2) + 16; /*0xa69901*/
      v1 = *(_BYTE *)(v2 + 1); /*0xa69903*/
      n240 = v1 & 0xF0; /*0xa69909*/
      if ( n240 == 16 ) /*0xa69911*/
        return 0; /*0xa69911*/
    }
  }
  return 0; /*0xa69915*/
}
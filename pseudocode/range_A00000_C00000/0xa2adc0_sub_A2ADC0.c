// Function: sub_A2ADC0
// Address: 0xa2adc0
// Size: 0x30

char *__usercall sub_A2ADC0@<eax>(char *dst_1@<eax>, char *dst_2, char *src, int a4)
{
  int v4; // edx
  char *dst; // edi

  v4 = a4; /*0xa2adc3*/
  if ( a4 ) /*0xa2adc8*/
  {
    dst_1 = dst_2; /*0xa2adca*/
    do /*0xa2ade9*/
    {
      dst = dst_1; /*0xa2add3*/
      dst_1 += 48; /*0xa2add5*/
      if ( dst ) /*0xa2adda*/
      {
        qmemcpy(dst, src, 0x30u); /*0xa2ade3*/
        src += 48; /*0xa2ade5*/
      }
      --v4; /*0xa2ade8*/
    }
    while ( v4 ); /*0xa2ade9*/
  }
  return dst_1; /*0xa2adee*/
}
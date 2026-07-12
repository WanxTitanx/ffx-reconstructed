// Function: sub_A70CE0
// Address: 0xa70ce0
// Size: 0x5d

int __cdecl sub_A70CE0(__int64 a1)
{
  int result; // eax

  result = 1; /*0xa70cec*/
  if ( SLODWORD(qword_22FB400[0]) < 1 ) /*0xa70cf7*/
  {
LABEL_4:
    ++qword_22FB400[0]; /*0xa70d17*/
    LODWORD(qword_22FB400[LODWORD(qword_22FB400[0])]) = a1; /*0xa70d27*/
    result = qword_22FB400[0]; /*0xa70d2e*/
    HIDWORD(qword_22FB400[LODWORD(qword_22FB400[0])]) = HIDWORD(a1); /*0xa70d33*/
  }
  else
  {
    while ( __PAIR64__(HIDWORD(qword_22FB400[result]), qword_22FB400[result]) != a1 ) /*0xa70d07*/
    {
      if ( ++result > SLODWORD(qword_22FB400[0]) ) /*0xa70d15*/
        goto LABEL_4; /*0xa70d15*/
    }
  }
  return result; /*0xa70d3a*/
}
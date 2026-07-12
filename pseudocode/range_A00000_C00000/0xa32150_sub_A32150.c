// Function: sub_A32150
// Address: 0xa32150
// Size: 0x2f

char __stdcall sub_A32150(int *a1)
{
  int v1; // ecx

  v1 = Phyre_PObject_ComputeLayout(dword_1A85990); /*0xa3215d*/
  if ( !v1 ) /*0xa32161*/
    return 0; /*0xa32163*/
  if ( a1 ) /*0xa3216e*/
  {
    *a1 = v1; /*0xa32170*/
    a1[1] = 0; /*0xa32172*/
  }
  return 1; /*0xa32165*/
}
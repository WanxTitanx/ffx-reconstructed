// Function: sub_A1A6C0
// Address: 0xa1a6c0
// Size: 0x55

int __userpurge sub_A1A6C0@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3, int a4)
{
  int result; // eax

  result = sub_A185A0(a1, a2, a4, a3, a4); /*0xa1a6ce*/
  if ( !result ) /*0xa1a6d5*/
  {
    a1[1005] = sub_56CD50("FocusPlaneDistance"); /*0xa1a6ea*/
    a1[1006] = sub_56CD50("FocusRange"); /*0xa1a6fc*/
    a1[1007] = sub_56CD50("FocusBlurRange"); /*0xa1a707*/
    return 0; /*0xa1a70d*/
  }
  return result; /*0xa1a70f*/
}
// Function: sub_A34430
// Address: 0xa34430
// Size: 0x19

int __thiscall sub_A34430(int (__thiscall **this)(int), int a2)
{
  int (__thiscall *v2)(int); // eax

  v2 = *(this + 13); /*0xa34433*/
  if ( v2 ) /*0xa34438*/
    return v2(a2); /*0xa3443d*/
  else
    return 0; /*0xa34443*/
}
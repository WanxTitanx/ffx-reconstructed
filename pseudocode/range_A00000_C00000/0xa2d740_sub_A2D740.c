// Function: sub_A2D740
// Address: 0xa2d740
// Size: 0x19

int __thiscall sub_A2D740(int (__thiscall **this)(int), int a2)
{
  int (__thiscall *v2)(int); // eax

  v2 = *(this + 13); /*0xa2d743*/
  if ( v2 ) /*0xa2d748*/
    return v2(a2); /*0xa2d74d*/
  else
    return 0; /*0xa2d753*/
}
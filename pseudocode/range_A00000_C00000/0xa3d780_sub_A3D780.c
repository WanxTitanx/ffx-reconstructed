// Function: sub_A3D780
// Address: 0xa3d780
// Size: 0x1a

int __thiscall sub_A3D780(_DWORD *this, int a2)
{
  int result; // eax

  result = *this; /*0xa3d783*/
  if ( *this ) /*0xa3d783*/
  {
    result = IggyPlayerDestroy(*this); /*0xa3d78a*/
    *this = 0; /*0xa3d790*/
  }
  return result; /*0xa3d796*/
}
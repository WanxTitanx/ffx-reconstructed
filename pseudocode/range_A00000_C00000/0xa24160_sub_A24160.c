// Function: sub_A24160
// Address: 0xa24160
// Size: 0x69

char __stdcall sub_A24160(int a1, char a2)
{
  if ( a2 ) /*0xa2416a*/
  {
    if ( a1 ) /*0xa2416e*/
      Phyre_PObject_TraverseBindMembers(Size_7, a1 + 4, 1); /*0xa2417b*/
    else
      Phyre_PObject_TraverseBindMembers(Size_7, 0, 1); /*0xa24190*/
    return 1; /*0xa24180*/
  }
  else
  {
    if ( a1 ) /*0xa2419d*/
      Phyre_PObject_TraverseBindMembers(Size_7, a1 + 4, 0); /*0xa241aa*/
    else
      Phyre_PObject_TraverseBindMembers(Size_7, 0, 0); /*0xa241be*/
    return 1; /*0xa241af*/
  }
}
// Function: sub_A78E20
// Address: 0xa78e20
// Size: 0x21
// Prototype: 

double __cdecl sub_A78E20(int a1)
{
  int ChrPointer; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
    return sub_82ADE0(ChrPointer);
  else
    return 0.0;
}


// Function: sub_A79E60
// Address: 0xa79e60
// Size: 0x1f
// Prototype: 

int __cdecl sub_A79E60(int a1)
{
  int ChrPointer; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
    sub_837200(ChrPointer);
  return 0;
}


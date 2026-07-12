// Function: sub_A7A680
// Address: 0xa7a680
// Size: 0x1f
// Prototype: 

int __cdecl sub_A7A680(int a1)
{
  int ChrPointer; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
    sub_835790(ChrPointer);
  return 0;
}


// Function: sub_A78940
// Address: 0xa78940
// Size: 0x1f
// Prototype: 

int __cdecl sub_A78940(int a1)
{
  int ChrPointer; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
    sub_82B100(ChrPointer);
  return 0;
}


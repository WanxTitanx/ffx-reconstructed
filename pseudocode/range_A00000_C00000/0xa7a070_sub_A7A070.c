// Function: sub_A7A070
// Address: 0xa7a070
// Size: 0x1f
// Prototype: 

int __cdecl sub_A7A070(int a1)
{
  int ChrPointer; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
    sub_835100(ChrPointer);
  return 0;
}


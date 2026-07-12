// Function: sub_A788A0
// Address: 0xa788a0
// Size: 0x25
// Prototype: 

int __cdecl sub_A788A0(int a1)
{
  int ChrPointer; // ecx
  int result; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  result = 0;
  if ( ChrPointer )
    return *(_BYTE *)(ChrPointer + 1846) != 0 ? 0 : 5;
  return result;
}


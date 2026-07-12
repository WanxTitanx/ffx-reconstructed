// Function: sub_A788D0
// Address: 0xa788d0
// Size: 0x21
// Prototype: 

bool __cdecl sub_A788D0(int a1)
{
  int ChrPointer; // ecx
  bool result; // al

  ChrPointer = FFX_TK_GetChrPointer(a1);
  result = 0;
  if ( ChrPointer )
    return *(_BYTE *)(ChrPointer + 1846) != 0;
  return result;
}


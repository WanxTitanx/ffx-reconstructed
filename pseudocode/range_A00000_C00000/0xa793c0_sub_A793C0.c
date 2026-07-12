// Function: sub_A793C0
// Address: 0xa793c0
// Size: 0x4b
// Prototype: 

int __cdecl sub_A793C0(int a1)
{
  int ChrPointer; // edx
  int v2; // ecx

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( !ChrPointer )
    return 0;
  v2 = unk_22FB4D8;
  if ( unk_12FB7C4 == 1 )
    v2 = ++unk_22FB4D8;
  if ( *(_BYTE *)(ChrPointer + 1846) )
    return 0;
  unk_22FB4D8 = unk_12FB7C4 != 1 ? v2 : 0;
  return 5;
}


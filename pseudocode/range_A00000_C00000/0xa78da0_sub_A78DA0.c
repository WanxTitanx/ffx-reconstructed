// Function: sub_A78DA0
// Address: 0xa78da0
// Size: 0x2f
// Prototype: 

int __cdecl sub_A78DA0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_82A9D0(ChrPointer, v4);
  return 0;
}


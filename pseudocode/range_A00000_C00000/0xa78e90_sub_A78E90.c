// Function: sub_A78E90
// Address: 0xa78e90
// Size: 0x2f
// Prototype: 

int __cdecl sub_A78E90(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  __int16 v4; // ax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_8399E0(ChrPointer, v4);
  return 0;
}


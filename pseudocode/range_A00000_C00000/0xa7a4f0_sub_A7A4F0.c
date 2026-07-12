// Function: sub_A7A4F0
// Address: 0xa7a4f0
// Size: 0x2f
// Prototype: 

int __cdecl sub_A7A4F0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
  {
    v4 = FFX_FieldVM_PopOperand(a1, a3);
    sub_82A9B0(ChrPointer, v4);
  }
  return 0;
}


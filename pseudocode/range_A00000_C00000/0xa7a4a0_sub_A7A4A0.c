// Function: sub_A7A4A0
// Address: 0xa7a4a0
// Size: 0x2f
// Prototype: 

int __cdecl sub_A7A4A0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  if ( ChrPointer )
  {
    v4 = FFX_FieldVM_PopOperand(a1, a3);
    sub_82B1B0(ChrPointer, v4);
  }
  return 0;
}


// Function: sub_A79510
// Address: 0xa79510
// Size: 0x2f
// Prototype: 

int __cdecl sub_A79510(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  __int16 v4; // ax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_82B400(ChrPointer, v4);
  return 0;
}


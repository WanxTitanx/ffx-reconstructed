// Function: sub_A79AF0
// Address: 0xa79af0
// Size: 0x32
// Prototype: 

int __cdecl sub_A79AF0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    return sub_82AAB0(ChrPointer, v4);
  else
    return 0;
}


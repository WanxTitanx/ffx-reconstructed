// Function: sub_A79F70
// Address: 0xa79f70
// Size: 0x2f
// Prototype: 

int __cdecl sub_A79F70(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  int v4; // eax

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    sub_834FE0(ChrPointer, v4);
  return 0;
}


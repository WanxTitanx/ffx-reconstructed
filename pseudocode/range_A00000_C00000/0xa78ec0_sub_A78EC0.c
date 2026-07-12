// Function: sub_A78EC0
// Address: 0xa78ec0
// Size: 0x39
// Prototype: 

int __cdecl sub_A78EC0(int a1, int a2, int *a3)
{
  int ChrPointer; // edi
  char v4; // al
  char v5; // si

  ChrPointer = FFX_TK_GetChrPointer(a1);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v5 = v4;
  if ( ChrPointer )
  {
    sub_82B260(ChrPointer, v4);
    sub_82B420(ChrPointer, v5);
  }
  return 0;
}


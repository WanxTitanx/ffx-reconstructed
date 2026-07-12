// Function: sub_A78D30
// Address: 0xa78d30
// Size: 0x32
// Prototype: 

int __cdecl sub_A78D30(int a1, int a2, int *a3)
{
  int ChrPointer; // esi

  ChrPointer = FFX_TK_GetChrPointer(a1);
  FFX_FieldVM_PopOperand(a1, a3);
  if ( ChrPointer )
    nullsub_34();
  return 0;
}


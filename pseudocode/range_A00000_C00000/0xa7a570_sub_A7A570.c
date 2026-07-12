// Function: sub_A7A570
// Address: 0xa7a570
// Size: 0x2b
// Prototype: 

int __cdecl sub_A7A570(int a1, int a2, int *a3)
{
  int v3; // edi
  int v4; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  sub_824F90(v4, v3);
  return 0;
}


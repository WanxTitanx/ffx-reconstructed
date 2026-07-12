// Function: sub_A79030
// Address: 0xa79030
// Size: 0x3b
// Prototype: 

int __cdecl sub_A79030(int a1, int *a2, int *a3)
{
  int result; // eax

  a2[3] = 0;
  a2[2] = FFX_FieldVM_PopOperand(a1, a3);
  a2[1] = FFX_FieldVM_PopOperand(a1, a3);
  result = FFX_FieldVM_PopOperand(a1, a3);
  *a2 = result;
  return result;
}


// Function: sub_A79480
// Address: 0xa79480
// Size: 0x21
// Prototype: 

int __cdecl sub_A79480(int a1, int *a2, int *a3)
{
  int result; // eax

  a2[3] = 0;
  result = FFX_FieldVM_PopOperand(a1, a3);
  *a2 = result;
  return result;
}


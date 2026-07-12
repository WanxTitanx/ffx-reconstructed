// Function: sub_A799B0
// Address: 0xa799b0
// Size: 0x18
// Prototype: 

int __cdecl sub_A799B0(int a1, int *a2, int *a3)
{
  int result; // eax

  result = FFX_FieldVM_PopOperand(a1, a3);
  *a2 = result;
  return result;
}


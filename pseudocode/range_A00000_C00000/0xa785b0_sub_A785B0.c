// Function: sub_A785B0
// Address: 0xa785b0
// Size: 0x2b
// Prototype: 

int __cdecl sub_A785B0(int a1, int a2, int *a3)
{
  char v3; // di
  int v4; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  sub_831CE0(v4, v3);
  return 0;
}


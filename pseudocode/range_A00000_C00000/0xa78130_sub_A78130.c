// Function: sub_A78130
// Address: 0xa78130
// Size: 0x2b
// Prototype: 

int __cdecl sub_A78130(int a1, int a2, int *a3)
{
  int v3; // edi
  int v4; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  sub_83E9E0(v4, v3);
  return 0;
}


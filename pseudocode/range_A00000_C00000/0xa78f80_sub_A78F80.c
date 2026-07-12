// Function: sub_A78F80
// Address: 0xa78f80
// Size: 0x2b
// Prototype: 

int __cdecl sub_A78F80(int a1, int a2, int *a3)
{
  int v3; // edi
  int v4; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  sub_836AC0(v4, v3);
  return 0;
}


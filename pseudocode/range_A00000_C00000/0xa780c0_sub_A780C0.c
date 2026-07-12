// Function: sub_A780C0
// Address: 0xa780c0
// Size: 0x2b
// Prototype: 

int __cdecl sub_A780C0(int a1, int a2, int *a3)
{
  int v3; // edi
  int v4; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  sub_82CEA0(v4, v3);
  return 0;
}


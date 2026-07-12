// Function: sub_A77AC0
// Address: 0xa77ac0
// Size: 0x49
// Prototype: 

double __cdecl sub_A77AC0(int a1, int a2, int *a3)
{
  char v3; // di
  char v4; // si
  char v5; // al
  char v7; // [esp+Ch] [ebp-4h]

  v7 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v5 = FFX_FieldVM_PopOperand(a1, a3);
  sub_82BE40(v5, v4, v3, v7);
  return 0.0;
}


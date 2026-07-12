// Function: sub_A77E80
// Address: 0xa77e80
// Size: 0x49
// Prototype: 

int __cdecl sub_A77E80(int a1, int a2, int *a3)
{
  char v3; // di
  char v4; // si
  char v5; // al
  int v7; // [esp+Ch] [ebp-4h]

  v7 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v5 = FFX_FieldVM_PopOperand(a1, a3);
  FFX_BtlActor_FSM_ApplyFadeEffect(v5, v4, v3, v7);
  return 0;
}


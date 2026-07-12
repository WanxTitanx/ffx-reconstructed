// Function: sub_A78320
// Address: 0xa78320
// Size: 0x19
// Prototype: 

int __cdecl sub_A78320(int a1, int a2, int *a3)
{
  char v3; // al

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  return FFX_BtlTick_FreeTempBattleAllocations(v3);
}


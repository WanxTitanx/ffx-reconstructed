// Function: sub_A77BE0
// Address: 0xa77be0
// Size: 0x35
// Prototype: 

int __cdecl sub_A77BE0(int a1, int a2, int *a3)
{
  int v3; // eax
  float v5; // [esp+4h] [ebp-4h]

  v5 = FFX_TK_PopStackFloat(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  sub_82DA10(*(float *)&v3, v5);
  return 0;
}


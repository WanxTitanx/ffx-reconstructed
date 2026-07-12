// Function: sub_A778A0
// Address: 0xa778a0
// Size: 0x35
// Prototype: 

int __cdecl sub_A778A0(int a1, int a2, int *a3)
{
  int v3; // eax
  float v5; // [esp+4h] [ebp-4h]

  v5 = FFX_TK_PopStackFloat(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  sub_831D60(v3, v5);
  return 0;
}


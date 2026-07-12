// Function: sub_A77A70
// Address: 0xa77a70
// Size: 0x39
// Prototype: 

int __cdecl sub_A77A70(int a1, int a2, int *a3)
{
  int v3; // ebx
  int v4; // esi
  int v5; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v5 = FFX_FieldVM_PopOperand(a1, a3);
  sub_824E60(v5, v4, v3);
  return 0;
}


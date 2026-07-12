// Function: sub_860100
// Address: 0x860100
int __cdecl sub_860100(int a1, int a2, int *a3)
{
  int n127; // ebx
  int v4; // eax

  n127 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  FFX_BtlEffect_SetVolume(v4, n127);
  return n127;
}

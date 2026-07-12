// Function: sub_A77980
// Address: 0xa77980
// Size: 0x35
// Prototype: 

int __cdecl sub_A77980(int a1, int a2, int *a3)
{
  int v3; // eax
  float v5; // [esp+4h] [ebp-4h]

  v5 = FFX_TK_PopStackFloat(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  sub_831C70(v3, v5);
  return 0;
}


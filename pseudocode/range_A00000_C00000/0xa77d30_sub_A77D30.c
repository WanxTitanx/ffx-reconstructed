// Function: sub_A77D30
// Address: 0xa77d30
// Size: 0x49

int __cdecl sub_A77D30(int a1, int a2, int *a3)
{
  char v3; // di
  char v4; // si
  int v5; // eax
  char v7; // [esp+Ch] [ebp-4h]

  v7 = FFX_FieldVM_PopOperand(a1, a3); /*0xa77d46*/
  v3 = FFX_FieldVM_PopOperand(a1, a3); /*0xa77d50*/
  v4 = FFX_FieldVM_PopOperand(a1, a3); /*0xa77d5a*/
  v5 = FFX_FieldVM_PopOperand(a1, a3); /*0xa77d5d*/
  sub_82CD20(v5, v4, v3, v7); /*0xa77d68*/
  return 0; /*0xa77d72*/
}
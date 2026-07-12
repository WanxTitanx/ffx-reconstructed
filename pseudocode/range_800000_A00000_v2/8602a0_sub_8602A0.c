// Function: sub_8602A0
// Address: 0x8602a0
int __cdecl sub_8602A0(int a1, int a2, int *a3)
{
  int v3; // esi
  int v4; // eax
  int v6; // [esp+Ch] [ebp-4h]

  v6 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  FFX_BtlEffect_EnableTimed(v4, v3, v6);
  return v6;
}

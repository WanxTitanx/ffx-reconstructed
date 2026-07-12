// Function: sub_A78510
// Address: 0xa78510
// Size: 0x49
// Prototype: 

int __cdecl sub_A78510(int a1, int a2, int *a3)
{
  int v3; // edi
  int v4; // esi
  int v5; // eax
  int v7; // [esp+Ch] [ebp-4h]

  v7 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v5 = FFX_FieldVM_PopOperand(a1, a3);
  sub_831C90(v5, v4, v3, v7);
  return 0;
}


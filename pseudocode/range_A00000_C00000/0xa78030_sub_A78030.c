// Function: sub_A78030
// Address: 0xa78030
// Size: 0x66
// Prototype: 

int __cdecl sub_A78030(int a1, int a2, int *a3)
{
  int v3; // ebx
  int v4; // edi
  int v5; // esi
  int v6; // eax
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h]

  v9 = FFX_FieldVM_PopOperand(a1, a3);
  v8 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v5 = FFX_FieldVM_PopOperand(a1, a3);
  v6 = FFX_FieldVM_PopOperand(a1, a3);
  sub_8365A0(v6, v5, v4, v3, v8, v9);
  return 0;
}


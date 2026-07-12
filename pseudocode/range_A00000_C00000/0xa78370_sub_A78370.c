// Function: sub_A78370
// Address: 0xa78370
// Size: 0xdc
// Prototype: 

int __cdecl sub_A78370(int a1, int a2, int *a3)
{
  int v3; // ebx
  int v5; // [esp-4h] [ebp-5Ch]
  int v6; // [esp+3Ch] [ebp-1Ch]
  float v7; // [esp+40h] [ebp-18h]
  float v8; // [esp+44h] [ebp-14h]
  float v9; // [esp+48h] [ebp-10h]
  float v10; // [esp+4Ch] [ebp-Ch]
  int v11; // [esp+50h] [ebp-8h]
  int v12; // [esp+54h] [ebp-4h]

  v12 = FFX_FieldVM_PopOperand(a1, a3);
  v11 = FFX_FieldVM_PopOperand(a1, a3);
  v6 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v10 = FFX_TK_PopStackFloat(a1, a3);
  v9 = FFX_TK_PopStackFloat(a1, a3);
  v8 = FFX_TK_PopStackFloat(a1, a3);
  v7 = FFX_TK_PopStackFloat(a1, a3);
  v5 = FFX_FieldVM_PopOperand(a1, a3);
  nullsub_34();
  sub_831A30(v5, v7, v8, v9, v10, v3, v6, v11, v12);
  return 0;
}


// Function: sub_A78450
// Address: 0xa78450
// Size: 0x67
// Prototype: 

int __cdecl sub_A78450(int a1, int a2, int *a3)
{
  int v3; // esi
  int v4; // eax
  float v6; // [esp+18h] [ebp-Ch]
  float v7; // [esp+1Ch] [ebp-8h]
  float v8; // [esp+20h] [ebp-4h]

  v8 = FFX_TK_PopStackFloat(a1, a3);
  v7 = FFX_TK_PopStackFloat(a1, a3);
  v6 = FFX_TK_PopStackFloat(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  sub_831D20(v4, v3, v6, v7, v8);
  return 0;
}


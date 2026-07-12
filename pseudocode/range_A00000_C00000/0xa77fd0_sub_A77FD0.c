// Function: sub_A77FD0
// Address: 0xa77fd0
// Size: 0x5b
// Prototype: 

int __cdecl sub_A77FD0(int a1, int a2, int *a3)
{
  int v3; // eax
  float v5; // [esp+14h] [ebp-Ch]
  float v6; // [esp+18h] [ebp-8h]
  float v7; // [esp+1Ch] [ebp-4h]

  v7 = FFX_TK_PopStackFloat(a1, a3);
  v6 = FFX_TK_PopStackFloat(a1, a3);
  v5 = FFX_TK_PopStackFloat(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  sub_836480(v3, v5, v6, v7);
  return 0;
}


// Function: sub_A79820
// Address: 0xa79820
// Size: 0x36
// Prototype: 

void __cdecl sub_A79820(int a1, int *a2, int *a3)
{
  int v3; // [esp-18h] [ebp-1Ch]
  int v4; // [esp-14h] [ebp-18h]

  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v3 = FFX_FieldVM_PopOperand(a1, a3);
  a2[1] = v4;
  *a2 = v3;
  nullsub_34();
}


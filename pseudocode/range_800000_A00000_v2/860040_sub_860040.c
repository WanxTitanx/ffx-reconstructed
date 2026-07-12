// Function: sub_860040
// Address: 0x860040
int __cdecl sub_860040(int a1, int a2, int *a3)
{
  int v4; // ebx
  int v6; // ebx
  int v7; // eax
  int v8; // [esp+14h] [ebp+8h]
  int v9; // [esp+14h] [ebp+8h]

  v4 = FFX_FieldVM_PopOperand(a1, a3);
  v8 = FFX_FieldVM_PopOperand(a1, a3);
  if ( *(_BYTE *)(a1 + 170) != 5 )
    return 0;
  sub_86E380(a1, a3, *(unsigned __int16 *)(a1 + 168));
  sub_86E380(a1, a3, v8);
  sub_86E380(a1, a3, v4);
  v6 = FFX_FieldVM_PopOperand(a1, a3);
  v9 = FFX_FieldVM_PopOperand(a1, a3);
  v7 = FFX_FieldVM_PopOperand(a1, a3);
  if ( *(_BYTE *)(a1 + 170) != 5 )
    return 0;
  sub_908330(v7, v9, v6);
  return 1;
}

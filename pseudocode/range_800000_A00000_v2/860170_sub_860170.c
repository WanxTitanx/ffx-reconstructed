// Function: sub_860170
// Address: 0x860170
int __cdecl sub_860170(_BYTE **a1, int a2, int *a3)
{
  int v3; // edi
  int v4; // eax

  v3 = FFX_FieldVM_PopOperand((int)a1, a3);
  v4 = sub_86C240(a1);
  if ( (unsigned __int8)(**a1 - 5) <= 1u )
    *(_WORD *)(v4 + 40) = v3;
  return v3;
}

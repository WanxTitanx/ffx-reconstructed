// Function: sub_A78960
// Address: 0xa78960
// Size: 0x40
// Prototype: 

int __cdecl sub_A78960(int a1, int a2, int *a3)
{
  int v3; // ebx
  int v4; // esi
  int result; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  v4 = FFX_FieldVM_PopOperand(a1, a3);
  result = FFX_TK_GetChrPointer(a1);
  if ( result )
    return FFX_Model_SetHideFlag(result, v4, v3);
  return result;
}


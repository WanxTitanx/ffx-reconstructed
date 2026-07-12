// Function: sub_A78A10
// Address: 0xa78a10
// Size: 0x30
// Prototype: 

int __cdecl sub_A78A10(int a1, int a2, int *a3)
{
  int v3; // edi
  int result; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  result = FFX_TK_GetChrPointer(a1);
  if ( result )
    return sub_82AE50(result, v3);
  return result;
}


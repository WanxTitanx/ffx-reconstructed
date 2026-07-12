// Function: sub_A79C30
// Address: 0xa79c30
// Size: 0x1f
// Prototype: 

int __cdecl sub_A79C30(int a1)
{
  int result; // eax

  result = FFX_TK_GetChrPointer(a1);
  if ( result )
    return sub_82AC60(result);
  return result;
}


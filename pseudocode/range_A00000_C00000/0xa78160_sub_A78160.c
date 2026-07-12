// Function: sub_A78160
// Address: 0xa78160
// Size: 0x19
// Prototype: 

const char *__cdecl sub_A78160(int a1, int a2, int *a3)
{
  int v3; // eax

  v3 = FFX_FieldVM_PopOperand(a1, a3);
  return std::_Get_future_error_what(v3);
}


// Function: sub_860130
// Address: 0x860130
float *__cdecl sub_860130(int a1, int a2, int *a3)
{
  int v4; // [esp-4h] [ebp-8h]

  v4 = FFX_FieldVM_PopOperand(a1, a3);
  if ( j_FFX_Kernel_GetStubZero() )
    return (float *)sub_86B100(v4);
  else
    return sub_86BEC0(*(float *)&v4);
}

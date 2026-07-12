// Function: sub_9200A0
// Address: 0x9200a0
int __cdecl sub_9200A0(_DWORD *a1, _DWORD *a2, float a3)
{
  FFX_VecMath_Vec4Load(&n964689920, a2);
  sub_72F4A0(&a3, &flt_C8F970);
  sub_710F80((int)&n964689920, (int)&n964689920, flt_C8F970);
  return FFX_VecMath_Vec4Store(&n964689920, a1);
}

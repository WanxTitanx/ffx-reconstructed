// Function: sub_81B3C0
// Address: 0x81b3c0
int __cdecl sub_81B3C0(int a1, float *a2)
{
  int result; // eax
  int v3; // ecx

  if ( sub_780D80() )
    return sub_796160(a1, a2);
  result = a1;
  v3 = LODWORD(flt_12A80C0[a1]);
  if ( v3 )
    return FFX_Chr_SetWorldPosition(v3, *a2, a2[1], a2[2]);
  return result;
}

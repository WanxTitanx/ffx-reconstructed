// Function: sub_81B2F0
// Address: 0x81b2f0
int __cdecl sub_81B2F0(int a1, int a2)
{
  int result; // eax
  float v3; // edx

  *(_DWORD *)a2 = word_C8F508[0];
  *(float *)(a2 + 4) = word_C8F50C;
  *(float *)(a2 + 8) = word_C8F510;
  *(float *)(a2 + 12) = word_C8F514[0];
  result = a1;
  v3 = flt_12A80C0[a1];
  if ( v3 != 0.0 )
    return sub_82AD10(LODWORD(v3), a2, a2 + 4, a2 + 8);
  return result;
}

// Function: sub_800B00
// Address: 0x800b00
int sub_800B00()
{
  int result; // eax
  float *v1; // esi

  result = sub_780D80();
  if ( result )
  {
    v1 = flt_12A80C0;
    do
    {
      result = *(_DWORD *)v1;
      if ( *(_DWORD *)v1 )
        result = sub_82AAB0(result, 1);
      ++v1;
    }
    while ( (int)v1 < (int)&flt_12A8140 );
  }
  return result;
}

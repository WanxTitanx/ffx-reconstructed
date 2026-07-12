// Function: sub_810D80
// Address: 0x810d80
int __cdecl sub_810D80(int a1, int a2, int a3, int a4)
{
  __int16 n2; // ax

  n2 = *(__int16 *)(a1 + 538) >> 12;
  *(_BYTE *)(a4 + 78) = n2;
  if ( (unsigned __int8)n2 == 2 )
  {
    *(float *)(a4 + 64) = *(float *)(a4 + 16);
    *(float *)(a4 + 68) = *(float *)(a4 + 20);
    *(float *)(a4 + 72) = *(float *)(a4 + 24);
  }
  return a3 + 2;
}

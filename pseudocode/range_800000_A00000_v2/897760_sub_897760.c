// Function: sub_897760
// Address: 0x897760
_DWORD *sub_897760()
{
  int n0x12; // eax
  bool v1; // cf
  _DWORD *result; // eax
  int n10; // esi

  n0x12 = 0;
  v1 = 1;
  do
  {
    if ( !v1 )
      __report_rangecheckfailure();
    unk_133D730[n0x12++] = 0;
    v1 = (unsigned int)n0x12 < 0x12;
  }
  while ( n0x12 < 18 );
  result = &unk_133D754;
  do
  {
    n10 = 10;
    do
    {
      *(result - 3) = 0;
      *(result - 2) = 0;
      *(result - 1) = 0;
      result[2] = 0;
      result[3] = 0;
      result[4] = 0;
      result[5] = 0;
      *result = 16711935;
      result[1] = 16711935;
      *((_WORD *)result + 4) = 255;
      result += 9;
      --n10;
    }
    while ( n10 );
  }
  while ( (int)result < (int)dword_133F0A4 );
  return result;
}

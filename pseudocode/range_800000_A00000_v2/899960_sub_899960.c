// Function: sub_899960
// Address: 0x899960
__int16 __cdecl sub_899960(__int16 a1, __int16 a2, __int16 a3)
{
  int n4; // ecx
  __int16 n4_1; // dx
  __int16 result; // ax

  if ( n4_5 < 4 )
  {
    n4 = n4_5;
    n4_1 = n4_5 + 1;
    *((_WORD *)&unk_133F774 + 4 * n4_5) = a1;
    *((_WORD *)&unk_133F778 + 4 * n4) = a2;
    *((_WORD *)&unk_133F77A + 4 * n4) = a3;
    n4_5 = n4_1;
    return a3;
  }
  return result;
}

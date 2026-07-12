// Function: sub_900F80
// Address: 0x900f80
unsigned int __cdecl sub_900F80(int n16, int a2, int a3, int a4)
{
  unsigned int result; // eax

  if ( n16 < 16 )
  {
    if ( a2 != *((__int16 *)&unk_18762A2 + 8 * n16) || (result = *((__int16 *)&unk_18762A4 + 8 * n16), a3 != result) )
    {
      result = 1;
      *((_WORD *)&unk_18762A0 + 8 * n16) = 1;
      *((_WORD *)&unk_18762A2 + 8 * n16) = a2;
      *((_WORD *)&unk_18762A4 + 8 * n16) = a3;
      if ( word_18762AE[8 * n16] != 1 )
      {
        *((_DWORD *)&unk_18762A8 + 4 * n16) = 0;
        result = ((int)((unsigned __int64)(2454267027LL * a4) >> 32) >> 3)
               + ((unsigned int)((unsigned __int64)(2454267027LL * a4) >> 32) >> 31)
               + 2;
        *((_WORD *)&unk_18762A6 + 8 * n16) = a4;
        *((_WORD *)&unk_18762AC + 8 * n16) = result;
      }
    }
  }
  return result;
}

// Function: sub_901090
// Address: 0x901090
int __cdecl sub_901090(int n16, int a2, int a3, int a4)
{
  int result; // eax

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
        *((_WORD *)&unk_18762A6 + 8 * n16) = a4;
        *((_WORD *)&unk_18762A8 + 8 * n16) = a4;
        *((_DWORD *)&unk_18762AA + 4 * n16) = 655370;
        return a4;
      }
    }
  }
  return result;
}

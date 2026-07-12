// Function: sub_8999B0
// Address: 0x8999b0
int __cdecl sub_8999B0(__int16 a1, __int16 a2, int a3, int a4, char a5, char a6, char a7, char a8)
{
  int v9; // ecx
  __int16 v10; // dx

  if ( word_133F0C8[0] >= 63 )
    return -1;
  v9 = 16 * word_133F0C8[0];
  v10 = word_133F0C8[0] + 1;
  *(_WORD *)((char *)&unk_133F0D0 + v9) = a1;
  *(_WORD *)((char *)&unk_133F0D2 + v9) = a2;
  *(_DWORD *)((char *)&unk_133F0D4 + v9) = a3;
  *(_DWORD *)((char *)&unk_133F0D8 + v9) = a4;
  *((_BYTE *)&unk_133F0DC + v9) = a5;
  *((_BYTE *)&unk_133F0DD + v9) = a6;
  *((_BYTE *)&unk_133F0DE + v9) = a7;
  byte_133F0DF[v9] = a8;
  word_133F0C8[0] = v10;
  return v10;
}

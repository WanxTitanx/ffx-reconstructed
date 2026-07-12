// Function: sub_893200
// Address: 0x893200
int sub_893200()
{
  int v0; // edi
  int *v1; // esi
  int n9; // ecx

  sub_903300();
  v0 = 0;
  if ( word_133F0C8[0] > 0 )
  {
    v1 = (int *)&unk_133F0D8;
    do
    {
      if ( unk_1133390 )
      {
        FFX_Achievement_TryUnlock(18);
        unk_1133390 = 0;
      }
      if ( unk_1133394 )
      {
        FFX_Achievement_TryUnlock(21);
        unk_1133394 = 0;
      }
      if ( FFX_Btl_GetCurrentBattleFormationId() != 283 || *(v1 - 1) != 3 )
      {
        n9 = *v1;
        if ( *v1 < 0 || n9 > 9 )
        {
          switch ( n9 )
          {
            case '=':
              sub_8FBCC0(0, *((__int16 *)v1 - 4), *((__int16 *)v1 - 3), *((unsigned __int8 *)v1 + 7));
              break;
            case '<':
              sub_8FBCC0(1, *((__int16 *)v1 - 4), *((__int16 *)v1 - 3), *((unsigned __int8 *)v1 + 7));
              break;
            case ';':
              sub_8FBCC0(2, *((__int16 *)v1 - 4), *((__int16 *)v1 - 3), *((unsigned __int8 *)v1 + 7));
              break;
            case ':':
              sub_8FBCC0(3, *((__int16 *)v1 - 4), *((__int16 *)v1 - 3), *((unsigned __int8 *)v1 + 7));
              break;
          }
        }
        else
        {
          sub_8FB840(
            n9,
            *((__int16 *)v1 - 4),
            *((__int16 *)v1 - 3),
            *((unsigned __int8 *)v1 + 4),
            *((unsigned __int8 *)v1 + 5),
            *((unsigned __int8 *)v1 + 6),
            *((unsigned __int8 *)v1 + 7));
        }
      }
      ++v0;
      v1 += 4;
    }
    while ( v0 < word_133F0C8[0] );
  }
  word_133F0C8[0] = 0;
  return 0;
}

// Function: FFX_Btl_HudRefreshPartyArrays
// Address: 0x8910b0
float *FFX_Btl_HudRefreshPartyArrays()
{
  float *PartyDataArray; // eax
  int i; // ecx
  int i_2; // edx
  float *result; // eax
  int j; // ecx
  int j_1; // edx
  int v6; // esi
  int i_1; // [esp+8h] [ebp-4h] BYREF

  i_1 = 0;
  PartyDataArray = FFX_Btl_GetPartyDataArray(0, 9, &i_1);
  for ( i = i_1; i > 0; i_1 = --i )
  {
    if ( *((_WORD *)PartyDataArray + i - 1) != 255 )
      break;
  }
  i_2 = 0;
  for ( MEMORY[0x133F098] = i; i_2 < i; ++i_2 )
    unk_133F09C[i_2] = *((_WORD *)PartyDataArray + i_2);
  i_1 = 0;
  result = FFX_Btl_GetPartyDataArray(0, 11, &i_1);
  for ( j = i_1; j > 0; i_1 = --j )
  {
    if ( *((_WORD *)result + j - 1) != 255 )
      break;
  }
  j_1 = 0;
  MEMORY[0x133F0AC] = j;
  if ( j > 0 )
  {
    v6 = (char *)result - (char *)unk_133F0B0;
    do
    {
      LOWORD(result) = *(_WORD *)((char *)&unk_133F0B0[j_1] + v6);
      unk_133F0B0[j_1++] = (_WORD)result;
    }
    while ( j_1 < j );
  }
  return result;
}

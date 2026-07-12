// Function: FFX_Btl_SubmenuBuildCommandList
// Address: 0x89af30
__int16 FFX_Btl_SubmenuBuildCommandList()
{
  int n2; // ecx
  int n2_1; // ebx
  _WORD *v2; // edx
  unsigned __int16 *v3; // esi
  unsigned __int16 v4; // di
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v9; // [esp+4h] [ebp-Ch]
  int v10; // [esp+Ch] [ebp-4h]

  n2 = 0;
  n2_1 = 0;
  *(_DWORD *)word_23CC048 = &unk_FF00FF;
  unk_23CC050 = 0;
  unk_23CC058[0] = &unk_FF00FF;
  unk_23CC060 = 0;
  unk_23CC068 = &unk_FF00FF;
  unk_23CC070 = 0;
  if ( unk_23CC092[0] >= 0 )
  {
    v10 = unk_23CC092[0] + 1;
    v2 = word_133C926;
    v3 = word_23CC048;
    do
    {
      v4 = *v2;
      if ( *v2 != 0xFFFF && v4 != 0xFFFE )
      {
        if ( *((_BYTE *)v2 - 20) )
        {
          *((_DWORD *)v3 + 2) = *(_DWORD *)(v2 + 97);
          ++n2_1;
          v3 += 8;
          n2 = 0;
        }
        else
        {
          if ( n2 >= 2 )
          {
            *v3 = v3[1];
            --n2;
          }
          v5 = n2 + 8 * n2_1;
          ++n2;
          word_23CC048[v5] = v4;
        }
      }
      v2 += 120;
      --v10;
    }
    while ( v10 );
  }
  if ( n256_0 == 256 )
  {
    word_23CC048[0] = 12574;
    word_23CC048[1] = unk_133CB06;
    n2_1 = 2;
    LOWORD(unk_23CC058[0]) = unk_133CB08;
  }
  unk_23CC040[0] = unk_133C918;
  if ( !n2_1 )
    LOBYTE(n2_1) = 1;
  n2_11 = n2_1;
  sub_792E60(unk_23CC040);
  if ( unk_133C912[240 * unk_23CC092[0]] )
    v6 = unk_133D138;
  else
    v6 = 1 << *((_BYTE *)&unk_133C918 + 240 * unk_23CC092[0]);
  v9 = v6;
  v7 = word_23CC048[0];
  if ( word_23CC048[1] != 255 )
    v7 = word_23CC048[1];
  return sub_89EC70(v7, v9);
}

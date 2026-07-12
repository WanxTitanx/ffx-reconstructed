// Function: sub_89A0D0
// Address: 0x89a0d0
int __cdecl sub_89A0D0(__int16 a1)
{
  int v1; // eax
  __int16 v2; // dx
  int i; // esi
  int v4; // eax
  __int16 v5; // si
  int j; // edx
  int result; // eax
  __int16 v8; // si
  int v9; // ebx
  int k; // edx

  unk_133F66E = 0;
  unk_133F66A = a1;
  n20_2 = 20;
  unk_133F6BE = FFX_Btl_GetActorCtbGaugeCurrent(a1);
  unk_133F6C0 = FFX_Btl_GetActorCtbTurns(a1);
  v1 = sub_78FAF0(a1);
  v2 = unk_133F670;
  for ( i = 0; i < 12; ++i )
  {
    if ( i == 11 )
    {
      if ( *(_BYTE *)(v1 + 11) )
        continue;
      word_133F672[v2] = 4113;
    }
    else
    {
      if ( *(_BYTE *)(i + v1) != 0xFF )
        continue;
      word_133F672[v2] = i + 4102;
    }
    v2 = ++unk_133F670;
  }
  v4 = sub_78FB30(a1);
  v5 = unk_133F670;
  for ( j = 0; j < 13; ++j )
  {
    if ( *(_BYTE *)(j + v4) == 0xFF )
    {
      word_133F672[v5] = j + 4114;
      v5 = ++unk_133F670;
    }
  }
  result = sub_78FB10(a1);
  v8 = unk_133F670;
  v9 = (unsigned __int16)result;
  for ( k = 0; k < 15; ++k )
  {
    if ( k != 9 )
    {
      HIWORD(result) = HIWORD(v9);
      LOWORD(result) = (unsigned __int16)v9 >> k;
      if ( (((unsigned __int16)v9 >> k) & 1) != 0 )
      {
        result = v8;
        word_133F672[v8] = k + 4128;
        v8 = ++unk_133F670;
      }
    }
  }
  return result;
}

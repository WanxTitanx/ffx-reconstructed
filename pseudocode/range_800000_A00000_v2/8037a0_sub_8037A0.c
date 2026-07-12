// Function: sub_8037A0
// Address: 0x8037a0
int __cdecl sub_8037A0(int a1, int n2, int a3, int a4)
{
  int result; // eax
  int v5; // ebx
  int v6; // esi
  unsigned int v7; // ecx
  unsigned int v8; // eax
  int v9; // [esp+18h] [ebp+14h]

  if ( a4 && sub_80F790(a1) )
    return sub_80F6E0(n2);
  v9 = 0;
  result = sub_830490(a1);
  v5 = result;
  if ( result )
  {
    v6 = 0;
    if ( result > 0 )
    {
      do
      {
        if ( !sub_82AE50(a1, v6) || !a3 )
        {
          v7 = (sub_8304D0(a1, v6) + 15) & 0xFFFFFF0;
          v8 = 0;
          if ( n2 == 2 )
            v8 = (12 * (v7 / 0x1C) + 15) & 0xFFFFFF0;
          v9 += v7 + v8;
        }
        ++v6;
      }
      while ( v6 < v5 );
    }
    return v9 + 16 * (v5 + 1);
  }
  return result;
}

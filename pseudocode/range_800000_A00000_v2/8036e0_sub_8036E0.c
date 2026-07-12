// Function: sub_8036E0
// Address: 0x8036e0
int __cdecl sub_8036E0(int a1, int n2, int a3)
{
  int result; // eax
  int v4; // ebx
  int v5; // esi
  unsigned int v6; // ecx
  unsigned int v7; // eax
  int v8; // [esp+4h] [ebp-4h]

  if ( sub_80F790(a1) )
    return sub_80F6E0(n2);
  v8 = 0;
  result = sub_830490(a1);
  v4 = result;
  if ( result )
  {
    v5 = 0;
    if ( result > 0 )
    {
      do
      {
        if ( !sub_82AE50(a1, v5) || !a3 )
        {
          v6 = (sub_8304D0(a1, v5) + 15) & 0xFFFFFF0;
          v7 = 0;
          if ( n2 == 2 )
            v7 = (12 * (v6 / 0x1C) + 15) & 0xFFFFFF0;
          v8 += v6 + v7;
        }
        ++v5;
      }
      while ( v5 < v4 );
    }
    return v8 + 16 * (v4 + 1);
  }
  return result;
}

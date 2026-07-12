// Function: sub_808000
// Address: 0x808000
_WORD *__cdecl sub_808000(_WORD *i, int a2, int n256)
{
  int n256_1; // ecx
  unsigned __int8 *v5; // eax
  int v6; // ebx
  int v7; // edi
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  __int16 v11; // dx
  unsigned __int8 *v13; // [esp+8h] [ebp-4h]
  int ia; // [esp+14h] [ebp+8h]
  int v15; // [esp+18h] [ebp+Ch]

  n256_1 = n256;
  if ( n256 > 0 )
  {
    v5 = (unsigned __int8 *)(a2 + 2);
    v13 = (unsigned __int8 *)(a2 + 2);
    do
    {
      if ( *(_DWORD *)(v5 - 2) )
      {
        v6 = *(v5 - 2);
        v7 = *(v5 - 1);
        v8 = *v5;
        v9 = v6;
        if ( v6 < v7 )
          v9 = v7;
        if ( v8 > v9 )
          v9 = v8;
        v10 = v6;
        if ( v6 > v7 )
          v10 = v7;
        if ( v8 < v10 )
          v10 = v8;
        ia = v9 - v10;
        if ( v9 == v10 )
        {
          v11 = 0;
          LOWORD(v8) = 0;
        }
        else
        {
          if ( v9 )
            v15 = (ia << 8) / v9;
          else
            LOWORD(v15) = 0;
          if ( v6 == v9 )
          {
            v8 = ((v7 - v8) << 7) / ia;
          }
          else if ( v7 == v9 )
          {
            LOWORD(v8) = ((v8 - v6) << 7) / ia + 256;
          }
          else
          {
            v8 = ((v6 - v7) << 7) / ia + 512;
          }
          v11 = v15;
        }
        *i = v8;
        i[2] = v9;
        n256_1 = n256;
        i[1] = v11;
        i[3] = v13[1];
        v5 = v13;
      }
      else
      {
        *(_DWORD *)i = 0;
      }
      --n256_1;
      v5 += 4;
      i += 4;
      v13 = v5;
      n256 = n256_1;
    }
    while ( n256_1 > 0 );
  }
  return i;
}

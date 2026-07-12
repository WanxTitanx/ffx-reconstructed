// Function: sub_901490
// Address: 0x901490
_DWORD *__cdecl sub_901490(float a1, int a2, int a3, int a4)
{
  int v4; // edi
  int v5; // esi
  int v6; // ebx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  bool v10; // zf
  double v11; // st6
  unsigned int n0x10; // ebx
  int v13; // ecx
  int v14; // edi
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // ecx
  int i; // edi
  char n48; // bl
  int v22; // esi
  int n2; // [esp+0h] [ebp-1Ch]
  int v25; // [esp+0h] [ebp-1Ch]
  float v26[5]; // [esp+4h] [ebp-18h]

  v4 = (int)a1;
  v5 = 1;
  LODWORD(v26[0]) = v4;
  v6 = 0;
  v7 = 1;
  n2 = 2;
  do
  {
    if ( v7 > 0 )
    {
      v8 = v7;
      do
      {
        v5 *= 10;
        --v8;
      }
      while ( v8 );
    }
    v9 = v4 / v5;
    ++v6;
    --v7;
    v4 %= v5;
    v10 = n2-- == 1;
    *((_BYTE *)v26 + v6 + 3) = v9 + 48;
    v5 = 1;
  }
  while ( !v10 );
  v11 = (double)SLODWORD(v26[0]);
  *((_BYTE *)&v26[1] + v6) = 46;
  n0x10 = v6 + 1;
  v26[0] = v11;
  v13 = (int)((a1 - v26[0]) * 100.0);
  v25 = v13;
  v14 = 1;
  LODWORD(v26[0]) = 2;
  do
  {
    if ( v14 > 0 )
    {
      v15 = v14;
      do
      {
        v5 *= 10;
        --v15;
      }
      while ( v15 );
      v13 = v25;
    }
    v16 = v13 / v5;
    ++n0x10;
    --v14;
    v13 %= v5;
    v10 = LODWORD(v26[0])-- == 1;
    *((_BYTE *)v26 + n0x10 + 3) = v16 + 48;
    v25 = v13;
    v5 = 1;
  }
  while ( !v10 );
  if ( n0x10 >= 0x10 )
    __report_rangecheckfailure();
  v17 = a4;
  v18 = a3;
  *((_BYTE *)&v26[1] + n0x10) = 0;
  for ( i = 0; i < 16; ++i )
  {
    n48 = *((_BYTE *)&v26[1] + i);
    if ( !n48 )
      break;
    if ( n48 >= 48 && n48 <= 57 )
    {
      sub_903A50(n48 + 432, a2, v18, v17, v17);
      v17 = a4;
      v18 = a3;
      a2 += 16;
    }
    if ( n48 == 46 )
    {
      v22 = a2 - 5;
      sub_903A50(479, v22, v18, v17, v17);
      a2 = v22 + 10;
    }
    v17 = a4;
    v18 = a3;
  }
  return sub_8F3A30();
}

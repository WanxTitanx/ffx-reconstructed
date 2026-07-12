// Function: sub_8B0050
// Address: 0x8b0050
int __cdecl sub_8B0050(_DWORD *a1)
{
  _WORD *v1; // edx
  int i; // eax
  int j; // ecx
  _WORD *v4; // eax
  __int16 v5; // ax
  int k; // ecx
  int n8; // eax
  __int16 n0x7FFF; // cx
  int v9; // [esp+4h] [ebp-28h]
  int v10; // [esp+8h] [ebp-24h]
  int v11; // [esp+Ch] [ebp-20h]
  int v12; // [esp+10h] [ebp-1Ch]
  int v13; // [esp+14h] [ebp-18h]
  int v14; // [esp+18h] [ebp-14h]
  int v15; // [esp+1Ch] [ebp-10h]
  int v16; // [esp+20h] [ebp-Ch]
  int v17; // [esp+24h] [ebp-8h]

  v1 = a1;
  for ( i = 0; i < 8; ++i )
    *(&v9 + i) = 2147450879;
  for ( j = 0; j < 8; ++j )
  {
    v4 = (_WORD *)dword_1865AFC[j];
    if ( *v4 == 1 )
    {
      v5 = v4[2];
      *((_WORD *)&v9 + 2 * j) = j;
      *((_WORD *)&v9 + 2 * j + 1) = v5;
    }
  }
  for ( k = 0; k < 8; ++k )
  {
    if ( SHIWORD(v9) < *((__int16 *)&v9 + 2 * k + 1) )
    {
      LOWORD(v17) = *((_WORD *)&v9 + 2 * k);
      HIWORD(v17) = *((_WORD *)&v9 + 2 * k + 1);
      *((_WORD *)&v9 + 2 * k) = v9;
      *((_WORD *)&v9 + 2 * k + 1) = HIWORD(v9);
      v9 = v17;
    }
    if ( SHIWORD(v10) < *((__int16 *)&v9 + 2 * k + 1) )
    {
      LOWORD(v17) = *((_WORD *)&v9 + 2 * k);
      HIWORD(v17) = *((_WORD *)&v9 + 2 * k + 1);
      *((_WORD *)&v9 + 2 * k) = v10;
      *((_WORD *)&v9 + 2 * k + 1) = HIWORD(v10);
      v10 = v17;
    }
    if ( SHIWORD(v11) < *((__int16 *)&v9 + 2 * k + 1) )
    {
      LOWORD(v17) = *((_WORD *)&v9 + 2 * k);
      HIWORD(v17) = *((_WORD *)&v9 + 2 * k + 1);
      *((_WORD *)&v9 + 2 * k) = v11;
      *((_WORD *)&v9 + 2 * k + 1) = HIWORD(v11);
      v11 = v17;
    }
    if ( SHIWORD(v12) < *((__int16 *)&v9 + 2 * k + 1) )
    {
      LOWORD(v17) = *((_WORD *)&v9 + 2 * k);
      HIWORD(v17) = *((_WORD *)&v9 + 2 * k + 1);
      *((_WORD *)&v9 + 2 * k) = v12;
      *((_WORD *)&v9 + 2 * k + 1) = HIWORD(v12);
      v12 = v17;
    }
    if ( SHIWORD(v13) < *((__int16 *)&v9 + 2 * k + 1) )
    {
      LOWORD(v17) = *((_WORD *)&v9 + 2 * k);
      HIWORD(v17) = *((_WORD *)&v9 + 2 * k + 1);
      *((_WORD *)&v9 + 2 * k) = v13;
      *((_WORD *)&v9 + 2 * k + 1) = HIWORD(v13);
      v13 = v17;
    }
    if ( SHIWORD(v14) < *((__int16 *)&v9 + 2 * k + 1) )
    {
      LOWORD(v17) = *((_WORD *)&v9 + 2 * k);
      HIWORD(v17) = *((_WORD *)&v9 + 2 * k + 1);
      *((_WORD *)&v9 + 2 * k) = v14;
      *((_WORD *)&v9 + 2 * k + 1) = HIWORD(v14);
      v14 = v17;
    }
    if ( SHIWORD(v15) < *((__int16 *)&v9 + 2 * k + 1) )
    {
      LOWORD(v17) = *((_WORD *)&v9 + 2 * k);
      HIWORD(v17) = *((_WORD *)&v9 + 2 * k + 1);
      *((_WORD *)&v9 + 2 * k) = v15;
      *((_WORD *)&v9 + 2 * k + 1) = HIWORD(v15);
      v15 = v17;
    }
    if ( SHIWORD(v16) < *((__int16 *)&v9 + 2 * k + 1) )
    {
      LOWORD(v17) = *((_WORD *)&v9 + 2 * k);
      HIWORD(v17) = *((_WORD *)&v9 + 2 * k + 1);
      *((_WORD *)&v9 + 2 * k) = v16;
      *((_WORD *)&v9 + 2 * k + 1) = HIWORD(v16);
      v16 = v17;
    }
  }
  *a1 = -1;
  a1[1] = -1;
  a1[2] = -1;
  a1[3] = -1;
  for ( n8 = 0; n8 < 8; ++n8 )
  {
    n0x7FFF = *((_WORD *)&v9 + 2 * n8);
    if ( n0x7FFF == 0x7FFF )
      break;
    *v1++ = n0x7FFF;
  }
  return n8;
}

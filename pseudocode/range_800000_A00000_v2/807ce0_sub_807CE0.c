// Function: sub_807CE0
// Address: 0x807ce0
int __cdecl sub_807CE0(int a1, __int16 *i, int n256, int a4, int a5, int a6, int n256_3)
{
  int v7; // edx
  int n256_1; // edi
  int n256_4; // eax
  __int16 *i_1; // ebx
  _BYTE *v11; // ecx
  int v12; // esi
  int n768; // esi
  int v14; // esi
  int n256_6; // eax
  int n256_5; // ecx
  int n255_1; // eax
  int n255; // ebx
  int v19; // esi
  int n255_6; // ecx
  char n255_3; // al
  int v23; // [esp+0h] [ebp-18h]
  _BYTE *v24; // [esp+4h] [ebp-14h]
  int v25; // [esp+8h] [ebp-10h]
  int n256_2; // [esp+Ch] [ebp-Ch]
  int n255_4; // [esp+10h] [ebp-8h]
  char n255_2; // [esp+14h] [ebp-4h]
  float v29; // [esp+2Ch] [ebp+14h]
  float v30; // [esp+2Ch] [ebp+14h]
  int n255_5; // [esp+2Ch] [ebp+14h]

  v29 = (float)a4;
  v30 = v29 / 5.333333492279053;
  v7 = (int)v30 % 768;
  v25 = v7;
  if ( n256_3 <= 256 )
  {
    n256_2 = n256_3 < 0 ? 0 : n256_3;
    n256_1 = n256_2;
  }
  else
  {
    n256_1 = 256;
    n256_2 = 256;
  }
  if ( n256 <= 0 )
    return (int)i;
  n256_4 = n256;
  i_1 = i;
  v11 = (_BYTE *)(a1 + 2);
  v24 = (_BYTE *)(a1 + 2);
  do
  {
    if ( *(_DWORD *)i_1 )
    {
      v12 = *i_1;
      if ( v7 <= v12 )
      {
        if ( v12 - v7 >= 384 )
        {
          v7 += 768;
          v25 = v7;
        }
      }
      else if ( v7 - v12 >= 384 )
      {
        v12 += 768;
      }
      n768 = n256_1 * (v7 - v12) / 256 + v12;
      if ( n768 < 768 )
        v14 = n768 + (n768 < 0 ? 0x300 : 0);
      else
        v14 = n768 - 768;
      n256_6 = a5 + i_1[1];
      if ( n256_6 <= 256 )
        n256_5 = n256_6 < 0 ? 0 : n256_6;
      else
        n256_5 = 256;
      n255_1 = a6 + i_1[2];
      if ( n255_1 <= 255 )
        n255 = n255_1 < 0 ? 0 : n255_1;
      else
        n255 = 255;
      v23 = v14 / 128;
      v19 = v14 % 128;
      n255_5 = n255 * (256 - n256_5) / 256;
      n255_4 = n255 * (0x8000 - n256_5 * v19) / 0x8000;
      n255_6 = n255 * (0x8000 - n256_5 * (128 - v19)) / 0x8000;
      if ( v23 )
      {
        switch ( v23 )
        {
          case 1:
            n255_3 = n255_4;
            LOBYTE(n256_3) = n255_4;
            LOBYTE(a1) = n255;
            n255_2 = n255_5;
            break;
          case 2:
            n255_3 = n255_5;
            LOBYTE(n256_3) = n255_5;
            LOBYTE(a1) = n255;
            n255_2 = n255_6;
            break;
          case 3:
            n255_3 = n255_5;
            LOBYTE(n256_3) = n255_5;
            LOBYTE(a1) = n255_4;
            n255_2 = n255;
            break;
          case 4:
            n255_3 = n255_6;
            LOBYTE(n256_3) = n255_6;
            LOBYTE(a1) = n255_5;
            n255_2 = n255;
            break;
          case 5:
            LOBYTE(a1) = n255_5;
            n255_3 = n255;
            LOBYTE(n256_3) = n255;
            n255_2 = n255_4;
            break;
          default:
            n255_3 = n256_3;
            break;
        }
      }
      else
      {
        LOBYTE(a1) = n255_6;
        n255_3 = n255;
        LOBYTE(n256_3) = n255;
        n255_2 = n255_5;
      }
      v11 = v24;
      i_1 = i;
      v7 = v25;
      *(v24 - 2) = n255_3;
      *(v24 - 1) = a1;
      *v24 = n255_2;
      v24[1] = *((_BYTE *)i + 6);
      n256_4 = n256;
    }
    else
    {
      *(_DWORD *)(v11 - 2) = 0;
    }
    n256_1 = n256_2;
    --n256_4;
    v11 += 4;
    i_1 += 4;
    v24 = v11;
    i = i_1;
    n256 = n256_4;
  }
  while ( n256_4 > 0 );
  return (int)i_1;
}

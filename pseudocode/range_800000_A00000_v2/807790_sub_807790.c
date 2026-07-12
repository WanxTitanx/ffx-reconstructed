// Function: sub_807790
// Address: 0x807790
int __cdecl sub_807790(int a1, unsigned __int16 *a2, int a3, int a4, int a5, int n256_10)
{
  int v6; // edi
  int result; // eax
  __int16 *v8; // ebx
  int v9; // eax
  int n256_2; // edi
  int v11; // edx
  unsigned __int16 *v12; // ecx
  int v13; // esi
  int v14; // edx
  int n256; // edi
  float v16; // ecx
  int v17; // esi
  int n768; // esi
  int v19; // esi
  int n256_4; // eax
  int n256_3; // ecx
  int n255_1; // eax
  int n255; // ebx
  int v24; // esi
  int v25; // ecx
  int n256_9; // ecx
  char n256_6; // al
  int v28; // eax
  float v29; // [esp+4h] [ebp-58h]
  float v30; // [esp+8h] [ebp-54h]
  float n256_12; // [esp+Ch] [ebp-50h]
  int v32; // [esp+1Ch] [ebp-40h]
  float n256_11; // [esp+1Ch] [ebp-40h]
  float v34; // [esp+1Ch] [ebp-40h]
  float v35; // [esp+1Ch] [ebp-40h]
  float v36; // [esp+20h] [ebp-3Ch] BYREF
  float v37; // [esp+24h] [ebp-38h]
  unsigned __int16 *v38; // [esp+28h] [ebp-34h]
  int v39; // [esp+2Ch] [ebp-30h]
  int v40; // [esp+30h] [ebp-2Ch]
  __int16 *v41; // [esp+34h] [ebp-28h]
  float v42; // [esp+38h] [ebp-24h]
  int v43; // [esp+3Ch] [ebp-20h]
  int v44; // [esp+40h] [ebp-1Ch]
  int n256_1; // [esp+44h] [ebp-18h]
  int n256_5; // [esp+48h] [ebp-14h]
  int n255_3; // [esp+4Ch] [ebp-10h]
  int n255_2; // [esp+50h] [ebp-Ch]
  int n256_7; // [esp+54h] [ebp-8h]
  int n256_8; // [esp+58h] [ebp-4h]

  v6 = a1;
  result = sub_7FCBA0(a1);
  if ( !result )
  {
    v44 = *a2;
    v8 = (__int16 *)(a2 + 16);
    v37 = (float)a5;
    v36 = v37 * 0.0078125 + *(float *)sub_83CB90(a1);
    if ( !(a5 + a4) )
      sub_83C770(a1, &v36);
    v9 = 0;
    v39 = 0;
    if ( v44 > 0 )
    {
      n256_2 = n256_10;
      v11 = v44;
      v12 = a2 + 1;
      v38 = a2 + 1;
      do
      {
        v13 = *v12;
        v40 = v13;
        if ( v13 )
        {
          v41 = v8;
          n256_5 = sub_83C9D0(a1, v9);
          v42 = (float)a3;
          v42 = v42 / 5.333333492279053;
          v14 = (int)v42 % 768;
          v43 = v14;
          if ( n256_2 <= 256 )
          {
            n256_1 = n256_2 < 0 ? 0 : n256_2;
            n256 = n256_1;
          }
          else
          {
            n256 = 256;
            n256_1 = 256;
          }
          LODWORD(v16) = n256_5 + 2;
          LODWORD(v42) = n256_5 + 2;
          do
          {
            if ( *(_DWORD *)v8 )
            {
              v17 = *v8;
              if ( v14 <= v17 )
              {
                if ( v17 - v14 >= 384 )
                {
                  v14 += 768;
                  v43 = v14;
                }
              }
              else if ( v14 - v17 >= 384 )
              {
                v17 += 768;
              }
              n768 = n256 * (v14 - v17) / 256 + v17;
              if ( n768 < 768 )
                v19 = n768 + (n768 < 0 ? 0x300 : 0);
              else
                v19 = n768 - 768;
              n256_4 = a4 + v8[1];
              if ( n256_4 <= 256 )
                n256_3 = n256_4 < 0 ? 0 : n256_4;
              else
                n256_3 = 256;
              n255_1 = a5 + v8[2];
              n256_5 = n256_3;
              if ( n255_1 <= 255 )
                n255 = n255_1 < 0 ? 0 : n255_1;
              else
                n255 = 255;
              v32 = v19 / 128;
              v24 = v19 % 128;
              n256_8 = n255 * (256 - n256_3) / 256;
              v25 = n256_5 * (128 - v24);
              n256_5 = n255 * (0x8000 - n256_5 * v24) / 0x8000;
              n256_9 = n255 * (0x8000 - v25) / 0x8000;
              if ( v32 )
              {
                switch ( v32 )
                {
                  case 1:
                    n256_6 = n256_5;
                    n256_7 = n256_5;
                    n255_2 = n255;
                    n255_3 = n256_8;
                    break;
                  case 2:
                    n256_6 = n256_8;
                    n256_7 = n256_8;
                    n255_2 = n255;
                    n255_3 = n256_9;
                    break;
                  case 3:
                    n256_6 = n256_8;
                    n256_7 = n256_8;
                    n255_2 = n256_5;
                    n255_3 = n255;
                    break;
                  case 4:
                    n256_6 = n256_9;
                    n256_7 = n256_9;
                    n255_2 = n256_8;
                    n255_3 = n255;
                    break;
                  case 5:
                    n255_2 = n256_8;
                    n256_6 = n255;
                    n256_7 = n255;
                    n255_3 = n256_5;
                    break;
                  default:
                    n256_6 = n256_7;
                    break;
                }
              }
              else
              {
                n255_2 = n256_9;
                n256_6 = n255;
                n256_7 = n255;
                n255_3 = n256_8;
              }
              v16 = v42;
              v8 = v41;
              v14 = v43;
              v13 = v40;
              *(_BYTE *)(LODWORD(v42) - 2) = n256_6;
              *(_BYTE *)(LODWORD(v16) - 1) = n255_2;
              *(_BYTE *)LODWORD(v16) = n255_3;
              *(_BYTE *)(LODWORD(v16) + 1) = *((_BYTE *)v8 + 6);
            }
            else
            {
              *(_DWORD *)(LODWORD(v16) - 2) = 0;
            }
            n256 = n256_1;
            --v13;
            LODWORD(v16) += 4;
            v8 += 4;
            v42 = v16;
            v41 = v8;
            v40 = v13;
          }
          while ( v13 > 0 );
          v9 = v39;
          v12 = v38;
          n256_2 = n256_10;
          v11 = v44;
        }
        ++v9;
        ++v12;
        v39 = v9;
        v38 = v12;
      }
      while ( v9 < v11 );
      v6 = a1;
    }
    n256_11 = (float)n256_10;
    n256_12 = n256_11;
    v30 = v37;
    v34 = (float)a4;
    v29 = v34;
    v35 = (float)a3;
    v28 = sub_826BF0(v6);
    return sub_6434F0(v28, v35, v29, v30, n256_12);
  }
  return result;
}

// Function: sub_A04920
// Address: 0xa04920
// Size: 0x1f6
// Prototype: int __cdecl(int, int, int, int, int, int, float, char)

int __cdecl sub_A04920(int a1, int a2, int a3, unsigned int a4, int a5, int a6, float a7, char a8)
{
  int n17; // ecx
  int v10; // edx
  unsigned int v11; // ebx
  double v12; // st7
  double v13; // st6
  int v14; // esi
  unsigned int v15; // edi
  int v16; // eax
  unsigned int v17; // ecx
  int v18; // ebx
  int v19; // eax
  _DWORD *v20; // edi
  char *v21; // ecx
  _DWORD *v22; // edx
  int n4_1; // esi
  bool v24; // zf
  float v25; // [esp+0h] [ebp-80h]
  int v26; // [esp+14h] [ebp-6Ch]
  int v27; // [esp+1Ch] [ebp-64h]
  int v28; // [esp+20h] [ebp-60h]
  char v29; // [esp+24h] [ebp-5Ch]
  unsigned int v30; // [esp+28h] [ebp-58h]
  unsigned int v31; // [esp+2Ch] [ebp-54h]
  int n4; // [esp+30h] [ebp-50h]
  int v33; // [esp+34h] [ebp-4Ch]
  unsigned int v34; // [esp+38h] [ebp-48h]
  int v35; // [esp+3Ch] [ebp-44h] BYREF
  char v36; // [esp+40h] [ebp-40h] BYREF

  n17 = *(_DWORD *)(a6 + 8);
  v28 = a1;
  if ( n17 != 17 && n17 != 15 )
    return 5;
  v10 = a3;
  if ( (a3 & 3) != 0 || !a3 )
    return 5;
  v11 = a4;
  if ( (a4 & 3) != 0 || !a4 || (a5 & 3) != 0 || !a5 || !a1 || !a2 )
    return 5;
  v29 = n17 == 17;
  v12 = a7;
  v13 = 0.0;
  v14 = 0;
  v15 = ((unsigned int)(a5 - 1) >> 2) + 1;
  v33 = 0;
  v31 = v15;
  v16 = 4 * a4;
  do
  {
    v17 = 0;
    v34 = 0;
    if ( v11 )
    {
      do
      {
        if ( v10 )
        {
          v18 = 4 * v10;
          v26 = 4 * a4 * v10;
          v19 = a2 + 8 + 4 * v10 * (v14 + v17);
          v27 = v19;
          v30 = ((unsigned int)(v10 - 1) >> 2) + 1;
          do
          {
            v20 = (_DWORD *)v19;
            n4 = 4;
            do
            {
              v21 = &v36;
              v22 = v20;
              n4_1 = 4;
              do
              {
                *((_DWORD *)v21 - 1) = *(v22 - 2);
                *(_DWORD *)v21 = *(v22 - 1);
                *((_DWORD *)v21 + 1) = *v22;
                *((_DWORD *)v21 + 2) = v22[1];
                v22 = (_DWORD *)((char *)v22 + v18);
                v21 += 16;
                --n4_1;
              }
              while ( n4_1 );
              v25 = v12;
              sub_A10DD0(v28, (int)&v35, v13 < v12, v29, v25, a8);
              v12 = a7;
              v13 = 0.0;
              v20 = (_DWORD *)((char *)v20 + v26);
              v24 = n4-- == 1;
              v28 += 4 * (2 * (v29 != 0) + 2);
            }
            while ( !v24 );
            v19 = v27 + 16;
            v24 = v30-- == 1;
            v12 = a7;
            v13 = 0.0;
            v27 += 16;
          }
          while ( !v24 );
          v17 = v34;
          v10 = a3;
          v12 = a7;
          v11 = a4;
          v13 = 0.0;
          v14 = v33;
        }
        v17 += 4;
        v34 = v17;
      }
      while ( v17 < v11 );
      v15 = v31;
      v16 = 4 * v11;
    }
    v14 += v16;
    --v15;
    v33 = v14;
    v31 = v15;
  }
  while ( v15 );
  return 0;
}


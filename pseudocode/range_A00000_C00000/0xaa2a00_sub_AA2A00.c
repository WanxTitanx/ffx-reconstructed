// Function: sub_AA2A00
// Address: 0xaa2a00
// Size: 0x359
// Prototype: int __cdecl(void *Block, int)

int *__cdecl sub_AA2A00(_DWORD *Block, int a2)
{
  int n63; // edi
  int v3; // esi
  int v4; // ebx
  int v5; // eax
  int *Blocka_1; // ecx
  int v7; // eax
  int *v8; // ecx
  int *v9; // esi
  int v10; // eax
  int v11; // ebx
  int *v12; // esi
  int v13; // eax
  int v14; // eax
  int *Blocka_2; // edx
  int v16; // ebx
  int v17; // ecx
  int n63_2; // esi
  _DWORD *v19; // eax
  int *v20; // edi
  int v21; // eax
  signed int n4; // esi
  signed int n4_1; // ecx
  __m128i si128; // xmm2
  __m128i v25; // xmm3
  __m128i v26; // xmm1
  __m128i *Base_1; // eax
  __m128i v28; // xmm0
  int *v29; // eax
  int v30; // edx
  _DWORD Base[65]; // [esp+Ch] [ebp-118h] BYREF
  int n63_3; // [esp+110h] [ebp-14h]
  int n63_1; // [esp+114h] [ebp-10h]
  int v36; // [esp+118h] [ebp-Ch]
  int *v37; // [esp+11Ch] [ebp-8h]
  int *v38; // [esp+120h] [ebp-4h]
  int *Blocka; // [esp+12Ch] [ebp+8h]

  v36 = Block[7];
  n63 = 0;
  v3 = -1;
  Blocka = (int *)calloc_0(1u, 0x460u);
  memset(Blocka, 0, 0x460u);
  v4 = a2;
  v5 = sub_42EB10(a2, 5);
  Blocka_1 = Blocka;
  v38 = 0;
  *Blocka = v5;
  if ( v5 > 0 )
  {
    v37 = Blocka + 1;
    do
    {
      v7 = sub_42EB10(a2, 4);
      v8 = v37;
      *v37 = v7;
      if ( v7 < 0 )
        goto LABEL_44;
      if ( v3 < v7 )
        v3 = v7;
      v37 = v8 + 1;
      Blocka_1 = Blocka;
      v38 = (int *)((char *)v38 + 1);
    }
    while ( (int)v38 < *Blocka );
  }
  n63_1 = 0;
  n63_3 = v3 + 1;
  if ( v3 + 1 > 0 )
  {
    v9 = Blocka_1 + 64;
    v38 = Blocka_1 + 80;
    v37 = Blocka_1 + 64;
    while ( 1 )
    {
      *(v9 - 32) = sub_42EB10(v4, 3) + 1;
      v10 = sub_42EB10(v4, 2);
      *(v9 - 16) = v10;
      if ( v10 < 0 )
        break;
      if ( v10 )
        *v9 = sub_42EB10(v4, 8);
      if ( *v9 < 0 || *v9 >= *(_DWORD *)(v36 + 24) )
        break;
      v11 = 0;
      if ( 1 << *(v9 - 16) > 0 )
      {
        v12 = v38;
        while ( 1 )
        {
          v13 = sub_42EB10(a2, 8) - 1;
          *v12 = v13;
          if ( v13 < -1 || v13 >= *(_DWORD *)(v36 + 24) )
            goto LABEL_44;
          ++v11;
          ++v12;
          if ( v11 >= 1 << *(v37 - 16) )
          {
            v9 = v37;
            break;
          }
        }
      }
      v38 += 8;
      v4 = a2;
      ++v9;
      ++n63_1;
      v37 = v9;
      if ( n63_1 >= n63_3 )
        goto LABEL_21;
    }
LABEL_44:
    Blocka_2 = Blocka;
    goto LABEL_45;
  }
LABEL_21:
  Blocka[208] = sub_42EB10(v4, 2) + 1;
  v14 = sub_42EB10(v4, 4);
  Blocka_2 = Blocka;
  v16 = v14;
  if ( v14 >= 0 )
  {
    v17 = 0;
    n63_2 = 0;
    v36 = 0;
    if ( *Blocka > 0 )
    {
      v19 = Blocka + 1;
      v38 = Blocka + 1;
      do
      {
        n63 += Blocka_2[*v19 + 32];
        n63_1 = n63;
        if ( n63 > 63 )
          goto LABEL_45;
        if ( n63_2 < n63 )
        {
          v20 = &Blocka_2[n63_2 + 211];
          while ( 1 )
          {
            v21 = sub_42EB10(a2, v16);
            *v20 = v21;
            if ( v21 < 0 || v21 >= 1 << v16 )
              goto LABEL_44;
            ++n63_2;
            ++v20;
            if ( n63_2 >= n63_1 )
            {
              n63 = n63_1;
              Blocka_2 = Blocka;
              v17 = v36;
              break;
            }
          }
        }
        ++v17;
        v19 = v38 + 1;
        v36 = v17;
        ++v38;
      }
      while ( v17 < *Blocka_2 );
    }
    n4 = n63 + 2;
    n4_1 = 0;
    Blocka_2[209] = 0;
    Blocka_2[210] = 1 << v16;
    if ( n63 + 2 > 0 )
    {
      if ( (unsigned int)n4 >= 4 && n2_9 >= 2 )
      {
        si128 = _mm_load_si128((const __m128i *)&xmmword_B92360);
        v25 = _mm_load_si128((const __m128i *)&xmmword_B92370);
        v26 = _mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128((unsigned int)Blocka_2), 0), (__m128i)xmmword_B92380);
        Base_1 = (__m128i *)Base;
        do
        {
          v28 = _mm_add_epi32(
                  _mm_mullo_epi32(_mm_add_epi32(_mm_shuffle_epi32(_mm_cvtsi32_si128(n4_1), 0), si128), v25),
                  v26);
          n4_1 += 4;
          *Base_1++ = v28;
        }
        while ( n4_1 < n4 - n4 % 4 );
      }
      if ( n4_1 < n4 )
      {
        v29 = &Blocka_2[n4_1 + 209];
        do
          Base[n4_1++] = v29++;
        while ( n4_1 < n4 );
      }
    }
    qsort(Base, n4, 4u, sub_AA2D60);
    v30 = 1;
    if ( n4 <= 1 )
      return Blocka;
    while ( *(_DWORD *)Base[v30 - 1] != *(_DWORD *)Base[v30] )
    {
      if ( ++v30 >= n4 )
        return Blocka;
    }
    goto LABEL_44;
  }
LABEL_45:
  memset(Blocka_2, 0, 0x460u);
  free_1(Blocka);
  return 0;
}


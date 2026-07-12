// Function: sub_A95990
// Address: 0xa95990
// Size: 0x351
// Prototype: 

int __fastcall sub_A95990(int *a1, unsigned int a2, unsigned int a3)
{
  int n4; // esi
  unsigned int v4; // ebx
  void *v5; // esp
  float *v6; // edi
  signed int n4_2; // ecx
  __m128 *v8; // edx
  char *v9; // edx
  __m128 *v10; // eax
  __m128 v11; // xmm0
  __int32 *v12; // eax
  unsigned int v13; // edx
  unsigned int v14; // edx
  float *v15; // eax
  signed int n4_7; // edi
  int v17; // esi
  float v18; // xmm0_4
  float v19; // xmm0_4
  unsigned int v20; // edi
  float v21; // xmm0_4
  float *v22; // eax
  int v23; // edi
  int v24; // edx
  signed int n4_9; // ecx
  float v26; // xmm0_4
  int result; // eax
  signed int n4_5; // ecx
  __m128 *v29; // edx
  __m128 *v30; // eax
  unsigned int v31; // edx
  __m128 v32; // xmm1
  unsigned int n4_3; // eax
  unsigned int v34; // ebx
  __int32 *v35; // eax
  unsigned int n4_4; // edx
  float v37; // xmm0_4
  bool v38; // zf
  float *m128_f32; // eax
  unsigned int v40; // ebx
  int v41; // edx
  float v42; // xmm0_4
  int v43; // edx
  int n39; // ecx
  int v45; // [esp+8h] [ebp-30h] BYREF
  unsigned int n4_1; // [esp+14h] [ebp-24h]
  int n4_8; // [esp+18h] [ebp-20h]
  unsigned int v48; // [esp+1Ch] [ebp-1Ch]
  unsigned int v49; // [esp+20h] [ebp-18h]
  int v50; // [esp+24h] [ebp-14h]
  unsigned int v51; // [esp+28h] [ebp-10h]
  int *v52; // [esp+2Ch] [ebp-Ch]
  signed int n4_6; // [esp+30h] [ebp-8h]
  __m128 *v54; // [esp+34h] [ebp-4h]

  n4 = *a1;
  v4 = a2;
  v52 = a1;
  v51 = a2;
  n4_1 = n4;
  v5 = alloca(4 * n4);
  v6 = (float *)a3;
  v54 = (__m128 *)&v45;
  sub_A95CF0(a2, a3, 1124859904, -1);
  n4_2 = 0;
  if ( n4 > 0 )
  {
    v8 = v54;
    if ( (unsigned int)n4 >= 4
      && ((unsigned int)v54 > a3 - 4 + 4 * n4 || (unsigned int)&v54[-1].m128_u32[n4 + 3] < a3)
      && ((unsigned int)v54 > v4 - 4 + 4 * n4 || (unsigned int)&v54[-1].m128_u32[n4 + 3] < v4) )
    {
      n4_6 = n4 - (n4 & 3);
      v49 = a3 - v4;
      v9 = (char *)v54 - v4;
      v10 = (__m128 *)v4;
      do
      {
        n4_2 += 4;
        v11 = _mm_sub_ps(*v10, *(__m128 *)((char *)v10 + a3 - v4));
        *(__m128 *)((char *)++v10 + (_DWORD)v9 - 16) = v11;
      }
      while ( n4_2 < n4_6 );
      v6 = (float *)a3;
      v8 = v54;
    }
    if ( n4_2 < n4 )
    {
      if ( n4 - n4_2 >= 4 )
      {
        n4_8 = n4 - 3;
        v12 = &v8->m128_i32[2];
        v13 = v4;
        v50 = (char *)v54 - (char *)v6;
        v4 = v51;
        v49 = (unsigned int)&v12[n4_2];
        n4_6 = v13 - (_DWORD)v6;
        v14 = v49;
        v15 = &v6[n4_2 + 1];
        n4_7 = n4_6;
        v48 = v51 - (_DWORD)v54;
        v17 = v50;
        do
        {
          v18 = *(float *)(v4 + 4 * n4_2) - *(v15 - 1);
          n4_2 += 4;
          v15 += 4;
          v14 += 16;
          *(float *)(v14 - 24) = v18;
          v19 = *(float *)((char *)v15 + n4_7 - 16) - *(v15 - 4);
          v20 = v48;
          *(float *)((char *)v15 + v17 - 16) = v19;
          v21 = *(float *)(v14 + v20 - 16) - *(v15 - 3);
          n4_7 = n4_6;
          *(float *)(v14 - 16) = v21;
          *(float *)(v14 - 12) = *(float *)(v4 + 4 * n4_2 - 4) - *(v15 - 2);
        }
        while ( n4_2 < n4_8 );
        n4 = n4_1;
        v6 = (float *)a3;
        v8 = v54;
      }
      if ( n4_2 < n4 )
      {
        n4_1 = (char *)v8 - (char *)v6;
        n4_6 = v4 - (_DWORD)v6;
        v22 = &v6[n4_2];
        v23 = (char *)v8 - (char *)v6;
        v24 = n4 - n4_2;
        n4_9 = n4_6;
        do
        {
          v26 = *(float *)((char *)v22 + n4_9) - *v22;
          *(float *)((char *)++v22 + v23 - 4) = v26;
          --v24;
        }
        while ( v24 );
        v6 = (float *)a3;
      }
    }
  }
  result = sub_A95CF0(v54, v6, 0, *(_DWORD *)(v52[1] + 128));
  n4_5 = 0;
  if ( n4 > 0 )
  {
    v29 = v54;
    if ( (unsigned int)n4 >= 4
      && ((unsigned int)v54 > v4 + 4 * (n4 - 1) || (unsigned int)&v54[-1].m128_u32[n4 + 3] < v4) )
    {
      n4_6 = n4 - (n4 & 3);
      n4_1 = v4 - (_DWORD)v54;
      v6 = (float *)a3;
      v30 = v54;
      v31 = v4 - (_DWORD)v54;
      do
      {
        n4_5 += 4;
        v32 = _mm_sub_ps(*(__m128 *)((char *)v30 + v31), *v30);
        ++v30;
        v30[-1] = v32;
      }
      while ( n4_5 < n4_6 );
      v29 = v54;
    }
    if ( n4_5 < n4 )
    {
      if ( n4 - n4_5 >= 4 )
      {
        n4_8 = v4 - (_DWORD)v29;
        n4_3 = v4 + 4 * (n4_5 + 3);
        v34 = v4 - (_DWORD)v29;
        n4_1 = n4_3;
        n4_6 = ((unsigned int)(n4 - n4_5 - 4) >> 2) + 1;
        v35 = &v29[n4_5 / 4u].m128_i32[1];
        n4_4 = n4_1;
        n4_5 += 4 * n4_6;
        v6 = (float *)a3;
        do
        {
          v37 = *(float *)(n4_4 - 12) - *((float *)v35 - 1);
          v35 += 4;
          n4_4 += 16;
          v38 = n4_6-- == 1;
          *((float *)v35 - 5) = v37;
          *((float *)v35 - 4) = *(float *)((char *)v35 + v34 - 16) - *((float *)v35 - 4);
          *((float *)v35 - 3) = *(float *)(n4_4 - 20) - *((float *)v35 - 3);
          *((float *)v35 - 2) = *(float *)(n4_4 - 16) - *((float *)v35 - 2);
        }
        while ( !v38 );
        v4 = v51;
        v29 = v54;
      }
      if ( n4_5 < n4 )
      {
        m128_f32 = v29[n4_5 / 4u].m128_f32;
        v40 = v4 - (_DWORD)v29;
        v41 = n4 - n4_5;
        do
        {
          v42 = *(float *)((char *)m128_f32 + v40) - *m128_f32;
          *m128_f32++ = v42;
          --v41;
        }
        while ( v41 );
      }
    }
    v43 = (char *)v54 - (char *)v6;
    do
    {
      n39 = (int)(*v6 + 0.5);
      if ( n39 < 40 )
      {
        if ( n39 < 0 )
          n39 = 0;
      }
      else
      {
        n39 = 39;
      }
      ++v6;
      result = v52[1];
      *(v6 - 1) = *(float *)(result + 4 * n39 + 336) + *(float *)((char *)v6 + v43 - 4);
      --n4;
    }
    while ( n4 );
  }
  return result;
}


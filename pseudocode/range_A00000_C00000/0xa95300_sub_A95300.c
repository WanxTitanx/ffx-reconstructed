// Function: sub_A95300
// Address: 0xa95300
// Size: 0x342
// Prototype: __m128 __cdecl(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int n1000, int n16, size_t Size)

void __usercall sub_A95300(
        int a1@<edx>,
        int a2@<ecx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>,
        int a6,
        float *a7,
        int a8,
        int a9,
        int a10,
        int n1000,
        int n16,
        size_t Size)
{
  int v13; // eax
  int n16_1; // edi
  void *v15; // esp
  int v16; // edx
  int n16_3; // ecx
  float v18; // xmm0_4
  unsigned int v19; // ecx
  float *v20; // esi
  double v21; // xmm0_8
  int v22; // eax
  int *v23; // esi
  size_t n16_4; // edi
  float v25; // xmm1_4
  void *Base; // eax
  double v27; // xmm0_8
  int v28; // eax
  int n16_5; // esi
  int n16_6; // edx
  float v31; // xmm1_4
  int v32; // ecx
  _DWORD Base_2[2]; // [esp+8h] [ebp-54h] BYREF
  double v34; // [esp+10h] [ebp-4Ch]
  double v35; // [esp+18h] [ebp-44h]
  double v36; // [esp+20h] [ebp-3Ch]
  int v37; // [esp+2Ch] [ebp-30h]
  int v38; // [esp+30h] [ebp-2Ch]
  int v39; // [esp+34h] [ebp-28h]
  int v40; // [esp+38h] [ebp-24h]
  size_t v41; // [esp+3Ch] [ebp-20h]
  _DWORD *Base_1; // [esp+40h] [ebp-1Ch]
  unsigned int v43; // [esp+44h] [ebp-18h]
  float v44; // [esp+48h] [ebp-14h]
  size_t n16_2; // [esp+4Ch] [ebp-10h]
  int v46; // [esp+50h] [ebp-Ch]
  void *v47; // [esp+54h] [ebp-8h]
  void *retaddr; // [esp+5Ch] [ebp+0h]

  v46 = a3;
  v47 = retaddr;
  v13 = *(_DWORD *)(a2 + 4);
  Base_2[1] = a5;
  Base_2[0] = a4;
  n16_1 = n16;
  v39 = v13;
  v37 = a1;
  v15 = alloca(4 * n16);
  Base_1 = Base_2;
  if ( *(_DWORD *)(v13 + 500) )
  {
    n16_1 = *(_DWORD *)(v13 + 504) - n1000;
    if ( n16_1 > n16 )
      n16_1 = n16;
  }
  v16 = a9;
  n16_3 = 0;
  v18 = 0.0;
  v44 = 0.0;
  n16_2 = 0;
  if ( n16_1 > 0 )
  {
    v43 = a9 - (_DWORD)a7;
    v40 = a8 - (_DWORD)a7;
    v38 = a6 - (_DWORD)a7;
    v41 = Size - (_DWORD)a7;
    v19 = a9 - (_DWORD)a7;
    v20 = a7;
    n16_2 = n16_1;
    do
    {
      if ( !v16 || !*(_DWORD *)((char *)v20 + v19) )
      {
        v21 = (float)(*v20 / *(float *)((char *)v20 + v40));
        if ( *(float *)((char *)v20 + v38) >= 0.0 )
        {
          libm_sse2_sqrt_precise();
          v34 = v21 + 0.5;
          v22 = (int)floor(v21 + 0.5);
        }
        else
        {
          libm_sse2_sqrt_precise();
          v36 = v21 + 0.5;
          v35 = floor(v21 + 0.5);
          v22 = (int)-v35;
        }
        v16 = a9;
        *(_DWORD *)((char *)v20 + v41) = v22;
        v19 = v43;
      }
      ++v20;
      --n16_1;
    }
    while ( n16_1 );
    v18 = v44;
    n16_3 = n16_2;
  }
  if ( n16_3 < n16 )
  {
    v23 = (int *)(Size + 4 * n16_3);
    v38 = v16 - a6;
    v41 = a6 - Size;
    v40 = a8 - Size;
    v43 = (unsigned int)a7 - Size;
    n16_4 = 0;
    while ( 1 )
    {
      if ( v16 )
      {
        n16_3 = n16_2;
        if ( *(int *)((char *)v23 + v38 + v41) )
          goto LABEL_26;
      }
      v25 = *(float *)((char *)v23 + v43) / *(float *)((char *)v23 + v40);
      if ( v25 >= 0.25 || a9 && n16_3 < v37 - n1000 )
        break;
      Base = Base_1;
      v18 = v18 + v25;
      Base_1[n16_4] = (char *)v23 + v43;
      v16 = a9;
      ++n16_4;
      v44 = v18;
LABEL_27:
      ++n16_3;
      ++v23;
      n16_2 = n16_3;
      if ( n16_3 >= n16 )
      {
        n16_2 = n16_4;
        if ( n16_4 )
        {
          n16_5 = n16_2;
          qsort(Base, n16_2, 4u, sub_A956E0);
          n16_6 = 0;
          if ( n16_5 > 0 )
          {
            v31 = v44;
            do
            {
              v32 = (Base_1[n16_6] - (int)a7) >> 2;
              if ( v31 < *(double *)(v39 + 512) )
              {
                *(_DWORD *)(Size + 4 * v32) = 0;
                a7[v32] = 0.0;
              }
              else
              {
                v43 = *(unsigned int *)(a6 + 4 * v32);
                v43 = v43 & 0x80000000 | 0x3F800000;
                v31 = v31 - 1.0;
                *(_DWORD *)(Size + 4 * v32) = (int)*(float *)&v43;
                n16_5 = n16_2;
                a7[v32] = *(float *)(a8 + 4 * v32);
              }
              ++n16_6;
            }
            while ( n16_6 < n16_5 );
          }
        }
        return;
      }
    }
    v27 = v25;
    if ( *(float *)((char *)v23 + v41) >= 0.0 )
    {
      libm_sse2_sqrt_precise();
      v36 = v27 + 0.5;
      v28 = (int)floor(v27 + 0.5);
    }
    else
    {
      libm_sse2_sqrt_precise();
      v34 = v27 + 0.5;
      v35 = floor(v27 + 0.5);
      v28 = (int)-v35;
    }
    *v23 = v28;
    n16_3 = n16_2;
    v16 = a9;
    *(float *)((char *)v23 + v43) = (float)(v28 * v28) * *(float *)((char *)v23 + v40);
    v18 = v44;
LABEL_26:
    Base = Base_1;
    goto LABEL_27;
  }
}


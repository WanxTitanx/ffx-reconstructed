// Function: sub_A80CE4
// Address: 0xa80ce4
// Size: 0xd0
// Prototype: 

int __cdecl sub_A80CE4(unsigned int *a1, int a2, unsigned int **a3, int a4)
{
  unsigned int *v4; // edx
  unsigned int *v5; // edi
  unsigned int *v6; // et0
  __m64 v7; // mm0
  __m64 v8; // mm1
  __m64 v9; // mm4
  __m64 v10; // mm5
  __m64 v11; // mm6
  unsigned int *v12; // edx
  unsigned int *v13; // ebx
  unsigned int *v14; // edi
  __m64 v15; // mm0
  __m64 v16; // mm3
  __m64 v17; // mm7
  _DWORD *v19; // esi
  __m64 v20; // mm2
  __m64 v21; // mm1
  __m64 v22; // mm7
  int v23; // [esp+0h] [ebp-10h]

  v4 = a3[1];
  v5 = a3[3];
  v6 = a3[2];
  v7 = _m_punpcklbw(_mm_cvtsi32_si64(*a1), _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + a2)));
  v8 = _m_psadbw(_m_punpcklbw(_mm_cvtsi32_si64(**a3), _mm_cvtsi32_si64(*(unsigned int *)((char *)*a3 + a4))), v7);
  v9 = _m_psadbw(_m_punpcklbw(_mm_cvtsi32_si64(*v4), _mm_cvtsi32_si64(*(unsigned int *)((char *)v4 + a4))), v7);
  v10 = _m_psadbw(_m_punpcklbw(_mm_cvtsi32_si64(*v6), _mm_cvtsi32_si64(*(unsigned int *)((char *)v6 + a4))), v7);
  v11 = _m_psadbw(_m_punpcklbw(_mm_cvtsi32_si64(*v5), _mm_cvtsi32_si64(*(unsigned int *)((char *)v5 + a4))), v7);
  v12 = (unsigned int *)((char *)v4 + 2 * a4);
  v13 = (unsigned int *)((char *)v6 + 2 * a4);
  v14 = (unsigned int *)((char *)v5 + 2 * a4);
  v15 = _m_punpcklbw(
          _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 2 * a2)),
          _mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + 2 * a2 + a2)));
  v16 = _mm_cvtsi32_si64(*v12);
  v17 = _mm_cvtsi32_si64(*v13);
  v19 = *(_DWORD **)(v23 + 24);
  *v19 = _mm_cvtsi64_si32(
           _m_paddw(
             v8,
             _m_psadbw(
               _m_punpcklbw(
                 _mm_cvtsi32_si64(*(unsigned int *)((char *)*a3 + 2 * a4)),
                 _mm_cvtsi32_si64(*(unsigned int *)((char *)*a3 + 2 * a4 + a4))),
               v15)));
  v20 = _mm_cvtsi32_si64(*v14);
  v21 = _mm_cvtsi32_si64(*(unsigned int *)((char *)v14 + a4));
  v22 = _m_paddw(_m_psadbw(_m_punpcklbw(v17, _mm_cvtsi32_si64(*(unsigned int *)((char *)v13 + a4))), v15), v10);
  v19[1] = _mm_cvtsi64_si32(_m_paddw(_m_psadbw(_m_punpcklbw(v16, _mm_cvtsi32_si64(*(unsigned int *)((char *)v12 + a4))), v15), v9));
  v19[2] = _mm_cvtsi64_si32(v22);
  v19[3] = _mm_cvtsi64_si32(_m_paddw(_m_psadbw(_m_punpcklbw(v20, v21), v15), v11));
  return a4;
}


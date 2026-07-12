// Function: sub_A8202B
// Address: 0xa8202b
// Size: 0xe6
// Prototype: 

char *__cdecl sub_A8202B(unsigned int *a1, int a2, _DWORD *a3, int a4, int a5, int a6)
{
  __m64 *v6; // eax
  __m64 m64_u64; // mm5
  __m64 v10; // mm6
  __m64 v11; // mm7
  unsigned int *v12; // esi
  char *result; // eax
  __m64 v14; // mm3
  __m64 v15; // mm2
  __m64 v16; // mm1
  __m64 v17; // mm2
  __m64 v18; // mm6
  __m64 v19; // mm7
  unsigned int *v20; // esi
  __m64 v21; // mm3
  __m64 v22; // mm2
  __m64 v23; // mm2

  v6 = (__m64 *)((char *)&unk_25D7460 + 16 * a6);
  if ( v6->m64_i32[0] )
  {
    m64_u64 = (__m64)v6->m64_u64;
    v10 = v6[32];
    v11 = v6[16];
    v12 = a1;
    result = (char *)a1 + a2;
    do
    {
      v14 = _mm_maddubs_pi16(
              _m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)v12 + 2 * a2)), _mm_cvtsi32_si64(v12[a2])),
              v10);
      v15 = _mm_maddubs_pi16(
              _m_punpcklbw(
                _mm_cvtsi32_si64(*(unsigned int *)((char *)v12 + a2)),
                _mm_cvtsi32_si64(*(_DWORD *)&result[2 * a2])),
              v11);
      v16 = _mm_maddubs_pi16(
              _m_punpcklbw(_mm_cvtsi32_si64(*v12), _mm_cvtsi32_si64(*(_DWORD *)&result[4 * a2])),
              m64_u64);
      v12 = (unsigned int *)((char *)v12 + a2);
      result += a2;
      v17 = _m_psrawi(_m_paddsw(_m_paddsw(_m_paddsw(v15, v14), v16), (__m64)0x40004000400040LL), 7u);
      *a3 = _mm_cvtsi64_si32(_m_packuswb(v17, v17));
      a3 = (_DWORD *)((char *)a3 + a4);
      --a5;
    }
    while ( a5 );
  }
  else
  {
    v18 = v6[32];
    v19 = v6[16];
    v20 = a1;
    result = (char *)a1 + a2;
    do
    {
      v21 = _mm_maddubs_pi16(
              _m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)v20 + 2 * a2)), _mm_cvtsi32_si64(v20[a2])),
              v18);
      v22 = _mm_maddubs_pi16(
              _m_punpcklbw(
                _mm_cvtsi32_si64(*(unsigned int *)((char *)v20 + a2)),
                _mm_cvtsi32_si64(*(_DWORD *)&result[2 * a2])),
              v19);
      v20 = (unsigned int *)((char *)v20 + a2);
      result += a2;
      v23 = _m_psrawi(_m_paddsw(_m_paddsw(v22, v21), (__m64)0x40004000400040LL), 7u);
      *a3 = _mm_cvtsi64_si32(_m_packuswb(v23, v23));
      a3 = (_DWORD *)((char *)a3 + a4);
      --a5;
    }
    while ( a5 );
  }
  return result;
}


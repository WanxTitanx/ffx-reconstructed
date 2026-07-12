// Function: sub_A8BF22
// Address: 0xa8bf22
// Size: 0xca
// Prototype: 

int __cdecl sub_A8BF22(unsigned int *a1, int a2, unsigned int *a3, int a4, _DWORD *a5, _DWORD *a6)
{
  __m64 v6; // mm0
  __m64 v7; // mm5
  __m64 v8; // mm7
  __m64 v9; // mm0
  __m64 v10; // mm5
  unsigned int *v11; // ebx
  unsigned int *v12; // eax
  __m64 v13; // mm7
  __m64 v14; // mm0
  __m64 v15; // mm5
  __m64 v16; // mm7
  __m64 v17; // mm0
  __m64 v18; // kr00_8
  __m64 v20; // [esp+8h] [ebp-14h]

  v6 = _m_psubsw(_m_punpcklbw(_mm_cvtsi32_si64(*a1), 0), _m_punpcklbw(_mm_cvtsi32_si64(*a3), 0));
  v7 = _m_paddw(0, v6);
  v8 = _m_paddd(0, _m_pmaddwd(v6, v6));
  v9 = _m_psubsw(
         _m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)a1 + a2)), 0),
         _m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)a3 + a4)), 0));
  v10 = _m_paddw(v7, v9);
  v11 = (unsigned int *)((char *)a3 + a4 + a4);
  v12 = (unsigned int *)((char *)a1 + a2 + a2);
  v13 = _m_paddd(v8, _m_pmaddwd(v9, v9));
  v14 = _m_psubsw(_m_punpcklbw(_mm_cvtsi32_si64(*v12), 0), _m_punpcklbw(_mm_cvtsi32_si64(*v11), 0));
  v15 = _m_paddw(v10, v14);
  v16 = _m_paddd(v13, _m_pmaddwd(v14, v14));
  v17 = _m_psubsw(
          _m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)v12 + a2)), 0),
          _m_punpcklbw(_mm_cvtsi32_si64(*(unsigned int *)((char *)v11 + a4)), 0));
  v20 = _m_paddw(v15, v17);
  v18 = _m_paddd(v16, _m_pmaddwd(v17, v17));
  *a5 = v18.m64_i32[1] + v18.m64_i32[0];
  *a6 = v20.m64_i16[3] + v20.m64_i16[2] + v20.m64_i16[1] + v20.m64_i16[0];
  return 0;
}


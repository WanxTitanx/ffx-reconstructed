// Function: sub_A8AEC0
// Address: 0xa8aec0
// Size: 0x199
// Prototype: 

int __cdecl sub_A8AEC0(_QWORD *a1, int a2, int a3, int a4, __int32 a5)
{
  __int64 *v5; // edi
  __int64 v6; // mm1
  int n8; // ecx
  _QWORD *v8; // edi
  __int64 v9; // mm1
  int n8_1; // ecx
  unsigned int *v11; // esi
  int result; // eax
  __m64 v13; // mm5
  __m64 v14; // mm6
  __m64 v15; // mm7
  unsigned int *v16; // edi
  int n15; // ecx
  __m64 v18; // mm1
  __m64 v19; // mm2
  int n8_2; // edx
  __m64 v21; // mm1
  __m64 v22; // mm2
  __m64 v23; // mm4
  __m64 v24; // mm2
  __m64 v25; // mm4
  __m64 v26; // mm2
  __m64 v27; // mm3
  __m64 v28; // mm2
  _DWORD v29[32]; // [esp+0h] [ebp-A0h]
  __m64 v30; // [esp+80h] [ebp-20h]
  int *v31; // [esp+88h] [ebp-18h]
  int v32; // [esp+98h] [ebp-8h] BYREF
  int n8_3; // [esp+B0h] [ebp+10h]

  v31 = &v32;
  v30.m64_i32[0] = a5;
  v30.m64_i32[1] = a5;
  n8_3 = a3 + 8;
  do
  {
    v5 = (_QWORD *)((char *)a1 + a2 * (n8_3 - 9));
    v6 = *v5;
    n8 = 8;
    do
    {
      v5 = (__int64 *)((char *)v5 + a2);
      *v5 = v6;
      --n8;
    }
    while ( n8 );
    v8 = a1;
    v9 = *a1;
    n8_1 = 8;
    do
    {
      v8 = (_QWORD *)((char *)v8 - a2);
      *v8 = v9;
      --n8_1;
    }
    while ( n8_1 );
    v11 = (unsigned int *)&a1[-a2];
    result = a2;
    v13.m64_u64 = 0;
    v14.m64_u64 = 0;
    v15.m64_u64 = 0;
    v16 = v11;
    n15 = 15;
    do
    {
      v18 = _m_punpcklbw(_mm_cvtsi32_si64(*v16), 0);
      v13 = _m_paddw(v13, v18);
      v19 = _m_pmullw(v18, v18);
      v14 = _m_paddd(v14, _m_punpcklwd(v19, 0));
      v15 = _m_paddd(v15, _m_punpckhwd(v19, 0));
      v16 = (unsigned int *)((char *)v16 + a2);
      --n15;
    }
    while ( n15 );
    n8_2 = 0;
    do
    {
      v21 = _m_punpcklbw(_mm_cvtsi32_si64(*v11), 0);
      v22 = _m_punpcklbw(_mm_cvtsi32_si64(*v16), 0);
      v13 = _m_psubw(_m_paddw(v13, v22), v21);
      v23 = _m_pmullw(v22, v22);
      v24 = _m_pmullw(v21, v21);
      v14 = _m_psubd(_m_paddd(v14, _m_punpcklwd(v23, 0)), _m_punpcklwd(v24, 0));
      v15 = _m_psubd(_m_paddd(v15, _m_punpckhwd(v23, 0)), _m_punpckhwd(v24, 0));
      v25 = _m_pmulhw(v13, v13);
      v26 = _m_pmullw(v13, v13);
      v27 = _m_packsswb(
              _m_packssdw(
                _m_psradi(_m_psubd(_m_psubd(_m_psubd(_m_pslldi(v14, 4u), v14), _m_punpcklwd(v26, v25)), v30), 0x1Fu),
                _m_psradi(_m_psubd(_m_psubd(_m_psubd(_m_pslldi(v15, 4u), v15), _m_punpckhwd(v26, v25)), v30), 0x1Fu)),
              0);
      v28 = _mm_cvtsi32_si64(v11[2 * a2]);
      v29[n8_2 & 0xF] = _mm_cvtsi64_si32(
                          _m_por(
                            _m_pand(
                              _m_packuswb(
                                _m_psrawi(
                                  _m_paddw(
                                    _m_paddw(_m_punpcklbw(v28, 0), v13),
                                    *(__m64 *)((char *)&xmmword_B7F7D8 + 2 * (n8_2 & 0x7F))),
                                  4u),
                                0),
                              v27),
                            _m_pandn(v27, v28)));
      if ( n8_2 >= 8 )
        *v11 = _mm_cvtsi64_si32(_mm_cvtsi32_si64(v29[((_BYTE)n8_2 - 8) & 0xF]));
      v11 = (unsigned int *)((char *)v11 + a2);
      v16 = (unsigned int *)((char *)v16 + a2);
      ++n8_2;
    }
    while ( n8_2 < n8_3 );
    a1 = (_QWORD *)((char *)a1 + 4);
    a4 -= 4;
  }
  while ( a4 > 0 );
  return result;
}


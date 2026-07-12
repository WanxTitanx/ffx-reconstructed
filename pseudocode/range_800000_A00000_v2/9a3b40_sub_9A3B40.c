// Function: sub_9A3B40
// Address: 0x9a3b40
void __userpurge sub_9A3B40(float a1@<ecx>, int a2@<ebp>, __int32 a3, int a4, int a5, int a6)
{
  bool v6; // zf
  char v8; // dl
  __m128 *dst; // edx
  double v10; // st7
  double v11; // st6
  double v12; // st6
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // ecx
  int v17; // eax
  int v18; // [esp-4h] [ebp-84h]
  __m128 src_; // [esp+14h] [ebp-6Ch] BYREF
  __m128 v20; // [esp+24h] [ebp-5Ch]
  __m128 v21; // [esp+34h] [ebp-4Ch]
  float v22; // [esp+44h] [ebp-3Ch]
  float v23; // [esp+48h] [ebp-38h]
  float v24; // [esp+4Ch] [ebp-34h]
  float v25; // [esp+54h] [ebp-2Ch] BYREF
  float v26; // [esp+58h] [ebp-28h]
  float v27; // [esp+5Ch] [ebp-24h] BYREF
  float v28; // [esp+60h] [ebp-20h]
  char v29; // [esp+73h] [ebp-Dh]
  int v30; // [esp+74h] [ebp-Ch]
  void *v31; // [esp+78h] [ebp-8h]
  void *retaddr; // [esp+80h] [ebp+0h]

  v30 = a2;
  v31 = retaddr;
  v6 = *(_DWORD *)(a3 + 60) == 2;
  v29 = 0;
  src_.m128_u64[0] = *(_QWORD *)a4;
  src_.m128_u64[1] = *(_QWORD *)(a4 + 8);
  v20.m128_u64[0] = *(_QWORD *)a5;
  v20.m128_u64[1] = *(_QWORD *)(a5 + 8);
  if ( v6 )
  {
    sub_989750((int *)(LODWORD(a1) + 44), *(_DWORD **)(a3 + 48));
    *(_DWORD *)(a3 + 48) = sub_988CC0((_DWORD *)(LODWORD(a1) + 4), &src_, a3);
    v8 = 1;
  }
  else
  {
    ++*(_DWORD *)(LODWORD(a1) + 128);
    dst = *(__m128 **)(a3 + 48);
    v21 = _mm_or_ps(_mm_cmplt_ps(dst[1], src_), _mm_cmplt_ps(v20, *dst));
    if ( v21.m128_i32[2] | v21.m128_i32[1] | v21.m128_i32[0] )
    {
      sub_98A770((int *)(LODWORD(a1) + 4), dst, &src_);
      ++*(_DWORD *)(LODWORD(a1) + 132);
      v8 = 1;
    }
    else
    {
      v28 = *(float *)(a3 + 16);
      v10 = v28;
      v21.m128_f32[0] = *(float *)a4 - v28;
      v28 = *(float *)(a3 + 20);
      v11 = v28;
      v21.m128_f32[1] = *(float *)(a4 + 4) - v28;
      v28 = *(float *)(a3 + 24);
      v21.m128_f32[2] = *(float *)(a4 + 8) - v28;
      v25 = *(float *)(a3 + 32) - v10;
      v26 = *(float *)(a3 + 36) - v11;
      v27 = *(float *)(a3 + 40) - v28;
      v22 = v25 * 0.5;
      v23 = v26 * 0.5;
      v24 = 0.5 * v27;
      v12 = *(float *)(LODWORD(a1) + 100);
      v28 = 0.0;
      v25 = v22 * v12;
      v26 = v23 * v12;
      v27 = v12 * v24;
      if ( v21.m128_f32[0] < 0.0 )
        v25 = -v25;
      if ( v21.m128_f32[1] < 0.0 )
        v26 = -v26;
      if ( v21.m128_f32[2] < 0.0 )
        v27 = -v27;
      if ( sub_98A920((int *)(LODWORD(a1) + 4), dst->m128_f32, src_.m128_f32, &v25, 0.050000001) )
      {
        ++*(_DWORD *)(LODWORD(a1) + 132);
        v8 = 1;
      }
      else
      {
        v8 = v29;
      }
    }
  }
  v13 = *(_DWORD *)(a3 + 52);
  v14 = *(_DWORD *)(a3 + 56);
  if ( v13 )
    *(_DWORD *)(v13 + 56) = v14;
  else
    *(_DWORD *)(LODWORD(a1) + 4 * *(_DWORD *)(a3 + 60) + 84) = v14;
  v15 = *(_DWORD *)(a3 + 56);
  if ( v15 )
    *(_DWORD *)(v15 + 52) = *(_DWORD *)(a3 + 52);
  *(_DWORD *)(a3 + 16) = *(_DWORD *)a4;
  *(_DWORD *)(a3 + 20) = *(_DWORD *)(a4 + 4);
  *(_DWORD *)(a3 + 24) = *(_DWORD *)(a4 + 8);
  *(_DWORD *)(a3 + 28) = *(_DWORD *)(a4 + 12);
  *(_DWORD *)(a3 + 32) = *(_DWORD *)a5;
  *(_DWORD *)(a3 + 36) = *(_DWORD *)(a5 + 4);
  *(_DWORD *)(a3 + 40) = *(_DWORD *)(a5 + 8);
  *(_DWORD *)(a3 + 44) = *(_DWORD *)(a5 + 12);
  *(_DWORD *)(a3 + 60) = *(_DWORD *)(LODWORD(a1) + 104);
  v16 = *(_DWORD *)(LODWORD(a1) + 104);
  *(_DWORD *)(a3 + 52) = 0;
  *(_DWORD *)(a3 + 56) = *(_DWORD *)(LODWORD(a1) + 4 * v16 + 84);
  v17 = *(_DWORD *)(LODWORD(a1) + 4 * v16 + 84);
  if ( v17 )
    *(_DWORD *)(v17 + 52) = a3;
  *(_DWORD *)(LODWORD(a1) + 4 * v16 + 84) = a3;
  if ( v8 )
  {
    v6 = *(_BYTE *)(LODWORD(a1) + 153) == 0;
    *(_BYTE *)(LODWORD(a1) + 154) = 1;
    if ( v6 )
    {
      v18 = *(_DWORD *)(a3 + 48);
      v27 = a1;
      sub_9A1D10(LODWORD(a1) + 44, *(_DWORD *)(LODWORD(a1) + 44), v18, (int)&v27);
      sub_9A1D10(LODWORD(a1) + 4, *(_DWORD *)(LODWORD(a1) + 4), *(_DWORD *)(a3 + 48), (int)&v27);
    }
  }
}

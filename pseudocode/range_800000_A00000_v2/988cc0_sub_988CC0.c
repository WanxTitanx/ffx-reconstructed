// Function: sub_988CC0
// Address: 0x988cc0
__m128 *__thiscall sub_988CC0(_DWORD *this, const void *src, __int32 a3)
{
  int *this_1; // edx
  __m128 *dst; // ebx
  int dst_1; // eax

  this_1 = this;
  dst = (__m128 *)*(this + 1);
  if ( dst )
  {
    *(this + 1) = 0;
  }
  else
  {
    dst_1 = sub_9D4CE0(48, 16);
    this_1 = this;
    dst = (__m128 *)dst_1;
  }
  dst[2].m128_i32[0] = 0;
  dst[2].m128_i32[1] = a3;
  dst[2].m128_i32[2] = 0;
  qmemcpy(dst, src, 0x20u);
  sub_988D30(this_1, *this_1, dst);
  ++*(this + 3);
  return dst;
}

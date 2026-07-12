// Function: sub_9A3560
// Address: 0x9a3560
int __userpurge sub_9A3560@<eax>(int a1@<ecx>, int a2@<ebp>, _OWORD *a3, int a4)
{
  __m128 *src; // esi
  __m128 *v5; // eax
  int result; // eax
  int v7; // [esp+14h] [ebp-4Ch] BYREF
  _OWORD dst[2]; // [esp+34h] [ebp-2Ch] BYREF
  int v9; // [esp+54h] [ebp-Ch]
  void *v10; // [esp+58h] [ebp-8h]
  void *retaddr; // [esp+60h] [ebp+0h]

  v9 = a2;
  v10 = retaddr;
  src = *(__m128 **)(a1 + 4);
  if ( !src )
  {
    src = *(__m128 **)(a1 + 44);
    if ( !src )
    {
      memset(&dst[1], 0, sizeof(_OWORD));
      src = (__m128 *)sub_9A2DB0((int)&v7, (float *)&dst[1], 0.0);
    }
    goto LABEL_6;
  }
  v5 = *(__m128 **)(a1 + 44);
  if ( !v5 )
  {
LABEL_6:
    qmemcpy(dst, src, sizeof(dst));
    goto LABEL_7;
  }
  dst[0] = _mm_min_ps(*src, *v5);
  dst[1] = _mm_max_ps(src[1], v5[1]);
LABEL_7:
  *a3 = dst[0];
  *(_QWORD *)a4 = *(_QWORD *)&dst[1];
  *(_DWORD *)(a4 + 8) = DWORD2(dst[1]);
  result = HIDWORD(dst[1]);
  *(_DWORD *)(a4 + 12) = HIDWORD(dst[1]);
  return result;
}

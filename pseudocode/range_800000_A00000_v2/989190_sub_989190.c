// Function: sub_989190
// Address: 0x989190
void __userpurge sub_989190(int *a1@<ecx>, int a2@<ebp>, int a3)
{
  int v3; // edi
  int *v4; // esi
  __m128 *src_1; // eax
  int v6; // ecx
  __int32 *src; // edx
  __int32 v8; // edi
  __m128 *src_3; // ecx
  __m128 *src_4; // esi
  unsigned int v11; // eax
  __m128 *v12; // eax
  _BYTE dst[32]; // [esp-40h] [ebp-4Ch] BYREF
  int *v14; // [esp-14h] [ebp-20h]
  int v15; // [esp-10h] [ebp-1Ch]
  int v16; // [esp-Ch] [ebp-18h]
  __m128 *src_2; // [esp-8h] [ebp-14h]
  BOOL v18; // [esp-4h] [ebp-10h]
  _DWORD v19[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v19[0] = a2;
  v19[1] = retaddr;
  v3 = a3;
  v4 = a1;
  v14 = a1;
  if ( a3 < 0 )
  {
    v3 = a1[3];
    a3 = v3;
  }
  if ( *a1 && v3 > 0 )
  {
    do
    {
      LOBYTE(v6) = 0;
      src_2 = (__m128 *)*v4;
      src_1 = src_2;
      v16 = 0;
      if ( src_2[2].m128_i32[2] )
      {
        do
        {
          src = (__int32 *)src_1[2].m128_i32[0];
          if ( src <= (__int32 *)src_1 )
          {
            src = (__int32 *)src_1;
          }
          else
          {
            v8 = src[8];
            v18 = src[10] == (_DWORD)src_1;
            v15 = 4 * (1 - v18) + 36;
            src_3 = *(__m128 **)((char *)src + v15);
            src_2 = src_3;
            if ( v8 )
            {
              *(_DWORD *)(v8 + 4 * (*(_DWORD *)(v8 + 40) == (_DWORD)src) + 36) = src_1;
              src_3 = src_2;
            }
            else
            {
              *v4 = (int)src_1;
            }
            src_3[2].m128_i32[0] = (__int32)src_1;
            src[8] = (__int32)src_1;
            v6 = src_1[2].m128_i32[1];
            src_4 = src_2;
            src_1[2].m128_i32[0] = v8;
            src[9] = v6;
            src[10] = src_1[2].m128_i32[2];
            *(_DWORD *)(src_1[2].m128_i32[1] + 32) = src;
            *(_DWORD *)(src_1[2].m128_i32[2] + 32) = src;
            src_1[2].m128_i32[v18 + 1] = (__int32)src;
            *(__int32 *)((char *)src_1->m128_i32 + v15) = (__int32)src_4;
            qmemcpy(dst, src, sizeof(dst));
            qmemcpy(src, src_1, 0x20u);
            qmemcpy(src_1, dst, 0x20u);
            LOBYTE(v6) = v16;
            v4 = v14;
          }
          v11 = (unsigned int)v4[4] >> v6;
          v6 = ((_BYTE)v6 + 1) & 0x1F;
          v16 = v6;
          src_1 = (__m128 *)src[(v11 & 1) + 9];
        }
        while ( src_1[2].m128_i32[2] );
        v3 = a3;
        src_2 = src_1;
      }
      v12 = sub_989780((int)v19, v4, src_1);
      if ( v12 )
        v12 = (__m128 *)*v4;
      sub_988D30(v4, (__int32)v12, src_2);
      ++v4[4];
      a3 = --v3;
    }
    while ( v3 );
  }
}

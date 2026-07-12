// Function: sub_9A2090
// Address: 0x9a2090
int __userpurge sub_9A2090@<eax>(int a1@<ebp>, int a2, const void *src, _DWORD *a4)
{
  int n64_3; // eax
  _DWORD *n64_8; // edi
  int n64; // ecx
  int n64_4; // esi
  __m128 *v8; // edx
  int *n64_15; // ecx
  char *v10; // edi
  int n64_16; // edx
  int *v12; // edx
  int n64_11; // esi
  int n64_6; // ecx
  _DWORD *n64_7; // eax
  char *v16; // edi
  int n64_17; // edx
  int *v18; // ecx
  __m128 dst[2]; // [esp-1Ch] [ebp-8Ch] BYREF
  int n64_13; // [esp+14h] [ebp-5Ch]
  int n64_1; // [esp+18h] [ebp-58h]
  _DWORD *n64_10; // [esp+1Ch] [ebp-54h]
  char v23; // [esp+20h] [ebp-50h]
  __m128 v24; // [esp+24h] [ebp-4Ch]
  _DWORD *n64_14; // [esp+40h] [ebp-30h]
  __m128 *v26; // [esp+44h] [ebp-2Ch]
  _DWORD *n64_2; // [esp+48h] [ebp-28h]
  _DWORD *n64_5; // [esp+4Ch] [ebp-24h]
  _DWORD *n64_9; // [esp+50h] [ebp-20h]
  int *v30; // [esp+54h] [ebp-1Ch]
  _DWORD n64_12[2]; // [esp+58h] [ebp-18h] BYREF
  int v32; // [esp+60h] [ebp-10h]
  int v33; // [esp+64h] [ebp-Ch]
  void *v34; // [esp+68h] [ebp-8h]
  int v35; // [esp+6Ch] [ebp-4h] BYREF
  void *retaddr; // [esp+70h] [ebp+0h]

  v33 = a1;
  v34 = retaddr;
  v32 = -1;
  n64_12[1] = &loc_AD9908;
  n64_12[0] = NtCurrentTeb()->NtTib.ExceptionList;
  v30 = &v35;
  n64_3 = (int)n64_12;
  if ( a2 )
  {
    qmemcpy(dst, src, sizeof(dst));
    v23 = 1;
    n64_10 = 0;
    n64_1 = 0;
    v32 = 0;
    n64_13 = 0;
    n64_8 = (_DWORD *)sub_9D4CE0(256, 16);
    n64 = 64;
    n64_9 = n64_8;
    v23 = 1;
    n64_10 = n64_8;
    n64_1 = 64;
    if ( n64_8 )
      *n64_8 = a2;
    n64_4 = 1;
    do
    {
      v8 = (__m128 *)n64_8[--n64_4];
      v24 = _mm_or_ps(_mm_cmplt_ps(dst[1], *v8), _mm_cmplt_ps(v8[1], dst[0]));
      v26 = v8;
      n64_3 = v24.m128_i32[2] | v24.m128_i32[1] | v24.m128_i32[0];
      n64_13 = n64_4;
      if ( !n64_3 )
      {
        if ( v8[2].m128_i32[2] )
        {
          if ( n64_4 == n64 )
          {
            n64_3 = 2 * n64_4;
            if ( !n64_4 )
              n64_3 = 1;
            n64_2 = (_DWORD *)n64_3;
            if ( n64 < n64_3 )
            {
              if ( n64_3 )
                n64_3 = sub_9D4CE0(4 * n64_3, 16);
              else
                n64_3 = 0;
              n64_5 = (_DWORD *)n64_3;
              if ( n64_4 > 0 )
              {
                n64_14 = n64_8;
                n64_15 = (int *)n64_3;
                v10 = (char *)n64_8 - n64_3;
                n64_16 = n64_4;
                do
                {
                  if ( n64_15 )
                  {
                    n64_3 = *(int *)((char *)n64_15 + (_DWORD)v10);
                    *n64_15 = n64_3;
                  }
                  ++n64_15;
                  --n64_16;
                }
                while ( n64_16 );
                n64_8 = n64_9;
              }
              if ( n64_8 )
                n64_3 = sub_9D4D50(n64_8);
              n64_8 = n64_5;
              n64 = (int)n64_2;
              v23 = 1;
              n64_9 = n64_5;
              n64_10 = n64_5;
              n64_1 = (int)n64_2;
            }
          }
          v12 = &n64_8[n64_4];
          if ( v12 )
          {
            n64_3 = v26[2].m128_i32[1];
            *v12 = n64_3;
          }
          n64_11 = n64_4 + 1;
          n64_13 = n64_11;
          if ( n64_11 == n64 )
          {
            n64_3 = 2 * n64_11;
            if ( !n64_11 )
              n64_3 = 1;
            n64_5 = (_DWORD *)n64_3;
            if ( n64 < n64_3 )
            {
              if ( n64_3 )
              {
                n64_6 = sub_9D4CE0(4 * n64_3, 16);
                n64_2 = (_DWORD *)n64_6;
              }
              else
              {
                n64_6 = 0;
                n64_2 = 0;
              }
              if ( n64_11 > 0 )
              {
                n64_14 = n64_8;
                n64_7 = (_DWORD *)n64_6;
                v16 = (char *)n64_8 - n64_6;
                n64_17 = n64_11;
                do
                {
                  if ( n64_7 )
                    *n64_7 = *(_DWORD *)((char *)n64_7 + (_DWORD)v16);
                  ++n64_7;
                  --n64_17;
                }
                while ( n64_17 );
                n64_8 = n64_9;
              }
              if ( n64_8 )
                sub_9D4D50(n64_8);
              n64_8 = n64_2;
              n64_3 = (int)n64_5;
              v23 = 1;
              n64_9 = n64_2;
              n64_10 = n64_2;
              n64_1 = (int)n64_5;
            }
          }
          v18 = &n64_8[n64_11];
          if ( v18 )
          {
            n64_3 = v26[2].m128_i32[2];
            *v18 = n64_3;
          }
          n64_4 = n64_11 + 1;
        }
        else
        {
          n64_3 = (*(int (__thiscall **)(_DWORD, __int32))(*(_DWORD *)*a4 + 4))(*a4, v8[2].m128_i32[1]);
        }
      }
      n64 = n64_1;
    }
    while ( n64_4 > 0 );
    v32 = -1;
    if ( n64_8 )
      return sub_9D4D50(n64_8);
  }
  return n64_3;
}

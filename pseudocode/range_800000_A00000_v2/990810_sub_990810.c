// Function: sub_990810
// Address: 0x990810
int __userpurge sub_990810@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, int a4)
{
  int v4; // esi
  int v5; // ecx
  int v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // ecx
  int n2048; // eax
  int v12; // ecx
  int n2048_1; // ecx
  int dst_10; // ecx
  int dst_9; // eax
  int dst_8; // edi
  char *dst; // eax
  int v18; // ecx
  int v19; // edx
  int dst_4; // eax
  int v21; // edi
  void *dst_1; // edi
  int v23; // ecx
  int n2048_3; // eax
  int dst_7; // ecx
  int dst_5; // edi
  char *dst_2; // eax
  int v28; // ecx
  int v29; // edx
  int v30; // edi
  int v31; // eax
  void *src_1; // edi
  _WORD *v33; // edx
  int v34; // ecx
  _BYTE src[32]; // [esp-50h] [ebp-5Ch] BYREF
  _WORD *v36; // [esp-28h] [ebp-34h]
  int n2048_2; // [esp-24h] [ebp-30h]
  int v38; // [esp-20h] [ebp-2Ch]
  int v39; // [esp-1Ch] [ebp-28h]
  int v40; // [esp-18h] [ebp-24h]
  int dst_3; // [esp-14h] [ebp-20h]
  int dst_6; // [esp-10h] [ebp-1Ch]
  int v43; // [esp-Ch] [ebp-18h]
  int dst_11; // [esp-8h] [ebp-14h]
  int v45; // [esp-4h] [ebp-10h]
  int v46; // [esp+0h] [ebp-Ch]
  void *v47; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v46 = a2;
  v47 = retaddr;
  v4 = a1;
  v5 = *(_DWORD *)(a1 + 148);
  v6 = v5 + 16 * a3;
  v7 = *(_DWORD *)(v6 + 12);
  v45 = v4;
  v38 = v6;
  if ( v7 < 0 )
    v8 = -v7;
  else
    v8 = 1;
  v9 = v5 + 16 * a4;
  v40 = v8;
  v10 = *(_DWORD *)(v9 + 12);
  n2048 = 16 * v8;
  v36 = (_WORD *)v9;
  if ( v10 < 0 )
    v12 = -v10;
  else
    v12 = 1;
  v39 = v12;
  n2048_1 = 16 * v12;
  n2048_2 = n2048_1;
  if ( n2048 <= 2048 )
  {
    dst_10 = *(_DWORD *)(v4 + 164);
    dst_9 = *(_DWORD *)(v4 + 168);
    dst_11 = dst_10;
    if ( dst_10 == dst_9 )
    {
      dst_8 = 2 * dst_10;
      if ( !dst_10 )
        dst_8 = 1;
      dst_6 = dst_8;
      if ( dst_9 < dst_8 )
      {
        if ( dst_8 )
          dst = (char *)sub_9D4CE0(32 * dst_8, 16);
        else
          dst = 0;
        v18 = *(_DWORD *)(v4 + 164);
        dst_3 = (int)dst;
        v43 = v18;
        if ( v18 > 0 )
        {
          v19 = 0;
          do
          {
            if ( dst )
            {
              qmemcpy(dst, (const void *)(v19 + *(_DWORD *)(v4 + 172)), 0x20u);
              v4 = v45;
              v18 = v43;
            }
            v19 += 32;
            dst += 32;
            v43 = --v18;
          }
          while ( v18 );
          dst_8 = dst_6;
        }
        if ( *(_DWORD *)(v4 + 172) )
        {
          if ( *(_BYTE *)(v4 + 176) )
            sub_9D4D50(*(_DWORD *)(v4 + 172));
          *(_DWORD *)(v4 + 172) = 0;
        }
        dst_4 = dst_3;
        v6 = v38;
        dst_10 = dst_11;
        *(_BYTE *)(v4 + 176) = 1;
        *(_DWORD *)(v4 + 172) = dst_4;
        *(_DWORD *)(v4 + 168) = dst_8;
      }
    }
    v21 = *(_DWORD *)(v4 + 172);
    ++*(_DWORD *)(v4 + 164);
    dst_11 = 32 * dst_10;
    dst_1 = (void *)(32 * dst_10 + v21);
    if ( dst_1 )
    {
      qmemcpy(dst_1, src, 0x20u);
      v4 = v45;
    }
    v23 = dst_11 + *(_DWORD *)(v4 + 172);
    *(_WORD *)v23 = *(_WORD *)v6;
    *(_WORD *)(v23 + 2) = *(_WORD *)(v6 + 2);
    *(_WORD *)(v23 + 4) = *(_WORD *)(v6 + 4);
    *(_WORD *)(v23 + 6) = *(_WORD *)(v6 + 6);
    *(_WORD *)(v23 + 8) = *(_WORD *)(v6 + 8);
    *(_WORD *)(v23 + 10) = *(_WORD *)(v6 + 10);
    *(_DWORD *)(v23 + 12) = a3;
    *(_DWORD *)(v23 + 16) = v40;
    n2048_1 = n2048_2;
  }
  n2048_3 = *(_DWORD *)(v4 + 164);
  if ( n2048_1 <= 2048 )
  {
    dst_7 = *(_DWORD *)(v4 + 168);
    n2048_2 = *(_DWORD *)(v4 + 164);
    if ( n2048_3 == dst_7 )
    {
      dst_5 = 2 * n2048_3;
      if ( !n2048_3 )
        dst_5 = 1;
      dst_3 = dst_5;
      if ( dst_7 < dst_5 )
      {
        if ( dst_5 )
          dst_2 = (char *)sub_9D4CE0(32 * dst_5, 16);
        else
          dst_2 = 0;
        v28 = *(_DWORD *)(v4 + 164);
        dst_6 = (int)dst_2;
        v40 = v28;
        if ( v28 > 0 )
        {
          v29 = 0;
          do
          {
            if ( dst_2 )
            {
              qmemcpy(dst_2, (const void *)(v29 + *(_DWORD *)(v4 + 172)), 0x20u);
              v4 = v45;
              v28 = v40;
            }
            v29 += 32;
            dst_2 += 32;
            v40 = --v28;
          }
          while ( v28 );
          dst_5 = dst_3;
        }
        if ( *(_DWORD *)(v4 + 172) )
        {
          if ( *(_BYTE *)(v4 + 176) )
            sub_9D4D50(*(_DWORD *)(v4 + 172));
          *(_DWORD *)(v4 + 172) = 0;
        }
        *(_DWORD *)(v4 + 172) = dst_6;
        n2048_3 = n2048_2;
        *(_BYTE *)(v4 + 176) = 1;
        *(_DWORD *)(v4 + 168) = dst_5;
      }
    }
    v30 = *(_DWORD *)(v4 + 172);
    ++*(_DWORD *)(v4 + 164);
    v31 = 32 * n2048_3;
    src_1 = (void *)(v31 + v30);
    if ( src_1 )
    {
      qmemcpy(src_1, src, 0x20u);
      v4 = v45;
    }
    v33 = v36;
    v34 = v31 + *(_DWORD *)(v4 + 172);
    *(_WORD *)v34 = *v36;
    *(_WORD *)(v34 + 2) = v33[1];
    *(_WORD *)(v34 + 4) = v33[2];
    *(_WORD *)(v34 + 6) = v33[3];
    *(_WORD *)(v34 + 8) = v33[4];
    *(_WORD *)(v34 + 10) = v33[5];
    *(_DWORD *)(v34 + 12) = a4;
    *(_DWORD *)(v34 + 16) = v39;
    n2048_3 = *(_DWORD *)(v4 + 164);
  }
  *(_DWORD *)(v4 + 180) = n2048_3;
  return n2048_3;
}

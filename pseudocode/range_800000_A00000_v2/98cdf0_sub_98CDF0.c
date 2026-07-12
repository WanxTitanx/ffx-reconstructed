// Function: sub_98CDF0
// Address: 0x98cdf0
int __userpurge sub_98CDF0@<eax>(int a1@<ecx>, int a2@<ebp>, int dst_10)
{
  int v3; // esi
  double v4; // st7
  int dst_19; // edi
  int dst_20; // ecx
  char *dst; // eax
  int dst_11; // ecx
  int v9; // edx
  int dst_5; // eax
  int v11; // eax
  int v12; // edx
  void *dst_1; // edi
  int v14; // edx
  char *v15; // ecx
  int v16; // eax
  char *dst_12; // edi
  float *v18; // eax
  bool v19; // zf
  int dst_14; // eax
  int dst_13; // edi
  int dst_21; // ecx
  int dst_6; // eax
  int v24; // edi
  _DWORD *dst_22; // edx
  _DWORD *v26; // ecx
  int v27; // ecx
  int v28; // edx
  _DWORD *v29; // eax
  int v30; // edx
  int v31; // edi
  __int16 v32; // ax
  int dst_9; // eax
  int dst_17; // edi
  int dst_16; // ecx
  char *dst_2; // eax
  int dst_8; // ecx
  int v38; // edx
  int v39; // edx
  void *dst_3; // edi
  int v41; // edx
  int v42; // edi
  __int16 v43; // ax
  _BYTE src[64]; // [esp-60h] [ebp-6Ch] BYREF
  int dst_15; // [esp-14h] [ebp-20h]
  int dst_4; // [esp-10h] [ebp-1Ch]
  char *dst_7; // [esp-Ch] [ebp-18h]
  int v48; // [esp-8h] [ebp-14h]
  int dst_18; // [esp-4h] [ebp-10h]
  int v50; // [esp+0h] [ebp-Ch]
  void *v51; // [esp+4h] [ebp-8h]
  void *retaddr; // [esp+Ch] [ebp+0h]

  v50 = a2;
  v51 = retaddr;
  v3 = a1;
  v4 = *(double *)(dst_10 + 32);
  v48 = a1;
  *(float *)(a1 + 32) = v4;
  *(float *)(a1 + 36) = *(double *)(dst_10 + 40);
  *(float *)(a1 + 40) = *(double *)(dst_10 + 48);
  *(float *)(a1 + 44) = *(double *)(dst_10 + 56);
  *(float *)(a1 + 16) = *(double *)dst_10;
  *(float *)(a1 + 20) = *(double *)(dst_10 + 8);
  *(float *)(a1 + 24) = *(double *)(dst_10 + 16);
  *(float *)(a1 + 28) = *(double *)(dst_10 + 24);
  *(float *)(a1 + 48) = *(double *)(dst_10 + 64);
  *(float *)(a1 + 52) = *(double *)(dst_10 + 72);
  *(float *)(a1 + 56) = *(double *)(dst_10 + 80);
  *(float *)(a1 + 60) = *(double *)(dst_10 + 88);
  *(_DWORD *)(a1 + 68) = *(_DWORD *)(dst_10 + 96);
  *(_BYTE *)(a1 + 72) = *(_DWORD *)(dst_10 + 100) != 0;
  dst_19 = *(_DWORD *)(dst_10 + 104);
  dst_20 = *(_DWORD *)(a1 + 100);
  dst_18 = dst_19;
  dst_15 = dst_20;
  if ( dst_19 >= dst_20 )
  {
    if ( dst_19 > dst_20 && *(_DWORD *)(v3 + 104) < dst_19 )
    {
      if ( dst_19 )
        dst = (char *)sub_9D4CE0(dst_19 << 6, 16);
      else
        dst = 0;
      dst_11 = *(_DWORD *)(v3 + 100);
      dst_4 = (int)dst;
      dst_7 = (char *)dst_11;
      if ( dst_11 > 0 )
      {
        v9 = 0;
        do
        {
          if ( dst )
          {
            qmemcpy(dst, (const void *)(v9 + *(_DWORD *)(v3 + 108)), 0x40u);
            v3 = v48;
            dst_11 = (int)dst_7;
          }
          v9 += 64;
          dst += 64;
          dst_7 = (char *)--dst_11;
        }
        while ( dst_11 );
        dst_19 = dst_18;
      }
      if ( *(_DWORD *)(v3 + 108) )
      {
        if ( *(_BYTE *)(v3 + 112) )
          sub_9D4D50(*(_DWORD *)(v3 + 108));
        *(_DWORD *)(v3 + 108) = 0;
      }
      dst_5 = dst_4;
      dst_20 = dst_15;
      *(_BYTE *)(v3 + 112) = 1;
      *(_DWORD *)(v3 + 108) = dst_5;
      *(_DWORD *)(v3 + 104) = dst_19;
    }
    if ( dst_20 < dst_19 )
    {
      v11 = dst_20 << 6;
      v12 = dst_19 - dst_20;
      do
      {
        dst_1 = (void *)(v11 + *(_DWORD *)(v3 + 108));
        if ( dst_1 )
        {
          qmemcpy(dst_1, src, 0x40u);
          v3 = v48;
        }
        v11 += 64;
        --v12;
      }
      while ( v12 );
      dst_19 = dst_18;
    }
  }
  *(_DWORD *)(v3 + 100) = dst_19;
  if ( dst_19 )
  {
    v14 = *(_DWORD *)(dst_10 + 112);
    if ( dst_19 > 0 )
    {
      v15 = 0;
      dst_7 = 0;
      do
      {
        v16 = *(_DWORD *)(v3 + 108);
        dst_12 = dst_7;
        *(float *)&v15[v16 + 16] = *(double *)(v14 + 32);
        v14 += 80;
        *(float *)&v15[v16 + 20] = *(double *)(v14 - 40);
        *(float *)&v15[v16 + 24] = *(double *)(v14 - 32);
        *(float *)&v15[v16 + 28] = *(double *)(v14 - 24);
        v18 = (float *)&v15[*(_DWORD *)(v3 + 108)];
        *v18 = *(double *)(v14 - 80);
        v18[1] = *(double *)(v14 - 72);
        v18[2] = *(double *)(v14 - 64);
        v18[3] = *(double *)(v14 - 56);
        *(_DWORD *)&dst_12[*(_DWORD *)(v3 + 108) + 32] = *(_DWORD *)(v14 - 16);
        *(_DWORD *)&dst_12[*(_DWORD *)(v3 + 108) + 36] = *(_DWORD *)(v14 - 12);
        *(_DWORD *)&dst_12[*(_DWORD *)(v3 + 108) + 40] = *(_DWORD *)(v14 - 8);
        v15 = dst_12 + 64;
        v19 = dst_18-- == 1;
        dst_7 = dst_12 + 64;
      }
      while ( !v19 );
    }
  }
  dst_14 = *(_DWORD *)(v3 + 140);
  dst_13 = *(_DWORD *)(dst_10 + 108);
  dst_7 = (char *)dst_13;
  dst_15 = dst_14;
  if ( dst_13 >= dst_14 )
  {
    if ( dst_13 > dst_14 && *(_DWORD *)(v3 + 144) < dst_13 )
    {
      if ( dst_13 )
      {
        dst_21 = sub_9D4CE0(16 * dst_13, 16);
        dst_18 = dst_21;
      }
      else
      {
        dst_21 = 0;
        dst_18 = 0;
      }
      dst_6 = *(_DWORD *)(v3 + 140);
      dst_4 = dst_6;
      if ( dst_6 > 0 )
      {
        v24 = 0;
        dst_22 = (_DWORD *)dst_21;
        do
        {
          if ( dst_22 )
          {
            v26 = (_DWORD *)(v24 + *(_DWORD *)(v3 + 148));
            *dst_22 = *v26;
            dst_22[1] = v26[1];
            dst_22[2] = v26[2];
            dst_22[3] = v26[3];
            dst_6 = dst_4;
          }
          v24 += 16;
          dst_22 += 4;
          dst_4 = --dst_6;
        }
        while ( dst_6 );
        dst_13 = (int)dst_7;
      }
      if ( *(_DWORD *)(v3 + 148) )
      {
        if ( *(_BYTE *)(v3 + 152) )
          sub_9D4D50(*(_DWORD *)(v3 + 148));
        *(_DWORD *)(v3 + 148) = 0;
      }
      *(_DWORD *)(v3 + 148) = dst_18;
      dst_14 = dst_15;
      *(_BYTE *)(v3 + 152) = 1;
      *(_DWORD *)(v3 + 144) = dst_13;
    }
    if ( dst_14 < dst_13 )
    {
      v27 = 16 * dst_14;
      v28 = dst_13 - dst_14;
      do
      {
        v29 = (_DWORD *)(v27 + *(_DWORD *)(v3 + 148));
        if ( v29 )
        {
          *v29 = 0;
          v29[1] = 0;
          v29[2] = 0;
          v29[3] = 0;
        }
        v27 += 16;
        --v28;
      }
      while ( v28 );
    }
  }
  *(_DWORD *)(v3 + 140) = dst_13;
  if ( dst_13 )
  {
    v30 = *(_DWORD *)(dst_10 + 116);
    if ( dst_13 > 0 )
    {
      v31 = 0;
      do
      {
        v19 = dst_7-- == (char *)1;
        *(_DWORD *)(*(_DWORD *)(v3 + 148) + v31 + 12) = *(_DWORD *)(v30 + 12);
        v31 += 16;
        *(_WORD *)(*(_DWORD *)(v3 + 148) + v31 - 10) = *(_WORD *)(v30 + 6);
        v32 = *(_WORD *)(v30 + 8);
        v30 += 16;
        *(_WORD *)(*(_DWORD *)(v3 + 148) + v31 - 8) = v32;
        *(_WORD *)(*(_DWORD *)(v3 + 148) + v31 - 6) = *(_WORD *)(v30 - 6);
        *(_WORD *)(v31 + *(_DWORD *)(v3 + 148) - 16) = *(_WORD *)(v30 - 16);
        *(_WORD *)(*(_DWORD *)(v3 + 148) + v31 - 14) = *(_WORD *)(v30 - 14);
        *(_WORD *)(*(_DWORD *)(v3 + 148) + v31 - 12) = *(_WORD *)(v30 - 12);
      }
      while ( !v19 );
    }
  }
  dst_9 = *(_DWORD *)(dst_10 + 120);
  *(_DWORD *)(v3 + 156) = dst_9;
  dst_17 = *(_DWORD *)(dst_10 + 124);
  dst_16 = *(_DWORD *)(v3 + 164);
  dst_18 = dst_17;
  dst_15 = dst_16;
  if ( dst_17 >= dst_16 )
  {
    if ( dst_17 > dst_16 && *(_DWORD *)(v3 + 168) < dst_17 )
    {
      if ( dst_17 )
        dst_2 = (char *)sub_9D4CE0(32 * dst_17, 16);
      else
        dst_2 = 0;
      dst_8 = *(_DWORD *)(v3 + 164);
      dst_7 = dst_2;
      dst_4 = dst_8;
      if ( dst_8 > 0 )
      {
        v38 = 0;
        do
        {
          if ( dst_2 )
          {
            qmemcpy(dst_2, (const void *)(v38 + *(_DWORD *)(v3 + 172)), 0x20u);
            v3 = v48;
            dst_8 = dst_4;
          }
          v38 += 32;
          dst_2 += 32;
          dst_4 = --dst_8;
        }
        while ( dst_8 );
        dst_17 = dst_18;
      }
      if ( *(_DWORD *)(v3 + 172) )
      {
        if ( *(_BYTE *)(v3 + 176) )
          sub_9D4D50(*(_DWORD *)(v3 + 172));
        *(_DWORD *)(v3 + 172) = 0;
      }
      dst_9 = (int)dst_7;
      dst_16 = dst_15;
      *(_BYTE *)(v3 + 176) = 1;
      *(_DWORD *)(v3 + 172) = dst_9;
      *(_DWORD *)(v3 + 168) = dst_17;
    }
    if ( dst_16 < dst_17 )
    {
      dst_9 = 32 * dst_16;
      v39 = dst_17 - dst_16;
      do
      {
        dst_3 = (void *)(dst_9 + *(_DWORD *)(v3 + 172));
        if ( dst_3 )
        {
          qmemcpy(dst_3, &src[32], 0x20u);
          v3 = v48;
        }
        dst_9 += 32;
        --v39;
      }
      while ( v39 );
      dst_17 = dst_18;
    }
  }
  *(_DWORD *)(v3 + 164) = dst_17;
  if ( dst_17 )
  {
    dst_9 = dst_10;
    v41 = *(_DWORD *)(dst_10 + 128);
    if ( dst_17 > 0 )
    {
      v42 = 0;
      do
      {
        v19 = dst_18-- == 1;
        v42 += 32;
        *(_WORD *)(v42 + *(_DWORD *)(v3 + 172) - 26) = *(_WORD *)(v41 + 14);
        v43 = *(_WORD *)(v41 + 16);
        v41 += 20;
        *(_WORD *)(v42 + *(_DWORD *)(v3 + 172) - 24) = v43;
        *(_WORD *)(v42 + *(_DWORD *)(v3 + 172) - 22) = *(_WORD *)(v41 - 2);
        *(_WORD *)(v42 + *(_DWORD *)(v3 + 172) - 32) = *(_WORD *)(v41 - 12);
        *(_WORD *)(v42 + *(_DWORD *)(v3 + 172) - 30) = *(_WORD *)(v41 - 10);
        *(_WORD *)(v42 + *(_DWORD *)(v3 + 172) - 28) = *(_WORD *)(v41 - 8);
        *(_DWORD *)(v42 + *(_DWORD *)(v3 + 172) - 20) = *(_DWORD *)(v41 - 20);
        dst_9 = *(_DWORD *)(v41 - 16);
        *(_DWORD *)(v42 + *(_DWORD *)(v3 + 172) - 16) = dst_9;
      }
      while ( !v19 );
    }
  }
  return dst_9;
}

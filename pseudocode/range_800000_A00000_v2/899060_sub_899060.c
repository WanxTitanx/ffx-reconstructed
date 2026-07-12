// Function: sub_899060
// Address: 0x899060
__int16 sub_899060()
{
  __int16 v0; // dx
  _DWORD *dst_2; // ebx
  int n20; // edi
  int v3; // esi
  int v4; // ebx
  __int16 v5; // cx
  _DWORD *src_1; // eax
  int n20_1; // edi
  int n0x100000; // esi
  bool v9; // zf
  bool v10; // cc
  _DWORD *src_3; // eax
  int n20_2; // edi
  int n0x100000_1; // esi
  int v14; // ecx
  double v15; // st7
  _DWORD *src; // ebx
  int n20_4; // edi
  int n0x100000_2; // esi
  int v19; // ecx
  _DWORD *dst_1; // ebx
  int n20_5; // edi
  int v22; // esi
  int v23; // ebx
  int n20_6; // esi
  int v25; // edx
  int n28_1; // ecx
  __int16 result; // ax
  int n20_7; // edi
  int v29; // esi
  double v30; // st5
  double v31; // st7
  double v32; // st7
  float v33; // [esp+Ch] [ebp-D0h]
  float v34; // [esp+10h] [ebp-CCh]
  float v35; // [esp+14h] [ebp-C8h]
  double v36; // [esp+1Ch] [ebp-C0h]
  int v37; // [esp+20h] [ebp-BCh]
  float v38; // [esp+24h] [ebp-B8h]
  float v39; // [esp+24h] [ebp-B8h]
  float v40; // [esp+28h] [ebp-B4h]
  float v41; // [esp+28h] [ebp-B4h]
  float v42; // [esp+2Ch] [ebp-B0h]
  float v43; // [esp+2Ch] [ebp-B0h]
  float v44; // [esp+34h] [ebp-A8h]
  float v45; // [esp+34h] [ebp-A8h]
  float v46; // [esp+38h] [ebp-A4h]
  float v47; // [esp+38h] [ebp-A4h]
  float v48; // [esp+3Ch] [ebp-A0h]
  float v49; // [esp+3Ch] [ebp-A0h]
  float v50; // [esp+40h] [ebp-9Ch]
  float v51; // [esp+40h] [ebp-9Ch]
  float v52; // [esp+48h] [ebp-94h]
  float v53; // [esp+48h] [ebp-94h]
  float v54; // [esp+48h] [ebp-94h]
  int v55; // [esp+4Ch] [ebp-90h]
  int n20_3; // [esp+4Ch] [ebp-90h]
  float v57; // [esp+50h] [ebp-8Ch]
  float v58; // [esp+54h] [ebp-88h]
  float v59; // [esp+54h] [ebp-88h]
  float v60; // [esp+54h] [ebp-88h]
  float v61; // [esp+54h] [ebp-88h]
  int v62; // [esp+58h] [ebp-84h]
  int v63; // [esp+58h] [ebp-84h]
  __int16 v64; // [esp+58h] [ebp-84h]
  int v65; // [esp+5Ch] [ebp-80h]
  int v66; // [esp+5Ch] [ebp-80h]
  int v67; // [esp+5Ch] [ebp-80h]
  int v68; // [esp+5Ch] [ebp-80h]
  float v69; // [esp+60h] [ebp-7Ch]
  _DWORD *src_2; // [esp+64h] [ebp-78h]
  _DWORD *src_4; // [esp+64h] [ebp-78h]
  int n28; // [esp+64h] [ebp-78h]
  _DWORD dst[20]; // [esp+68h] [ebp-74h] BYREF
  float v74; // [esp+B8h] [ebp-24h] BYREF
  float v75; // [esp+BCh] [ebp-20h]
  float v76; // [esp+C0h] [ebp-1Ch]
  float v77; // [esp+C8h] [ebp-14h] BYREF
  float v78; // [esp+CCh] [ebp-10h]
  float v79; // [esp+D0h] [ebp-Ch]

  v0 = word_133D13C[0];
  v38 = 0.0;
  v40 = 0.0;
  v42 = 0.0;
  v65 = 0;
  if ( word_133D13C[0] > 0 )
  {
    dst_2 = dst_1;
    do
    {
      n20 = 0;
      v3 = 1;
      do
      {
        if ( (v3 & *dst_2) != 0 )
        {
          sub_7948F0(n20, &v74);
          v38 = v74 + v38;
          v40 = 0.0;
          v42 = v76 + v42;
        }
        v3 = __ROL4__(v3, 1);
        ++n20;
      }
      while ( n20 < 20 );
      v0 = word_133D13C[0];
      ++dst_2;
      ++v65;
    }
    while ( v65 < word_133D13C[0] );
  }
  v4 = 0;
  v55 = 0;
  v66 = 0;
  v36 = (double)v0;
  v5 = word_133D190[0];
  v39 = v38 / v36;
  v41 = v40 / v36;
  v43 = v42 / v36;
  if ( word_133D190[0] > 0 )
  {
    src_1 = src;
    src_2 = src;
    do
    {
      n20_1 = 20;
      n0x100000 = 0x100000;
      do
      {
        if ( (n0x100000 & *src_1) != 0 )
        {
          v9 = FFX_BattleTarget_GetCurrentRange(n20_1) == 0;
          src_1 = src_2;
          if ( v9 )
            ++v4;
        }
        n0x100000 = __ROL4__(n0x100000, 1);
        ++n20_1;
      }
      while ( n20_1 < 28 );
      v5 = word_133D190[0];
      src_2 = src_1 + 1;
      v10 = v66 + 1 < word_133D190[0];
      ++src_1;
      v55 = v4;
      ++v66;
    }
    while ( v10 );
  }
  v46 = 0.0;
  v48 = 0.0;
  v50 = 0.0;
  v67 = 0;
  if ( v5 > 0 )
  {
    src_3 = src;
    src_4 = src;
    do
    {
      n20_2 = 20;
      n0x100000_1 = 0x100000;
      do
      {
        if ( (n0x100000_1 & *src_3) != 0 )
        {
          if ( v4 <= 0 || !FFX_BattleTarget_GetCurrentRange(n20_2) )
          {
            sub_7948F0(n20_2, &v74);
            v46 = v46 + v74;
            v48 = 0.0;
            v50 = v50 + v76;
          }
          src_3 = src_4;
        }
        n0x100000_1 = __ROL4__(n0x100000_1, 1);
        ++n20_2;
      }
      while ( n20_2 < 28 );
      v5 = word_133D190[0];
      src_4 = src_3 + 1;
      v10 = v67 + 1 < word_133D190[0];
      ++src_3;
      ++v67;
    }
    while ( v10 );
  }
  if ( !v4 )
    v55 = v5;
  v57 = (float)v55;
  v47 = v46 / v57;
  v49 = v48 / v57;
  v51 = v50 / v57;
  sub_7948F0((unsigned __int16)i_5, &v74);
  if ( (unsigned __int16)i_5 < 0x14u )
  {
    v33 = v47 - v39;
    qmemcpy(dst, src, 0x20u);
    v34 = v49 - v41;
    v35 = v51 - v43;
    v14 = 0;
    n20_3 = 20;
    n28 = 28;
    v68 = word_133D190[0];
    v62 = 0;
    if ( word_133D190[0] > 0 )
    {
      v15 = v69;
      src = src;
      do
      {
        n20_4 = 20;
        n0x100000_2 = 0x100000;
        do
        {
          if ( (n0x100000_2 & *src) != 0 )
          {
            sub_7948F0(n20_4, &v77);
            v77 = v77 - v74;
            v78 = v78 - v75;
            v79 = v79 - v76;
            v58 = sqrt(v78 * v78 + v77 * v77 + v79 * v79);
            v14 = v62;
            if ( !v62 || v69 > (double)v58 )
              v69 = v58;
            v15 = v69;
          }
          n0x100000_2 = __ROL4__(n0x100000_2, 1);
          ++n20_4;
        }
        while ( n20_4 < 28 );
        ++v14;
        ++src;
        v62 = v14;
      }
      while ( v14 < word_133D190[0] );
      goto LABEL_52;
    }
LABEL_51:
    v15 = v69;
    goto LABEL_52;
  }
  v33 = v39 - v47;
  qmemcpy(dst, dst_1, sizeof(dst));
  v34 = v41 - v49;
  v35 = v43 - v51;
  v19 = 0;
  n20_3 = 0;
  n28 = 20;
  v68 = word_133D13C[0];
  v63 = 0;
  if ( word_133D13C[0] <= 0 )
    goto LABEL_51;
  v15 = v69;
  dst_1 = dst_1;
  do
  {
    n20_5 = 0;
    v22 = 1;
    do
    {
      if ( (v22 & *dst_1) != 0 )
      {
        sub_7948F0(n20_5, &v77);
        v77 = v77 - v74;
        v78 = v78 - v75;
        v79 = v79 - v76;
        v59 = sqrt(v78 * v78 + v77 * v77 + v79 * v79);
        v19 = v63;
        if ( !v63 || v69 > (double)v59 )
          v69 = v59;
        v15 = v69;
      }
      v22 = __ROL4__(v22, 1);
      ++n20_5;
    }
    while ( n20_5 < 20 );
    ++v19;
    ++dst_1;
    v63 = v19;
  }
  while ( v19 < word_133D13C[0] );
LABEL_52:
  if ( v15 < 1.0 )
    v69 = 1.0;
  v23 = 0;
  if ( v68 <= 0 )
    return WORD2(v36);
  n20_6 = n20_3;
  v25 = __ROL4__(1, n20_3);
  n28_1 = n28;
  v37 = v25;
  result = v25;
  v64 = v25;
  do
  {
    n20_7 = n20_6;
    v29 = v25;
    if ( n20_3 < n28_1 )
    {
      do
      {
        if ( (v29 & dst[v23]) != 0 )
        {
          sub_7948F0(n20_7, &v77);
          v77 = v77 - v74;
          v78 = v78 - v75;
          v79 = v79 - v76;
          v52 = v79 * v35 + v77 * v33 + v78 * v34;
          v44 = sqrt(v33 * v33 + v34 * v34 + v35 * v35);
          v60 = sqrt(v78 * v78 + v77 * v77 + v79 * v79);
          v30 = v60;
          if ( 0.0 == v44 || v30 == 0.0 || v52 == 0.0 )
            v31 = 1.0;
          else
            v31 = v52 / (v44 * v30);
          v45 = v31;
          v53 = acos(v45) * 180.0 / 3.141592741012573;
          v32 = v53;
          v54 = v60 / v69;
          if ( v23 )
          {
            v61 = v32 * v54;
            if ( v57 <= (double)v61 )
            {
              result = v64;
            }
            else
            {
              result = v23;
              v57 = v32 * v54;
              v64 = v23;
            }
          }
          else
          {
            result = 0;
            v57 = v32 * v54;
            v64 = 0;
          }
          n28_1 = n28;
        }
        v29 = __ROL4__(v29, 1);
        ++n20_7;
      }
      while ( n20_7 < n28_1 );
      v25 = v37;
    }
    n20_6 = n20_3;
    ++v23;
  }
  while ( v23 < v68 );
  return result;
}

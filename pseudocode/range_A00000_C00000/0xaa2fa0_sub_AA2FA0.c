// Function: sub_AA2FA0
// Address: 0xaa2fa0
// Size: 0x5e3
// Prototype: _DWORD __cdecl(int, int n4)

int __fastcall sub_AA2FA0(_DWORD *a1, _DWORD *a2, int a3, int n4)
{
  signed int count; // ebx
  int v5; // esi
  int *buf__19; // edx
  bool v7; // zf
  int v8; // eax
  int v9; // esi
  int *v10; // edi
  int v11; // ebx
  int v12; // eax
  int buf__11; // edi
  int n2; // esi
  _DWORD *v15; // edx
  int *v16; // eax
  int v17; // eax
  int v18; // ecx
  int v19; // eax
  int v20; // edi
  float *v21; // edx
  int buf__8; // edi
  int v23; // ecx
  int buf__4; // eax
  int v25; // ecx
  int v26; // edx
  int v27; // ecx
  int buf__16; // edx
  int buf__5; // ecx
  int buf__7; // eax
  int buf__18; // edi
  int *v32; // eax
  int v33; // edx
  int buf__9; // eax
  int v35; // ecx
  int i; // eax
  signed int j; // eax
  int buf__3; // esi
  _DWORD *v39; // edx
  size_t Size; // ecx
  _DWORD *v41; // eax
  void *v42; // eax
  int v43; // eax
  bool v44; // sf
  int v45; // ebx
  _DWORD *v46; // ecx
  int v47; // eax
  int v48; // edi
  int v49; // ebx
  int v50; // ecx
  int v51; // eax
  int n2_2; // edx
  int v53; // ecx
  int v54; // esi
  int count_2; // edx
  bool v56; // cc
  int v58; // [esp+Ch] [ebp-136Ch]
  int v59; // [esp+Ch] [ebp-136Ch]
  int v60; // [esp+Ch] [ebp-136Ch]
  int v61; // [esp+Ch] [ebp-136Ch]
  int buf__2; // [esp+10h] [ebp-1368h] BYREF
  int v63; // [esp+14h] [ebp-1364h]
  int buf__12; // [esp+18h] [ebp-1360h] BYREF
  _DWORD *v65; // [esp+1Ch] [ebp-135Ch]
  int buf__17; // [esp+20h] [ebp-1358h] BYREF
  int buf__6; // [esp+24h] [ebp-1354h] BYREF
  int n2_1; // [esp+28h] [ebp-1350h]
  int *v69; // [esp+2Ch] [ebp-134Ch]
  int buf__15; // [esp+30h] [ebp-1348h] BYREF
  _DWORD *v71; // [esp+34h] [ebp-1344h]
  int v72; // [esp+38h] [ebp-1340h]
  int count_1; // [esp+3Ch] [ebp-133Ch]
  int buf__14; // [esp+40h] [ebp-1338h] BYREF
  int *v75; // [esp+44h] [ebp-1334h]
  int v76; // [esp+48h] [ebp-1330h]
  int v77; // [esp+4Ch] [ebp-132Ch]
  int buf__1; // [esp+50h] [ebp-1328h] BYREF
  int buf__10; // [esp+54h] [ebp-1324h]
  int buf_; // [esp+158h] [ebp-1220h] BYREF
  int buf__13; // [esp+15Ch] [ebp-121Ch]
  _DWORD buf[66]; // [esp+260h] [ebp-1118h] BYREF
  _DWORD buf_1[66]; // [esp+368h] [ebp-1010h] BYREF
  _DWORD buf_2[66]; // [esp+470h] [ebp-F08h] BYREF
  int v85[896]; // [esp+578h] [ebp-E00h] BYREF

  count = a2[321];
  v5 = a2[324];
  v65 = a2;
  buf__19 = 0;
  v71 = a1;
  v63 = v5;
  count_1 = count;
  v7 = count == 0;
  if ( count > 0 )
  {
    memset32(&buf_, -200, count);
    memset32(&buf__1, -200, count);
    memset(buf, 0, 4 * count);
    memset32(buf_1, 1, count);
    memset(buf_2, 0xFFu, 4 * count);
    v7 = count == 0;
  }
  if ( v7 )
  {
    v8 = sub_AA23B0(n4, a3, 0, v65[322], v85, v65[322], v5);
  }
  else
  {
    v9 = 0;
    v58 = count - 1;
    if ( count - 1 <= 0 )
      return (int)buf__19;
    v10 = v85;
    v11 = 0;
    do
    {
      v12 = sub_AA23B0(n4, a3, v65[v9], v65[v9 + 1], v10, v65[322], v63);
      ++v9;
      v11 += v12;
      v10 += 14;
    }
    while ( v9 < v58 );
    v5 = v63;
    v59 = v11;
    count = count_1;
    v8 = v59;
  }
  if ( !v8 )
    return 0;
  buf__2 = -200;
  buf__12 = -200;
  sub_AA20F0(v85, count - 1, &buf__2, &buf__12, v5);
  buf__11 = buf__12;
  n2 = 2;
  buf_ = buf__2;
  buf__1 = buf__2;
  buf__10 = buf__12;
  buf__13 = buf__12;
  if ( count > 2 )
  {
    v15 = v65;
    v16 = v65 + 132;
    buf__12 = (int)(v65 + 132);
    while ( 1 )
    {
      v17 = *v16;
      v18 = buf[v17];
      v19 = buf_1[v17];
      v60 = v18;
      v77 = v19;
      if ( buf_2[v18] != v19 )
        break;
LABEL_48:
      ++n2;
      v16 = (int *)(buf__12 + 4);
      buf__12 += 4;
      if ( n2 >= count )
      {
        buf__11 = buf__13;
        buf__3 = buf__1;
        goto LABEL_52;
      }
    }
    v20 = v15[v18 + 130];
    v72 = v15[v19 + 130];
    v21 = (float *)v63;
    v76 = v20;
    buf__6 = *(_DWORD *)(v63 + 4 * v18 + 836);
    n2_1 = *(_DWORD *)(v63 + 4 * v19 + 836);
    buf__8 = *(&buf_ + v18);
    buf_2[v18] = v19;
    if ( buf__8 >= 0 )
    {
      v69 = &buf__1 + v18;
      if ( *v69 >= 0 )
        buf__8 = (*v69 + buf__8) >> 1;
    }
    else
    {
      buf__8 = *(&buf__1 + v18);
      v69 = &buf__1 + v18;
      v21 = (float *)v63;
    }
    v23 = 4 * v19;
    v75 = &buf_ + v19;
    buf__4 = *v75;
    buf__2 = buf__4;
    if ( buf__4 >= 0 )
    {
      v25 = *(int *)((char *)&buf__1 + v23);
      if ( v25 < 0 )
        goto LABEL_22;
      buf__4 = (v25 + buf__4) >> 1;
    }
    else
    {
      buf__4 = *(int *)((char *)&buf__1 + v23);
    }
    buf__2 = buf__4;
LABEL_22:
    if ( buf__8 == -1 || buf__4 == -1 )
      exit(1);
    if ( !sub_AA1ED0(buf__6, n2_1, buf__8, buf__4, n4, a3, v21) )
      goto LABEL_46;
    buf__14 = -200;
    v26 = *(_DWORD *)buf__12 - v76;
    buf__17 = -200;
    buf__15 = -200;
    buf__6 = -200;
    n2_1 = sub_AA20F0(&v85[14 * v76], v26, &buf__14, &buf__17, v63);
    v27 = sub_AA20F0(&v85[14 * *(_DWORD *)buf__12], v72 - *(_DWORD *)buf__12, &buf__15, &buf__6, v63);
    v72 = v27;
    if ( n2_1 )
    {
      buf__16 = buf__15;
    }
    else
    {
      buf__8 = buf__14;
      buf__16 = buf__17;
    }
    buf__17 = buf__16;
    if ( v27 )
    {
      buf__5 = buf__2;
      buf__15 = buf__16;
    }
    else
    {
      buf__5 = buf__6;
    }
    if ( n2_1 && v72 )
    {
LABEL_46:
      *(&buf__1 + n2) = -200;
      *(&buf_ + n2) = -200;
    }
    else
    {
      *v69 = buf__8;
      buf__7 = buf_;
      if ( !v60 )
        buf__7 = buf__8;
      buf__18 = buf__15;
      buf_ = buf__7;
      v32 = v75;
      *(&buf_ + n2) = buf__16;
      v33 = v77;
      *(&buf__1 + n2) = buf__18;
      *v32 = buf__5;
      buf__9 = buf__10;
      if ( v33 == 1 )
        buf__9 = buf__5;
      buf__10 = buf__9;
      if ( buf__17 >= 0 || buf__18 >= 0 )
      {
        v35 = *(_DWORD *)buf__12;
        for ( i = *(_DWORD *)buf__12 - 1; i >= 0; buf_1[i + 1] = n2 )
        {
          if ( buf_1[i] != v33 )
            break;
          --i;
        }
        for ( j = v35 + 1; j < count; buf[j++] = n2 )
        {
          if ( buf[j] != v60 )
            break;
        }
      }
    }
    v15 = v65;
    goto LABEL_48;
  }
  buf__3 = buf__2;
LABEL_52:
  v39 = v71;
  Size = (4 * count + 7) & 0xFFFFFFF8;
  if ( (signed int)(Size + v71[18]) > v71[19] )
  {
    if ( v71[17] )
    {
      v41 = malloc_0(8u);
      v39 = v71;
      v71[20] += v71[18];
      v41[1] = v39[21];
      *v41 = v39[17];
      Size = (4 * count + 7) & 0xFFFFFFF8;
      v39[21] = v41;
    }
    v39[19] = Size;
    v42 = malloc_0(Size);
    v39 = v71;
    Size = (4 * count + 7) & 0xFFFFFFF8;
    v71[17] = v42;
    v39[18] = 0;
  }
  v43 = v39[18];
  buf__19 = (int *)(v43 + v39[17]);
  v44 = buf_ < 0;
  buf__17 = (int)buf__19;
  v71[18] = Size + v43;
  if ( !v44 )
  {
    if ( buf__3 >= 0 )
      buf__3 = (buf_ + buf__3) >> 1;
    else
      buf__3 = buf_;
  }
  *buf__19 = buf__3;
  if ( buf__11 >= 0 )
  {
    if ( buf__10 >= 0 )
      buf__11 = (buf__10 + buf__11) >> 1;
  }
  else
  {
    buf__11 = buf__10;
  }
  buf__19[1] = buf__11;
  n2_1 = 2;
  if ( count <= 2 )
    return (int)buf__19;
  v45 = v63;
  buf__2 = v63 + 844;
  v46 = v65 + 195;
  buf__6 = (int)(v65 + 195);
  v69 = buf__19 + 2;
  do
  {
    v47 = v46[63];
    v48 = *(_DWORD *)(v45 + 4 * v47 + 836);
    v61 = buf__19[v47] & 0x7FFF;
    v49 = (buf__19[*v46] & 0x7FFF) - v61;
    v50 = (int)((*(_DWORD *)buf__2 - v48) * abs32(v49)) / (*(_DWORD *)(v63 + 4 * *v46 + 836) - v48);
    if ( v49 >= 0 )
      v51 = v50 + v61;
    else
      v51 = v61 - v50;
    n2_2 = n2_1;
    v53 = *(&buf_ + n2_1);
    if ( v53 >= 0 )
    {
      v54 = *(&buf__1 + n2_1);
      if ( v54 >= 0 )
        v53 = (v54 + v53) >> 1;
    }
    else
    {
      v53 = *(&buf__1 + n2_1);
    }
    if ( v53 < 0 || v51 == v53 )
      v69[n2_1 - 2] = v51 | 0x8000;
    else
      v69[n2_1 - 2] = v53;
    buf__2 += 4;
    v45 = v63;
    count_2 = n2_2 + 1;
    v46 = (_DWORD *)(buf__6 + 4);
    v56 = count_2 < count_1;
    n2_1 = count_2;
    buf__19 = (int *)buf__17;
    buf__6 += 4;
  }
  while ( v56 );
  return buf__17;
}


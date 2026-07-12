// Function: sub_89EC70
// Address: 0x89ec70
__int16 __cdecl sub_89EC70(int a1, int a2)
{
  _BYTE *refreshed; // ebx
  int n16; // esi
  _BYTE *refreshed_2; // edx
  int i; // edx
  int v6; // eax
  _DWORD *v7; // edx
  int j; // esi
  int n16_1; // edx
  _BYTE *refreshed_3; // eax
  int v11; // ecx
  unsigned __int16 *v12; // edi
  int n16_2; // ebx
  int *v14; // edx
  int v15; // ecx
  unsigned __int16 *v16; // esi
  int k; // ebx
  int v18; // ecx
  _BYTE *v19; // eax
  int v20; // edx
  __int16 refreshed_4; // cx
  _BYTE *v22; // edi
  __int16 refreshed_5; // ax
  _DWORD *v24; // esi
  void (__cdecl *v25)(_DWORD); // ecx
  char *v26; // ecx
  int v27; // edx
  int v28; // esi
  int v29; // eax
  int v30; // edx
  int v31; // eax
  int v32; // edx
  __int16 result; // ax
  __int16 v34; // cx
  bool v35; // cc
  char v36; // dl
  int v37; // eax
  bool v38; // zf
  _DWORD src[32]; // [esp+Ch] [ebp-8Ch] BYREF
  int v40; // [esp+8Ch] [ebp-Ch] BYREF
  unsigned __int16 *v41; // [esp+90h] [ebp-8h]
  int refreshed_1; // [esp+94h] [ebp-4h]

  unk_1340430 = a2;
  refreshed = FFX_Btl_RefreshAllActorsCommandStates(&v40);
  n16 = 0;
  refreshed_1 = (int)refreshed;
  refreshed_2 = refreshed;
  while ( *(_BYTE *)(*(_DWORD *)&refreshed_2[(char *)&dword_1340434[1] - refreshed] + 1) == *refreshed_2 )
  {
    ++n16;
    refreshed_2 += 4;
    if ( n16 >= 16 )
      goto LABEL_41;
  }
  for ( i = 0; i < 16; *(_DWORD *)(dword_1340434[i] + 20) = 0 )
  {
    *(_BYTE *)dword_1340434[i + 1] = 1;
    *(_DWORD *)(dword_1340434[i + 1] + 4) = *(_DWORD *)(dword_1340434[i + 1] + 8);
    *(_WORD *)(dword_1340434[i + 1] + 16) = 0;
    *(_WORD *)(dword_1340434[i + 1] + 18) = 22 * i;
    v6 = dword_1340434[++i];
    *(_BYTE *)(v6 + 15) = 0;
  }
  v7 = &dword_1340434[17];
  do
  {
    if ( *v7 )
    {
      *(_BYTE *)*v7 = 0;
      *(_DWORD *)(*v7 + 4) = *(_DWORD *)(*v7 + 8);
      *(_WORD *)(*v7 + 16) = 0;
      *(_WORD *)(*v7 + 18) = 0;
      *(_BYTE *)(*v7 + 15) = 0;
      *(_DWORD *)(*v7 + 20) = 0;
      *v7 = 0;
    }
    ++v7;
  }
  while ( (int)v7 < (int)&unk_13404B8 );
  memset(src, 0, sizeof(src));
  for ( j = 0; j < 16; ++j )
  {
    n16_1 = 0;
    refreshed_3 = refreshed;
    while ( *(_DWORD *)&refreshed_3[(char *)src - refreshed] || *(_BYTE *)(dword_1340434[j + 1] + 1) != *refreshed_3 )
    {
      ++n16_1;
      refreshed_3 += 4;
      if ( n16_1 >= 16 )
        goto LABEL_22;
    }
    v11 = dword_1340434[j + 1];
    src[n16_1] = v11;
    *(_BYTE *)(v11 + 13) = *(_BYTE *)(v11 + 12);
    *(_BYTE *)(v11 + 12) = n16_1;
    *(_DWORD *)(v11 + 8) = *(unsigned __int16 *)&refreshed[4 * n16_1 + 2];
    dword_1340434[j + 1] = 0;
    if ( j == n16_1 )
    {
      *(_DWORD *)(v11 + 20) = 0;
    }
    else if ( ((1 << *(_BYTE *)(v11 + 1)) & a2) != 0 )
    {
      *(_DWORD *)(v11 + 20) = sub_8A2A70;
    }
    else
    {
      *(_DWORD *)(v11 + 20) = sub_8A2B40;
    }
LABEL_22:
    ;
  }
  v12 = (unsigned __int16 *)(refreshed_1 + 2);
  n16_2 = 16;
  v14 = &dword_1340434[1];
  v41 = (unsigned __int16 *)(refreshed_1 + 2);
  do
  {
    v15 = *v14;
    if ( *v14 )
    {
      *(_BYTE *)(v15 + 13) = *(_BYTE *)(v15 + 12);
      src[n16_2] = v15;
      *(_BYTE *)(v15 + 12) = n16_2;
      *(_DWORD *)(v15 + 8) = *v12;
      *v14 = 0;
      if ( ((1 << *(_BYTE *)(v15 + 1)) & a2) != 0 )
        *(_DWORD *)(v15 + 20) = sub_8A2A70;
      else
        *(_DWORD *)(v15 + 20) = sub_8A2B40;
      ++n16_2;
    }
    ++v14;
    v12 += 2;
  }
  while ( (int)v14 < (int)&dword_1340434[17] );
  v16 = v41;
  refreshed_1 = 16;
  for ( k = 0; k < 16; ++k )
  {
    if ( !src[k] )
    {
      v18 = 0;
      v19 = &unk_13404B8;
      do
      {
        if ( !*v19 )
          break;
        v19 += 24;
        ++v18;
      }
      while ( (int)v19 < (int)unk_13407B8 );
      v20 = 3 * v18;
      refreshed_4 = refreshed_1;
      v22 = (char *)&unk_13404B8 + 8 * v20;
      *((_BYTE *)&unk_13404C5 + 8 * v20) = refreshed_1;
      *v22 = 1;
      *((_BYTE *)&unk_13404C4 + 8 * v20) = k;
      *((_BYTE *)&unk_13404B9 + 8 * v20) = *((_BYTE *)v16 - 2);
      *((_DWORD *)&unk_13404BC + 2 * v20) = *v16;
      *((_DWORD *)&unk_13404C0 + 2 * v20) = *v16;
      *((_WORD *)&unk_13404C8 + 4 * v20) = 0;
      refreshed_5 = refreshed_4;
      LOBYTE(refreshed_4) = *((_BYTE *)&unk_13404B9 + 8 * v20);
      *((_WORD *)&unk_13404CA + 4 * v20) = 22 * refreshed_5;
      if ( ((1 << refreshed_4) & a2) != 0 )
        unk_13404CC[2 * v20] = sub_8A2A70;
      else
        unk_13404CC[2 * v20] = sub_8A2B40;
      ++refreshed_1;
      src[k] = v22;
    }
    v16 += 2;
  }
  qmemcpy(&dword_1340434[1], src, 0x80u);
LABEL_41:
  v24 = &dword_1340434[1];
  do
  {
    if ( *v24 )
    {
      v25 = *(void (__cdecl **)(_DWORD))(*v24 + 20);
      if ( v25 )
        v25(*v24);
    }
    ++v24;
  }
  while ( (int)v24 < (int)&unk_13404B8 );
  v26 = (char *)&dword_1340434[1];
  do
  {
    v27 = *(_DWORD *)v26;
    if ( *(_DWORD *)v26 )
    {
      v28 = *(_DWORD *)(v27 + 8);
      v29 = *(_DWORD *)(v27 + 4);
      if ( v28 != v29 )
      {
        if ( v28 < v29 )
        {
          *(_DWORD *)(v27 + 4) = v29 - 3;
          v30 = *(_DWORD *)(*(_DWORD *)v26 + 8);
          if ( v30 >= *(_DWORD *)(*(_DWORD *)v26 + 4) )
            *(_DWORD *)(*(_DWORD *)v26 + 4) = v30;
        }
        v31 = *(_DWORD *)(*(_DWORD *)v26 + 4);
        if ( *(_DWORD *)(*(_DWORD *)v26 + 8) > v31 )
        {
          *(_DWORD *)(*(_DWORD *)v26 + 4) = v31 + 3;
          v32 = *(_DWORD *)(*(_DWORD *)v26 + 8);
          if ( v32 <= *(_DWORD *)(*(_DWORD *)v26 + 4) )
            *(_DWORD *)(*(_DWORD *)v26 + 4) = v32;
        }
      }
    }
    v26 += 4;
  }
  while ( (int)v26 < (int)&unk_13404B8 );
  if ( sub_630E80(&unk_2000000) )
  {
    result = unk_1340410;
    v34 = unk_1340408;
    v35 = unk_1340410 < unk_1340408;
    if ( unk_1340410 != unk_1340408 )
      goto LABEL_66;
    if ( unk_1340406[0] <= 0 )
      goto LABEL_65;
    v36 = unk_1340406[0] - 1;
    result = unk_1340410 + 22;
    goto LABEL_64;
  }
  v37 = sub_630E80(0x4000000);
  v34 = unk_1340408;
  v38 = v37 == 0;
  result = unk_1340410;
  if ( !v38 )
  {
    v35 = unk_1340410 < unk_1340408;
    if ( unk_1340410 != unk_1340408 )
      goto LABEL_66;
    if ( unk_1340406[0] < 10 )
    {
      v36 = unk_1340406[0] + 1;
      result = unk_1340410 - 22;
LABEL_64:
      unk_1340410 = result;
      unk_1340406[0] = v36;
    }
  }
LABEL_65:
  v35 = result < v34;
LABEL_66:
  if ( v35 )
  {
    unk_1340408 = v34 - 11;
    if ( result >= (__int16)(v34 - 11) )
      unk_1340408 = result;
  }
  else if ( result > v34 )
  {
    unk_1340408 = v34 + 11;
    if ( result <= (__int16)(v34 + 11) )
      unk_1340408 = result;
  }
  return result;
}

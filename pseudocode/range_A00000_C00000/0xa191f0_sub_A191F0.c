// Function: sub_A191F0
// Address: 0xa191f0
// Size: 0x271
// Prototype: 

int __userpurge sub_A191F0@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4, int *n2_1)
{
  int n2_2; // eax
  int *n2_3; // edx
  int *v8; // eax
  bool v9; // zf
  int *n2; // ecx
  int v11; // ebx
  int v12; // ebx
  int v13; // edi
  int v14; // edi
  int v15; // eax
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v21; // ecx
  int v22; // eax
  int v23; // eax
  int v24; // ecx
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // ecx
  int v29; // eax
  int v30; // eax
  int v32; // [esp-8h] [ebp-Ch]
  int v33; // [esp-8h] [ebp-Ch]
  int v35; // [esp-4h] [ebp-8h]
  int v36; // [esp-4h] [ebp-8h]

  if ( *(_DWORD *)(a1 + 16084) )
    return 22;
  n2_3 = n2_1;
  v8 = (int *)n2_1[5];
  if ( !v8 )
    return 5;
  v9 = *((_BYTE *)v8 + 4) == 0;
  n2 = (int *)*((unsigned __int8 *)v8 + 5);
  n2_1 = n2;
  if ( v9 )
    v11 = *v8;
  else
    v11 = 0;
  v12 = *(_DWORD *)(v11 + 28);
  if ( *((_BYTE *)v8 + 4) )
    v13 = 0;
  else
    v13 = *v8;
  v14 = *(_DWORD *)(v13 + 32);
  if ( n2 && n2 != (int *)2 )
    return 5;
  v15 = *n2_3;
  if ( !*n2_3 )
    return 5;
  v16 = *(_BYTE *)(v15 + 4) ? 0 : *(_DWORD *)v15;
  if ( *(_DWORD *)(v16 + 28) != v12 )
    return 5;
  v17 = *(_BYTE *)(v15 + 4) ? 0 : *(_DWORD *)v15;
  if ( *(_DWORD *)(v17 + 32) != v14 )
    return 5;
  v18 = n2_3[1];
  if ( !v18 )
    return 5;
  v19 = *(_BYTE *)(v18 + 4) ? 0 : *(_DWORD *)v18;
  if ( *(_DWORD *)(v19 + 28) != v12 )
    return 5;
  v20 = *(_BYTE *)(v18 + 4) ? 0 : *(_DWORD *)v18;
  if ( *(_DWORD *)(v20 + 32) != v14 )
    return 5;
  v21 = n2_3[3];
  if ( !v21 || (int *)*(unsigned __int8 *)(v21 + 5) != n2_1 )
    return 5;
  v22 = *(_BYTE *)(v21 + 4) ? 0 : *(_DWORD *)v21;
  if ( *(_DWORD *)(v22 + 28) != v12 )
    return 5;
  v23 = *(_BYTE *)(v21 + 4) ? 0 : *(_DWORD *)v21;
  if ( *(_DWORD *)(v23 + 32) != v14 )
    return 5;
  v24 = n2_3[2];
  if ( !v24 || (int *)*(unsigned __int8 *)(v24 + 5) != n2_1 )
    return 5;
  v25 = *(_BYTE *)(v24 + 4) ? 0 : *(_DWORD *)v24;
  if ( *(_DWORD *)(v25 + 28) != v12 )
    return 5;
  v26 = *(_BYTE *)(v24 + 4) ? 0 : *(_DWORD *)v24;
  if ( *(_DWORD *)(v26 + 32) != v14 )
    return 5;
  v27 = n2_3[4];
  if ( !v27 || *(_BYTE *)(v27 + 5) )
    return 5;
  v28 = *(_BYTE *)(v27 + 4) ? 0 : *(_DWORD *)v27;
  if ( *(_DWORD *)(v28 + 28) != v12 )
    return 5;
  v29 = *(_BYTE *)(v27 + 4) ? 0 : *(_DWORD *)v27;
  if ( *(_DWORD *)(v29 + 32) != v14 )
    return 5;
  *(_DWORD *)(a1 + 16304) = *n2_3;
  *(_DWORD *)(a1 + 16308) = n2_3[1];
  *(_DWORD *)(a1 + 16312) = n2_3[2];
  *(_DWORD *)(a1 + 16316) = n2_3[3];
  *(_DWORD *)(a1 + 16320) = n2_3[4];
  *(_DWORD *)(a1 + 16324) = n2_3[5];
  *(_DWORD *)(a1 + 16084) = 3;
  n2_2 = sub_A19CB0(a4);
  if ( !n2_2 )
  {
    n2_2 = sub_A10590(v12, v14);
    if ( !n2_2 )
    {
      n2_1 = 0;
      v30 = sub_A06A30(a4, 128, 128, &unk_CA310C, 0, 0, &n2_1);
      *(_DWORD *)(a1 + 16432) = v30;
      v9 = v30 == 0;
      n2_2 = (int)n2_1;
      if ( !v9 && !n2_1 )
      {
        n2_2 = sub_A19CF0(a3, a2);
        if ( !n2_2 )
        {
          *(_BYTE *)(a1 + 16428) &= *(_DWORD *)(sub_4FDA00(v32, v35) + 180) >= 45056;
          *(_BYTE *)(a1 + 16272) &= *(_DWORD *)(sub_4FDA00(v33, v36) + 180) >= 45056;
          return 0;
        }
      }
    }
  }
  return n2_2;
}


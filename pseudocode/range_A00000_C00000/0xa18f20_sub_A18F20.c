// Function: sub_A18F20
// Address: 0xa18f20
// Size: 0x17d
// Prototype: 

int __userpurge sub_A18F20@<eax>(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4, int *a5)
{
  int result; // eax
  int *v7; // eax
  int n2; // ebx
  int v9; // ecx
  int v10; // eax
  int v11; // edi
  int v12; // eax
  int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // eax
  int v23; // [esp+4h] [ebp-4h]

  if ( a1[4021] )
    return 22;
  v7 = (int *)a5[3];
  if ( !v7 )
    return 5;
  n2 = *((unsigned __int8 *)v7 + 5);
  if ( *((_BYTE *)v7 + 4) )
    v9 = 0;
  else
    v9 = *v7;
  v23 = *(_DWORD *)(v9 + 28);
  if ( *((_BYTE *)v7 + 4) )
    v10 = 0;
  else
    v10 = *v7;
  v11 = *(_DWORD *)(v10 + 32);
  if ( n2 && n2 != 2 )
    return 5;
  v12 = *a5;
  if ( !*a5 )
    return 5;
  v13 = *(_BYTE *)(v12 + 4) ? 0 : *(_DWORD *)v12;
  if ( *(_DWORD *)(v13 + 28) != v23 )
    return 5;
  v14 = *(_BYTE *)(v12 + 4) ? 0 : *(_DWORD *)v12;
  if ( *(_DWORD *)(v14 + 32) != v11 )
    return 5;
  v15 = a5[1];
  if ( !v15 || *(unsigned __int8 *)(v15 + 5) != n2 )
    return 5;
  v16 = *(_BYTE *)(v15 + 4) ? 0 : *(_DWORD *)v15;
  if ( *(_DWORD *)(v16 + 28) != v23 )
    return 5;
  v17 = *(_BYTE *)(v15 + 4) ? 0 : *(_DWORD *)v15;
  if ( *(_DWORD *)(v17 + 32) != v11 )
    return 5;
  v18 = a5[2];
  if ( !v18 || *(_BYTE *)(v18 + 5) )
    return 5;
  v19 = *(_BYTE *)(v18 + 4) ? 0 : *(_DWORD *)v18;
  if ( *(_DWORD *)(v19 + 28) != v23 )
    return 5;
  v20 = *(_BYTE *)(v18 + 4) ? 0 : *(_DWORD *)v18;
  if ( *(_DWORD *)(v20 + 32) != v11 )
    return 5;
  a1[4072] = *a5;
  a1[4073] = a5[1];
  a1[4074] = a5[2];
  a1[4075] = a5[3];
  a1[4021] = 2;
  result = sub_A19CB0(a4);
  if ( !result )
  {
    result = sub_A10590(v23, v11);
    if ( !result )
      return sub_A19CF0(a3, a2);
  }
  return result;
}


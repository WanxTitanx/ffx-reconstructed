// Function: sub_A92460
// Address: 0xa92460
// Size: 0x1aa
// Prototype: 

int __cdecl sub_A92460(int *a1, int *a2)
{
  int v3; // eax
  int v4; // ebx
  int v5; // edx
  int v6; // ecx
  _DWORD *v7; // edi
  int v8; // ecx
  int v9; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // edi
  int v15; // [esp+Ch] [ebp-4h]
  int **v16; // [esp+Ch] [ebp-4h]
  int v17; // [esp+18h] [ebp+8h]

  if ( !a1 )
  {
    v3 = 0;
    goto LABEL_6;
  }
  v3 = a1[16];
  if ( !v3 )
  {
LABEL_6:
    v5 = 0;
    v15 = 0;
    v4 = 0;
    goto LABEL_7;
  }
  v4 = *(_DWORD *)(v3 + 4);
  v5 = *(_DWORD *)(v3 + 104);
  v15 = v5;
  if ( !v4 )
  {
LABEL_7:
    v6 = 0;
    goto LABEL_8;
  }
  v6 = *(_DWORD *)(v4 + 28);
LABEL_8:
  v17 = v6;
  if ( a1 )
    v7 = a1 + 1;
  else
    v7 = 0;
  if ( !v3 || !v5 || !v4 || !v6 || !v7 )
    return -136;
  sub_A920E0((int)a1);
  v8 = a2[1];
  v9 = *a2;
  *(_QWORD *)v7 = 0;
  *((_QWORD *)v7 + 1) = 0;
  v7[4] = 0;
  v7[4] = v8;
  v7[3] = v9;
  v7[2] = v9;
  if ( sub_42EB10(v7, 1) )
    return -135;
  v11 = sub_42EB10(v7, *(_DWORD *)(v15 + 44));
  if ( v11 == -1 )
    return -136;
  a1[10] = v11;
  v16 = (int **)(v17 + 4 * v11 + 32);
  if ( !*v16 )
    return -136;
  v12 = **v16;
  a1[7] = v12;
  if ( v12 )
  {
    a1[6] = sub_42EB10(v7, 1);
    v13 = sub_42EB10(v7, 1);
    a1[8] = v13;
    if ( v13 == -1 )
      return -136;
  }
  else
  {
    a1[6] = 0;
    a1[8] = 0;
  }
  a1[12] = a2[4];
  a1[13] = a2[5];
  a1[14] = a2[6];
  a1[15] = a2[7];
  a1[11] = a2[3];
  a1[9] = *(_DWORD *)(v17 + 4 * a1[7]);
  v14 = 0;
  for ( *a1 = sub_A92150(a1, 4 * *(_DWORD *)(v4 + 4));
        v14 < *(_DWORD *)(v4 + 4);
        *(_DWORD *)(*a1 + 4 * v14 - 4) = sub_A92150(a1, 4 * a1[9]) )
  {
    ++v14;
  }
  return ((int (__cdecl *)(int *, _DWORD))(&off_B814FC)[*(_DWORD *)(v17 + 4 * (*v16)[3] + 288)][4])(
           a1,
           *(_DWORD *)(v17 + 4 * (*v16)[3] + 544));
}


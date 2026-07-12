// Function: sub_A97E60
// Address: 0xa97e60
// Size: 0x205
// Prototype: 

int __fastcall sub_A97E60(int n4_1, int a2, int a3, int a4, int n4_3)
{
  int n4_2; // eax
  int v6; // edx
  int v8; // esi
  int v9; // ecx
  int v10; // ebx
  int v11; // eax
  int v12; // edx
  int v13; // edi
  int v14; // eax
  bool v15; // zf
  unsigned int v16; // edi
  _DWORD *v17; // edx
  int v18; // ebx
  _DWORD *v19; // ecx
  int v20; // ebx
  int *v21; // ecx
  int v22; // edi
  int v23; // [esp-Ch] [ebp-34h]
  int v24; // [esp-8h] [ebp-30h]
  int v25; // [esp-8h] [ebp-30h]
  int v26; // [esp-4h] [ebp-2Ch]
  int v27; // [esp-4h] [ebp-2Ch]
  int v28; // [esp-4h] [ebp-2Ch]
  int v29; // [esp-4h] [ebp-2Ch]
  int v30; // [esp+Ch] [ebp-1Ch]
  int n4_4; // [esp+Ch] [ebp-1Ch]
  int v32; // [esp+10h] [ebp-18h]
  int v33; // [esp+14h] [ebp-14h]
  int v34; // [esp+18h] [ebp-10h]
  int v35; // [esp+1Ch] [ebp-Ch]
  int v36; // [esp+1Ch] [ebp-Ch]
  int n4; // [esp+20h] [ebp-8h]
  int v39; // [esp+38h] [ebp+10h]

  n4_2 = n4_3;
  v6 = 1;
  v8 = 0;
  v9 = 1;
  n4 = n4_1;
  v30 = *(_DWORD *)(n4_3 + 4);
  v35 = 1;
  v33 = 1;
  if ( v30 <= 0 )
    return n4_2;
  v10 = a3;
  n4_2 = n4_3 + 8;
  v32 = n4_3 + 8;
  do
  {
    v39 = *(_DWORD *)n4_2;
    v34 = v6 * *(_DWORD *)n4_2;
    v11 = n4_1 / v34;
    v12 = v35;
    v13 = v11;
    v36 = v35 * v11;
    switch ( v39 )
    {
      case 4:
        v29 = a4 + 4 * (v11 + v11 + v9) - 4;
        v10 = a3;
        v25 = a4 + 4 * (v11 + v9) - 4;
        v23 = a4 + 4 * v9 - 4;
        if ( v8 )
          sub_A98E20(a3, a2, v23, v25, v29);
        else
          sub_A98E20(a2, a3, v23, v25, v29);
        goto LABEL_20;
      case 2:
        v28 = a4 + 4 * v9 - 4;
        if ( v8 )
          sub_A995C0(v10, a2, v28);
        else
          sub_A995C0(a2, v10, v28);
        goto LABEL_20;
      case 3:
        v10 = a3;
        v27 = a4 + 4 * (v11 + v9) - 4;
        v24 = a4 + 4 * v9 - 4;
        if ( v8 )
          sub_A992D0(a3, a2, v24, v27);
        else
          sub_A992D0(a2, a3, v24, v27);
LABEL_20:
        v8 = 1 - v8;
        goto LABEL_21;
    }
    v26 = a4 + 4 * v9 - 4;
    if ( v8 )
      sub_A98070(v12, v36, v10, v10, v10, a2, a2, v26);
    else
      sub_A98070(v12, v36, a2, a2, a2, v10, v10, v26);
    if ( v13 == 1 )
      goto LABEL_20;
LABEL_21:
    v6 = v34;
    v14 = v13 * (v39 - 1);
    n4_1 = n4;
    v9 = v14 + v33;
    n4_2 = v32 + 4;
    v15 = v30-- == 1;
    v35 = v34;
    v33 = v9;
    v32 += 4;
  }
  while ( !v15 );
  if ( v8 )
  {
    n4_2 = 0;
    if ( n4 >= 4 )
    {
      v16 = ((unsigned int)(n4 - 4) >> 2) + 1;
      v17 = (_DWORD *)(v10 + 12);
      v18 = v10 - a2;
      v19 = (_DWORD *)(a2 + 4);
      n4_4 = 4 * v16;
      do
      {
        *(v19 - 1) = *(v17 - 3);
        *v19 = *(_DWORD *)((char *)v19 + v18);
        v19[1] = *(v17 - 1);
        v19[2] = *v17;
        v19 += 4;
        v17 += 4;
        --v16;
      }
      while ( v16 );
      v10 = a3;
      n4_1 = n4;
      n4_2 = n4_4;
    }
    if ( n4_2 < n4_1 )
    {
      v20 = v10 - a2;
      v21 = (int *)(a2 + 4 * n4_2);
      v22 = n4_1 - n4_2;
      do
      {
        n4_2 = *(int *)((char *)v21 + v20);
        *v21++ = n4_2;
        --v22;
      }
      while ( v22 );
    }
  }
  return n4_2;
}


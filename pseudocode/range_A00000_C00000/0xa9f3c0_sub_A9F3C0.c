// Function: sub_A9F3C0
// Address: 0xa9f3c0
// Size: 0x240
// Prototype: 

int __fastcall sub_A9F3C0(int a1, _DWORD **a2, int a3, int a4, _DWORD *a5)
{
  _DWORD *v5; // ebx
  _DWORD *v6; // ecx
  int v7; // esi
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v11; // eax
  int v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // esi
  _DWORD *v17; // edx
  _DWORD *v18; // ebx
  int v19; // eax
  int v20; // eax
  int v21; // ebx
  int v22; // edx
  int v23; // eax
  int v24; // edx
  _DWORD *v25; // esi
  int v26; // ebx
  int v27; // ecx
  int v28; // eax
  int v29; // eax
  int v30; // eax
  _DWORD v32[128]; // [esp+8h] [ebp-434h] BYREF
  _DWORD v33[128]; // [esp+208h] [ebp-234h] BYREF
  int v34; // [esp+408h] [ebp-34h]
  int v35; // [esp+40Ch] [ebp-30h]
  int v36; // [esp+410h] [ebp-2Ch]
  int v37; // [esp+414h] [ebp-28h]
  int v38; // [esp+418h] [ebp-24h]
  _DWORD *v39; // [esp+41Ch] [ebp-20h]
  int v40; // [esp+420h] [ebp-1Ch]
  int v41; // [esp+424h] [ebp-18h]
  int v42; // [esp+428h] [ebp-14h]
  int v43; // [esp+42Ch] [ebp-10h]
  int v44; // [esp+430h] [ebp-Ch]
  int v45; // [esp+434h] [ebp-8h]
  _DWORD *v46; // [esp+438h] [ebp-4h]

  v5 = a2;
  v40 = a1;
  v6 = *a2;
  v7 = (*a2)[2];
  v35 = (*a2)[3];
  v42 = *a2[4];
  v8 = v6[1] - *v6;
  v46 = a2;
  v39 = v6;
  v41 = v7;
  v45 = v8 / v7;
  memset(v32, 0, sizeof(v32));
  memset(v33, 0, sizeof(v33));
  v9 = 0;
  v44 = 0;
  if ( (int)v5[2] <= 0 )
    return 0;
  v10 = a4;
  v11 = v45;
  do
  {
    v12 = 0;
    if ( v11 <= 0 )
      goto LABEL_37;
    do
    {
      if ( !v9 )
      {
        v13 = 0;
        v43 = 0;
        if ( v10 > 0 )
        {
          do
          {
            v14 = a5[v13];
            v15 = 1;
            v16 = *(_DWORD *)(v14 + 4 * v12);
            if ( v42 > 1 )
            {
              v17 = (_DWORD *)(v14 + 4 * (v12 + 1));
              do
              {
                v16 *= v35;
                if ( v15 + v12 < v45 )
                  v16 += *v17;
                ++v15;
                ++v17;
              }
              while ( v15 < v42 );
              v5 = v46;
              v10 = a4;
            }
            v18 = (_DWORD *)v5[4];
            if ( v16 >= v18[1] )
            {
              v5 = v46;
            }
            else if ( v16 < 0 || (v19 = v18[3], v16 >= *(_DWORD *)(v19 + 4)) )
            {
              v5 = v46;
              v10 = a4;
              v46[9] = v46[9];
            }
            else
            {
              sub_42E350(v40, *(_DWORD *)(v18[5] + 4 * v16), *(char *)(*(_DWORD *)(v19 + 8) + v16));
              v20 = v18[3];
              v5 = v46;
              v10 = a4;
              v46[9] += *(char *)(*(_DWORD *)(v20 + 8) + v16);
            }
            v13 = v43 + 1;
            v43 = v13;
          }
          while ( v13 < v10 );
          v9 = v44;
          v7 = v41;
        }
        v11 = v45;
      }
      v43 = 0;
      if ( v42 <= 0 )
        goto LABEL_35;
      v21 = v42;
      v22 = v7 * v12;
      v38 = v7 * v12;
      do
      {
        if ( v12 >= v11 )
          goto LABEL_36;
        v23 = v22 + *v39;
        v24 = __ROL4__(1, v9);
        v34 = v23;
        v36 = v24;
        if ( a4 <= 0 )
          goto LABEL_34;
        v25 = a5;
        v26 = a4;
        v37 = a3 - (_DWORD)a5;
        do
        {
          if ( !v9 )
            v33[*(_DWORD *)(*v25 + 4 * v12)] += v41;
          v27 = *(_DWORD *)(*v25 + 4 * v12);
          if ( (v24 & v39[v27 + 6]) != 0 )
          {
            v28 = *(_DWORD *)(v46[5] + 4 * v27);
            v9 = v44;
            v29 = *(_DWORD *)(v28 + 4 * v44);
            if ( !v29 )
              goto LABEL_32;
            v30 = sub_A9FA20(v40, *(_DWORD *)((char *)v25 + v37) + 4 * v34, v41, v29);
            v24 = v36;
            v46[8] += v30;
            v32[*(_DWORD *)(*v25 + 4 * v12)] += v30;
          }
          v9 = v44;
LABEL_32:
          ++v25;
          --v26;
        }
        while ( v26 );
        v21 = v42;
        v7 = v41;
LABEL_34:
        v22 = v7 + v38;
        ++v12;
        ++v43;
        v11 = v45;
        v38 += v7;
      }
      while ( v43 < v21 );
LABEL_35:
      v5 = v46;
      v10 = a4;
    }
    while ( v12 < v11 );
LABEL_36:
    v5 = v46;
    v10 = a4;
LABEL_37:
    v44 = ++v9;
  }
  while ( v9 < v5[2] );
  return 0;
}


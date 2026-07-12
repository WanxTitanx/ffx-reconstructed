// Function: sub_A997D0
// Address: 0xa997d0
// Size: 0x207
// Prototype: 

signed int __fastcall sub_A997D0(int n4, int a2, int a3, int a4, int a5)
{
  signed int n4_1; // edi
  signed int n4_7; // eax
  int n4_2; // edx
  int v9; // esi
  _DWORD *v10; // ecx
  int v11; // edi
  int n4_5; // edx
  int v13; // ecx
  int v14; // eax
  bool v15; // zf
  _DWORD *v16; // edx
  unsigned int v17; // esi
  _DWORD *v18; // ecx
  int v19; // esi
  signed int *v20; // ecx
  int v21; // edi
  int v22; // [esp-4h] [ebp-2Ch]
  int v23; // [esp-4h] [ebp-2Ch]
  int v24; // [esp-4h] [ebp-2Ch]
  int n4_9; // [esp+Ch] [ebp-1Ch]
  int n4_6; // [esp+10h] [ebp-18h]
  _DWORD *v27; // [esp+14h] [ebp-14h]
  int n4_4; // [esp+1Ch] [ebp-Ch]
  int n4_3; // [esp+20h] [ebp-8h]
  int v31; // [esp+20h] [ebp-8h]
  signed int n4_8; // [esp+24h] [ebp-4h]

  n4_1 = n4;
  n4_7 = *(_DWORD *)(a5 + 4);
  n4_8 = n4_7;
  n4_9 = 1;
  n4_2 = n4;
  n4_3 = n4;
  n4_4 = n4;
  if ( n4_7 <= 0 )
    return n4_7;
  v9 = a3;
  v10 = (_DWORD *)(a5 + 4 * n4_7 + 4);
  v27 = v10;
  do
  {
    n4_6 = n4_2 / *v10;
    v11 = n4_1 / n4_3;
    v31 = n4_6 * v11;
    n4_5 = n4_4 - v11 * (*v27 - 1);
    v13 = 1 - n4_9;
    n4_4 = n4_5;
    n4_9 = 1 - n4_9;
    if ( *v27 == 4 )
    {
      v24 = a4 + 4 * (v11 + v11 + n4_5 - 1);
      v14 = n4_5 - 1;
      if ( v13 )
        sub_A9A8E0(a3, a2, a4 - 4 + 4 * n4_5, a4 + 4 * (v11 + v14), v24);
      else
        sub_A9A8E0(a2, a3, a4 - 4 + 4 * n4_5, a4 + 4 * (v11 + v14), v24);
      goto LABEL_16;
    }
    if ( *v27 == 2 )
    {
      v23 = a4 + 4 * n4_5 - 4;
      if ( v13 )
        sub_A9AD40(a3, a2, v23);
      else
        sub_A9AD40(a2, a3, v23);
LABEL_16:
      n4_7 = n4_9;
      goto LABEL_17;
    }
    if ( v11 == 1 )
      v13 = 1 - v13;
    v22 = a4 + 4 * n4_5 - 4;
    if ( v13 )
    {
      sub_A999E0(n4_6, v31, a3, a3, a3, a2, a2, v22);
      n4_7 = 0;
      n4_9 = 0;
    }
    else
    {
      sub_A999E0(n4_6, v31, a2, a2, a2, a3, a3, v22);
      n4_7 = 1;
      n4_9 = 1;
    }
LABEL_17:
    n4_2 = n4_6;
    n4_1 = n4;
    v10 = v27 - 1;
    v15 = n4_8-- == 1;
    n4_3 = n4_6;
    --v27;
  }
  while ( !v15 );
  if ( n4_7 != 1 )
  {
    n4_7 = 0;
    if ( n4 >= 4 )
    {
      v16 = (_DWORD *)(a3 + 12);
      v17 = ((unsigned int)(n4 - 4) >> 2) + 1;
      v18 = (_DWORD *)(a2 + 4);
      do
      {
        *(v18 - 1) = *(v16 - 3);
        *v18 = *(_DWORD *)((char *)v18 + a3 - a2);
        v18[1] = *(v16 - 1);
        v18[2] = *v16;
        v18 += 4;
        v16 += 4;
        --v17;
      }
      while ( v17 );
      v9 = a3;
      n4_1 = n4;
      n4_7 = 4 * (((unsigned int)(n4 - 4) >> 2) + 1);
    }
    if ( n4_7 < n4_1 )
    {
      v19 = v9 - a2;
      v20 = (signed int *)(a2 + 4 * n4_7);
      v21 = n4_1 - n4_7;
      do
      {
        n4_7 = *(signed int *)((char *)v20 + v19);
        *v20++ = n4_7;
        --v21;
      }
      while ( v21 );
    }
  }
  return n4_7;
}


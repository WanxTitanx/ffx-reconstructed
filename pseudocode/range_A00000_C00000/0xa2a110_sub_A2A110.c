// Function: sub_A2A110
// Address: 0xa2a110
// Size: 0x2e2
// Prototype: 

int __thiscall sub_A2A110(int this, unsigned int i_10)
{
  unsigned int i_7; // ebx
  int v4; // eax
  unsigned int i_6; // ecx
  int v6; // esi
  _BYTE *v7; // ebx
  _BYTE *i_1; // eax
  _BYTE *i; // edx
  _BYTE *v10; // ecx
  int i_3; // ecx
  int v12; // eax
  int i_4; // eax
  _DWORD *v14; // esi
  int v15; // eax
  int v16; // ebx
  int i_8; // ecx
  int v18; // eax
  _DWORD *v19; // esi
  int i_9; // ecx
  int v21; // eax
  _DWORD *v22; // esi
  int v23; // ebx
  int v24; // eax
  int v25; // edi
  int v26; // esi
  int v27; // ebx
  _WORD *v28; // esi
  unsigned int v29; // edx
  __int16 v30; // cx
  int v31; // esi
  int v32; // [esp+Ch] [ebp-10h] BYREF
  int i_5; // [esp+10h] [ebp-Ch]
  int v34; // [esp+14h] [ebp-8h]
  int i_2; // [esp+18h] [ebp-4h]
  int v36; // [esp+24h] [ebp+8h]

  i_7 = i_10;
  v4 = *(_DWORD *)(this + 348);
  i_6 = v4 & 0x7FFFFFFF;
  i_5 = v4 & 0x7FFFFFFF;
  v34 = i_10 + 1;
  if ( i_10 + 1 != v4 )
  {
    v6 = i_10 + 1;
    if ( i_10 + 1 >= i_6 )
      v6 = v4 & 0x7FFFFFFF;
    v7 = *(_BYTE **)(this + 352);
    i_2 = 0;
    if ( i_10 != -1 )
    {
      i_1 = (_BYTE *)sub_42FC60(i_10 + 1, 1);
      i_2 = (int)i_1;
      if ( i_1 )
      {
        for ( i = i_1; v6; --v6 )
        {
          v10 = i++;
          if ( v10 )
            *v10 = *v7++;
        }
      }
      else if ( v34 )
      {
        return 13;
      }
    }
    i_3 = *(_DWORD *)(this + 352);
    if ( i_3 != i_2 && *(int *)(this + 348) >= 0 && i_3 )
      Phyre_Memory_AlignedFree(*(_DWORD *)(this + 352));
    v12 = v34;
    i_6 = i_5;
    i_7 = i_10;
    *(_DWORD *)(this + 352) = i_2;
    *(_DWORD *)(this + 348) = v12;
  }
  if ( i_7 >= i_6 )
    memset((void *)(i_6 + *(_DWORD *)(this + 352)), 0, i_7 - i_6);
  else
    *(_BYTE *)(i_7 + *(_DWORD *)(this + 352)) = 0;
  v14 = *(_DWORD **)(this + 100);
  v15 = 4 * i_7;
  v16 = 6 * i_7;
  v36 = v15;
  v34 = v16;
  i_4 = sub_483690(8, v15, 1);
  i_8 = *v14 * v14[1];
  i_2 = i_4;
  i_5 = i_8;
  if ( v14[14] != i_8 )
  {
    if ( (unsigned __int8)sub_562F10(v14) )
      sub_564830();
    v14[14] = i_5;
    i_4 = i_2;
  }
  if ( !i_4 )
  {
    v18 = v14[3];
    *(_BYTE *)(v18 + 8) = 1;
    *(_DWORD *)(v18 + 4) = &unk_C98620;
    *(_DWORD *)v18 = 0;
    v19 = (_DWORD *)(*(_DWORD *)(this + 100) + 64);
    i_4 = sub_483690(8, v36, 1);
    i_9 = *v19 * v19[1];
    i_2 = i_4;
    i_5 = i_9;
    if ( v19[14] != i_9 )
    {
      if ( (unsigned __int8)sub_562F10(v19) )
        sub_564830();
      v19[14] = i_5;
      i_4 = i_2;
    }
    if ( !i_4 )
    {
      v21 = v19[3];
      *(_BYTE *)(v21 + 8) = 1;
      *(_DWORD *)(v21 + 4) = &unk_C98638;
      *(_DWORD *)v21 = 0;
      if ( !*(_BYTE *)(this + 372) )
      {
LABEL_38:
        v25 = this + 104;
        *(_DWORD *)(v25 + 8) = v16;
        *(_BYTE *)(v25 + 12) = 12;
        *(_DWORD *)v25 = 0;
        *(_DWORD *)(v25 + 4) = v36 - 1;
        v26 = v16 * sub_55BDB0(12);
        if ( *(_DWORD *)(v25 + 52) != v26 )
        {
          if ( (unsigned __int8)sub_562F20(v25) )
            sub_564A20();
          *(_DWORD *)(v25 + 52) = v26;
        }
        i_4 = sub_434DD0(&v32);
        if ( !i_4 )
        {
          if ( v32 )
          {
            v27 = 0;
            if ( v34 )
            {
              v28 = (_WORD *)(v32 + 4);
              v29 = (v34 - 1) / 6u + 1;
              do
              {
                v30 = v27;
                v27 += 4;
                *(v28 - 1) = v30 + 1;
                *v28 = v30 + 2;
                v28[2] = v30 + 2;
                *(v28 - 2) = v30;
                v28[1] = v30;
                v28[3] = v30 + 3;
                v28 += 6;
                --v29;
              }
              while ( v29 );
            }
          }
          v31 = (*(_DWORD *)(v25 + 20) & 0x7FFFFFFF) != *(_DWORD *)(v25 + 16) + 1 ? *(_DWORD *)(v25 + 16) + 1 : 0;
          i_4 = sub_565160(v31, &v32);
          if ( !i_4 )
          {
            *(_DWORD *)(v25 + 16) = v31;
            *(_BYTE *)(v25 + 14) = 0;
          }
        }
        return i_4;
      }
      v22 = (_DWORD *)(*(_DWORD *)(this + 100) + 128);
      i_4 = sub_483690(16, v36, 1);
      v23 = *v22 * v22[1];
      i_5 = i_4;
      if ( v22[14] != v23 )
      {
        if ( (unsigned __int8)sub_562F10(v22) )
          sub_564830();
        i_4 = i_5;
        v22[14] = v23;
      }
      if ( !i_4 )
      {
        v24 = v22[3];
        v16 = v34;
        *(_BYTE *)(v24 + 8) = 3;
        *(_DWORD *)(v24 + 4) = &unk_C98650;
        *(_DWORD *)v24 = 0;
        goto LABEL_38;
      }
    }
  }
  return i_4;
}


// Function: sub_988370
// Address: 0x988370
_DWORD *__thiscall sub_988370(int *this, _DWORD *a2, int a3)
{
  _DWORD *result; // eax
  _DWORD *v5; // edx
  int v6; // eax
  int v7; // esi
  int v8; // edi
  int v9; // esi
  int v10; // ebx
  _DWORD *src; // edi
  _DWORD *dst_2; // ecx
  int v13; // eax
  int v14; // esi
  int dst_3; // eax
  void *dst_1; // ecx
  _DWORD *src_1; // esi
  int v18; // eax
  int v19; // edi
  int v20; // esi
  int v21; // eax
  _DWORD *v22; // ecx
  char *v23; // edi
  int v24; // esi
  _DWORD *v25; // ecx
  int v26; // ecx
  int v27; // ebx
  int v28; // esi
  int v29; // eax
  _DWORD *v30; // ecx
  _DWORD *v31; // eax
  char *v32; // esi
  int v33; // edi
  int v34; // [esp+18h] [ebp-30h]
  int v35; // [esp+24h] [ebp-24h]
  int v36; // [esp+24h] [ebp-24h]
  _DWORD *v37; // [esp+28h] [ebp-20h]
  int v38; // [esp+28h] [ebp-20h]
  int v39; // [esp+2Ch] [ebp-1Ch]
  int v40; // [esp+2Ch] [ebp-1Ch]
  _DWORD *v41; // [esp+2Ch] [ebp-1Ch]
  _DWORD *src_2; // [esp+30h] [ebp-18h]
  void *dst; // [esp+34h] [ebp-14h]
  _DWORD *v44; // [esp+38h] [ebp-10h]

  result = (_DWORD *)sub_9882D0(a2);
  if ( *this )
  {
    v5 = 0;
    v6 = 0;
    v44 = 0;
    v34 = 0;
    v7 = *(this + 3);
    if ( v7 > 0 )
    {
      v5 = (_DWORD *)sub_9D4CE0(8 * v7, 16);
      v6 = v7;
      v44 = v5;
      v34 = v7;
    }
    v8 = *this;
    if ( !v6 )
    {
      v9 = sub_9D4CE0(8, 16);
      if ( v44 )
        sub_9D4D50(v44);
      v5 = (_DWORD *)v9;
      v44 = (_DWORD *)v9;
      v34 = 1;
    }
    if ( v5 )
    {
      *v5 = v8;
      v5[1] = 0;
    }
    v10 = 1;
    do
    {
      src = (_DWORD *)v5[2 * v10 - 2];
      dst_2 = (_DWORD *)a2[1];
      v13 = v5[2 * v10 - 1];
      v14 = src[9];
      --v10;
      src_2 = src;
      v39 = v13;
      dst = dst_2;
      if ( dst_2 )
      {
        a2[1] = 0;
      }
      else
      {
        dst_3 = sub_9D4CE0(48, 16);
        v5 = v44;
        dst_2 = (_DWORD *)dst_3;
        v13 = v39;
        dst = dst_2;
      }
      dst_2[9] = v14;
      dst_2[8] = v13;
      dst_2[10] = 0;
      qmemcpy(dst, src, 0x20u);
      if ( v13 )
      {
        *(_DWORD *)(v39 + 4 * (v10 & 1) + 36) = dst;
        dst_1 = dst;
      }
      else
      {
        dst_1 = dst;
        *a2 = dst;
      }
      src_1 = src;
      if ( src[10] )
      {
        v18 = v34;
        v19 = src[9];
        v35 = src_2[9];
        if ( v10 == v34 )
        {
          v20 = 2 * v10;
          if ( !v10 )
            v20 = 1;
          v40 = v20;
          if ( v34 < v20 )
          {
            if ( v20 )
              v21 = sub_9D4CE0(8 * v20, 16);
            else
              v21 = 0;
            v37 = (_DWORD *)v21;
            if ( v10 > 0 )
            {
              v22 = (_DWORD *)v21;
              v23 = (char *)v44 - v21;
              v24 = v10;
              do
              {
                if ( v22 )
                {
                  *v22 = *(_DWORD *)((char *)v22 + (_DWORD)v23);
                  v22[1] = *(_DWORD *)((char *)v22 + (_DWORD)v23 + 4);
                }
                v22 += 2;
                --v24;
              }
              while ( v24 );
              v20 = v40;
              v19 = v35;
            }
            if ( v44 )
              sub_9D4D50(v44);
            v5 = v37;
            v18 = v20;
            v44 = v37;
            v34 = v20;
          }
          src_1 = src_2;
        }
        v25 = &v5[2 * v10];
        if ( v25 )
        {
          *v25 = v19;
          v25[1] = dst;
        }
        v26 = src_1[10];
        v27 = v10 + 1;
        v36 = v26;
        if ( v27 == v18 )
        {
          v28 = 2 * v27;
          if ( !v27 )
            v28 = 1;
          v38 = v28;
          if ( v18 < v28 )
          {
            if ( v28 )
            {
              v29 = sub_9D4CE0(8 * v28, 16);
              v5 = v44;
              v30 = (_DWORD *)v29;
              v41 = (_DWORD *)v29;
            }
            else
            {
              v30 = 0;
              v41 = 0;
            }
            if ( v27 > 0 )
            {
              v31 = v30;
              v32 = (char *)((char *)v5 - (char *)v30);
              v33 = v27;
              do
              {
                if ( v31 )
                {
                  *v31 = *(_DWORD *)((char *)v31 + (_DWORD)v32);
                  v31[1] = *(_DWORD *)((char *)v31 + (_DWORD)v32 + 4);
                }
                v31 += 2;
                --v33;
              }
              while ( v33 );
              v28 = v38;
            }
            if ( v5 )
              sub_9D4D50(v5);
            v5 = v41;
            v26 = v36;
            v44 = v41;
            v34 = v28;
          }
        }
        result = &v5[2 * v27];
        if ( result )
        {
          *result = v26;
          result[1] = dst;
        }
        v10 = v27 + 1;
      }
      else
      {
        result = (_DWORD *)(*(int (__thiscall **)(int, void *))(*(_DWORD *)a3 + 4))(a3, dst_1);
        v5 = v44;
      }
    }
    while ( v10 > 0 );
    if ( v5 )
      return (_DWORD *)sub_9D4D50(v5);
  }
  return result;
}

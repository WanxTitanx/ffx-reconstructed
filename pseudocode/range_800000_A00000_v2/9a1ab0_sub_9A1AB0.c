// Function: sub_9A1AB0
// Address: 0x9a1ab0
int __thiscall sub_9A1AB0(int *this, int a2)
{
  int *this_1; // ebx
  int v3; // edi
  int v4; // esi
  int result; // eax
  int v6; // ecx
  _DWORD *v7; // edx
  int v8; // ecx
  int v9; // ecx
  _DWORD *n8; // eax
  _DWORD *v11; // edx
  _DWORD *v12; // ecx
  int i; // esi
  int v14; // ecx
  int v15; // esi
  int v16; // [esp+14h] [ebp-34h]
  int v17; // [esp+18h] [ebp-30h]
  int v18; // [esp+1Ch] [ebp-2Ch]
  _DWORD *v19; // [esp+24h] [ebp-24h]
  int i_1; // [esp+24h] [ebp-24h]
  int v22; // [esp+2Ch] [ebp-1Ch]
  int v23; // [esp+2Ch] [ebp-1Ch]
  int v24; // [esp+30h] [ebp-18h]
  int v25; // [esp+34h] [ebp-14h]
  int v26; // [esp+38h] [ebp-10h]
  int v27; // [esp+50h] [ebp+8h]

  this_1 = this;
  v3 = 0;
  v4 = 0;
  result = 0;
  v18 = 0;
  v16 = 0;
  v17 = 0;
  v24 = 0;
  if ( *(this + 2) > 0 )
  {
    v6 = 0;
    v22 = 0;
    do
    {
      v7 = (_DWORD *)(v6 + this_1[4]);
      v19 = v7;
      if ( v4 == result )
      {
        v8 = 2 * v4;
        if ( !v4 )
          v8 = 1;
        v25 = v8;
        if ( result < v8 )
        {
          if ( v8 )
          {
            v3 = v18;
            v4 = v16;
            v9 = sub_9D4CE0(16 * v8, 16);
            v26 = v9;
          }
          else
          {
            v9 = 0;
            v26 = 0;
          }
          if ( v4 > 0 )
          {
            n8 = (_DWORD *)(v9 + 8);
            do
            {
              if ( n8 != (_DWORD *)8 )
              {
                v11 = (_DWORD *)((char *)n8 + v3 - v9 - 8);
                *(n8 - 2) = *v11;
                *(n8 - 1) = v11[1];
                *n8 = v11[2];
                n8[1] = v11[3];
                v3 = v18;
              }
              n8 += 4;
              --v4;
            }
            while ( v4 );
            v4 = v16;
            this_1 = this;
          }
          if ( v3 )
          {
            sub_9D4D50(v3);
            v4 = v16;
          }
          v3 = v26;
          result = v25;
          v7 = v19;
          v18 = v26;
          v17 = v25;
        }
      }
      v12 = (_DWORD *)(v3 + 16 * v4);
      if ( v12 )
      {
        *v12 = *v7;
        v12[1] = v7[1];
        v12[2] = v7[2];
        v12[3] = v7[3];
        v3 = v18;
        result = v17;
        v4 = v16;
      }
      ++v4;
      v6 = v22 + 16;
      v16 = v4;
      ++v24;
      v22 += 16;
    }
    while ( v24 < this_1[2] );
  }
  v23 = 0;
  if ( v4 > 0 )
  {
    for ( i = 0; ; i = i_1 )
    {
      (*(void (__thiscall **)(int *, _DWORD, _DWORD, int))(*this_1 + 8))(
        this_1,
        *(_DWORD *)(i + v3),
        *(_DWORD *)(i + v3 + 4),
        a2);
      v3 = v18;
      result = v23 + 1;
      i_1 = i + 16;
      v4 = v16;
      v23 = result;
      if ( result >= v16 )
        break;
    }
  }
  v14 = 0;
  if ( this_1[14] > 0 )
  {
    do
    {
      result = this_1[16];
      ++v14;
      *(_DWORD *)(result + 4 * v14 - 4) = -1;
    }
    while ( v14 < this_1[14] );
    v3 = v18;
    v4 = v16;
  }
  LOBYTE(a2) = 0;
  if ( v4 > 1 )
  {
    result = sub_9765F0(a2, 0, v4 - 1);
    v3 = v18;
    v4 = v16;
  }
  v27 = 0;
  if ( v4 > 0 )
  {
    v15 = 0;
    do
    {
      (*(void (__thiscall **)(int *, _DWORD, _DWORD))(*this_1 + 4))(
        this_1,
        *(_DWORD *)(v15 + v3),
        *(_DWORD *)(v15 + v3 + 4));
      v3 = v18;
      result = v27 + 1;
      v27 = result;
      v15 += 16;
    }
    while ( result < v16 );
  }
  if ( v3 )
    return sub_9D4D50(v3);
  return result;
}

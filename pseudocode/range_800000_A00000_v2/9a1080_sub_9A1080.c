// Function: sub_9A1080
// Address: 0x9a1080
_DWORD *__thiscall sub_9A1080(int this, int a2, int a3)
{
  int v3; // ebx
  int v5; // ecx
  int v6; // edx
  int v7; // edi
  int v8; // edi
  int v9; // eax
  int v10; // ecx
  int v11; // ecx
  int v12; // edx
  int v14; // ebx
  _DWORD *n8; // edx
  int v16; // edi
  _DWORD *v17; // ecx
  int v18; // ecx
  _DWORD *v19; // edi
  int v20; // [esp+Ch] [ebp-20h]
  int v21; // [esp+10h] [ebp-1Ch]
  int v22; // [esp+14h] [ebp-18h]
  int v23; // [esp+18h] [ebp-14h]
  int v24; // [esp+20h] [ebp-Ch]
  int v25; // [esp+24h] [ebp-8h]
  int v26; // [esp+24h] [ebp-8h]
  int v27; // [esp+28h] [ebp-4h]
  int v28; // [esp+28h] [ebp-4h]

  v3 = a2;
  v5 = a3;
  if ( *(_DWORD *)(a2 + 12) > *(_DWORD *)(a3 + 12) )
  {
    v3 = a3;
    v5 = a2;
    a2 = a3;
    a3 = v5;
  }
  v27 = *(_DWORD *)(v5 + 12);
  v21 = *(_DWORD *)(v3 + 12) | (v27 << 16);
  v25 = *(_DWORD *)(v3 + 12);
  v22 = *(_DWORD *)(this + 12);
  v24 = (v22 - 1)
      & ((~((((9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))) >> 6)
           ^ (9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21)))) << 11)
        + (((9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))) >> 6)
         ^ (9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21)))))
       ^ ((~((((9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))) >> 6)
            ^ (9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21)))) << 11)
         + (((9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))) >> 6)
          ^ (9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))))) >> 16));
  v6 = *(_DWORD *)(*(_DWORD *)(this + 44) + 4 * v24);
  if ( v6 != -1 )
  {
    v7 = *(_DWORD *)(this + 16);
    while ( 1 )
    {
      v3 = a2;
      if ( *(_DWORD *)(*(_DWORD *)(v7 + 16 * v6) + 12) == v25 && *(_DWORD *)(*(_DWORD *)(v7 + 16 * v6 + 4) + 12) == v27 )
        break;
      v6 = *(_DWORD *)(*(_DWORD *)(this + 64) + 4 * v6);
      if ( v6 == -1 )
        goto LABEL_8;
    }
    v12 = v7 + 16 * v6;
    if ( v12 )
      return (_DWORD *)v12;
  }
LABEL_8:
  v8 = *(_DWORD *)(this + 8);
  v20 = v8;
  v9 = *(_DWORD *)(this + 12);
  v23 = v8;
  if ( v8 == v9 )
  {
    v10 = 2 * v8;
    if ( !v8 )
      v10 = 1;
    v26 = v10;
    if ( v9 < v10 )
    {
      if ( v10 )
      {
        v11 = sub_9D4CE0(16 * v10, 16);
        v28 = v11;
      }
      else
      {
        v11 = 0;
        v28 = 0;
      }
      v14 = *(_DWORD *)(this + 8);
      if ( v14 > 0 )
      {
        n8 = (_DWORD *)(v11 + 8);
        v16 = -8 - v11;
        do
        {
          if ( n8 != (_DWORD *)8 )
          {
            v17 = (_DWORD *)((char *)n8 + v16 + *(_DWORD *)(this + 16));
            *(n8 - 2) = *v17;
            *(n8 - 1) = v17[1];
            *n8 = v17[2];
            n8[1] = v17[3];
          }
          n8 += 4;
          --v14;
        }
        while ( v14 );
        v8 = v23;
      }
      if ( *(_DWORD *)(this + 16) )
      {
        if ( *(_BYTE *)(this + 20) )
          sub_9D4D50(*(_DWORD *)(this + 16));
        *(_DWORD *)(this + 16) = 0;
      }
      v3 = a2;
      *(_DWORD *)(this + 16) = v28;
      *(_BYTE *)(this + 20) = 1;
      *(_DWORD *)(this + 12) = v26;
    }
  }
  ++*(_DWORD *)(this + 8);
  v18 = *(_DWORD *)(this + 72);
  v19 = (_DWORD *)(*(_DWORD *)(this + 16) + 16 * v8);
  if ( v18 )
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v18 + 4))(v18, v3, a3);
  if ( v22 < *(_DWORD *)(this + 12) )
  {
    sub_9A0E50((void *)this);
    v24 = (*(_DWORD *)(this + 12) - 1)
        & ((~((((9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))) >> 6)
             ^ (9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21)))) << 11)
          + (((9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))) >> 6)
           ^ (9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21)))))
         ^ ((~((((9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))) >> 6)
              ^ (9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21)))) << 11)
           + (((9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))) >> 6)
            ^ (9 * (((~(v21 << 15) + v21) >> 10) ^ (~(v21 << 15) + v21))))) >> 16));
  }
  if ( v19 )
  {
    if ( *(_DWORD *)(v3 + 12) >= *(_DWORD *)(a3 + 12) )
    {
      *v19 = a3;
      v19[1] = v3;
    }
    else
    {
      *v19 = v3;
      v19[1] = a3;
    }
    v19[2] = 0;
    v19[3] = 0;
  }
  else
  {
    v19 = 0;
  }
  v19[2] = 0;
  v19[3] = 0;
  *(_DWORD *)(*(_DWORD *)(this + 64) + 4 * v20) = *(_DWORD *)(*(_DWORD *)(this + 44) + 4 * v24);
  *(_DWORD *)(*(_DWORD *)(this + 44) + 4 * v24) = v20;
  return v19;
}

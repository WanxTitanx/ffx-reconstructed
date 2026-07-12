// Function: sub_982450
// Address: 0x982450
int __thiscall sub_982450(int this, _DWORD *a2, _DWORD *a3)
{
  int v4; // eax
  int v5; // ecx
  int result; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // edi
  int v12; // edx
  _DWORD *v13; // ecx
  _DWORD *v14; // ecx
  int v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // ebx
  int v20; // edi
  _DWORD *v21; // edx
  int v22; // ecx
  _DWORD *v23; // ecx
  int v24; // edx
  int v25; // [esp+8h] [ebp-10h]
  int v26; // [esp+Ch] [ebp-Ch]
  int v27; // [esp+10h] [ebp-8h]
  int v28; // [esp+14h] [ebp-4h]
  int v29; // [esp+14h] [ebp-4h]
  int v30; // [esp+24h] [ebp+Ch]

  v4 = (~(*a2 << 15) + *a2) ^ ((~(*a2 << 15) + *a2) >> 10);
  v5 = ~((((9 * v4) >> 6) ^ (9 * v4)) << 11) + (((9 * v4) >> 6) ^ (9 * v4));
  v27 = *(_DWORD *)(this + 48);
  v26 = (v27 - 1) & (v5 ^ (v5 >> 16));
  result = sub_981F90((_DWORD *)this, a2);
  if ( result == -1 )
  {
    v7 = *(_DWORD *)(this + 44);
    v8 = *(_DWORD *)(this + 48);
    v25 = v7;
    if ( v7 == v8 )
    {
      v9 = 2 * v7;
      if ( !v7 )
        v9 = 1;
      if ( v8 < v9 )
      {
        if ( v9 )
          v10 = sub_9D4CE0(4 * v9, 16);
        else
          v10 = 0;
        v11 = *(_DWORD *)(this + 44);
        v12 = 0;
        v28 = v10;
        if ( v11 > 0 )
        {
          v13 = (_DWORD *)v10;
          do
          {
            if ( v13 )
              *v13 = *(_DWORD *)(*(_DWORD *)(this + 52) + 4 * v12);
            ++v12;
            ++v13;
          }
          while ( v12 < v11 );
        }
        if ( *(_DWORD *)(this + 52) )
        {
          if ( *(_BYTE *)(this + 56) )
            sub_9D4D50(*(_DWORD *)(this + 52));
          *(_DWORD *)(this + 52) = 0;
        }
        *(_BYTE *)(this + 56) = 1;
        *(_DWORD *)(this + 52) = v28;
        *(_DWORD *)(this + 48) = v9;
      }
    }
    v14 = (_DWORD *)(*(_DWORD *)(this + 52) + 4 * *(_DWORD *)(this + 44));
    if ( v14 )
      *v14 = *a3;
    ++*(_DWORD *)(this + 44);
    v15 = *(_DWORD *)(this + 68);
    v16 = *(_DWORD *)(this + 64);
    if ( v16 == v15 )
    {
      v17 = v16 ? 2 * v16 : 1;
      v29 = v17;
      if ( v15 < v17 )
      {
        if ( v17 )
          v18 = sub_9D4CE0(8 * v17, 16);
        else
          v18 = 0;
        v19 = *(_DWORD *)(this + 64);
        v20 = 0;
        v30 = v18;
        if ( v19 > 0 )
        {
          v21 = (_DWORD *)v18;
          do
          {
            if ( v21 )
            {
              v22 = *(_DWORD *)(this + 72);
              *v21 = *(_DWORD *)(v22 + 8 * v20);
              v21[1] = *(_DWORD *)(v22 + 8 * v20 + 4);
            }
            ++v20;
            v21 += 2;
          }
          while ( v20 < v19 );
        }
        if ( *(_DWORD *)(this + 72) )
        {
          if ( *(_BYTE *)(this + 76) )
            sub_9D4D50(*(_DWORD *)(this + 72));
          *(_DWORD *)(this + 72) = 0;
        }
        *(_DWORD *)(this + 72) = v30;
        *(_BYTE *)(this + 76) = 1;
        *(_DWORD *)(this + 68) = v29;
      }
    }
    v23 = (_DWORD *)(*(_DWORD *)(this + 72) + 8 * *(_DWORD *)(this + 64));
    if ( v23 )
    {
      *v23 = *a2;
      v23[1] = a2[1];
    }
    ++*(_DWORD *)(this + 64);
    if ( v27 >= *(_DWORD *)(this + 48) )
    {
      v24 = v26;
    }
    else
    {
      sub_9821F0(this, (int)a2);
      v24 = (*(_DWORD *)(this + 48) - 1)
          & ((~((((9 * ((~(*a2 << 15) + *a2) ^ ((~(*a2 << 15) + *a2) >> 10))) >> 6)
               ^ (9 * ((~(*a2 << 15) + *a2) ^ ((~(*a2 << 15) + *a2) >> 10)))) << 11)
            + (((9 * ((~(*a2 << 15) + *a2) ^ ((~(*a2 << 15) + *a2) >> 10))) >> 6)
             ^ (9 * ((~(*a2 << 15) + *a2) ^ ((~(*a2 << 15) + *a2) >> 10)))))
           ^ ((~((((9 * ((~(*a2 << 15) + *a2) ^ ((~(*a2 << 15) + *a2) >> 10))) >> 6)
                ^ (9 * ((~(*a2 << 15) + *a2) ^ ((~(*a2 << 15) + *a2) >> 10)))) << 11)
             + (((9 * ((~(*a2 << 15) + *a2) ^ ((~(*a2 << 15) + *a2) >> 10))) >> 6)
              ^ (9 * ((~(*a2 << 15) + *a2) ^ ((~(*a2 << 15) + *a2) >> 10))))) >> 16));
    }
    *(_DWORD *)(*(_DWORD *)(this + 32) + 4 * v25) = *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * v24);
    result = *(_DWORD *)(this + 12);
    *(_DWORD *)(result + 4 * v24) = v25;
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)(this + 52) + 4 * result) = *a3;
  }
  return result;
}

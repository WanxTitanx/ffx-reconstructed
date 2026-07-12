// Function: sub_99B440
// Address: 0x99b440
char __thiscall sub_99B440(int this, int a2, int a3)
{
  _DWORD *v4; // eax
  int v5; // esi
  int v6; // ecx
  int v7; // esi
  int v8; // edi
  _DWORD *v9; // ecx
  int i_1; // eax
  int i_2; // edx
  int v12; // ecx
  int v13; // esi
  int v14; // edx
  int v15; // edi
  _DWORD *v16; // esi
  int v18; // [esp+8h] [ebp-10h]
  _DWORD *v19; // [esp+Ch] [ebp-Ch]
  int i; // [esp+10h] [ebp-8h]
  int v21; // [esp+10h] [ebp-8h]
  _DWORD *v22; // [esp+14h] [ebp-4h]
  int v23; // [esp+14h] [ebp-4h]
  int v24; // [esp+20h] [ebp+8h]
  int v25; // [esp+24h] [ebp+Ch]

  LOBYTE(v4) = *(_BYTE *)(this + 28);
  v5 = a3;
  v6 = a2;
  if ( (_BYTE)v4 )
  {
    v6 = a3;
    v5 = a2;
  }
  v25 = v5;
  v7 = *(_DWORD *)(this + 12);
  v19 = *(_DWORD **)(v6 + 204);
  v8 = v19[4];
  v24 = v6;
  v18 = v8;
  if ( v8 >= v7 )
  {
    if ( v8 > v7 && *(_DWORD *)(this + 16) < v8 )
    {
      if ( v8 )
      {
        v9 = (_DWORD *)sub_9D4CE0(4 * v8, 16);
        v22 = v9;
      }
      else
      {
        v9 = 0;
        v22 = 0;
      }
      i_1 = *(_DWORD *)(this + 12);
      i_2 = 0;
      for ( i = i_1; i_2 < i_1; ++v9 )
      {
        if ( v9 )
        {
          *v9 = *(_DWORD *)(*(_DWORD *)(this + 20) + 4 * i_2);
          i_1 = i;
        }
        ++i_2;
      }
      if ( *(_DWORD *)(this + 20) )
      {
        if ( *(_BYTE *)(this + 24) )
          sub_9D4D50(*(_DWORD *)(this + 20));
        *(_DWORD *)(this + 20) = 0;
      }
      LOBYTE(v4) = (_BYTE)v22;
      *(_BYTE *)(this + 24) = 1;
      *(_DWORD *)(this + 20) = v22;
      *(_DWORD *)(this + 16) = v8;
    }
    for ( ; v7 < v8; ++v7 )
    {
      v4 = (_DWORD *)(*(_DWORD *)(this + 20) + 4 * v7);
      if ( v4 )
        *v4 = 0;
    }
  }
  v12 = 0;
  *(_DWORD *)(this + 12) = v8;
  v23 = 0;
  if ( v8 > 0 )
  {
    v13 = v24;
    v14 = 0;
    v21 = 0;
    do
    {
      if ( v19[16] )
      {
        v4 = *(_DWORD **)(this + 20);
        v4[v12] = 0;
      }
      else
      {
        v15 = *(_DWORD *)(v13 + 204);
        *(_DWORD *)(v24 + 204) = *(_DWORD *)(v19[6] + v14 + 64);
        v16 = (_DWORD *)(*(_DWORD *)(this + 20) + 4 * v12);
        v4 = (_DWORD *)(*(int (__thiscall **)(_DWORD, int, int, _DWORD))(**(_DWORD **)(this + 4) + 4))(
                         *(_DWORD *)(this + 4),
                         v24,
                         v25,
                         *(_DWORD *)(this + 32));
        v12 = v23;
        v14 = v21;
        *v16 = v4;
        v13 = v24;
        *(_DWORD *)(v24 + 204) = v15;
        v8 = v18;
      }
      ++v12;
      v14 += 80;
      v23 = v12;
      v21 = v14;
    }
    while ( v12 < v8 );
  }
  return (char)v4;
}

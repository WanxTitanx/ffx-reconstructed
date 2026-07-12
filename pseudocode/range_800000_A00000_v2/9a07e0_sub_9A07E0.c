// Function: sub_9A07E0
// Address: 0x9a07e0
_DWORD *__thiscall sub_9A07E0(int this, int a2, int a3)
{
  int v3; // ebx
  int v5; // ecx
  char v6; // al
  int v8; // ecx
  int v9; // esi
  int v10; // eax
  int v11; // eax
  int v12; // ecx
  _DWORD *n8; // edx
  int v14; // ebx
  _DWORD *v15; // ecx
  int v16; // eax
  _DWORD *v17; // esi
  int v18; // eax
  int v19; // [esp+Ch] [ebp-Ch]
  int v20; // [esp+10h] [ebp-8h]
  int v21; // [esp+14h] [ebp-4h]

  v3 = a3;
  v5 = *(_DWORD *)(this + 28);
  if ( v5 )
    v6 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v5 + 4))(v5, a2, a3);
  else
    v6 = (*(_WORD *)(a2 + 4) & *(_WORD *)(a3 + 6)) != 0 && (*(_WORD *)(a2 + 6) & *(_WORD *)(a3 + 4)) != 0;
  if ( !v6 )
    return 0;
  v8 = *(_DWORD *)(this + 12);
  v9 = *(_DWORD *)(this + 8);
  if ( v9 == v8 )
  {
    v10 = 2 * v9;
    if ( !v9 )
      v10 = 1;
    v19 = v10;
    if ( v8 < v10 )
    {
      if ( v10 )
        v11 = sub_9D4CE0(16 * v10, 16);
      else
        v11 = 0;
      v12 = *(_DWORD *)(this + 8);
      v21 = v11;
      v20 = v12;
      if ( v12 > 0 )
      {
        n8 = (_DWORD *)(v11 + 8);
        v14 = -8 - v11;
        do
        {
          if ( n8 != (_DWORD *)8 )
          {
            v15 = (_DWORD *)((char *)n8 + v14 + *(_DWORD *)(this + 16));
            *(n8 - 2) = *v15;
            *(n8 - 1) = v15[1];
            *n8 = v15[2];
            v16 = v15[3];
            v12 = v20;
            n8[1] = v16;
          }
          n8 += 4;
          v20 = --v12;
        }
        while ( v12 );
        v3 = a3;
      }
      if ( *(_DWORD *)(this + 16) )
      {
        if ( *(_BYTE *)(this + 20) )
          sub_9D4D50(*(_DWORD *)(this + 16));
        *(_DWORD *)(this + 16) = 0;
      }
      *(_DWORD *)(this + 16) = v21;
      *(_BYTE *)(this + 20) = 1;
      *(_DWORD *)(this + 12) = v19;
    }
  }
  ++*(_DWORD *)(this + 8);
  v17 = (_DWORD *)(*(_DWORD *)(this + 16) + 16 * v9);
  if ( v17 )
  {
    if ( *(_DWORD *)(a2 + 12) >= *(_DWORD *)(v3 + 12) )
    {
      *v17 = v3;
      v17[1] = a2;
    }
    else
    {
      *v17 = a2;
      v17[1] = v3;
    }
    v17[2] = 0;
    v17[3] = 0;
  }
  else
  {
    v17 = 0;
  }
  ++unk_193F640;
  ++unk_193F638;
  v18 = *(_DWORD *)(this + 32);
  if ( v18 )
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v18 + 4))(v18, a2, v3);
  return v17;
}

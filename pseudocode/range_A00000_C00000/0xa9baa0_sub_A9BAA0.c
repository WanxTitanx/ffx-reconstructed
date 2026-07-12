// Function: sub_A9BAA0
// Address: 0xa9baa0
// Size: 0xc9
// Prototype: 

int __thiscall sub_A9BAA0(int this)
{
  int v2; // ecx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  int v7; // esi
  int v8; // ebx
  int v9; // eax
  int v10; // esi
  int v11; // eax
  int v13; // ecx
  int v14; // esi
  int v15; // eax
  _DWORD *i; // ecx
  int v17; // [esp+Ch] [ebp-Ch]
  _DWORD *v18; // [esp+14h] [ebp-4h]

  v2 = **(_DWORD **)(this + 104);
  v3 = *(_DWORD *)(this + 48);
  v4 = *(_DWORD *)(this + 40);
  v18 = *(_DWORD **)(*(_DWORD *)(this + 4) + 28);
  v5 = v18[v4] / 4;
  v6 = v3 - v5;
  v7 = v5 + v3;
  v17 = v2;
  if ( v4 )
  {
    v8 = v18[*(_DWORD *)(this + 36)] / -4 + v6;
    v9 = v18[*(_DWORD *)(this + 44)] / 4;
  }
  else
  {
    v9 = *v18 / 4;
    v8 = v6 - v9;
  }
  v10 = v9 + v7;
  v11 = *(_DWORD *)(v2 + 172);
  if ( v11 >= v8 && v11 < v10 )
    return 1;
  v13 = *(_DWORD *)(v2 + 8);
  v14 = v10 / v13;
  v15 = v8 / v13;
  if ( v8 / v13 < v14 )
  {
    for ( i = (_DWORD *)(*(_DWORD *)(v17 + 160) + 4 * v15); !*i; ++i )
    {
      if ( ++v15 >= v14 )
        return 0;
    }
    return 1;
  }
  return 0;
}


// Function: sub_A9BB70
// Address: 0xa9bb70
// Size: 0x221
// Prototype: 

int __thiscall sub_A9BB70(int this)
{
  int this_1; // edi
  int v2; // esi
  int v3; // ebx
  int v4; // edx
  int v5; // eax
  void *v6; // eax
  int n24; // eax
  char v8; // cl
  int v9; // edi
  int v10; // edx
  int v11; // eax
  int v12; // ebx
  int v13; // ecx
  int v14; // edi
  int v15; // edx
  int v16; // ecx
  int v19; // [esp+Ch] [ebp-14h]
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+10h] [ebp-10h]
  int v22; // [esp+14h] [ebp-Ch]
  int v23; // [esp+18h] [ebp-8h]
  int v24; // [esp+18h] [ebp-8h]
  int v25; // [esp+18h] [ebp-8h]
  _DWORD *v26; // [esp+1Ch] [ebp-4h]

  this_1 = this;
  v2 = **(_DWORD **)(this + 104);
  v26 = *(_DWORD **)(*(_DWORD *)(this + 4) + 28);
  v3 = *(_DWORD *)(v2 + 168) / *(_DWORD *)(v2 + 8);
  v4 = *(_DWORD *)(this + 20) / *(_DWORD *)(v2 + 8) - 4;
  if ( v3 < 0 )
    v3 = 0;
  v5 = *(_DWORD *)(this + 20) / *(_DWORD *)(v2 + 8) + 2;
  v20 = *(_DWORD *)(this + 20) / *(_DWORD *)(v2 + 8) - 4;
  if ( v5 > *(_DWORD *)(v2 + 164) )
  {
    *(_DWORD *)(v2 + 164) = v5;
    v6 = realloc_0(*(void **)(v2 + 160), 4 * v5);
    v4 = v20;
    *(_DWORD *)(v2 + 160) = v6;
  }
  if ( v3 < v4 )
  {
    do
    {
      n24 = ++*(_DWORD *)(v2 + 156);
      v8 = 0;
      if ( n24 > 24 )
        n24 = 24;
      v9 = 0;
      v23 = 0;
      *(_DWORD *)(v2 + 156) = n24;
      if ( *(int *)v2 > 0 )
      {
        v10 = 0;
        v22 = 0;
        do
        {
          v11 = sub_A9B250(
                  (float *)v2,
                  (int)(v26 + 717),
                  *(_DWORD *)(*(_DWORD *)(this + 8) + 4 * v9) + 4 * v3 * *(_DWORD *)(v2 + 8),
                  v2 + 40,
                  v10 + *(_DWORD *)(v2 + 152));
          v8 = v11 | v23;
          ++v9;
          v10 = v22 + 1008;
          v23 |= v11;
          v22 += 1008;
        }
        while ( v9 < *(_DWORD *)v2 );
        v4 = v20;
      }
      *(_DWORD *)(*(_DWORD *)(v2 + 160) + 4 * v3 + 8) = 0;
      if ( (v8 & 1) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)(v2 + 160) + 4 * v3) = 1;
        *(_DWORD *)(*(_DWORD *)(v2 + 160) + 4 * v3 + 4) = 1;
      }
      if ( (v8 & 2) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)(v2 + 160) + 4 * v3) = 1;
        if ( v3 > 0 )
          *(_DWORD *)(*(_DWORD *)(v2 + 160) + 4 * v3 - 4) = 1;
      }
      if ( (v8 & 4) != 0 )
        *(_DWORD *)(v2 + 156) = -1;
      ++v3;
    }
    while ( v3 < v4 );
    this_1 = this;
  }
  v12 = *(_DWORD *)(v2 + 8);
  v24 = v4 * v12;
  *(_DWORD *)(v2 + 168) = v4 * v12;
  v19 = *(_DWORD *)(this_1 + 48);
  v13 = v26[*(_DWORD *)(this_1 + 40)] / 4 + v19 + v26[1] / 2;
  v14 = *(_DWORD *)(v2 + 176);
  v15 = v13 + *v26 / 4;
  v21 = v15;
  v25 = v24 - v12;
  if ( v14 >= v25 )
    return -1;
  while ( v14 < v15 )
  {
    v16 = *(_DWORD *)(v2 + 160);
    *(_DWORD *)(v2 + 176) = v14;
    if ( *(_DWORD *)(v16 + 4 * (v14 / v12)) && v14 > v19 )
    {
      *(_DWORD *)(v2 + 172) = v14;
      return 0;
    }
    v14 += v12;
    if ( v14 >= v25 )
      return -1;
    v15 = v21;
  }
  return 1;
}


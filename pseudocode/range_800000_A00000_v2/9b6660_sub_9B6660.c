// Function: sub_9B6660
// Address: 0x9b6660
int __thiscall sub_9B6660(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *this_1; // esi
  int v5; // edx
  int v6; // eax
  int v7; // edi
  int *i; // ecx
  int v9; // esi
  int v10; // edx
  int v11; // eax
  int v12; // ebx
  int j; // esi
  int v14; // ecx
  int v15; // eax
  int v16; // ecx
  int result; // eax
  int v19; // [esp+10h] [ebp-10h]
  int v20; // [esp+14h] [ebp-Ch]
  int v21; // [esp+18h] [ebp-8h]
  int v22; // [esp+1Ch] [ebp-4h]

  this_1 = this;
  v19 = a4;
  v22 = a3;
  v5 = a3;
  v6 = *(_DWORD *)(*(this + 3) + 4 * ((a3 + a4) / 2));
  v21 = v6;
  do
  {
    v7 = *(_DWORD *)(*(_DWORD *)(v6 + 20) + 220);
    v20 = this_1[3];
    for ( i = (int *)(v20 + 4 * v5); ; ++i )
    {
      v9 = *i;
      if ( v7 < 0 )
        v10 = *(_DWORD *)(*(_DWORD *)(v21 + 24) + 220);
      else
        v10 = v7;
      v11 = *(_DWORD *)(*(_DWORD *)(v9 + 20) + 220);
      if ( v11 < 0 )
        v11 = *(_DWORD *)(*(_DWORD *)(v9 + 24) + 220);
      if ( v11 >= v10 )
        break;
      ++v22;
    }
    v12 = v19;
    for ( j = v20 + 4 * v19; ; j -= 4 )
    {
      v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)j + 20) + 220);
      if ( v14 < 0 )
        v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)j + 24) + 220);
      v15 = *(int *)(*(_DWORD *)(v21 + 20) + 220) < 0
          ? *(_DWORD *)(*(_DWORD *)(v21 + 24) + 220)
          : *(_DWORD *)(*(_DWORD *)(v21 + 20) + 220);
      if ( v15 >= v14 )
        break;
      --v12;
    }
    v5 = v22;
    if ( v22 > v12 )
      break;
    v5 = v22 + 1;
    v16 = *(_DWORD *)(v20 + 4 * (v22 + 1) - 4);
    *(_DWORD *)(v20 + 4 * v5 - 4) = *(_DWORD *)(v20 + 4 * v12);
    this_1 = this;
    --v12;
    ++v22;
    *(_DWORD *)(*(this + 3) + 4 * v12 + 4) = v16;
    v6 = v21;
    v19 = v12;
  }
  while ( v5 <= v12 );
  if ( a3 < v12 )
  {
    sub_9B6660(a2, a3, v12);
    v5 = v22;
  }
  result = a4;
  if ( v5 < a4 )
    return sub_9B6660(a2, v5, a4);
  return result;
}

// Function: sub_A8D8F0
// Address: 0xa8d8f0
// Size: 0x150
// Prototype: 

int __thiscall sub_A8D8F0(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // esi
  _DWORD *this_1; // edi
  int v6; // eax
  int v7; // ecx
  int v8; // ebx
  int v9; // edi
  int i; // esi
  int v11; // edx
  int v12; // eax
  int v13; // eax
  int v14; // ebx
  int *j; // ecx
  int v16; // esi
  int v17; // edx
  int v18; // eax
  int v19; // ecx
  int result; // eax
  int v22; // [esp+10h] [ebp-10h]
  int v23; // [esp+14h] [ebp-Ch]
  int v24; // [esp+18h] [ebp-8h]
  int v25; // [esp+1Ch] [ebp-4h]
  int v26; // [esp+1Ch] [ebp-4h]

  v22 = a4;
  v4 = a3;
  this_1 = this;
  v6 = *(_DWORD *)(*(this + 3) + 4 * ((a3 + a4) / 2));
  v25 = a3;
  v24 = v6;
  do
  {
    v7 = this_1[3];
    v8 = v25;
    v9 = *(_DWORD *)(*(_DWORD *)(v6 + 1168) + 220);
    v23 = v7;
    for ( i = v7 + 4 * v4; ; i += 4 )
    {
      v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)i + 1168) + 220);
      if ( v11 < 0 )
        v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)i + 1172) + 220);
      v12 = v9 < 0 ? *(_DWORD *)(*(_DWORD *)(v24 + 1172) + 220) : v9;
      if ( v11 >= v12 )
        break;
      ++v8;
    }
    v13 = v24;
    v26 = v8;
    v14 = v22;
    for ( j = (int *)(v7 + 4 * v22); ; --j )
    {
      v16 = *j;
      if ( *(int *)(*(_DWORD *)(v24 + 1168) + 220) < 0 )
        v17 = *(_DWORD *)(*(_DWORD *)(v13 + 1172) + 220);
      else
        v17 = *(_DWORD *)(*(_DWORD *)(v24 + 1168) + 220);
      v18 = *(_DWORD *)(*(_DWORD *)(v16 + 1168) + 220);
      if ( v18 < 0 )
        v18 = *(_DWORD *)(*(_DWORD *)(v16 + 1172) + 220);
      if ( v17 >= v18 )
        break;
      v13 = v24;
      --v14;
    }
    v4 = v26;
    this_1 = this;
    if ( v26 > v14 )
      break;
    v4 = v26 + 1;
    v19 = *(_DWORD *)(v23 + 4 * (v26 + 1) - 4);
    *(_DWORD *)(v23 + 4 * v4 - 4) = *(_DWORD *)(v23 + 4 * v14--);
    *(_DWORD *)(*(this + 3) + 4 * v14 + 4) = v19;
    v6 = v24;
    v25 = v26 + 1;
    v22 = v14;
  }
  while ( v4 <= v14 );
  if ( a3 < v14 )
    sub_A8D8F0(a2, a3, v14);
  result = a4;
  if ( v4 < a4 )
    return sub_A8D8F0(a2, v4, a4);
  return result;
}


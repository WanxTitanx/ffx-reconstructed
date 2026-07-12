// Function: sub_A8E520
// Address: 0xa8e520
// Size: 0xc6
// Prototype: 

int __thiscall sub_A8E520(_DWORD *this, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // edi
  _DWORD *this_1; // edx
  int v7; // ebx
  int v8; // edx
  _DWORD *i; // eax
  _DWORD *j; // eax
  int v11; // ecx
  int v12; // edx
  int v13; // eax
  int result; // eax
  int v15; // [esp+Ch] [ebp-10h]
  int v16; // [esp+14h] [ebp-8h]

  v4 = a3;
  v5 = a4;
  this_1 = this;
  v7 = *(_DWORD *)(*(this + 3) + 8 * ((a3 + a4) / 2));
  v15 = v7;
  while ( 1 )
  {
    v8 = this_1[3];
    v16 = v8;
    for ( i = (_DWORD *)(v8 + 8 * v4); *i < v7; ++v4 )
      i += 2;
    for ( j = (_DWORD *)(v8 + 8 * v5); v7 < *j; --v5 )
      j -= 2;
    if ( v4 > v5 )
      break;
    v11 = *(_DWORD *)(v8 + 8 * v4);
    v12 = *(_DWORD *)(v8 + 8 * v4++ + 4);
    *(_DWORD *)(v16 + 8 * v4 - 8) = *(_DWORD *)(v16 + 8 * v5--);
    *(_DWORD *)(v16 + 8 * v4 - 4) = *(_DWORD *)(v16 + 8 * v5 + 12);
    v7 = v15;
    v13 = *(this + 3);
    *(_DWORD *)(v13 + 8 * v5 + 8) = v11;
    *(_DWORD *)(v13 + 8 * v5 + 12) = v12;
    if ( v4 > v5 )
      break;
    this_1 = this;
  }
  if ( a3 < v5 )
    sub_A8E520(a2, a3, v5);
  result = a4;
  if ( v4 < a4 )
    return sub_A8E520(a2, v4, a4);
  return result;
}


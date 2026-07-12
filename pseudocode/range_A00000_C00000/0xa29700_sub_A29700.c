// Function: sub_A29700
// Address: 0xa29700
// Size: 0x67
// Prototype: 

double __thiscall sub_A29700(_DWORD *this, int a2, _DWORD *a3)
{
  int v3; // esi
  int v4; // edx
  _DWORD *i; // ecx
  float v7; // [esp+14h] [ebp+8h]

  v3 = *(_DWORD *)(a2 + 4);
  if ( v3 <= 0 )
    return 0.0;
  v4 = 0;
  for ( i = (_DWORD *)(*(_DWORD *)(*(_DWORD *)(*(this + 86) + 48) + 28) + 4 * *(_DWORD *)(a2 + 8)); *a3 != *i; i += 3 )
  {
    if ( ++v4 >= v3 )
      return 0.0;
  }
  v7 = (float)(int)i[1];
  return (float)(v7 * 0.015625);
}


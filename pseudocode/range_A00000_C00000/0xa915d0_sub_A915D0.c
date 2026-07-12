// Function: sub_A915D0
// Address: 0xa915d0
// Size: 0xe1
// Prototype: 

int __thiscall sub_A915D0(int *this)
{
  void *v2; // esp
  int v3; // esi
  void *v4; // esp
  int n32; // eax
  int i_1; // edx
  int v7; // ecx
  _DWORD *v8; // edx
  int v9; // ecx
  _DWORD *v10; // edx
  int v11; // eax
  _DWORD v12[20]; // [esp-40h] [ebp-54h] BYREF
  int i; // [esp+10h] [ebp-4h]

  v2 = alloca(64);
  v3 = *(this + 5);
  v12[19] = v12;
  v4 = alloca(4 * v3);
  n32 = v3 - *(this + 12);
  *(this + 7) = 1;
  if ( n32 > 32 )
  {
    n32 = *(this + 1);
    i_1 = 0;
    for ( i = 0; i_1 < *(_DWORD *)(n32 + 4); i = i_1 )
    {
      v7 = 0;
      if ( v3 > 0 )
      {
        v8 = (_DWORD *)(*(_DWORD *)(*(this + 2) + 4 * i_1) + 4 * (v3 - 1));
        do
          v12[v7++] = *v8--;
        while ( v7 < v3 );
      }
      sub_A9E060(v3 - *(this + 12), 16);
      sub_A9E4F0(16, &v12[*(this + 5) - *(this + 12)], *(this + 12));
      v3 = *(this + 5);
      v9 = 0;
      if ( v3 > 0 )
      {
        v10 = (_DWORD *)(*(_DWORD *)(*(this + 2) + 4 * i) + 4 * (v3 - 1));
        do
        {
          v11 = v12[v9++];
          *v10-- = v11;
        }
        while ( v9 < v3 );
      }
      n32 = *(this + 1);
      i_1 = i + 1;
    }
  }
  return n32;
}


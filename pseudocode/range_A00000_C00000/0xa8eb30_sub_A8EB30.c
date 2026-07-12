// Function: sub_A8EB30
// Address: 0xa8eb30
// Size: 0x7d
// Prototype: int __thiscall(_DWORD)

int __thiscall sub_A8EB30(int *this)
{
  int v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // ecx
  int v6; // edx
  int *v7; // ecx
  int result; // eax
  int v9; // [esp+8h] [ebp-4h]

  v2 = 0;
  v9 = *(this + 1);
  if ( v9 > 0 )
  {
    do
    {
      v3 = *(this + 3);
      v4 = 8 * v2;
      v5 = v2;
      if ( v2 != *(_DWORD *)(8 * v2 + v3) )
      {
        v6 = 8 * v2;
        do
        {
          v7 = (int *)(v3 + 8 * *(_DWORD *)(v6 + v3));
          *(_DWORD *)(v3 + v6) = *v7;
          v5 = *v7;
          v3 = *(this + 3);
          v6 = 8 * v5;
        }
        while ( v5 != *(_DWORD *)(v3 + 8 * v5) );
      }
      ++v2;
      *(_DWORD *)(v4 + *(this + 3)) = v5;
    }
    while ( v2 < v9 );
  }
  result = *(this + 1);
  LOBYTE(v9) = 0;
  if ( result > 1 )
    return sub_A8E520(this, v9, 0, result - 1);
  return result;
}


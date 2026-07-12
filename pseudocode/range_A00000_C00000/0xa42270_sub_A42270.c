// Function: sub_A42270
// Address: 0xa42270
// Size: 0xe1
// Prototype: 

int __thiscall sub_A42270(int this, int a2, int a3, int a4, int a5)
{
  _DWORD *v5; // eax
  unsigned int v6; // esi
  int result; // eax
  unsigned int *v8; // [esp+Ch] [ebp-10h]
  unsigned int v9; // [esp+10h] [ebp-Ch]
  int v10; // [esp+18h] [ebp-4h]

  v10 = ((_BYTE)a2 + (_BYTE)a3) & 0xF;
  v5 = *(_DWORD **)(this + 4 * v10 + 64);
  v8 = (unsigned int *)(this + 4 * v10);
  v6 = 0;
  v9 = *v8;
  if ( *v8 )
  {
    while ( *v5 != a3 || v5[1] != a2 )
    {
      if ( *v5 == a2 && v5[1] == a3 )
        *(_BYTE *)(this + 208) = 1;
      ++v6;
      v5 += 4;
      if ( v6 >= v9 )
        goto LABEL_8;
    }
    if ( v5[3] != -1 )
      *(_BYTE *)(this + 208) = 1;
    v5[3] = a4;
    *(_BYTE *)(3 * a4 + *(_DWORD *)(this + 204) + a5) = v10;
    result = *(_DWORD *)(this + 196);
    *(_DWORD *)(result + 4 * (3 * a4 + a5)) = v6;
  }
  else
  {
LABEL_8:
    *(_BYTE *)(3 * a4 + *(_DWORD *)(this + 204) + a5) = v10;
    *(_DWORD *)(*(_DWORD *)(this + 196) + 4 * (3 * a4 + a5)) = v9;
    v5[2] = a4;
    v5[1] = a3;
    v5[3] = -1;
    *v5 = a2;
    ++*v8;
    return this + 4 * v10;
  }
  return result;
}


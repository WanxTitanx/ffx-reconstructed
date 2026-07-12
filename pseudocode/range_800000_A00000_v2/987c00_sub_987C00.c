// Function: sub_987C00
// Address: 0x987c00
int __thiscall sub_987C00(int this, int a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // edx
  _DWORD *v9; // ecx
  int result; // eax
  _DWORD *v11; // ecx
  int v12; // [esp+4h] [ebp-4h]

  v3 = *(_DWORD *)(this + 8);
  v4 = *(_DWORD *)(this + 4);
  if ( v4 == v3 )
  {
    v5 = 2 * v4;
    if ( !v4 )
      v5 = 1;
    if ( v3 < v5 )
    {
      if ( v5 )
        v6 = sub_9D4CE0(4 * v5, 16);
      else
        v6 = 0;
      v7 = *(_DWORD *)(this + 4);
      v8 = 0;
      v12 = v6;
      if ( v7 > 0 )
      {
        v9 = (_DWORD *)v6;
        do
        {
          if ( v9 )
            *v9 = *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * v8);
          ++v8;
          ++v9;
        }
        while ( v8 < v7 );
      }
      if ( *(_DWORD *)(this + 12) )
      {
        if ( *(_BYTE *)(this + 16) )
          sub_9D4D50(*(_DWORD *)(this + 12));
        *(_DWORD *)(this + 12) = 0;
      }
      *(_BYTE *)(this + 16) = 1;
      *(_DWORD *)(this + 12) = v12;
      *(_DWORD *)(this + 8) = v5;
    }
  }
  result = *(_DWORD *)(this + 12);
  v11 = (_DWORD *)(result + 4 * *(_DWORD *)(this + 4));
  if ( v11 )
  {
    result = a2;
    *v11 = a2;
  }
  ++*(_DWORD *)(this + 4);
  return result;
}

// Function: sub_9B73C0
// Address: 0x9b73c0
int __thiscall sub_9B73C0(int this, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // edx
  _DWORD *v9; // ecx
  int result; // eax
  _DWORD *v11; // ecx
  int v12; // [esp+8h] [ebp-4h]

  v3 = *(_DWORD *)(this + 256);
  v4 = *(_DWORD *)(this + 252);
  if ( v4 == v3 )
  {
    v5 = v4 ? 2 * v4 : 1;
    if ( v3 < v5 )
    {
      if ( v5 )
        v6 = sub_9D4CE0(4 * v5, 16);
      else
        v6 = 0;
      v7 = *(_DWORD *)(this + 252);
      v8 = 0;
      v12 = v6;
      if ( v7 > 0 )
      {
        v9 = (_DWORD *)v6;
        do
        {
          if ( v9 )
            *v9 = *(_DWORD *)(*(_DWORD *)(this + 260) + 4 * v8);
          ++v8;
          ++v9;
        }
        while ( v8 < v7 );
      }
      if ( *(_DWORD *)(this + 260) )
      {
        if ( *(_BYTE *)(this + 264) )
          sub_9D4D50(*(_DWORD *)(this + 260));
        *(_DWORD *)(this + 260) = 0;
      }
      *(_BYTE *)(this + 264) = 1;
      *(_DWORD *)(this + 260) = v12;
      *(_DWORD *)(this + 256) = v5;
    }
  }
  result = *(_DWORD *)(this + 260);
  v11 = (_DWORD *)(result + 4 * *(_DWORD *)(this + 252));
  if ( v11 )
  {
    result = a2;
    *v11 = a2;
  }
  ++*(_DWORD *)(this + 252);
  return result;
}

// Function: LuaGC_MarkTableKeyList
// Address: 0x950310
int __cdecl LuaGC_MarkTableKeyList(int a1, int a2)
{
  int v2; // edi
  unsigned int v3; // edx
  BOOL v4; // ebx
  unsigned int v5; // eax
  int v6; // eax
  bool v7; // zf
  int v8; // eax
  int result; // eax
  unsigned int v10; // [esp+10h] [ebp-4h]

  v2 = a2;
  v3 = *(_DWORD *)(a2 + 16);
  v4 = *(_DWORD *)(a2 + 28) > 0;
  v5 = v3 + 20 * (1 << *(_BYTE *)(a2 + 7));
  v10 = v5;
  if ( v3 < v5 )
  {
    do
    {
      if ( *(_DWORD *)(v3 + 4) )
      {
        if ( (*(_BYTE *)(v3 + 12) & 0x40) != 0 )
        {
          if ( (*(_BYTE *)(*(_DWORD *)(v3 + 8) + 5) & 3) != 0 )
            LuaGC_Mark(a1, *(_DWORD *)(v3 + 8));
          v5 = v10;
        }
        if ( !v4 )
        {
          v6 = *(_DWORD *)(v3 + 4);
          if ( (v6 & 0x40) != 0 )
          {
            v7 = (v6 & 0xF) == 4;
            v8 = *(_DWORD *)v3;
            if ( v7 )
            {
              if ( v8 && (*(_BYTE *)(v8 + 5) & 3) != 0 )
                LuaGC_Mark(a1, *(_DWORD *)v3);
            }
            else
            {
              v4 = (*(_BYTE *)(v8 + 5) & 3) != 0;
            }
          }
          v5 = v10;
        }
      }
      else if ( (*(_BYTE *)(v3 + 12) & 0x40) != 0 )
      {
        v5 = v10;
        if ( (*(_BYTE *)(*(_DWORD *)(v3 + 8) + 5) & 3) != 0 )
          *(_DWORD *)(v3 + 12) = 11;
      }
      v3 += 20;
    }
    while ( v3 < v5 );
    v2 = a2;
  }
  if ( v4 )
  {
    result = *(_DWORD *)(a1 + 80);
    *(_DWORD *)(v2 + 24) = result;
    *(_DWORD *)(a1 + 80) = v2;
  }
  else
  {
    result = *(_DWORD *)(a1 + 76);
    *(_DWORD *)(v2 + 24) = result;
    *(_DWORD *)(a1 + 76) = v2;
  }
  return result;
}

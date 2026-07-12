// Function: LuaGC_MarkTable
// Address: 0x950220
int __cdecl LuaGC_MarkTable(_DWORD *a1, int a2)
{
  int v3; // eax
  _DWORD *Metamethod; // edx
  int v5; // eax
  char *v6; // eax
  char *v8; // [esp+8h] [ebp-4h]
  _DWORD *Metamethod_1; // [esp+18h] [ebp+Ch]

  v3 = *(_DWORD *)(a2 + 8);
  if ( v3 )
  {
    if ( (*(_BYTE *)(v3 + 6) & 8) != 0 )
    {
      Metamethod = 0;
      Metamethod_1 = 0;
    }
    else
    {
      Metamethod = (_DWORD *)LuaV_TryGetMetamethod(v3, 3, a1[42]);
      Metamethod_1 = Metamethod;
    }
  }
  else
  {
    Metamethod = 0;
    Metamethod_1 = 0;
  }
  v5 = *(_DWORD *)(a2 + 8);
  if ( v5 && (*(_BYTE *)(v5 + 5) & 3) != 0 )
    LuaGC_Mark((int)a1, *(_DWORD *)(a2 + 8));
  if ( Metamethod
    && (Metamethod[1] & 0xF) == 4
    && ((v8 = strchr((const char *)(*Metamethod + 16), 107), v6 = strchr((const char *)(*Metamethod_1 + 16), 118), v8)
     || v6) )
  {
    *(_BYTE *)(a2 + 5) &= ~4u;
    if ( v8 )
    {
      if ( v6 )
      {
        *(_DWORD *)(a2 + 24) = a1[22];
        a1[22] = a2;
      }
      else
      {
        LuaGC_MarkTableKeys(a1, a2);
      }
    }
    else
    {
      LuaGC_MarkTableKeyList((int)a1, a2);
    }
  }
  else
  {
    LuaGC_MarkTableDefault((int)a1, a2);
  }
  return 8 * *(_DWORD *)(a2 + 28) + 32 + 20 * (1 << *(_BYTE *)(a2 + 7));
}

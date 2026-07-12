// Function: sub_A0EE00
// Address: 0xa0ee00
// Size: 0x7c
// Prototype: 

int __thiscall sub_A0EE00(int (__thiscall **this)(_DWORD, _DWORD), int a2)
{
  int v3; // ebx
  int v4; // eax
  int v5; // edi
  void *GlobalTypeAccessor; // eax

  v3 = sub_94BF60(a2, -1, 0);
  Lua_Pop(a2, -2);
  v4 = sub_A0B630(a2);
  if ( !v4 )
    return 0;
  v5 = (*(this + 1))(v4, v3);
  GlobalTypeAccessor = Phyre_GetGlobalTypeAccessor();
  if ( v5 )
  {
    PhyreLua_PushPhyreObject(a2, v5, (int)GlobalTypeAccessor);
  }
  else
  {
    sub_94AC00(a2, 1);
    LuaStack_PushSlot(a2);
  }
  return 1;
}


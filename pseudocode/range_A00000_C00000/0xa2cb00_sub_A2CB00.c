// Function: sub_A2CB00
// Address: 0xa2cb00
// Size: 0x16b
// Prototype: 

int __cdecl sub_A2CB00(int a1)
{
  int *v1; // edi
  int v2; // ebx
  int v3; // edi
  _DWORD *v4; // eax
  int v6; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  if ( v1 && (Lua_Pop(a1, -2), v2 = *v1, (v3 = v1[1]) != 0) )
  {
    if ( (dword_1A85144 & 1) == 0 )
    {
      dword_1A85144 |= 1u;
      sub_A2B780(dword_1A850B0);
      unk_1A85140 &= ~2u;
      dword_1A850B0[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable';
      atexit(sub_B090E0);
    }
    if ( v2 )
    {
      v4 = (_DWORD *)v2;
      while ( v4 != dword_1A850B0 )
      {
        v4 = (_DWORD *)v4[16];
        if ( !v4 )
        {
          *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
          *(_DWORD *)&byte_C96298[2052] = 106;
          *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PArray<class"
                                          " Phyre::PText::PBitmapFontCharInfo,4> *>::Get";
          Lua_Error(
            a1,
            "Object pointer obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
            *(const char **)(v2 + 24),
            unk_1A850C8);
        }
      }
    }
    return v3;
  }
  else
  {
    if ( Lua_Type(a1, -1) )
    {
      v6 = Lua_Type(a1, -1);
      *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
      *(_DWORD *)&byte_C96298[2052] = 118;
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PArray<class Phy"
                                      "re::PText::PBitmapFontCharInfo,4> *>::Get";
      Lua_Error(
        a1,
        "Unable to obtain object pointer from script - found another type of data instead (Lua type %d)\n",
        v6);
    }
    Lua_Pop(a1, -2);
    return 0;
  }
}


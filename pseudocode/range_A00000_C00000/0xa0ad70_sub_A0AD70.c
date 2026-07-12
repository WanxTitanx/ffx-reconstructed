// Function: sub_A0AD70
// Address: 0xa0ad70
// Size: 0xd4
// Prototype: 

int __cdecl sub_A0AD70(int a1)
{
  int v1; // edi
  _DWORD *v2; // ecx
  _DWORD *v3; // eax
  int v5; // eax

  v1 = Lua_ToPhyreObject(a1, -1);
  if ( v1 && (Lua_Pop(a1, -2), v2 = *(_DWORD **)v1, *(_DWORD *)(v1 + 4)) )
  {
    if ( v2 )
    {
      v3 = *(_DWORD **)v1;
      while ( v3 != dword_1944478 )
      {
        v3 = (_DWORD *)v3[16];
        if ( !v3 )
        {
          *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
          *(_DWORD *)&byte_C96298[2052] = 106;
          *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcess"
                                          "ing::PLegacyGlowD3D11 *>::Get";
          Lua_Error(
            a1,
            "Object pointer obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
            (const char *)v2[6],
            unk_1944490);
        }
      }
    }
    return *(_DWORD *)(v1 + 4);
  }
  else
  {
    if ( Lua_Type(a1, -1) )
    {
      v5 = Lua_Type(a1, -1);
      *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
      *(_DWORD *)&byte_C96298[2052] = 118;
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing:"
                                      ":PLegacyGlowD3D11 *>::Get";
      Lua_Error(
        a1,
        "Unable to obtain object pointer from script - found another type of data instead (Lua type %d)\n",
        v5);
    }
    Lua_Pop(a1, -2);
    return 0;
  }
}


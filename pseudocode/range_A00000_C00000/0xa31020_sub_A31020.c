// Function: sub_A31020
// Address: 0xa31020
// Size: 0xd4
// Prototype: 

int __cdecl sub_A31020(int a1)
{
  int v1; // edi
  _DWORD *v2; // ecx
  _DWORD *Size; // eax
  int v5; // eax

  v1 = Lua_ToPhyreObject(a1, -1);
  if ( v1 && (Lua_Pop(a1, -2), v2 = *(_DWORD **)v1, *(_DWORD *)(v1 + 4)) )
  {
    if ( v2 )
    {
      Size = *(_DWORD **)v1;
      while ( Size != Size_5 )
      {
        Size = (_DWORD *)Size[16];
        if ( !Size )
        {
          *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
          *(_DWORD *)&byte_C96298[2052] = 106;
          *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::POccluderGeo"
                                          "metry::POccluderGeometryInstance *>::Get";
          Lua_Error(
            a1,
            "Object pointer obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
            (const char *)v2[6],
            unk_1A85438);
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
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::POccluderGeometr"
                                      "y::POccluderGeometryInstance *>::Get";
      Lua_Error(
        a1,
        "Unable to obtain object pointer from script - found another type of data instead (Lua type %d)\n",
        v5);
    }
    Lua_Pop(a1, -2);
    return 0;
  }
}


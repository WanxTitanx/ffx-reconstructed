// Function: sub_A2CC90
// Address: 0xa2cc90
// Size: 0xd4
// Prototype: 

int __cdecl sub_A2CC90(int a1)
{
  int *v1; // edi
  int v2; // ecx
  int v3; // eax
  int v5; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  if ( v1 && (Lua_Pop(a1, -2), v2 = *v1, v1[1]) )
  {
    if ( v2 )
    {
      v3 = *v1;
      while ( (_UNKNOWN *)v3 != &unk_1A84D20 )
      {
        v3 = *(_DWORD *)(v3 + 64);
        if ( !v3 )
        {
          *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
          *(_DWORD *)&byte_C96298[2052] = 106;
          *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PText::PBitmapFont *>::Get";
          Lua_Error(
            a1,
            "Object pointer obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
            *(const char **)(v2 + 24),
            unk_1A84D38);
        }
      }
    }
    return v1[1];
  }
  else
  {
    if ( Lua_Type(a1, -1) )
    {
      v5 = Lua_Type(a1, -1);
      *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
      *(_DWORD *)&byte_C96298[2052] = 118;
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PText::PBitmapFont *>::Get";
      Lua_Error(
        a1,
        "Unable to obtain object pointer from script - found another type of data instead (Lua type %d)\n",
        v5);
    }
    Lua_Pop(a1, -2);
    return 0;
  }
}


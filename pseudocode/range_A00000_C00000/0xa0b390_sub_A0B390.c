// Function: sub_A0B390
// Address: 0xa0b390
// Size: 0xd5
// Prototype: 

int __cdecl sub_A0B390(int a1)
{
  int *v1; // edi
  int v2; // edx
  int v3; // ecx
  int v4; // eax
  int v6; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  if ( v1 && (Lua_Pop(a1, -2), v2 = v1[1], v3 = *v1, v2) )
  {
    if ( v3 )
    {
      v4 = *v1;
      while ( (_UNKNOWN *)v4 != &unk_1943A10 )
      {
        v4 = *(_DWORD *)(v4 + 64);
        if ( !v4 )
        {
          *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
          *(_DWORD *)&byte_C96298[2052] = 106;
          *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcess"
                                          "ing::PMotionBlurBase *>::Get";
          Lua_Error(
            a1,
            "Object pointer obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
            *(const char **)(v3 + 24),
            unk_1943A28);
        }
      }
    }
    return v2 - 4;
  }
  else
  {
    if ( Lua_Type(a1, -1) )
    {
      v6 = Lua_Type(a1, -1);
      *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
      *(_DWORD *)&byte_C96298[2052] = 118;
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing:"
                                      ":PMotionBlurBase *>::Get";
      Lua_Error(
        a1,
        "Unable to obtain object pointer from script - found another type of data instead (Lua type %d)\n",
        v6);
    }
    Lua_Pop(a1, -2);
    return 0;
  }
}


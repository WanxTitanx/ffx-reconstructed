// Function: sub_A08F20
// Address: 0xa08f20
// Size: 0xc1
// Prototype: 

int __cdecl sub_A08F20(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  _DWORD *v4; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  Lua_Pop(a1, -2);
  if ( !v1 )
  {
    Phyre_PObject_ComputeLayout(dword_19442B0);
LABEL_8:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
    *(_DWORD *)&byte_C96298[2052] = 141;
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P"
                                    "LegacyGlowBase &>::Get";
    Lua_Error(
      a1,
      "Object obtained from script was not a Phyre Object when an object of type \"%s\" was required.\n",
      unk_19442C8);
  }
  v2 = *v1;
  v3 = v1[1];
  if ( !v2 )
    goto LABEL_8;
  v4 = (_DWORD *)v2;
  while ( v4 != dword_19442B0 )
  {
    v4 = (_DWORD *)v4[16];
    if ( !v4 )
    {
      *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
      *(_DWORD *)&byte_C96298[2052] = 143;
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing:"
                                      ":PLegacyGlowBase &>::Get";
      Lua_Error(
        a1,
        "Object obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
        *(const char **)(v2 + 24),
        unk_19442C8);
    }
  }
  return v3;
}


// Function: sub_A084B0
// Address: 0xa084b0
// Size: 0xda
// Prototype: 

int __cdecl sub_A084B0(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  Lua_Pop(a1, -2);
  if ( !v1 )
  {
    Phyre_PObject_ComputeLayout(dword_19437B0);
    goto LABEL_11;
  }
  v2 = *v1;
  v3 = v1[1];
  if ( v3 )
    v4 = v3 - 4;
  else
    v4 = 0;
  if ( !v2 )
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
    *(_DWORD *)&byte_C96298[2052] = 141;
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P"
                                    "DeferredLightingD3D11 &>::Get";
    Lua_Error(
      a1,
      "Object obtained from script was not a Phyre Object when an object of type \"%s\" was required.\n",
      unk_19437C8);
  }
  v5 = (_DWORD *)v2;
  while ( v5 != dword_19437B0 )
  {
    v5 = (_DWORD *)v5[16];
    if ( !v5 )
    {
      *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
      *(_DWORD *)&byte_C96298[2052] = 143;
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing:"
                                      ":PDeferredLightingD3D11 &>::Get";
      Lua_Error(
        a1,
        "Object obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
        *(const char **)(v2 + 24),
        unk_19437C8);
    }
  }
  return v4;
}


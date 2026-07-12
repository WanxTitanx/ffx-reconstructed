// Function: sub_A2CA30
// Address: 0xa2ca30
// Size: 0xc1
// Prototype: 

int __cdecl sub_A2CA30(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  _DWORD *v4; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  Lua_Pop(a1, -2);
  if ( !v1 )
  {
    Phyre_PObject_ComputeLayout(dword_1A84C88);
LABEL_8:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
    *(_DWORD *)&byte_C96298[2052] = 141;
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PText::PBitmapFont"
                                    "CharInfo &>::Get";
    Lua_Error(
      a1,
      "Object obtained from script was not a Phyre Object when an object of type \"%s\" was required.\n",
      unk_1A84CA0);
  }
  v2 = *v1;
  v3 = v1[1];
  if ( !v2 )
    goto LABEL_8;
  v4 = (_DWORD *)v2;
  while ( v4 != dword_1A84C88 )
  {
    v4 = (_DWORD *)v4[16];
    if ( !v4 )
    {
      *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
      *(_DWORD *)&byte_C96298[2052] = 143;
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PText::PBitmapFo"
                                      "ntCharInfo &>::Get";
      Lua_Error(
        a1,
        "Object obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
        *(const char **)(v2 + 24),
        unk_1A84CA0);
    }
  }
  return v3;
}


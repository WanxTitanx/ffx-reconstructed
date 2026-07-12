// Function: sub_A339E0
// Address: 0xa339e0
// Size: 0xc1
// Prototype: 

int __cdecl sub_A339E0(int a1)
{
  int *v1; // esi
  int Size_1; // ecx
  int v3; // esi
  _DWORD *Size; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  Lua_Pop(a1, -2);
  if ( !v1 )
  {
    Phyre_PObject_ComputeLayout(Size_6);
LABEL_8:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
    *(_DWORD *)&byte_C96298[2052] = 141;
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PGame::PGameSettings &>::Get";
    Lua_Error(
      a1,
      "Object obtained from script was not a Phyre Object when an object of type \"%s\" was required.\n",
      unk_1A855D0);
  }
  Size_1 = *v1;
  v3 = v1[1];
  if ( !Size_1 )
    goto LABEL_8;
  Size = (_DWORD *)Size_1;
  while ( Size != Size_6 )
  {
    Size = (_DWORD *)Size[16];
    if ( !Size )
    {
      *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
      *(_DWORD *)&byte_C96298[2052] = 143;
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PGame::PGameSettings &>::Get";
      Lua_Error(
        a1,
        "Object obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
        *(const char **)(Size_1 + 24),
        unk_1A855D0);
    }
  }
  return v3;
}


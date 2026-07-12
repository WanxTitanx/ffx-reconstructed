// Function: sub_A338A0
// Address: 0xa338a0
// Size: 0x137
// Prototype: 

int __cdecl sub_A338A0(int a1)
{
  int *v1; // esi
  int Size_1; // ebx
  int v3; // esi
  _DWORD *Size; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  Lua_Pop(a1, -2);
  if ( v1 )
  {
    Size_1 = *v1;
    v3 = v1[1];
  }
  else
  {
    Size_1 = 0;
    v3 = sub_A32910();
  }
  if ( (dword_1A85744 & 1) == 0 )
  {
    dword_1A85744 |= 1u;
    sub_A32EF0();
    unk_1A85740 &= ~2u;
    Size_7[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
    atexit(sub_B0B860);
  }
  if ( !Size_1 )
  {
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
    *(_DWORD *)&byte_C96298[2052] = 141;
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PArray<class Phyre"
                                    "::PInputs::PInputMap *,4> &>::Get";
    Lua_Error(
      a1,
      "Object obtained from script was not a Phyre Object when an object of type \"%s\" was required.\n",
      unk_1A856C8);
  }
  Size = (_DWORD *)Size_1;
  while ( Size != Size_7 )
  {
    Size = (_DWORD *)Size[16];
    if ( !Size )
    {
      *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
      *(_DWORD *)&byte_C96298[2052] = 143;
      *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PArray<class Phy"
                                      "re::PInputs::PInputMap *,4> &>::Get";
      Lua_Error(
        a1,
        "Object obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
        *(const char **)(Size_1 + 24),
        unk_1A856C8);
    }
  }
  return v3;
}


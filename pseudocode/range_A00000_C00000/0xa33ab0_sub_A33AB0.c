// Function: sub_A33AB0
// Address: 0xa33ab0
// Size: 0x16b
// Prototype: 

int __cdecl sub_A33AB0(int a1)
{
  int *v1; // edi
  int Size_1; // ebx
  int v3; // edi
  _DWORD *Size; // eax
  int v6; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  if ( v1 && (Lua_Pop(a1, -2), Size_1 = *v1, (v3 = v1[1]) != 0) )
  {
    if ( (dword_1A85744 & 1) == 0 )
    {
      dword_1A85744 |= 1u;
      sub_A32EF0();
      unk_1A85740 &= ~2u;
      Size_7[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PInputs::PInputMap *,4>>::`vftable';
      atexit(sub_B0B860);
    }
    if ( Size_1 )
    {
      Size = (_DWORD *)Size_1;
      while ( Size != Size_7 )
      {
        Size = (_DWORD *)Size[16];
        if ( !Size )
        {
          *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
          *(_DWORD *)&byte_C96298[2052] = 106;
          *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PArray<class"
                                          " Phyre::PInputs::PInputMap *,4> *>::Get";
          Lua_Error(
            a1,
            "Object pointer obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
            *(const char **)(Size_1 + 24),
            unk_1A856C8);
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
                                      "re::PInputs::PInputMap *,4> *>::Get";
      Lua_Error(
        a1,
        "Unable to obtain object pointer from script - found another type of data instead (Lua type %d)\n",
        v6);
    }
    Lua_Pop(a1, -2);
    return 0;
  }
}


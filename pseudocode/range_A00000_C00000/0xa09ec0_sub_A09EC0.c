// Function: sub_A09EC0
// Address: 0xa09ec0
// Size: 0x16b
// Prototype: 

int __cdecl sub_A09EC0(int a1)
{
  int *v1; // edi
  int Size_1; // ebx
  int v3; // edi
  _DWORD *Size; // eax
  int v6; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1);
  if ( v1 && (Lua_Pop(a1, -2), Size_1 = *v1, (v3 = v1[1]) != 0) )
  {
    if ( (dword_19450A4 & 1) == 0 )
    {
      dword_19450A4 |= 1u;
      sub_9F96D0();
      unk_19450A0 &= ~2u;
      Size_5[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PPostProcessing::PPostEffectBase *,4>>::`vftable';
      atexit(sub_B08DA0);
    }
    if ( Size_1 )
    {
      Size = (_DWORD *)Size_1;
      while ( Size != Size_5 )
      {
        Size = (_DWORD *)Size[16];
        if ( !Size )
        {
          *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl";
          *(_DWORD *)&byte_C96298[2052] = 106;
          *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PArray<class"
                                          " Phyre::PPostProcessing::PPostEffectBase *,4> *>::Get";
          Lua_Error(
            a1,
            "Object pointer obtained from script was of type \"%s\" when an object of type \"%s\" was required.\n",
            *(const char **)(Size_1 + 24),
            unk_1945028);
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
                                      "re::PPostProcessing::PPostEffectBase *,4> *>::Get";
      Lua_Error(
        a1,
        "Unable to obtain object pointer from script - found another type of data instead (Lua type %d)\n",
        v6);
    }
    Lua_Pop(a1, -2);
    return 0;
  }
}


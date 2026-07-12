// Function: sub_A09890
// Address: 0xa09890
// Size: 0xc1

int __cdecl sub_A09890(int a1)
{
  int *v1; // esi
  int Size_1; // ecx
  int v3; // esi
  _DWORD *Size; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa098a3*/
  Lua_Pop(a1, -2); /*0xa098a5*/
  if ( !v1 ) /*0xa098af*/
  {
    Phyre_PObject_ComputeLayout(Size_10); /*0xa09912*/
LABEL_8:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa09919*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa0992f*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P" /*0xa09939*/
                                    "PostEffectManager &>::Get";
    Lua_Error( /*0xa09943*/
      a1,
      "Object obtained from script was not a Phyre Object when an object of type \"%s\" was required.\n",
      unk_19448B8);
  }
  Size_1 = *v1; /*0xa098b1*/
  v3 = v1[1]; /*0xa098b3*/
  if ( !Size_1 ) /*0xa098b8*/
    goto LABEL_8; /*0xa098b8*/
  Size = (_DWORD *)Size_1; /*0xa098... [1769 chars total]
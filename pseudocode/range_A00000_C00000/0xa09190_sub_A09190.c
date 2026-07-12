// Function: sub_A09190
// Address: 0xa09190
// Size: 0xda

int __cdecl sub_A09190(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa091a3*/
  Lua_Pop(a1, -2); /*0xa091a5*/
  if ( !v1 ) /*0xa091af*/
  {
    Phyre_PObject_ComputeLayout(dword_1943E88); /*0xa09222*/
    goto LABEL_11; /*0xa09222*/
  }
  v2 = *v1; /*0xa091b1*/
  v3 = v1[1]; /*0xa091b3*/
  if ( v3 ) /*0xa091b8*/
    v4 = v3 - 4; /*0xa091ba*/
  else
    v4 = 0; /*0xa091bf*/
  if ( !v2 ) /*0xa091c3*/
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa09232*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa09248*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::PMLAA &>::Get"; /*0xa09252*/
    Lua_Error( /*0xa0925c*/
      a1,
      "Object obtained from script was not a Phyre Object when an object of type \"%s\" was required.\n",
     ... [1757 chars total]
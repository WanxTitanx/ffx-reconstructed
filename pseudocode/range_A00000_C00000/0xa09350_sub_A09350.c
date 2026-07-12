// Function: sub_A09350
// Address: 0xa09350
// Size: 0xda

int __cdecl sub_A09350(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa09363*/
  Lua_Pop(a1, -2); /*0xa09365*/
  if ( !v1 ) /*0xa0936f*/
  {
    Phyre_PObject_ComputeLayout(dword_1943F20); /*0xa093e2*/
    goto LABEL_11; /*0xa093e2*/
  }
  v2 = *v1; /*0xa09371*/
  v3 = v1[1]; /*0xa09373*/
  if ( v3 ) /*0xa09378*/
    v4 = v3 - 4; /*0xa0937a*/
  else
    v4 = 0; /*0xa0937f*/
  if ( !v2 ) /*0xa09383*/
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa093f2*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa09408*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P" /*0xa09412*/
                                    "MLAAD3D11 &>::Get";
    Lua_Error( /*0xa0941c*/
      a1,
      "Object obtained from script was not a Phyre Object when an o... [1847 chars total]
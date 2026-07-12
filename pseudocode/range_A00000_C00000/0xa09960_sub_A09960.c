// Function: sub_A09960
// Address: 0xa09960
// Size: 0xda

int __cdecl sub_A09960(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa09973*/
  Lua_Pop(a1, -2); /*0xa09975*/
  if ( !v1 ) /*0xa0997f*/
  {
    Phyre_PObject_ComputeLayout(dword_1943C70); /*0xa099f2*/
    goto LABEL_11; /*0xa099f2*/
  }
  v2 = *v1; /*0xa09981*/
  v3 = v1[1]; /*0xa09983*/
  if ( v3 ) /*0xa09988*/
    v4 = v3 - 4; /*0xa0998a*/
  else
    v4 = 0; /*0xa0998f*/
  if ( !v2 ) /*0xa09993*/
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa09a02*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa09a18*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P" /*0xa09a22*/
                                    "ScreenSpaceAmbientOcclusion &>::Get";
    Lua_Error( /*0xa09a2c*/
      a1,
      "Object obtained from script was not a Phyr... [1883 chars total]
// Function: sub_A09270
// Address: 0xa09270
// Size: 0xda

int __cdecl sub_A09270(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa09283*/
  Lua_Pop(a1, -2); /*0xa09285*/
  if ( !v1 ) /*0xa0928f*/
  {
    Phyre_PObject_ComputeLayout(dword_1943DF0); /*0xa09302*/
    goto LABEL_11; /*0xa09302*/
  }
  v2 = *v1; /*0xa09291*/
  v3 = v1[1]; /*0xa09293*/
  if ( v3 ) /*0xa09298*/
    v4 = v3 - 4; /*0xa0929a*/
  else
    v4 = 0; /*0xa0929f*/
  if ( !v2 ) /*0xa092a3*/
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa09312*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa09328*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P" /*0xa09332*/
                                    "MLAABase &>::Get";
    Lua_Error( /*0xa0933c*/
      a1,
      "Object obtained from script was not a Phyre Object when an ob... [1845 chars total]
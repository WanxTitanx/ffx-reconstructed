// Function: sub_A09430
// Address: 0xa09430
// Size: 0xda

int __cdecl sub_A09430(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa09443*/
  Lua_Pop(a1, -2); /*0xa09445*/
  if ( !v1 ) /*0xa0944f*/
  {
    Phyre_PObject_ComputeLayout(dword_1943FB8); /*0xa094c2*/
    goto LABEL_11; /*0xa094c2*/
  }
  v2 = *v1; /*0xa09451*/
  v3 = v1[1]; /*0xa09453*/
  if ( v3 ) /*0xa09458*/
    v4 = v3 - 4; /*0xa0945a*/
  else
    v4 = 0; /*0xa0945f*/
  if ( !v2 ) /*0xa09463*/
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa094d2*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa094e8*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P" /*0xa094f2*/
                                    "MeshParticleSystemBase &>::Get";
    Lua_Error( /*0xa094fc*/
      a1,
      "Object obtained from script was not a Phyre Obj... [1873 chars total]
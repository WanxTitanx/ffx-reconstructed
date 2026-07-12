// Function: sub_A09510
// Address: 0xa09510
// Size: 0xda

int __cdecl sub_A09510(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa09523*/
  Lua_Pop(a1, -2); /*0xa09525*/
  if ( !v1 ) /*0xa0952f*/
  {
    Phyre_PObject_ComputeLayout(dword_1943AA8); /*0xa095a2*/
    goto LABEL_11; /*0xa095a2*/
  }
  v2 = *v1; /*0xa09531*/
  v3 = v1[1]; /*0xa09533*/
  if ( v3 ) /*0xa09538*/
    v4 = v3 - 4; /*0xa0953a*/
  else
    v4 = 0; /*0xa0953f*/
  if ( !v2 ) /*0xa09543*/
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa095b2*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa095c8*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P" /*0xa095d2*/
                                    "MotionBlur &>::Get";
    Lua_Error( /*0xa095dc*/
      a1,
      "Object obtained from script was not a Phyre Object when an ... [1849 chars total]
// Function: sub_A097B0
// Address: 0xa097b0
// Size: 0xda

int __cdecl sub_A097B0(int a1)
{
  int *v1; // esi
  int Size_1; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *Size; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa097c3*/
  Lua_Pop(a1, -2); /*0xa097c5*/
  if ( !v1 ) /*0xa097cf*/
  {
    Phyre_PObject_ComputeLayout(Size_9); /*0xa09842*/
    goto LABEL_11; /*0xa09842*/
  }
  Size_1 = *v1; /*0xa097d1*/
  v3 = v1[1]; /*0xa097d3*/
  if ( v3 ) /*0xa097d8*/
    v4 = v3 - 4; /*0xa097da*/
  else
    v4 = 0; /*0xa097df*/
  if ( !Size_1 ) /*0xa097e3*/
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa09852*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa09868*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P" /*0xa09872*/
                                    "PostEffectBase &>::Get";
    Lua_Error( /*0xa0987c*/
      a1,
      "Object obtained from script was not a Phyre Obje... [1875 chars total]
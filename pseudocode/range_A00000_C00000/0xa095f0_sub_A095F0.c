// Function: sub_A095F0
// Address: 0xa095f0
// Size: 0xda

int __cdecl sub_A095F0(int a1)
{
  int *v1; // esi
  int Size_1; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *Size; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa09603*/
  Lua_Pop(a1, -2); /*0xa09605*/
  if ( !v1 ) /*0xa0960f*/
  {
    Phyre_PObject_ComputeLayout(Size_8); /*0xa09682*/
    goto LABEL_11; /*0xa09682*/
  }
  Size_1 = *v1; /*0xa09611*/
  v3 = v1[1]; /*0xa09613*/
  if ( v3 ) /*0xa09618*/
    v4 = v3 - 4; /*0xa0961a*/
  else
    v4 = 0; /*0xa0961f*/
  if ( !Size_1 ) /*0xa09623*/
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa09692*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa096a8*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P" /*0xa096b2*/
                                    "MotionBlurBase &>::Get";
    Lua_Error( /*0xa096bc*/
      a1,
      "Object obtained from script was not a Phyre Obje... [1875 chars total]
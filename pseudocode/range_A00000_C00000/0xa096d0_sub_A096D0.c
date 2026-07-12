// Function: sub_A096D0
// Address: 0xa096d0
// Size: 0xda

int __cdecl sub_A096D0(int a1)
{
  int *v1; // esi
  int v2; // ecx
  int v3; // esi
  int v4; // esi
  _DWORD *v5; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa096e3*/
  Lua_Pop(a1, -2); /*0xa096e5*/
  if ( !v1 ) /*0xa096ef*/
  {
    Phyre_PObject_ComputeLayout(dword_1943B40); /*0xa09762*/
    goto LABEL_11; /*0xa09762*/
  }
  v2 = *v1; /*0xa096f1*/
  v3 = v1[1]; /*0xa096f3*/
  if ( v3 ) /*0xa096f8*/
    v4 = v3 - 4; /*0xa096fa*/
  else
    v4 = 0; /*0xa096ff*/
  if ( !v2 ) /*0xa09703*/
  {
LABEL_11:
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa09772*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa09788*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PObjectAccessor<class Phyre::PPostProcessing::P" /*0xa09792*/
                                    "MotionBlurD3D11 &>::Get";
    Lua_Error( /*0xa0979c*/
      a1,
      "Object obtained from script was not a Phyre Object whe... [1859 chars total]
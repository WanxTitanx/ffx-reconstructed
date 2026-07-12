// Function: sub_A2C8F0
// Address: 0xa2c8f0
// Size: 0x137

int __cdecl sub_A2C8F0(int a1)
{
  int *v1; // esi
  int Size_1; // ebx
  int v3; // esi
  _DWORD *Size; // eax

  v1 = (int *)Lua_ToPhyreObject(a1, -1); /*0xa2c923*/
  Lua_Pop(a1, -2); /*0xa2c925*/
  if ( v1 ) /*0xa2c92f*/
  {
    Size_1 = *v1; /*0xa2c931*/
    v3 = v1[1]; /*0xa2c933*/
  }
  else
  {
    Size_1 = 0; /*0xa2c938*/
    v3 = sub_A2AEF0(); /*0xa2c93f*/
  }
  if ( (dword_1A85144 & 1) == 0 ) /*0xa2c94a*/
  {
    dword_1A85144 |= 1u; /*0xa2c94f*/
    sub_A2B780(Size_15); /*0xa2c961*/
    unk_1A85140 &= ~2u; /*0xa2c966*/
    Size_15[0] = &Phyre::PClassDescriptorConcrete<Phyre::PArray<Phyre::PText::PBitmapFontCharInfo,4>>::`vftable'; /*0xa2c972*/
    atexit(sub_B090E0); /*0xa2c97c*/
  }
  if ( !Size_1 ) /*0xa2c986*/
  {
    *(_DWORD *)&byte_C96298[2048] = "r:\\hg_code\\middleware_w32\\phyreengine\\include\\Scripting/PhyreScripting.inl"; /*0xa2c98e*/
    *(_DWORD *)&byte_C96298[2052] = 141; /*0xa2c99e*/
    *(_DWORD *)&byte_C96298[2056] = "Phyre::PScripting::PScriptAccessors::PO... [2125 chars total]
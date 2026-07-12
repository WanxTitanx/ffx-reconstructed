// Function: sub_AE5C10
// Address: 0xae5c10
// Size: 0x4b
// Prototype: 

int sub_AE5C10()
{
  if ( !sub_4D38C0("SHADER_LOD_LEVEL") )
  {
    ++unk_CA4E20;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B__3 = p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_ = &p____7PContextSwitchShaderLODLevel_PRendering_Phyre__6B_;
    dword_C16130 = 1;
  }
  p____7PContextSwitchShaderLODLevel_PRendering_Phyre__6B_ = &Phyre::PRendering::PContextSwitchShaderLODLevel::`vftable';
  return atexit(sub_AFE800);
}


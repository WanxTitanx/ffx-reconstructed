// Function: sub_AE5C60
// Address: 0xae5c60
// Size: 0x4b
// Prototype: 

int sub_AE5C60()
{
  if ( !sub_4D38C0("ORTHO_CAMERA") )
  {
    ++unk_CA4E20;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B__4 = p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_ = &p____7PContextSwitchShaderOrthoCamera_PRendering_Phyre__6B_;
    dword_C16148 = 1;
  }
  p____7PContextSwitchShaderOrthoCamera_PRendering_Phyre__6B_ = &Phyre::PRendering::PContextSwitchShaderOrthoCamera::`vftable';
  return atexit(sub_AFE830);
}


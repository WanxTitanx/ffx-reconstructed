// Function: sub_AE5B50
// Address: 0xae5b50
// Size: 0x4b
// Prototype: 

int sub_AE5B50()
{
  if ( !sub_4D38C0("LOD_BLEND") )
  {
    ++unk_CA4E20;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B__1 = p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_ = &p____7PContextSwitchLODBlend_PRendering_Phyre__6B_;
    dword_C16100 = 1;
  }
  p____7PContextSwitchLODBlend_PRendering_Phyre__6B_ = &Phyre::PRendering::PContextSwitchLODBlend::`vftable';
  return atexit(sub_AFE770);
}


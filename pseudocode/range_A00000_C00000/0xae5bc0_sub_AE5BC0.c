// Function: sub_AE5BC0
// Address: 0xae5bc0
// Size: 0x4b
// Prototype: 

int sub_AE5BC0()
{
  if ( !sub_4D38C0("INDICES_16BIT") )
  {
    ++unk_CA4E20;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B__2 = p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_ = &p____7PContextSwitchShader16BitIndices_PRendering_Phyre__6B_;
    dword_C16160 = 1;
  }
  p____7PContextSwitchShader16BitIndices_PRendering_Phyre__6B_ = &Phyre::PRendering::PContextSwitchShader16BitIndices::`vftable';
  return atexit(sub_AFE7D0);
}


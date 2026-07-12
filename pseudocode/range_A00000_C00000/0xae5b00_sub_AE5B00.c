// Function: sub_AE5B00
// Address: 0xae5b00
// Size: 0x4b
// Prototype: 

int sub_AE5B00()
{
  if ( !sub_4D38C0("INSTANCING_ENABLED") )
  {
    ++unk_CA4E20;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B__0 = p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_;
    p_p____7PContextSwitchInstancing_PRendering_Phyre__6B_ = &p____7PContextSwitchInstancing_PRendering_Phyre__6B_;
    dword_C16118 = 1;
  }
  p____7PContextSwitchInstancing_PRendering_Phyre__6B_ = &Phyre::PRendering::PContextSwitchInstancing::`vftable';
  return atexit(sub_AFE740);
}


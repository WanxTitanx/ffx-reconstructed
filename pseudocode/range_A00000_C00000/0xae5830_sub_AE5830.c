// Function: sub_AE5830
// Address: 0xae5830
// Size: 0x58
// Prototype: 

int sub_AE5830()
{
  if ( !unk_CA43BC && !sub_4CB1B0("CombinedCascadedShadowMap") )
  {
    dword_C158F4 = unk_CA43A8;
    unk_CA43A8 = &off_C158EC;
    n8_1 = 8;
    n3_11 = 3;
    unk_CA43BC = &off_C158EC;
  }
  return atexit(sub_AFE520);
}


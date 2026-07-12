// Function: sub_A15ED0
// Address: 0xa15ed0
// Size: 0x6f

_DWORD *sub_A15ED0()
{
  if ( (dword_1984C30[0] & 1) == 0 ) /*0xa15ef9*/
  {
    dword_1984C30[0] |= 1u; /*0xa15efe*/
    dword_1984C24 = (char *)Size_10 + 1; /*0xa15f12*/
    unk_1984C28 = Phyre_PTypeDefault_Uint32_GetSingleton(); /*0xa15f1c*/
    unk_1984C2C = 0; /*0xa15f21*/
  }
  return &dword_1984C24; /*0xa15f3b*/
}
// Function: sub_A15E60
// Address: 0xa15e60
// Size: 0x6f

_DWORD *sub_A15E60()
{
  if ( (dword_194513C & 1) == 0 ) /*0xa15e89*/
  {
    dword_194513C |= 1u; /*0xa15e8e*/
    dword_1945130 = (char *)Size_10 + 1; /*0xa15ea2*/
    unk_1945134 = Phyre_PTypeDefault_Uint32_GetSingleton(); /*0xa15eac*/
    unk_1945138 = 0; /*0xa15eb1*/
  }
  return &dword_1945130; /*0xa15ecb*/
}
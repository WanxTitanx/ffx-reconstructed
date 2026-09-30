// FFX Render: Bind data to gfx resource flag 8
int __cdecl FFX_Render_BindDataToGfxResource_Flag8(int a1, int a2)
{
  int v2; // esi
  _DWORD *v3; // ecx
  unsigned __int16 *i; // edx
  int result; // eax

  if ( MEMORY[0xD2C248] ) /*0x72a6db*/
  {
    v2 = *((unsigned __int16 *)MEMORY[0xD2C248] + 2); /*0x72a6de*/
    v3 = &unk_D30250; /*0x72a6e2*/
    if ( *((_WORD *)MEMORY[0xD2C248] + 2) ) /*0x72a6de*/
    {
      for ( i = (unsigned __int16 *)(MEMORY[0xD2C248] + 25); ; i += 40 ) /*0x72a6ef*/
      {
        result = *i; /*0x72a6f2*/
        --v2; /*0x72a6f5*/
        if ( result == a1 ) /*0x72a6f8*/
          break; /*0x72a6f8*/
        v3 += 19; /*0x72a6fd*/
        if ( !v2 ) /*0x72a702*/
          return result; /*0x72a702*/
      }
      if ( v3 ) /*0x72a70a*/
      {
        *v3 |= 8u; /*0x72a70f*/
        v3[1] = a2; /*0x72a712*/
        v3[2] = 0; /*0x72a715*/
        return a2; /*0x72a70c*/
      }
    }
  }
  return result; /*0x72a706*/
}
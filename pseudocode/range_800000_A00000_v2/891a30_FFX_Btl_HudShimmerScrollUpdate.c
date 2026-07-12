// Function: FFX_Btl_HudShimmerScrollUpdate
// Address: 0x891a30
void __thiscall FFX_Btl_HudShimmerScrollUpdate(void *this)
{
  int HasSubmenuActive; // eax
  double v2; // st6
  double v3; // st6
  float v4; // [esp+0h] [ebp-4h]

  if ( n2_4 == 2 )
  {
    unk_133F748 = unk_133F748 + 1.0;
    HasSubmenuActive = FFX_BtlHud_HasSubmenuActive();
    v2 = unk_133F748;
    if ( HasSubmenuActive )
      v3 = v2 / 25.0;
    else
      v3 = v2 / 30.0;
    MEMORY[0x133F750] = MEMORY[0x133F74C] - v3;
    if ( MEMORY[0x133F750] > 0.0 )
    {
      v4 = (float)(FFX_Rng_NextLcg31() % 10 - 10 * (int)(MEMORY[0x133F750] * -10.0));
      MEMORY[0x133F754] = v4 / 100.0;
    }
    else
    {
      MEMORY[0x133F750] = 0.0;
      MEMORY[0x133F754] = 0.0;
    }
  }
}

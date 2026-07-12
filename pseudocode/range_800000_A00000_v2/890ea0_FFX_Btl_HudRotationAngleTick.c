// Function: FFX_Btl_HudRotationAngleTick
// Address: 0x890ea0
void FFX_Btl_HudRotationAngleTick()
{
  unk_133FA3C = unk_133FA3C + 0.1047197543084621;
  if ( unk_133FA3C > 3.141592741012573 )
    unk_133FA3C = unk_133FA3C - 6.283185482025146;
}

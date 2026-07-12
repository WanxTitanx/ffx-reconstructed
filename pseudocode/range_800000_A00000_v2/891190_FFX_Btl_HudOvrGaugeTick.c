// Function: FFX_Btl_HudOvrGaugeTick
// Address: 0x891190
// [Jarvis naming goal 2026-06-17] HUD tick for Overdrive gauge fill animation; recomputes current/max ratio and eases displayed fill toward target. HUD-only, not a command availability gate.
void FFX_Btl_HudOvrGaugeTick()
{
  int v0; // ebx
  _DWORD *v1; // esi
  int v2; // edi
  int v3; // ecx

  v0 = 0;
  if ( MEMORY[0x133F0AC] > 0 )
  {
    v1 = &unk_133F94C;
    do
    {
      if ( unk_133F0B0[v0] != 255 && FFX_Btl_UI_UpdateAndStoreOverdriveGaugePos(unk_133F0B0[v0]) == 1 )
      {
        if ( FFX_Btl_GetOverdriveChargeMax(unk_133F0B0[v0]) <= 0 )
        {
          *(v1 - 1) = 0;
        }
        else
        {
          v2 = unk_25D0AA4 * FFX_Btl_GetOverdriveCharge(unk_133F0B0[v0]);
          *(v1 - 1) = v2 / FFX_Btl_GetOverdriveChargeMax(unk_133F0B0[v0]);
        }
        v3 = *(v1 - 1);
        if ( *v1 < v3 )
          *v1 += 6;
        if ( *v1 > v3 )
          *v1 = v3;
      }
      ++v0;
      v1 += 4;
    }
    while ( v0 < MEMORY[0x133F0AC] );
  }
}

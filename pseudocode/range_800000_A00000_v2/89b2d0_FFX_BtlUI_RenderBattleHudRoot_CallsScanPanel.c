// Function: FFX_BtlUI_RenderBattleHudRoot_CallsScanPanel
// Address: 0x89b2d0
void __usercall FFX_BtlUI_RenderBattleHudRoot_CallsScanPanel(double a1@<st0>)
{
  int i; // esi
  char *v2; // esi
  void *v3; // ecx

  if ( !unk_133C908 )
    return;
  sub_780D90();
  nullsub_158();
  FFX_Menu2D_SetViewport(0, 0, 512, 416);
  if ( *(_WORD *)&byte_133D6B2[2] || n7_5 || n9_0[0] )
  {
    sub_8A1C70();
    goto LABEL_8;
  }
  if ( unk_133C8FF )
  {
LABEL_8:
    sub_8AE2A0(2, 0, 1);
    goto LABEL_9;
  }
  sub_8AE2A0(2, 0, 0);
LABEL_9:
  sub_893200();
  sub_89D920(0);
  sub_89D920(1);
  if ( FFX_Battle_QueueGateCheck() == 2 || FFX_Battle_QueueGateCheck() == 1 )
  {
    if ( byte_C58EF4 == 1 )
      FFX_BtlUI_RenderPartyStatusDetail();
    sub_893330();
    sub_895300();
    sub_8926B0();
    sub_8971B0();
    sub_8955D0();
    sub_895550();
    if ( unk_23CC08C && dword_C58EF8 == 1 )
    {
      if ( !unk_133D6A0 )
        sub_892500(unk_23CC088[0]);
      sub_8A0520(unk_25D0A8A, unk_25D0A88);
      v2 = (char *)&unk_133C9A0;
      do
      {
        if ( *(v2 - 143) >= 3 && *(_DWORD *)v2 )
          (*(void (__cdecl **)(char *))v2)(v2 - 144);
        v2 += 240;
      }
      while ( (int)v2 < (int)byte_133D120 );
      sub_893640();
      FFX_BtlUI_DrawScanTargetInfoPanel(a1, (unsigned __int16)i_5, 179, 240);
      sub_8950B0(v3);
    }
    sub_8F9230(0, 0, 512, 416);
    if ( *(_WORD *)&byte_133D6B2[2] || n7_5 || n9_0[0] || unk_133C8FF )
      sub_8AE2A0(2, 1, 1);
    else
      sub_8AE2A0(2, 1, 0);
    if ( !unk_133D6A0 )
    {
      for ( i = 0; i < n4_5; ++i )
        sub_8FEB00(
          *((__int16 *)&unk_133F774 + 4 * i),
          *((__int16 *)&unk_133F778 + 4 * i),
          *((__int16 *)&unk_133F77A + 4 * i));
      n4_5 = 0;
    }
  }
}

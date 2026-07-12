// Function: FFX_BtlTick_UI_AllHudAndSubmenuTick
// Address: 0x89ad90
__int16 __usercall FFX_BtlTick_UI_AllHudAndSubmenuTick@<ax>(double a1@<st1>)
{
  void *v1; // ecx
  double v2; // st7
  int v3; // eax
  float *v4; // esi
  char v5; // cl
  void (__cdecl *v6)(float *); // ecx
  void (__cdecl *v7)(float *); // eax

  FFX_Btl_HudAnimationUpdate(2);
  FFX_Btl_HudRefreshPartyArrays();
  FFX_Btl_SubmenuRefresh();
  FFX_Btl_HudOvrGaugeTick();
  FFX_Btl_HudSubmenuTransitionTick();
  FFX_Btl_HudShimmerScrollUpdate(v1);
  FFX_Btl_SubmenuStateMachine();
  FFX_Btl_SubmenuShimmerNavTick();
  v2 = FFX_Btl_HudAnimationTickAll(a1);
  if ( unk_133C8F0 )
  {
    sub_630F90();
    FFX_Iop_TickDevicePoll();
    FFX_Iop_TickDeviceInit();
    v2 = FFX_Btl_HudAnimationTickAll(a1);
  }
  v3 = FFX_Battle_QueueGateCheck();
  if ( v3 == 1 && unk_23CC08C && dword_C58EF8 )
  {
    FFX_Btl_HudRotationAngleTick();
    n4_5 = 0;
    unk_133F774 = 0;
    unk_133F778 = 0;
    unk_133F77C = 0;
    unk_133F780 = 0;
    unk_133F784 = 0;
    unk_133F788 = 0;
    unk_133F78C = 0;
    unk_133F790 = 0;
    v4 = (float *)&unk_133C9A4;
    do
    {
      v5 = *((_BYTE *)v4 - 147);
      switch ( v5 )
      {
        case 1:
        case 5:
          *((_BYTE *)v4 - 147) = v5 + 1;
          break;
        case 2:
          FFX_Engine_GetTime();
          v4[18] = v2;
          v2 = 0.0;
          v6 = *(void (__cdecl **)(float *))v4;
          v4[19] = 0.0;
          if ( v6 )
            v6(v4 - 37);
          ++*((_BYTE *)v4 - 147);
          break;
        case 3:
          if ( (*((int (__cdecl **)(float *))v4 + 1))(v4 - 37) == 1 )
            ++*((_BYTE *)v4 - 147);
          break;
        case 4:
          FFX_Engine_GetTime();
          v2 = v2 - v4[18];
          v7 = (void (__cdecl *)(float *))*((_DWORD *)v4 + 2);
          v4[19] = v2;
          v7(v4 - 37);
          break;
        case 6:
          if ( (*((int (__cdecl **)(float *))v4 + 3))(v4 - 37) == 1 )
          {
            v2 = 0.0;
            v4[18] = 0.0;
          }
          *((_BYTE *)v4 - 147) = 0;
          break;
        default:
          break;
      }
      v4 += 60;
    }
    while ( (int)v4 < (int)&unk_133D124 );
    FFX_Btl_SubmenuContextCommandDisplay();
    FFX_Btl_UI_Overdrive_DetectReadyActor(v2);
    FFX_Btl_UI_Overdrive_AnimateGauge();
    LOWORD(v3) = FFX_Btl_SubmenuBuildCommandList();
  }
  return v3;
}

// Function: FFX_Btl_UI_Overdrive_AnimateGauge
// Address: 0x8914f0
void FFX_Btl_UI_Overdrive_AnimateGauge()
{
  int ActorWithReadyOverdrive; // eax
  unsigned __int8 v1; // cl
  __int16 v2; // dx
  __int16 v3; // dx
  int v4; // edx
  _DWORD *p_n3; // edi
  _DWORD *p_n3_1; // edi
  _DWORD *dst; // edi
  float v8; // [esp+8h] [ebp-78h]
  float v9; // [esp+8h] [ebp-78h]
  float v10; // [esp+8h] [ebp-78h]
  _DWORD p_n2[28]; // [esp+Ch] [ebp-74h] BYREF

  if ( unk_133C912[240 * unk_23CC092[0]] != 1 )
  {
    unk_133C8FD = 0;
    return;
  }
  ActorWithReadyOverdrive = FFX_Btl_FindActorWithReadyOverdrive();
  v1 = word_133D1B4;
  if ( ActorWithReadyOverdrive == -1 && (unsigned __int16)(word_133D1B4 - 20) <= 7u )
  {
    if ( unk_133F57C != word_133D1B4 )
    {
      FFX_Btl_UI_Overdrive_ResetGaugeToActor((unsigned __int16)word_133D1B4);
      v1 = word_133D1B4;
      unk_133F57C = word_133D1B4;
    }
    unk_133C8FD = 1;
  }
  else
  {
    unk_133C8FD = 0;
  }
  if ( FFX_Btl_IsOverdriveFull(v1) == 1 && (unsigned __int16)(word_133D1B4 - 20) <= 7u )
  {
    if ( unk_133F57C != word_133D1B4 )
    {
      FFX_Btl_UI_Overdrive_ResetGaugeToActor((unsigned __int16)word_133D1B4);
      unk_133F57C = word_133D1B4;
    }
    unk_133C8FD = 1;
  }
  if ( n2_15 != 8 )
  {
    memset(p_n2, 0, sizeof(p_n2));
    if ( n2_15 )
      unk_133F5E4 = unk_133F5E4 - 1.200000047683716;
    if ( n3_2 )
      unk_133F600 = unk_133F600 - 1.200000047683716;
    if ( n3_16 )
      unk_133F61C = unk_133F61C - 1.200000047683716;
    if ( src__5 )
      unk_133F638 = unk_133F638 - 1.200000047683716;
    if ( n2_15 == 2 && (v8 = (float)(unk_133F65C - 80), v8 > (double)unk_133F5EC[0] + unk_133F5E4) )
    {
      v2 = unk_133F5EC[0];
      n3_2 = 2;
      unk_133F600 = (float)unk_133F65C;
      unk_133F608[0] = unk_133F5EC[0];
      unk_133F60C = unk_133F5F0;
      unk_133F604 = unk_133F5E8;
      n2_15 = 3;
    }
    else
    {
      if ( n3_2 != 2 )
        goto LABEL_30;
      v2 = unk_133F608[0];
    }
    v9 = (float)(unk_133F65C - 80);
    if ( v9 > (double)v2 + unk_133F600 )
    {
      v3 = unk_133F608[0];
      n3_16 = 2;
      unk_133F61C = (float)unk_133F65C;
      unk_133F624[0] = unk_133F608[0];
      unk_133F628 = unk_133F60C;
      unk_133F620 = unk_133F604;
      n3_2 = 3;
      goto LABEL_32;
    }
LABEL_30:
    if ( n3_16 != 2 )
    {
LABEL_34:
      if ( n2_15 == 3 && (double)unk_133F5EC[0] + unk_133F5E4 < (double)unk_133F654 )
        n2_15 = 0;
      if ( n3_2 == 3 && (double)unk_133F608[0] + unk_133F600 < (double)unk_133F654 )
        n3_2 = 0;
      if ( n3_16 == 3 && (double)unk_133F624[0] + unk_133F61C < (double)unk_133F654 )
        n3_16 = 0;
      if ( src__5 == 3 && (double)unk_133F640[0] + unk_133F638 < (double)unk_133F654 )
        src__5 = 0;
      v4 = 0;
      if ( n2_15 )
      {
        v4 = 1;
        qmemcpy(p_n2, &n2_15, 0x1Cu);
      }
      if ( n3_2 )
      {
        p_n3 = &p_n2[7 * v4++];
        qmemcpy(p_n3, &n3_2, 0x1Cu);
      }
      if ( n3_16 )
      {
        p_n3_1 = &p_n2[7 * v4++];
        qmemcpy(p_n3_1, &n3_16, 0x1Cu);
      }
      if ( src__5 )
      {
        dst = &p_n2[7 * v4];
        LOWORD(v4) = v4 + 1;
        qmemcpy(dst, &src__5, 0x1Cu);
      }
      qmemcpy(&n2_15, p_n2, 0x70u);
      unk_133F648 = v4;
      return;
    }
    v3 = unk_133F624[0];
LABEL_32:
    v10 = (float)(unk_133F65C - 80);
    if ( v10 > (double)v3 + unk_133F61C )
    {
      unk_133F640[0] = unk_133F624[0];
      unk_133F638 = (float)unk_133F65C;
      src__5 = 2;
      unk_133F644 = unk_133F628;
      unk_133F63C = unk_133F620;
      n3_16 = 3;
    }
    goto LABEL_34;
  }
}

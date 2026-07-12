// Function: FFX_Btl_HudAnimationTickAll
// Address: 0x891af0
double __usercall FFX_Btl_HudAnimationTickAll@<st0>(double a1@<st1>)
{
  char n0x60; // bh
  unsigned __int8 n4; // bl
  double v4; // st6
  double v5; // st5
  double v6; // rt0
  double v7; // st5
  double v8; // st6
  int Tick; // eax
  int v10; // esi
  char Byte; // al
  unsigned __int8 n16; // bl
  __int16 IsPlaying; // si
  char *v14; // ecx
  int v15; // esi
  int v16; // eax
  int v17; // eax
  int v18; // edi
  double result; // st7
  int v20; // [esp-10h] [ebp-38h]
  float v21; // [esp+Ch] [ebp-1Ch]
  unsigned __int8 Byte_1; // [esp+13h] [ebp-15h]
  int n67438087; // [esp+18h] [ebp-10h] BYREF
  _DWORD v24[2]; // [esp+1Ch] [ebp-Ch]

  Byte_1 = 0x80;
  n0x60 = 0x80;
  n4 = -1;
  v24[0] = 117835012;
  v24[1] = 117835012;
  n67438087 = 67438087;
  FFX_Engine_GetTime();
  unk_133C8E0 = a1;
  v4 = unk_133C8E4;
  v5 = 0.0;
  if ( 0.0 == unk_133C8E4 )
  {
    FFX_Engine_GetTime();
    unk_133C8E4 = 0.0;
    v4 = (float)0.0;
    v5 = 0.0;
  }
  v6 = v5;
  v7 = unk_133C8E0 - v4;
  v8 = v6;
  switch ( n7_5 )
  {
    case 1:
      FFX_BtlHud_NamedAnimStartSimple(2, "blulu");
      ++n7_5;
      return result;
    case 2:
      if ( FFX_BtlHud_NamedAnimIsPlaying(2, "blulu") )
      {
        FFX_BtlHud_NamedAnimStart(2, "blulu2");
        ++n7_5;
      }
      return result;
    case 3:
      FFX_BtlHud_ShimmerStart();
      unk_133C8F0 = 1;
      Tick = FFX_Engine_TimerGetTick();
      ++n7_5;
      IsPlaying = Tick;
      return result;
    case 4:
      if ( v8 >= MEMORY[0x133F750] )
      {
        n7_5 = 6;
        return result;
      }
      v10 = 0;
      break;
    case 6:
      if ( unk_133C8F0 )
      {
        FFX_HUD_SubmenuThreadWait();
        unk_133C8E4 = 0.0;
        unk_133C8F0 = 0;
        unk_133C8E8 = 0;
        unk_133C8EC = 0;
      }
      FFX_BtlHud_ShimmerStopOnExit();
      FFX_BtlHud_ShimmerResetAll();
      result = MEMORY[0x133F750];
      FFX_BtlHud_SubmenuWriteFrameData(5u, n16, MEMORY[0x133F750], MEMORY[0x133F74C]);
      n7_5 = 7;
      return result;
    case 7:
      ++n7_5;
      return result;
    case 8:
      FFX_BtlHud_NamedAnimStop(2, "blulu");
      FFX_BtlHud_NamedAnimStop(2, "blulu2");
      ++n7_5;
      return result;
    case 9:
      n7_5 = 0;
      return result;
    default:
      return result;
  }
  while ( 1 )
  {
    if ( v10 )
    {
      if ( IsPlaying )
      {
        Byte = FFX_HUD_InputStateReadByte(0, 0, 0, 0);
        v20 = 0;
        goto LABEL_16;
      }
    }
    else if ( IsPlaying )
    {
      Byte = FFX_HUD_InputStateReadByte(0, 0, 0, -1);
      v20 = -1;
LABEL_16:
      Byte_1 = Byte;
      n0x60 = FFX_HUD_InputStateReadByte(0, 0, 1, v20);
      goto LABEL_18;
    }
    FFX_HUD_ReadDPadOrTriggers(&unk_133C8E8, &unk_133C8EC);
LABEL_18:
    if ( Byte_1 >= 0xA0u )
    {
      if ( (unsigned __int8)n0x60 < 0x60u )
      {
        n4 = 4;
        goto LABEL_21;
      }
      if ( Byte_1 >= 0xA0u && (unsigned __int8)n0x60 >= 0xA0u )
      {
        n4 = 5;
        goto LABEL_21;
      }
    }
    if ( Byte_1 < 0x60u )
    {
      if ( (unsigned __int8)n0x60 >= 0xA0u )
      {
        n4 = 6;
        goto LABEL_21;
      }
      if ( Byte_1 < 0x60u && (unsigned __int8)n0x60 < 0x60u )
        break;
    }
    v21 = v7;
    if ( v21 <= 0.50010002 )
      goto LABEL_21;
    unk_133C8E8 = 0;
    unk_133C8E4 = unk_133C8E0;
    unk_133C8EC = 0;
LABEL_23:
    if ( n4 != 0xFF )
    {
      if ( unk_133D6F1[0] )
      {
        if ( *((char *)&unk_133D6E0 + unk_133D6F1[0]) != n4 )
          unk_133D6E1[unk_133D6F1[0]++] = n4;
      }
      else
      {
        unk_133D6E1[0] = n4;
        unk_133D6F1[0] = 1;
      }
    }
    if ( ++v10 >= 2 )
    {
      n16 = n16;
      IsPlaying = IsPlaying_0;
      goto LABEL_41;
    }
  }
  n4 = 7;
LABEL_21:
  if ( !unk_133C8E8 || !unk_133C8EC )
    goto LABEL_23;
  n16 = n16;
  unk_133C8E8 = 0;
  unk_133C8EC = 0;
  if ( n16 >= 0x10u )
  {
    n16 = 16;
    goto LABEL_52;
  }
  v15 = unk_133F758[n16];
  v16 = ((unsigned __int8)++unk_133D6DE + 1) / 2;
  if ( v16 >= v15 )
  {
    n16 = n16 + 1;
LABEL_52:
    n16 = n16;
  }
  v17 = MEMORY[0x133D6CE] / 16;
  if ( IsPlaying_0 >= v17 * n16 )
  {
    IsPlaying = v17 * n16;
    IsPlaying_0 = IsPlaying;
  }
  else
  {
    IsPlaying = IsPlaying_0 + 3;
    IsPlaying_0 += 3;
  }
LABEL_41:
  if ( unk_133D6F1[0] >= 5 )
  {
    if ( *(_DWORD *)unk_133D6E1 == *(_DWORD *)((char *)&v24[-1] + unk_133D6E1[0])
      && unk_133D6E5[0] == *((_BYTE *)v24 + unk_133D6E1[0])
      || (v14 = (char *)&n67438087 - unk_133D6E1[0] + 3, *(_DWORD *)unk_133D6E1 == *(_DWORD *)v14)
      && unk_133D6E5[0] == v14[4] )
    {
      FFX_BtlHud_NamedAnimStart(2, "bgoodl");
      if ( n16 < 0x10u )
      {
        if ( ++unk_133D6DE >= unk_133F758[n16] )
          ++n16;
      }
      else
      {
        n16 = 16;
      }
    }
    memmove(unk_133D6E1, unk_133D6E5, 0xCu);
    n16 = n16;
    IsPlaying = IsPlaying_0;
    unk_133D6F1[0] = 0;
  }
  v18 = MEMORY[0x133D6CE] / 16;
  if ( IsPlaying >= v18 * n16 )
    IsPlaying_0 = v18 * n16;
  else
    IsPlaying_0 = IsPlaying + 3;
  return result;
}

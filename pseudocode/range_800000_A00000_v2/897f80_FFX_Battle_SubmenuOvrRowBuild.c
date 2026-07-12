// Function: FFX_Battle_SubmenuOvrRowBuild
// Address: 0x897f80
int FFX_Battle_SubmenuOvrRowBuild()
{
  float *PartyDataArray; // eax
  int i; // ecx
  __int16 *p_i; // esi
  int *v3; // ebx
  int i_2; // eax
  int ActorCtbGaugeCurrent; // eax
  int ActorCtbGaugeTarget; // eax
  int v7; // edi
  int v8; // eax
  __int16 i_4; // [esp-Ch] [ebp-1Ch]
  __int16 i_3; // [esp-8h] [ebp-18h]
  int i_1; // [esp+Ch] [ebp-4h] BYREF

  memset(&unk_133F798, 0, 0x1B0u);
  i_1 = 0;
  PartyDataArray = FFX_Btl_GetPartyDataArray(0, 18, &i_1);
  for ( i = i_1; i > 0; i_1 = --i )
  {
    if ( *((_WORD *)PartyDataArray + i - 1) != 255 )
      break;
  }
  p_i[0] = *(_WORD *)PartyDataArray;
  unk_133F76E = *((_WORD *)PartyDataArray + 1);
  unk_133F770 = *((_WORD *)PartyDataArray + 2);
  p_i = p_i;
  v3 = (int *)&unk_133F7A8;
  do
  {
    i_2 = (unsigned __int16)*p_i;
    if ( (_WORD)i_2 != 255 )
    {
      ActorCtbGaugeCurrent = FFX_Btl_GetActorCtbGaugeCurrent(*p_i);
      *(v3 - 1) = ActorCtbGaugeCurrent;
      *v3 = ActorCtbGaugeCurrent;
      i_3 = *p_i;
      v3[1] = 0;
      *((_BYTE *)v3 + 8) = 0;
      ActorCtbGaugeTarget = FFX_Btl_GetActorCtbGaugeTarget(i_3);
      v3[5] = ActorCtbGaugeTarget;
      v3[6] = ActorCtbGaugeTarget;
      i_4 = *p_i;
      v3[7] = 0;
      *((_BYTE *)v3 + 32) = 0;
      v7 = unk_25D0AA4 * FFX_Btl_GetOverdriveCharge(i_4);
      v8 = v7 / FFX_Btl_GetOverdriveChargeMax(*p_i);
      v3[9] = v8;
      v3[10] = v8;
      *((_WORD *)v3 + 24) = FFX_Btl_UI_BuildOverdriveSubcommandList((unsigned __int16)*p_i, (int)v3 + 50);
      i_2 = 20;
      *((_WORD *)v3 + 22) = 20;
    }
    ++p_i;
    v3 += 36;
  }
  while ( (int)p_i < (int)&unk_133F772 );
  return i_2;
}

// Function: sub_8958B0
// Address: 0x8958b0
void __cdecl sub_8958B0(unsigned __int8 a1, __int16 a2, __int16 a3)
{
  int ActorCtbTurns; // esi
  int ActorCtbGaugeCurrent; // eax
  int n2; // esi
  int ActorCtbGaugeTarget_1; // eax
  int ActorCtbGaugeTarget; // eax
  __int16 v8; // [esp+Eh] [ebp-12h]
  __int16 v9; // [esp+10h] [ebp-10h]
  __int16 v10; // [esp+12h] [ebp-Eh]
  __int16 v11; // [esp+14h] [ebp-Ch]
  __int16 v12; // [esp+16h] [ebp-Ah]
  __int16 v13; // [esp+18h] [ebp-8h]
  __int16 v14; // [esp+1Ah] [ebp-6h]
  __int16 v15; // [esp+1Ch] [ebp-4h]
  __int16 v16; // [esp+1Eh] [ebp-2h]
  __int16 v17; // [esp+32h] [ebp+12h]

  v14 = a2 + unk_25D0AC2;
  v15 = a2 + unk_25D0AC6;
  v17 = a3 + unk_25D0AC0;
  v12 = a2 + unk_25D0ABE;
  v16 = a3 + unk_25D0AC4;
  v13 = a3 + unk_25D0ABC;
  v10 = a2 + unk_25D0ABA;
  v11 = a3 + unk_25D0AB8;
  v8 = a2 + unk_25D0AB6;
  v9 = a3 + unk_25D0AB4;
  sub_8FB150(a2, a3, unk_25D0ACE, unk_25D0ACC, unk_25D0ACB, unk_25D0ACA, unk_25D0AC9, unk_25D0AC8);
  sub_903A10(233, v15, v16);
  ActorCtbTurns = FFX_Btl_GetActorCtbTurns(a1);
  ActorCtbGaugeCurrent = FFX_Btl_GetActorCtbGaugeCurrent(a1);
  switch ( FFX_Btl_ComputeCtbStateFromODRatio(ActorCtbGaugeCurrent, ActorCtbTurns) )
  {
    case 1:
    case 2:
      n2 = 2;
      break;
    case 3:
      n2 = 83;
      break;
    default:
      n2 = 0;
      break;
  }
  ActorCtbGaugeTarget_1 = FFX_Btl_GetActorCtbGaugeCurrent(a1);
  sub_9042E0(ActorCtbGaugeTarget_1, v14, v17, n2);
  sub_903A10(234, v12, v13);
  ActorCtbGaugeTarget = FFX_Btl_GetActorCtbGaugeTarget(a1);
  sub_9042E0(ActorCtbGaugeTarget, v10, v11, 0);
  FFX_Btl_DrawOverdriveGaugeFill(a1, v8, v9);
}

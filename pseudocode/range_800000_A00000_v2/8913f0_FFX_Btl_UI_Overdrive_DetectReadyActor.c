// Function: FFX_Btl_UI_Overdrive_DetectReadyActor
// Address: 0x8913f0
void __usercall FFX_Btl_UI_Overdrive_DetectReadyActor(double a1@<st0>)
{
  char v1; // bl
  unsigned __int8 v2; // cl
  char v3; // al

  v1 = unk_133C8FE;
  if ( unk_133C912[240 * unk_23CC092[0]] != 1 )
  {
    unk_133C8FE = 0;
    return;
  }
  if ( FFX_Btl_FindActorWithReadyOverdrive() != -1 )
  {
LABEL_9:
    v2 = word_133D1B4;
    goto LABEL_10;
  }
  v2 = word_133D1B4;
  if ( (unsigned __int16)(word_133D1B4 - 20) <= 7u )
  {
    if ( FFX_Btl_IsOverdriveUnlockedForAeon(word_133D1B4) )
    {
      v2 = word_133D1B4;
      if ( unk_133F578 != word_133D1B4 )
      {
        FFX_Btl_UI_Overdrive_InitGaugeForActor((unsigned __int16)word_133D1B4);
        v2 = word_133D1B4;
        unk_133F578 = word_133D1B4;
      }
      unk_133C8FE = 1;
      goto LABEL_11;
    }
    goto LABEL_9;
  }
LABEL_10:
  unk_133C8FE = 0;
LABEL_11:
  if ( FFX_Btl_IsOverdriveFull(v2) == 1 && (unsigned __int16)(word_133D1B4 - 20) <= 7u )
  {
    if ( unk_133F578 != word_133D1B4 )
    {
      FFX_Btl_UI_Overdrive_InitGaugeForActor((unsigned __int16)word_133D1B4);
      unk_133F578 = word_133D1B4;
    }
    v3 = 1;
    unk_133C8FE = 1;
  }
  else
  {
    v3 = unk_133C8FE;
  }
  if ( !v1 && v3 == 1 )
  {
    FFX_Engine_GetTime();
    unk_133C904 = a1;
  }
}

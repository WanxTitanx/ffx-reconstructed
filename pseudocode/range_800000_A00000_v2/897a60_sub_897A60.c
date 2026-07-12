// Function: sub_897A60
// Address: 0x897a60
void *sub_897A60()
{
  void *n255; // eax
  int v1; // esi
  _DWORD *v2; // ebx
  int v3; // edi

  n255 = memset(&unk_133F948, 0, 0x80u);
  v1 = 0;
  if ( MEMORY[0x133F0AC] > 0 )
  {
    v2 = &unk_133F94C;
    do
    {
      n255 = (void *)(unsigned __int16)unk_133F0B0[v1];
      if ( (_WORD)n255 != 255 )
      {
        n255 = (void *)FFX_Btl_UI_UpdateAndStoreOverdriveGaugePos(unk_133F0B0[v1]);
        if ( n255 == (void *)1 )
        {
          v3 = unk_25D0AA4 * FFX_Btl_GetOverdriveCharge(unk_133F0B0[v1]);
          n255 = (void *)(v3 / FFX_Btl_GetOverdriveChargeMax(unk_133F0B0[v1]));
          *(v2 - 1) = n255;
          *v2 = n255;
        }
      }
      ++v1;
      v2 += 4;
    }
    while ( v1 < MEMORY[0x133F0AC] );
  }
  return n255;
}

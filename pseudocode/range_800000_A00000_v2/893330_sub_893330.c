// Function: sub_893330
// Address: 0x893330
void sub_893330()
{
  int v0; // esi
  int *v1; // edi
  float v2; // [esp+4h] [ebp-2Ch]
  float v3; // [esp+8h] [ebp-28h]
  float v4; // [esp+Ch] [ebp-24h]
  double v5; // [esp+1Ch] [ebp-14h]
  int v6; // [esp+24h] [ebp-Ch] BYREF
  float v7; // [esp+28h] [ebp-8h]
  int v8; // [esp+2Ch] [ebp-4h] BYREF

  if ( FFX_Btl_Death_CheckPartyAliveStatus() != 1 )
  {
    FFX_Menu2D_SetViewport(0, 0, 512, 416);
    v0 = 0;
    if ( MEMORY[0x133F0AC] > 0 )
    {
      v1 = (int *)&unk_133F94C;
      do
      {
        if ( unk_133F0B0[v0] != 255 && FFX_Btl_UI_UpdateAndStoreOverdriveGaugePos(unk_133F0B0[v0]) == 1 )
        {
          sub_795000((unsigned __int16)unk_133F0B0[v0], &v8, &v6);
          v7 = (float)v8;
          v5 = v7;
          v4 = FFX_Menu2D_ScaleY_1080to416(8.0);
          v3 = FFX_Menu2D_ScaleX_1920to512(450.0);
          v7 = (float)v6;
          v2 = v7;
          v7 = v5 - FFX_Menu2D_ScaleX_1920to512(450.0) * 0.5;
          FFX_Menu2D_DrawProgressBar(*v1, v7, v2, v3, v4);
        }
        ++v0;
        v1 += 4;
      }
      while ( v0 < MEMORY[0x133F0AC] );
    }
  }
}

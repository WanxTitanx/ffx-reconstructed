// Function: FFX_Btl_DrawOverdriveGaugeFill
// Address: 0x8953f0
void __cdecl FFX_Btl_DrawOverdriveGaugeFill(unsigned __int8 a1, __int16 a2, __int16 a3)
{
  __int16 v3; // di
  __int16 v4; // bx
  double OverdriveCharge; // st7
  double OverdriveChargeMax; // [esp+Ch] [ebp-1Ch]
  __int16 v7; // [esp+1Eh] [ebp-Ah]
  __int16 v8; // [esp+36h] [ebp+Eh]
  __int16 v9; // [esp+3Ah] [ebp+12h]

  v3 = a2 + unk_25D0AA8 - 1;
  v9 = a3 + unk_25D0AA6;
  v7 = a3 + unk_25D0AA6;
  v4 = unk_25D0AA4;
  v8 = unk_25D0AA2;
  sub_8FB150(a2, a3, unk_25D0AB2, unk_25D0AB0, 0, 0, 0, 128);
  OverdriveChargeMax = (double)FFX_Btl_GetOverdriveChargeMax(a1);
  OverdriveCharge = (double)FFX_Btl_GetOverdriveCharge(a1);
  if ( OverdriveChargeMax != 0.0 && 0.0 != OverdriveCharge )
  {
    if ( OverdriveChargeMax > OverdriveCharge )
      sub_8F3EB0(v3, v7, (int)(OverdriveCharge * (double)v4 / OverdriveChargeMax), v8, -2138375937, -2145945629, v4);
    else
      sub_8FB150(v3, v9, v4, v8, 247, 121, 46, 128);
  }
}

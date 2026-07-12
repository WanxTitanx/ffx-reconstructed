// Function: FFX_BtlUI_DrawScanStatusRow
// Address: 0x8951b0
int __cdecl FFX_BtlUI_DrawScanStatusRow(int a1, int a2, int a3)
{
  int v3; // ecx
  __int16 v5; // ax
  int KernelString; // esi
  double v7; // st7
  float v9; // [esp+4h] [ebp-18h]
  int v10; // [esp+18h] [ebp-4h] BYREF
  float v11; // [esp+2Ch] [ebp+10h]
  float v12; // [esp+2Ch] [ebp+10h]
  float v13; // [esp+2Ch] [ebp+10h]

  v10 = v3;
  if ( MEMORY[0x133F582]-- )
  {
    v5 = unk_133F584;
  }
  else
  {
    MEMORY[0x133F582] = 20;
    v5 = unk_133F584 + 1;
    unk_133F584 = v5;
    if ( v5 == unk_133F586 )
    {
      v5 = 0;
      unk_133F584 = 0;
    }
  }
  KernelString = FFX_Table_GetKernelString(1, (unsigned __int16)unk_133F588[v5], 1);
  sub_905290(KernelString, (int)&v10, 0, 0.77999997);
  v11 = (float)a3;
  v9 = v11;
  v7 = FFX_Menu2D_ScaleX_1920to512(380.0);
  v12 = (float)a2;
  v13 = (v7 - *(float *)&v10) * 0.5 + v12;
  return FFX_Menu2D_DrawStatusEffectTimerBar(KernelString, v13, v9, 0, 0.77999997, COERCE_INT(1.0));
}

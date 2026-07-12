// Function: FFX_MagicCoreOp_6E_FloatRangeBranch
// Address: 0x818250
int __cdecl FFX_MagicCoreOp_6E_FloatRangeBranch(int a1, int a2)
{
  int v2; // ecx
  double v5; // st7
  float v6; // [esp+8h] [ebp-Ch]
  float v7; // [esp+10h] [ebp-4h]
  float v8; // [esp+1Ch] [ebp+8h]
  float v9; // [esp+20h] [ebp+Ch]
  float v10; // [esp+20h] [ebp+Ch]
  float v11; // [esp+20h] [ebp+Ch]

  v2 = *(_DWORD *)(a1 + 544);
  if ( (*(_WORD *)(a1 + 538) & 0xF000) != 0 && (*(_WORD *)(a1 + 538) & 0xF000) != 0x1000 )
    return a2;
  v7 = *(float *)(*(unsigned __int8 *)(a2 + 2) + v2);
  v8 = *(float *)(*(unsigned __int8 *)(a2 + 3) + v2);
  v9 = (float)*(__int16 *)(a2 + 4);
  v5 = v9;
  v10 = v9 + v8;
  v6 = v10;
  v11 = v8 - v5;
  if ( sub_7E7E70(v7, v11, v6) )
    return a2 + *(__int16 *)(a2 + 6);
  else
    return a2 + 8;
}

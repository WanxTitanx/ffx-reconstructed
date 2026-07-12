// Function: FFX_MagicCoreOp_C9_SphericalPlacement
// Address: 0x8160b0
int __cdecl FFX_MagicCoreOp_C9_SphericalPlacement(int a1, int a2)
{
  int v3; // edi
  int v4; // ebx
  float v6; // [esp+8h] [ebp-10h]
  float v7; // [esp+20h] [ebp+8h]
  float v8; // [esp+20h] [ebp+8h]
  float v9; // [esp+20h] [ebp+8h]
  float v10; // [esp+20h] [ebp+8h]
  float v11; // [esp+24h] [ebp+Ch]

  v3 = *(_DWORD *)(a1 + 544);
  v4 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v3 + 24)]);
  if ( *(_WORD *)(a2 + 2) )
  {
    if ( *(_WORD *)(a2 + 2) == 1 )
    {
      sub_824D50(v4, 0);
      return a2 + 4;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    v7 = (float)(((unsigned __int16)(int)*(float *)(v3 + 52) + 1024) & 0xFFF);
    v11 = v7 * 0.000244140625 * 360.0 - 90.0;
    v8 = *(float *)(v3 + 56);
    sub_7E6610(10.0);
    v9 = v8 + 10.0;
    v6 = v9;
    v10 = *(float *)(v3 + 48) * 0.00390625;
    sub_824D20(v4, v10, v11, v6);
    return a2 + 4;
  }
}

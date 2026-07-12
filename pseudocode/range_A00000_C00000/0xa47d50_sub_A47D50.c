// Function: sub_A47D50
// Address: 0xa47d50
// Size: 0x1ac
// Prototype: 

char sub_A47D50()
{
  int n8; // edi
  int v1; // edx
  int v2; // esi
  double v3; // st7
  double v4; // st6
  int n20; // eax
  int v6; // ecx
  double v7; // st7
  int n8_1; // edi
  int v9; // esi
  float v11; // [esp+Ch] [ebp-4h]
  float v12; // [esp+Ch] [ebp-4h]

  n8 = 0;
  v1 = dword_2305834[0];
  v2 = dword_2305834[0] + 69828;
  v11 = (double)*(unsigned __int8 *)(dword_2305834[0] + 71248) / 40.0;
  v12 = v11 * (*(float *)(dword_2305834[0] + 71212) - *(float *)(dword_2305834[0] + 71208))
      + *(float *)(dword_2305834[0] + 71208);
  v3 = v12;
  v4 = 0.0;
  do
  {
    if ( v4 < *(float *)v2 && *(_WORD *)(v2 + 8) == *(_WORD *)(v1 + 71246) )
    {
      *(float *)v2 = v3;
      sub_A58080(n8);
      v3 = v12;
      v1 = dword_2305834[0];
      v4 = 0.0;
    }
    ++n8;
    v2 += 80;
  }
  while ( n8 < 8 );
  LOBYTE(n20) = *(_BYTE *)(v1 + 71248);
  if ( (unsigned __int8)n20 < 0x14u )
  {
    n20 = (unsigned __int8)n20 + 1;
    if ( n20 >= 20 )
    {
      FFX_Abmap_SaveMenuRuntimeToSphereGridState();
      FFX_Abmap_RecomputePartyStatsAndLearnedMoves();
      *(_WORD *)(dword_2305834[0] + 40 * *(unsigned __int16 *)(dword_2305834[0] + 71246) + 2062) = *(_WORD *)(dword_2305834[0] + 71244);
      *(_DWORD *)(dword_2305834[0] + 71336) = *(unsigned __int16 *)(dword_2305834[0] + 71246);
      *(_DWORD *)(dword_2305834[0] + 71340) = 1;
      *(_DWORD *)(dword_2305834[0] + 71272) = &unk_1693160;
      LOBYTE(n20) = FFX_Abmap_UpdateRuntimeLinkGeometry();
      v1 = dword_2305834[0];
    }
  }
  ++*(_BYTE *)(v1 + 71248);
  if ( !unk_1A8607E )
  {
    v6 = dword_2305834[0];
    v7 = 0.0;
    n8_1 = 0;
    v9 = dword_2305834[0] + 69828;
    do
    {
      if ( v7 < *(float *)v9 && *(_WORD *)(v9 + 8) == *(_WORD *)(v6 + 71246) )
      {
        *(float *)v9 = *(float *)(v6 + 71212);
        sub_A58080(n8_1);
        v6 = dword_2305834[0];
        v7 = 0.0;
      }
      ++n8_1;
      v9 += 80;
    }
    while ( n8_1 < 8 );
    *(_DWORD *)(v6 + 71080) = *(_DWORD *)(v6 + 71088);
    *(_DWORD *)(dword_2305834[0] + 71088) = 0;
    *(_DWORD *)(dword_2305834[0] + 71084) = *(_DWORD *)(dword_2305834[0] + 71092);
    LOBYTE(n20) = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71092) = 0;
  }
  return n20;
}


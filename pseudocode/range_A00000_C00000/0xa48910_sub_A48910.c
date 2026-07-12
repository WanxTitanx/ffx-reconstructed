// Function: sub_A48910
// Address: 0xa48910
// Size: 0x166
// Prototype: 

int __cdecl sub_A48910(int a1, int a2)
{
  _DWORD *v3; // esi
  int result; // eax
  int v5; // ecx
  float v6; // [esp+4h] [ebp-30h]
  float v7; // [esp+8h] [ebp-2Ch]
  float v8; // [esp+Ch] [ebp-28h]
  float v9; // [esp+10h] [ebp-24h]
  float v10; // [esp+14h] [ebp-20h]
  float v11; // [esp+18h] [ebp-1Ch]
  float v12; // [esp+1Ch] [ebp-18h]
  float v13; // [esp+20h] [ebp-14h]
  float v14; // [esp+30h] [ebp-4h]
  float v15; // [esp+30h] [ebp-4h]
  int v16; // [esp+40h] [ebp+Ch]

  v16 = dword_2305834[0];
  v3 = (_DWORD *)sub_785350();
  FFX_MagicHost_LinkResourceBufferRange(dword_1A86034, dword_16C1830, 512000);
  v13 = 0.5;
  v12 = 0.5;
  v11 = 0.5;
  v10 = 0.0;
  v9 = 0.0;
  v8 = 0.0;
  v7 = 0.0;
  v14 = (float)*(__int16 *)(v16 + 40 * a2 + 2058);
  v6 = v14;
  v15 = (float)*(__int16 *)(v16 + 40 * a2 + 2056);
  if ( (*v3 & 0xC000) == 0x8000 )
    sub_A5BAD0((int)&unk_1A86060, 4, v15, v6, v7, v8, v9, v10, v11, v12, v13);
  else
    sub_A5BAD0((int)&unk_1A86060, 0, v15, v6, v7, v8, v9, v10, v11, v12, v13);
  *(_BYTE *)(v16 + 40 * a2 + 2089) |= 1 << a1;
  *(_DWORD *)(dword_2305834[0] + 71336) = a2;
  FFX_Abmap_SaveMenuRuntimeToSphereGridState();
  FFX_Abmap_RecomputePartyStatsAndLearnedMoves();
  FFX_SphereGrid_LoadDefaultStateResourceAndValidate();
  result = sub_A5AA30(a1, a2);
  v5 = dword_2305834[0];
  if ( !*(_DWORD *)(dword_2305834[0] + 71092) )
  {
    *(_DWORD *)(dword_2305834[0] + 71092) = *(_DWORD *)(dword_2305834[0] + 71084);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71084) = sub_A51700;
    v5 = dword_2305834[0];
  }
  if ( !*(_DWORD *)(v5 + 71088) )
  {
    *(_DWORD *)(v5 + 71088) = *(_DWORD *)(v5 + 71080);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71080) = sub_A48280;
  }
  return result;
}


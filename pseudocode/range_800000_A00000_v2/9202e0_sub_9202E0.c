// Function: sub_9202E0
// Address: 0x9202e0
double __cdecl sub_9202E0(float *a1, float a2, float a3, float a4, int a5, float *a6)
{
  int v6; // esi
  int v7; // eax
  float v9; // [esp+10h] [ebp-20h]
  float v10; // [esp+1Ch] [ebp-14h]
  float v11; // [esp+20h] [ebp-10h]
  float v12; // [esp+24h] [ebp-Ch]
  float v13; // [esp+24h] [ebp-Ch]
  float v14; // [esp+24h] [ebp-Ch]
  float v15; // [esp+24h] [ebp-Ch]
  float v16; // [esp+28h] [ebp-8h]
  float v17; // [esp+2Ch] [ebp-4h]
  float v18; // [esp+3Ch] [ebp+Ch]
  float v19; // [esp+3Ch] [ebp+Ch]
  float v20; // [esp+3Ch] [ebp+Ch]

  v6 = 0;
  if ( unk_193BF80 )
  {
    if ( *(_DWORD *)unk_193BF80 )
    {
      v7 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
      if ( v7 )
        v6 = *(_DWORD *)(v7 + 252);
    }
  }
  v18 = tan(a2 * 0.5 * 0.01745329238474369);
  v16 = v18;
  v19 = unk_1136FFC * 2.0 * v18;
  v20 = 512.0 / v19;
  if ( v6 )
  {
    v12 = 2.0 * (unk_1136FEC * 65536.0);
    v11 = v12;
    v13 = unk_1136FE8 * 10.0;
    v10 = v13;
  }
  else
  {
    v11 = unk_1136FEC;
    v10 = unk_1136FE8;
  }
  v14 = unk_1137004 + a4;
  v9 = v14;
  v15 = unk_1137000 + a3;
  v17 = 1.166666626930237 * v20;
  sub_93D960(a1, unk_1136FFC, v20, v17, v15, v9, unk_1136FE0, unk_1136FE4, v10, v11);
  if ( a6 )
    *a6 = 256.0 / v16;
  return v20;
}

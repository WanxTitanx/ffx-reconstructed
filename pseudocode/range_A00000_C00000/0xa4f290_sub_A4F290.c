// Function: sub_A4F290
// Address: 0xa4f290
// Size: 0x399
// Prototype: 

void __cdecl sub_A4F290(__int16 *a1, int a2, int a3)
{
  double v3; // st7
  int v4; // esi
  double v5; // st7
  double v6; // st6
  int v7; // eax
  int n11; // eax
  int v9; // eax
  double v10; // st7
  int n2; // eax
  double v12; // st6
  double v13; // st5
  double v14; // st6
  int v15; // [esp+14h] [ebp-1A4h]
  int v16; // [esp+14h] [ebp-1A4h]
  int v17; // [esp+14h] [ebp-1A4h]
  float v18; // [esp+18h] [ebp-1A0h]
  int v19; // [esp+18h] [ebp-1A0h]
  float v20; // [esp+18h] [ebp-1A0h]
  float v21; // [esp+18h] [ebp-1A0h]
  float v22; // [esp+18h] [ebp-1A0h]
  float v23; // [esp+18h] [ebp-1A0h]
  float v24; // [esp+18h] [ebp-1A0h]
  int v25[38]; // [esp+1Ch] [ebp-19Ch] BYREF
  char Buffer[256]; // [esp+B4h] [ebp-104h] BYREF

  v18 = (float)(a1[4] + a3 + 2);
  v3 = v18;
  v4 = dword_2305834[0];
  v19 = *(_DWORD *)(dword_2305834[0] + 71352);
  *(float *)&v15 = v3 - *(float *)(dword_2305834[0] + 71348) / 3.0;
  v5 = 12.0;
  v6 = 3.141592502593994;
  if ( v19 > 0 )
  {
    v20 = (float)v19;
    v21 = sin(v20 / 12.0 * 3.141592502593994);
    *(float *)(dword_2305834[0] + 71348) = v21 * 2.0 + *(float *)(dword_2305834[0] + 71348);
    ++*(_DWORD *)(v4 + 71352);
    v5 = 12.0;
    v4 = dword_2305834[0];
    v6 = 3.141592502593994;
  }
  v7 = *(_DWORD *)(v4 + 71352);
  if ( v7 < 0 )
  {
    v22 = (float)-v7;
    v23 = sin(v22 / v5 * v6);
    *(float *)(v4 + 71348) = *(float *)(v4 + 71348) - v23 * 2.0;
    ++*(_DWORD *)(v4 + 71352);
    v4 = dword_2305834[0];
  }
  n11 = *(_DWORD *)(v4 + 71352);
  if ( n11 == 11 || n11 == -1 )
  {
    *(_DWORD *)(v4 + 71352) = -n11;
    v4 = dword_2305834[0];
  }
  v9 = a1[12] - a2;
  v25[36] = 0;
  v25[37] = 0;
  v10 = (double)(a1[5] + 20 * v9 - 2);
  n2 = *(_DWORD *)(v4 + 71332);
  if ( n2 )
  {
    if ( n2 == 2 )
    {
      sprintf(Buffer, "%s/dat12/%s/12288_19.dds.phyre", "/FFX_Data/GameData/PS3Data/menu/abmap", "tex/D3D11");
      if ( FFX_Game_GetRegion() == 11 )
        sprintf(Buffer, "%s/dat12/%s/12288_19.dds.phyre", "/FFX_Data/GameData/PS3Data/menu_cn/abmap", "tex/D3D11");
    }
  }
  else
  {
    sprintf(Buffer, "%s/dat00/%s/12288_19.dds.phyre", "/FFX_Data/GameData/PS3Data/menu/abmap", "tex/D3D11");
    if ( FFX_Game_GetRegion() == 11 )
      sprintf(Buffer, "%s/dat00/%s/12288_19.dds.phyre", "/FFX_Data/GameData/PS3Data/menu_cn/abmap", "tex/D3D11");
  }
  v25[0] = v15;
  *(float *)&v25[1] = v10;
  v12 = *(float *)&v15;
  v25[8] = v15;
  v25[4] = 128;
  v25[5] = 128;
  v25[6] = 128;
  v25[7] = 128;
  v25[12] = 128;
  v24 = v10;
  *(float *)&v16 = v24 + 20.0;
  v25[13] = 128;
  v25[14] = 128;
  v25[9] = v16;
  v25[15] = 128;
  v13 = v12;
  v14 = *(float *)&v16;
  v25[20] = 128;
  v25[21] = 128;
  v25[22] = 128;
  v25[23] = 128;
  *(float *)&v17 = v13 + 18.0;
  v25[28] = 128;
  v25[29] = 128;
  v25[16] = v17;
  v25[30] = 128;
  v25[24] = v17;
  v25[31] = 128;
  *(float *)&v25[17] = v10;
  *(float *)&v25[25] = v14;
  *(float *)&v25[2] = 0.75195312;
  *(float *)&v25[3] = 0.041015625;
  *(float *)&v25[10] = 0.75195312;
  *(float *)&v25[11] = 0.084960938;
  *(float *)&v25[18] = 0.81835938;
  *(float *)&v25[26] = 0.81835938;
  *(float *)&v25[19] = 0.041015625;
  *(float *)&v25[27] = 0.084960938;
  sub_63EAE0((int)v25, Buffer, 6);
}


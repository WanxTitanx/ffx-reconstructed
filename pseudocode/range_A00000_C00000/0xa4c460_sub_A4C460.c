// Function: sub_A4C460
// Address: 0xa4c460
// Size: 0x258
// Prototype: 

void __cdecl sub_A4C460(int a1, int a2)
{
  _DWORD *v2; // esi
  _DWORD *v3; // eax
  int n2; // eax
  int v5[38]; // [esp+4h] [ebp-19Ch] BYREF
  char Buffer[256]; // [esp+9Ch] [ebp-104h] BYREF

  v5[36] = 0;
  v5[37] = 0;
  v2 = dword_1A860EC;
  *dword_1A860EC = 32769;
  v3 = dword_1A860EC;
  v2[2] = 5631726;
  v3[1] = 1612922880;
  v2[3] = 0;
  v2[4] = 822083848;
  v2[5] = 0;
  v2[6] = 78;
  v2[7] = 0;
  v2[8] = 196608;
  v2[9] = 0;
  v2[10] = 71;
  v2[11] = 0;
  v2[12] = 68;
  v2[13] = 0;
  v2[14] = 66;
  v2[15] = 0;
  v2[18] = 1;
  v2[19] = 0;
  v2[20] = 28672;
  v2[21] = 29440;
  v2[23] = 0;
  v2[24] = 36864;
  v2[25] = 36096;
  v2[27] = 0;
  *((_QWORD *)v2 + 8) = (__int64)a1 << 24;
  v2[22] = a2;
  v2[26] = a2;
  *(float *)v5 = 0.0;
  v5[7] = 2 * a1;
  *(float *)&v5[1] = 0.0;
  v5[15] = 2 * a1;
  *(float *)&v5[8] = 512.0;
  memset(&v5[4], 0, 12);
  *(float *)&v5[9] = 416.0;
  memset(&v5[12], 0, 12);
  *(float *)&v5[2] = 0.76171875;
  *(float *)&v5[3] = 0.51757812;
  *(float *)&v5[10] = 0.83007812;
  *(float *)&v5[11] = 0.5859375;
  n2 = *(_DWORD *)(dword_2305834[0] + 71332);
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
  sub_63F090((int)v5, Buffer, 1, 0, 0.0);
}


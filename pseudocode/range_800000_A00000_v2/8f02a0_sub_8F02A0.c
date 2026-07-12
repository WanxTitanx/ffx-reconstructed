// Function: sub_8F02A0
// Address: 0x8f02a0
int __cdecl sub_8F02A0(int a1, int a2, int a3, int a4)
{
  int n9; // eax
  unsigned int *v5; // ebx
  unsigned __int8 *v6; // edi
  unsigned int i; // esi
  float v9; // [esp+0h] [ebp-B0h] BYREF
  float v10; // [esp+4h] [ebp-ACh] BYREF
  char *Str; // [esp+8h] [ebp-A8h]
  int v12; // [esp+Ch] [ebp-A4h]
  int v13; // [esp+10h] [ebp-A0h]
  int v14[38]; // [esp+14h] [ebp-9Ch] BYREF

  v12 = 1;
  v14[36] = 0;
  v14[37] = 0;
  if ( a2 )
  {
    if ( a2 == 1 )
    {
      v12 = 0;
      n9 = 9;
    }
    else
    {
      n9 = (int)Str;
    }
  }
  else
  {
    n9 = 45;
  }
  v5 = (unsigned int *)sub_8FA7D0(n9);
  v6 = (unsigned __int8 *)(v5 + 1);
  v14[32] = 0;
  Str = FFX_Menu2D_TexHandleByAtlasId(15872);
  FFX_Menu2D_GetAtlasDimensions_structural(15872, &v9, &v10);
  for ( i = 0; i < *v5; v6 += 12 )
  {
    if ( i )
    {
      v14[4] = 128;
      v14[5] = 128;
      v14[6] = 128;
      v14[7] = 128;
      v14[12] = 128;
      v14[13] = 128;
      v14[14] = 128;
      v14[15] = 128;
      v13 = a3 + 3 * *((unsigned __int16 *)v6 + 2) / 20 + (char)v6[2];
      *(float *)v14 = (float)v13;
      v13 = a4 + 3 * *((unsigned __int16 *)v6 + 3) / 20 + (char)v6[3];
      *(float *)&v14[1] = (float)v13;
      v13 = a3 + 51 * *((unsigned __int16 *)v6 + 2) / 80 + (char)v6[2];
      *(float *)&v14[8] = (float)v13;
      v13 = a4 + 17 * *((unsigned __int16 *)v6 + 3) / 20 + (char)v6[3];
      *(float *)&v14[9] = (float)v13;
      v13 = *v6 + 1;
      *(float *)&v13 = (float)v13;
      *(float *)&v14[2] = *(float *)&v13 / v9;
      v13 = v6[1] + 1;
      *(float *)&v13 = (float)v13;
      *(float *)&v14[3] = *(float *)&v13 / v10;
      v13 = *v6 - 1 + *((unsigned __int16 *)v6 + 2);
      *(float *)&v13 = (float)v13;
      *(float *)&v14[10] = *(float *)&v13 / v9;
      *(float *)&v13 = (float)(*((unsigned __int16 *)v6 + 3) + v6[1] - 1);
      *(float *)&v14[11] = *(float *)&v13 / v10;
    }
    ++i;
  }
  sub_63F090((int)v14, Str, v12, 0, 0.0);
  return a1;
}

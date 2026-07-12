// Function: sub_8FEB00
// Address: 0x8feb00
void __usercall sub_8FEB00(double a1@<st0>, int n5, int a3, int a4)
{
  int v4; // ebx
  char *v5; // edi
  int n8; // eax
  unsigned __int8 *v7; // esi
  float v8; // eax
  unsigned int i; // edi
  int v10; // [esp+4h] [ebp-D4h]
  float v11; // [esp+8h] [ebp-D0h]
  float v12; // [esp+Ch] [ebp-CCh]
  float v13; // [esp+20h] [ebp-B8h] BYREF
  float v14; // [esp+24h] [ebp-B4h] BYREF
  char *Str[2]; // [esp+28h] [ebp-B0h]
  int v16; // [esp+30h] [ebp-A8h]
  float v17; // [esp+34h] [ebp-A4h]
  int v18; // [esp+38h] [ebp-A0h]
  int v19[38]; // [esp+3Ch] [ebp-9Ch] BYREF

  v16 = 1;
  v19[36] = 0;
  v19[37] = 0;
  if ( n5 )
  {
    v4 = a3;
    if ( n5 == 4 )
    {
      v5 = 0;
      *(float *)&v16 = 0.0;
      n8 = 8;
      v4 = a3 - 30;
    }
    else if ( n5 == 5 )
    {
      v5 = 0;
      *(float *)&v16 = 0.0;
      n8 = 9;
      v4 = a3 + 30;
    }
    else
    {
      v5 = Str[1];
      n8 = (int)Str[1];
    }
    v17 = COERCE_FLOAT(sub_8FA7D0(n8));
    v7 = (unsigned __int8 *)(LODWORD(v17) + 4);
    v19[32] = 0;
    v19[34] = (int)v5;
    Str[1] = FFX_Menu2D_TexHandleByAtlasId(15872);
    FFX_Menu2D_GetAtlasDimensions_structural(15872, &v14, &v13);
    v8 = v17;
    for ( i = 0; i < *(_DWORD *)LODWORD(v8); v7 += 12 )
    {
      if ( i )
      {
        v19[4] = 128;
        v19[5] = 128;
        v19[6] = 128;
        v19[7] = 128;
        v19[12] = 128;
        v19[13] = 128;
        v19[14] = 128;
        v19[15] = 128;
        if ( unk_18716B0 )
        {
          v18 = v4 + 8 * *((unsigned __int16 *)v7 + 2) / 20 + (char)v7[2];
          *(float *)v19 = (float)v18;
          v18 = v4 + 18 * *((unsigned __int16 *)v7 + 2) / 20 + (char)v7[2];
        }
        else
        {
          v18 = v4 + 3 * *((unsigned __int16 *)v7 + 2) / 20 + (char)v7[2];
          *(float *)v19 = (float)v18;
          v18 = v4 + 51 * *((unsigned __int16 *)v7 + 2) / 80 + (char)v7[2];
        }
        *(float *)&v19[8] = (float)v18;
        v18 = a4 + 3 * *((unsigned __int16 *)v7 + 3) / 20 + (char)v7[3];
        *(float *)&v19[1] = (float)v18;
        v18 = a4 + 17 * *((unsigned __int16 *)v7 + 3) / 20 + (char)v7[3];
        *(float *)&v19[9] = (float)v18;
        v18 = *v7 + 1;
        *(float *)&v18 = (float)v18;
        *(float *)&v19[2] = *(float *)&v18 / v14;
        v18 = v7[1] + 1;
        *(float *)&v18 = (float)v18;
        *(float *)&v19[3] = *(float *)&v18 / v13;
        v18 = *v7 - 1 + *((unsigned __int16 *)v7 + 2);
        *(float *)&v18 = (float)v18;
        *(float *)&v19[10] = *(float *)&v18 / v14;
        v18 = *((unsigned __int16 *)v7 + 3) + v7[1] - 1;
        v8 = v17;
        *(float *)&v18 = (float)v18;
        *(float *)&v19[11] = *(float *)&v18 / v13;
      }
      ++i;
    }
    sub_63F090((int)v19, Str[1], v16, 0, 0.0);
  }
  else
  {
    FFX_Engine_GetTime();
    v17 = cos(a1 * 8.0);
    *(float *)&v16 = v17 * 3.0;
    v12 = FFX_Menu2D_ScaleY_1080to416(45.0);
    v11 = FFX_Menu2D_ScaleX_1920to512(68.0);
    v17 = (float)a4;
    v17 = v17 - FFX_Menu2D_ScaleY_1080to416(5.0);
    *(float *)&v10 = v17;
    v17 = (float)a3;
    v17 = v17 + *(float *)&v16 - FFX_Menu2D_ScaleX_1920to512(68.0);
    FFX_Menu2D_DrawTexQuadSolid(
      0x190u,
      v17,
      v10,
      v11,
      v12,
      COERCE_INT(0.0009765625),
      COERCE_INT(0.63476562),
      COERCE_INT(0.06640625),
      COERCE_INT(0.67871094));
  }
}

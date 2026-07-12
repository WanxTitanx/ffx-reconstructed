// Function: sub_893640
// Address: 0x893640
void sub_893640()
{
  double v0; // st7
  double v1; // st7
  double v2; // st7
  float v3; // [esp+0h] [ebp-34h]
  int v4; // [esp+4h] [ebp-30h]
  float v5; // [esp+8h] [ebp-2Ch]
  float v6; // [esp+8h] [ebp-2Ch]
  float v7; // [esp+Ch] [ebp-28h]
  int v8; // [esp+Ch] [ebp-28h]
  float v9; // [esp+10h] [ebp-24h]
  float v10; // [esp+14h] [ebp-20h]
  float v11; // [esp+14h] [ebp-20h]
  float v12; // [esp+18h] [ebp-1Ch]
  float v13; // [esp+18h] [ebp-1Ch]
  float v14; // [esp+18h] [ebp-1Ch]
  double v15; // [esp+28h] [ebp-Ch]
  float v16; // [esp+2Ch] [ebp-8h]
  float v17; // [esp+2Ch] [ebp-8h]
  int v18; // [esp+30h] [ebp-4h] BYREF

  if ( unk_133D6A0 != 1 && (*(_DWORD *)sub_785350() & 0x400) != 0 )
  {
    if ( unk_133C8FC == 1 )
    {
      sub_8F9230(0, 0, 512, 416);
      v7 = FFX_Menu2D_ScaleY_1080to416(55.0);
      v5 = FFX_Menu2D_ScaleX_1920to512(1600.0);
      *(float *)&v4 = FFX_Menu2D_ScaleY_1080to416(96.0);
      v3 = FFX_Menu2D_ScaleX_1920to512(145.0);
      FFX_Menu2D_DrawTexQuadTinted(
        0xFFFFFFFF,
        v3,
        v4,
        v5,
        v7,
        COERCE_INT(0.0),
        COERCE_INT(544.0),
        COERCE_INT(1600.0),
        COERCE_INT(599.0),
        0x80808080,
        0x808080u);
      v10 = FFX_Menu2D_ScaleY_1080to416(22.0);
      v9 = FFX_Menu2D_ScaleX_1920to512(95.0);
      *(float *)&v8 = FFX_Menu2D_ScaleY_1080to416(78.0);
      v6 = FFX_Menu2D_ScaleX_1920to512(145.0);
      FFX_Menu2D_DrawTexQuadSolid(
        0x3Eu,
        v6,
        v8,
        v9,
        v10,
        COERCE_INT(0.65332031),
        COERCE_INT(0.94140625),
        COERCE_INT(0.75488281),
        COERCE_INT(0.96484375));
      sub_905320(0, (int)&unk_133F4F8, (int)&v18, 0.77999997, 1.0);
      if ( (unk_133C8FD == 1 || unk_133D6A0) && (v15 = *(float *)&v18, FFX_Menu2D_ScaleX_1920to512(435.0) < v15) )
      {
        sub_8E8940(40.0, 40.0, 178.0, 62.0);
        unk_133C900 = unk_133C900 - 0.800000011920929;
        v12 = FFX_Menu2D_ScaleY_1080to416(101.0);
        v16 = FFX_Menu2D_ScaleX_1920to512(235.0) + unk_133C900;
        sub_9016B0(0, (int)&unk_133F4F8, v16, v12, 0, 0.77999997, 1.0);
        v0 = FFX_Menu2D_ScaleX_1920to512(235.0);
        if ( v0 + unk_133C900 + *(float *)&v18 < 158.0 )
        {
          v13 = FFX_Menu2D_ScaleY_1080to416(101.0);
          v1 = FFX_Menu2D_ScaleX_1920to512(235.0);
          v17 = v1 + unk_133C900 + *(float *)&v18 + 20.0;
          sub_9016B0(0, (int)&unk_133F4F8, v17, v13, 0, 0.77999997, 1.0);
        }
        v2 = FFX_Menu2D_ScaleX_1920to512(235.0);
        if ( v2 + unk_133C900 + *(float *)&v18 < 40.0 )
          unk_133C900 = *(float *)&v18 + 20.0 + unk_133C900;
        sub_8E5CD0();
      }
      else
      {
        v14 = FFX_Menu2D_ScaleY_1080to416(101.0);
        v11 = FFX_Menu2D_ScaleX_1920to512(235.0);
        sub_9016B0(0, (int)&unk_133F4F8, v11, v14, 0, 0.77999997, 1.0);
      }
    }
    else
    {
      unk_133C900 = 0.0;
    }
  }
}

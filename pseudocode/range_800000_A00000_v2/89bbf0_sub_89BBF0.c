// Function: sub_89BBF0
// Address: 0x89bbf0
int __usercall sub_89BBF0@<eax>(double a1@<st0>)
{
  int n454; // esi
  int v2; // esi
  float v4; // [esp+4h] [ebp-34h]
  float v5; // [esp+4h] [ebp-34h]
  int v6; // [esp+8h] [ebp-30h]
  int v7; // [esp+8h] [ebp-30h]
  float v8; // [esp+Ch] [ebp-2Ch]
  float v9; // [esp+Ch] [ebp-2Ch]
  float v10; // [esp+10h] [ebp-28h]
  float v11; // [esp+10h] [ebp-28h]
  float v12; // [esp+18h] [ebp-20h]
  int v13; // [esp+1Ch] [ebp-1Ch]
  float v14; // [esp+20h] [ebp-18h]
  float v15; // [esp+24h] [ebp-14h]
  float v16; // [esp+24h] [ebp-14h]
  float v17; // [esp+28h] [ebp-10h]
  float v18; // [esp+28h] [ebp-10h]
  float v19; // [esp+30h] [ebp-8h]
  float v20; // [esp+30h] [ebp-8h]
  float v21; // [esp+30h] [ebp-8h]
  float v22; // [esp+30h] [ebp-8h]
  float v23; // [esp+30h] [ebp-8h]

  n454 = 454;
  if ( FFX_Game_GetRegion() )
    n454 = 394;
  v2 = n454 - 80 * MEMORY[0x133F6C2];
  FFX_Engine_GetTime();
  v17 = a1;
  v19 = (float)(v2 + 40);
  sub_902EF0(-1, v19, 488.0, 68.0, 68.0, 1.0, 53.0, 101.0, 153.0, -2139062144, -2139062144, v17);
  FFX_Engine_GetTime();
  v18 = -v19;
  v20 = (float)(v2 + 47);
  sub_902EF0(-1, v20, 495.0, 54.0, 54.0, 1759.0, 1.0, 1835.0, 77.0, -2139062144, -2139062144, v18);
  v10 = FFX_Menu2D_ScaleY_1080to416(149.0);
  v8 = FFX_Menu2D_ScaleX_1920to512(477.0);
  *(float *)&v6 = FFX_Menu2D_ScaleY_1080to416(448.0);
  v21 = (float)v2;
  v4 = FFX_Menu2D_ScaleX_1920to512(v21);
  FFX_Menu2D_DrawTexQuadTinted(
    0x190u,
    v4,
    v6,
    v8,
    v10,
    COERCE_INT(0.0),
    COERCE_INT(0.69628906),
    COERCE_INT(0.46484375),
    COERCE_INT(0.84179688),
    0x80808080,
    0x80808080);
  v11 = FFX_Menu2D_ScaleY_1080to416(24.0);
  v9 = FFX_Menu2D_ScaleX_1920to512(166.0);
  *(float *)&v7 = FFX_Menu2D_ScaleY_1080to416(511.0);
  v22 = (float)(v2 + 65);
  v5 = FFX_Menu2D_ScaleX_1920to512(v22);
  FFX_Menu2D_DrawTexQuadTinted(
    0x190u,
    v5,
    v7,
    v9,
    v11,
    COERCE_INT(0.091796875),
    COERCE_INT(0.65332031),
    COERCE_INT(0.29296875),
    COERCE_INT(0.68261719),
    0x80808080,
    0x80808080);
  v15 = 430.0;
  if ( FFX_Game_GetRegion() )
  {
    v16 = FFX_Menu2D_ScaleY_1080to416(v15);
    v14 = FFX_Menu2D_ScaleX_1920to512(1000.0);
  }
  else
  {
    v16 = FFX_Menu2D_ScaleY_1080to416(v15);
    v14 = FFX_Menu2D_ScaleX_1920to512(880.0);
  }
  *(float *)&v13 = FFX_Menu2D_ScaleY_1080to416(535.0);
  v23 = (float)(v2 + 71);
  v12 = FFX_Menu2D_ScaleX_1920to512(v23);
  FFX_Menu2D_DrawRoundedPanel9Slice(v12, v13, v14, v16, 0);
  if ( !MEMORY[0x133F6C2] )
    return 1;
  --MEMORY[0x133F6C2];
  return 0;
}

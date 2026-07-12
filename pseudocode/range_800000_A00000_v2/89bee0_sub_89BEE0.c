// Function: sub_89BEE0
// Address: 0x89bee0
int __cdecl sub_89BEE0(int a1)
{
  float *DurationFloatPtr; // eax
  double v2; // st7
  float *v3; // eax
  int ActorCtbGaugeCurrent; // eax
  double v5; // st7
  int ActorCtbTurns; // eax
  int v7; // eax
  int v8; // eax
  int v9; // ebx
  int v10; // edi
  int i; // esi
  int result; // eax
  __int16 v14; // ax
  int KernelString; // esi
  double v16; // st7
  int v17; // [esp+4h] [ebp-40h]
  float v18; // [esp+8h] [ebp-3Ch]
  float v19; // [esp+8h] [ebp-3Ch]
  float v20; // [esp+Ch] [ebp-38h]
  float v21; // [esp+Ch] [ebp-38h]
  int v22; // [esp+10h] [ebp-34h]
  float v23; // [esp+10h] [ebp-34h]
  int v24; // [esp+10h] [ebp-34h]
  int v25; // [esp+10h] [ebp-34h]
  float v26; // [esp+10h] [ebp-34h]
  float v27; // [esp+10h] [ebp-34h]
  float v28; // [esp+10h] [ebp-34h]
  float v29; // [esp+14h] [ebp-30h]
  float v30; // [esp+14h] [ebp-30h]
  float v31; // [esp+14h] [ebp-30h]
  float v32; // [esp+14h] [ebp-30h]
  float v33; // [esp+18h] [ebp-2Ch]
  float v34; // [esp+18h] [ebp-2Ch]
  float v35; // [esp+18h] [ebp-2Ch]
  float v36; // [esp+18h] [ebp-2Ch]
  float v37; // [esp+18h] [ebp-2Ch]
  float v38; // [esp+18h] [ebp-2Ch]
  float v39; // [esp+1Ch] [ebp-28h]
  int v40; // [esp+1Ch] [ebp-28h]
  float v41; // [esp+1Ch] [ebp-28h]
  float v42; // [esp+1Ch] [ebp-28h]
  int v43; // [esp+20h] [ebp-24h]
  int v44; // [esp+24h] [ebp-20h]
  int v45; // [esp+28h] [ebp-1Ch]
  int v46; // [esp+28h] [ebp-1Ch]
  double v47; // [esp+2Ch] [ebp-18h]
  float v48; // [esp+30h] [ebp-14h]
  float v49; // [esp+34h] [ebp-10h]
  float v50; // [esp+34h] [ebp-10h]
  float v51; // [esp+38h] [ebp-Ch]
  float v52; // [esp+38h] [ebp-Ch]
  float v53; // [esp+38h] [ebp-Ch]
  float v54; // [esp+38h] [ebp-Ch]
  float v55; // [esp+38h] [ebp-Ch]
  float v56; // [esp+38h] [ebp-Ch]
  float v57; // [esp+38h] [ebp-Ch]
  float v58; // [esp+38h] [ebp-Ch]
  float v59; // [esp+38h] [ebp-Ch]
  float v60; // [esp+38h] [ebp-Ch]
  int v61; // [esp+38h] [ebp-Ch]
  float v62; // [esp+38h] [ebp-Ch]
  int v63; // [esp+3Ch] [ebp-8h] BYREF
  _BYTE v64[4]; // [esp+40h] [ebp-4h] BYREF
  float v65; // [esp+4Ch] [ebp+8h]
  float v66; // [esp+4Ch] [ebp+8h]

  DurationFloatPtr = FFX_StatusEffect_GetDurationFloatPtr(word_133F66A);
  sub_8B9600(0, DurationFloatPtr, &v63, v64, 0, 0);
  v2 = FFX_Menu2D_ScaleX_1920to512(410.0);
  v47 = (v2 - *(float *)&v63 * 0.8999999761581421) * 0.5;
  v65 = (float)a1;
  v39 = FFX_Menu2D_ScaleY_1080to416(547.0);
  v51 = FFX_Menu2D_ScaleX_1920to512(486.0) + v65 + v47;
  v3 = FFX_StatusEffect_GetDurationFloatPtr(word_133F66A);
  sub_9016B0(-1, (int)v3, v51, v39, 0, 0.63999999, 0.5);
  v33 = FFX_Menu2D_ScaleY_1080to416(42.0);
  v29 = FFX_Menu2D_ScaleX_1920to512(410.0);
  *(float *)&v22 = FFX_Menu2D_ScaleY_1080to416(586.0);
  v52 = FFX_Menu2D_ScaleX_1920to512(486.0) + v65;
  FFX_Menu2D_DrawTexQuadSolid(
    0xFFFFFFFF,
    v52,
    v22,
    v29,
    v33,
    COERCE_INT(1330.0),
    COERCE_INT(0.0),
    COERCE_INT(1680.0),
    COERCE_INT(50.0));
  if ( FFX_Game_GetRegion() == 11 )
  {
    *(float *)&v45 = 0.041015625;
    *(float *)&v44 = 0.44433594;
    *(float *)&v43 = 0.01171875;
    *(float *)&v40 = 0.36132812;
    v34 = FFX_Menu2D_ScaleY_1080to416(30.0);
    v30 = FFX_Menu2D_ScaleX_1920to512(85.0);
    v53 = FFX_Menu2D_ScaleY_1080to416(582.0) + 2.0;
    v23 = v53;
    v54 = FFX_Menu2D_ScaleX_1920to512(520.0) + v65 - 7.0;
  }
  else
  {
    *(float *)&v45 = 0.0625;
    *(float *)&v44 = 0.44335938;
    *(float *)&v43 = 0.001953125;
    *(float *)&v40 = 0.36132812;
    v34 = FFX_Menu2D_ScaleY_1080to416(58.0);
    v30 = FFX_Menu2D_ScaleX_1920to512(60.0);
    v23 = FFX_Menu2D_ScaleY_1080to416(582.0);
    v54 = FFX_Menu2D_ScaleX_1920to512(520.0) + v65;
  }
  FFX_Menu2D_DrawTexQuadSolid(0xE9u, v54, SLODWORD(v23), v30, v34, v40, v43, v44, v45);
  v41 = FFX_Menu2D_ScaleY_1080to416(589.0);
  v55 = FFX_Menu2D_ScaleX_1920to512(700.0) + v65;
  ActorCtbGaugeCurrent = FFX_Btl_GetActorCtbGaugeCurrent(word_133F66A);
  sub_9055C0(ActorCtbGaugeCurrent, v55, v41, 0, 0.63999999, 0.5);
  v46 = (int)FFX_Menu2D_ScaleY_1080to416(594.0);
  v5 = FFX_Menu2D_ScaleX_1920to512(705.0) + v65;
  sub_902040(word_B8F87C, (int)v5, v46);
  v42 = FFX_Menu2D_ScaleY_1080to416(589.0);
  v56 = FFX_Menu2D_ScaleX_1920to512(740.0) + v65;
  ActorCtbTurns = FFX_Btl_GetActorCtbTurns(word_133F66A);
  sub_905550(ActorCtbTurns, v56, v42, 0, 0.63999999, 0.5);
  v35 = 30.0;
  if ( FFX_Game_GetRegion() == 11 )
  {
    v36 = FFX_Menu2D_ScaleY_1080to416(v35);
    v31 = FFX_Menu2D_ScaleX_1920to512(170.0);
    *(float *)&v24 = FFX_Menu2D_ScaleY_1080to416(635.0);
    v57 = FFX_Menu2D_ScaleX_1920to512(518.0) + v65 - 5.0;
  }
  else
  {
    v36 = FFX_Menu2D_ScaleY_1080to416(v35);
    v31 = FFX_Menu2D_ScaleX_1920to512(170.0);
    *(float *)&v24 = FFX_Menu2D_ScaleY_1080to416(635.0);
    v57 = FFX_Menu2D_ScaleX_1920to512(518.0) + v65;
  }
  FFX_Menu2D_DrawTexQuadSolid(
    0x1F8u,
    v57,
    v24,
    v31,
    v36,
    COERCE_INT(0.0),
    COERCE_INT(0.31542969),
    COERCE_INT(0.3125),
    COERCE_INT(0.375));
  v37 = 30.0;
  if ( FFX_Game_GetRegion() == 11 )
  {
    v38 = FFX_Menu2D_ScaleY_1080to416(v37);
    v32 = FFX_Menu2D_ScaleX_1920to512(202.0);
    *(float *)&v25 = FFX_Menu2D_ScaleY_1080to416(670.0);
    v58 = FFX_Menu2D_ScaleX_1920to512(518.0) + v65 - 5.0;
  }
  else
  {
    v38 = FFX_Menu2D_ScaleY_1080to416(v37);
    v32 = FFX_Menu2D_ScaleX_1920to512(202.0);
    *(float *)&v25 = FFX_Menu2D_ScaleY_1080to416(670.0);
    v58 = FFX_Menu2D_ScaleX_1920to512(518.0) + v65;
  }
  FFX_Menu2D_DrawTexQuadSolid(
    0x1F9u,
    v58,
    v25,
    v32,
    v38,
    COERCE_INT(0.0),
    COERCE_INT(0.25195312),
    COERCE_INT(0.37109375),
    COERCE_INT(0.3125));
  v26 = FFX_Menu2D_ScaleY_1080to416(630.0);
  v59 = FFX_Menu2D_ScaleX_1920to512(800.0) + v65;
  v7 = sub_79AF50(word_133F66A);
  sub_9055C0(v7, v59, v26, 0, 0.63999999, 0.5);
  v27 = FFX_Menu2D_ScaleY_1080to416(665.0);
  v60 = FFX_Menu2D_ScaleX_1920to512(800.0) + v65;
  v8 = sub_79AEA0(word_133F66A);
  sub_9055C0(v8, v60, v27, 0, 0.63999999, 0.5);
  v9 = (int)(FFX_Menu2D_ScaleX_1920to512(495.0) + v65);
  v10 = (int)FFX_Menu2D_ScaleY_1080to416(706.0);
  v61 = v10;
  for ( i = 0; i <= 3; ++i )
  {
    v62 = (float)v61;
    v20 = FFX_Menu2D_ScaleY_1080to416(42.0);
    v18 = FFX_Menu2D_ScaleX_1920to512(410.0);
    v49 = FFX_Menu2D_ScaleX_1920to512(486.0) + v65;
    FFX_Menu2D_DrawTexQuadSolid(
      0xFFFFFFFF,
      v49,
      SLODWORD(v62),
      v18,
      v20,
      COERCE_INT(1330.0),
      COERCE_INT(0.0),
      COERCE_INT(1680.0),
      COERCE_INT(50.0));
    if ( FFX_Game_GetRegion() == 11 )
    {
      v50 = (float)v9;
      sub_895A50(word_133F66A, i, (int)(v50 - 5.0), v10);
    }
    else
    {
      sub_895A50(word_133F66A, i, v9, v10);
    }
    v10 = (int)(FFX_Menu2D_ScaleY_1080to416(45.0) + v62);
    v61 = v10;
  }
  v21 = FFX_Menu2D_ScaleY_1080to416(28.0);
  v19 = FFX_Menu2D_ScaleX_1920to512(229.0);
  *(float *)&v17 = FFX_Menu2D_ScaleY_1080to416(887.0);
  v48 = FFX_Menu2D_ScaleX_1920to512(570.0) + v65;
  result = FFX_Menu2D_DrawTexQuadSolid(
             0x1FAu,
             v48,
             v17,
             v19,
             v21,
             COERCE_INT(0.0),
             COERCE_INT(0.19628906),
             COERCE_INT(0.39746094),
             COERCE_INT(0.24902344));
  if ( word_133F670 > 0 )
  {
    if ( n20_2-- )
    {
      v14 = unk_133F66E;
    }
    else
    {
      n20_2 = 20;
      v14 = unk_133F66E + 1;
      unk_133F66E = v14;
      if ( v14 == word_133F670 )
      {
        v14 = 0;
        unk_133F66E = 0;
      }
    }
    KernelString = FFX_Table_GetKernelString(1, (unsigned __int16)word_133F672[v14], 1);
    sub_905290(KernelString, (int)&v63, 0, 0.63999999);
    v28 = FFX_Menu2D_ScaleY_1080to416(915.0);
    v16 = FFX_Menu2D_ScaleX_1920to512(684.5);
    v66 = v16 + v65 - *(float *)&v63 * 0.5;
    return sub_9016B0(-1, KernelString, v66, v28, 0, 0.63999999, 0.5);
  }
  return result;
}

// Function: sub_8A0520
// Address: 0x8a0520
void __cdecl sub_8A0520(int a1, int a2)
{
  char n10; // al
  double v3; // st7
  double v4; // st6
  double v5; // st7
  int v6; // edi
  int v7; // esi
  double v8; // st6
  double v9; // st7
  double v10; // st6
  int v11; // edi
  _DWORD *v12; // esi
  int v13; // [esp+4h] [ebp-54h]
  float v14; // [esp+8h] [ebp-50h]
  float v15; // [esp+Ch] [ebp-4Ch]
  int v16; // [esp+10h] [ebp-48h]
  float v17; // [esp+14h] [ebp-44h]
  int v18; // [esp+14h] [ebp-44h]
  float v19; // [esp+18h] [ebp-40h]
  float v20; // [esp+18h] [ebp-40h]
  int v21; // [esp+18h] [ebp-40h]
  int v22; // [esp+1Ch] [ebp-3Ch]
  int n10_1; // [esp+20h] [ebp-38h]
  int v24; // [esp+24h] [ebp-34h]
  float v25; // [esp+28h] [ebp-30h]
  int v26; // [esp+28h] [ebp-30h]
  float v27; // [esp+28h] [ebp-30h]
  int v28; // [esp+28h] [ebp-30h]
  float v29; // [esp+28h] [ebp-30h]
  float v30; // [esp+2Ch] [ebp-2Ch]
  float v31; // [esp+30h] [ebp-28h]
  float v32; // [esp+38h] [ebp-20h]
  float v33; // [esp+38h] [ebp-20h]
  float v34; // [esp+38h] [ebp-20h]
  float v35; // [esp+38h] [ebp-20h]
  int v36; // [esp+38h] [ebp-20h]
  float v37; // [esp+38h] [ebp-20h]
  float v38; // [esp+40h] [ebp-18h]
  float v39; // [esp+40h] [ebp-18h]
  float v40; // [esp+40h] [ebp-18h]
  int v41; // [esp+40h] [ebp-18h]
  float v42; // [esp+40h] [ebp-18h]
  int v43; // [esp+40h] [ebp-18h]
  float v44; // [esp+40h] [ebp-18h]
  int v45; // [esp+40h] [ebp-18h]
  float v46; // [esp+40h] [ebp-18h]
  float v47; // [esp+40h] [ebp-18h]
  int v48; // [esp+40h] [ebp-18h]
  float v49; // [esp+40h] [ebp-18h]
  float v50; // [esp+44h] [ebp-14h]
  float v51; // [esp+44h] [ebp-14h]
  int v52; // [esp+44h] [ebp-14h]
  float v53; // [esp+44h] [ebp-14h]
  float v54; // [esp+48h] [ebp-10h]
  float v55; // [esp+4Ch] [ebp-Ch]
  float v56; // [esp+50h] [ebp-8h]
  float v57; // [esp+54h] [ebp-4h]

  if ( unk_133D6A0 != 1 )
  {
    v57 = FFX_Menu2D_ScaleX_1920to512(1637.0);
    v56 = FFX_Menu2D_ScaleY_1080to416(194.0);
    v54 = FFX_Menu2D_ScaleX_1920to512(1765.0);
    v55 = FFX_Menu2D_ScaleY_1080to416(482.0);
    v50 = v55 - v56;
    sub_8F9230(0, 0, 512, 416);
    v38 = FFX_Menu2D_ScaleY_1080to416(16.0) + v50;
    v30 = v38;
    v39 = v54 - v57;
    v40 = FFX_Menu2D_ScaleX_1920to512(16.0) + v39;
    v25 = v40;
    *(float *)&v41 = v56 - FFX_Menu2D_ScaleY_1080to416(8.0);
    v24 = v41;
    v42 = v57 - FFX_Menu2D_ScaleX_1920to512(8.0);
    FFX_Menu2D_DrawRoundedPanel9Slice(v42, v24, v25, v30, 0);
    n10 = unk_1340406[0];
    v3 = 0.0;
    v4 = 10.0;
    if ( unk_1340406[0] > 0 )
    {
      *(float *)&v43 = v56 - FFX_Menu2D_ScaleY_1080to416(10.0);
      v26 = v43;
      v44 = FFX_Menu2D_ScaleX_1920to512(44.0) + v57;
      sub_89E5D0(438, v44, v26, 0.0, 0.0);
      v3 = 0.0;
      n10 = unk_1340406[0];
      v4 = 10.0;
    }
    if ( n10 < 10 )
    {
      v31 = v3;
      v27 = v4;
      *(float *)&v45 = FFX_Menu2D_ScaleY_1080to416(v27) + v55;
      v28 = v45;
      v46 = FFX_Menu2D_ScaleX_1920to512(44.0) + v57;
      sub_89E5D0(439, v46, v28, v31, v31);
      n10 = unk_1340406[0];
    }
    n10_1 = n10;
    v19 = FFX_Menu2D_ScaleX_1920to512(8.0);
    sub_8E6CC0(v57, v56, v19, v50, n10_1, 6, 16);
    sub_8E8980(v57, v56, v54, v55);
    v5 = 15.0;
    v6 = 0;
    while ( 1 )
    {
      if ( dword_1340434[v6 + 1] )
      {
        v7 = dword_1340434[v6 + 1];
        v29 = v5;
        v32 = FFX_Menu2D_ScaleX_1920to512(v29) + (double)*(__int16 *)(v7 + 16) + v57;
        v47 = (double)*(__int16 *)(v7 + 18) / 22.0 * 48.0 + 48.0 * (double)word_1340408[0] / 22.0;
        v8 = FFX_Menu2D_ScaleY_1080to416(v47) + v56;
        v9 = v56;
        if ( *(int (__cdecl **)(int))(dword_1340434[v6 + 1] + 20) != sub_8A2AB0 )
        {
          if ( !v6 && !word_1340408[0] )
          {
            v20 = FFX_Menu2D_ScaleY_1080to416(33.0);
            v17 = FFX_Menu2D_ScaleX_1920to512(23.0);
            *(float *)&v48 = FFX_Menu2D_ScaleY_1080to416(7.0) + v56;
            v16 = v48;
            v49 = v54 - FFX_Menu2D_ScaleX_1920to512(23.0);
            FFX_Menu2D_DrawTexQuadSolid(
              0x1D8u,
              v49,
              v16,
              v17,
              v20,
              COERCE_INT(0.70703125),
              COERCE_INT(0.2890625),
              COERCE_INT(0.73925781),
              COERCE_INT(0.33496094));
          }
          v51 = v8;
          sub_8A1660(*(char *)(dword_1340434[v6 + 1] + 1), *(_DWORD *)(dword_1340434[v6 + 1] + 4), v32, v51);
          v9 = v56;
        }
        v10 = 15.0;
      }
      else
      {
        v10 = v5;
        v9 = v56;
      }
      if ( ++v6 >= 32 )
        break;
      v5 = v10;
    }
    if ( unk_133C912[240 * unk_23CC092[0]] == 1 )
    {
      FFX_Menu2D_SetViewport((int)(v57 - 30.0), (int)v9, (int)v54, (int)v55);
      v11 = 0;
      v52 = 0;
      v12 = &dword_1340434[1];
      do
      {
        v33 = (float)v52;
        v34 = (double)word_1340408[0] * 48.0 / 22.0 + v33;
        v53 = FFX_Menu2D_ScaleY_1080to416(v34) + v56;
        if ( ((1 << *(_BYTE *)(*v12 + 1)) & unk_1340430) != 0 )
        {
          v35 = (float)a1;
          sub_903A10(470, (int)(v35 + v57 + 8.0), a2);
          if ( *(char *)(*v12 + 1) < 20 )
          {
            *(float *)&v22 = 0.5546875;
            *(float *)&v21 = 0.61914062;
            *(float *)&v18 = 0.51074219;
          }
          else
          {
            *(float *)&v22 = 0.49609375;
            *(float *)&v21 = 0.61914062;
            *(float *)&v18 = 0.45214844;
          }
          v15 = FFX_Menu2D_ScaleY_1080to416(33.0);
          v14 = FFX_Menu2D_ScaleX_1920to512(54.0);
          *(float *)&v36 = FFX_Menu2D_ScaleY_1080to416(6.0) + v53;
          v13 = v36;
          v37 = v57 - FFX_Menu2D_ScaleX_1920to512(30.0);
          FFX_Menu2D_DrawTexQuadTinted(
            0x190u,
            v37,
            v13,
            v14,
            v15,
            COERCE_INT(0.55273438),
            v18,
            v21,
            v22,
            0x4D808080u,
            0x4D808080u);
        }
        v11 += 48;
        ++v12;
        v52 = v11;
      }
      while ( (int)v12 < (int)&dword_1340434[17] );
    }
    sub_8F9230(0, 0, 512, 416);
  }
}

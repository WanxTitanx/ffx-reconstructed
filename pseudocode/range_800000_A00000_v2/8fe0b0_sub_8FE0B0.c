// Function: sub_8FE0B0
// Address: 0x8fe0b0
void __cdecl sub_8FE0B0(int a1)
{
  int n0xC8; // eax
  double v2; // st6
  double v3; // st7
  _DWORD *v4; // esi
  _DWORD *v5; // edi
  int n0xC8_1; // eax
  int n0x190; // eax
  bool v8; // zf
  char *v9; // edi
  int v10; // eax
  int v11; // ecx
  double v12; // st6
  double v13; // st5
  double v14; // st4
  __int16 n100; // ax
  double v16; // st3
  __int16 n100_1; // ax
  double v18; // st7
  int v19; // esi
  int v20; // eax
  double v21; // st6
  double v22; // rtt
  double v23; // st4
  int v24; // eax
  int v25; // esi
  double v26; // rt0
  int v27; // eax
  double v28; // st7
  double v29; // st7
  double v30; // st7
  int v31; // edx
  double v32; // st7
  double v33; // st7
  float v34; // [esp+0h] [ebp-110h]
  int v35; // [esp+4h] [ebp-10Ch]
  float v36; // [esp+8h] [ebp-108h]
  int v37; // [esp+Ch] [ebp-104h]
  float v38; // [esp+Ch] [ebp-104h]
  float v39; // [esp+10h] [ebp-100h]
  int v40; // [esp+10h] [ebp-100h]
  float v41; // [esp+14h] [ebp-FCh]
  int v42; // [esp+14h] [ebp-FCh]
  int v43; // [esp+14h] [ebp-FCh]
  float v44; // [esp+18h] [ebp-F8h]
  int v45; // [esp+18h] [ebp-F8h]
  float v46; // [esp+1Ch] [ebp-F4h]
  int v47; // [esp+1Ch] [ebp-F4h]
  unsigned int v48; // [esp+20h] [ebp-F0h]
  unsigned int v49; // [esp+24h] [ebp-ECh]
  unsigned int v50; // [esp+28h] [ebp-E8h]
  unsigned int v51; // [esp+2Ch] [ebp-E4h]
  int v52; // [esp+34h] [ebp-DCh]
  int v53; // [esp+38h] [ebp-D8h]
  int v54; // [esp+3Ch] [ebp-D4h]
  char *Str; // [esp+48h] [ebp-C8h]
  float v56; // [esp+4Ch] [ebp-C4h] BYREF
  double v57; // [esp+50h] [ebp-C0h]
  float v58; // [esp+58h] [ebp-B8h] BYREF
  float v59; // [esp+5Ch] [ebp-B4h]
  float v60; // [esp+60h] [ebp-B0h]
  double v61; // [esp+64h] [ebp-ACh]
  double n100_2; // [esp+6Ch] [ebp-A4h]
  int n503_; // [esp+74h] [ebp-9Ch] BYREF
  float v64; // [esp+78h] [ebp-98h]
  float v65; // [esp+7Ch] [ebp-94h]
  float v66; // [esp+80h] [ebp-90h]
  int v67; // [esp+84h] [ebp-8Ch]
  int v68; // [esp+88h] [ebp-88h]
  int v69; // [esp+8Ch] [ebp-84h]
  int v70; // [esp+90h] [ebp-80h]
  float v71; // [esp+94h] [ebp-7Ch]
  float v72; // [esp+98h] [ebp-78h]
  float v73; // [esp+9Ch] [ebp-74h]
  float v74; // [esp+A0h] [ebp-70h]
  int v75; // [esp+A4h] [ebp-6Ch]
  int v76; // [esp+A8h] [ebp-68h]
  int v77; // [esp+ACh] [ebp-64h]
  int v78; // [esp+B0h] [ebp-60h]
  int v79; // [esp+F4h] [ebp-1Ch]
  int v80; // [esp+FCh] [ebp-14h]
  int v81; // [esp+104h] [ebp-Ch]
  int v82; // [esp+108h] [ebp-8h]

  n0xC8 = *(unsigned __int16 *)(a1 + 20);
  v81 = 0;
  v82 = 0;
  v79 = 0;
  v80 = 0;
  if ( (_WORD)n0xC8 != 415 && (_WORD)n0xC8 != 419 && (_WORD)n0xC8 != 411 && (_WORD)n0xC8 != 412 && (_WORD)n0xC8 != 507 )
  {
    if ( (_WORD)n0xC8 == 417 )
    {
      HIDWORD(n100_2) = *(__int16 *)(a1 + 16);
      v61 = (double)SHIDWORD(n100_2);
      HIDWORD(n100_2) = *(__int16 *)(a1 + 18);
      v60 = v61 / 100.0;
      v61 = (double)SHIDWORD(n100_2);
      v59 = v61 / 100.0;
      if ( *(__int16 *)(a1 + 14) <= 330 )
      {
        v51 = *(_DWORD *)(a1 + 8);
        v50 = *(_DWORD *)(a1 + 4);
        v2 = v59 * 120.0;
        if ( *(_WORD *)(a1 + 12) == 116 )
        {
          v61 = 120.0 * v60;
          *((float *)&n100_2 + 1) = v2;
          v41 = FFX_Menu2D_ScaleY_1080to416(*((float *)&n100_2 + 1));
          *((float *)&n100_2 + 1) = v61;
          v39 = FFX_Menu2D_ScaleX_1920to512(*((float *)&n100_2 + 1));
          *((float *)&n100_2 + 1) = 535.0 - 0.5 * v2;
          *(float *)&v37 = FFX_Menu2D_ScaleY_1080to416(*((float *)&n100_2 + 1));
          *((float *)&n100_2 + 1) = 0.5 * v61;
          *((float *)&n100_2 + 1) = 160.0 - FFX_Menu2D_ScaleX_1920to512(*((float *)&n100_2 + 1));
        }
        else
        {
          v61 = 120.0 * v60;
          *((float *)&n100_2 + 1) = v2;
          v41 = FFX_Menu2D_ScaleY_1080to416(*((float *)&n100_2 + 1));
          *((float *)&n100_2 + 1) = v61;
          v39 = FFX_Menu2D_ScaleX_1920to512(*((float *)&n100_2 + 1));
          *((float *)&n100_2 + 1) = 535.0 - 0.5 * v2;
          *(float *)&v37 = FFX_Menu2D_ScaleY_1080to416(*((float *)&n100_2 + 1));
          *((float *)&n100_2 + 1) = 0.5 * v61;
          *((float *)&n100_2 + 1) = 388.0 - FFX_Menu2D_ScaleX_1920to512(*((float *)&n100_2 + 1));
        }
        FFX_Menu2D_DrawTexQuadTinted(
          0xFFFFFFFF,
          *((float *)&n100_2 + 1),
          v37,
          v39,
          v41,
          COERCE_INT(1759.0),
          COERCE_INT(1.0),
          COERCE_INT(1835.0),
          COERCE_INT(77.0),
          v50,
          v51);
      }
    }
    else if ( (_WORD)n0xC8 == 240 )
    {
      HIDWORD(n100_2) = *(__int16 *)(a1 + 14);
      v3 = (double)SHIDWORD(n100_2);
      HIDWORD(n100_2) = *(__int16 *)(a1 + 12);
      v61 = v3;
      v57 = (double)SHIDWORD(n100_2);
      v46 = FFX_Menu2D_ScaleY_1080to416(186.0);
      v44 = FFX_Menu2D_ScaleX_1920to512(89.0);
      *((float *)&n100_2 + 1) = v61 - FFX_Menu2D_ScaleY_1080to416(185.0);
      v42 = SHIDWORD(n100_2);
      *((float *)&n100_2 + 1) = v57 - FFX_Menu2D_ScaleX_1920to512(10.0);
      FFX_Menu2D_DrawTexQuadSolid(
        0xC8u,
        *((float *)&n100_2 + 1),
        v42,
        v44,
        v46,
        COERCE_INT(0.0078125),
        COERCE_INT(0.0),
        COERCE_INT(0.094726562),
        COERCE_INT(0.18164062));
    }
    else
    {
      if ( (unsigned __int16)n0xC8 >= 0xC8u )
      {
        v4 = (_DWORD *)HIDWORD(v61);
        v5 = (_DWORD *)HIDWORD(v61);
        v60 = *((float *)&v61 + 1);
        Str = (char *)HIDWORD(v61);
      }
      else
      {
        v4 = (_DWORD *)sub_8FA7D0(n0xC8);
        v60 = *(float *)&v4;
        v5 = v4 + 1;
        Str = FFX_Menu2D_TexHandleByAtlasId(15872);
        FFX_Menu2D_GetAtlasDimensions_structural(15872, &v56, &v58);
      }
      n0xC8_1 = *(unsigned __int16 *)(a1 + 20);
      if ( (unsigned __int16)n0xC8_1 >= 0xC8u && (unsigned __int16)n0xC8_1 < 0x190u )
      {
        v4 = (_DWORD *)sub_8FA7D0(n0xC8_1 - 200);
        v60 = *(float *)&v4;
        v5 = v4 + 1;
        Str = FFX_Menu2D_TexHandleByAtlasId(15872);
        FFX_Menu2D_GetAtlasDimensions_structural(15872, &v56, &v58);
      }
      n0x190 = *(unsigned __int16 *)(a1 + 20);
      if ( (unsigned __int16)n0x190 >= 0x190u && (unsigned __int16)n0x190 < 0x258u )
      {
        v4 = (_DWORD *)sub_8FA450(n0x190 - 400);
        v60 = *(float *)&v4;
        v5 = v4 + 1;
        Str = FFX_Menu2D_TexHandleByAtlasId(16128);
        FFX_Menu2D_GetAtlasDimensions_structural(16128, &v56, &v58);
      }
      v8 = *v4 == 0;
      v52 = *(unsigned __int8 *)(a1 + 4);
      v53 = *(unsigned __int8 *)(a1 + 5);
      HIDWORD(v57) = *(unsigned __int8 *)(a1 + 6);
      HIDWORD(v61) = *(unsigned __int8 *)(a1 + 7);
      v59 = 0.0;
      if ( !v8 )
      {
        v9 = (char *)v5 + 3;
        while ( 2 )
        {
          v10 = *(v9 - 1) + *(unsigned __int16 *)(v9 + 1);
          HIDWORD(n100_2) = *(v9 - 1);
          v11 = *v9;
          v12 = (double)SHIDWORD(n100_2);
          HIDWORD(n100_2) = v10;
          v13 = (double)v10;
          v14 = (double)v11;
          HIDWORD(n100_2) = v11 + *(unsigned __int16 *)(v9 + 3);
          n100 = *(_WORD *)(a1 + 16);
          v16 = (double)SHIDWORD(n100_2);
          if ( n100 != 100 )
          {
            n100_2 = (double)n100;
            v12 = v12 / 100.0 * n100_2;
            v13 = n100_2 * (v13 / 100.0);
          }
          n100_1 = *(_WORD *)(a1 + 18);
          if ( n100_1 == 100 )
          {
            v18 = v16;
          }
          else
          {
            n100_2 = (double)n100_1;
            v14 = v14 / 100.0 * n100_2;
            v18 = n100_2 * (v16 / 100.0);
          }
          v19 = *(__int16 *)(a1 + 12);
          if ( *(_WORD *)(v9 + 5) == 1 )
          {
            v20 = (int)v13;
            v13 = v12;
            v21 = v14;
          }
          else
          {
            v22 = v14;
            v23 = v12;
            v21 = v22;
            v20 = (int)v23;
          }
          v54 = v19 + v20;
          v24 = v19 + (int)v13;
          v25 = *(__int16 *)(a1 + 14);
          if ( *(_WORD *)(v9 + 7) == 1 )
          {
            v26 = v21;
            v21 = v18;
            v18 = v26;
          }
          *(float *)&n503_ = (float)v54;
          HIDWORD(n100_2) = v25 + (int)v18;
          v64 = (float)(v25 + (int)v21);
          v67 = v52;
          v75 = v52;
          v68 = v53;
          v76 = v53;
          v71 = (float)v24;
          v69 = HIDWORD(v57);
          v70 = HIDWORD(v61);
          v77 = HIDWORD(v57);
          v78 = HIDWORD(v61);
          v72 = (float)SHIDWORD(n100_2);
          HIDWORD(n100_2) = (unsigned __int8)*(v9 - 3);
          n100_2 = (double)SHIDWORD(n100_2);
          v65 = n100_2 / v56;
          HIDWORD(n100_2) = (unsigned __int8)*(v9 - 2);
          n100_2 = (double)SHIDWORD(n100_2);
          v66 = n100_2 / v58;
          HIDWORD(n100_2) = *(unsigned __int16 *)(v9 + 1) - 1 + (unsigned __int8)*(v9 - 3);
          *((float *)&n100_2 + 1) = (float)SHIDWORD(n100_2);
          v73 = *((float *)&n100_2 + 1) / v56;
          HIDWORD(n100_2) = *(unsigned __int16 *)(v9 + 3) + (unsigned __int8)*(v9 - 2) - 1;
          *((float *)&n100_2 + 1) = (float)SHIDWORD(n100_2);
          v27 = *(unsigned __int16 *)(a1 + 20) - 413;
          v74 = *((float *)&n100_2 + 1) / v58;
          switch ( v27 )
          {
            case 0:
              if ( v64 <= 300.0 )
              {
                sub_8F59C0(
                  (int)(*(float *)&n503_ * 1920.0 * 0.001953125 - 21.0),
                  (int)(v64 * 1080.0 / 416.0 - 18.0),
                  332,
                  32,
                  274,
                  61,
                  SHIDWORD(v61),
                  SHIDWORD(v61));
                v61 = v64;
                v49 = (v78 << 24) + 8421504;
                v48 = (v70 << 24) + 8421504;
                *(float *)&v47 = 0.4921875;
                *(float *)&v45 = 0.33496094;
                *(float *)&v43 = 0.45605469;
                *(float *)&v40 = 0.0625;
                v38 = FFX_Menu2D_ScaleY_1080to416(24.0);
                v36 = FFX_Menu2D_ScaleX_1920to512(201.0);
                v28 = FFX_Menu2D_ScaleY_1080to416(14.0);
                *((float *)&v61 + 1) = v61 - v28;
                v35 = SHIDWORD(v61);
                v29 = FFX_Menu2D_ScaleX_1920to512(13.0);
                *((float *)&v61 + 1) = v29 + *(float *)&n503_;
                v30 = *((float *)&v61 + 1);
                goto LABEL_46;
              }
              return;
            case 1:
              sub_8E8A10((int)&n503_, 4141);
              goto LABEL_41;
            case 90:
              v31 = HIDWORD(v61) << 24;
              v61 = v64;
              v57 = *(float *)&n503_;
              v49 = v31 + 8421504;
              v48 = v31 + 8421504;
              *(float *)&v47 = 0.67871094;
              *(float *)&v45 = 0.74511719;
              *(float *)&v43 = 0.63183594;
              *(float *)&v40 = 0.68847656;
              v38 = FFX_Menu2D_ScaleY_1080to416(48.0);
              v36 = FFX_Menu2D_ScaleX_1920to512(58.0);
              v32 = FFX_Menu2D_ScaleY_1080to416(14.0);
              *((float *)&v61 + 1) = v61 - v32;
              v35 = SHIDWORD(v61);
              v33 = FFX_Menu2D_ScaleX_1920to512(53.0);
              *((float *)&v61 + 1) = v57 - v33;
              v30 = *((float *)&v61 + 1);
LABEL_46:
              v34 = v30;
              FFX_Menu2D_DrawTexQuadTinted(0x190u, v34, v35, v36, v38, v40, v43, v45, v47, v48, v49);
              return;
            case 94:
              if ( v59 == 0.0 )
                sub_8E8A10((int)&n503_, 411);
              else
                sub_8E8A10((int)&n503_, 507);
              goto LABEL_41;
            case 95:
              sub_8E8A10((int)&n503_, 508);
              goto LABEL_41;
            default:
LABEL_41:
              sub_63F090((int)&n503_, Str, 1, 0, 0.0);
              v9 += 12;
              if ( ++LODWORD(v59) < *(_DWORD *)LODWORD(v60) )
                continue;
              return;
          }
        }
      }
    }
  }
}

// Function: sub_8E6070
// Address: 0x8e6070
int __cdecl sub_8E6070(int a1, float a2, int a3, float a4, float a5, unsigned int a6, unsigned int a7)
{
  int result; // eax
  double v8; // st7
  double v9; // st7
  double v10; // st7
  int v13; // [esp+4h] [ebp-24h]
  int v14; // [esp+4h] [ebp-24h]
  int v15; // [esp+4h] [ebp-24h]
  int v16; // [esp+4h] [ebp-24h]
  int v17; // [esp+4h] [ebp-24h]
  float v18; // [esp+8h] [ebp-20h]
  float v19; // [esp+Ch] [ebp-1Ch]
  float v20; // [esp+Ch] [ebp-1Ch]
  float v21; // [esp+Ch] [ebp-1Ch]
  float v22; // [esp+Ch] [ebp-1Ch]
  float v23; // [esp+Ch] [ebp-1Ch]
  float v24; // [esp+Ch] [ebp-1Ch]
  float v25; // [esp+Ch] [ebp-1Ch]
  int v26; // [esp+10h] [ebp-18h]
  int v27; // [esp+14h] [ebp-14h]
  int v28; // [esp+18h] [ebp-10h]
  int v29; // [esp+1Ch] [ebp-Ch]
  unsigned int v30; // [esp+20h] [ebp-8h]
  unsigned int v31; // [esp+24h] [ebp-4h]
  float v32; // [esp+30h] [ebp+8h]
  float v33; // [esp+30h] [ebp+8h]
  float v34; // [esp+30h] [ebp+8h]
  float v35; // [esp+30h] [ebp+8h]
  float v36; // [esp+30h] [ebp+8h]
  float v37; // [esp+30h] [ebp+8h]
  float v38; // [esp+30h] [ebp+8h]
  float v39; // [esp+30h] [ebp+8h]
  float v40; // [esp+30h] [ebp+8h]
  float v41; // [esp+30h] [ebp+8h]
  float v42; // [esp+30h] [ebp+8h]
  float v43; // [esp+30h] [ebp+8h]
  float v44; // [esp+30h] [ebp+8h]
  float v45; // [esp+30h] [ebp+8h]
  float v46; // [esp+30h] [ebp+8h]
  float v47; // [esp+30h] [ebp+8h]
  float v48; // [esp+38h] [ebp+10h]
  float v49; // [esp+38h] [ebp+10h]
  int v50; // [esp+38h] [ebp+10h]
  float v51; // [esp+38h] [ebp+10h]
  int v52; // [esp+38h] [ebp+10h]
  float v53; // [esp+38h] [ebp+10h]
  int v54; // [esp+38h] [ebp+10h]
  float v55; // [esp+38h] [ebp+10h]
  int v56; // [esp+38h] [ebp+10h]
  float v57; // [esp+38h] [ebp+10h]
  float v58; // [esp+38h] [ebp+10h]
  float v59; // [esp+38h] [ebp+10h]

  result = a1 - 600;
  switch ( a1 )
  {
    case 600:
      v32 = a5 * 0.449999988079071;
      v19 = v32;
      v33 = 0.3899999856948853 * a4;
      v48 = a4 * 0.3050000071525574 + a2;
      return FFX_Menu2D_DrawTexQuadTinted(
               0x258u,
               v48,
               a3,
               v33,
               v19,
               COERCE_INT(384.0),
               COERCE_INT(223.0),
               COERCE_INT(412.0),
               COERCE_INT(255.0),
               a6,
               a7);
    case 601:
      v34 = a5 * 0.449999988079071;
      v20 = v34;
      v35 = 0.3899999856948853 * a4;
      v49 = a4 * 0.3050000071525574 + a2;
      return FFX_Menu2D_DrawTexQuadTinted(
               0x258u,
               v49,
               a3,
               v35,
               v20,
               COERCE_INT(416.0),
               COERCE_INT(223.0),
               COERCE_INT(444.0),
               COERCE_INT(255.0),
               a6,
               a7);
    case 602:
      v36 = 0.3899999856948853 * a5;
      v21 = v36;
      v37 = 0.449999988079071 * a4;
      *(float *)&v50 = a5 * 0.3050000071525574 + *(float *)&a3;
      v13 = v50;
      v51 = a4 * 0.550000011920929 + a2;
      return FFX_Menu2D_DrawTexQuadTinted(
               0x258u,
               v51,
               v13,
               v37,
               v21,
               COERCE_INT(384.0),
               COERCE_INT(256.0),
               COERCE_INT(416.0),
               COERCE_INT(284.0),
               a6,
               a7);
    case 603:
      v38 = 0.3899999856948853 * a5;
      v22 = v38;
      v39 = 0.449999988079071 * a4;
      *(float *)&v52 = a5 * 0.3050000071525574 + *(float *)&a3;
      v14 = v52;
      v53 = a4 * 0.550000011920929 + a2;
      return FFX_Menu2D_DrawTexQuadTinted(
               0x258u,
               v53,
               v14,
               v39,
               v22,
               COERCE_INT(416.0),
               COERCE_INT(256.0),
               COERCE_INT(448.0),
               COERCE_INT(284.0),
               a6,
               a7);
    case 604:
      v40 = 0.449999988079071 * a5;
      v23 = v40;
      v41 = 0.3899999856948853 * a4;
      *(float *)&v54 = a5 * 0.5 + *(float *)&a3;
      v15 = v54;
      v55 = a4 * 0.3050000071525574 + a2;
      return FFX_Menu2D_DrawTexQuadTinted(
               0x258u,
               v55,
               v15,
               v41,
               v23,
               COERCE_INT(448.0),
               COERCE_INT(223.0),
               COERCE_INT(476.0),
               COERCE_INT(255.0),
               a6,
               a7);
    case 605:
      v42 = 0.449999988079071 * a5;
      v24 = v42;
      v43 = 0.3899999856948853 * a4;
      *(float *)&v56 = a5 * 0.5 + *(float *)&a3;
      v16 = v56;
      v57 = a4 * 0.3050000071525574 + a2;
      return FFX_Menu2D_DrawTexQuadTinted(
               0x258u,
               v57,
               v16,
               v43,
               v24,
               COERCE_INT(479.0),
               COERCE_INT(223.0),
               COERCE_INT(507.0),
               COERCE_INT(255.0),
               a6,
               a7);
    case 606:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 316.0;
      *(float *)&v28 = 416.0;
      *(float *)&v27 = 288.0;
      *(float *)&v26 = 384.0;
      v44 = 0.3899999856948853 * a5;
      v25 = v44;
      v45 = a4 * 0.449999988079071;
      v18 = v45;
      v58 = a5 * 0.3050000071525574 + *(float *)&a3;
      v8 = v58;
      goto LABEL_22;
    case 607:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 316.0;
      *(float *)&v28 = 448.0;
      *(float *)&v27 = 288.0;
      *(float *)&v26 = 416.0;
      v46 = 0.3899999856948853 * a5;
      v25 = v46;
      v47 = a4 * 0.449999988079071;
      v18 = v47;
      v59 = a5 * 0.3050000071525574 + *(float *)&a3;
      v8 = v59;
      goto LABEL_22;
    case 608:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 267.0;
      *(float *)&v28 = 43.0;
      v9 = 224.0;
      goto LABEL_20;
    case 609:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 267.0;
      *(float *)&v28 = 139.0;
      *(float *)&v27 = 224.0;
      v10 = 96.0;
      goto LABEL_21;
    case 610:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 267.0;
      *(float *)&v28 = 236.0;
      *(float *)&v27 = 224.0;
      v10 = 192.0;
      goto LABEL_21;
    case 611:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 267.0;
      *(float *)&v28 = 332.0;
      *(float *)&v27 = 224.0;
      v10 = 289.0;
      goto LABEL_21;
    case 612:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 255.0;
      *(float *)&v28 = 559.0;
      *(float *)&v27 = 222.0;
      v10 = 511.0;
      goto LABEL_21;
    case 613:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 255.0;
      *(float *)&v28 = 751.0;
      *(float *)&v27 = 222.0;
      v10 = 704.0;
      goto LABEL_21;
    case 614:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 255.0;
      *(float *)&v28 = 656.0;
      *(float *)&v27 = 222.0;
      v10 = 608.0;
      goto LABEL_21;
    case 615:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 255.0;
      *(float *)&v28 = 848.0;
      *(float *)&v27 = 222.0;
      v10 = 800.0;
      goto LABEL_21;
    case 616:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 355.0;
      *(float *)&v28 = 286.0;
      *(float *)&v27 = 298.0;
      v10 = 194.0;
      goto LABEL_21;
    case 617:
      v31 = a7;
      v30 = a6;
      *(float *)&v29 = 336.0;
      *(float *)&v28 = 84.0;
      v9 = 298.0;
LABEL_20:
      *(float *)&v27 = v9;
      v10 = 0.0;
LABEL_21:
      *(float *)&v26 = v10;
      v25 = a5;
      v18 = a4;
      v8 = *(float *)&a3;
LABEL_22:
      *(float *)&v17 = v8;
      result = FFX_Menu2D_DrawTexQuadTinted(0x258u, a2, v17, v18, v25, v26, v27, v28, v29, v30, v31);
      break;
    default:
      return result;
  }
  return result;
}

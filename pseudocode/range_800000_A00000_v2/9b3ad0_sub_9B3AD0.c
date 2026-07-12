// Function: sub_9B3AD0
// Address: 0x9b3ad0
char __usercall sub_9B3AD0@<al>(int a1@<ecx>, int a2@<ebp>)
{
  int v3; // eax
  double v4; // st7
  double v5; // st7
  char result; // al
  _WORD *v7; // ecx
  double v8; // st7
  double v9; // st5
  double v10; // st7
  double v11; // st6
  float v12; // xmm0_4
  double v13; // st7
  double v14; // st6
  double v15; // st5
  double v16; // st4
  double v17; // st6
  double v18; // st5
  double v19; // rt0
  double v20; // st7
  double v21; // st7
  double v22; // st7
  double v23; // st7
  double v24; // st7
  double v25; // st7
  double v26; // st7
  double v27; // st7
  double v28; // st7
  double v29; // st7
  double v30; // st7
  float v31; // [esp-70h] [ebp-7Ch] BYREF
  float v32; // [esp-6Ch] [ebp-78h]
  float v33; // [esp-68h] [ebp-74h]
  int v34; // [esp-64h] [ebp-70h]
  float v35; // [esp-60h] [ebp-6Ch]
  float v36; // [esp-5Ch] [ebp-68h]
  float v37; // [esp-58h] [ebp-64h]
  float v38; // [esp-50h] [ebp-5Ch]
  float v39; // [esp-4Ch] [ebp-58h]
  float v40; // [esp-48h] [ebp-54h]
  float v41; // [esp-40h] [ebp-4Ch]
  float v42; // [esp-3Ch] [ebp-48h]
  float v43; // [esp-38h] [ebp-44h]
  float v44; // [esp-30h] [ebp-3Ch]
  float v45; // [esp-2Ch] [ebp-38h]
  float v46; // [esp-28h] [ebp-34h]
  float v47; // [esp-20h] [ebp-2Ch]
  float v48; // [esp-1Ch] [ebp-28h]
  float v49; // [esp-18h] [ebp-24h]
  int v50; // [esp-14h] [ebp-20h]
  float v51; // [esp-8h] [ebp-14h]
  float v52; // [esp-4h] [ebp-10h]
  _DWORD v53[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v53[0] = a2;
  v53[1] = retaddr;
  if ( *(_BYTE *)(a1 + 384) )
  {
    *(_BYTE *)(a1 + 372) = 0;
    *(_DWORD *)(a1 + 356) = 0;
    *(_DWORD *)(a1 + 360) = 0;
    *(_DWORD *)(a1 + 364) = 0;
    *(_DWORD *)(a1 + 368) = 0;
    *(_WORD *)(a1 + 352) &= 0xFFF0u;
    v3 = *(_DWORD *)a1;
    *(_BYTE *)(a1 + 384) = 0;
    switch ( v3 )
    {
      case 1:
        *(_DWORD *)(a1 + 256) = *(_DWORD *)(a1 + 96);
        *(_DWORD *)(a1 + 260) = *(_DWORD *)(a1 + 100);
        *(_DWORD *)(a1 + 264) = *(_DWORD *)(a1 + 104);
        *(_DWORD *)(a1 + 268) = *(_DWORD *)(a1 + 108);
        *(_DWORD *)(a1 + 272) = *(_DWORD *)(a1 + 176);
        *(_DWORD *)(a1 + 276) = *(_DWORD *)(a1 + 180);
        *(_DWORD *)(a1 + 280) = *(_DWORD *)(a1 + 184);
        *(_DWORD *)(a1 + 284) = *(_DWORD *)(a1 + 188);
        v4 = *(float *)(a1 + 256) - *(float *)(a1 + 272);
        v50 = 0;
        v47 = v4;
        v48 = *(float *)(a1 + 260) - *(float *)(a1 + 276);
        v5 = *(float *)(a1 + 264) - *(float *)(a1 + 280);
        *(float *)(a1 + 288) = v47;
        *(float *)(a1 + 292) = v48;
        v49 = v5;
        *(float *)(a1 + 296) = v49;
        *(_DWORD *)(a1 + 300) = v50;
        sub_9B39C0(a1 + 336);
        *(_DWORD *)(a1 + 356) = 1065353216;
        *(_DWORD *)(a1 + 360) = 0;
        *(_DWORD *)(a1 + 364) = 0;
        *(_DWORD *)(a1 + 368) = 0;
        *(_BYTE *)(a1 + 324) = 1;
        return *(_BYTE *)(a1 + 324);
      case 2:
        v7 = (_WORD *)(a1 + 352);
        v52 = *(float *)(a1 + 16);
        v8 = v52;
        v44 = 0.0 - v52;
        v52 = *(float *)(a1 + 20);
        v9 = v52;
        v45 = 0.0 - v52;
        v52 = *(float *)(a1 + 24);
        v46 = 0.0 - v52;
        v47 = *(float *)(a1 + 32) - v8;
        v48 = *(float *)(a1 + 36) - v9;
        v49 = *(float *)(a1 + 40) - v52;
        v52 = v48 * v45 + v47 * v44 + v49 * v46;
        if ( v52 <= 0.0 )
        {
          v12 = 0.0;
          *v7 |= 1u;
        }
        else
        {
          v10 = v52;
          v51 = v47 * v47 + v48 * v48 + v49 * v49;
          v11 = v51;
          if ( v51 > (double)v52 )
          {
            *v7 |= 3u;
            v52 = v10 / v11;
            v12 = v52;
            goto LABEL_10;
          }
          v12 = 1.0;
          *v7 |= 2u;
        }
        v52 = v12;
LABEL_10:
        v13 = v52;
        *(float *)(a1 + 360) = v12;
        *(_DWORD *)(a1 + 364) = 0;
        *(_DWORD *)(a1 + 368) = 0;
        v50 = 0;
        *(float *)(a1 + 356) = 1.0 - v13;
        v51 = *(float *)(a1 + 96);
        v14 = v51;
        v44 = *(float *)(a1 + 112) - v51;
        v51 = *(float *)(a1 + 100);
        v15 = v51;
        v45 = *(float *)(a1 + 116) - v51;
        v51 = *(float *)(a1 + 104);
        v16 = v51;
        v46 = *(float *)(a1 + 120) - v51;
        v41 = v44 * v13;
        v42 = v45 * v13;
        v43 = v46 * v13;
        v47 = v14 + v41;
        *(float *)(a1 + 256) = v47;
        v48 = v15 + v42;
        *(float *)(a1 + 260) = v48;
        v49 = v16 + v43;
        *(float *)(a1 + 264) = v49;
        *(_DWORD *)(a1 + 268) = v50;
        v51 = *(float *)(a1 + 176);
        v17 = v51;
        v41 = *(float *)(a1 + 192) - v51;
        v51 = *(float *)(a1 + 180);
        v18 = v51;
        v42 = *(float *)(a1 + 196) - v51;
        v51 = *(float *)(a1 + 184);
        v43 = *(float *)(a1 + 200) - v51;
        v50 = 0;
        v44 = v41 * v13;
        v45 = v42 * v13;
        v19 = v51;
        v46 = v13 * v43;
        v47 = v17 + v44;
        *(float *)(a1 + 272) = v47;
        v48 = v18 + v45;
        *(float *)(a1 + 276) = v48;
        v49 = v19 + v46;
        *(float *)(a1 + 280) = v49;
        *(_DWORD *)(a1 + 284) = v50;
        v20 = *(float *)(a1 + 256) - *(float *)(a1 + 272);
        v50 = 0;
        v47 = v20;
        v48 = *(float *)(a1 + 260) - *(float *)(a1 + 276);
        v21 = *(float *)(a1 + 264) - *(float *)(a1 + 280);
        *(float *)(a1 + 288) = v47;
        *(float *)(a1 + 292) = v48;
        v49 = v21;
        *(float *)(a1 + 296) = v49;
        *(_DWORD *)(a1 + 300) = v50;
        sub_9B38D0((int *)a1, (_BYTE *)(a1 + 352));
        if ( *(float *)(a1 + 356) < 0.0
          || *(float *)(a1 + 360) < 0.0
          || *(float *)(a1 + 364) < 0.0
          || *(float *)(a1 + 368) < 0.0 )
        {
          goto LABEL_15;
        }
        *(_BYTE *)(a1 + 324) = 1;
        return 1;
      case 3:
        v31 = 0.0;
        v32 = 0.0;
        v33 = 0.0;
        v34 = 0;
        sub_9B2DD0(&v31, a1 + 16, a1 + 32, a1 + 48, a1 + 336);
        v52 = *(float *)(a1 + 364);
        v50 = 0;
        v35 = *(float *)(a1 + 128) * v52;
        v36 = *(float *)(a1 + 132) * v52;
        v37 = v52 * *(float *)(a1 + 136);
        v52 = *(float *)(a1 + 360);
        v44 = v52 * *(float *)(a1 + 112);
        v45 = *(float *)(a1 + 116) * v52;
        v46 = v52 * *(float *)(a1 + 120);
        v52 = *(float *)(a1 + 356);
        v41 = *(float *)(a1 + 96) * v52;
        v42 = *(float *)(a1 + 100) * v52;
        v43 = v52 * *(float *)(a1 + 104);
        v38 = v41 + v44;
        v39 = v42 + v45;
        v40 = v43 + v46;
        v47 = v38 + v35;
        v22 = v39;
        *(float *)(a1 + 256) = v47;
        v48 = v22 + v36;
        v23 = v40;
        *(float *)(a1 + 260) = v48;
        v49 = v23 + v37;
        *(float *)(a1 + 264) = v49;
        *(_DWORD *)(a1 + 268) = v50;
        v52 = *(float *)(a1 + 364);
        v44 = *(float *)(a1 + 208) * v52;
        v45 = *(float *)(a1 + 212) * v52;
        v46 = v52 * *(float *)(a1 + 216);
        v52 = *(float *)(a1 + 360);
        v38 = v52 * *(float *)(a1 + 192);
        v39 = *(float *)(a1 + 196) * v52;
        v40 = v52 * *(float *)(a1 + 200);
        v52 = *(float *)(a1 + 356);
        v35 = v52 * *(float *)(a1 + 176);
        v36 = *(float *)(a1 + 180) * v52;
        v37 = v52 * *(float *)(a1 + 184);
        v41 = v35 + v38;
        v42 = v36 + v39;
        v43 = v37 + v40;
        v47 = v41 + v44;
        v48 = v42 + v45;
        v24 = v43;
        goto LABEL_18;
      case 4:
        v31 = 0.0;
        v32 = 0.0;
        v33 = 0.0;
        v34 = 0;
        if ( sub_9B2910(a1, (int)v53, &v31, a1 + 16, a1 + 32, a1 + 48, a1 + 64, a1 + 336) )
        {
          v28 = *(float *)(a1 + 368);
          v50 = 0;
          v52 = v28;
          v31 = v52 * *(float *)(a1 + 144);
          v32 = *(float *)(a1 + 148) * v52;
          v33 = v52 * *(float *)(a1 + 152);
          v52 = *(float *)(a1 + 364);
          v44 = *(float *)(a1 + 128) * v52;
          v45 = *(float *)(a1 + 132) * v52;
          v46 = v52 * *(float *)(a1 + 136);
          v52 = *(float *)(a1 + 360);
          v38 = v52 * *(float *)(a1 + 112);
          v39 = *(float *)(a1 + 116) * v52;
          v40 = v52 * *(float *)(a1 + 120);
          v52 = *(float *)(a1 + 356);
          v35 = *(float *)(a1 + 96) * v52;
          v36 = *(float *)(a1 + 100) * v52;
          v37 = v52 * *(float *)(a1 + 104);
          v41 = v35 + v38;
          v42 = v36 + v39;
          v43 = v37 + v40;
          v35 = v41 + v44;
          v36 = v42 + v45;
          v37 = v43 + v46;
          v47 = v35 + v31;
          v29 = v36;
          *(float *)(a1 + 256) = v47;
          v48 = v29 + v32;
          v30 = v37;
          *(float *)(a1 + 260) = v48;
          v49 = v30 + v33;
          *(float *)(a1 + 264) = v49;
          *(_DWORD *)(a1 + 268) = v50;
          v52 = *(float *)(a1 + 368);
          v44 = *(float *)(a1 + 224) * v52;
          v45 = *(float *)(a1 + 228) * v52;
          v46 = v52 * *(float *)(a1 + 232);
          v52 = *(float *)(a1 + 364);
          v41 = *(float *)(a1 + 208) * v52;
          v42 = *(float *)(a1 + 212) * v52;
          v43 = v52 * *(float *)(a1 + 216);
          v52 = *(float *)(a1 + 360);
          v35 = v52 * *(float *)(a1 + 192);
          v36 = *(float *)(a1 + 196) * v52;
          v37 = v52 * *(float *)(a1 + 200);
          v52 = *(float *)(a1 + 356);
          v31 = v52 * *(float *)(a1 + 176);
          v32 = *(float *)(a1 + 180) * v52;
          v33 = v52 * *(float *)(a1 + 184);
          v38 = v31 + v35;
          v39 = v32 + v36;
          v40 = v33 + v37;
          v31 = v38 + v41;
          v32 = v39 + v42;
          v33 = v40 + v43;
          v47 = v31 + v44;
          v48 = v32 + v45;
          v24 = v33;
LABEL_18:
          v25 = v24 + v46;
          *(float *)(a1 + 272) = v47;
          *(float *)(a1 + 276) = v48;
          v49 = v25;
          *(float *)(a1 + 280) = v49;
          v50 = 0;
          *(_DWORD *)(a1 + 284) = 0;
          v26 = *(float *)(a1 + 256) - *(float *)(a1 + 272);
          v50 = 0;
          v47 = v26;
          v48 = *(float *)(a1 + 260) - *(float *)(a1 + 276);
          v27 = *(float *)(a1 + 264) - *(float *)(a1 + 280);
          *(float *)(a1 + 288) = v47;
          *(float *)(a1 + 292) = v48;
          v49 = v27;
          *(float *)(a1 + 296) = v49;
          *(_DWORD *)(a1 + 300) = v50;
          sub_9B38D0((int *)a1, (_BYTE *)(a1 + 352));
          if ( *(float *)(a1 + 356) < 0.0
            || *(float *)(a1 + 360) < 0.0
            || *(float *)(a1 + 364) < 0.0
            || *(float *)(a1 + 368) < 0.0 )
          {
LABEL_15:
            result = 0;
          }
          else
          {
            result = 1;
          }
          *(_BYTE *)(a1 + 324) = result;
          return result;
        }
        if ( !*(_BYTE *)(a1 + 372) )
        {
          *(_BYTE *)(a1 + 324) = 1;
          *(_DWORD *)(a1 + 288) = 0;
          *(_DWORD *)(a1 + 292) = 0;
          *(_DWORD *)(a1 + 296) = 0;
          *(_DWORD *)(a1 + 300) = 0;
          return *(_BYTE *)(a1 + 324);
        }
LABEL_27:
        *(_BYTE *)(a1 + 324) = 0;
        break;
      default:
        goto LABEL_27;
    }
  }
  return *(_BYTE *)(a1 + 324);
}

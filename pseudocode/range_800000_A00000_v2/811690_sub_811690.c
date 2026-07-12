// Function: sub_811690
// Address: 0x811690
char __cdecl sub_811690(int a1, int a2)
{
  int v2; // esi
  int n2622_1; // eax
  int v4; // ecx
  int v5; // ebx
  double v6; // st7
  double v7; // st7
  double n2622_6; // st7
  double v9; // st6
  double v10; // st5
  double v11; // st3
  unsigned __int16 *n2622_9; // ecx
  unsigned __int16 v13; // ax
  int v14; // ebx
  unsigned __int16 v15; // si
  float *v16; // ecx
  unsigned __int16 v17; // dx
  unsigned __int16 v18; // ax
  float *v19; // esi
  double v20; // st7
  int v21; // esi
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // ecx
  int v26; // eax
  bool v27; // cc
  bool v28; // zf
  __int64 v30; // [esp-4h] [ebp-9Ch]
  int v31; // [esp+20h] [ebp-78h]
  float v32; // [esp+24h] [ebp-74h]
  float v33; // [esp+28h] [ebp-70h]
  float v34; // [esp+2Ch] [ebp-6Ch]
  float v35; // [esp+30h] [ebp-68h]
  float v36; // [esp+34h] [ebp-64h]
  float v37; // [esp+38h] [ebp-60h]
  float v38; // [esp+3Ch] [ebp-5Ch]
  float v39; // [esp+44h] [ebp-54h]
  float v40; // [esp+48h] [ebp-50h]
  float v41; // [esp+4Ch] [ebp-4Ch]
  float v42; // [esp+50h] [ebp-48h]
  int v43; // [esp+54h] [ebp-44h]
  int v44; // [esp+58h] [ebp-40h]
  unsigned int v45; // [esp+5Ch] [ebp-3Ch]
  float v46; // [esp+60h] [ebp-38h]
  float v47; // [esp+60h] [ebp-38h]
  float v48; // [esp+64h] [ebp-34h]
  float v49; // [esp+64h] [ebp-34h]
  float v50; // [esp+68h] [ebp-30h]
  float v51; // [esp+68h] [ebp-30h]
  int n2622; // [esp+74h] [ebp-24h]
  float n2622a; // [esp+74h] [ebp-24h]
  float n2622_4; // [esp+78h] [ebp-20h]
  int v55; // [esp+7Ch] [ebp-1Ch]
  float v56; // [esp+80h] [ebp-18h]
  int n2622_8; // [esp+84h] [ebp-14h]
  int v58; // [esp+84h] [ebp-14h]
  unsigned __int16 *n2622_7; // [esp+88h] [ebp-10h]
  float n2622_3; // [esp+8Ch] [ebp-Ch]
  unsigned __int16 v61; // [esp+8Ch] [ebp-Ch]
  int v62; // [esp+90h] [ebp-8h]
  float v63; // [esp+90h] [ebp-8h]
  float v64; // [esp+90h] [ebp-8h]
  float v65; // [esp+90h] [ebp-8h]
  float v66; // [esp+94h] [ebp-4h]
  float v67; // [esp+94h] [ebp-4h]
  float n2622_2; // [esp+94h] [ebp-4h]
  float n2622_5; // [esp+94h] [ebp-4h]
  float v70; // [esp+94h] [ebp-4h]
  float v71; // [esp+94h] [ebp-4h]
  float v72; // [esp+94h] [ebp-4h]
  float v73; // [esp+94h] [ebp-4h]
  int v74; // [esp+94h] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 544);
  v43 = v2;
  LOBYTE(n2622_1) = byte_12A8480[*(unsigned __int8 *)(v2 + 24)];
  if ( ((unsigned __int8)n2622_1 & *(_BYTE *)(v2 + 179)) == 0 )
  {
    n2622_1 = *(_DWORD *)(v2 + 188);
    v4 = *(unsigned __int16 *)(n2622_1 + 10);
    n2622_7 = (unsigned __int16 *)n2622_1;
    v5 = n2622_1 + 16;
    LOWORD(n2622_1) = *(_WORD *)(n2622_1 + 8);
    v62 = *(_DWORD *)(a2 + 32) + (v4 << 8);
    if ( (_WORD)n2622_1 )
    {
      n2622_1 = (int)*(float *)(v2 + 48);
      n2622_8 = n2622_1;
      n2622 = n2622_1;
      if ( n2622_1 > 0 )
      {
        n2622_1 = (int)*(float *)(v2 + 76);
        v58 = n2622_8 - n2622_1;
        if ( v58 > 0 )
        {
          v56 = *(float *)(v2 + 52) * 0.00390625;
          if ( v56 <= 0.0 )
          {
            v56 = 0.0;
          }
          else
          {
            v6 = *(float *)(v5 + 16 * ((unsigned __int16)(n2622_7[3] - n2622_7[4] + 1) % (int)n2622_7[2]) + 12);
            v66 = v56 * *(float *)(v2 + 48);
            if ( v66 > v6 )
              v56 = v6 / *(float *)(v2 + 48);
          }
          *(_DWORD *)(a1 + 328) = *(_DWORD *)(v2 + 228);
          v67 = (*(float *)(v62 + 60) - *(float *)(v2 + 60)) / *(float *)(v2 + 48);
          v7 = v67;
          *(float *)(a1 + 324) = v67;
          n2622_2 = (float)n2622_1;
          n2622_3 = n2622_2;
          *(float *)(a1 + 320) = *(float *)(v62 + 60) - v7 * n2622_2;
          v39 = (float)*(unsigned __int8 *)(v62 + 200);
          v40 = (float)*(unsigned __int8 *)(v62 + 201);
          v41 = (float)*(unsigned __int8 *)(v62 + 202);
          v42 = (float)*(unsigned __int8 *)(v62 + 203);
          v32 = (float)*(unsigned __int8 *)(v2 + 200);
          v33 = (float)*(unsigned __int8 *)(v2 + 201);
          v34 = (float)*(unsigned __int8 *)(v2 + 202);
          v35 = (float)*(unsigned __int8 *)(v2 + 203);
          n2622_5 = (float)n2622;
          n2622_6 = n2622_5;
          v70 = (v32 - v39) / n2622_5;
          v9 = v70;
          *(float *)(a1 + 352) = v70;
          v71 = (v33 - v40) / n2622_6;
          v10 = v71;
          *(float *)(a1 + 356) = v71;
          v72 = (v34 - v41) / n2622_6;
          v11 = v72;
          *(float *)(a1 + 360) = v72;
          v73 = (v35 - v42) / n2622_6;
          *(float *)(a1 + 364) = v73;
          *(float *)(a1 + 336) = v9 * n2622_3 + v39;
          *(float *)(a1 + 340) = v10 * n2622_3 + v40;
          *(float *)(a1 + 344) = v41 + v11 * n2622_3;
          *(float *)(a1 + 348) = v42 + n2622_3 * v73;
          v31 = sub_801E20((_DWORD *)a1, (unsigned __int16 *)v2);
          sub_7E7F20(a1 + 64, v31);
          n2622_9 = n2622_7;
          n2622_4 = 0.0;
          *(_WORD *)(a1 + 2) = 128;
          *(_DWORD *)(a1 + 16) = a1 + 128;
          *(_DWORD *)(a1 + 8) = 0;
          *(_DWORD *)(a1 + 12) = *(_DWORD *)(v2 + 196);
          *(_BYTE *)(a1 + 24) = 0;
          v13 = n2622_7[3];
          v14 = 0;
          v74 = *(_DWORD *)(a2 + 84);
          v61 = v13;
          v55 = 0;
          while ( 1 )
          {
            v15 = v13 - 1;
            v16 = (float *)&n2622_7[8 * ((unsigned __int16)(v13 - 1) % (int)n2622_9[2]) + 8];
            if ( v16[3] < (double)n2622_4 )
              break;
LABEL_14:
            v19 = (float *)&n2622_7[8 * (v61 % (int)n2622_7[2]) + 8];
            v36 = *v19;
            v37 = v19[1];
            v38 = v19[2];
            v46 = *v16 - v36;
            v48 = v16[1] - v37;
            v50 = v16[2] - v38;
            v63 = sqrt(v46 * v46 + v48 * v48 + v50 * v50);
            n2622a = n2622_4 - v19[3];
            v20 = v63;
            if ( 0.0 == v63 )
            {
              v51 = 0.0;
              v49 = 0.0;
              v47 = 0.0;
            }
            else
            {
              v47 = v46 * n2622a / v20;
              v49 = v48 * n2622a / v20;
              v51 = n2622a * v50 / v20;
            }
            *(float *)(a1 + 240) = v47 + v36;
            *(float *)(a1 + 244) = v49 + v37;
            *(float *)(a1 + 248) = v51 + v38;
            v64 = *(float *)(a1 + 320) * 0.000244140625;
            sub_7EA610((void *)(a1 + 256), v64);
            sub_7E78B0(a1 + 304, v31, a1 + 240);
            sub_7E7F20(a1 + 128, a1 + 256);
            v21 = v43;
            if ( *(_WORD *)(v43 + 198) )
            {
              *(_DWORD *)(a1 + 28) = a1 + 256;
              v65 = (float)*(__int16 *)(v43 + 198);
              *(float *)(a1 + 312) = v65 * 0.0625 + *(float *)(a1 + 312);
            }
            else
            {
              *(_DWORD *)(a1 + 28) = 0;
            }
            *(_DWORD *)(a1 + 20) = v74;
            v44 = *(_DWORD *)(*(_DWORD *)(v43 + 224)
                            + 4 * ((*(_DWORD *)(a1 + 328) >> 8) % (unsigned int)*(unsigned __int16 *)(v43 + 232)));
            *(_BYTE *)(a1 + 4) = (int)*(float *)(a1 + 336);
            *(_BYTE *)(a1 + 5) = (int)*(float *)(a1 + 340);
            *(_BYTE *)(a1 + 6) = (int)*(float *)(a1 + 344);
            *(_BYTE *)(a1 + 7) = (int)*(float *)(a1 + 348);
            *(float *)(a1 + 336) = *(float *)(a1 + 352) + *(float *)(a1 + 336);
            *(float *)(a1 + 340) = *(float *)(a1 + 340) + *(float *)(a1 + 356);
            *(float *)(a1 + 344) = *(float *)(a1 + 344) + *(float *)(a1 + 360);
            *(float *)(a1 + 348) = *(float *)(a1 + 364) + *(float *)(a1 + 348);
            if ( !unk_12FB790 )
            {
              HIDWORD(v30) = (v55 >> 31) + v43;
              LODWORD(v30) = v55;
              v45 = HIDWORD(v30);
              if ( sub_645580(v30) )
              {
                sub_71C190(v55, v45, v44, a1);
                FFX_MagicHost_CommitDrawableResources(__SPAIR64__(v45, v55));
              }
              else
              {
                if ( *(_BYTE *)(v44 + 15) == 3 )
                  v22 = *(unsigned __int8 *)(v44 + 28);
                else
                  v22 = *(unsigned __int8 *)(*(_DWORD *)(v44 + 4) + v44 + 4);
                v23 = FFX_MagicHost_ClassifyPppOpcodeByte(v22);
                sub_7115E0(__SPAIR64__(v45, v55), v44, a1, v23);
                if ( !v55 && unk_113335C )
                {
                  v24 = 16 * unk_12F40D4;
                  v25 = unk_12F40D4 + 1;
                  *(_DWORD *)((char *)&unk_2332EC0 + v24) = 0;
                  *(_DWORD *)((char *)&unk_2332EC4 + v24) = v43;
                  *(_DWORD *)((char *)&unk_2332EC8 + v24) = v58;
                  unk_12F40D4 = v25;
                }
              }
            }
            v26 = (int)*(float *)(v43 + 56);
            *(float *)(a1 + 320) = *(float *)(a1 + 320) - *(float *)(a1 + 324);
            *(_DWORD *)(a1 + 328) += -2 * v26;
            n2622_4 = n2622_4 + v56;
            n2622_9 = n2622_7;
            v27 = ++v55 < v58;
            v13 = v61;
            if ( !v27 )
              goto LABEL_32;
          }
          v17 = n2622_7[4];
          while ( 1 )
          {
            v18 = v15;
            ++v14;
            v61 = v15;
            if ( (unsigned __int16)v14 >= v17 )
              break;
            --v15;
            v17 = n2622_7[4];
            v16 = (float *)&n2622_7[8 * ((unsigned __int16)(v18 - 1) % (int)n2622_7[2]) + 8];
            if ( v16[3] >= (double)n2622_4 )
              goto LABEL_14;
          }
          v21 = v43;
LABEL_32:
          v28 = (*(_WORD *)(v21 + 192) & 0x4000) == 0;
          *(_WORD *)(v21 + 192) &= 0x4000u;
          if ( v28 )
            *(_DWORD *)(v21 + 228) += 512;
          *(_DWORD *)(a2 + 84) = v74;
          LOBYTE(n2622_1) = a2;
        }
      }
    }
  }
  return n2622_1;
}

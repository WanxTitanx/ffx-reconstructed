// Function: sub_813D80
// Address: 0x813d80
int __cdecl sub_813D80(__int64 n2622, __int16 *a2, int a3, unsigned int a4, unsigned int a5)
{
  int result; // eax
  int v6; // esi
  __int16 v7; // di
  int v9; // edx
  _DWORD *v10; // ecx
  __int16 *v11; // edx
  float *v12; // esi
  _WORD *v13; // edi
  int v14; // eax
  int v15; // ebx
  float *v16; // ecx
  float *v17; // edx
  double v18; // st6
  double v19; // st7
  double v20; // st7
  __int16 v21; // dx
  int v22; // ecx
  float *v23; // [esp+4h] [ebp-50h]
  float v24; // [esp+8h] [ebp-4Ch]
  int v25; // [esp+Ch] [ebp-48h]
  int v26; // [esp+10h] [ebp-44h]
  int v27; // [esp+14h] [ebp-40h]
  int v28; // [esp+18h] [ebp-3Ch]
  int v29; // [esp+1Ch] [ebp-38h]
  _DWORD *v30; // [esp+20h] [ebp-34h]
  float *v31; // [esp+24h] [ebp-30h]
  float v32; // [esp+24h] [ebp-30h]
  float v33; // [esp+24h] [ebp-30h]
  float v34; // [esp+24h] [ebp-30h]
  int v35; // [esp+24h] [ebp-30h]
  float v36; // [esp+24h] [ebp-30h]
  int v37; // [esp+28h] [ebp-2Ch]
  signed int v38; // [esp+2Ch] [ebp-28h]
  int v39; // [esp+30h] [ebp-24h]
  int v40; // [esp+34h] [ebp-20h]
  int v41; // [esp+38h] [ebp-1Ch]
  int v42; // [esp+38h] [ebp-1Ch]
  float v43; // [esp+3Ch] [ebp-18h]
  float v44; // [esp+40h] [ebp-14h]
  float v45; // [esp+44h] [ebp-10h]
  float v46; // [esp+48h] [ebp-Ch]
  float v47; // [esp+4Ch] [ebp-8h]
  float v48; // [esp+50h] [ebp-4h]
  signed int v49; // [esp+70h] [ebp+1Ch]

  v48 = 3.4028235e38;
  v47 = 3.4028235e38;
  v46 = 3.4028235e38;
  v45 = -3.4028235e38;
  v44 = -3.4028235e38;
  v43 = -3.4028235e38;
  result = sub_645580(n2622);
  v6 = result;
  v23 = (float *)result;
  if ( result )
  {
    result = (int)a2;
    v7 = a2[4];
    if ( v7 )
    {
      v40 = (unsigned __int8)a5 << 16;
      v39 = (a5 & 0xFF00) << 8;
      v49 = (unsigned int)&unk_FF0000 & (a5 >> 8);
      v41 = a2[2] * a2[3];
      v38 = (unsigned int)&unk_FF0000 & a5;
      v28 = (v40 - ((unsigned __int8)a4 << 16)) / v41;
      v27 = (int)(v39 - ((a4 & 0xFF00) << 8)) / v41;
      v26 = (int)(((unsigned int)&unk_FF0000 & a5) - ((unsigned int)&unk_FF0000 & a4)) / v41;
      v25 = (int)(v49 - ((unsigned int)&unk_FF0000 & (a4 >> 8))) / v41;
      result = a3 * v41;
      v9 = a3 * v41 / 256;
      if ( v9 > -v41 && v9 < v41 )
      {
        if ( v9 >= 0 )
        {
          result = v7 - v9;
          v37 = result;
          if ( result <= 1 )
            return result;
          v42 = a2[5];
        }
        else
        {
          result = v9 + v7;
          v37 = result;
          if ( result <= 1 )
            return result;
          v42 = a2[5] - v9;
        }
        result = sub_63FF60(v6, 0, 2 * result, 6 * result - 6);
        if ( result )
        {
          v10 = *(_DWORD **)(v6 + 148);
          v11 = a2;
          v12 = (float *)v10[3];
          v13 = (_WORD *)v10[7];
          v31 = (float *)v10[5];
          v14 = v37;
          v29 = a2[2] * a2[3];
          v15 = 0;
          v30 = v10;
          if ( v37 > 0 )
          {
            do
            {
              v16 = (float *)(32 * (v42 % v29) + unknown_libname_741(*((_DWORD *)v11 + 7)));
              *v31 = 0.0;
              v31[1] = 0.0;
              v31[2] = 0.0;
              v17 = v31 + 8;
              v31[3] = 0.0;
              v32 = (float)(v40 >> 16);
              *(v17 - 4) = v32 / 255.0;
              v33 = (float)(v39 >> 16);
              *(v17 - 3) = v33 / 255.0;
              v34 = (float)(v38 >> 16);
              v18 = v34;
              v35 = v49 >> 16;
              v40 -= v28;
              v39 -= v27;
              v38 -= v26;
              v49 -= v25;
              *(v17 - 2) = v18 / 255.0;
              v36 = (float)v35;
              v19 = v36 / 255.0;
              v31 = v17;
              *(v17 - 1) = v19;
              *v12 = *v16;
              v12[1] = v16[1];
              v12[2] = v16[2];
              v12[3] = v16[4];
              v12[4] = v16[5];
              v24 = v16[6];
              v20 = v24;
              v12[5] = v24;
              if ( *v12 <= (double)v48 )
                v48 = *v12;
              if ( *v12 >= (double)v45 )
                v45 = *v12;
              if ( v12[1] <= (double)v47 )
                v47 = v12[1];
              if ( v12[1] >= (double)v44 )
                v44 = v12[1];
              if ( v12[2] <= (double)v46 )
                v46 = v12[2];
              if ( v12[2] >= (double)v43 )
                v43 = v12[2];
              if ( v12[4] <= (double)v48 )
                v48 = v12[4];
              if ( v12[4] >= (double)v45 )
                v45 = v12[4];
              if ( v47 >= v20 )
                v47 = v24;
              if ( v44 <= v20 )
                v44 = v24;
              v12 += 6;
              if ( *v12 <= (double)v46 )
                v46 = *v12;
              if ( *v12 >= (double)v43 )
                v43 = *v12;
              if ( v15 > 0 )
              {
                v21 = 2 * v15 - 2;
                v13[1] = 2 * v15 - 1;
                *v13 = v21;
                v13[2] = 2 * v15 + 1;
                v13[3] = v21;
                v13[4] = 2 * v15 + 1;
                v13[5] = 2 * v15;
                v13 += 6;
              }
              v14 = v37;
              ++v42;
              v11 = a2;
              ++v15;
            }
            while ( v15 < v37 );
            v10 = v30;
          }
          v10[1] = 2 * v14;
          v10[2] = 2 * (3 * v14 - 3);
          v22 = 7 * sub_640100();
          v30[v22 + 12] = v30[2];
          v30[v22 + 11] = v30[1];
          v23[44] = 0.0;
          memset(v23, 0, 0x40u);
          *v23 = 1.0;
          v23[5] = 1.0;
          v23[10] = 1.0;
          v23[15] = 1.0;
          v23[38] = v48;
          v23[39] = v47;
          v23[40] = v46;
          v23[41] = v45;
          v23[42] = v44;
          v23[43] = v43;
          return FFX_MagicHost_CommitDrawableResources(n2622);
        }
      }
    }
  }
  return result;
}

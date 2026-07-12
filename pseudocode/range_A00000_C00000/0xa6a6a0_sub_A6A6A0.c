// Function: sub_A6A6A0
// Address: 0xa6a6a0
// Size: 0x601
// Prototype: int __cdecl(int, int, int, float, int)

int __cdecl sub_A6A6A0(int a1, int a2, unsigned int *a3, float a4, int a5)
{
  int v5; // edi
  int n437; // eax
  int v7; // eax
  int v8; // esi
  char *v9; // eax
  int v10; // eax
  bool v11; // zf
  char *v12; // ecx
  int v13; // esi
  int v14; // eax
  int v15; // ecx
  BOOL v16; // eax
  int v17; // eax
  int v18; // ecx
  double v19; // st7
  double v20; // st5
  double v21; // rt1
  double v22; // st4
  double v23; // st5
  double v24; // st5
  double v25; // st6
  double v26; // st6
  double v27; // st6
  __int64 v28; // rdi
  unsigned __int64 v29; // rdi
  int v30; // ecx
  char v31; // al
  int v32; // ebx
  int v33; // eax
  int v34; // esi
  int v35; // ecx
  int v36; // edx
  float v37; // eax
  int v38; // esi
  char n7; // al
  int v40; // [esp+8h] [ebp-278h] BYREF
  int v41; // [esp+Ch] [ebp-274h]
  int v42; // [esp+10h] [ebp-270h] BYREF
  double v43; // [esp+14h] [ebp-26Ch]
  float v44; // [esp+1Ch] [ebp-264h]
  float v45; // [esp+20h] [ebp-260h]
  float v46; // [esp+24h] [ebp-25Ch]
  float v47; // [esp+28h] [ebp-258h]
  int v48; // [esp+2Ch] [ebp-254h]
  float v49; // [esp+30h] [ebp-250h]
  float v50; // [esp+34h] [ebp-24Ch]
  float v51; // [esp+38h] [ebp-248h]
  float v52; // [esp+3Ch] [ebp-244h]
  int v53; // [esp+40h] [ebp-240h]
  float v54; // [esp+44h] [ebp-23Ch]
  float v55; // [esp+48h] [ebp-238h]
  float v56; // [esp+4Ch] [ebp-234h]
  float v57; // [esp+50h] [ebp-230h]
  int v58; // [esp+54h] [ebp-22Ch] BYREF
  int v59; // [esp+58h] [ebp-228h]
  int v60; // [esp+5Ch] [ebp-224h]
  char *v61; // [esp+60h] [ebp-220h]
  int v62; // [esp+64h] [ebp-21Ch]
  double v63; // [esp+68h] [ebp-218h]
  double v64; // [esp+70h] [ebp-210h]
  int v65; // [esp+78h] [ebp-208h]
  char v66[256]; // [esp+7Ch] [ebp-204h] BYREF
  char Buffer[256]; // [esp+17Ch] [ebp-104h] BYREF

  v5 = a1;
  v65 = a2;
  v53 = a1;
  HIDWORD(v63) = a5;
  if ( FFX_Btl_GetCurrentBattleFormationId() == 438 || (n437 = FFX_Btl_GetCurrentBattleFormationId(), n437 == 437) )
  {
    v7 = sub_7E6910(6144);
    *(_DWORD *)a1 |= 4u;
    v8 = v7;
    v9 = (char *)sub_A69940(a1, v65, v7);
    v65 = v9[28];
    v61 = v9;
    *(float *)(v8 + 880) = (float)v65;
    v65 = v9[29];
    *(float *)(v8 + 884) = (float)v65;
    v65 = v9[30];
    *(float *)(v8 + 888) = (float)v65;
    v65 = v9[31];
    *(float *)(v8 + 892) = (float)v65;
    *(_DWORD *)(v8 + 1024) = *(_DWORD *)(v8 + 912) + 16 * *(__int16 *)(a1 + 20);
    v65 = (int)a4;
    if ( !dword_22FB3C8[HIDWORD(v63)] )
      dword_22FB3C8[HIDWORD(v63)] = sub_687190(16 * *(__int16 *)(a1 + 20), (void *)0x10);
    sub_A6CFB0(
      a1,
      v61,
      v8,
      dword_22FB3C8[HIDWORD(v63)],
      v65,
      16 * *((unsigned __int8 *)a3 + 10),
      16 * *((unsigned __int8 *)a3 + 11));
    v10 = a1 + *(_DWORD *)(a1 + 4);
    v11 = *(_BYTE *)(v10 + 1) == 16;
    v12 = (char *)(v10 + 1);
    v62 = v10;
    if ( v11 )
    {
      v13 = HIDWORD(v63) + 100;
      v60 = HIDWORD(v63) + 100;
      v59 = ((HIDWORD(v63) + 100) >> 31) + 437;
      v14 = sub_645580(HIDWORD(v63) + 100 + 0x1B500000000LL);
      v15 = (unsigned __int8)v61[77];
      v16 = v14 == 0;
      v11 = !v16;
      v65 = v16;
      v48 = *((_DWORD *)v61 + 14);
      v17 = HIDWORD(v63);
      HIDWORD(v63) = v15;
      v41 = dword_22FB3C8[v17];
      v43 = (double)v15;
      v18 = *(__int16 *)(a1 + 16);
      v19 = v43 / 255.0;
      HIDWORD(v63) = (unsigned __int8)v61[28];
      HIDWORD(v43) = v18;
      *((float *)&v64 + 1) = v19;
      v63 = (double)SHIDWORD(v63);
      v20 = *((float *)&v64 + 1);
      HIDWORD(v64) = (unsigned __int8)v61[29];
      v21 = v20;
      v44 = v63 * v20;
      v22 = (double)SHIDWORD(v64);
      v64 = v22;
      HIDWORD(v64) = (unsigned __int8)v61[30];
      v45 = v20 * v22;
      v64 = (double)SHIDWORD(v64);
      v23 = v64 * v20;
      HIDWORD(v64) = (unsigned __int8)v61[31];
      v46 = v23;
      v24 = (double)SHIDWORD(v64);
      v64 = v24;
      HIDWORD(v64) = (unsigned __int8)v61[24];
      v47 = v21 * v24;
      v64 = (double)SHIDWORD(v64);
      v25 = v64 / 255.0;
      HIDWORD(v64) = (unsigned __int8)v61[25];
      v49 = v25;
      v64 = (double)SHIDWORD(v64);
      v26 = v64 / 255.0;
      HIDWORD(v64) = (unsigned __int8)v61[26];
      v50 = v26;
      v64 = (double)SHIDWORD(v64);
      v27 = v64 / 255.0;
      HIDWORD(v64) = (unsigned __int8)v61[27];
      v51 = v27;
      v64 = (double)SHIDWORD(v64);
      v62 = *(unsigned __int8 *)(v62 + 7);
      v52 = v64 / 255.0;
      v56 = 256.0;
      v55 = 256.0;
      v54 = 256.0;
      v57 = (float)v62;
      if ( v11 )
      {
        v32 = v59;
      }
      else
      {
        HIDWORD(v28) = a3[1];
        v58 = 3 * v18;
        v42 = 3 * v18;
        LODWORD(v28) = 0;
        v29 = *a3 + v28;
        v40 = 1;
        sprintf(
          Buffer,
          "%d_%d_0_0_%d_%d.dds.phyre",
          (unsigned __int16)v29 & 0x3FFF,
          (unsigned __int8)(v29 >> 20) & 0x3F,
          1 << ((v29 >> 26) & 0xF),
          1 << ((v29 >> 30) & 0xF));
        if ( sub_6455B0(Buffer, v66, 0, 0, 0, 0) )
        {
          v30 = 0;
          do
          {
            v31 = v66[v30];
            Buffer[v30++] = v31;
          }
          while ( v31 );
        }
        v32 = v59;
        v13 = v60;
        FFX_MagicCoreOp_CreateModelTexturedVtxFormat(__SPAIR64__(v59, v60), 32778);
        FFX_Ps3Data_BuildTextureSlotRecord_LoadTime(__SPAIR64__(v59, v60), 1, (int)&v58, &v42, Buffer, (int)&v40);
        v5 = v53;
      }
      v33 = sub_645580(__SPAIR64__(v32, v13));
      v34 = v33;
      if ( v33 )
      {
        *(_DWORD *)(*(_DWORD *)(v33 + 148) + 36) = 1;
        n437 = sub_63FF60(v33, 0, *(_DWORD *)(*(_DWORD *)(v33 + 148) + 4), *(_DWORD *)(*(_DWORD *)(v33 + 148) + 8));
        if ( !n437 )
          return n437;
        if ( sub_63FF20(v35) )
        {
          v36 = FFX_MagicHost_AllocPppDrawRecord(SHIDWORD(v43));
          v37 = v57;
          *(float *)(v36 + 32) = v54;
          *(float *)(v36 + 36) = v55;
          *(float *)(v36 + 40) = v56;
          *(float *)(v36 + 44) = v37;
          *(float *)(v36 + 48) = v49;
          *(float *)(v36 + 52) = v50;
          *(float *)(v36 + 56) = v51;
          *(float *)(v36 + 60) = v52;
          *(float *)(v36 + 64) = v44;
          *(float *)(v36 + 68) = v45;
          *(float *)(v36 + 72) = v46;
          *(float *)(v36 + 76) = v47;
          *(_BYTE *)v36 = 6;
          *(_DWORD *)(v36 + 20) = v5;
          *(_DWORD *)(v36 + 16) = *(_DWORD *)(v34 + 148);
          *(_DWORD *)(v36 + 24) = v48;
          *(_DWORD *)(v36 + 28) = v41;
        }
        sub_6ED700(v34, &src__0, *((_DWORD *)v61 + 8));
        v38 = v60;
        sub_6458C0(v60, v32, 1);
        if ( v65 )
          sub_645930(__SPAIR64__(v32, v38));
        else
          sub_6457B0(v38, v32);
      }
    }
    else
    {
      while ( 1 )
      {
        while ( 1 )
        {
          n7 = *v12;
          if ( *v12 != 3 && n7 != 7 )
            break;
          *(_DWORD *)(v8 + 496) = 32769;
          *(_DWORD *)(v8 + 504) = 306258962;
          *(_DWORD *)(v8 + 288) = *a3;
          v12 += 16;
        }
        if ( n7 != 16 )
          break;
        *(_DWORD *)(v8 + 496) = 32769;
        *(_DWORD *)(v8 + 504) = 306258962;
        *(_DWORD *)(v8 + 288) = *a3;
        v12 += 32;
      }
    }
    while ( (word_23056E8 & 0x100) != 0 )
      ;
    return sub_7E6970(6144);
  }
  return n437;
}


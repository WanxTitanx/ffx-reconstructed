// Function: FFX_Magic_RunRuntimeRootPhase_structural
// Address: 0x80cd60
// [Jarvis naming goal 2026-06-17] Structural magic runtime root interpreter/phase body. Called by phase0/1/2 wrappers and dispatches through the core opcode table; name is structural, not original symbol proof.
int __cdecl FFX_Magic_RunRuntimeRootPhase_structural(unsigned __int16 a1, unsigned __int8 n2)
{
  int v2; // esi
  _DWORD *v3; // ebx
  __int16 *v4; // edi
  __int16 *v5; // ecx
  __int16 v6; // ax
  int v7; // ebx
  __int16 v8; // cx
  unsigned __int8 v9; // dl
  int v10; // ecx
  char v11; // al
  __int16 v12; // cx
  int v13; // edx
  int (__cdecl *v14)(int, int); // eax
  char v15; // cl
  float v16; // eax
  unsigned __int8 n0xC; // al
  int result; // eax
  _DWORD *v19; // [esp+Ch] [ebp-28h]

  if ( a1 == 1 )
    unk_113335C = 1;
  v2 = sub_7E6910(1024);
  unk_C8F534 = unk_113FCBC;
  n3_11 = n3_12;
  unk_C8F53C = unk_113FCC4;
  unk_C8F540 = unk_113FCC8;
  unk_C8F544 = unk_113FCCC;
  unk_C8F548 = unk_113FCD0;
  unk_C8F54C = unk_113FCD4;
  unk_C8F550 = unk_113FCD8;
  unk_C8F554 = unk_113FCDC;
  v3 = (_DWORD *)dword_12A4080[a1];
  MEMORY[0xC8F558] = unk_113FCE0;
  unk_C8F55C = unk_113FCE4;
  unk_C8F560 = unk_113FCE8;
  unk_C8F564 = unk_113FCEC;
  unk_C8F52C = unk_113FCB4;
  unk_C8F530 = unk_113FCB8;
  unk_12A12BC = v2;
  *(_DWORD *)(v2 + 640) = unk_113FCB0;
  *(_DWORD *)(v2 + 644) = unk_C8F52C;
  *(_DWORD *)(v2 + 648) = unk_C8F530;
  *(_DWORD *)(v2 + 652) = unk_C8F534;
  *(_DWORD *)(v2 + 656) = n3_11;
  *(_DWORD *)(v2 + 660) = unk_C8F53C;
  *(_DWORD *)(v2 + 664) = unk_C8F540;
  *(_DWORD *)(v2 + 668) = unk_C8F544;
  *(_DWORD *)(v2 + 672) = unk_C8F548;
  *(_DWORD *)(v2 + 676) = unk_C8F54C;
  *(_DWORD *)(v2 + 680) = unk_C8F550;
  *(_DWORD *)(v2 + 684) = unk_C8F554;
  *(_DWORD *)(v2 + 688) = MEMORY[0xC8F558];
  *(_DWORD *)(v2 + 692) = unk_C8F55C;
  *(_DWORD *)(v2 + 696) = unk_C8F560;
  *(_DWORD *)(v2 + 700) = unk_C8F564;
  unk_C8F52C = unk_113FCF4;
  unk_C8F530 = unk_113FCF8;
  unk_C8F534 = unk_113FCFC;
  n3_11 = n3_13;
  v19 = v3;
  n1065353216 = n1065353216_0;
  unk_C8F53C = unk_113FD04;
  unk_C8F540 = unk_113FD08;
  unk_C8F544 = unk_113FD0C;
  unk_C8F548 = unk_113FD10;
  unk_C8F54C = unk_113FD14;
  unk_C8F550 = unk_113FD18;
  unk_C8F554 = unk_113FD1C;
  MEMORY[0xC8F558] = unk_113FD20;
  unk_C8F55C = unk_113FD24;
  unk_C8F560 = unk_113FD28;
  unk_C8F564 = unk_113FD2C;
  *(_DWORD *)(v2 + 704) = n1065353216_0;
  *(_DWORD *)(v2 + 708) = unk_C8F52C;
  *(_DWORD *)(v2 + 712) = unk_C8F530;
  *(_DWORD *)(v2 + 716) = unk_C8F534;
  *(_DWORD *)(v2 + 720) = n3_11;
  *(_DWORD *)(v2 + 724) = unk_C8F53C;
  *(_DWORD *)(v2 + 728) = unk_C8F540;
  *(_DWORD *)(v2 + 732) = unk_C8F544;
  *(_DWORD *)(v2 + 736) = unk_C8F548;
  *(_DWORD *)(v2 + 740) = unk_C8F54C;
  *(_DWORD *)(v2 + 744) = unk_C8F550;
  *(_DWORD *)(v2 + 748) = unk_C8F554;
  *(_DWORD *)(v2 + 752) = MEMORY[0xC8F558];
  *(_DWORD *)(v2 + 756) = unk_C8F55C;
  *(_DWORD *)(v2 + 760) = unk_C8F560;
  *(_DWORD *)(v2 + 764) = unk_C8F564;
  n1065353216 = *v3;
  unk_C8F52C = v3[1];
  unk_C8F530 = v3[2];
  unk_C8F534 = v3[3];
  n3_11 = v3[4];
  unk_C8F53C = v3[5];
  unk_C8F540 = v3[6];
  unk_C8F544 = v3[7];
  unk_C8F548 = v3[8];
  unk_C8F54C = v3[9];
  unk_C8F550 = v3[10];
  unk_C8F554 = v3[11];
  MEMORY[0xC8F558] = v3[12];
  unk_C8F55C = v3[13];
  unk_C8F560 = v3[14];
  unk_C8F564 = v3[15];
  *(_DWORD *)(v2 + 768) = n1065353216;
  *(_DWORD *)(v2 + 772) = unk_C8F52C;
  *(_DWORD *)(v2 + 776) = unk_C8F530;
  *(_DWORD *)(v2 + 780) = unk_C8F534;
  *(_DWORD *)(v2 + 784) = n3_11;
  *(_DWORD *)(v2 + 788) = unk_C8F53C;
  *(_DWORD *)(v2 + 792) = unk_C8F540;
  *(_DWORD *)(v2 + 796) = unk_C8F544;
  *(_DWORD *)(v2 + 800) = unk_C8F548;
  *(_DWORD *)(v2 + 804) = unk_C8F54C;
  *(_DWORD *)(v2 + 808) = unk_C8F550;
  *(_DWORD *)(v2 + 812) = unk_C8F554;
  *(_DWORD *)(v2 + 816) = MEMORY[0xC8F558];
  *(_DWORD *)(v2 + 820) = unk_C8F55C;
  *(_DWORD *)(v2 + 824) = unk_C8F560;
  *(_DWORD *)(v2 + 828) = unk_C8F564;
  n1065353216 = v3[16];
  unk_C8F52C = v3[17];
  unk_C8F530 = v3[18];
  unk_C8F534 = v3[19];
  n3_11 = v3[20];
  unk_C8F53C = v3[21];
  unk_C8F540 = v3[22];
  unk_C8F544 = v3[23];
  unk_C8F548 = v3[24];
  unk_C8F54C = v3[25];
  unk_C8F550 = v3[26];
  unk_C8F554 = v3[27];
  MEMORY[0xC8F558] = v3[28];
  unk_C8F55C = v3[29];
  unk_C8F560 = v3[30];
  unk_C8F564 = v3[31];
  *(_DWORD *)(v2 + 832) = n1065353216;
  *(_DWORD *)(v2 + 836) = unk_C8F52C;
  *(_DWORD *)(v2 + 840) = unk_C8F530;
  *(_DWORD *)(v2 + 844) = unk_C8F534;
  *(_DWORD *)(v2 + 848) = n3_11;
  *(_DWORD *)(v2 + 852) = unk_C8F53C;
  *(_DWORD *)(v2 + 856) = unk_C8F540;
  *(_DWORD *)(v2 + 860) = unk_C8F544;
  *(_DWORD *)(v2 + 864) = unk_C8F548;
  *(_DWORD *)(v2 + 868) = unk_C8F54C;
  *(_DWORD *)(v2 + 872) = unk_C8F550;
  *(_DWORD *)(v2 + 876) = unk_C8F554;
  *(_DWORD *)(v2 + 880) = MEMORY[0xC8F558];
  *(_DWORD *)(v2 + 884) = unk_C8F55C;
  *(_DWORD *)(v2 + 888) = unk_C8F560;
  *(_DWORD *)(v2 + 892) = unk_C8F564;
  n1065353216 = v3[32];
  unk_C8F52C = v3[33];
  unk_C8F530 = v3[34];
  unk_C8F534 = v3[35];
  n3_11 = v3[36];
  unk_C8F53C = v3[37];
  unk_C8F540 = v3[38];
  unk_C8F544 = v3[39];
  unk_C8F548 = v3[40];
  unk_C8F54C = v3[41];
  unk_C8F550 = v3[42];
  unk_C8F554 = v3[43];
  MEMORY[0xC8F558] = v3[44];
  unk_C8F55C = v3[45];
  unk_C8F560 = v3[46];
  unk_C8F564 = v3[47];
  *(_DWORD *)(v2 + 896) = n1065353216;
  *(_DWORD *)(v2 + 900) = unk_C8F52C;
  *(_DWORD *)(v2 + 904) = unk_C8F530;
  *(_DWORD *)(v2 + 908) = unk_C8F534;
  *(_DWORD *)(v2 + 912) = n3_11;
  *(_DWORD *)(v2 + 916) = unk_C8F53C;
  *(_DWORD *)(v2 + 920) = unk_C8F540;
  *(_DWORD *)(v2 + 924) = unk_C8F544;
  *(_DWORD *)(v2 + 928) = unk_C8F548;
  *(_DWORD *)(v2 + 932) = unk_C8F54C;
  *(_DWORD *)(v2 + 936) = unk_C8F550;
  *(_DWORD *)(v2 + 940) = unk_C8F554;
  *(_DWORD *)(v2 + 944) = MEMORY[0xC8F558];
  *(_DWORD *)(v2 + 948) = unk_C8F55C;
  *(_DWORD *)(v2 + 952) = unk_C8F560;
  *(_DWORD *)(v2 + 956) = unk_C8F564;
  n1065353216 = v3[48];
  unk_C8F52C = v3[49];
  unk_C8F530 = v3[50];
  unk_C8F534 = v3[51];
  n3_11 = v3[52];
  unk_C8F53C = v3[53];
  unk_C8F540 = v3[54];
  unk_C8F544 = v3[55];
  unk_C8F548 = v3[56];
  unk_C8F54C = v3[57];
  unk_C8F550 = v3[58];
  unk_C8F554 = v3[59];
  MEMORY[0xC8F558] = v3[60];
  unk_C8F55C = v3[61];
  unk_C8F560 = v3[62];
  unk_C8F564 = v3[63];
  *(_DWORD *)(v2 + 960) = n1065353216;
  *(_DWORD *)(v2 + 964) = unk_C8F52C;
  *(_DWORD *)(v2 + 968) = unk_C8F530;
  *(_DWORD *)(v2 + 972) = unk_C8F534;
  *(_DWORD *)(v2 + 976) = n3_11;
  *(_DWORD *)(v2 + 980) = unk_C8F53C;
  *(_DWORD *)(v2 + 984) = unk_C8F540;
  *(_DWORD *)(v2 + 988) = unk_C8F544;
  *(_DWORD *)(v2 + 992) = unk_C8F548;
  *(_DWORD *)(v2 + 996) = unk_C8F54C;
  *(_DWORD *)(v2 + 1000) = unk_C8F550;
  *(_DWORD *)(v2 + 1004) = unk_C8F554;
  *(_DWORD *)(v2 + 1008) = MEMORY[0xC8F558];
  *(_DWORD *)(v2 + 1012) = unk_C8F55C;
  *(_DWORD *)(v2 + 1016) = unk_C8F560;
  *(_DWORD *)(v2 + 1020) = unk_C8F564;
  *(_DWORD *)(v2 + 528) = word_C8F508[0];
  *(_DWORD *)(v2 + 532) = *(_DWORD *)&word_C8F50C;
  *(_DWORD *)(v2 + 536) = *(_DWORD *)&word_C8F510;
  *(_DWORD *)(v2 + 540) = *(_DWORD *)&word_C8F514;
  *(_BYTE *)(v2 + 540) = n2;
  *(_DWORD *)(v2 + 548) = *(_DWORD *)(v2 + 4 * n2 + 784);
  if ( sub_780D80() )
    *(_BYTE *)(v2 + 542) = 1;
  v4 = (__int16 *)v3;
  while ( 1 )
  {
    v5 = *(__int16 **)(v2 + 548);
    v6 = v5[*(__int16 *)(v2 + 536)];
    if ( v6 == -1 )
      break;
LABEL_9:
    v7 = *(_DWORD *)(v2 + 800) + (v6 << 8);
    *(_WORD *)(v2 + 532) = v6;
    *(_DWORD *)(v2 + 544) = v7;
    *(_WORD *)(v2 + 534) = 0;
    do
    {
      if ( *(_BYTE *)(v2 + 543) && !*(_BYTE *)(v2 + 541) )
      {
LABEL_36:
        v15 = *(_BYTE *)(v7 + 178);
        n1065353216 = 1031798784;
        unk_C8F8D0[0] = *(float *)(v7 + 48);
        unk_C8F8D4 = *(float *)(v7 + 52);
        unk_C8F8D8 = *(float *)(v7 + 56);
        unk_C8F8DC[0] = *(float *)(v7 + 60);
        flt_C8F8E0 = *(float *)(v7 + 64);
        flt_C8F8E4 = *(float *)(v7 + 68);
        flt_C8F8E8 = *(float *)(v7 + 72);
        flt_C8F8EC = *(float *)(v7 + 76);
        unk_C8F934 = unk_C8F52C;
        unk_C8F938 = unk_C8F530;
        flt_C8F930 = 0.0625;
        unk_C8F93C = unk_C8F534;
        if ( (v15 & 2) == 0 )
        {
          n1065353216 = *(__int16 *)(v2 + 530);
          unk_C8F8F0[0] = *(float *)(v7 + 80);
          flt_C8F8F4 = *(float *)(v7 + 84);
          flt_C8F8F8 = *(float *)(v7 + 88);
          flt_C8F8FC = *(float *)(v7 + 92);
          if ( !n1065353216 )
          {
            flt_C8F900 = *(float *)(v7 + 96);
            flt_C8F904 = *(float *)(v7 + 100);
            flt_C8F908 = *(float *)(v7 + 104);
            flt_C8F90C = *(float *)(v7 + 108);
            flt_C8F910 = *(float *)(v7 + 112);
            flt_C8F914 = *(float *)(v7 + 116);
            flt_C8F918 = *(float *)(v7 + 120);
            flt_C8F91C = *(float *)(v7 + 124);
            unk_C8F920 = *(float *)(v7 + 128);
            unk_C8F924 = *(float *)(v7 + 132);
            unk_C8F928 = *(float *)(v7 + 136);
            v16 = *(float *)(v7 + 140);
            unk_C8F8F0[0] = unk_C8F8F0[0] + flt_C8F910;
            unk_C8F92C = v16;
            flt_C8F8F4 = flt_C8F8F4 + flt_C8F914;
            flt_C8F8F8 = flt_C8F8F8 + flt_C8F918;
            flt_C8F8FC = flt_C8F8FC + flt_C8F91C;
            flt_C8F900 = flt_C8F900 + unk_C8F920;
            flt_C8F904 = flt_C8F904 + unk_C8F924;
            flt_C8F908 = flt_C8F908 + unk_C8F928;
            flt_C8F90C = flt_C8F90C + v16;
            *(float *)(v7 + 80) = unk_C8F8F0[0];
            *(float *)(v7 + 84) = flt_C8F8F4;
            *(float *)(v7 + 88) = flt_C8F8F8;
            *(float *)(v7 + 92) = flt_C8F8FC;
            *(float *)(v7 + 96) = flt_C8F900;
            *(float *)(v7 + 100) = flt_C8F904;
            *(float *)(v7 + 104) = flt_C8F908;
            *(float *)(v7 + 108) = flt_C8F90C;
            unk_C8F8D0[0] = unk_C8F8D0[0] + unk_C8F8F0[0];
            unk_C8F8D4 = unk_C8F8D4 + flt_C8F8F4;
            unk_C8F8D8 = unk_C8F8D8 + flt_C8F8F8;
            unk_C8F8DC[0] = unk_C8F8DC[0] + flt_C8F8FC;
            flt_C8F8E0 = flt_C8F8E0 + flt_C8F900;
            flt_C8F8E4 = flt_C8F8E4 + flt_C8F904;
            flt_C8F8E8 = flt_C8F8E8 + flt_C8F908;
            flt_C8F8EC = flt_C8F8EC + flt_C8F90C;
            *(float *)(v7 + 48) = unk_C8F8D0[0];
            *(float *)(v7 + 52) = unk_C8F8D4;
            *(float *)(v7 + 56) = unk_C8F8D8;
            *(float *)(v7 + 60) = unk_C8F8DC[0];
            *(float *)(v7 + 64) = flt_C8F8E0;
            *(float *)(v7 + 68) = flt_C8F8E4;
            *(float *)(v7 + 72) = flt_C8F8E8;
            *(float *)(v7 + 76) = flt_C8F8EC;
          }
        }
        if ( (*(_BYTE *)(v7 + 178) & 4) == 0 )
        {
          flt_C8F8E0 = flt_C8F8E0 * flt_C8F930;
          flt_C8F8E4 = flt_C8F8E4 * flt_C8F930;
          flt_C8F8E8 = flt_C8F930 * flt_C8F8E8;
          flt_C8F8EC = flt_C8F930 * flt_C8F8EC;
          *(float *)(v7 + 144) = flt_C8F8E0;
          *(float *)(v7 + 148) = flt_C8F8E4;
          *(float *)(v7 + 152) = flt_C8F8E8;
          *(float *)(v7 + 156) = flt_C8F8EC;
          n0xC = *(_BYTE *)(v7 + 186);
          if ( n0xC )
          {
            if ( n0xC < 0xCu )
              g_FFX_MagicPostProcTable[n0xC](v2, (int)v4);
          }
        }
        goto LABEL_43;
      }
      v4 = (__int16 *)unknown_libname_741(*(_DWORD *)(v7 + 4 * *(__int16 *)(v2 + 534)));
      if ( !v4 )
        goto LABEL_34;
      if ( *(_BYTE *)(v2 + 541) )
      {
        v8 = *(_WORD *)(v2 + 534);
        v9 = *(_BYTE *)(v7 + 31);
        if ( ((unsigned __int8)(1 << v8) & v9) == 0 )
          goto LABEL_34;
        *(_BYTE *)(v7 + 31) = v9 & ~(1 << v8) & 0xF;
      }
      else if ( ((unsigned __int8)(1 << *(_BYTE *)(v2 + 534)) & *(_BYTE *)(v7 + 31)) != 0 )
      {
        goto LABEL_34;
      }
      v10 = *(__int16 *)(v2 + 534);
      v11 = *(_BYTE *)(v10 + v7 + 16);
      if ( v11 )
      {
        *(_BYTE *)(v10 + v7 + 16) = v11 - 1;
        goto LABEL_34;
      }
      while ( 1 )
      {
        if ( v4 )
          v12 = *v4;
        else
          v12 = 0;
        unk_12F40D0 = v4;
        *(_WORD *)(v2 + 538) = v12;
        if ( (v12 & 0x100) == 0 )
        {
          v14 = g_FFX_MagicOpcodeTable_core[(unsigned __int8)v12];
          if ( !v14 )
            goto LABEL_29;
          goto LABEL_26;
        }
        v13 = *(_DWORD *)(v19[20] + 124);
        if ( !v13 )
          break;
        v14 = *(int (__cdecl **)(int, int))(v13 + 4 * (unsigned __int8)v12);
LABEL_26:
        v4 = (__int16 *)((__int16 *(__cdecl *)(int))v14)(v2);
        if ( *(_BYTE *)(v2 + 528) )
          goto LABEL_29;
      }
      nullsub_34();
LABEL_29:
      *(_BYTE *)(*(__int16 *)(v2 + 534) + v7 + 16) += *(_BYTE *)(v2 + 528) - 1;
      *(_BYTE *)(v2 + 528) = 0;
      if ( v4 && *(_BYTE *)(v2 + 541) )
        *(_BYTE *)(v7 + 31) |= 1 << *(_BYTE *)(v2 + 534);
      *(_DWORD *)(v7 + 4 * *(__int16 *)(v2 + 534)) = unknown_libname_742(v4);
LABEL_34:
      ++*(_WORD *)(v2 + 534);
    }
    while ( *(__int16 *)(v2 + 534) < 4 );
    if ( !*(_BYTE *)(v2 + 541) )
      goto LABEL_36;
LABEL_43:
    ++*(_WORD *)(v2 + 536);
  }
  while ( !*(_BYTE *)(v2 + 541) )
  {
    *(_WORD *)(v2 + 536) = 0;
    *(_BYTE *)(v2 + 541) = -1;
    v6 = *v5;
    if ( *v5 != -1 )
      goto LABEL_9;
  }
  n1065353216 = *(_DWORD *)(v2 + 768);
  unk_C8F52C = *(_DWORD *)(v2 + 772);
  unk_C8F530 = *(_DWORD *)(v2 + 776);
  unk_C8F534 = *(_DWORD *)(v2 + 780);
  n3_11 = *(_DWORD *)(v2 + 784);
  unk_C8F53C = *(_DWORD *)(v2 + 788);
  unk_C8F540 = *(_DWORD *)(v2 + 792);
  unk_C8F544 = *(_DWORD *)(v2 + 796);
  unk_C8F548 = *(_DWORD *)(v2 + 800);
  unk_C8F54C = *(_DWORD *)(v2 + 804);
  unk_C8F550 = *(_DWORD *)(v2 + 808);
  unk_C8F554 = *(_DWORD *)(v2 + 812);
  MEMORY[0xC8F558] = *(_DWORD *)(v2 + 816);
  unk_C8F55C = *(_DWORD *)(v2 + 820);
  unk_C8F560 = *(_DWORD *)(v2 + 824);
  unk_C8F564 = *(_DWORD *)(v2 + 828);
  *v19 = n1065353216;
  v19[1] = unk_C8F52C;
  v19[2] = unk_C8F530;
  v19[3] = unk_C8F534;
  v19[4] = n3_11;
  v19[5] = unk_C8F53C;
  v19[6] = unk_C8F540;
  v19[7] = unk_C8F544;
  v19[8] = unk_C8F548;
  v19[9] = unk_C8F54C;
  v19[10] = unk_C8F550;
  v19[11] = unk_C8F554;
  v19[12] = MEMORY[0xC8F558];
  v19[13] = unk_C8F55C;
  v19[14] = unk_C8F560;
  v19[15] = unk_C8F564;
  n1065353216 = *(_DWORD *)(v2 + 832);
  unk_C8F52C = *(_DWORD *)(v2 + 836);
  unk_C8F530 = *(_DWORD *)(v2 + 840);
  unk_C8F534 = *(_DWORD *)(v2 + 844);
  n3_11 = *(_DWORD *)(v2 + 848);
  unk_C8F53C = *(_DWORD *)(v2 + 852);
  unk_C8F540 = *(_DWORD *)(v2 + 856);
  unk_C8F544 = *(_DWORD *)(v2 + 860);
  unk_C8F548 = *(_DWORD *)(v2 + 864);
  unk_C8F54C = *(_DWORD *)(v2 + 868);
  unk_C8F550 = *(_DWORD *)(v2 + 872);
  unk_C8F554 = *(_DWORD *)(v2 + 876);
  MEMORY[0xC8F558] = *(_DWORD *)(v2 + 880);
  unk_C8F55C = *(_DWORD *)(v2 + 884);
  unk_C8F560 = *(_DWORD *)(v2 + 888);
  unk_C8F564 = *(_DWORD *)(v2 + 892);
  v19[16] = n1065353216;
  v19[17] = unk_C8F52C;
  v19[18] = unk_C8F530;
  v19[19] = unk_C8F534;
  v19[20] = n3_11;
  v19[21] = unk_C8F53C;
  v19[22] = unk_C8F540;
  v19[23] = unk_C8F544;
  v19[24] = unk_C8F548;
  v19[25] = unk_C8F54C;
  v19[26] = unk_C8F550;
  v19[27] = unk_C8F554;
  v19[28] = MEMORY[0xC8F558];
  v19[29] = unk_C8F55C;
  v19[30] = unk_C8F560;
  v19[31] = unk_C8F564;
  n1065353216 = *(_DWORD *)(v2 + 896);
  unk_C8F52C = *(_DWORD *)(v2 + 900);
  unk_C8F530 = *(_DWORD *)(v2 + 904);
  unk_C8F534 = *(_DWORD *)(v2 + 908);
  n3_11 = *(_DWORD *)(v2 + 912);
  unk_C8F53C = *(_DWORD *)(v2 + 916);
  unk_C8F540 = *(_DWORD *)(v2 + 920);
  unk_C8F544 = *(_DWORD *)(v2 + 924);
  unk_C8F548 = *(_DWORD *)(v2 + 928);
  unk_C8F54C = *(_DWORD *)(v2 + 932);
  unk_C8F550 = *(_DWORD *)(v2 + 936);
  unk_C8F554 = *(_DWORD *)(v2 + 940);
  MEMORY[0xC8F558] = *(_DWORD *)(v2 + 944);
  unk_C8F55C = *(_DWORD *)(v2 + 948);
  unk_C8F560 = *(_DWORD *)(v2 + 952);
  unk_C8F564 = *(_DWORD *)(v2 + 956);
  v19[32] = n1065353216;
  v19[33] = unk_C8F52C;
  v19[34] = unk_C8F530;
  v19[35] = unk_C8F534;
  v19[36] = n3_11;
  v19[37] = unk_C8F53C;
  v19[38] = unk_C8F540;
  v19[39] = unk_C8F544;
  v19[40] = unk_C8F548;
  v19[41] = unk_C8F54C;
  v19[42] = unk_C8F550;
  v19[43] = unk_C8F554;
  v19[44] = MEMORY[0xC8F558];
  v19[45] = unk_C8F55C;
  v19[46] = unk_C8F560;
  v19[47] = unk_C8F564;
  n1065353216 = *(_DWORD *)(v2 + 960);
  unk_C8F52C = *(_DWORD *)(v2 + 964);
  unk_C8F530 = *(_DWORD *)(v2 + 968);
  unk_C8F534 = *(_DWORD *)(v2 + 972);
  n3_11 = *(_DWORD *)(v2 + 976);
  unk_C8F53C = *(_DWORD *)(v2 + 980);
  unk_C8F540 = *(_DWORD *)(v2 + 984);
  unk_C8F544 = *(_DWORD *)(v2 + 988);
  unk_C8F548 = *(_DWORD *)(v2 + 992);
  unk_C8F54C = *(_DWORD *)(v2 + 996);
  unk_C8F550 = *(_DWORD *)(v2 + 1000);
  unk_C8F554 = *(_DWORD *)(v2 + 1004);
  MEMORY[0xC8F558] = *(_DWORD *)(v2 + 1008);
  unk_C8F55C = *(_DWORD *)(v2 + 1012);
  unk_C8F560 = *(_DWORD *)(v2 + 1016);
  unk_C8F564 = *(_DWORD *)(v2 + 1020);
  v19[48] = n1065353216;
  v19[49] = unk_C8F52C;
  v19[50] = unk_C8F530;
  v19[51] = unk_C8F534;
  v19[52] = n3_11;
  v19[53] = unk_C8F53C;
  v19[54] = unk_C8F540;
  v19[55] = unk_C8F544;
  v19[56] = unk_C8F548;
  v19[57] = unk_C8F54C;
  v19[58] = unk_C8F550;
  v19[59] = unk_C8F554;
  v19[60] = MEMORY[0xC8F558];
  v19[61] = unk_C8F55C;
  v19[62] = unk_C8F560;
  v19[63] = unk_C8F564;
  unk_12A12BC = 0;
  result = sub_7E6970(1024);
  unk_113335C = 0;
  return result;
}

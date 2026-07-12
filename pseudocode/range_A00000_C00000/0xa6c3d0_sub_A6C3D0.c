// Function: sub_A6C3D0
// Address: 0xa6c3d0
// Size: 0x4bb
// Prototype: 

int __cdecl sub_A6C3D0(int a1, _DWORD *a2)
{
  int result; // eax
  int v3; // ecx
  int v4; // edx
  int v5; // ecx
  int v6; // eax
  int v7; // edi
  int v8; // eax
  unsigned int n6; // eax
  char *v10; // ecx
  _DWORD *v11; // esi
  _DWORD *v12; // edi
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // [esp+14h] [ebp+Ch]

  if ( sub_A698B0(a1, a2[13], 1) )
    return a2[13];
  v3 = byte_2332EA1[0] + 1;
  v4 = dword_119FDEC[v3];
  ++byte_2332EA1[0];
  dword_119FDF0[v3] = v4 + 10240;
  MEMORY[0xC8F528] = *a2;
  unk_C8F52C = a2[1];
  unk_C8F530 = a2[2];
  unk_C8F534 = a2[3];
  *(_DWORD *)(v4 + 768) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 772) = unk_C8F52C;
  *(_DWORD *)(v4 + 776) = unk_C8F530;
  *(_DWORD *)(v4 + 780) = unk_C8F534;
  MEMORY[0xC8F528] = a2[4];
  unk_C8F52C = a2[5];
  unk_C8F530 = a2[6];
  unk_C8F534 = a2[7];
  *(_DWORD *)(v4 + 784) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 788) = unk_C8F52C;
  *(_DWORD *)(v4 + 792) = unk_C8F530;
  *(_DWORD *)(v4 + 796) = unk_C8F534;
  MEMORY[0xC8F528] = a2[8];
  unk_C8F52C = a2[9];
  unk_C8F530 = a2[10];
  unk_C8F534 = a2[11];
  *(_DWORD *)(v4 + 800) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 804) = unk_C8F52C;
  *(_DWORD *)(v4 + 808) = unk_C8F530;
  *(_DWORD *)(v4 + 812) = unk_C8F534;
  MEMORY[0xC8F528] = a2[12];
  unk_C8F52C = a2[13];
  unk_C8F530 = a2[14];
  unk_C8F534 = a2[15];
  *(_DWORD *)(v4 + 816) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 820) = unk_C8F52C;
  *(_DWORD *)(v4 + 824) = unk_C8F530;
  *(_DWORD *)(v4 + 828) = unk_C8F534;
  MEMORY[0xC8F528] = a2[16];
  unk_C8F52C = a2[17];
  unk_C8F530 = a2[18];
  unk_C8F534 = a2[19];
  *(_DWORD *)(v4 + 832) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 836) = unk_C8F52C;
  *(_DWORD *)(v4 + 840) = unk_C8F530;
  *(_DWORD *)(v4 + 844) = unk_C8F534;
  v5 = *(_DWORD *)(v4 + 824);
  *(_DWORD *)(v4 + 820) = (*(_DWORD *)(v4 + 820) + 63) & 0xFFFFFC0;
  if ( !v5 )
    v5 = a1 + *(_DWORD *)(a1 + 8);
  v6 = *(_DWORD *)(v4 + 828);
  if ( !v6 )
    v6 = a1 + *(_DWORD *)(a1 + 12);
  *(_DWORD *)(v4 + 828) = v6;
  v17 = *(char *)(v4 + 796);
  *(_DWORD *)(v4 + 824) = v5;
  *(float *)(v4 + 880) = (float)v17;
  *(float *)(v4 + 884) = (float)*(char *)(v4 + 797);
  *(float *)(v4 + 888) = (float)*(char *)(v4 + 798);
  *(float *)(v4 + 892) = (float)*(char *)(v4 + 799);
  *(_DWORD *)(v4 + 916) = *(_DWORD *)(v4 + 772);
  *(_DWORD *)(v4 + 924) = *(_DWORD *)(v4 + 772) + 16 * *(__int16 *)(a1 + 18);
  v7 = a1 + *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v4 + 272) = 32769;
  *(_DWORD *)(v4 + 280) = 978670;
  *(_DWORD *)(v4 + 296) = 6;
  if ( *(_WORD *)(v4 + 776) )
  {
    *(_DWORD *)(v4 + 304) = *(unsigned __int8 *)(v4 + 776);
    v8 = *(unsigned __int8 *)(v4 + 777);
  }
  else
  {
    *(_DWORD *)(v4 + 304) = *(unsigned __int8 *)(a1 + 22);
    v8 = *(unsigned __int8 *)(a1 + 23);
  }
  *(_DWORD *)(v4 + 308) = v8;
  *(_DWORD *)(v4 + 312) = 66;
  *(_DWORD *)(v4 + 320) = unk_11A0800;
  *(_DWORD *)(v4 + 324) = unk_11A0804;
  *(_DWORD *)(v4 + 328) = unk_11A0808;
  *(_DWORD *)(v4 + 332) = unk_11A080C;
  *(_DWORD *)(v4 + 336) = unk_11A0720;
  *(_DWORD *)(v4 + 340) = unk_11A0724;
  *(_DWORD *)(v4 + 344) = unk_11A0728;
  *(_DWORD *)(v4 + 348) = unk_11A072C;
  *(_DWORD *)(v4 + 352) = (*(_BYTE *)a1 & 4) != 0 ? 0 : 5;
  *(_DWORD *)(v4 + 360) = 8;
  *(_DWORD *)(v4 + 384) = &unk_12A8D68;
  while ( (word_23056E8 & 0x100) != 0 )
    ;
  n6 = *(char *)(v7 + 1);
  v10 = (char *)(v7 + 1);
  v11 = (_DWORD *)(v7 + 12);
  v12 = (_DWORD *)(v7 + 8);
  while ( 2 )
  {
    switch ( n6 )
    {
      case 0u:
        v12 += 4;
        v11 += 4;
        *(_DWORD *)(v4 + 256) = 536870921;
        *(_DWORD *)(v4 + 496) = 32769;
        *(_DWORD *)(v4 + 504) = 1094795758;
        v10 += 16;
        while ( (word_23056E8 & 0x100) != 0 )
          ;
        goto LABEL_25;
      case 2u:
        *(_DWORD *)(v4 + 256) = 536870925;
        *(_DWORD *)(v4 + 496) = 32769;
        *(_DWORD *)(v4 + 504) = 306261742;
        v13 = *v12 + *(unsigned __int16 *)(v4 + 780);
        v12 += 4;
        *(_DWORD *)(v4 + 288) = v13;
        v14 = *v11 + 32 * *(unsigned __int16 *)(v4 + 782);
        v11 += 4;
        *(_DWORD *)(v4 + 292) = v14;
        *(_DWORD *)(v4 + 296) = 6;
        v10 += 16;
        while ( (word_23056E8 & 0x100) != 0 )
          ;
        goto LABEL_25;
      case 4u:
        v12 += 4;
        v11 += 4;
        *(_DWORD *)(v4 + 256) = 536870923;
        *(_DWORD *)(v4 + 496) = 32769;
        *(_DWORD *)(v4 + 504) = 1094795758;
        v10 += 16;
        while ( (word_23056E8 & 0x100) != 0 )
          ;
        goto LABEL_25;
      case 6u:
        *(_DWORD *)(v4 + 256) = 536870928;
        *(_DWORD *)(v4 + 496) = 32769;
        *(_DWORD *)(v4 + 504) = 306261742;
        v15 = *v12 + *(unsigned __int16 *)(v4 + 780);
        v12 += 4;
        *(_DWORD *)(v4 + 288) = v15;
        v16 = *v11 + 32 * *(unsigned __int16 *)(v4 + 782);
        v11 += 4;
        *(_DWORD *)(v4 + 292) = v16;
        *(_DWORD *)(v4 + 296) = 6;
        v10 += 16;
        while ( (word_23056E8 & 0x100) != 0 )
          ;
LABEL_25:
        n6 = *v10;
        if ( n6 > 6 )
          goto LABEL_26;
        continue;
      default:
LABEL_26:
        --byte_2332EA1[0];
        result = *(_DWORD *)(v4 + 820) + 64;
        break;
    }
    return result;
  }
}


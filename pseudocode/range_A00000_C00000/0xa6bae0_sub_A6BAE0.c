// Function: sub_A6BAE0
// Address: 0xa6bae0
// Size: 0x4cf
// Prototype: 

int __cdecl sub_A6BAE0(int a1, _DWORD *a2)
{
  int v2; // ecx
  int v3; // edi
  int v4; // ecx
  int v5; // eax
  _DWORD *v6; // ecx
  int v7; // edx
  int v8; // eax
  int v9; // eax
  int v10; // esi
  unsigned int n7; // eax
  _DWORD *v12; // ecx
  _DWORD *v13; // edx
  int v15; // [esp+18h] [ebp+Ch]

  v2 = ++byte_2332EA1[0];
  v3 = dword_119FDEC[v2];
  dword_119FDF0[v2] = v3 + 6144;
  MEMORY[0xC8F528] = *a2;
  unk_C8F52C = a2[1];
  unk_C8F530 = a2[2];
  unk_C8F534 = a2[3];
  *(_DWORD *)(v3 + 768) = MEMORY[0xC8F528];
  *(_DWORD *)(v3 + 772) = unk_C8F52C;
  *(_DWORD *)(v3 + 776) = unk_C8F530;
  *(_DWORD *)(v3 + 780) = unk_C8F534;
  MEMORY[0xC8F528] = a2[4];
  unk_C8F52C = a2[5];
  unk_C8F530 = a2[6];
  unk_C8F534 = a2[7];
  *(_DWORD *)(v3 + 784) = MEMORY[0xC8F528];
  *(_DWORD *)(v3 + 788) = unk_C8F52C;
  *(_DWORD *)(v3 + 792) = unk_C8F530;
  *(_DWORD *)(v3 + 796) = unk_C8F534;
  MEMORY[0xC8F528] = a2[8];
  unk_C8F52C = a2[9];
  unk_C8F530 = a2[10];
  unk_C8F534 = a2[11];
  *(_DWORD *)(v3 + 800) = MEMORY[0xC8F528];
  *(_DWORD *)(v3 + 804) = unk_C8F52C;
  *(_DWORD *)(v3 + 808) = unk_C8F530;
  *(_DWORD *)(v3 + 812) = unk_C8F534;
  MEMORY[0xC8F528] = a2[12];
  unk_C8F52C = a2[13];
  unk_C8F530 = a2[14];
  unk_C8F534 = a2[15];
  *(_DWORD *)(v3 + 816) = MEMORY[0xC8F528];
  *(_DWORD *)(v3 + 820) = unk_C8F52C;
  *(_DWORD *)(v3 + 824) = unk_C8F530;
  *(_DWORD *)(v3 + 828) = unk_C8F534;
  MEMORY[0xC8F528] = a2[16];
  unk_C8F52C = a2[17];
  unk_C8F530 = a2[18];
  unk_C8F534 = a2[19];
  *(_DWORD *)(v3 + 832) = MEMORY[0xC8F528];
  *(_DWORD *)(v3 + 836) = unk_C8F52C;
  *(_DWORD *)(v3 + 840) = unk_C8F530;
  *(_DWORD *)(v3 + 844) = unk_C8F534;
  v4 = *(_DWORD *)(v3 + 824);
  if ( !v4 )
    v4 = a1 + *(_DWORD *)(a1 + 8);
  v5 = *(_DWORD *)(v3 + 828);
  if ( !v5 )
    v5 = a1 + *(_DWORD *)(a1 + 12);
  *(_DWORD *)(v3 + 828) = v5;
  v15 = *(char *)(v3 + 796);
  *(_DWORD *)(v3 + 824) = v4;
  *(float *)(v3 + 880) = (float)v15;
  *(float *)(v3 + 884) = (float)*(char *)(v3 + 797);
  *(float *)(v3 + 888) = (float)*(char *)(v3 + 798);
  *(float *)(v3 + 892) = (float)*(char *)(v3 + 799);
  sub_7EA5E0((void *)(v3 + 512));
  *(float *)(v3 + 512) = 1.0;
  *(float *)(v3 + 532) = 1.0;
  *(float *)(v3 + 552) = 1.0000305;
  *(float *)(v3 + 568) = -2.0000305;
  *(float *)(v3 + 556) = 1.0;
  *(float *)(v3 + 572) = 0.0;
  sub_7E82C0(v3 + 512, v3 + 512, *(_DWORD *)(v3 + 816));
  *(_DWORD *)(v3 + 912) = *(_DWORD *)(v3 + 772);
  *(_DWORD *)(v3 + 916) = *(_DWORD *)(v3 + 772) + 16 * *(__int16 *)(a1 + 18);
  *(_DWORD *)(v3 + 920) = *(_DWORD *)(v3 + 772) + 32 * *(__int16 *)(a1 + 18);
  v6 = *(_DWORD **)(v3 + 800);
  *(_DWORD *)(v3 + 576) = *v6;
  *(_DWORD *)(v3 + 580) = v6[1];
  *(_DWORD *)(v3 + 584) = v6[2];
  *(_DWORD *)(v3 + 588) = v6[3];
  *(_DWORD *)(v3 + 592) = v6[4];
  *(_DWORD *)(v3 + 596) = v6[5];
  *(_DWORD *)(v3 + 600) = v6[6];
  *(_DWORD *)(v3 + 604) = v6[7];
  *(_DWORD *)(v3 + 608) = v6[8];
  *(_DWORD *)(v3 + 612) = v6[9];
  *(_DWORD *)(v3 + 616) = v6[10];
  *(_DWORD *)(v3 + 620) = v6[11];
  *(_DWORD *)(v3 + 624) = v6[12];
  *(_DWORD *)(v3 + 628) = v6[13];
  *(_DWORD *)(v3 + 632) = v6[14];
  *(_DWORD *)(v3 + 636) = v6[15];
  v7 = a1 + *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v3 + 256) = 1879048197;
  *(_DWORD *)(v3 + 264) = 0;
  *(_DWORD *)(v3 + 272) = 32769;
  *(_DWORD *)(v3 + 280) = 61166;
  *(_DWORD *)(v3 + 296) = 6;
  if ( *(_WORD *)(v3 + 776) )
  {
    *(_DWORD *)(v3 + 304) = *(unsigned __int8 *)(v3 + 776);
    v8 = *(unsigned __int8 *)(v3 + 777);
  }
  else
  {
    *(_DWORD *)(v3 + 304) = *(unsigned __int8 *)(a1 + 22);
    v8 = *(unsigned __int8 *)(a1 + 23);
  }
  *(_DWORD *)(v3 + 308) = v8;
  *(_DWORD *)(v3 + 312) = 66;
  if ( (*(_BYTE *)(v3 + 768) & 8) != 0 )
  {
    *(_DWORD *)(v3 + 320) = unk_11A07D0;
    *(_DWORD *)(v3 + 324) = unk_11A07D4;
    *(_DWORD *)(v3 + 328) = unk_11A07D8;
    v9 = unk_11A07DC;
  }
  else
  {
    *(_DWORD *)(v3 + 320) = unk_11A0720;
    *(_DWORD *)(v3 + 324) = unk_11A0724;
    *(_DWORD *)(v3 + 328) = unk_11A0728;
    v9 = unk_11A072C;
  }
  *(_DWORD *)(v3 + 332) = v9;
  v10 = v7 + 1;
  *(_DWORD *)(v3 + 336) = (*(_BYTE *)a1 & 4) != 0 ? 0 : 5;
  *(_DWORD *)(v3 + 344) = 8;
  n7 = *(char *)(v7 + 1);
  v12 = (_DWORD *)(v7 + 12);
  v13 = (_DWORD *)(v7 + 8);
  while ( 2 )
  {
    switch ( n7 )
    {
      case 0u:
      case 1u:
      case 4u:
      case 5u:
        *(_DWORD *)(v3 + 496) = 0x8000;
        *(_DWORD *)(v3 + 504) = 65;
        *(_DWORD *)(v3 + 640) = 0x8000;
        *(_DWORD *)(v3 + 648) = 65;
        goto LABEL_15;
      case 2u:
      case 3u:
      case 6u:
      case 7u:
        *(_DWORD *)(v3 + 496) = 0x8000;
        *(_DWORD *)(v3 + 504) = 1042;
        *(_DWORD *)(v3 + 640) = 0x8000;
        *(_DWORD *)(v3 + 648) = 1042;
        *(_DWORD *)(v3 + 288) = *v13 + *(unsigned __int16 *)(v3 + 780);
        *(_DWORD *)(v3 + 292) = *v12 + 32 * *(unsigned __int16 *)(v3 + 782);
LABEL_15:
        n7 = *(char *)(v10 + 16);
        v10 += 16;
        v13 += 4;
        v12 += 4;
        if ( n7 > 7 )
          goto LABEL_16;
        continue;
      default:
LABEL_16:
        while ( (word_23056E8 & 0x100) != 0 )
          ;
        --byte_2332EA1[0];
        return *(_DWORD *)(v3 + 820);
    }
  }
}


// Function: sub_A6ACB0
// Address: 0xa6acb0
// Size: 0x547
// Prototype: 

int __cdecl sub_A6ACB0(int a1, _DWORD *a2)
{
  int result; // eax
  int v3; // esi
  int v4; // ecx
  _DWORD *v5; // ebx
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  unsigned int n7; // eax
  _BYTE *v11; // ecx
  _DWORD *v12; // edx
  _DWORD *v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // [esp+8h] [ebp-48h]
  int v19; // [esp+8h] [ebp-48h]
  _BYTE v20[64]; // [esp+Ch] [ebp-44h] BYREF

  if ( sub_A698B0(a1, a2[13], 1) )
    return a2[13];
  v3 = dword_119FDF0[byte_2332EA1[0]];
  v4 = ++byte_2332EA1[0];
  dword_119FDF0[v4] = v3 + 10240;
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
  v5 = (_DWORD *)(v3 + 768);
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
  v6 = *(_DWORD *)(v3 + 824);
  *(_DWORD *)(v3 + 820) = (*(_DWORD *)(v3 + 820) + 63) & 0xFFFFFC0;
  if ( !v6 )
    v6 = a1 + *(_DWORD *)(a1 + 8);
  v7 = *(_DWORD *)(v3 + 828);
  if ( !v7 )
    v7 = a1 + *(_DWORD *)(a1 + 12);
  *(_DWORD *)(v3 + 828) = v7;
  v18 = *(char *)(v3 + 796);
  *(_DWORD *)(v3 + 824) = v6;
  *(float *)(v3 + 880) = (float)v18;
  *(float *)(v3 + 884) = (float)*(char *)(v3 + 797);
  *(float *)(v3 + 888) = (float)*(char *)(v3 + 798);
  *(float *)(v3 + 892) = (float)*(char *)(v3 + 799);
  *(_DWORD *)(v3 + 912) = *(_DWORD *)(v3 + 772) + 16 * *(__int16 *)(a1 + 18);
  *(_DWORD *)(v3 + 916) = *(_DWORD *)(v3 + 772);
  if ( (*v5 & 0x40) != 0 )
  {
    nullsub_202(a1, v3 + 768, v3);
  }
  else if ( *(_WORD *)(a1 + 20) && (*v5 & 0x20) == 0 )
  {
    sub_A6CD80(v20, *(_DWORD *)(v3 + 808), *(_DWORD *)(v3 + 812));
  }
  v8 = a1 + *(_DWORD *)(a1 + 4);
  *(_DWORD *)(v3 + 272) = 32769;
  *(_DWORD *)(v3 + 280) = 978670;
  *(_DWORD *)(v3 + 296) = 6;
  v19 = v8;
  if ( *(_WORD *)(v3 + 776) )
  {
    *(_DWORD *)(v3 + 304) = *(unsigned __int8 *)(v3 + 776);
    v9 = *(unsigned __int8 *)(v3 + 777);
  }
  else
  {
    *(_DWORD *)(v3 + 304) = *(unsigned __int8 *)(a1 + 22);
    v9 = *(unsigned __int8 *)(a1 + 23);
  }
  *(_DWORD *)(v3 + 308) = v9;
  *(_DWORD *)(v3 + 312) = 66;
  *(_DWORD *)(v3 + 320) = unk_11A0800;
  *(_DWORD *)(v3 + 324) = unk_11A0804;
  *(_DWORD *)(v3 + 328) = unk_11A0808;
  *(_DWORD *)(v3 + 332) = unk_11A080C;
  *(_DWORD *)(v3 + 336) = unk_11A0720;
  *(_DWORD *)(v3 + 340) = unk_11A0724;
  *(_DWORD *)(v3 + 344) = unk_11A0728;
  *(_DWORD *)(v3 + 348) = unk_11A072C;
  *(_DWORD *)(v3 + 352) = (*(_BYTE *)a1 & 4) != 0 ? 0 : 5;
  *(_DWORD *)(v3 + 360) = 8;
  *(_DWORD *)(v3 + 384) = &unk_12A8D68;
  while ( (word_23056E8 & 0x100) != 0 )
    ;
  n7 = *(char *)(v8 + 1);
  v11 = (_BYTE *)(v8 + 1);
  v12 = (_DWORD *)(v8 + 12);
  v13 = (_DWORD *)(v19 + 8);
  while ( 2 )
  {
    switch ( n7 )
    {
      case 0u:
      case 1u:
        *(_DWORD *)(v3 + 256) = 536870921;
        *(_DWORD *)(v3 + 496) = 32769;
        *(_DWORD *)(v3 + 504) = 1094795758;
        v13 += 4;
        v12 += 4;
        if ( *v11 == 1 )
        {
          v11 += 16;
          while ( (word_23056E8 & 0x100) != 0 )
            ;
        }
        else
        {
          v11 += 16;
          while ( (word_23056E8 & 0x100) != 0 )
            ;
        }
        goto LABEL_46;
      case 2u:
      case 3u:
        *(_DWORD *)(v3 + 256) = 536870925;
        *(_DWORD *)(v3 + 496) = 32769;
        *(_DWORD *)(v3 + 504) = 306261742;
        v14 = *v13 + *(unsigned __int16 *)(v3 + 780);
        v13 += 4;
        *(_DWORD *)(v3 + 288) = v14;
        v15 = *v12 + 32 * *(unsigned __int16 *)(v3 + 782);
        *(_DWORD *)(v3 + 296) = 6;
        *(_DWORD *)(v3 + 292) = v15;
        v12 += 4;
        if ( *v11 == 3 )
        {
          v11 += 16;
          while ( (word_23056E8 & 0x100) != 0 )
            ;
        }
        else
        {
          v11 += 16;
          while ( (word_23056E8 & 0x100) != 0 )
            ;
        }
        goto LABEL_46;
      case 4u:
      case 5u:
        *(_DWORD *)(v3 + 256) = 536870923;
        *(_DWORD *)(v3 + 496) = 32769;
        *(_DWORD *)(v3 + 504) = 1094795758;
        v13 += 4;
        v12 += 4;
        if ( *v11 == 5 )
        {
          v11 += 16;
          while ( (word_23056E8 & 0x100) != 0 )
            ;
        }
        else
        {
          v11 += 16;
          while ( (word_23056E8 & 0x100) != 0 )
            ;
        }
        goto LABEL_46;
      case 6u:
      case 7u:
        *(_DWORD *)(v3 + 256) = 536870928;
        *(_DWORD *)(v3 + 496) = 32769;
        *(_DWORD *)(v3 + 504) = 306261742;
        v16 = *v13 + *(unsigned __int16 *)(v3 + 780);
        v13 += 4;
        *(_DWORD *)(v3 + 288) = v16;
        v17 = *v12 + 32 * *(unsigned __int16 *)(v3 + 782);
        *(_DWORD *)(v3 + 296) = 6;
        *(_DWORD *)(v3 + 292) = v17;
        v12 += 4;
        if ( *v11 == 7 )
        {
          v11 += 16;
          while ( (word_23056E8 & 0x100) != 0 )
            ;
        }
        else
        {
          v11 += 16;
          while ( (word_23056E8 & 0x100) != 0 )
            ;
        }
LABEL_46:
        n7 = (char)*v11;
        if ( n7 > 7 )
          goto LABEL_47;
        continue;
      default:
LABEL_47:
        --byte_2332EA1[0];
        result = *(_DWORD *)(v3 + 820);
        break;
    }
    return result;
  }
}


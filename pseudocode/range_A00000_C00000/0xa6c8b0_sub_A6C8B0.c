// Function: sub_A6C8B0
// Address: 0xa6c8b0
// Size: 0x466
// Prototype: 

int __usercall sub_A6C8B0@<eax>(int a1@<esi>, int a2, _DWORD *a3)
{
  int result; // eax
  int v4; // ecx
  int v5; // esi
  int v6; // ecx
  int v7; // eax
  int v8; // edx
  int v9; // eax
  int v10; // eax
  int v11; // edi
  unsigned int n7; // eax
  _DWORD *v13; // ecx
  _DWORD *v14; // edx
  int v16; // [esp+14h] [ebp+Ch]

  if ( sub_A698B0(a2, a3[13], 1) )
    return a3[13];
  v4 = ++byte_2332EA1[0];
  v5 = dword_119FDEC[v4];
  dword_119FDF0[v4] = v5 + 10240;
  MEMORY[0xC8F528] = *a3;
  unk_C8F52C = a3[1];
  unk_C8F530 = a3[2];
  unk_C8F534 = a3[3];
  *(_DWORD *)(v5 + 768) = MEMORY[0xC8F528];
  *(_DWORD *)(v5 + 772) = unk_C8F52C;
  *(_DWORD *)(v5 + 776) = unk_C8F530;
  *(_DWORD *)(v5 + 780) = unk_C8F534;
  MEMORY[0xC8F528] = a3[4];
  unk_C8F52C = a3[5];
  unk_C8F530 = a3[6];
  unk_C8F534 = a3[7];
  *(_DWORD *)(v5 + 784) = MEMORY[0xC8F528];
  *(_DWORD *)(v5 + 788) = unk_C8F52C;
  *(_DWORD *)(v5 + 792) = unk_C8F530;
  *(_DWORD *)(v5 + 796) = unk_C8F534;
  MEMORY[0xC8F528] = a3[8];
  unk_C8F52C = a3[9];
  unk_C8F530 = a3[10];
  unk_C8F534 = a3[11];
  *(_DWORD *)(v5 + 800) = MEMORY[0xC8F528];
  *(_DWORD *)(v5 + 804) = unk_C8F52C;
  *(_DWORD *)(v5 + 808) = unk_C8F530;
  *(_DWORD *)(v5 + 812) = unk_C8F534;
  MEMORY[0xC8F528] = a3[12];
  unk_C8F52C = a3[13];
  unk_C8F530 = a3[14];
  unk_C8F534 = a3[15];
  *(_DWORD *)(v5 + 816) = MEMORY[0xC8F528];
  *(_DWORD *)(v5 + 820) = unk_C8F52C;
  *(_DWORD *)(v5 + 824) = unk_C8F530;
  *(_DWORD *)(v5 + 828) = unk_C8F534;
  MEMORY[0xC8F528] = a3[16];
  unk_C8F52C = a3[17];
  unk_C8F530 = a3[18];
  unk_C8F534 = a3[19];
  *(_DWORD *)(v5 + 832) = MEMORY[0xC8F528];
  *(_DWORD *)(v5 + 836) = unk_C8F52C;
  *(_DWORD *)(v5 + 840) = unk_C8F530;
  *(_DWORD *)(v5 + 844) = unk_C8F534;
  v6 = *(_DWORD *)(v5 + 824);
  *(_DWORD *)(v5 + 820) = (*(_DWORD *)(v5 + 820) + 63) & 0xFFFFFC0;
  if ( !v6 )
    v6 = a2 + *(_DWORD *)(a2 + 8);
  v7 = *(_DWORD *)(v5 + 828);
  if ( !v7 )
    v7 = a2 + *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v5 + 828) = v7;
  v16 = *(char *)(v5 + 796);
  *(_DWORD *)(v5 + 824) = v6;
  *(float *)(v5 + 880) = (float)v16;
  *(float *)(v5 + 884) = (float)*(char *)(v5 + 797);
  *(float *)(v5 + 888) = (float)*(char *)(v5 + 798);
  *(float *)(v5 + 892) = (float)*(char *)(v5 + 799);
  *(_DWORD *)(v5 + 916) = *(_DWORD *)(v5 + 772);
  *(_DWORD *)(v5 + 924) = *(_DWORD *)(v5 + 772) + 16 * *(__int16 *)(a2 + 18);
  v8 = a2 + *(_DWORD *)(a2 + 4);
  *(_DWORD *)(v5 + 256) = 0x20000000;
  *(_DWORD *)(v5 + 264) = 0;
  *(_DWORD *)(v5 + 272) = 32769;
  *(_DWORD *)(v5 + 280) = 978670;
  *(_DWORD *)(v5 + 296) = 6;
  if ( *(_WORD *)(v5 + 776) )
  {
    *(_DWORD *)(v5 + 304) = *(unsigned __int8 *)(v5 + 776);
    v9 = *(unsigned __int8 *)(v5 + 777);
  }
  else
  {
    *(_DWORD *)(v5 + 304) = *(unsigned __int8 *)(a2 + 22);
    v9 = *(unsigned __int8 *)(a2 + 23);
  }
  *(_DWORD *)(v5 + 308) = v9;
  *(_DWORD *)(v5 + 312) = 66;
  *(_DWORD *)(v5 + 320) = unk_11A0800;
  *(_DWORD *)(v5 + 324) = unk_11A0804;
  *(_DWORD *)(v5 + 328) = unk_11A0808;
  *(_DWORD *)(v5 + 332) = unk_11A080C;
  if ( (*(_BYTE *)(v5 + 768) & 8) != 0 )
  {
    *(_DWORD *)(v5 + 336) = unk_11A07D0;
    *(_DWORD *)(v5 + 340) = unk_11A07D4;
    *(_DWORD *)(v5 + 344) = unk_11A07D8;
    v10 = unk_11A07DC;
  }
  else
  {
    *(_DWORD *)(v5 + 336) = unk_11A0720;
    *(_DWORD *)(v5 + 340) = unk_11A0724;
    *(_DWORD *)(v5 + 344) = unk_11A0728;
    v10 = unk_11A072C;
  }
  *(_DWORD *)(v5 + 348) = v10;
  v11 = v8 + 1;
  *(_DWORD *)(v5 + 352) = (*(_BYTE *)a2 & 4) != 0 ? 0 : 5;
  *(_DWORD *)(v5 + 360) = 8;
  *(_DWORD *)(v5 + 736) = 32769;
  *(_DWORD *)(v5 + 744) = 14;
  *(_DWORD *)(v5 + 384) = &unk_12A8D68;
  n7 = *(char *)(v8 + 1);
  v13 = (_DWORD *)(v8 + 12);
  v14 = (_DWORD *)(v8 + 8);
  while ( 2 )
  {
    switch ( n7 )
    {
      case 0u:
        *(_DWORD *)(v5 + 496) = 32769;
        *(_DWORD *)(v5 + 504) = 4276545;
        goto LABEL_18;
      case 1u:
      case 3u:
      case 5u:
      case 7u:
        nullsub_34();
        nullsub_35(1, "(op)\top_md0_onef() light no support !\n", a1);
        goto LABEL_21;
      case 2u:
      case 6u:
        *(_DWORD *)(v5 + 496) = 32769;
        *(_DWORD *)(v5 + 504) = 306258962;
        *(_DWORD *)(v5 + 288) = *v14 + *(unsigned __int16 *)(v5 + 780);
        *(_DWORD *)(v5 + 292) = *v13 + 32 * *(unsigned __int16 *)(v5 + 782);
        goto LABEL_18;
      case 4u:
        *(_DWORD *)(v5 + 496) = 32769;
        *(_DWORD *)(v5 + 504) = 1094795585;
LABEL_18:
        n7 = *(char *)(v11 + 16);
        v11 += 16;
        v14 += 4;
        v13 += 4;
        if ( n7 <= 7 )
          continue;
        --byte_2332EA1[0];
        result = *(_DWORD *)(v5 + 820) + 64;
        break;
      default:
LABEL_21:
        --byte_2332EA1[0];
        return *(_DWORD *)(v5 + 820) + 64;
    }
    return result;
  }
}


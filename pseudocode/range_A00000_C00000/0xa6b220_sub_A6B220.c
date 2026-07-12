// Function: sub_A6B220
// Address: 0xa6b220
// Size: 0x4cd
// Prototype: 

int __usercall sub_A6B220@<eax>(int a1@<edi>, int a2, _DWORD *a3)
{
  int v4; // esi
  int v5; // ecx
  _DWORD *v6; // edi
  int v7; // ecx
  int v8; // eax
  int v9; // edx
  int v10; // eax
  int v11; // eax
  _BYTE *v12; // ecx
  unsigned int n7; // eax
  _DWORD *v14; // edx
  _DWORD *v15; // ebx
  bool v16; // zf
  int v18; // [esp+8h] [ebp-48h]
  int v19; // [esp+8h] [ebp-48h]
  _BYTE v20[64]; // [esp+Ch] [ebp-44h] BYREF

  if ( sub_A698B0(a2, a3[13], 1) )
    return a3[13];
  v4 = dword_119FDF0[byte_2332EA1[0]];
  v5 = ++byte_2332EA1[0];
  dword_119FDF0[v5] = v4 + 10240;
  MEMORY[0xC8F528] = *a3;
  unk_C8F52C = a3[1];
  unk_C8F530 = a3[2];
  unk_C8F534 = a3[3];
  *(_DWORD *)(v4 + 768) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 772) = unk_C8F52C;
  *(_DWORD *)(v4 + 776) = unk_C8F530;
  *(_DWORD *)(v4 + 780) = unk_C8F534;
  MEMORY[0xC8F528] = a3[4];
  unk_C8F52C = a3[5];
  unk_C8F530 = a3[6];
  unk_C8F534 = a3[7];
  v6 = (_DWORD *)(v4 + 768);
  *(_DWORD *)(v4 + 784) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 788) = unk_C8F52C;
  *(_DWORD *)(v4 + 792) = unk_C8F530;
  *(_DWORD *)(v4 + 796) = unk_C8F534;
  MEMORY[0xC8F528] = a3[8];
  unk_C8F52C = a3[9];
  unk_C8F530 = a3[10];
  unk_C8F534 = a3[11];
  *(_DWORD *)(v4 + 800) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 804) = unk_C8F52C;
  *(_DWORD *)(v4 + 808) = unk_C8F530;
  *(_DWORD *)(v4 + 812) = unk_C8F534;
  MEMORY[0xC8F528] = a3[12];
  unk_C8F52C = a3[13];
  unk_C8F530 = a3[14];
  unk_C8F534 = a3[15];
  *(_DWORD *)(v4 + 816) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 820) = unk_C8F52C;
  *(_DWORD *)(v4 + 824) = unk_C8F530;
  *(_DWORD *)(v4 + 828) = unk_C8F534;
  MEMORY[0xC8F528] = a3[16];
  unk_C8F52C = a3[17];
  unk_C8F530 = a3[18];
  unk_C8F534 = a3[19];
  *(_DWORD *)(v4 + 832) = MEMORY[0xC8F528];
  *(_DWORD *)(v4 + 836) = unk_C8F52C;
  *(_DWORD *)(v4 + 840) = unk_C8F530;
  *(_DWORD *)(v4 + 844) = unk_C8F534;
  v7 = *(_DWORD *)(v4 + 824);
  *(_DWORD *)(v4 + 820) = (*(_DWORD *)(v4 + 820) + 63) & 0xFFFFFC0;
  if ( !v7 )
    v7 = a2 + *(_DWORD *)(a2 + 8);
  v8 = *(_DWORD *)(v4 + 828);
  if ( !v8 )
    v8 = a2 + *(_DWORD *)(a2 + 12);
  *(_DWORD *)(v4 + 828) = v8;
  v18 = *(char *)(v4 + 796);
  *(_DWORD *)(v4 + 824) = v7;
  *(float *)(v4 + 880) = (float)v18;
  *(float *)(v4 + 884) = (float)*(char *)(v4 + 797);
  *(float *)(v4 + 888) = (float)*(char *)(v4 + 798);
  *(float *)(v4 + 892) = (float)*(char *)(v4 + 799);
  *(_DWORD *)(v4 + 912) = *(_DWORD *)(v4 + 772) + 16 * *(__int16 *)(a2 + 18);
  *(_DWORD *)(v4 + 916) = *(_DWORD *)(v4 + 772);
  if ( (*v6 & 0x40) != 0 )
  {
    if ( !*(_DWORD *)(v4 + 836) )
      *(_DWORD *)(v4 + 836) = *(_DWORD *)(v4 + 800);
    nullsub_202(a2, v4 + 768, v4);
  }
  else if ( *(_WORD *)(a2 + 20) && (*v6 & 0x20) == 0 )
  {
    sub_A6CD80(v20, *(_DWORD *)(v4 + 808), *(_DWORD *)(v4 + 812));
  }
  v9 = a2 + *(_DWORD *)(a2 + 4);
  *(_DWORD *)(v4 + 256) = 0x20000000;
  *(_DWORD *)(v4 + 264) = 0;
  *(_DWORD *)(v4 + 272) = 32769;
  *(_DWORD *)(v4 + 280) = 978670;
  *(_DWORD *)(v4 + 296) = 6;
  v19 = v9;
  if ( *(_WORD *)(v4 + 776) )
  {
    *(_DWORD *)(v4 + 304) = *(unsigned __int8 *)(v4 + 776);
    v10 = *(unsigned __int8 *)(v4 + 777);
  }
  else
  {
    *(_DWORD *)(v4 + 304) = *(unsigned __int8 *)(a2 + 22);
    v10 = *(unsigned __int8 *)(a2 + 23);
  }
  *(_DWORD *)(v4 + 308) = v10;
  *(_DWORD *)(v4 + 312) = 66;
  *(_DWORD *)(v4 + 320) = unk_11A0800;
  *(_DWORD *)(v4 + 324) = unk_11A0804;
  *(_DWORD *)(v4 + 328) = unk_11A0808;
  *(_DWORD *)(v4 + 332) = unk_11A080C;
  if ( (*(_BYTE *)v6 & 8) != 0 )
  {
    *(_DWORD *)(v4 + 336) = unk_11A07D0;
    *(_DWORD *)(v4 + 340) = unk_11A07D4;
    *(_DWORD *)(v4 + 344) = unk_11A07D8;
    v11 = unk_11A07DC;
  }
  else
  {
    *(_DWORD *)(v4 + 336) = unk_11A0720;
    *(_DWORD *)(v4 + 340) = unk_11A0724;
    *(_DWORD *)(v4 + 344) = unk_11A0728;
    v11 = unk_11A072C;
  }
  *(_DWORD *)(v4 + 348) = v11;
  v12 = (_BYTE *)(v9 + 1);
  *(_DWORD *)(v4 + 352) = (*(_BYTE *)a2 & 4) != 0 ? 0 : 5;
  *(_DWORD *)(v4 + 360) = 8;
  *(_DWORD *)(v4 + 736) = 32769;
  *(_DWORD *)(v4 + 744) = 14;
  *(_DWORD *)(v4 + 384) = &unk_12A8D68;
  n7 = *(char *)(v9 + 1);
  v14 = (_DWORD *)(v9 + 12);
  v15 = (_DWORD *)(v19 + 8);
  while ( 2 )
  {
    switch ( n7 )
    {
      case 0u:
      case 1u:
        *(_DWORD *)(v4 + 496) = 32769;
        *(_DWORD *)(v4 + 504) = 4276545;
        v16 = *v12 == 1;
        goto LABEL_26;
      case 2u:
      case 3u:
        *(_DWORD *)(v4 + 496) = 32769;
        *(_DWORD *)(v4 + 504) = 306258962;
        *(_DWORD *)(v4 + 288) = *v15 + *(unsigned __int16 *)(v4 + 780);
        *(_DWORD *)(v4 + 292) = *v14 + 32 * *(unsigned __int16 *)(v4 + 782);
        v16 = *v12 == 3;
        goto LABEL_26;
      case 4u:
      case 5u:
        *(_DWORD *)(v4 + 496) = 32769;
        *(_DWORD *)(v4 + 504) = 1094795585;
        v16 = *v12 == 5;
        goto LABEL_26;
      case 6u:
      case 7u:
        *(_DWORD *)(v4 + 496) = 32769;
        *(_DWORD *)(v4 + 504) = 306258962;
        *(_DWORD *)(v4 + 288) = *v15 + *(unsigned __int16 *)(v4 + 780);
        *(_DWORD *)(v4 + 292) = *v14 + 32 * *(unsigned __int16 *)(v4 + 782);
        v16 = *v12 == 7;
LABEL_26:
        if ( !v16 )
        {
          n7 = (char)v12[16];
          v12 += 16;
          v15 += 4;
          v14 += 4;
          if ( n7 > 7 )
            goto LABEL_30;
          continue;
        }
        nullsub_34();
        nullsub_35(1, "one8 draw mode unsuport light program ----------------------------\n", a1);
LABEL_30:
        --byte_2332EA1[0];
        return *(_DWORD *)(v4 + 820) + 64;
      default:
        goto LABEL_30;
    }
  }
}


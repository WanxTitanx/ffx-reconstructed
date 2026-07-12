// Function: sub_A6A3A0
// Address: 0xa6a3a0
// Size: 0x2ff
// Prototype: 

int __cdecl sub_A6A3A0(int a1, _DWORD *a2, int a3)
{
  int v3; // ecx
  int v4; // edi
  _DWORD *v5; // ebx
  int v6; // ecx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-Ch]
  float v10; // [esp+14h] [ebp-4h]

  v3 = ++byte_2332EA1[0];
  v4 = dword_119FDEC[v3];
  dword_119FDF0[v3] = v4 + 6144;
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
  v5 = (_DWORD *)(v4 + 768);
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
  v6 = *(_DWORD *)(v4 + 824);
  if ( !v6 )
    v6 = a1 + *(_DWORD *)(a1 + 8);
  v7 = *(_DWORD *)(v4 + 828);
  if ( !v7 )
    v7 = a1 + *(_DWORD *)(a1 + 12);
  *(_DWORD *)(v4 + 824) = v6;
  *(_DWORD *)(v4 + 828) = v7;
  v9 = sub_A68FF0();
  v10 = (double)*(unsigned __int8 *)(v4 + 844) * 0.0078125;
  *(float *)(v4 + 880) = (double)(unsigned __int8)v9 * v10 + (double)*(unsigned __int8 *)(v4 + 796) * (1.0 - v10);
  *(float *)(v4 + 884) = (double)*(unsigned __int8 *)(v4 + 797) * (1.0 - v10) + (double)BYTE1(v9) * v10;
  *(float *)(v4 + 888) = (double)*(unsigned __int8 *)(v4 + 798) * (1.0 - v10) + (double)BYTE2(v9) * v10;
  *(float *)(v4 + 892) = v10 * (double)HIBYTE(v9) + (1.0 - v10) * (double)*(unsigned __int8 *)(v4 + 799);
  *(_DWORD *)(v4 + 912) = *(_DWORD *)(v4 + 772) + 32 * *(__int16 *)(a1 + 18);
  *(_DWORD *)(v4 + 916) = *(_DWORD *)(v4 + 772);
  if ( (*v5 & 0x40) != 0 )
  {
    sub_A6D380(a1, v4 + 768, v4, a3);
  }
  else if ( *(_WORD *)(a1 + 20) && (*v5 & 0x20) == 0 )
  {
    sub_A6CF10(a1, v4 + 768, v4);
    --byte_2332EA1[0];
    return 0;
  }
  --byte_2332EA1[0];
  return 0;
}


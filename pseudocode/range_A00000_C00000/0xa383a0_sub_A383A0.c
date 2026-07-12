// Function: sub_A383A0
// Address: 0xa383a0
// Size: 0xa7
// Prototype: 

_DWORD *__cdecl sub_A383A0(int a1)
{
  _DWORD *v1; // esi
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // eax
  _WORD v7[24]; // [esp+4h] [ebp-30h] BYREF

  memset(v7, 0, sizeof(v7));
  v1 = (_DWORD *)sub_A3B210(dword_1A858B4[684], 0, v7);
  v1[12] &= 0xF0000000;
  v2 = v1[7];
  v3 = v1[6];
  v1[1] = a1;
  v4 = v1[8];
  *v1 = 0;
  v1[2] = 0;
  v1[3] = 1;
  v1[4] = 1;
  v1[5] = 0;
  *(_DWORD *)(v4 + 28) = v2;
  *(_DWORD *)(v1[7] + 32) = v1[8];
  v3 += 296;
  v1[7] = v3;
  v5 = *(_DWORD *)(v3 + 32);
  v1[8] = v5;
  *(_DWORD *)(v5 + 28) = v1;
  *(_DWORD *)(v1[7] + 32) = v1;
  v1[12] = v1[12] & 0xFFFFFFF | 0x50000000;
  return v1;
}


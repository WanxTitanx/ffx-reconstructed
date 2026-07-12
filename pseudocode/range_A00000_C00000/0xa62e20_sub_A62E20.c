// Function: sub_A62E20
// Address: 0xa62e20
// Size: 0x219
// Prototype: 

int sub_A62E20()
{
  int v0; // eax
  _DWORD *v1; // ebx
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // edx
  int v8; // [esp+Ch] [ebp-4h]

  v8 = sub_7E6910(3072);
  sub_6EDAE0(&unk_2322700);
  sub_93D550(&unk_113FC70, &unk_2322700, &unk_22C92A0);
  sub_93D830(&unk_113FC70, &unk_113FC70, &unk_22C92B0);
  sub_6ED700(&unk_2322700, &unk_113FCB0, &unk_113FC70);
  sub_6ED700(&unk_113FDB0, &unk_113FCF0, &unk_2322700);
  sub_62FA30(0, 0);
  *(_DWORD *)(v8 + 56) = 128;
  *(_DWORD *)(v8 + 16) = 1;
  *(_DWORD *)(v8 + 24) = -286331362;
  *(_DWORD *)(v8 + 32) = 196610;
  *(_DWORD *)(v8 + 40) = 71;
  *(_DWORD *)(v8 + 48) = 128;
  *(_DWORD *)(v8 + 52) = 128;
  *(_DWORD *)(v8 + 59) = 128;
  v0 = sub_A5E7B0((_DWORD *)(v8 + 64), 3, 0);
  *(float *)(v8 + 1024) = 64.0;
  v1 = (_DWORD *)(v0 + v8 + 64);
  *(float *)(v8 + 1028) = 0.0;
  *(float *)(v8 + 1032) = 0.0;
  *v1 = 128;
  v1[1] = 512;
  v1[8] = 240;
  v1[9] = 624;
  sub_7E9A60(v1 + 4, &unk_113FDB0, v8 + 1024);
  v1[4] -= 128;
  v2 = v1[4];
  v1[5] -= 64;
  v3 = v1[5];
  v1[12] = v2 + 256;
  v1[13] = v3 + 128;
  *(float *)(v8 + 1024) = 0.0;
  *(float *)(v8 + 1028) = 0.0;
  *(float *)(v8 + 1032) = 64.0;
  v1[16] = 384;
  v1[17] = 512;
  v1[24] = 496;
  v1[25] = 624;
  sub_7E9A60(v1 + 20, &unk_113FDB0, v8 + 1024);
  v1[20] -= 128;
  v4 = v1[20];
  v1[21] -= 64;
  v5 = v1[21];
  v1[28] = v4 + 256;
  v1[29] = v5 + 128;
  v1 += 32;
  *v1 = 896;
  v1[1] = 640;
  v1[8] = 1008;
  v1[9] = 752;
  sub_7E9A60(v1 + 4, &unk_113FDB0, &dword_C48CC0);
  v1[4] -= 128;
  v1[5] -= 64;
  v6 = v1[5];
  v1[12] = v1[4] + 256;
  v1[13] = v6 + 128;
  *(_DWORD *)(v8 + 8) = 0;
  *(_DWORD *)v8 = (((int)v1 - v8 + 64) / 16 - 1) | 0x70000000;
  nullsub_39(unk_23328E0, v8 | 0x80000000);
  sub_62FA30(0, 0);
  return sub_7E6970(3072);
}


// Function: sub_A63070
// Address: 0xa63070
// Size: 0x232
// Prototype: int __cdecl(int n32, int n32, float, float)

int __cdecl sub_A63070(int n32, int a2, float a3, float a4)
{
  double v4; // st7
  int v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int n32_2; // edi
  double v10; // st6
  double v11; // st5
  double v12; // st4
  int n32_1; // esi
  double v14; // rt0
  double v15; // st4
  double v16; // st7
  float v18; // [esp+0h] [ebp-7Ch]
  double v19; // [esp+10h] [ebp-6Ch]
  float v20; // [esp+18h] [ebp-64h]
  int v21; // [esp+1Ch] [ebp-60h]
  float v22; // [esp+20h] [ebp-5Ch]
  int v23; // [esp+20h] [ebp-5Ch]
  float v24; // [esp+24h] [ebp-58h]
  int n32_3; // [esp+24h] [ebp-58h]
  float n32_4; // [esp+24h] [ebp-58h]
  float v27; // [esp+24h] [ebp-58h]
  _BYTE v28[64]; // [esp+28h] [ebp-54h] BYREF
  float v29[4]; // [esp+68h] [ebp-14h] BYREF

  v4 = a3;
  v5 = sub_7E6910(0x2000);
  *(_DWORD *)v5 = 0;
  *(_DWORD *)(v5 + 4) = 32;
  *(_DWORD *)(v5 + 12) = 0;
  v24 = 100.0 * a3;
  *(_DWORD *)(v5 + 16) = 262145;
  *(_DWORD *)(v5 + 20) = 4325376;
  *(_DWORD *)(v5 + 28) = 0;
  *(_DWORD *)(v5 + 8) = 88;
  *(_DWORD *)(v5 + 32) = 66560;
  memset((void *)(v5 + 48), 128, 14);
  *(_DWORD *)(v5 + 62) = 32896;
  *(_DWORD *)(v5 + 66) = 65538;
  *(_DWORD *)(v5 + 70) = -16777213;
  v21 = v5;
  *(_DWORD *)(v5 + 88) = 0;
  *(_WORD *)(v5 + 92) = 0;
  v6 = (int)v24;
  v7 = v5 + 1024;
  *(_WORD *)(v5 + 94) = v6;
  *(_DWORD *)(v5 + 96) = 0;
  *(_DWORD *)(v5 + 100) = 0;
  *(_WORD *)(v5 + 104) = v6;
  *(_DWORD *)(v5 + 106) = (unsigned __int16)v6;
  *(_WORD *)(v5 + 110) = v6;
  v8 = v5 + 2048;
  *(_DWORD *)(v5 + 1052) = 0;
  *(_DWORD *)(v5 + 1092) = 0;
  *(_DWORD *)(v5 + 1080) = 0;
  *(_DWORD *)(v5 + 1084) = 0;
  n32_2 = 0;
  *(_DWORD *)v7 = 28;
  *(_DWORD *)(v7 + 4) = v8;
  *(_WORD *)(v7 + 8) = 68;
  n32_3 = 0;
  if ( n32 > 0 )
  {
    v22 = (float)(n32 / 2);
    v10 = v22 * v4;
    v19 = v10;
    v11 = a4;
    v12 = 0.0099999998;
    do
    {
      n32_1 = 0;
      v23 = 0;
      n32_4 = (float)n32_3;
      v14 = v12;
      v15 = v4 * n32_4;
      v16 = v14;
      do
      {
        v18 = v16;
        sub_7EA610(&unk_2322700, v18);
        sub_93D550(&unk_113FC70, &unk_2322700, &unk_22C92A0);
        v27 = (float)v23;
        v29[0] = v27 * a3 - v19 - a4;
        v29[1] = 0.0;
        v20 = v15 - v10 - v11;
        v29[2] = v20;
        sub_93D830(&unk_113FC70, &unk_113FC70, v29);
        sub_6ED700(v28, &unk_113FCB0, &unk_113FC70);
        sub_6ED700(&unk_113FDB0, &unk_113FCF0, v28);
        *(_DWORD *)(v7 + 24) = dword_C879B0[((_BYTE)n32_1 + (_BYTE)n32_2) & 3];
        *(_DWORD *)(v7 + 32) = &unk_113FDB0;
        sub_A65750(v21, v7);
        v16 = 0.0099999998;
        v23 = ++n32_1;
      }
      while ( n32_1 < n32 );
      ++n32_2;
      v4 = a3;
      n32_3 = n32_2;
      v10 = v19;
      v11 = a4;
      v12 = 0.0099999998;
    }
    while ( n32_2 < n32 );
  }
  return sub_7E6970(0x2000);
}


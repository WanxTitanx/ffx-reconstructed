// Function: sub_A28F40
// Address: 0xa28f40
// Size: 0xac
// Prototype: 

int __thiscall sub_A28F40(int this, int a2, int a3, int a4, int a5)
{
  double v5; // st6
  double v6; // st7
  double v7; // rt0
  int v8; // ebx
  double v9; // st5
  double v10; // st6
  double v11; // rt1
  double v12; // st5
  double v13; // st6
  double v14; // st7
  float v16; // [esp+14h] [ebp+10h]
  float v17; // [esp+14h] [ebp+10h]
  float v18; // [esp+14h] [ebp+10h]
  float v19; // [esp+14h] [ebp+10h]

  v16 = (float)a4;
  v5 = v16;
  v6 = *(float *)(this + 116) * v16;
  v17 = (float)a2;
  v7 = v5;
  v8 = (int)(v6 + v17);
  *(_DWORD *)(this + 132) = v8;
  v18 = (float)a5;
  v9 = v18;
  v10 = *(float *)(this + 120) * v18;
  v19 = (float)a3;
  v11 = v9;
  v12 = v10 + v19;
  v13 = v7 * *(float *)(this + 124);
  *(_DWORD *)(this + 136) = (int)v12;
  v14 = v11 * *(float *)(this + 128);
  *(_DWORD *)(this + 140) = (int)v13;
  *(_DWORD *)(this + 144) = (int)v14;
  return sub_A3DD00(v8, (int)v12, (int)v13, (int)v14);
}


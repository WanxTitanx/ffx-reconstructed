// Function: sub_A6CD80
// Address: 0xa6cd80
// Size: 0x177
// Prototype: 

int __cdecl sub_A6CD80(int a1, int a2, int a3)
{
  int *v3; // edi
  float *v4; // esi
  int n4; // ebx
  double v6; // st7
  double v7; // st7
  float *v8; // esi
  int n3; // edi
  _BYTE v11[12]; // [esp+18h] [ebp-84h] BYREF
  char v12; // [esp+24h] [ebp-78h] BYREF
  _BYTE v13[16]; // [esp+28h] [ebp-74h] BYREF
  _BYTE v14[16]; // [esp+38h] [ebp-64h] BYREF
  float v15; // [esp+48h] [ebp-54h]
  float v16; // [esp+4Ch] [ebp-50h]
  float v17; // [esp+50h] [ebp-4Ch]
  float v18; // [esp+54h] [ebp-48h]
  int v19; // [esp+58h] [ebp-44h] BYREF
  float v20; // [esp+5Ch] [ebp-40h]
  float v21; // [esp+60h] [ebp-3Ch]
  float v22; // [esp+68h] [ebp-34h]
  float v23; // [esp+6Ch] [ebp-30h]
  float v24; // [esp+70h] [ebp-2Ch]
  float v25; // [esp+78h] [ebp-24h]
  float v26; // [esp+7Ch] [ebp-20h]
  float v27; // [esp+80h] [ebp-1Ch]
  float v28; // [esp+88h] [ebp-14h] BYREF
  float v29; // [esp+8Ch] [ebp-10h]
  float v30; // [esp+90h] [ebp-Ch]

  sub_6ED4A0(&v19, a2);
  *(float *)&v19 = -*(float *)&v19;
  v3 = &v19;
  v4 = (float *)(a2 + 12);
  n4 = 4;
  v20 = -v20;
  v21 = -v21;
  v22 = -v22;
  v23 = -v23;
  v24 = -v24;
  v25 = -v25;
  v26 = -v26;
  v27 = -v27;
  v28 = -v28;
  v29 = -v29;
  v30 = -v30;
  v6 = 0.0;
  do
  {
    *((float *)v3 + 3) = v6;
    sub_6ED830(v3, v3);
    sub_6EDA30((int)v3, (int)v3, *v4);
    v6 = 0.0;
    *((float *)v3 + 3) = 0.0;
    v4 += 4;
    v3 += 4;
    --n4;
  }
  while ( n4 );
  sub_6EDAD0(&v19, &v19);
  sub_6ED4A0(v11, a3);
  v7 = 0.0;
  v8 = (float *)&v12;
  n3 = 3;
  do
  {
    *v8 = v7;
    sub_6ED830(v8 - 3, v8 - 3);
    v7 = 0.0;
    *v8 = 0.0;
    v8 += 4;
    --n3;
  }
  while ( n3 );
  v18 = 0.0;
  v17 = 0.0;
  v16 = 0.0;
  v15 = 0.0;
  sub_6ED420(a1, &v19, v11);
  sub_6ED420(a1 + 16, &v19, v13);
  sub_6ED420(a1 + 32, &v19, v14);
  return sub_6ED4B0(a1 + 48, &v28);
}


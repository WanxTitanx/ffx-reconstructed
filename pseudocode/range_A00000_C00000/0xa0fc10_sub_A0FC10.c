// Function: sub_A0FC10
// Address: 0xa0fc10
// Size: 0xef
// Prototype: 

unsigned int __cdecl sub_A0FC10(int a1)
{
  int v1; // eax
  float *v2; // eax
  __int16 v3; // bx
  _BYTE v5[16]; // [esp+4h] [ebp-40h] BYREF
  float v6[4]; // [esp+14h] [ebp-30h] BYREF
  float v7; // [esp+24h] [ebp-20h] BYREF
  float v8; // [esp+28h] [ebp-1Ch]
  float v9; // [esp+2Ch] [ebp-18h]
  float v10; // [esp+34h] [ebp-10h] BYREF
  float v11; // [esp+38h] [ebp-Ch]
  float v12; // [esp+3Ch] [ebp-8h]
  int v13; // [esp+40h] [ebp-4h]

  v10 = *(float *)a1;
  v11 = *(float *)(a1 + 4);
  v12 = *(float *)(a1 + 8);
  v7 = v10 * 255.0;
  v13 = *(_DWORD *)(a1 + 12);
  v8 = v11 * 255.0;
  v9 = 255.0 * v12;
  v10 = v7;
  v11 = v8;
  v12 = v9;
  v7 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  v6[0] = 255.0;
  v6[1] = 255.0;
  v6[2] = 255.0;
  v1 = sub_4F86F0(v5, &v10, v6);
  v2 = (float *)sub_4F8660(v6, v1, &v7);
  v10 = *v2;
  v11 = v2[1];
  v12 = v2[2];
  v3 = 8 * ((int)v11 & 0xFC | (32 * ((int)v10 & 0xF8)));
  return (((((int)v12 & 0xF8u) >> 3) | (unsigned __int8)v3) << 8)
       | (unsigned __int8)((unsigned __int16)((((int)v12 & 0xF8u) >> 3) | v3) >> 8);
}


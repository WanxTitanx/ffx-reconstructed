// Function: sub_A43E60
// Address: 0xa43e60
// Size: 0x18e
// Prototype: 

int __cdecl sub_A43E60(float *a1, int a2, int a3, int a4)
{
  double v4; // st7
  double v5; // st6
  double v6; // st7
  int result; // eax
  float v8; // [esp+8h] [ebp-28h]
  float v9; // [esp+2Ch] [ebp-4h]
  float v10; // [esp+3Ch] [ebp+Ch]
  float v11; // [esp+3Ch] [ebp+Ch]
  float v12; // [esp+3Ch] [ebp+Ch]
  float v13; // [esp+3Ch] [ebp+Ch]
  float v14; // [esp+40h] [ebp+10h]
  float v15; // [esp+40h] [ebp+10h]
  float v16; // [esp+40h] [ebp+10h]

  v10 = (float)a2;
  v14 = (float)a3;
  v9 = v14 * 4.0 / (v10 * 3.0);
  v15 = a1[9] * 3.141499996185303 / 180.0;
  v16 = tan(v15 * 0.5);
  v4 = v16;
  if ( *(_BYTE *)(a4 + 329580) )
  {
    v5 = v10;
    *(float *)(a4 + 328976) = v10 * 0.5 / v4;
  }
  else
  {
    *(float *)(a4 + 328976) = 1024.0;
    v5 = v10;
  }
  v11 = v4 * (*(float *)(a4 + 328976) + *(float *)(a4 + 328976));
  v12 = v5 / v11;
  v6 = v12;
  v13 = v12 * v9;
  v8 = v6;
  result = sub_93D960(
             a4 + 328736,
             *(float *)(a4 + 328976),
             v8,
             v13,
             unk_1137000,
             unk_1137004,
             unk_1136FE0,
             unk_1136FE4,
             unk_1136FE8,
             unk_1136FEC);
  *(float *)(a4 + 328928) = *a1;
  *(float *)(a4 + 328932) = -a1[1];
  *(float *)(a4 + 328936) = -a1[2];
  *(float *)(a4 + 328940) = 1.0;
  *(float *)(a4 + 328944) = a1[3];
  *(float *)(a4 + 328948) = -a1[4];
  *(float *)(a4 + 328952) = -a1[5];
  *(float *)(a4 + 328956) = 1.0;
  *(float *)(a4 + 328960) = a1[6] - *a1;
  *(float *)(a4 + 328964) = -(a1[7] - a1[1]);
  *(float *)(a4 + 328968) = -(a1[8] - a1[2]);
  *(float *)(a4 + 328972) = 1.0;
  return result;
}


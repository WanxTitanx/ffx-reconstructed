// Function: sub_9B5000
// Address: 0x9b5000
void __thiscall sub_9B5000(int this, float a2)
{
  double v2; // st4
  double v3; // st6
  double v4; // st7
  double v5; // st6
  float v6; // [esp-30h] [ebp-3Ch]
  float v7; // [esp-2Ch] [ebp-38h]
  float v8; // [esp-28h] [ebp-34h]
  float v9; // [esp-20h] [ebp-2Ch]
  float v10; // [esp-20h] [ebp-2Ch]
  float v11; // [esp-1Ch] [ebp-28h]
  float v12; // [esp-1Ch] [ebp-28h]
  float v13; // [esp-18h] [ebp-24h]
  float v14; // [esp-18h] [ebp-24h]
  float v15; // [esp-Ch] [ebp-18h]
  float v16; // [esp-Ch] [ebp-18h]
  float v17; // [esp-Ch] [ebp-18h]
  float v18; // [esp-Ch] [ebp-18h]
  float v19; // [esp-Ch] [ebp-18h]
  float v20; // [esp-Ch] [ebp-18h]
  float v21; // [esp-4h] [ebp-10h]
  float v22; // [esp-4h] [ebp-10h]

  if ( (*(_BYTE *)(this + 216) & 3) == 0 )
  {
    v21 = *(float *)(this + 352) * a2;
    v9 = *(float *)(this + 432) * v21;
    v11 = *(float *)(this + 436) * v21;
    v13 = v21 * *(float *)(this + 440);
    *(float *)(this + 320) = v9 + *(float *)(this + 320);
    *(float *)(this + 324) = v11 + *(float *)(this + 324);
    *(float *)(this + 328) = v13 + *(float *)(this + 328);
    v22 = *(float *)(this + 452);
    v2 = *(float *)(this + 448);
    v3 = *(float *)(this + 456);
    v10 = *(float *)(this + 280) * v3 + *(float *)(this + 276) * v22 + v2 * *(float *)(this + 272);
    v12 = *(float *)(this + 292) * v22 + v2 * *(float *)(this + 288) + *(float *)(this + 296) * v3;
    v14 = v3 * *(float *)(this + 312) + v22 * *(float *)(this + 308) + v2 * *(float *)(this + 304);
    v6 = v10 * a2;
    v7 = v12 * a2;
    v8 = a2 * v14;
    v15 = v6 + *(float *)(this + 336);
    v4 = v15;
    *(float *)(this + 336) = v15;
    v16 = v7 + *(float *)(this + 340);
    v5 = v16;
    *(float *)(this + 340) = v16;
    v17 = v8 + *(float *)(this + 344);
    *(float *)(this + 344) = v17;
    v18 = v4 * v4 + v5 * v5 + v17 * v17;
    v19 = sqrt(v18);
    if ( v19 * a2 > 1.570796370506287 )
    {
      v20 = 1.570796370506287 / a2 / v19;
      *(float *)(this + 336) = v20 * *(float *)(this + 336);
      *(float *)(this + 340) = v20 * *(float *)(this + 340);
      *(float *)(this + 344) = v20 * *(float *)(this + 344);
    }
  }
}

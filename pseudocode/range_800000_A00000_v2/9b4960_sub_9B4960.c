// Function: sub_9B4960
// Address: 0x9b4960
void __thiscall sub_9B4960(int this, float a2)
{
  double v2; // st7
  double v3; // st6
  double v4; // st5
  double v5; // st7
  float v6; // [esp-30h] [ebp-3Ch]
  float v7; // [esp-30h] [ebp-3Ch]
  float v8; // [esp-2Ch] [ebp-38h]
  float v9; // [esp-2Ch] [ebp-38h]
  float v10; // [esp-28h] [ebp-34h]
  float v11; // [esp-28h] [ebp-34h]
  float v12; // [esp-20h] [ebp-2Ch]
  float v13; // [esp-20h] [ebp-2Ch]
  float v14; // [esp-1Ch] [ebp-28h]
  float v15; // [esp-1Ch] [ebp-28h]
  float v16; // [esp-18h] [ebp-24h]
  float v17; // [esp-18h] [ebp-24h]
  float v18; // [esp-10h] [ebp-1Ch]
  float v19; // [esp-10h] [ebp-1Ch]
  float v20; // [esp-10h] [ebp-1Ch]
  float v21; // [esp-10h] [ebp-1Ch]
  float v22; // [esp-10h] [ebp-1Ch]
  float v23; // [esp-10h] [ebp-1Ch]
  float v24; // [esp-10h] [ebp-1Ch]
  float v25; // [esp-10h] [ebp-1Ch]
  float v26; // [esp-10h] [ebp-1Ch]
  float v27; // [esp-10h] [ebp-1Ch]
  float v28; // [esp-10h] [ebp-1Ch]
  float v29; // [esp-10h] [ebp-1Ch]
  float v30; // [esp-10h] [ebp-1Ch]
  float v31; // [esp-Ch] [ebp-18h]
  float v32; // [esp-Ch] [ebp-18h]
  float v33; // [esp-8h] [ebp-14h]
  float v34; // [esp-8h] [ebp-14h]
  float v35; // [esp-4h] [ebp-10h]
  float v36; // [esp-4h] [ebp-10h]
  float v37; // [esp-4h] [ebp-10h]
  float v38; // [esp-4h] [ebp-10h]

  v18 = 1.0 - *(float *)(this + 464);
  v19 = pow(v18, a2);
  *(float *)(this + 320) = v19 * *(float *)(this + 320);
  *(float *)(this + 324) = v19 * *(float *)(this + 324);
  *(float *)(this + 328) = v19 * *(float *)(this + 328);
  v20 = 1.0 - *(float *)(this + 468);
  v21 = pow(v20, a2);
  v2 = v21;
  v22 = *(float *)(this + 336) * v21;
  v3 = v22;
  *(float *)(this + 336) = v22;
  v23 = v2 * *(float *)(this + 340);
  *(float *)(this + 340) = v23;
  v4 = v2 * *(float *)(this + 344);
  v5 = v23;
  v24 = v4;
  *(float *)(this + 344) = v24;
  if ( *(_BYTE *)(this + 472) )
  {
    v25 = v3 * v3 + v5 * v5 + v24 * v24;
    if ( *(float *)(this + 484) > (double)v25 )
    {
      v26 = *(float *)(this + 320) * *(float *)(this + 320)
          + *(float *)(this + 324) * *(float *)(this + 324)
          + *(float *)(this + 328) * *(float *)(this + 328);
      if ( *(float *)(this + 480) > (double)v26 )
      {
        *(float *)(this + 336) = *(float *)(this + 476) * *(float *)(this + 336);
        *(float *)(this + 340) = *(float *)(this + 476) * *(float *)(this + 340);
        *(float *)(this + 344) = *(float *)(this + 476) * *(float *)(this + 344);
        *(float *)(this + 320) = *(float *)(this + 476) * *(float *)(this + 320);
        *(float *)(this + 324) = *(float *)(this + 476) * *(float *)(this + 324);
        *(float *)(this + 328) = *(float *)(this + 476) * *(float *)(this + 328);
      }
    }
    v31 = *(float *)(this + 324);
    v33 = *(float *)(this + 320);
    v27 = *(float *)(this + 328);
    v35 = v33 * v33 + v31 * v31 + v27 * v27;
    v36 = sqrt(v35);
    if ( *(float *)(this + 464) > (double)v36 )
    {
      if ( v36 <= 0.0049999999 )
      {
        *(_DWORD *)(this + 320) = 0;
        *(_DWORD *)(this + 324) = 0;
        *(_DWORD *)(this + 328) = 0;
        *(_DWORD *)(this + 332) = 0;
      }
      else
      {
        v37 = 1.0 / v36;
        v12 = v33 * v37;
        v14 = v31 * v37;
        v16 = v37 * v27;
        v6 = v12 * 0.004999999888241291;
        v8 = v14 * 0.004999999888241291;
        v10 = 0.004999999888241291 * v16;
        *(float *)(this + 320) = v33 - v6;
        *(float *)(this + 324) = *(float *)(this + 324) - v8;
        *(float *)(this + 328) = *(float *)(this + 328) - v10;
      }
    }
    v34 = *(float *)(this + 340);
    v32 = *(float *)(this + 336);
    v38 = *(float *)(this + 344);
    v28 = v32 * v32 + v34 * v34 + v38 * v38;
    v29 = sqrt(v28);
    if ( *(float *)(this + 468) > (double)v29 )
    {
      if ( v29 <= 0.0049999999 )
      {
        *(_DWORD *)(this + 336) = 0;
        *(_DWORD *)(this + 340) = 0;
        *(_DWORD *)(this + 344) = 0;
        *(_DWORD *)(this + 348) = 0;
      }
      else
      {
        v30 = 1.0 / v29;
        v7 = v32 * v30;
        v9 = v34 * v30;
        v11 = v30 * v38;
        v13 = v7 * 0.004999999888241291;
        v15 = v9 * 0.004999999888241291;
        v17 = 0.004999999888241291 * v11;
        *(float *)(this + 336) = v32 - v13;
        *(float *)(this + 340) = *(float *)(this + 340) - v15;
        *(float *)(this + 344) = *(float *)(this + 344) - v17;
      }
    }
  }
}

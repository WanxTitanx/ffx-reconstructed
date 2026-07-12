// Function: sub_A59E80
// Address: 0xa59e80
// Size: 0x198
// Prototype: 

int sub_A59E80()
{
  int v0; // esi
  int v1; // ecx
  _DWORD *v2; // ecx
  int result; // eax
  _DWORD *v4; // ecx
  float v5; // [esp+8h] [ebp-28h]
  int v6[4]; // [esp+Ch] [ebp-24h] BYREF
  int v7; // [esp+1Ch] [ebp-14h] BYREF
  float v8; // [esp+20h] [ebp-10h]
  float v9; // [esp+24h] [ebp-Ch]
  float v10; // [esp+28h] [ebp-8h]

  v0 = dword_2305834[0];
  v1 = 5 * *(unsigned __int16 *)(dword_2305834[0] + 71220);
  *(float *)&v7 = (float)*(__int16 *)(dword_2305834[0] + 40 * *(unsigned __int16 *)(dword_2305834[0] + 71220) + 2056);
  v8 = (float)*(__int16 *)(dword_2305834[0] + 8 * v1 + 2058);
  v9 = 0.0;
  v10 = 1.0;
  v5 = *(float *)(dword_2305834[0] + 71204) + *(float *)(dword_2305834[0] + 71200);
  *(float *)(dword_2305834[0] + 71200) = v5;
  if ( v5 < 1.0 )
  {
    sub_62FF20((int)v6, (int)&v7, dword_2305834[0] + 71228, v5);
    *(float *)(v0 + 70328) = *(float *)v6;
    *(float *)(v0 + 70332) = *(float *)&v6[1];
    *(float *)(v0 + 70388) = (*(float *)(dword_2305834[0] + 71212) - *(float *)(dword_2305834[0] + 71208))
                           * *(float *)(dword_2305834[0] + 71200)
                           + *(float *)(dword_2305834[0] + 71208);
    v4 = (_DWORD *)dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 70408) = *(_DWORD *)(dword_2305834[0] + 70328);
    v4[17603] = v4[17583];
    v4[17604] = v4[17584];
    result = v4[17585];
    v4[17605] = result;
  }
  else
  {
    *(float *)(v0 + 70328) = *(float *)&v7;
    *(float *)(v0 + 70332) = v8;
    v2 = (_DWORD *)dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 70408) = *(_DWORD *)(v0 + 70328);
    v2[17603] = *(_DWORD *)(v0 + 70332);
    v2[17604] = *(_DWORD *)(v0 + 70336);
    v2[17605] = *(_DWORD *)(v0 + 70340);
    *(float *)(v0 + 70388) = *(float *)(dword_2305834[0] + 71212);
    *(_DWORD *)(dword_2305834[0] + 71080) = *(_DWORD *)(dword_2305834[0] + 71088);
    result = dword_2305834[0];
    *(_DWORD *)(dword_2305834[0] + 71088) = 0;
  }
  return result;
}


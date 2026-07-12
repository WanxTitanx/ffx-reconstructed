// Function: sub_9D14D0
// Address: 0x9d14d0
int __thiscall sub_9D14D0(int this)
{
  float v2; // [esp-40h] [ebp-4Ch]
  float v3; // [esp-3Ch] [ebp-48h]
  float v4; // [esp-38h] [ebp-44h]
  float v5; // [esp-30h] [ebp-3Ch]
  float v6; // [esp-2Ch] [ebp-38h]
  float v7; // [esp-28h] [ebp-34h]
  float v8; // [esp-20h] [ebp-2Ch]
  float v9; // [esp-1Ch] [ebp-28h]
  float v10; // [esp-18h] [ebp-24h]
  float v11; // [esp-8h] [ebp-14h]
  float v12; // [esp-4h] [ebp-10h]

  if ( *(float *)(*(_DWORD *)(this + 24) + 352) == 0.0 )
    v12 = 1.0;
  else
    v12 = *(float *)(*(_DWORD *)(this + 20) + 352)
        / (*(float *)(*(_DWORD *)(this + 24) + 352) + *(float *)(*(_DWORD *)(this + 20) + 352));
  v11 = 1.0 - v12;
  v2 = *(float *)(this + 1280) * v11;
  v3 = *(float *)(this + 1284) * v11;
  v4 = v11 * *(float *)(this + 1288);
  v5 = *(float *)(this + 1216) * v12;
  v6 = *(float *)(this + 1220) * v12;
  v7 = v12 * *(float *)(this + 1224);
  v8 = v5 + v2;
  *(float *)(this + 1392) = v8;
  v9 = v6 + v3;
  *(float *)(this + 1396) = v9;
  v10 = v7 + v4;
  *(float *)(this + 1400) = v10;
  *(_DWORD *)(this + 1404) = 0;
  return 0;
}

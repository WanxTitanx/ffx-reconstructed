// Function: sub_920100
// Address: 0x920100
int __cdecl sub_920100(float a1)
{
  int v1; // eax
  double v2; // st7
  _BYTE v4[8]; // [esp+0h] [ebp-24h] BYREF
  int v5; // [esp+8h] [ebp-1Ch]
  float v6; // [esp+10h] [ebp-14h] BYREF
  float v7; // [esp+14h] [ebp-10h]
  float v8; // [esp+18h] [ebp-Ch]
  float v9; // [esp+1Ch] [ebp-8h]

  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 && (v1 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8)) != 0 )
  {
    v6 = 0.0;
    v7 = 0.0;
    v2 = *(float *)(v1 + 244) * a1;
  }
  else
  {
    v6 = 0.0;
    v7 = 0.0;
    v2 = a1 * 10.0;
  }
  v8 = v2;
  v9 = 1.0;
  sub_6ED420(&v6, &src_, &v6);
  v8 = v8 / v9;
  nullsub_51(v4, &v6);
  return v5 / 12288;
}

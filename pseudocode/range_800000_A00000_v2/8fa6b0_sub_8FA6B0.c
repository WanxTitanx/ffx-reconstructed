// Function: sub_8FA6B0
// Address: 0x8fa6b0
double __cdecl sub_8FA6B0(float a1, float a2)
{
  double v2; // st7
  int v4; // [esp+0h] [ebp-Ch] BYREF
  float v5; // [esp+4h] [ebp-8h]
  int v6; // [esp+8h] [ebp-4h] BYREF
  float v7; // [esp+14h] [ebp+8h]

  v2 = unk_187166C;
  if ( 0.0 == unk_187166C )
  {
    sub_640F60(&v6, &v4);
    v5 = (float)v6;
    unk_1871668 = v5 * 0.001953125;
    v5 = (float)v4;
    unk_187166C = v5 / 416.0;
    v2 = unk_187166C;
  }
  v7 = (float)(int)(v2 * (a1 * a2) + 0.5);
  return (float)(v7 / unk_1871668);
}

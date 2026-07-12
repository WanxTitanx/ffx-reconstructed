// Function: sub_9201A0
// Address: 0x9201a0
int __cdecl sub_9201A0(float a1)
{
  int v1; // eax
  double v2; // st7
  float v4; // [esp+4h] [ebp-14h] BYREF
  float v5; // [esp+8h] [ebp-10h]
  float v6; // [esp+Ch] [ebp-Ch]
  float v7; // [esp+10h] [ebp-8h]

  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 && (v1 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8)) != 0 )
  {
    v4 = 0.0;
    v5 = 0.0;
    v2 = *(float *)(v1 + 244) * a1;
  }
  else
  {
    v4 = 0.0;
    v5 = 0.0;
    v2 = a1 * 10.0;
  }
  v6 = v2;
  v7 = 1.0;
  sub_6ED420(&v4, &src_, &v4);
  return (__int64)(v6 / v7);
}

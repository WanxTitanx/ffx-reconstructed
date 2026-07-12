// Function: sub_93D5A0
// Address: 0x93d5a0
int __cdecl sub_93D5A0(int a1, int a2, float a3)
{
  float v4; // [esp+8h] [ebp-4Ch]
  float v5; // [esp+Ch] [ebp-48h]
  float v6[16]; // [esp+10h] [ebp-44h] BYREF

  sub_93D900(v6);
  v5 = cos(a3);
  v6[5] = v5;
  v4 = sin(a3);
  v6[6] = -v4;
  v6[9] = v4;
  v6[10] = v5;
  return sub_93D1B0(a1, v6, a2);
}

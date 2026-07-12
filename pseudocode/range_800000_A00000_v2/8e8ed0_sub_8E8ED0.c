// Function: sub_8E8ED0
// Address: 0x8e8ed0
void __cdecl sub_8E8ED0(int a1, int a2, float a3)
{
  double v3; // st7
  double v5; // st7
  double v6; // st7
  double v7; // [esp+Ch] [ebp-10h] BYREF
  float v8; // [esp+14h] [ebp-8h]
  int v9; // [esp+18h] [ebp-4h] BYREF
  float v10; // [esp+24h] [ebp+8h]
  float v11; // [esp+24h] [ebp+8h]

  v3 = unk_1871668;
  if ( 0.0 == unk_1871668 )
  {
    sub_640F60(&v9, (char *)&v7 + 4);
    v8 = (float)v9;
    unk_1871668 = v8 * 0.001953125;
    v8 = (float)SHIDWORD(v7);
    unk_187166C = v8 / 416.0;
    v3 = unk_1871668;
  }
  v10 = v3 * *(float *)(a1 + 4);
  v11 = (float)(int)(v10 + 0.5);
  *(float *)(a1 + 4) = v11 / unk_1871668;
  v5 = *(float *)(a2 + 28);
  sub_8FA6B0(*(float *)(a2 + 28), a3);
  v7 = v5;
  v6 = sub_8FA570(*(_BYTE *)(a1 + 26));
  *(float *)(a1 + 4) = v6 + v7 + *(float *)(a1 + 4);
}

// Function: sub_813100
// Address: 0x813100
int __cdecl sub_813100(int a1)
{
  int v1; // esi
  int v2; // eax
  float v4; // [esp+4h] [ebp-14h]
  float v5; // [esp+8h] [ebp-10h]
  float v6; // [esp+Ch] [ebp-Ch]
  float v7; // [esp+20h] [ebp+8h]
  float v8; // [esp+20h] [ebp+8h]
  float v9; // [esp+20h] [ebp+8h]
  float v10; // [esp+20h] [ebp+8h]

  v1 = *(_DWORD *)(a1 + 544);
  v2 = FFX_MagicHost_ClassifyPppOpcodeByte(*(char *)(v1 + 168));
  v7 = *(float *)(v1 + 76) / 255.0;
  v6 = v7;
  v8 = *(float *)(v1 + 72) * 0.0078125;
  v5 = v8;
  v9 = *(float *)(v1 + 68) * 0.0078125;
  v4 = v9;
  v10 = 0.0078125 * *(float *)(v1 + 64);
  sub_6393F0(v10, v4, v5, v6, v2);
  return sub_646010(2049);
}

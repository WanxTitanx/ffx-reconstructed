// Function: sub_80F7E0
// Address: 0x80f7e0
int __cdecl sub_80F7E0(int a1)
{
  int v1; // esi
  int v2; // eax
  float v4; // [esp+4h] [ebp-18h]
  float v5; // [esp+4h] [ebp-18h]
  float v6; // [esp+8h] [ebp-14h]
  float v7; // [esp+Ch] [ebp-10h]
  float v8; // [esp+Ch] [ebp-10h]
  float v9; // [esp+24h] [ebp+8h]
  float v10; // [esp+24h] [ebp+8h]
  float v11; // [esp+24h] [ebp+8h]
  float v12; // [esp+24h] [ebp+8h]
  float v13; // [esp+24h] [ebp+8h]
  float v14; // [esp+24h] [ebp+8h]
  float v15; // [esp+24h] [ebp+8h]
  float v16; // [esp+24h] [ebp+8h]

  v1 = *(_DWORD *)(a1 + 544);
  if ( FFX_Btl_GetCurrentBattleFormationId() == 604 || FFX_Btl_GetCurrentBattleFormationId() == 615 )
    *(_DWORD *)(v1 + 200) = 0;
  sub_6392C0(0);
  v9 = (double)*(unsigned __int8 *)(v1 + 203) * 0.0078125;
  v7 = v9;
  v10 = (double)*(unsigned __int8 *)(v1 + 202) * 0.0078125;
  v6 = v10;
  v11 = (double)*(unsigned __int8 *)(v1 + 201) * 0.0078125;
  v4 = v11;
  v12 = 0.0078125 * (double)*(unsigned __int8 *)(v1 + 200);
  sub_6439E0(v12, v4, v6, v7);
  v13 = *(float *)(v1 + 52) * 2.0 * 0.001953125;
  v8 = v13;
  v14 = 0.001953125 * (2.0 * *(float *)(v1 + 48));
  sub_643A40(v14, v8);
  v15 = *(float *)(v1 + 148) / 416.0 + 0.5;
  v5 = v15;
  v16 = *(float *)(v1 + 144) * 0.001953125 + 0.5;
  sub_643A10(v16, v5, 0.0, 0.0);
  v2 = FFX_MagicHost_ClassifyPppOpcodeByte(*(unsigned __int8 *)(v1 + 194));
  return sub_6439C0(v2);
}

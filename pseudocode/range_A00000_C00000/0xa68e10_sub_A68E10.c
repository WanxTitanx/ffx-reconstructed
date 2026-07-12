// Function: sub_A68E10
// Address: 0xa68e10
// Size: 0x1d6
// Prototype: int __cdecl(int, int, int, int, int, int, float, int)

int __cdecl sub_A68E10(int a1, _DWORD *a2, int a3, void *a4, int a5, int a6, float a7, int a8)
{
  void *v8; // eax
  int *v9; // edi
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v20; // [esp-38h] [ebp-124h]
  int v21; // [esp-8h] [ebp-F4h]
  int v22; // [esp-4h] [ebp-F0h]
  int v23; // [esp+0h] [ebp-ECh]
  int v24; // [esp+4h] [ebp-E8h]
  int v25; // [esp+20h] [ebp-CCh]
  int v26; // [esp+24h] [ebp-C8h]
  _BYTE v27[64]; // [esp+28h] [ebp-C4h] BYREF
  _BYTE v28[56]; // [esp+68h] [ebp-84h] BYREF
  float v29; // [esp+A0h] [ebp-4Ch]
  _BYTE v30[64]; // [esp+A8h] [ebp-44h] BYREF

  v25 = a2[8]; /*0xa68e43*/
  v8 = a4; /*0xa68e55*/
  a2[8] = v27; /*0xa68e58*/
  a2[11] = v30; /*0xa68e5f*/
  if ( !a4 ) /*0xa68e64*/
    v8 = &unk_113FCB0; /*0xa68e66*/
  sub_7E7F20(v28, v8); /*0xa68e73*/
  if ( FFX_Btl_GetCurrentBattleFormationId() == 437 || FFX_Btl_GetCurrentBattleFormatio... [2710 chars total]
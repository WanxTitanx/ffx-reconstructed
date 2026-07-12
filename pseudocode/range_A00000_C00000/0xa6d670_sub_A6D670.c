// Function: sub_A6D670
// Address: 0xa6d670
// Size: 0x21d
// Prototype: 

int __usercall sub_A6D670@<eax>(int a1@<ebp>, int a2, int a3, float *a4, int a5)
{
  int result; // eax
  int v6; // eax
  int v7; // ecx
  int v8; // edi
  float v9; // [esp+24h] [ebp-214h]
  float v10; // [esp+28h] [ebp-210h]
  _BYTE v11[64]; // [esp+ACh] [ebp-18Ch] BYREF
  _BYTE v12[80]; // [esp+ECh] [ebp-14Ch] BYREF
  int v13; // [esp+13Ch] [ebp-FCh] BYREF
  int v14; // [esp+140h] [ebp-F8h] BYREF
  int v15; // [esp+144h] [ebp-F4h] BYREF
  _BYTE v16[64]; // [esp+154h] [ebp-E4h] BYREF
  _BYTE dst[64]; // [esp+194h] [ebp-A4h] BYREF
  float dst_1[17]; // [esp+1D4h] [ebp-64h] BYREF
  float v19; // [esp+218h] [ebp-20h] BYREF
  float v20; // [esp+21Ch] [ebp-1Ch]
  float v21; // [esp+220h] [ebp-18h]
  float v22; // [esp+224h] [ebp-14h]
  int v23; // [esp+22Ch] [ebp-Ch]
  void *v24; // [esp+230h] [ebp-8h]
  void *retaddr; // [esp+238h] [ebp+0h]

  v23 = a1;
  v24 = retaddr;
  result = a5;
  if ( a5 )
  {
    sub_82EB70(a5, &v13, &v14, &v15);
    qmemcpy(dst, *(const void **)(a3 + 40), sizeof(dst));
    qmemcpy(dst_1, *(const void **)(a3 + 44), 0x40u);
    dst_1[0] = -dst_1[0];
    dst_1[1] = -dst_1[1];
    dst_1[4] = -dst_1[4];
    dst_1[5] = -dst_1[5];
    dst_1[8] = -dst_1[8];
    dst_1[9] = -dst_1[9];
    dst_1[12] = -dst_1[12];
    dst_1[13] = -dst_1[13];
    sub_A691C0(v11, v12);
    sub_A6CD80((int)v12, (int)v12, (int)dst_1);
    sub_6ED5A0(v16, *(_DWORD *)(a3 + 44));
    sub_6ED700(dst, v16, dst);
    sub_6ED700(dst, dst_1, dst);
    v6 = sub_826BF0(a5);
    v7 = *(unsigned __int8 *)(a3 + 76);
    v8 = v6;
    v9 = (float)*(unsigned __int8 *)(a3 + 77);
    v20 = 0.0;
    v21 = 0.0;
    v22 = 0.0;
    v10 = (float)v7;
    v19 = a4[220] * 0.0078125;
    v20 = a4[221] * 0.0078125;
    v21 = a4[222] * 0.0078125;
    v22 = 0.0078125 * a4[223];
    if ( FFX_Btl_GetCurrentBattleFormationId() == 581 )
    {
      v20 = 1.0;
      v19 = 1.0;
      v21 = 0.5;
    }
    return sub_642900(v8, 0, (int)dst, *(_DWORD *)(a3 + 36), v9, (int)v12, (int)v11, v10, (int)&v13, (int)&v19, 1);
  }
  return result;
}


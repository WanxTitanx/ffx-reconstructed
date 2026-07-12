// Function: sub_A6D380
// Address: 0xa6d380
// Size: 0x2e3
// Prototype: int __cdecl(_DWORD, _DWORD, _DWORD, _DWORD)

int __usercall sub_A6D380@<eax>(int a1@<ebp>, int a2, int a3, int a4, int a5)
{
  const void *src; // eax
  int v6; // esi
  int result; // eax
  int v8; // esi
  _BYTE *NameFromModelSlot; // eax
  double v10; // st7
  int v11; // [esp+24h] [ebp-114h]
  BOOL v12; // [esp+28h] [ebp-110h]
  float v13; // [esp+2Ch] [ebp-10Ch]
  int v14; // [esp+30h] [ebp-108h]
  int v15; // [esp+30h] [ebp-108h]
  int v16; // [esp+38h] [ebp-100h]
  float v17; // [esp+38h] [ebp-100h]
  int v18; // [esp+3Ch] [ebp-FCh] BYREF
  int v19; // [esp+40h] [ebp-F8h] BYREF
  int v20; // [esp+44h] [ebp-F4h] BYREF
  _BYTE v21[64]; // [esp+54h] [ebp-E4h] BYREF
  _BYTE dst[64]; // [esp+94h] [ebp-A4h] BYREF
  float dst_1[17]; // [esp+D4h] [ebp-64h] BYREF
  float v24; // [esp+118h] [ebp-20h] BYREF
  float v25; // [esp+11Ch] [ebp-1Ch]
  float v26; // [esp+120h] [ebp-18h]
  float v27; // [esp+124h] [ebp-14h]
  int v28; // [esp+12Ch] [ebp-Ch]
  void *v29; // [esp+130h] [ebp-8h]
  void *retaddr; // [esp+138h] [ebp+0h]

  v28 = a1;
  v29 = retaddr;
  v14 = *(_DWORD *)(a4 + 912);
  src = *(const void **)(a3 + 44);
  qmemcpy(dst, *(const void **)(a3 + 40), sizeof(dst));
  qmemcpy(dst_1, src, 0x40u);
  dst_1[0] = -dst_1[0];
  dst_1[1] = -dst_1[1];
  dst_1[4] = -dst_1[4];
  dst_1[5] = -dst_1[5];
  dst_1[8] = -dst_1[8];
  dst_1[9] = -dst_1[9];
  dst_1[12] = -dst_1[12];
  dst_1[13] = -dst_1[13];
  sub_6ED5A0(v21, src);
  sub_6ED700(dst, v21, dst);
  sub_6ED700(dst, dst_1, dst);
  v6 = v14 + 192;
  v11 = v14 + 192;
  v15 = v14 + 128;
  sub_A690C0(v15, v6);
  sub_A6CD80(v6, v6, (int)dst_1);
  unk_C8F52C = unk_11A0004;
  unk_C8F530 = unk_11A0008;
  unk_C8F534 = unk_11A000C;
  *(_DWORD *)(a4 + 640) = unk_11A0000;
  *(_DWORD *)(a4 + 644) = unk_C8F52C;
  *(_DWORD *)(a4 + 648) = unk_C8F530;
  *(_DWORD *)(a4 + 652) = unk_C8F534;
  unk_C8F52C = unk_11A0034;
  unk_C8F530 = unk_11A0038;
  unk_C8F534 = unk_11A003C;
  MEMORY[0xC8F528] = unk_11A0030;
  *(_DWORD *)(a4 + 656) = unk_11A0030;
  *(_DWORD *)(a4 + 660) = unk_C8F52C;
  *(_DWORD *)(a4 + 664) = unk_C8F530;
  *(_DWORD *)(a4 + 668) = unk_C8F534;
  result = a5;
  if ( a5 )
  {
    v8 = sub_826BF0(a5);
    NameFromModelSlot = (_BYTE *)FFX_MagicPath_GetNameFromModelSlot(a5);
    v10 = *(float *)(a4 + 880) * 0.0078125;
    v25 = 0.0;
    v26 = 0.0;
    v24 = v10;
    v27 = 0.0;
    v25 = *(float *)(a4 + 884) * 0.0078125;
    v26 = *(float *)(a4 + 888) * 0.0078125;
    v16 = *(unsigned __int8 *)(a3 + 77);
    v27 = 0.0078125 * *(float *)(a4 + 892);
    v13 = (float)v16;
    v17 = (float)*(unsigned __int8 *)(a3 + 76);
    v12 = *NameFromModelSlot == 119;
    sub_82EB70(a5, &v18, &v19, &v20);
    return sub_642900(v8, v12, (int)dst, *(_DWORD *)(a3 + 36), v13, v11, v15, v17, (int)&v18, (int)&v24, 0);
  }
  return result;
}


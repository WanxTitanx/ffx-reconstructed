// Function: sub_A4C700
// Address: 0xa4c700
// Size: 0x1c8
// Prototype: 

int __usercall sub_A4C700@<eax>(int a1@<ebp>)
{
  _DWORD *v1; // edi
  _DWORD v3[2]; // [esp-140h] [ebp-14Ch] BYREF
  __int16 n72; // [esp-138h] [ebp-144h]
  char v5; // [esp-136h] [ebp-142h]
  int v6; // [esp-134h] [ebp-140h]
  int v7; // [esp-130h] [ebp-13Ch]
  int v8; // [esp-12Ch] [ebp-138h]
  int n1077952576; // [esp-128h] [ebp-134h]
  int v10; // [esp-124h] [ebp-130h]
  _BYTE *v11; // [esp-120h] [ebp-12Ch]
  int v12; // [esp-11Ch] [ebp-128h]
  int v13; // [esp-118h] [ebp-124h]
  _BYTE *v14; // [esp-114h] [ebp-120h]
  int v15; // [esp-108h] [ebp-114h]
  int v16; // [esp-104h] [ebp-110h]
  int v17; // [esp-100h] [ebp-10Ch]
  _DWORD *v18; // [esp-FCh] [ebp-108h]
  _BYTE v19[64]; // [esp-C8h] [ebp-D4h] BYREF
  _BYTE v20[64]; // [esp-88h] [ebp-94h] BYREF
  _DWORD v21[21]; // [esp-48h] [ebp-54h] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v21[18] = a1;
  v21[19] = retaddr;
  v1 = (_DWORD *)sub_785350();
  v11 = v19;
  v18 = v21;
  v14 = v20;
  *(float *)&v21[14] = 7.0;
  v21[3] = unk_C8F514;
  *(float *)&v21[15] = 1.0;
  v21[7] = unk_C8F514;
  v21[11] = unk_C8F514;
  v3[0] = 52;
  n1077952576 = 1077952576;
  v10 = 0;
  v5 = 0;
  v16 = 0;
  v15 = 0;
  v3[1] = byte_1740830;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v17 = 0;
  v13 = 0;
  v12 = 0;
  v21[0] = unk_C8F508[0];
  v21[1] = unk_C8F50C;
  v21[2] = unk_C8F510;
  v21[4] = unk_C8F508[0];
  v21[5] = unk_C8F50C;
  v21[6] = unk_C8F510;
  v21[8] = unk_C8F508[0];
  v21[9] = unk_C8F50C;
  v21[10] = unk_C8F510;
  v21[12] = unk_C8F508[0];
  v21[13] = unk_C8F50C;
  sub_6EDAE0(v20);
  sub_6ED700(v19, dword_2305834[0] + 70624, v20);
  if ( (*v1 & 0xC000) == 0x8000 )
  {
    n72 = 72;
    return sub_A657C0(unk_23056EC, v3, 8);
  }
  else
  {
    n72 = 68;
    return sub_A657C0(unk_23056F0, v3, 8);
  }
}


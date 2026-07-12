// Function: sub_8B0AC0
// Address: 0x8b0ac0
int __usercall sub_8B0AC0@<eax>(int a1@<ebp>, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // eax
  int v10; // [esp-38h] [ebp-44h]
  int v11; // [esp-34h] [ebp-40h]
  _DWORD v12[15]; // [esp-30h] [ebp-3Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v12[12] = a1;
  v12[13] = retaddr;
  v8 = sub_62F890(2);
  v10 = v8;
  v12[2] = 0;
  v12[3] = 0;
  v12[0] = 805306374;
  v12[1] = &n4_6;
  switch ( a4 )
  {
    case 0:
      v8 = 4 * a8 * a7;
      break;
    case 1:
      v8 = 3 * a8 * a7;
      break;
    case 2:
    case 10:
      v8 = 2 * a8 * a7;
      break;
    case 19:
    case 27:
      v8 = a8 * a7;
      break;
    case 20:
    case 36:
    case 44:
      v8 = a8 * (a7 / 2);
      break;
    default:
      break;
  }
  v12[4] = v8 / 16;
  v12[6] = 0;
  v12[7] = 0;
  v12[5] = a2;
  n4_6 = 4;
  n0x10000000 = 0x10000000;
  n14 = 14;
  unk_1865E6C = 0;
  v11 = a7 / 64;
  if ( !(a7 / 64) )
    v11 = 1;
  unk_1865E74 = a3 | ((v11 | (a4 << 8)) << 16);
  unk_1865E84 = a5 | (a6 << 16);
  unk_1865E70 = 0;
  n80 = 80;
  unk_1865E7C = 0;
  unk_1865E80 = 0;
  n81 = 81;
  unk_1865E8C = 0;
  unk_1865E90 = a7;
  unk_1865E94 = (a7 >> 31) | a8;
  n82 = 82;
  unk_1865E9C = 0;
  unk_1865EA0 = 0;
  unk_1865EA4 = 0;
  n83 = 83;
  unk_1865EAC = 0;
  qword_1865EB0 = (v8 / 16) | 0x800000000008000LL;
  n84 = 84;
  unk_1865EBC = 0;
  nullsub_33(0);
  sub_62FA30(0, 0);
  nullsub_39(v10, v12);
  return sub_62FA30(0, 0);
}

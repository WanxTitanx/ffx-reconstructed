// FFX Menu: Item list scroll
int __cdecl FFX_Menu_ItemListScroll(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // eax
  int v10; // [esp-34h] [ebp-40h]

  v8 = FFX_RenderStub_Return0(); /*0x8b0ae7*/
  switch ( a3 ) /*0x8b0b23*/
  {
    case 0: /*0x8b0b23*/
      v8 = 4 * a7 * a6; /*0x8b0b2f*/
      break; /*0x8b0b32*/
    case 1: /*0x8b0b23*/
      v8 = 3 * a7 * a6; /*0x8b0b39*/
      break; /*0x8b0b3c*/
    case 2: /*0x8b0b23*/
    case 10: /*0x8b0b23*/
      v8 = 2 * a7 * a6; /*0x8b0b43*/
      break; /*0x8b0b45*/
    case 19: /*0x8b0b23*/
    case 27: /*0x8b0b23*/
      v8 = a7 * a6; /*0x8b0b49*/
      break; /*0x8b0b4c*/
    case 20: /*0x8b0b23*/
    case 36: /*0x8b0b23*/
    case 44: /*0x8b0b23*/
      v8 = a7 * (a6 / 2); /*0x8b0b55*/
      break; /*0x8b0b55*/
    default:
      break; // Switch on FFX_MenuAction — item scroll layout multiplier
  }
  n4_66 = 4; /*0x8b0b5d*/
  n0x10000000 = 0x10000000; // Flag write: 0x10000000 render slot /*0x8b0b95*/
  n14_0 = 14; /*0x8b0b9f*/
  unk_1865E6C = 0; /*0x8b0ba9*/
  v10 = a6 / 64; /*0x8b0bb3*/
  if ( !(a6 / 64) ) /*0x8b0b7c*/
    v10 = 1; /*0x8b0bba*/
  unk_1865E74 = a2 | ((v10 | (a3 << 8)) << 16); /*0x8b0bfb*/
  unk_1865E84 = a4 | (a5 << 16); /*0x8b0c03*/
  unk_1865E70 = 0; /*0x8b0c23*/
  n80 = 80; /*0x8b0c2d*/
  unk_1865E7C = 0; /*0x8b0c37*/
  unk_1865E80 = 0; /*0x8b0c41*/
  n81 = 81; /*0x8b0c4b*/
  unk_1865E8C = 0; /*0x8b0c55*/
  unk_1865E90 = a6; /*0x8b0c5f*/
  unk_1865E94 = (a6 >> 31) | a7; /*0x8b0c65*/
  n82 = 82; /*0x8b0c6b*/
  unk_1865E9C = 0; /*0x8b0c75*/
  unk_1865EA0 = 0; /*0x8b0c7f*/
  unk_1865EA4 = 0; /*0x8b0c89*/
  n83 = 83; /*0x8b0c93*/
  unk_1865EAC = 0; /*0x8b0c9d*/
  Flag_write__OR_0x800000000008000__quad_dimensions_ = (v8 / 16) | 0x800000000008000LL;// Flag write: OR 0x800000000008000 (quad dimensions) /*0x8b0ca7*/
  n84 = 84; /*0x8b0cb2*/
  unk_1865EBC = 0; /*0x8b0cbc*/
  FlushCache(); /*0x8b0cc6*/
  FFX_GenericStub_Return0(); /*0x8b0ccf*/
  sceDmaSend(); /*0x8b0cdb*/
  return FFX_GenericStub_Return0(); /*0x8b0cfb*/
}
// Function: sub_8A1060
// Address: 0x8a1060
int __cdecl sub_8A1060(int a1)
{
  int result; // eax
  float v3; // [esp+10h] [ebp+8h]
  float v4; // [esp+10h] [ebp+8h]
  float v5; // [esp+10h] [ebp+8h]
  float v6; // [esp+10h] [ebp+8h]
  float v7; // [esp+10h] [ebp+8h]
  float v8; // [esp+10h] [ebp+8h]
  float v9; // [esp+10h] [ebp+8h]
  float v10; // [esp+10h] [ebp+8h]

  switch ( *(_WORD *)(a1 + 6) )
  {
    case 0:
    case 0xC:
    case 0xD:
      *(float *)(a1 + 104) = FFX_Menu2D_ScaleX_1920to512(154.0);
      *(float *)(a1 + 108) = FFX_Menu2D_ScaleY_1080to416(808.0);
      *(float *)(a1 + 112) = FFX_Menu2D_ScaleX_1920to512(574.0);
      *(float *)(a1 + 116) = FFX_Menu2D_ScaleY_1080to416(962.0);
      *(float *)(a1 + 124) = FFX_Menu2D_ScaleY_1080to416(811.0);
      *(float *)(a1 + 132) = FFX_Menu2D_ScaleY_1080to416(962.0);
      *(float *)(a1 + 120) = FFX_Menu2D_ScaleX_1920to512(191.0);
      *(float *)(a1 + 128) = *(float *)(a1 + 112);
      *(_WORD *)(a1 + 102) = (int)FFX_Menu2D_ScaleX_1920to512(300.0);
      *(_WORD *)(a1 + 98) = (int)FFX_Menu2D_ScaleX_1920to512(420.0);
      *(_DWORD *)(a1 + 40) = 1;
      *(_WORD *)(a1 + 44) = 4096;
      goto LABEL_9;
    case 1:
    case 2:
      v3 = 154.0 + 0.0;
      *(float *)(a1 + 104) = FFX_Menu2D_ScaleX_1920to512(v3);
      v4 = 835.0 + 0.0;
      *(float *)(a1 + 108) = FFX_Menu2D_ScaleY_1080to416(v4);
      *(float *)(a1 + 112) = FFX_Menu2D_ScaleX_1920to512(994.0);
      *(float *)(a1 + 116) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 124) = FFX_Menu2D_ScaleY_1080to416(838.0);
      *(float *)(a1 + 132) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 120) = FFX_Menu2D_ScaleX_1920to512(191.0);
      *(float *)(a1 + 128) = *(float *)(a1 + 112);
      *(_WORD *)(a1 + 102) = (int)FFX_Menu2D_ScaleX_1920to512(284.0);
      *(_WORD *)(a1 + 98) = (int)FFX_Menu2D_ScaleX_1920to512(420.0);
      *(_DWORD *)(a1 + 40) = 3;
      *(_DWORD *)(a1 + 44) = 268435712;
      *(_WORD *)(a1 + 48) = 1027;
      *(_DWORD *)(a1 + 56) = 196610;
      break;
    case 3:
    case 4:
    case 0xE:
      v5 = 154.0 + 0.0;
      *(float *)(a1 + 104) = FFX_Menu2D_ScaleX_1920to512(v5);
      v6 = 835.0 + 0.0;
      *(float *)(a1 + 108) = FFX_Menu2D_ScaleY_1080to416(v6);
      *(float *)(a1 + 112) = FFX_Menu2D_ScaleX_1920to512(994.0);
      *(float *)(a1 + 116) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 124) = FFX_Menu2D_ScaleY_1080to416(838.0);
      *(float *)(a1 + 132) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 120) = FFX_Menu2D_ScaleX_1920to512(191.0);
      *(float *)(a1 + 128) = *(float *)(a1 + 112);
      *(_WORD *)(a1 + 102) = (int)FFX_Menu2D_ScaleX_1920to512(284.0);
      *(_WORD *)(a1 + 98) = (int)FFX_Menu2D_ScaleX_1920to512(420.0);
      *(_DWORD *)(a1 + 40) = 3;
      *(_DWORD *)(a1 + 44) = 268435712;
      *(_WORD *)(a1 + 48) = 1026;
      *(_DWORD *)(a1 + 56) = 196610;
      break;
    case 5:
    case 0xA:
      *(float *)(a1 + 104) = FFX_Menu2D_ScaleX_1920to512(154.0);
      *(float *)(a1 + 108) = FFX_Menu2D_ScaleY_1080to416(835.0);
      *(float *)(a1 + 112) = FFX_Menu2D_ScaleX_1920to512(574.0);
      *(float *)(a1 + 116) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 124) = FFX_Menu2D_ScaleY_1080to416(838.0);
      *(float *)(a1 + 132) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 120) = FFX_Menu2D_ScaleX_1920to512(191.0);
      *(float *)(a1 + 128) = *(float *)(a1 + 112);
      *(_WORD *)(a1 + 102) = (int)FFX_Menu2D_ScaleX_1920to512(300.0);
      *(_WORD *)(a1 + 98) = (int)FFX_Menu2D_ScaleX_1920to512(420.0);
      *(_DWORD *)(a1 + 40) = 65537;
      *(_WORD *)(a1 + 44) = 4096;
      goto LABEL_9;
    case 6:
    case 0x11:
    case 0x14:
      v7 = 154.0 + 0.0;
      *(float *)(a1 + 104) = FFX_Menu2D_ScaleX_1920to512(v7);
      v8 = 835.0 + 0.0;
      *(float *)(a1 + 108) = FFX_Menu2D_ScaleY_1080to416(v8);
      *(float *)(a1 + 112) = FFX_Menu2D_ScaleX_1920to512(994.0);
      *(float *)(a1 + 116) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 124) = FFX_Menu2D_ScaleY_1080to416(838.0);
      *(float *)(a1 + 132) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 120) = FFX_Menu2D_ScaleX_1920to512(191.0);
      *(float *)(a1 + 128) = *(float *)(a1 + 112);
      *(_WORD *)(a1 + 102) = (int)FFX_Menu2D_ScaleX_1920to512(280.0);
      *(_WORD *)(a1 + 98) = (int)FFX_Menu2D_ScaleX_1920to512(420.0);
      *(_DWORD *)(a1 + 40) = 65539;
      *(_DWORD *)(a1 + 44) = 268435712;
      *(_WORD *)(a1 + 48) = 514;
      *(_DWORD *)(a1 + 56) = 196610;
      break;
    case 7:
    case 0xF:
      v9 = 154.0 + 0.0;
      *(float *)(a1 + 104) = FFX_Menu2D_ScaleX_1920to512(v9);
      v10 = 835.0 + 0.0;
      *(float *)(a1 + 108) = FFX_Menu2D_ScaleY_1080to416(v10);
      *(float *)(a1 + 112) = FFX_Menu2D_ScaleX_1920to512(574.0);
      *(float *)(a1 + 116) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 124) = FFX_Menu2D_ScaleY_1080to416(838.0);
      *(float *)(a1 + 132) = FFX_Menu2D_ScaleY_1080to416(989.0);
      *(float *)(a1 + 120) = FFX_Menu2D_ScaleX_1920to512(191.0);
      *(float *)(a1 + 128) = *(float *)(a1 + 112);
      *(_WORD *)(a1 + 102) = (int)FFX_Menu2D_ScaleX_1920to512(300.0);
      *(_WORD *)(a1 + 98) = (int)FFX_Menu2D_ScaleX_1920to512(420.0);
      *(_DWORD *)(a1 + 40) = 2;
      *(_DWORD *)(a1 + 44) = 268437248;
      goto LABEL_9;
    case 0x15:
    case 0x16:
      *(_DWORD *)(a1 + 180) = FFX_Btl_GetKernelString_Table0(12308, 0);
      *(_DWORD *)(a1 + 184) = FFX_Btl_GetKernelString_Table0(12309, 0);
      *(_DWORD *)(a1 + 176) = 2;
      *(_DWORD *)(a1 + 40) = 65538;
      *(_DWORD *)(a1 + 44) = 301994240;
      *(_WORD *)(a1 + 86) = unk_25D0AFA;
      *(_WORD *)(a1 + 88) = unk_25D0AF8;
LABEL_9:
      *(_DWORD *)(a1 + 56) = 196609;
      break;
    default:
      break;
  }
  *(_WORD *)(a1 + 64) = 0;
  *(_WORD *)(a1 + 60) = 0;
  result = *(unsigned __int16 *)(a1 + 36);
  *(_WORD *)(a1 + 68) = result;
  return result;
}

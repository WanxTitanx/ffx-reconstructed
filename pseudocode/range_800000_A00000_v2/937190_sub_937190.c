// Function: sub_937190
// Address: 0x937190
int sub_937190()
{
  signed int Size; // ebx
  int v1; // eax
  _DWORD *v2; // esi
  char *v3; // edi
  int Val; // eax
  int v5; // edi
  int v6; // esi
  char *v8; // [esp+Ch] [ebp-40h]
  _DWORD v9[13]; // [esp+14h] [ebp-38h]

  Size = *(_DWORD *)(unk_193C0F0 + 2812) * *(_DWORD *)(unk_193C0F0 + 2816);
  v1 = *(_DWORD *)(unk_193C0F0 + 2796);
  v2 = off_C498DC;
  v3 = (char *)off_C498DC + 1024;
  v9[0] = 0;
  v9[1] = 1;
  v9[2] = 2;
  v9[3] = 10;
  v9[4] = 19;
  v9[5] = 20;
  v9[6] = 27;
  v9[7] = 36;
  v9[8] = 44;
  v9[9] = 48;
  v9[10] = 49;
  v9[11] = 50;
  v9[12] = 58;
  v8 = (char *)off_C498DC + 1024;
  switch ( v1 )
  {
    case 0:
    case 1:
    case 27:
    case 36:
    case 44:
    case 48:
    case 49:
      Size *= 4;
      break;
    case 2:
    case 10:
    case 50:
    case 58:
      Size *= 2;
      break;
    case 20:
      Size /= 2;
      break;
    default:
      break;
  }
  Val = rand() % 256;
  memset(v3, Val, Size);
  *v2 = 268435461;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v2[5] = *(_DWORD *)(unk_193C0F0 + 2788)
        | ((*(_DWORD *)(unk_193C0F0 + 2792) | (v9[*(_DWORD *)(unk_193C0F0 + 2796)] << 8)) << 16);
  v2[4] = 0;
  v2[6] = 80;
  v2[7] = 0;
  v2[8] = 0;
  v2[9] = 0;
  v2[10] = 81;
  v2[11] = 0;
  v5 = (*(int *)(unk_193C0F0 + 2812) >> 31) | *(_DWORD *)(unk_193C0F0 + 2816);
  v2[12] = *(_DWORD *)(unk_193C0F0 + 2812);
  v2[13] = v5;
  v2[14] = 82;
  v2[15] = 0;
  v2[16] = 0;
  v2[17] = 0;
  v2[18] = 83;
  v2[19] = 0;
  *((_WORD *)v2 + 40) = Size / 16;
  *((_WORD *)v2 + 41) = 0;
  v2[21] = v8;
  v2[22] = 0;
  v2[23] = 0;
  v6 = sub_62F890(2);
  nullsub_33(0);
  nullsub_39(v6, off_C498DC);
  return sub_62F8E0(v6, 0, 0);
}

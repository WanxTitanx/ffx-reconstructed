// Function: sub_8A0D70
// Address: 0x8a0d70
int __cdecl sub_8A0D70(int a1)
{
  int result; // eax

  result = *(__int16 *)(a1 + 6);
  switch ( *(_WORD *)(a1 + 6) )
  {
    case 0:
      result = FFX_Btl_CheckActorCommandAvailabilityMask(*(__int16 *)(a1 + 8));
      if ( result > 0 && unk_1340412 == 1 )
        *(_DWORD *)(a1 + 152) = sub_8A8550;
      else
        *(_DWORD *)(a1 + 152) = sub_8A85F0;
      *(_DWORD *)(a1 + 156) = FFX_Btl_MenuCursorNavigateDispatcher;
      *(_DWORD *)(a1 + 160) = sub_8A2A00;
      *(_DWORD *)(a1 + 144) = sub_8A4950;
      *(_DWORD *)(a1 + 148) = 0;
      break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 0xE:
    case 0x11:
      *(_DWORD *)(a1 + 228) = 1;
      *(_DWORD *)(a1 + 152) = sub_8A86A0;
      *(_DWORD *)(a1 + 156) = sub_8A8AD0;
      *(_DWORD *)(a1 + 160) = sub_8A2A30;
      *(_DWORD *)(a1 + 144) = sub_8A74D0;
      *(_DWORD *)(a1 + 148) = 0;
      break;
    case 5:
      *(_DWORD *)(a1 + 152) = sub_8A86C0;
      *(_DWORD *)(a1 + 156) = sub_8A8B00;
      *(_DWORD *)(a1 + 160) = sub_8A2A40;
      *(_DWORD *)(a1 + 144) = sub_8A75A0;
      *(_DWORD *)(a1 + 148) = 0;
      break;
    case 7:
    case 0xF:
      *(_DWORD *)(a1 + 228) = 1;
      *(_DWORD *)(a1 + 152) = sub_8A86E0;
      *(_DWORD *)(a1 + 156) = sub_8A8B40;
      *(_DWORD *)(a1 + 160) = sub_8A2A50;
      *(_DWORD *)(a1 + 144) = sub_8A7D70;
      *(_DWORD *)(a1 + 148) = 0;
      break;
    case 0xA:
      *(_DWORD *)(a1 + 148) = sub_8A8480;
      *(_DWORD *)(a1 + 152) = sub_8A85B0;
      *(_DWORD *)(a1 + 156) = sub_8A8750;
      *(_DWORD *)(a1 + 160) = sub_8A29D0;
      *(_DWORD *)(a1 + 144) = sub_8A2D40;
      break;
    case 0xC:
      *(_DWORD *)(a1 + 152) = sub_8A85D0;
      *(_DWORD *)(a1 + 156) = sub_8A89F0;
      *(_DWORD *)(a1 + 160) = sub_8A29F0;
      *(_DWORD *)(a1 + 144) = sub_8A3620;
      *(_DWORD *)(a1 + 148) = 0;
      break;
    case 0xD:
      *(_DWORD *)(a1 + 152) = sub_8A8680;
      *(_DWORD *)(a1 + 156) = sub_8A8AA0;
      *(_DWORD *)(a1 + 160) = sub_8A2A20;
      *(_DWORD *)(a1 + 144) = sub_8A6A10;
      *(_DWORD *)(a1 + 148) = 0;
      break;
    case 0x14:
      *(_DWORD *)(a1 + 228) = 1;
      *(_DWORD *)(a1 + 152) = sub_8A8660;
      *(_DWORD *)(a1 + 156) = sub_8A8A70;
      *(_DWORD *)(a1 + 160) = sub_8A2A10;
      *(_DWORD *)(a1 + 144) = sub_8A6810;
      *(_DWORD *)(a1 + 148) = 0;
      break;
    case 0x15:
    case 0x16:
      if ( *(_WORD *)(a1 + 12) == 12324 )
        result = sub_8A1FD0(100000);
      else
        result = sub_8A1FD0(-1);
      *(_DWORD *)(a1 + 152) = sub_8A85C0;
      *(_DWORD *)(a1 + 156) = sub_8A8780;
      *(_DWORD *)(a1 + 160) = sub_8A29E0;
      *(_DWORD *)(a1 + 144) = sub_8A3250;
      *(_DWORD *)(a1 + 148) = 0;
      break;
    default:
      return result;
  }
  return result;
}

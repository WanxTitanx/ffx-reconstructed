// Function: FFX_MagicCoreOp_C0_GlobalMagicSwitch
// Address: 0x8167c0
// [Jarvis naming goal 2026-06-17 pass2] Magic core opcode 0xC0: switch over immediate cases for global magic state/branch helpers.
int __cdecl FFX_MagicCoreOp_C0_GlobalMagicSwitch(int a1, int a2)
{
  int v2; // esi
  _DWORD *v3; // ecx
  int result; // eax

  v2 = a2;
  v3 = (_DWORD *)((char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(*(_DWORD *)(a1 + 544) + 20));
  switch ( *(_WORD *)(a2 + 2) )
  {
    case 1:
      unk_11A0041 = 1;
      result = a2 + 4;
      break;
    case 2:
      unk_11A0041 = 0;
      result = a2 + 4;
      break;
    case 3:
      if ( !unk_11A0041 )
        goto LABEL_12;
      *(_BYTE *)(a1 + 528) = 1;
      result = a2;
      break;
    case 4:
      sub_7882C0(*v3, 1);
      result = a2 + 4;
      break;
    case 5:
      if ( (int)sub_787D60(*v3) >= 1 )
        goto LABEL_12;
      *(_BYTE *)(a1 + 528) = 1;
      result = a2;
      break;
    case 6:
      sub_7882C0(*v3, 0);
      result = a2 + 4;
      break;
    case 7:
      sub_820550(1);
      sub_820510(1);
      sub_820570(1);
      sub_820530(1);
      result = a2 + 4;
      break;
    case 8:
      sub_820550(0);
      sub_820510(0);
      sub_820570(0);
      sub_820530(0);
LABEL_12:
      v2 = a2 + 4;
      goto LABEL_13;
    default:
LABEL_13:
      result = v2;
      break;
  }
  return result;
}

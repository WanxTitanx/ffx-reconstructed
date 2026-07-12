// Function: FFX_Btl_SubmenuSetupSlider
// Address: 0x898c10
int __cdecl FFX_Btl_SubmenuSetupSlider(int a1)
{
  int n2; // esi
  float v3; // [esp+Ch] [ebp+8h]

  n2 = 0;
  switch ( a1 )
  {
    case ' ':
      n2 = 0;
      break;
    case '0':
      n2 = 1;
      break;
    case '@':
      n2 = 2;
      break;
    case 'P':
      n2 = 3;
      break;
    default:
      break;
  }
  v3 = sub_A5CBD0(n2);
  MEMORY[0x133F74C] = v3;
  n2_4 = 1;
  MEMORY[0x133F750] = v3;
  MEMORY[0x133F754] = v3;
  word_133D704 = sub_A5CB80(n2);
  MEMORY[0x133D702] = n9_0[1];
  unk_133D700 = sub_A5CB30(n2);
  MEMORY[0x133D6FC] = n9_0[1] + unk_133D6FA / 2 - (__int16)unk_133D700 / 2;
  MEMORY[0x133D6FE] = n9_0[1] + unk_133D6FA / 2 + (__int16)unk_133D700 / 2;
  n9_0[0] = 1;
  return 1;
}

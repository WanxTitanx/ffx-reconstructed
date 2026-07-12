// Function: FFX_Btl_SubmenuSetupTargeting
// Address: 0x898a40
int __cdecl FFX_Btl_SubmenuSetupTargeting(int a1)
{
  int n2; // esi
  _WORD *v2; // eax
  int v3; // ecx
  float v5; // [esp+Ch] [ebp+8h]

  n2 = 0;
  switch ( a1 )
  {
    case '"':
      n2 = 0;
      break;
    case '2':
      n2 = 1;
      break;
    case 'B':
      n2 = 2;
      break;
    case 'R':
      n2 = 3;
      break;
    default:
      break;
  }
  v5 = sub_A5CA70(n2);
  MEMORY[0x133F74C] = v5;
  n2_4 = 1;
  MEMORY[0x133F750] = v5;
  MEMORY[0x133F754] = v5;
  v2 = (_WORD *)sub_A5CA60(n2);
  v3 = 0;
  unk_133D6C4 = v2;
  unk_133D6C0 = 0;
  if ( *v2 != 0xFFFF )
  {
    do
      unk_133D6C0 = ++v3;
    while ( v2[v3] != 0xFFFF );
  }
  *(_WORD *)&byte_133D6B2[2] = 1;
  return 1;
}

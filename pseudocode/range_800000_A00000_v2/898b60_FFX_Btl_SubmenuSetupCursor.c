// Function: FFX_Btl_SubmenuSetupCursor
// Address: 0x898b60
int __cdecl FFX_Btl_SubmenuSetupCursor(int n31)
{
  int v1; // esi
  float n31a; // [esp+Ch] [ebp+8h]

  v1 = n31 - 12408;
  n31a = sub_A5CB10(n31 - 12408);
  MEMORY[0x133F74C] = n31a;
  n2_4 = 1;
  MEMORY[0x133F750] = n31a;
  MEMORY[0x133F754] = n31a;
  sub_A5CC70(v1);
  unk_133D6DE = unk_133F758[0];
  IsPlaying_0 = 3;
  n16 = 1;
  n7_5 = 1;
  return 1;
}

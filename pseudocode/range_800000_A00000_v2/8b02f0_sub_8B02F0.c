// Function: sub_8B02F0
// Address: 0x8b02f0
int sub_8B02F0()
{
  int v0; // eax
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax

  unk_1841CF0 = 1;
  v0 = sub_8AC740();
  sub_8AB9E0(dword_C59564, 11, v0);
  v1 = sub_8AC270();
  sub_8AB9E0(dword_C59564, 10, v1);
  v2 = sub_8ACEC0();
  sub_8AB9E0(dword_C59564, 15, v2);
  v3 = sub_8AC3A0();
  sub_8AB9E0(dword_C59564, 14, v3);
  v4 = sub_8AC280();
  sub_8AB9E0(dword_C59564, 8, v4);
  sub_8AB9E0(dword_C59564, 6, &unk_25D0D20);
  v5 = sub_906B20();
  sub_8AB9E0(dword_C59564, 5, v5);
  sub_8AB9E0(dword_C59564, 7, &unk_25D0DC0);
  sub_8AE550(2);
  sub_8AB9E0(dword_C59564, 22, &unk_1841DD0);
  sub_A7C7F0(2, &unk_1841DD0);
  sub_8AE6A0();
  sub_782110();
  unk_1841CEC = 1;
  unk_1841CF0 = 0;
  nullsub_34();
  return unk_1841CEC;
}

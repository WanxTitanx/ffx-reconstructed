// Function: sub_93FD60
// Address: 0x93fd60
int __cdecl sub_93FD60(float *a1, _DWORD *a2)
{
  int result; // eax
  float v3[16]; // [esp+0h] [ebp-44h] BYREF

  v3[0] = unk_193C338;
  v3[4] = unk_193C33C;
  v3[8] = unk_193C340;
  v3[12] = unk_193C344;
  v3[1] = unk_193C348;
  v3[5] = unk_193C34C;
  v3[9] = unk_193C350;
  v3[13] = unk_193C354;
  v3[2] = unk_193C358;
  v3[6] = unk_193C35C;
  v3[10] = unk_193C360;
  v3[14] = unk_193C364;
  v3[3] = unk_193C368;
  v3[7] = unk_193C36C;
  v3[11] = unk_193C370;
  v3[15] = unk_193C374;
  result = (int)sub_93D710(a2, v3, a1, 1);
  *a2 -= 1792;
  a2[1] -= 1840;
  return result;
}

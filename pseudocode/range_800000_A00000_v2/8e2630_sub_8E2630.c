// Function: sub_8E2630
// Address: 0x8e2630
int sub_8E2630()
{
  int result; // eax

  sub_8C2B70("rect_noactive", &unk_23CC138);
  sub_8C2B30("pos_noactive", &unk_23CC144);
  sub_8C2B30("pos_nmblkline", &unk_187164C);
  sub_8C2B70("rect_nmblkline", &unk_1871650);
  unk_23CC148 = sub_8C2AB0("col_noactive0");
  result = sub_8C2AB0("col_noactive1");
  unk_23CC140 = result;
  return result;
}

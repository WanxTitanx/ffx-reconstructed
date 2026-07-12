// Function: sub_A54660
// Address: 0xa54660
// Size: 0xbe
// Prototype: int(void)

int __usercall sub_A54660@<eax>(int a1@<ebp>)
{
  int v1; // esi
  void (*v2)(void); // eax
  int result; // eax

  v1 = unk_12FB790;
  unk_230FD2C = &unk_1760830;
  unk_12FB790 = 0;
  sub_A47630();
  sub_A497B0();
  sub_A4CE20();
  FFX_Abmap_DrawRuntimePanelNodes(a1);
  sub_A4C700(a1);
  sub_A4B4B0();
  sub_A49F10(a1);
  sub_A505E0();
  sub_A50290();
  sub_A4C8D0(a1);
  if ( 1.0 != *(float *)(dword_2305834[0] + 71144) )
    sub_A4C460((int)((1.0 - *(float *)(dword_2305834[0] + 71144)) * 128.0), 17152);
  sub_A4FBE0();
  sub_A4B790();
  if ( *(__int16 *)(unk_1A86108 + 9984) < 0 )
  {
    v2 = *(void (**)(void))(dword_2305834[0] + 71084);
    if ( v2 )
      v2();
  }
  result = sub_A58660();
  unk_12FB790 = v1;
  return result;
}


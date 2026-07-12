// Function: sub_A545A0
// Address: 0xa545a0
// Size: 0xb3
// Prototype: int(void)

void sub_A545A0()
{
  void (*v0)(void); // eax

  unk_230FD2C = &unk_1760830;
  if ( !unk_12FB790 )
  {
    sub_A8ECF0();
    sub_A8ED60();
    sub_A8ED40();
    sub_A8ED00();
    sub_A8ED20();
    sub_A4AC20();
    if ( 1.0 != *(float *)(dword_2305834[0] + 71144) )
      sub_A4C460((int)((1.0 - *(float *)(dword_2305834[0] + 71144)) * 128.0), 17152);
    sub_A4FBE0();
    sub_A4B790();
    sub_A58660();
    sub_A8ECF0();
    if ( *(__int16 *)(unk_1A86108 + 9984) < 0 )
    {
      v0 = *(void (**)(void))(dword_2305834[0] + 71084);
      if ( v0 )
        v0();
    }
    *(_DWORD *)(dword_2305834[0] + 71336) = -2;
  }
}


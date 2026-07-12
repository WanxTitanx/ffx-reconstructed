// Function: sub_A572E0
// Address: 0xa572e0
// Size: 0x235
// Prototype: int __cdecl(_DWORD, _DWORD, _DWORD)

int sub_A572E0()
{
  _DWORD *v0; // ecx
  int result; // eax

  memset(&buf__0, 0, 0x2710u);
  unk_16AD860 = -1;
  dword_2305834[0] = &buf__1;
  memset(&buf__1, 0, 0x12FC0u);
  buf = &buf__0;
  sub_93D960((int)&unk_16BEC10, 512.0, 1.0, 1.0833334, 2048.0, 2048.0, 1.0, 16777215.0, 1.0, 65536.0);
  sub_93D960(dword_2305834[0] + 70816, 512.0, 1.0, 1.0, 0.0, 0.0, 1.0, 16777215.0, 1.0, 65536.0);
  sub_6EDAE0(dword_2305834[0] + 70496);
  sub_6EDAE0(dword_2305834[0] + 70688);
  *(float *)(dword_2305834[0] + 70420) = 1.0;
  v0 = (_DWORD *)dword_2305834[0];
  *(_DWORD *)(dword_2305834[0] + 70440) = *(_DWORD *)(dword_2305834[0] + 70408);
  v0[17611] = v0[17603];
  v0[17612] = v0[17604];
  v0[17613] = v0[17605];
  *(float *)(dword_2305834[0] + 70492) = 1.0;
  *(float *)(dword_2305834[0] + 70488) = 1.0;
  *(float *)(dword_2305834[0] + 70484) = 1.0;
  *(float *)(dword_2305834[0] + 70480) = 1.0;
  *(_BYTE *)(dword_2305834[0] + 71108) = 0;
  *(_DWORD *)(dword_2305834[0] + 71080) = sub_A45010;
  *(_DWORD *)(dword_2305834[0] + 71084) = sub_A454A0;
  *(_DWORD *)(dword_2305834[0] + 71084) = sub_A454A0;
  *(_BYTE *)(dword_2305834[0] + 71107) = 0;
  *(_BYTE *)(dword_2305834[0] + 71110) = 0x80;
  *(_BYTE *)(dword_2305834[0] + 71100) = sub_8E1C50();
  *(_WORD *)(dword_2305834[0] + 71280) = -1;
  *(_BYTE *)(dword_2305834[0] + 71099) = 1;
  *(_BYTE *)(dword_2305834[0] + 71098) = 1;
  *(_DWORD *)(dword_2305834[0] + 71336) = -2;
  *(_DWORD *)(dword_2305834[0] + 71340) = 0;
  *(float *)(dword_2305834[0] + 71348) = 0.0;
  result = dword_2305834[0];
  *(_DWORD *)(dword_2305834[0] + 71352) = 1;
  return result;
}


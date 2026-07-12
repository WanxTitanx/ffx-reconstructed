// Function: sub_A594C0
// Address: 0xa594c0
// Size: 0x73
// Prototype: 

int __cdecl sub_A594C0(int a1, int a2, int a3)
{
  int result; // eax

  if ( *(_BYTE *)(dword_2305834[0] + 71097) == 0x80 )
    result = sub_8E8FB0(unk_230FD2C + 16, 0, a1, a2, a3, 0, 0, 128, 128, 128, 128, 0);
  else
    result = sub_8E8FB0(unk_230FD2C + 16, 7, a1, a2, a3, 0, 0, 128, 128, 128, *(_BYTE *)(dword_2305834[0] + 71097), 0);
  unk_230FD2C = result;
  return result;
}


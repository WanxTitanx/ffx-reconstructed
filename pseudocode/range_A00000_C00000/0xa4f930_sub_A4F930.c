// Function: sub_A4F930
// Address: 0xa4f930
// Size: 0x64
// Prototype: 

int __cdecl sub_A4F930(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int result; // eax

  if ( !*((_BYTE *)a2 + 4) )
    return sub_A594C0(*a2, a4 + 14, a5);
  result = sub_8E8FB0(
             unk_230FD2C + 16,
             -1,
             *a2,
             a4 + 14,
             a5,
             1,
             0,
             128,
             128,
             128,
             *(_BYTE *)(dword_2305834[0] + 71097),
             0);
  unk_230FD2C = result;
  return result;
}


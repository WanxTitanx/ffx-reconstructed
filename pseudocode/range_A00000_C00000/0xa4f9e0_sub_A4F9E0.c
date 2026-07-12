// Function: sub_A4F9E0
// Address: 0xa4f9e0
// Size: 0x4f

int __cdecl sub_A4F9E0(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int result; // eax

  result = sub_8E8FB0( /*0xa4fa20*/
             unk_230FD2C + 16,
             7,
             *a2,
             a4 + 10,
             a5,
             0,
             0,
             128,
             128,
             128,
             *(_BYTE *)(dword_2305834[0] + 71097),
             0);
  unk_230FD2C = result; /*0xa4fa28*/
  return result; /*0xa4fa2d*/
}
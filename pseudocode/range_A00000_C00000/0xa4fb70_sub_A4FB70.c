// Function: sub_A4FB70
// Address: 0xa4fb70
// Size: 0x6a

int __cdecl sub_A4FB70(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int result; // eax

  if ( !*((_BYTE *)a2 + 4) ) /*0xa4fb76*/
    return sub_A594C0(*a2, a4 + 5, a5); /*0xa4fbd0*/
  result = sub_8E8FB0( /*0xa4fbb5*/
             unk_230FD2C + 16,
             -1,
             *a2,
             a4 + 5,
             a5,
             1,
             0,
             128,
             128,
             128,
             *(_BYTE *)(dword_2305834[0] + 71097),
             0);
  unk_230FD2C = result; /*0xa4fbbd*/
  return result; /*0xa4fbc2*/
}
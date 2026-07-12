// Function: sub_8053F0
// Address: 0x8053f0
int __cdecl sub_8053F0(int a1, int a2, int a3)
{
  if ( (a3 & 0x8000) != 0 )
    return sub_835570(a2, a3 & 0x7FFF, a1);
  else
    return sub_833D90(a2, a3, 0, a1);
}

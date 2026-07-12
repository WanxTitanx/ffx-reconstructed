// Function: sub_A26510
// Address: 0xa26510
// Size: 0x7f

int __thiscall sub_A26510(int *this, _DWORD *a2, _DWORD *a3)
{
  int i; // ebx
  _DWORD *v6; // edx
  _DWORD *v7; // ecx

  if ( !a2 ) /*0xa2651c*/
    return 13; /*0xa2651e*/
  i = *this & 0x7FFFFFFF; /*0xa2652a*/
  sub_A25D50(a2, (_DWORD *)*(this + 1), i); /*0xa26535*/
  v6 = &a2[4 * i]; /*0xa26542*/
  if ( v6 ) /*0xa26544*/
  {
    *v6 = *a3; /*0xa2654b*/
    v6[1] = a3[1]; /*0xa26550*/
    v6[2] = a3[2]; /*0xa26556*/
    v6[3] = a3[3]; /*0xa2655c*/
  }
  v7 = (_DWORD *)*(this + 1); /*0xa2655f*/
  if ( v7 != a2 && *this >= 0 ) /*0xa2656f*/
  {
    if ( v7 ) /*0xa26573*/
      Phyre_Memory_AlignedFree(*(this + 1)); /*0xa26576*/
  }
  *(this + 1) = (int)a2; /*0xa26582*/
  *this = i + 1; /*0xa26585*/
  return 0; /*0xa26521*/
}
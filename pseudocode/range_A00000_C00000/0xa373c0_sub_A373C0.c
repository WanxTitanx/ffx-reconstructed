// Function: sub_A373C0
// Address: 0xa373c0
// Size: 0x48

_DWORD *sub_A373C0()
{
  _DWORD *result; // eax
  int v1; // edx

  (*(void (__stdcall **)(_DWORD, _DWORD, int, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 212))( /*0xa373db*/
    dword_1A858B4[1],
    dword_1A858B4[481],
    1,
    1.0,
    0);
  result = dword_1A858B4; /*0xa373e1*/
  v1 = dword_1A858B4[482]; /*0xa373e6*/
  if ( v1 ) /*0xa373ee*/
    return (_DWORD *)(*(int (__stdcall **)(_DWORD, int, int, _DWORD, _DWORD))(*(_DWORD *)dword_1A858B4[1] + 212))( /*0xa37401*/
                       dword_1A858B4[1],
                       v1,
                       1,
                       1.0,
                       0);
  return result; /*0xa37407*/
}
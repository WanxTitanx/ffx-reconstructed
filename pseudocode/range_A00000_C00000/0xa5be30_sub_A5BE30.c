// Function: sub_A5BE30
// Address: 0xa5be30
// Size: 0x87

int __cdecl sub_A5BE30(int a1)
{
  int result; // eax

  unk_C8F7A0 = *(float *)a1; /*0xa5be38*/
  unk_C8F7A4 = *(float *)(a1 + 4); /*0xa5be40*/
  unk_C8F7A8 = *(float *)(a1 + 8); /*0xa5be48*/
  unk_C8F7AC = *(_DWORD *)(a1 + 12); /*0xa5be50*/
  unk_C8F7B0 = *(_DWORD *)(a1 + 16); /*0xa5be58*/
  unk_C8F7B4 = *(_DWORD *)(a1 + 20); /*0xa5be60*/
  unk_C8F7B8 = *(_DWORD *)(a1 + 24); /*0xa5be68*/
  unk_C8F7BC = *(_DWORD *)(a1 + 28); /*0xa5be70*/
  unk_C8F7C0 = *(float *)(a1 + 32); /*0xa5be78*/
  unk_C8F7C4 = *(_DWORD *)(a1 + 36); /*0xa5be80*/
  unk_C8F7C8 = *(_DWORD *)(a1 + 40); /*0xa5be88*/
  unk_C8F7CC = *(_DWORD *)(a1 + 44); /*0xa5be90*/
  unk_C8F7D0 = *(float *)(a1 + 48); /*0xa5be98*/
  unk_C8F7D4 = *(float *)(a1 + 52); /*0xa5bea0*/
  unk_C8F7D8 = *(float *)(a1 + 56); /*0xa5bea8*/
  result = *(_DWORD *)(a1 + 60); /*0xa5bead*/
  LODWORD(flt_C8F7DC) = result; /*0xa5beb0*/
  return result; /*0xa5beb5*/
}
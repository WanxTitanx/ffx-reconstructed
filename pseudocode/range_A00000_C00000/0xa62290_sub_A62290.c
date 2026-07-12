// Function: sub_A62290
// Address: 0xa62290
// Size: 0x91
// Prototype: int __cdecl(int, int, float, float)

int __cdecl sub_A62290(_DWORD *a1, _DWORD *a2, float a3, float a4)
{
  int result; // eax

  MEMORY[0xC8F528] = *a2; /*0xa6229c*/
  unk_C8F52C = a2[1]; /*0xa622a5*/
  unk_C8F530 = a2[2]; /*0xa622ae*/
  unk_C8F534 = a2[3]; /*0xa622b7*/
  unk_12A12CC = unk_C8F534; /*0xa622bc*/
  unk_12A12C0 = MEMORY[0xC8F528]; /*0xa622c4*/
  unk_12A12C4 = unk_C8F52C; /*0xa622ca*/
  unk_12A12C8 = unk_C8F530; /*0xa622d0*/
  MEMORY[0xC8F528] = *a1; /*0xa622d8*/
  unk_C8F52C = a1[1]; /*0xa622e1*/
  unk_C8F530 = a1[2]; /*0xa622ea*/
  result = a1[3]; /*0xa622f0*/
  unk_23328B0 = a3; /*0xa622f3*/
  unk_12A12D0 = MEMORY[0xC8F528]; /*0xa622fc*/
  unk_23328AC = a4; /*0xa62302*/
  unk_C8F534 = result; /*0xa62308*/
  unk_12A12D4 = unk_C8F52C; /*0xa6230d*/
  unk_12A12D8 = unk_C8F530; /*0xa62313*/
  unk_12A12DC = result; /*0xa62319*/
  return result; /*0xa6231f*/
}
// Function: sub_A69940
// Address: 0xa69940
// Size: 0x300

int __cdecl sub_A69940(int a1, int a2, int a3)
{
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int result; // eax

  MEMORY[0xC8F528] = *(_DWORD *)a2; /*0xa6994e*/
  unk_C8F52C = *(_DWORD *)(a2 + 4); /*0xa69957*/
  unk_C8F530 = *(_DWORD *)(a2 + 8); /*0xa6995f*/
  unk_C8F534 = *(_DWORD *)(a2 + 12); /*0xa69967*/
  *(_DWORD *)(a3 + 768) = MEMORY[0xC8F528]; /*0xa6996c*/
  *(_DWORD *)(a3 + 772) = unk_C8F52C; /*0xa69977*/
  *(_DWORD *)(a3 + 776) = unk_C8F530; /*0xa69982*/
  *(_DWORD *)(a3 + 780) = unk_C8F534; /*0xa6998d*/
  MEMORY[0xC8F528] = *(_DWORD *)(a2 + 16); /*0xa69996*/
  unk_C8F52C = *(_DWORD *)(a2 + 20); /*0xa6999f*/
  unk_C8F530 = *(_DWORD *)(a2 + 24); /*0xa699a7*/
  unk_C8F534 = *(_DWORD *)(a2 + 28); /*0xa699af*/
  *(_DWORD *)(a3 + 784) = MEMORY[0xC8F528]; /*0xa699ba*/
  *(_DWORD *)(a3 + 788) = unk_C8F52C; /*0xa699c5*/
  *(_DWORD *)(a3 + 792) = unk_C8F530; /*0xa699d0*/
  *(_DWORD *)(a3 + 796) = unk_C8F534; /*0xa699db*/
  MEMORY[0xC8F528] = ... [4479 chars total]
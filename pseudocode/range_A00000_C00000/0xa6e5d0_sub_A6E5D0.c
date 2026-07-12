// Function: sub_A6E5D0
// Address: 0xa6e5d0
// Size: 0x74
// Prototype: 

int __cdecl sub_A6E5D0(_DWORD *a1, int a2, _DWORD *a3)
{
  _DWORD *v3; // esi

  v3 = &a1[8 * (a1[1] % *a1) + 4];
  sub_7EA760(v3, a2, 1.0);
  MEMORY[0xC8F528] = *a3;
  unk_C8F52C = a3[1];
  unk_C8F530 = a3[2];
  unk_C8F534 = a3[3];
  v3[4] = MEMORY[0xC8F528];
  v3[5] = unk_C8F52C;
  v3[6] = unk_C8F530;
  v3[7] = unk_C8F534;
  *((_WORD *)v3 + 14) = 0;
  ++a1[1];
  return 0;
}


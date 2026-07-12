// Function: sub_B07CA0
// Address: 0xb07ca0
// Size: 0x72
// Prototype: void __cdecl()

void __cdecl sub_B07CA0()
{
  char *v0; // esi
  _BYTE v1[7]; // [esp+4h] [ebp-8h] BYREF
  char v2; // [esp+Bh] [ebp-1h] BYREF

  sub_807130(v1, *(_DWORD *)dword_12F40B8[0], dword_12F40B8[0]);
  v0 = (char *)dword_12F40B8[0];
  sub_8066D0(&v2);
  nullsub_103(v0);
  sub_8066D0(&v2);
  nullsub_103(v0 + 4);
  sub_8066D0(&v2);
  nullsub_103(v0 + 8);
  sub_8066D0(&v2);
  FFX_Memory_Free(v0);
}


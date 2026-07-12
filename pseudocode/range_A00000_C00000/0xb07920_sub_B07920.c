// Function: sub_B07920
// Address: 0xb07920
// Size: 0x72
// Prototype: void __cdecl()

void __cdecl sub_B07920()
{
  char *v0; // esi
  _BYTE v1[7]; // [esp+4h] [ebp-8h] BYREF
  char v2; // [esp+Bh] [ebp-1h] BYREF

  sub_636F10(v1, *(_DWORD *)dword_CE6EA0[0], dword_CE6EA0[0]);
  v0 = (char *)dword_CE6EA0[0];
  sub_633B50(&v2);
  nullsub_52(v0);
  sub_633B50(&v2);
  nullsub_52(v0 + 4);
  sub_633B50(&v2);
  nullsub_52(v0 + 8);
  sub_633B50(&v2);
  FFX_Memory_Free(v0);
}


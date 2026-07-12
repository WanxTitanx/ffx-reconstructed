// Function: sub_B06050
// Address: 0xb06050
// Size: 0x72
// Prototype: void __cdecl()

void __cdecl sub_B06050()
{
  char *v0; // esi
  _BYTE v1[7]; // [esp+4h] [ebp-8h] BYREF
  char v2; // [esp+Bh] [ebp-1h] BYREF

  sub_6272E0(v1, *(_DWORD *)dword_CC9EE4[0], dword_CC9EE4[0]);
  v0 = (char *)dword_CC9EE4[0];
  sub_61F980(&v2);
  nullsub_31(v0);
  sub_61F980(&v2);
  nullsub_31(v0 + 4);
  sub_61F980(&v2);
  nullsub_31(v0 + 8);
  sub_61F980(&v2);
  FFX_Memory_Free(v0);
}


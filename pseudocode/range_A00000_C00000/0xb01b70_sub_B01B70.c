// Function: sub_B01B70
// Address: 0xb01b70
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01B70()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE9DC;
  v1 = (_DWORD *)unk_CAE9E0;
  *(_DWORD *)(dword_CAE9DC + 4) = unk_CAE9E0;
  *v1 = v0;
  dword_CAE9DC = &dword_CAE9DC;
  unk_CAE9E0 = &dword_CAE9DC;
  if ( (unk_CAE9EC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE9E8);
}


// Function: sub_AFB450
// Address: 0xafb450
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB450()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C947BC;
  v1 = (_DWORD *)unk_C947C0;
  *(_DWORD *)(dword_C947BC + 4) = unk_C947C0;
  *v1 = v0;
  dword_C947BC = &dword_C947BC;
  unk_C947C0 = &dword_C947BC;
  if ( (unk_C947CC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C947C8);
}


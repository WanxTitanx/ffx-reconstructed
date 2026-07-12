// Function: sub_AFB510
// Address: 0xafb510
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB510()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9466C;
  v1 = (_DWORD *)unk_C94670;
  *(_DWORD *)(dword_C9466C + 4) = unk_C94670;
  *v1 = v0;
  dword_C9466C = &dword_C9466C;
  unk_C94670 = &dword_C9466C;
  if ( (unk_C9467C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94678);
}


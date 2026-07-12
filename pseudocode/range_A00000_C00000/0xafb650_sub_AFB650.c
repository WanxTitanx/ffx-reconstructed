// Function: sub_AFB650
// Address: 0xafb650
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB650()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94934;
  v1 = (_DWORD *)unk_C94938;
  *(_DWORD *)(dword_C94934 + 4) = unk_C94938;
  *v1 = v0;
  dword_C94934 = &dword_C94934;
  unk_C94938 = &dword_C94934;
  if ( (unk_C94944 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94940);
}


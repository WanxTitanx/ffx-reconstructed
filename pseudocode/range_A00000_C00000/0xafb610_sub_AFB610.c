// Function: sub_AFB610
// Address: 0xafb610
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB610()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94694;
  v1 = (_DWORD *)unk_C94698;
  *(_DWORD *)(dword_C94694 + 4) = unk_C94698;
  *v1 = v0;
  dword_C94694 = &dword_C94694;
  unk_C94698 = &dword_C94694;
  if ( (unk_C946A4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C946A0);
}


// Function: sub_800620
// Address: 0x800620
// Size: 0x66

int __cdecl sub_800620(int a1)
{
  int v1; // esi

  v1 = *(_DWORD *)(a1 + 208);
  if ( *(_BYTE *)v1 )
  {
    unk_12F2050 = unknown_libname_741(*(_DWORD *)(v1 + 20));
    unk_12F2054 = unknown_libname_741(*(_DWORD *)(v1 + 24));
    unk_12F2058 = unknown_libname_741(*(_DWORD *)(v1 + 28));
    *(_DWORD *)off_C3A4C4 = &dword_12F2030;
    if ( !sub_80B7B0(v1) )
      FFX_MagicHost_RelocatePppResourceBlob(v1, (int)&off_C3A500);
  }
  return 0;
}

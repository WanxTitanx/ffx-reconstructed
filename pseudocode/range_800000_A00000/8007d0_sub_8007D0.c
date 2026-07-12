// Function: sub_8007D0
// Address: 0x8007D0
// Size: 0xa6

int __cdecl sub_8007D0(int a1)
{
  int v1; // esi
  int v2; // edi
  int result; // eax
  int v4; // esi

  v1 = *(_DWORD *)(a1 + 208);
  v2 = *(_DWORD *)(a1 + 188);
  unk_12F2050 = unknown_libname_741(*(_DWORD *)(v1 + 20));
  unk_12F2054 = unknown_libname_741(*(_DWORD *)(v1 + 24));
  unk_12F2058 = unknown_libname_741(*(_DWORD *)(v1 + 28));
  *(_DWORD *)off_C3A4C4 = dword_12F2030;
  if ( *(_BYTE *)v1 )
  {
    *(_DWORD *)off_C3A4C4 = dword_12F2030;
    result = FFX_Menu2D_FlushCaptureBatch48(v2, 48);
    v4 = result;
    if ( result )
    {
      buf__0[*(unsigned __int16 *)(v2 + 30)] = 0;
      *(_DWORD *)off_C3A4C4 = dword_12F2030;
      FFX_MagicHost_ClearResourceBufferList(v2);
      return v4;
    }
  }
  else
  {
    nullsub_34();
    return 0;
  }
  return result;
}

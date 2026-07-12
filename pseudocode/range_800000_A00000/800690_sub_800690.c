// Function: sub_800690
// Address: 0x800690
// Size: 0x135

int __cdecl sub_800690(int a1)
{
  int v2; // edi
  __int16 i; // si
  char *v4; // esi
  int v5; // eax
  int v7; // [esp+14h] [ebp+8h]

  v7 = *(_DWORD *)(a1 + 208);
  unk_12F2050 = unknown_libname_741(*(_DWORD *)(v7 + 20));
  unk_12F2054 = unknown_libname_741(*(_DWORD *)(v7 + 24));
  unk_12F2058 = unknown_libname_741(*(_DWORD *)(v7 + 28));
  *(_DWORD *)off_C3A4C4 = dword_12F2030;
  v2 = *(unsigned __int16 *)(a1 + 26) + (*(unsigned __int8 *)(a1 + 30) << 16);
  for ( i = 0; i < 256; ++i )
  {
    if ( buf__0[i] == v2 )
    {
LABEL_7:
      *(_DWORD *)off_C3A4C4 = dword_12F2030;
      FFX_MagicHost_ClearResourceBufferList((int)&unk_12EA030 + 128 * i);
      goto LABEL_8;
    }
  }
  i = 0;
  while ( buf__0[i] )
  {
    if ( ++i >= 256 )
      goto LABEL_7;
  }
LABEL_8:
  buf__0[i] = v2;
  v4 = (char *)&unk_12EA030 + 128 * i;
  *(_DWORD *)(a1 + 188) = v4;
  if ( *(_BYTE *)v7 )
  {
    *(_DWORD *)off_C3A4C4 = dword_12F2030;
    v5 = unknown_libname_741(*(_DWORD *)(*(_DWORD *)(a1 + 208) + 16));
    sub_712640(v4, 4096, *(_DWORD *)(v5 + 4 * *(unsigned __int8 *)(a1 + 212)), 1);
  }
  else
  {
    nullsub_34();
  }
  return 0;
}

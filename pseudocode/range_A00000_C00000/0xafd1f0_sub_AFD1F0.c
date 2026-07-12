// Function: sub_AFD1F0
// Address: 0xafd1f0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFD1F0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C9B348;
  v1 = (_DWORD *)unk_C9B34C;
  *(_DWORD *)(dword_C9B348 + 4) = unk_C9B34C;
  *v1 = v0;
  dword_C9B348 = &dword_C9B348;
  unk_C9B34C = &dword_C9B348;
  if ( (unk_C9B358 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C9B354);
}


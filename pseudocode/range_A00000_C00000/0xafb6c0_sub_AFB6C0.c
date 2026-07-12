// Function: sub_AFB6C0
// Address: 0xafb6c0
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB6C0()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94EAC;
  v1 = (_DWORD *)unk_C94EB0;
  *(_DWORD *)(dword_C94EAC + 4) = unk_C94EB0;
  *v1 = v0;
  dword_C94EAC = &dword_C94EAC;
  unk_C94EB0 = &dword_C94EAC;
  if ( (unk_C94EBC & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94EB8);
}


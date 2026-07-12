// Function: sub_AFB290
// Address: 0xafb290
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB290()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94AD4;
  v1 = (_DWORD *)unk_C94AD8;
  *(_DWORD *)(dword_C94AD4 + 4) = unk_C94AD8;
  *v1 = v0;
  dword_C94AD4 = &dword_C94AD4;
  unk_C94AD8 = &dword_C94AD4;
  if ( (unk_C94AE4 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94AE0);
}


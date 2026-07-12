// Function: sub_AFB350
// Address: 0xafb350
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_AFB350()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_C94A5C;
  v1 = (_DWORD *)unk_C94A60;
  *(_DWORD *)(dword_C94A5C + 4) = unk_C94A60;
  *v1 = v0;
  dword_C94A5C = &dword_C94A5C;
  unk_C94A60 = &dword_C94A5C;
  if ( (unk_C94A6C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_C94A68);
}


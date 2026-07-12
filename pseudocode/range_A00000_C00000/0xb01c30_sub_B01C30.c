// Function: sub_B01C30
// Address: 0xb01c30
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01C30()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAEA7C;
  v1 = (_DWORD *)unk_CAEA80;
  *(_DWORD *)(dword_CAEA7C + 4) = unk_CAEA80;
  *v1 = v0;
  dword_CAEA7C = &dword_CAEA7C;
  unk_CAEA80 = &dword_CAEA7C;
  if ( (unk_CAEA8C & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAEA88);
}


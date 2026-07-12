// Function: sub_B01350
// Address: 0xb01350
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B01350()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAE010;
  v1 = (_DWORD *)unk_CAE014;
  *(_DWORD *)(dword_CAE010 + 4) = unk_CAE014;
  *v1 = v0;
  dword_CAE010 = &dword_CAE010;
  unk_CAE014 = &dword_CAE010;
  if ( (unk_CAE020 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAE01C);
}


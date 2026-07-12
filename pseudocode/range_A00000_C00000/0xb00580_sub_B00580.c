// Function: sub_B00580
// Address: 0xb00580
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B00580()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAA8F8;
  v1 = (_DWORD *)unk_CAA8FC;
  *(_DWORD *)(dword_CAA8F8 + 4) = unk_CAA8FC;
  *v1 = v0;
  dword_CAA8F8 = &dword_CAA8F8;
  unk_CAA8FC = &dword_CAA8F8;
  if ( (unk_CAA908 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAA904);
}


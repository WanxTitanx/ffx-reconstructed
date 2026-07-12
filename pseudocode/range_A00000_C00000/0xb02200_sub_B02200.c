// Function: sub_B02200
// Address: 0xb02200
// Size: 0x3a
// Prototype: void __cdecl()

void __cdecl sub_B02200()
{
  int v0; // ecx
  _DWORD *v1; // eax

  v0 = dword_CAFA40;
  v1 = (_DWORD *)unk_CAFA44;
  *(_DWORD *)(dword_CAFA40 + 4) = unk_CAFA44;
  *v1 = v0;
  dword_CAFA40 = &dword_CAFA40;
  unk_CAFA44 = &dword_CAFA40;
  if ( (unk_CAFA50 & 1) != 0 )
    Phyre_Memory_AlignedFree(unk_CAFA4C);
}


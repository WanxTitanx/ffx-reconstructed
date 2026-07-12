// Function: sub_A3D5F0
// Address: 0xa3d5f0
// Size: 0xce

int __cdecl sub_A3D5F0(int a1, _BYTE *a2, int a3)
{
  _DWORD *v3; // eax
  _DWORD *v4; // esi
  int v6; // edi

  if ( !unk_1A858C4 ) /*0xa3d61c*/
  {
    v3 = (_DWORD *)sub_42FC20(8); /*0xa3d624*/
    if ( v3 ) /*0xa3d638*/
      v4 = Concurrency::details::_ReaderWriterLock::_ReaderWriterLock(v3); /*0xa3d641*/
    else
      v4 = 0; /*0xa3d645*/
    if ( !v4 ) /*0xa3d650*/
      return 13; /*0xa3d665*/
    v6 = sub_A3BA50(v4, a1, a2, a3); /*0xa3d676*/
    if ( v6 ) /*0xa3d67a*/
    {
      nullsub_191(); /*0xa3d67e*/
      Phyre_Memory_AlignedFree((int)v4); /*0xa3d684*/
      return v6; /*0xa3d69e*/
    }
    unk_1A858C4 = v4; /*0xa3d69f*/
  }
  ++unk_1A858C8; /*0xa3d6a5*/
  return 0; /*0xa3d655*/
}
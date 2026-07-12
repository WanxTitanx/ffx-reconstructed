// Function: sub_A3D570
// Address: 0xa3d570
// Size: 0x4c
// Prototype: int(void)

int sub_A3D570()
{
  int v0; // esi

  if ( unk_1A858C8 == 1 ) /*0xa3d578*/
  {
    v0 = unk_1A858C4; /*0xa3d57b*/
    unk_1A858C4 = 0; /*0xa3d581*/
    if ( v0 ) /*0xa3d58d*/
    {
      nullsub_191(); /*0xa3d591*/
      Phyre_Memory_AlignedFree(v0); /*0xa3d597*/
    }
    --unk_1A858C8; /*0xa3d59c*/
    return 0; /*0xa3d5a5*/
  }
  else
  {
    --unk_1A858C8; /*0xa3d5b4*/
    return 0; /*0xa3d5b9*/
  }
}
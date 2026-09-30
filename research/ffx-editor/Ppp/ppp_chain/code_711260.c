// FFX MagicHost: Build VFX texture and commit drawable
void __cdecl FFX_MagicHost_BuildVfxTextureAndCommitDrawable_structural(__int64 n2622, int a2, int a3)
{
  FFXMagicHost *host; // ecx
  int v4; // eax
  FFXMagicHost *host_1; // ecx

  FFX_MagicHost_BuildVfxTextureBindingDispatch_structural(host); /*0x711276*/
  if ( v4 && FFX_TextureSlot_ValidateGeometry(n2622) ) /*0x711284*/
  {
    FFX_MagicHost_AllocVfxParticleSlots(n2622, a2, a3); /*0x711298*/
    FFX_MagicHost_CommitDrawableResources(host_1); /*0x71129f*/
  }
  else
  {
    FFX_TextureSlot_ReleaseByKey(n2622); /*0x7112ad*/
  }
}
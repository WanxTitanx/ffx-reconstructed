// FFX MagicHost: Build VFX texture and finalize
void __cdecl FFX_MagicHost_BuildVfxTextureAndFinalize_structural(__int64 n2622, int a2, int a3)
{
  FFXMagicHost *host; // ecx
  int v4; // eax
  void *modelContext; // edx
  FFX_CharacterId charId; // ecx

  FFX_MagicHost_BuildVfxTextureBindingDispatch_structural(host); /*0x7110c6*/
  if ( v4 && FFX_TextureSlot_ValidateGeometry(n2622) ) /*0x7110d4*/
  {
    FFX_MagicHost_AllocVfxParticleSlots(n2622, a2, a3); /*0x7110e8*/
    FFX_Model_LoadCharacterModelWithFlag8000(charId, modelContext); /*0x7110ef*/
  }
  else
  {
    FFX_TextureSlot_ReleaseByKey(n2622); /*0x7110fd*/
  }
}
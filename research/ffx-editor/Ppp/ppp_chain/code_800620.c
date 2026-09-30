// FFX Magic: Relocate PPP resource accel
int __cdecl FFX_Magic_RelocatePppResourceAccel(int a1)
{
  int v1; // esi
  void *blob; // edx
  FFXMagicHost *host; // ecx

  v1 = *(_DWORD *)(a1 + 208); /*0x800627*/
  if ( *(_BYTE *)v1 ) /*0x80062d*/
  {
    *(_DWORD *)&byte_11333C4[1830028] = Std_IdentityFunc(*(_DWORD *)(v1 + 20)); /*0x80063a*/
    *(_DWORD *)&byte_11333C4[1830032] = Std_IdentityFunc(*(_DWORD *)(v1 + 24)); /*0x800647*/
    *(_DWORD *)&byte_11333C4[1830036] = Std_IdentityFunc(*(_DWORD *)(v1 + 28)); /*0x800654*/
    *(_DWORD *)FFX_PppResourceDescriptorTablePtr = &byte_11333C4[1829996]; /*0x80065f*/
    if ( !FFX_Magic_IsLargePppResource(v1) ) /*0x800665*/
      FFX_MagicHost_RelocatePppResourceBlob(host, blob);// "pppAccele" /*0x800679*/
  }
  return 0; /*0x800683*/
}
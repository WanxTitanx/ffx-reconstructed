// Function: sub_9A09E0
// Address: 0x9a09e0
int __thiscall sub_9A09E0(int *this, int a2, int a3)
{
  int v3; // edx
  _DWORD v5[7]; // [esp+4h] [ebp-1Ch] BYREF

  v5[1] = a2;
  v5[0] = &`btHashedOverlappingPairCache::cleanProxyFromPairs'::`2'::CleanPairCallback::`vftable';
  v5[2] = this;
  v5[3] = a3;
  v3 = *this;
  v5[6] = 0;
  return (*(int (__cdecl **)(_DWORD *))(v3 + 44))(v5);
}

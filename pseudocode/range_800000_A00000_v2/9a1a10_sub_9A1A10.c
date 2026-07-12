// Function: sub_9A1A10
// Address: 0x9a1a10
int __thiscall sub_9A1A10(int *this, int a2, int a3)
{
  int v3; // eax
  _DWORD v5[5]; // [esp+4h] [ebp-14h] BYREF

  v5[0] = &`btSortedOverlappingPairCache::removeOverlappingPairsContainingProxy'::`2'::RemovePairCallback::`vftable';
  v5[1] = a2;
  v3 = *this;
  v5[4] = 0;
  return (*(int (__cdecl **)(_DWORD *))(v3 + 44))(v5);
}

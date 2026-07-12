// Function: sub_9B6F90
// Address: 0x9b6f90
_DWORD *__thiscall sub_9B6F90(_DWORD *this, char a2)
{
  *this = &btSimulationIslandManager::IslandCallback::`vftable';
  if ( (a2 & 1) != 0 )
    FFX_Memory_Free(this);
  return this;
}

// Function: sub_A25EB0
// Address: 0xa25eb0
// Size: 0xf5
// Prototype: 

char __thiscall sub_A25EB0(int *this)
{
  unsigned int v2; // edi
  int v3; // eax
  void *v4; // ebx
  char result; // al

  v2 = 0;
  if ( (*(this + 2) & 0x7FFFFFFF) != 0 )
  {
    do
    {
      v3 = *(this + 3);
      v4 = *(void **)(v3 + 4 * v2);
      if ( v4 )
      {
        sub_A28A40(*(_DWORD *)(v3 + 4 * v2));
        FFX_Memory_Free(v4);
        *(_DWORD *)(*(this + 3) + 4 * v2) = 0;
      }
      ++v2;
    }
    while ( v2 < (*(this + 2) & 0x7FFFFFFFu) );
  }
  if ( *(this + 1) )
    sub_A3D240();
  sub_A3D570();
  *(this + 1) = 0;
  if ( *(this + 4) >= 0 && *(this + 5) )
    Phyre_Memory_AlignedFree(*(this + 5));
  *(this + 5) = 0;
  *(this + 4) = 0;
  result = ~(*(this + 2) < 0);
  if ( *(this + 2) >= 0 )
    result = Phyre_Memory_AlignedFree(*(this + 3));
  *(this + 2) = 0;
  *(this + 3) = 0;
  return result;
}


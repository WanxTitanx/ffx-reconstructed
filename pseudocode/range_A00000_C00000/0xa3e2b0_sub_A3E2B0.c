// Function: sub_A3E2B0
// Address: 0xa3e2b0
// Size: 0x84
// Prototype: int __stdcall(LONG lDistanceToMove, int, DWORD nNumberOfBytesToRead, LPVOID lpBuffer)

int __thiscall sub_A3E2B0(int this, __int64 lDistanceToMove, int nNumberOfBytesToRead, LPVOID lpBuffer)
{
  int v5; // ecx
  LONG lDistanceToMove_1; // eax

  v5 = *(_DWORD *)(this + 16);
  if ( !v5 )
    return -1;
  if ( SHIDWORD(lDistanceToMove) > 0 )
  {
    lDistanceToMove_1 = lDistanceToMove;
  }
  else
  {
    if ( lDistanceToMove < 0 )
      return -1;
    lDistanceToMove_1 = lDistanceToMove;
  }
  if ( nNumberOfBytesToRead < 0 )
    return -1;
  if ( !nNumberOfBytesToRead )
    return 0;
  if ( __SPAIR64__(HIDWORD(lDistanceToMove), lDistanceToMove_1) < *(_QWORD *)(this + 8)
    && FFX_FileIO_DeviceSeek(v5, lDistanceToMove_1, 0) == lDistanceToMove )
  {
    return -(FFX_FileIO_ReadFile(*(void ***)(this + 16), lpBuffer, nNumberOfBytesToRead) < nNumberOfBytesToRead);
  }
  else
  {
    return -1;
  }
}


// Function: InterlockedIncrement
// Address: 0xa8d706
// Size: 0x6
// Prototype: LONG __stdcall(volatile LONG *lpAddend)

// attributes: thunk
LONG __stdcall InterlockedIncrement(volatile LONG *lpAddend)
{
  return __imp_InterlockedIncrement(lpAddend);
}


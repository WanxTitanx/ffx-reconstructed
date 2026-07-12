// Function: InterlockedDecrement
// Address: 0xa8d70c
// Size: 0x6
// Prototype: LONG __stdcall(volatile LONG *lpAddend)

// attributes: thunk
LONG __stdcall InterlockedDecrement(volatile LONG *lpAddend)
{
  return __imp_InterlockedDecrement(lpAddend);
}


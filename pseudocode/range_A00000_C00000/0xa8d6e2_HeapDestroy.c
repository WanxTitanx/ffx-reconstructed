// Function: HeapDestroy
// Address: 0xa8d6e2
// Size: 0x6
// Prototype: BOOL __stdcall(HANDLE hHeap)

// attributes: thunk
BOOL __stdcall HeapDestroy(HANDLE hHeap)
{
  return __imp_HeapDestroy(hHeap);
}


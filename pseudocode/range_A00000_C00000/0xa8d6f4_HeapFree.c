// Function: HeapFree
// Address: 0xa8d6f4
// Size: 0x6
// Prototype: BOOL __stdcall(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem)

// attributes: thunk
BOOL __stdcall HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem)
{
  return __imp_HeapFree(hHeap, dwFlags, lpMem);
}


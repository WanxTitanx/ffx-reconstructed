// Function: HeapSize
// Address: 0xa8d6fa
// Size: 0x6
// Prototype: SIZE_T __stdcall(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem)

// attributes: thunk
SIZE_T __stdcall HeapSize(HANDLE hHeap, DWORD dwFlags, LPCVOID lpMem)
{
  return __imp_HeapSize(hHeap, dwFlags, lpMem);
}


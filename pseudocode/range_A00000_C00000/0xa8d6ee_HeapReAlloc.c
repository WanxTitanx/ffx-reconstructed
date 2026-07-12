// Function: HeapReAlloc
// Address: 0xa8d6ee
// Size: 0x6
// Prototype: LPVOID __stdcall(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes)

// attributes: thunk
LPVOID __stdcall HeapReAlloc(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem, SIZE_T dwBytes)
{
  return __imp_HeapReAlloc(hHeap, dwFlags, lpMem, dwBytes);
}


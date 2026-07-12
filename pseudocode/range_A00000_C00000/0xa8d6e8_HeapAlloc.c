// Function: HeapAlloc
// Address: 0xa8d6e8
// Size: 0x6
// Prototype: LPVOID __stdcall(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes)

// attributes: thunk
LPVOID __stdcall HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes)
{
  return __imp_HeapAlloc(hHeap, dwFlags, dwBytes);
}


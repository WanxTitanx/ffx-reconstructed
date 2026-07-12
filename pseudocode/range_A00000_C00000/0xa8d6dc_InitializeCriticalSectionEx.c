// Function: InitializeCriticalSectionEx
// Address: 0xa8d6dc
// Size: 0x6
// Prototype: BOOL __stdcall(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags)

// attributes: thunk
BOOL __stdcall InitializeCriticalSectionEx(LPCRITICAL_SECTION lpCriticalSection, DWORD dwSpinCount, DWORD Flags)
{
  return __imp_InitializeCriticalSectionEx(lpCriticalSection, dwSpinCount, Flags);
}


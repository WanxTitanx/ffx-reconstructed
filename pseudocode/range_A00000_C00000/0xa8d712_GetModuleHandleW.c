// Function: GetModuleHandleW
// Address: 0xa8d712
// Size: 0x6
// Prototype: HMODULE __stdcall(LPCWSTR lpModuleName)

// attributes: thunk
HMODULE __stdcall GetModuleHandleW(LPCWSTR lpModuleName)
{
  return __imp_GetModuleHandleW(lpModuleName);
}


// Function: GetSystemTimeAsFileTime
// Address: 0xa8d6d0
// Size: 0x6
// Prototype: void __stdcall(LPFILETIME lpSystemTimeAsFileTime)

// attributes: thunk
void __stdcall GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime)
{
  __imp_GetSystemTimeAsFileTime(lpSystemTimeAsFileTime);
}


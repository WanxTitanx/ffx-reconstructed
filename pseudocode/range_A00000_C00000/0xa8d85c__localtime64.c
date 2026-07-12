// Function: _localtime64
// Address: 0xa8d85c
// Size: 0x6
// Prototype: struct tm *__cdecl(const __time64_t *Time)

// attributes: thunk
struct tm *__cdecl localtime64(const __time64_t *Time)
{
  return _localtime64(Time);
}


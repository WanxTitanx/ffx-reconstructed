// Function: _gmtime64
// Address: 0xa8d856
// Size: 0x6
// Prototype: struct tm *__cdecl(const __time64_t *Time)

// attributes: thunk
struct tm *__cdecl gmtime64(const __time64_t *Time)
{
  return _gmtime64(Time);
}


// Function: _mktime64
// Address: 0xa8d862
// Size: 0x6
// Prototype: __time64_t __cdecl(struct tm *Tm)

// attributes: thunk
__time64_t __cdecl mktime64(struct tm *Tm)
{
  return _mktime64(Tm);
}


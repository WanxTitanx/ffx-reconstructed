// Function: strtod
// Address: 0xa8d7de
// Size: 0x6
// Prototype: double __cdecl(const char *String, char **EndPtr)

// attributes: thunk
double __cdecl strtod(const char *String, char **EndPtr)
{
  return __imp_strtod(String, EndPtr);
}


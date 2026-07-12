// Function: strtol
// Address: 0xa8d8a8
// Size: 0x6
// Prototype: int __cdecl(const char *String, char **EndPtr, int Radix)

// attributes: thunk
int __cdecl strtol(const char *String, char **EndPtr, int Radix)
{
  return __imp_strtol(String, EndPtr, Radix);
}


// Function: getenv
// Address: 0xa8d838
// Size: 0x6
// Prototype: char *__cdecl(const char *VarName)

// attributes: thunk
char *__cdecl getenv(const char *VarName)
{
  return __imp_getenv(VarName);
}


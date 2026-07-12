// Function: strerror
// Address: 0xa8d742
// Size: 0x6
// Prototype: char *__cdecl(int ErrorMessage)

// attributes: thunk
char *__cdecl strerror(int ErrorMessage)
{
  return __imp_strerror(ErrorMessage);
}


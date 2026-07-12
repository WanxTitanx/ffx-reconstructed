// Function: freopen
// Address: 0xa8d730
// Size: 0x6
// Prototype: FILE *__cdecl(const char *FileName, const char *Mode, FILE *Stream)

// attributes: thunk
FILE *__cdecl freopen(const char *FileName, const char *Mode, FILE *Stream)
{
  return __imp_freopen(FileName, Mode, Stream);
}


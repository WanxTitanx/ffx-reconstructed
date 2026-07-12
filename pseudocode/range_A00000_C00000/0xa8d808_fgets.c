// Function: fgets
// Address: 0xa8d808
// Size: 0x6
// Prototype: char *__cdecl(char *Buffer, int MaxCount, FILE *Stream)

// attributes: thunk
char *__cdecl fgets(char *Buffer, int MaxCount, FILE *Stream)
{
  return __imp_fgets(Buffer, MaxCount, Stream);
}


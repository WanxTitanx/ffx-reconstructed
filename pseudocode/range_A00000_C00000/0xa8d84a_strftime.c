// Function: strftime
// Address: 0xa8d84a
// Size: 0x6
// Prototype: size_t __cdecl(char *Buffer, size_t SizeInBytes, const char *Format, const struct tm *Tm)

// attributes: thunk
size_t __cdecl strftime(char *Buffer, size_t SizeInBytes, const char *Format, const struct tm *Tm)
{
  return __imp_strftime(Buffer, SizeInBytes, Format, Tm);
}


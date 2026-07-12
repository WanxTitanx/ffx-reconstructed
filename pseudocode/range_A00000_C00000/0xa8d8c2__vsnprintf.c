// Function: _vsnprintf
// Address: 0xa8d8c2
// Size: 0x6
// Prototype: int __cdecl(char *const Buffer, const size_t BufferCount, const char *const Format, va_list ArgList)

// attributes: thunk
int __cdecl vsnprintf(char *const Buffer, const size_t BufferCount, const char *const Format, va_list ArgList)
{
  return _vsnprintf(Buffer, BufferCount, Format, ArgList);
}


// Function: _popen
// Address: 0xa8d820
// Size: 0x6
// Prototype: FILE *__cdecl(const char *Command, const char *Mode)

// attributes: thunk
FILE *__cdecl popen(const char *Command, const char *Mode)
{
  return _popen(Command, Mode);
}


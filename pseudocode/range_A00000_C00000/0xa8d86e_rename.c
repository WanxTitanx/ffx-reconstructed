// Function: rename
// Address: 0xa8d86e
// Size: 0x6
// Prototype: int __cdecl(const char *OldFilename, const char *NewFilename)

// attributes: thunk
int __cdecl rename(const char *OldFilename, const char *NewFilename)
{
  return __imp_rename(OldFilename, NewFilename);
}


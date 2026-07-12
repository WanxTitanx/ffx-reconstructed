// Function: setlocale
// Address: 0xa8d832
// Size: 0x6
// Prototype: char *__cdecl(int Category, const char *Locale)

// attributes: thunk
char *__cdecl setlocale(int Category, const char *Locale)
{
  return __imp_setlocale(Category, Locale);
}


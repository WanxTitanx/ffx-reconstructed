/*
 * Function: FFX_Font_GetSafeColorKey
 * Address:   0x8ACEE0
 * Prototype: int FFX_Font_GetSafeColorKey()
 *
 * Returns safe color key from dword_C59554.
 * Initializes to 0 if uninitialized (-1).
 *
 * Referenced data:
 *   dword_C59554 - color key state (-1 = uninitialized)
 */

int FFX_Font_GetSafeColorKey()
{
  int result; // eax

  result = dword_C59554 != -1 ? dword_C59554 : 0;
  dword_C59554 = result;
  return result;
}

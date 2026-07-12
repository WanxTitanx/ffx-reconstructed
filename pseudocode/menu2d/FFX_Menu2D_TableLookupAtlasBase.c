/*
 * Function: FFX_Menu2D_TableLookupAtlasBase
 * Address:   0x8FA450
 * Prototype: _DWORD *__cdecl FFX_Menu2D_TableLookupAtlasBase(unsigned int a1)
 *
 * Looks up atlas base data from dword_C5C2C8 table.
 * Used for battle atlas (ID 16128) sprite data lookups.
 *
 * Callees:
 *   FFX_Menu2D_TableLookupCopy
 */

_DWORD *__cdecl FFX_Menu2D_TableLookupAtlasBase(unsigned int a1)
{
  return FFX_Menu2D_TableLookupCopy(dword_C5C2C8, a1);
}

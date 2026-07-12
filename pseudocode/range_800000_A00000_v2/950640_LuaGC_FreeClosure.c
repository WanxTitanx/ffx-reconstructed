// Function: LuaGC_FreeClosure
// Address: 0x950640
int __cdecl LuaGC_FreeClosure(int a1, _DWORD *a2)
{
  LuaStack_FreeBlocks((int)a2, a2[7]);
  if ( a2[7] )
  {
    a2[4] = a2 + 18;
    LuaGC_FreeUpvalList((int)a2);
    LuaAlloc_Realloc((int)a2, a2[7], 8 * a2[8], 0);
  }
  return LuaAlloc_Realloc(a1, (int)a2, 112, 0);
}

// Function: LuaGC_FreeUpvalList
// Address: 0x950600
int __cdecl LuaGC_FreeUpvalList(int a1)
{
  int v1; // eax
  int v2; // esi
  int result; // eax

  v1 = *(_DWORD *)(a1 + 16);
  v2 = *(_DWORD *)(v1 + 12);
  *(_DWORD *)(v1 + 12) = 0;
  for ( result = v2; v2; result = v2 )
  {
    v2 = *(_DWORD *)(v2 + 12);
    LuaAlloc_Realloc(a1, result, 40, 0);
  }
  return result;
}

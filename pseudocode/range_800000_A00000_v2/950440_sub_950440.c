// Function: sub_950440
// Address: 0x950440
int __cdecl sub_950440(_DWORD *a1)
{
  int v1; // edi

  v1 = a1[3];
  LuaStack_FreeBlocks((int)a1, a1[7]);
  sub_94ED40(a1);
  LuaAlloc_Realloc((int)a1, *(_DWORD *)(a1[3] + 24), 4 * *(_DWORD *)(a1[3] + 32), 0);
  *(_DWORD *)(v1 + 116) = LuaAlloc_Realloc((int)a1, *(_DWORD *)(v1 + 116), *(_DWORD *)(v1 + 124), 0);
  *(_DWORD *)(v1 + 124) = 0;
  if ( a1[7] )
  {
    a1[4] = a1 + 18;
    LuaGC_FreeUpvalList((int)a1);
    LuaAlloc_Realloc((int)a1, a1[7], 8 * a1[8], 0);
  }
  return (*(int (__cdecl **)(_DWORD, _DWORD *, int, _DWORD))v1)(*(_DWORD *)(v1 + 4), a1, 372, 0);
}

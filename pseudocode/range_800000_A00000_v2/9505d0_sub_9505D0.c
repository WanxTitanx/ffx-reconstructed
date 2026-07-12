// Function: sub_9505D0
// Address: 0x9505d0
int __cdecl sub_9505D0(int a1)
{
  int result; // eax

  result = LuaAlloc_Realloc(a1, 0, 0, 40);
  *(_DWORD *)(*(_DWORD *)(a1 + 16) + 12) = result;
  *(_DWORD *)(result + 8) = *(_DWORD *)(a1 + 16);
  *(_DWORD *)(result + 12) = 0;
  return result;
}

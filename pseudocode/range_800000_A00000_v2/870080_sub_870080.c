// Function: sub_870080
// Address: 0x870080
int __cdecl sub_870080(int a1)
{
  int Base; // eax

  Base = j_FFX_SceneState_GetBase();
  if ( a1 / 32 >= 2 )
    return 0;
  *(_DWORD *)(Base + 4 * (a1 / 32) + 24) |= 1 << (a1 % 32);
  return 1;
}

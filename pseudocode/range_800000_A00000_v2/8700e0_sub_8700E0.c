// Function: sub_8700E0
// Address: 0x8700e0
int __cdecl sub_8700E0(__int16 a1)
{
  int result; // eax

  result = j_FFX_SceneState_GetBase();
  *(_WORD *)(result + 212) = a1;
  *(_BYTE *)(result + 214) = 1;
  return result;
}

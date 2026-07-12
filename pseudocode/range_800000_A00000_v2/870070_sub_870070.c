// Function: sub_870070
// Address: 0x870070
int __cdecl sub_870070(char a1)
{
  int result; // eax

  result = j_FFX_SceneState_GetBase();
  *(_BYTE *)(result + 18) = a1;
  return result;
}

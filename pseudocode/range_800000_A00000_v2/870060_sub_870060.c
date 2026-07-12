// Function: sub_870060
// Address: 0x870060
int __cdecl sub_870060(char a1)
{
  int result; // eax

  result = j_FFX_SceneState_GetBase();
  *(_BYTE *)(result + 17) = a1;
  return result;
}

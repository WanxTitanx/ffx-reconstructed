// Function: sub_93C3D0
// Address: 0x93c3d0
int __cdecl sub_93C3D0(int a1)
{
  int result; // eax

  result = *(_DWORD *)(a1 + 40);
  *(_DWORD *)(a1 + 40) = 0;
  return result;
}

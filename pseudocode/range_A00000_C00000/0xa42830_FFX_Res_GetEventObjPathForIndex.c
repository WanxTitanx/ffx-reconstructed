// Function: FFX_Res_GetEventObjPathForIndex
// Address: 0xa42830
// Size: 0x17
// Prototype: int __cdecl(int)

// Event object path resolver by index.
int __cdecl FFX_Res_GetEventObjPathForIndex(int a1)
{
  _DWORD *CoreWorkPtr; // eax

  CoreWorkPtr = FFX_Btl_GetCoreWorkPtr(); /*0xa42833*/
  return sub_A42C00(a1 + CoreWorkPtr[8]); /*0xa42841*/
}
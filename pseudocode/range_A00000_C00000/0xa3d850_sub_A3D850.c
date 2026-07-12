// Function: sub_A3D850
// Address: 0xa3d850
// Size: 0xa2
// Prototype: int __stdcall(char ArgList, int, int, int, int)

int __thiscall sub_A3D850(_DWORD *this, const char *ArgList, int a3, int a4, int a5, int a6)
{
  int v8; // eax
  int v9; // ebx

  if ( !ArgList )
    return 5;
  v8 = IggyPlayerCreateFromFileAndPlay(ArgList, 0);
  *this = v8;
  if ( !v8 )
    return 9;
  v9 = IggyPlayerProperties(v8);
  if ( v9 )
  {
    Phyre_DebugPrintf(2, "Playing: %s:\n", ArgList);
    Phyre_DebugPrintf(2, "\tMovie width (in pixels)  : %d\n", *(_DWORD *)v9);
    Phyre_DebugPrintf(2, "\tMovie height (in pixels) : %d\n", *(_DWORD *)(v9 + 4));
    Phyre_DebugPrintf(2, "\tMovie framerate (in fps) : %f\n", *(float *)(v9 + 12));
  }
  *(this + 3) = a5;
  *(this + 4) = a6;
  *(this + 5) = a3;
  *(this + 6) = a4;
  return 0;
}


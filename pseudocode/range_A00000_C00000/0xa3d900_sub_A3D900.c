// Function: sub_A3D900
// Address: 0xa3d900
// Size: 0xa6
// Prototype: 

int __thiscall sub_A3D900(_DWORD *this, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v10; // eax
  float *v11; // eax
  float *v12; // edi

  if ( !a6 )
    return 5;
  v10 = IggyPlayerCreateFromMemory(a6, a7, 0);
  *this = v10;
  if ( !v10 )
    return 9;
  IggyPlayerInitializeAndTickRS(v10);
  IggyPlayerPlay(*this);
  v11 = (float *)IggyPlayerProperties(*this);
  v12 = v11;
  if ( v11 )
  {
    Phyre_DebugPrintf(2, "\tMovie width (in pixels)  : %d\n", *(_DWORD *)v11);
    Phyre_DebugPrintf(2, "\tMovie height (in pixels) : %d\n", *((_DWORD *)v12 + 1));
    Phyre_DebugPrintf(2, "\tMovie framerate (in fps) : %f\n", v12[3]);
  }
  *(this + 3) = a4;
  *(this + 4) = a5;
  *(this + 5) = a2;
  *(this + 6) = a3;
  return 0;
}


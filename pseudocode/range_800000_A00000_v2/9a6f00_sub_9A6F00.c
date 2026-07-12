// Function: sub_9A6F00
// Address: 0x9a6f00
int __thiscall sub_9A6F00(int this, _DWORD *a2, _DWORD *a3, float a4)
{
  int result; // eax

  if ( *(float *)(this + 48) > (double)a4 )
  {
    *(_BYTE *)(this + 52) = 1;
    *(_DWORD *)(this + 16) = *a2;
    *(_DWORD *)(this + 20) = a2[1];
    *(_DWORD *)(this + 24) = a2[2];
    *(_DWORD *)(this + 28) = a2[3];
    *(_DWORD *)(this + 32) = *a3;
    *(_DWORD *)(this + 36) = a3[1];
    *(_DWORD *)(this + 40) = a3[2];
    result = a3[3];
    *(_DWORD *)(this + 44) = result;
    *(float *)(this + 48) = a4;
  }
  return result;
}

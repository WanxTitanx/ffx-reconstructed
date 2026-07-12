// Function: sub_A3E1F0
// Address: 0xa3e1f0
// Size: 0xb3
// Prototype: int __stdcall(char ArgList)

int __thiscall sub_A3E1F0(_DWORD *this, int ArgList)
{
  _DWORD *v4; // eax
  _DWORD *v5; // eax
  char v6; // cl
  int v7; // [esp+0h] [ebp-18h]

  if ( !ArgList || *(this + 4) )
    return -1;
  v4 = (_DWORD *)FFX_Memory_Alloc_w(8u, v7);
  if ( v4 )
    v5 = FFX_FileIO_DeviceStructInit(v4, ArgList, 1, 0, 0, 1);
  else
    v5 = 0;
  *(this + 4) = v5;
  if ( v5 )
  {
    *(this + 2) = sub_607F80(v5);
    *(this + 3) = 0;
    v6 = 1;
  }
  else
  {
    v6 = 0;
  }
  return v6 == 0;
}


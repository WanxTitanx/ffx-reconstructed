// Function: sub_A3D7F0
// Address: 0xa3d7f0
// Size: 0x5c
// Prototype: 

int __thiscall sub_A3D7F0(_DWORD *this, int a2)
{
  int result; // eax
  int v3; // ebx
  unsigned int v4; // esi
  int v5; // edi
  _DWORD *this_1; // [esp+4h] [ebp-14h]
  _BYTE v7[12]; // [esp+8h] [ebp-10h] BYREF

  result = a2;
  v3 = *(_DWORD *)(a2 + 4);
  this_1 = this;
  if ( v3 )
  {
    if ( *this )
    {
      v4 = 0;
      if ( *(_DWORD *)(v3 + 8) )
      {
        v5 = v3 + 12;
        do
        {
          result = IggyPlayerDispatchEventRS(*this, v5, v7);
          this = this_1;
          ++v4;
          v5 += 24;
        }
        while ( v4 < *(_DWORD *)(v3 + 8) );
      }
    }
  }
  return result;
}


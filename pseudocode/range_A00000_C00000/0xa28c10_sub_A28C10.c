// Function: sub_A28C10
// Address: 0xa28c10
// Size: 0xf1
// Prototype: 

int __thiscall sub_A28C10(int this, _DWORD *a2, int a3)
{
  int v4; // ecx
  int v5; // edx
  int v6; // ecx
  int v7; // edx
  int result; // eax
  _BYTE v9[24]; // [esp+Ch] [ebp-1Ch] BYREF

  if ( *(_BYTE *)(this + 112) )
  {
    if ( *a2 == 7 )
    {
      IggyMakeEventNone(v9);
      IggyMakeEventMouseMove(v9, a2[2] - *(_DWORD *)(this + 132), a2[3] - *(_DWORD *)(this + 136));
      IggyPlayerDispatchEventRS(**(_DWORD **)(this + 108), v9, a3);
      v4 = a2[2];
      v5 = *(_DWORD *)(this + 132);
      if ( v4 <= v5
        || v4 >= v5 + *(_DWORD *)(this + 140)
        || (v6 = a2[3], v7 = *(_DWORD *)(this + 136), v6 <= v7)
        || v6 >= v7 + *(_DWORD *)(this + 144) )
      {
        *(_BYTE *)(this + 148) = 0;
        return 0;
      }
      else
      {
        *(_BYTE *)(this + 148) = 1;
        return 1;
      }
    }
    else
    {
      return IggyPlayerDispatchEventRS(**(_DWORD **)(this + 108), a2, a3);
    }
  }
  return result;
}


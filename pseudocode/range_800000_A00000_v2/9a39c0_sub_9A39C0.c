// Function: sub_9A39C0
// Address: 0x9a39c0
int __thiscall sub_9A39C0(int this, int a2)
{
  int result; // eax

  result = *(_DWORD *)(this + 16) + *(_DWORD *)(this + 56);
  if ( !result )
  {
    sub_9882D0((_DWORD *)(this + 4));
    result = sub_9882D0((_DWORD *)(this + 44));
    *(_WORD *)(this + 153) = 256;
    *(_DWORD *)(this + 104) = 0;
    *(_DWORD *)(this + 124) = 0;
    *(_DWORD *)(this + 108) = 1;
    *(_DWORD *)(this + 112) = 0;
    *(_DWORD *)(this + 116) = 10;
    *(_DWORD *)(this + 120) = 1;
    *(_DWORD *)(this + 128) = 0;
    *(_DWORD *)(this + 132) = 0;
    *(_DWORD *)(this + 136) = 0;
    *(_DWORD *)(this + 148) = 0;
    *(_DWORD *)(this + 140) = 0;
    *(_DWORD *)(this + 144) = 0;
    *(_DWORD *)(this + 84) = 0;
    *(_DWORD *)(this + 88) = 0;
    *(_DWORD *)(this + 92) = 0;
  }
  return result;
}

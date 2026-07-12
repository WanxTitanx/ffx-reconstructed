// Function: sub_9A4760
// Address: 0x9a4760
int __thiscall sub_9A4760(_DWORD *this, int a2)
{
  _DWORD *dst; // edi
  int result; // eax

  dst = this + 72 * a2 + 4;
  if ( dst[27] && unk_193F644 )
  {
    unk_193F644(dst[27]);
    dst[27] = 0;
  }
  result = *(this + 294) - 1;
  if ( a2 != result )
  {
    result *= 288;
    qmemcpy(dst, (char *)this + result + 16, 0x120u);
    *(_DWORD *)((char *)this + result + 124) = 0;
    *(_DWORD *)((char *)this + result + 236) = 0;
    *(_DWORD *)((char *)this + result + 268) = 0;
    *(_DWORD *)((char *)this + result + 300) = 0;
    *(_DWORD *)((char *)this + result + 128) = 0;
    *((_BYTE *)this + result + 132) = 0;
    *(_DWORD *)((char *)this + result + 136) = 0;
    *(_DWORD *)((char *)this + result + 140) = 0;
    *(_DWORD *)((char *)this + result + 160) = 0;
  }
  --*(this + 294);
  return result;
}

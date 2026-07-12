// Function: sub_9AFAB0
// Address: 0x9afab0
int __thiscall sub_9AFAB0(_DWORD *this)
{
  _DWORD *v2; // ecx
  int n128; // esi
  int result; // eax

  *(this + 12) = 0;
  *(this + 13) = 0;
  *(this + 14) = 0;
  *this = 9;
  *(this + 15) = 0;
  *(this + 16) = 0;
  *(this + 2580) = 0;
  v2 = this + 2564;
  n128 = 128;
  do
  {
    v2[12] = 0;
    v2[13] = *(this + 2583);
    result = *(this + 2583);
    if ( result )
      *(_DWORD *)(result + 48) = v2;
    ++*(this + 2584);
    *(this + 2583) = v2;
    v2 -= 16;
    --n128;
  }
  while ( n128 );
  return result;
}

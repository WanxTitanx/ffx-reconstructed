// Function: sub_A267F0
// Address: 0xa267f0
// Size: 0x7f
// Prototype: int __thiscall(_DWORD)

int __thiscall sub_A267F0(int this)
{
  int i; // ebx
  unsigned int v3; // esi
  int v4; // ecx
  int result; // eax

  if ( *(_BYTE *)(this + 48) )
  {
    sub_5BB2D0(0, 0);
    sub_5BB750(0);
    sub_5B5FD0(0);
    if ( *(_DWORD *)(this + 4) )
    {
      for ( i = 0; i < 3; ++i )
      {
        v3 = 0;
        if ( (*(_DWORD *)(this + 8) & 0x7FFFFFFF) != 0 )
        {
          do
          {
            v4 = *(_DWORD *)(*(_DWORD *)(this + 12) + 4 * v3);
            if ( v4 )
            {
              if ( *(_DWORD *)(v4 + 152) == i )
                sub_A28EB0();
            }
            ++v3;
          }
          while ( v3 < (*(_DWORD *)(this + 8) & 0x7FFFFFFFu) );
        }
      }
      sub_A362E0(*(_DWORD *)(this + 4));
    }
    return sub_5B6AF0(1);
  }
  return result;
}


// Function: sub_9A01E0
// Address: 0x9a01e0
void *__thiscall sub_9A01E0(void *this)
{
  int v2; // eax
  int v3; // edi
  _DWORD *n8; // edx
  _DWORD *v5; // ecx
  int v7; // [esp+14h] [ebp-10h]

  *(_DWORD *)this = &btHashedOverlappingPairCache::`vftable';
  *((_BYTE *)this + 20) = 1;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_BYTE *)this + 28) = 0;
  *((_BYTE *)this + 48) = 1;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_BYTE *)this + 68) = 1;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 15) = 0;
  *((_DWORD *)this + 18) = 0;
  if ( *((int *)this + 3) < 2 )
  {
    v2 = sub_9D4CE0(32, 16);
    v3 = *((_DWORD *)this + 2);
    v7 = v2;
    if ( v3 > 0 )
    {
      n8 = (_DWORD *)(v2 + 8);
      do
      {
        if ( n8 != (_DWORD *)8 )
        {
          v5 = (_DWORD *)((char *)n8 + -8 - v2 + *((_DWORD *)this + 4));
          *(n8 - 2) = *v5;
          *(n8 - 1) = v5[1];
          *n8 = v5[2];
          n8[1] = v5[3];
        }
        n8 += 4;
        --v3;
      }
      while ( v3 );
    }
    if ( *((_DWORD *)this + 4) )
    {
      if ( *((_BYTE *)this + 20) )
        sub_9D4D50(*((_DWORD *)this + 4));
      *((_DWORD *)this + 4) = 0;
    }
    *((_BYTE *)this + 20) = 1;
    *((_DWORD *)this + 4) = v7;
    *((_DWORD *)this + 3) = 2;
  }
  sub_9A0E50(this);
  return this;
}

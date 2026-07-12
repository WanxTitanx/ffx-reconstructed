// Function: sub_A19CF0
// Address: 0xa19cf0
// Size: 0x1e6
// Prototype: 

int __thiscall sub_A19CF0(_DWORD *this)
{
  int v2; // esi
  int result; // eax
  int v4; // esi
  int v5; // esi
  int v6; // esi

  v2 = sub_42FC20(60);
  if ( v2 )
    sub_5833D0();
  else
    v2 = 0;
  *(this + 4082) = v2;
  if ( (*(_DWORD *)(v2 + 12) & 0x7FFFFFFF) != 8 && !sub_599C10(8) )
    *(_DWORD *)(v2 + 4) = 0;
  result = sub_58EFB0(10240, 0);
  if ( !result )
  {
    v4 = sub_42FC20(60);
    if ( v4 )
      sub_5833D0();
    else
      v4 = 0;
    *(this + 4083) = v4;
    if ( (*(_DWORD *)(v4 + 12) & 0x7FFFFFFF) != 8 && !sub_599C10(8) )
      *(_DWORD *)(v4 + 4) = 0;
    result = sub_58EFB0(3072, 0);
    if ( !result )
    {
      if ( (unk_C9628C[0] & 1) == 0 )
      {
        unk_C9628C[0] |= 1u;
        PhyreSingleton_RegisterAtExit(byte_C94F00);
        atexit(PhyreSingleton_AtExit_C94F00_Cleanup);
      }
      if ( n45056 < 45056 )
        return 0;
      v5 = sub_42FC20(72);
      if ( v5 )
        sub_584330();
      else
        v5 = 0;
      *(this + 4109) = v5;
      result = sub_58F440(0x4000, 160, 10, 0);
      if ( !result )
      {
        v6 = sub_42FC20(72);
        if ( v6 )
          sub_584330();
        else
          v6 = 0;
        *(this + 4110) = v6;
        result = sub_58F440(4, 4, 8, 0);
        if ( !result )
          return 0;
      }
    }
  }
  return result;
}


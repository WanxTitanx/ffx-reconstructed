// Function: sub_A3BA50
// Address: 0xa3ba50
// Size: 0x7f
// Prototype: 

int __thiscall sub_A3BA50(_DWORD *this, int a2, _BYTE *a3, int a4)
{
  int result; // eax
  _DWORD v6[2]; // [esp+8h] [ebp-Ch] BYREF
  int v7; // [esp+10h] [ebp-4h]

  if ( *a3 )
  {
    IggyAudioInstallMP3Decoder();
    IggyAudioUseDirectSound();
  }
  result = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 8))(a2);
  if ( !result )
  {
    result = FFX_Ps3Tex_ListClear(a2);
    if ( !result )
    {
      v6[1] = a4;
      v6[0] = this;
      v7 = 0;
      result = sub_5B5A20(sub_A34AE0, v6);
      if ( !result )
      {
        result = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 8))(a2);
        if ( !result )
        {
          result = FFX_Ps3Tex_ListClear(a2);
          if ( !result )
          {
            result = v7;
            *(this + 1) = a2;
          }
        }
      }
    }
  }
  return result;
}


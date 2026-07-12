// Function: sub_A59350
// Address: 0xa59350
// Size: 0x140
// Prototype: 

int __cdecl sub_A59350(int a1)
{
  __int16 v1; // ax
  int result; // eax
  int v3; // ecx

  v1 = *(_WORD *)(dword_2305834[0] + 71270);
  if ( v1 <= 0 )
  {
    result = a1;
    if ( a1 )
      return sub_A594C0(a1, 72, 35);
  }
  else
  {
    *(_WORD *)(dword_2305834[0] + 71270) = v1 - 1;
    if ( *(_WORD *)(dword_2305834[0] + 71268) )
    {
      if ( (unsigned int)(*(__int16 *)(dword_2305834[0] + 71268) - 1) <= 1 )
      {
        sub_8B84A0(7, 0, 0);
        sub_8B84C0(7, 0, *(_DWORD *)(dword_2305834[0] + 71256));
        sub_8B84A0(7, 1, 0);
        sub_8B84C0(7, 1, *(_DWORD *)(dword_2305834[0] + 71260));
      }
    }
    else
    {
      sub_8B84A0(7, 0, 0);
      sub_8B84C0(7, 0, *(_DWORD *)(dword_2305834[0] + 71256));
      sub_8B84A0(7, 1, 0);
      sub_8B84C0(7, 1, *(_DWORD *)(dword_2305834[0] + 71260));
      sub_8B84A0(7, 2, 1);
      sub_8B84C0(7, 2, *(_DWORD *)(dword_2305834[0] + 71264));
    }
    result = dword_2305834[0];
    v3 = *(_DWORD *)(dword_2305834[0] + 71252);
    if ( v3 )
    {
      result = sub_8E8FB0(unk_230FD2C + 16, 7, v3, 72, 35, 0, 0, 128, 128, 128, *(_BYTE *)(dword_2305834[0] + 71097), 0);
      unk_230FD2C = result;
    }
  }
  return result;
}


// Function: sub_A35B40
// Address: 0xa35b40
// Size: 0x82
// Prototype: 

int __cdecl sub_A35B40(_DWORD *a1, _DWORD *a2)
{
  bool v2; // zf
  int result; // eax

  *a1 = *a2;
  v2 = *a1 == 0;
  result = a2[1];
  a1[1] = result;
  if ( !v2 )
  {
    result = (*(int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD *))(*(_DWORD *)*dword_1A858B4 + 60))(
               *dword_1A858B4,
               *a1,
               a1[1],
               0,
               a1 + 1);
    if ( result < 0 )
    {
      if ( result == -2147024882 )
        result = IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreatePixelShader", &byte_B8FBDB);
      else
        result = IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreatePixelShader", &byte_B8FBDB, result);
      a1[1] = 0;
    }
  }
  return result;
}


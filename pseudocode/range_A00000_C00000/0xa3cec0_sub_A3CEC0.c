// Function: sub_A3CEC0
// Address: 0xa3cec0
// Size: 0x74
// Prototype: 

int __cdecl sub_A3CEC0(int a1)
{
  int v1; // eax
  _DWORD v3[3]; // [esp+0h] [ebp-Ch] BYREF

  v1 = (*(int (__stdcall **)(_DWORD, int, _DWORD, int, _DWORD, _DWORD *))(*(_DWORD *)dword_1A858B4[1] + 56))(
         dword_1A858B4[1],
         a1,
         0,
         4,
         0,
         v3);
  if ( v1 >= 0 )
    return v3[0];
  if ( v1 == -2147024882 )
    IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "Map", "of buffer");
  else
    IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "Map", "of buffer", v1);
  return 0;
}


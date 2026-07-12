// Function: sub_A3C070
// Address: 0xa3c070
// Size: 0x79
// Prototype: 

int __cdecl sub_A3C070(int a1, int a2, char a3)
{
  int v3; // eax
  _DWORD v5[3]; // [esp+0h] [ebp-Ch] BYREF

  v3 = (*(int (__stdcall **)(int, int, _DWORD, int, _DWORD, _DWORD *))(*(_DWORD *)a1 + 56))(
         a1,
         a2,
         0,
         (a3 == 0) + 4,
         0,
         v5);
  if ( v3 >= 0 )
    return v5[0];
  if ( v3 == -2147024882 )
    IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "Map", "of buffer");
  else
    IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "Map", "of buffer", v3);
  return 0;
}


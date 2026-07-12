// Function: sub_A35A70
// Address: 0xa35a70
// Size: 0xc7
// Prototype: 

int __cdecl sub_A35A70(int a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int v5; // [esp+0h] [ebp-20h] BYREF
  _DWORD v6[6]; // [esp+4h] [ebp-1Ch] BYREF

  v6[0] = a1;
  v6[2] = a2;
  v2 = *dword_1A858B4;
  v6[1] = 2;
  v6[3] = 0x10000;
  v6[4] = 0;
  v6[5] = 0;
  v5 = 0;
  v3 = (*(int (__stdcall **)(int, _DWORD *, _DWORD, int *))(*(_DWORD *)v2 + 12))(v2, v6, 0, &v5);
  if ( v3 >= 0 )
    return v5;
  if ( v3 == -2147024882 )
    IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateBuffer", " creating dynamic vertex buffer");
  else
    IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateBuffer", " creating dynamic vertex buffer", v3);
  return 0;
}


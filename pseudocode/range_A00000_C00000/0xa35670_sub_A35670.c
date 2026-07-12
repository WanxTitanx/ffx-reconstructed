// Function: sub_A35670
// Address: 0xa35670
// Size: 0x102
// Prototype: 

int __cdecl sub_A35670(int *a1, int a2, int n9, int a4)
{
  int n7; // eax
  int v5; // eax
  int v6; // eax
  int v8; // [esp+4h] [ebp-110h] BYREF
  _DWORD v9[66]; // [esp+8h] [ebp-10Ch] BYREF

  memset(v9, 0, sizeof(v9));
  v9[2] = a2;
  n7 = n9;
  v9[3] = n9;
  v9[4] = a4;
  v9[5] = 1;
  if ( n9 == 9 )
    n7 = 7;
  v9[7] = a4;
  v9[6] = n7;
  v5 = *a1;
  v9[8] = 1;
  LOBYTE(v9[9]) = 15;
  v6 = (*(int (__stdcall **)(int *, _DWORD *, int *))(v5 + 80))(a1, v9, &v8);
  if ( v6 >= 0 )
    return v8;
  if ( v6 == -2147024882 )
    IggyGDrawSendWarning(0, "GDraw D3D out of memory in %s%s", "CreateBlendState", &byte_B8FBDB);
  else
    IggyGDrawSendWarning(0, "GDraw D3D error in %s%s: 0x%08x", "CreateBlendState", &byte_B8FBDB, v6);
  return 0;
}


// Function: sub_850770
// Address: 0x850770
int __cdecl sub_850770(_DWORD *a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int result; // eax
  int i; // esi
  char Buffer[128]; // [esp+Ch] [ebp-84h] BYREF

  v2 = sub_844CD0();
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
        sprintf(Buffer, "host0:EXEC:cmd /c dir \\ffx\\proj\\map\\btlmaster\\ /b > \\%s", "sugilist.tmp");
    }
    else
    {
      sprintf(Buffer, "host0:EXEC:cmd /c dir \\ffx\\proj\\map\\sugi\\data\\ /b > \\%s", "sugilist.tmp");
    }
  }
  else
  {
    sprintf(Buffer, "host0:EXEC:cmd /c dir \\ffx\\proj\\map\\master\\ /b > \\%s", "sugilist.tmp");
  }
  sub_8509E0(a1, (int)Buffer, 0);
  result = sub_849F40(a2, *a1);
  for ( i = 0; i < *a1; ++i )
    result = sub_849FD0(a2, i, *(_DWORD *)(a1[2] + 4 * i), i);
  return result;
}

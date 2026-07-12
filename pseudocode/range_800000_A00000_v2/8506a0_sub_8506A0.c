// Function: sub_8506A0
// Address: 0x8506a0
int __cdecl sub_8506A0(_DWORD *a1, int a2)
{
  int v2; // eax
  int v3; // eax
  int result; // eax
  int i; // esi
  int v6; // [esp-8h] [ebp-98h]
  int v7; // [esp-8h] [ebp-98h]
  int v8; // [esp-8h] [ebp-98h]
  char Buffer[128]; // [esp+Ch] [ebp-84h] BYREF

  v2 = sub_844CD0();
  if ( v2 )
  {
    v3 = v2 - 1;
    if ( v3 )
    {
      if ( v3 == 1 )
      {
        v6 = sub_844CF0(0);
        sprintf(Buffer, "host0:EXEC:cmd /c dir \\ffx\\proj\\map\\btlmaster\\%s\\ /b > \\%s", v6, "sugilist.tmp");
      }
    }
    else
    {
      v7 = sub_844CF0(0);
      sprintf(Buffer, "host0:EXEC:cmd /c dir \\ffx\\proj\\map\\sugi\\data\\%s\\ /b > \\%s", v7, "sugilist.tmp");
    }
  }
  else
  {
    v8 = sub_844CF0(0);
    sprintf(Buffer, "host0:EXEC:cmd /c dir \\ffx\\proj\\map\\master\\%s\\ /b > \\%s", v8, "sugilist.tmp");
  }
  sub_8509E0(a1, (int)Buffer, 0);
  result = sub_849F40(a2, *a1);
  for ( i = 0; i < *a1; ++i )
    result = sub_849FD0(a2, i, *(_DWORD *)(a1[2] + 4 * i), i);
  return result;
}

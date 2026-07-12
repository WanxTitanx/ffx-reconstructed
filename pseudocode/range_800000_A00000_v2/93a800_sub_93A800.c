// Function: sub_93A800
// Address: 0x93a800
int __cdecl sub_93A800(int a1, int a2)
{
  int result; // eax
  char Buffer[256]; // [esp+0h] [ebp-10Ch] BYREF
  char v4; // [esp+100h] [ebp-Ch] BYREF
  char v5; // [esp+101h] [ebp-Bh]
  char v6; // [esp+102h] [ebp-Ah]
  char v7; // [esp+103h] [ebp-9h]

  result = a1;
  if ( a1 )
  {
    result = sub_937960(a1, &v4, a2);
    if ( result )
    {
      if ( a2 )
        sprintf(Buffer, "/ffx/proj/map/btlmaster/%c%c%c%c/%s/3d/eff/", v4, v5, v6, v7, &v4);
      else
        sprintf(Buffer, "/ffx/proj/map/master/%c%c%c%c/%s/3d/eff/", v4, v5, v6, v7, &v4);
      return sub_93A890(Buffer);
    }
  }
  return result;
}

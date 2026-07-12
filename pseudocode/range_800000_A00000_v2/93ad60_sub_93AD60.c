// Function: sub_93AD60
// Address: 0x93ad60
int __cdecl sub_93AD60(int a1, char *Str)
{
  char *v2; // eax
  int v3; // edi
  const char *String1; // ebx
  int v5; // esi
  const char *mws; // eax
  _DWORD v8[2]; // [esp+8h] [ebp-8h]

  v2 = strrchr(Str, 46);
  if ( !v2 )
    return 0;
  v3 = -1;
  String1 = v2 + 1;
  v8[0] = "rsd";
  v8[1] = 0;
  v5 = 0;
  mws = "mws";
  while ( stricmp(String1, mws) )
  {
    mws = (const char *)v8[v5++];
    if ( !mws )
      goto LABEL_7;
  }
  v3 = v5;
LABEL_7:
  if ( v3 == 1 )
    return sub_93A280(a1, Str);
  else
    return 0;
}

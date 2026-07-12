// Function: sub_93ACB0
// Address: 0x93acb0
int __cdecl sub_93ACB0(int a1, char *Str2, int a3)
{
  const char *Str2_1; // edx
  size_t MaxCount; // edi
  int i_1; // eax
  int v6; // ebx
  int v7; // ecx
  char *v8; // eax
  _DWORD v9[2]; // [esp+8h] [ebp-10h] BYREF
  int v10; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v9[0] = 0;
  v9[1] = 0;
  v10 = 0;
  sub_8498E0(v9, a1);
  Str2_1 = Str2;
  MaxCount = strlen(Str2);
  i_1 = 0;
  v6 = 0;
  for ( i = 0; v6 < v9[0]; ++v6 )
  {
    if ( !strncmp(*(const char **)(v10 + 4 * v6), Str2_1, MaxCount) )
    {
      v7 = 0;
      if ( a3 > 0 )
      {
        v8 = (char *)(MaxCount + *(_DWORD *)(v10 + 4 * v6));
        do
        {
          if ( *v8 < 48 )
            break;
          if ( *v8 > 57 )
            break;
          ++v7;
          ++v8;
        }
        while ( v7 < a3 );
      }
      i_1 = i;
      if ( v7 == a3 )
        i_1 = ++i;
    }
    else
    {
      i_1 = i;
    }
    Str2_1 = Str2;
  }
  return i_1;
}

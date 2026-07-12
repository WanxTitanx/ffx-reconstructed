// Function: sub_93A910
// Address: 0x93a910
int __cdecl sub_93A910(const char *a1, const char *a2)
{
  void (*__imp_sprintf)(char *const, const char *const, ...); // ebx
  const char *v3; // edi
  int result; // eax
  int v5; // esi
  int v6; // eax
  _DWORD v7[2]; // [esp+10h] [ebp-124h] BYREF
  int v8; // [esp+18h] [ebp-11Ch]
  int v9; // [esp+1Ch] [ebp-118h]
  char Buffer[256]; // [esp+20h] [ebp-114h] BYREF
  char Buffer_1[16]; // [esp+120h] [ebp-14h] BYREF

  __imp_sprintf = (void (*)(char *const, const char *const, ...))sprintf;
  v3 = a2;
  v7[0] = 0;
  v7[1] = 0;
  v8 = 0;
  sprintf(Buffer, "ls -l %s", a1);
  memset(off_C498DC, 0, 0x10000u);
  if ( sub_84EDE0((int)Buffer, off_C498DC) >= 0 )
    sub_8498E0(v7, a1);
  result = 0;
  v9 = 0;
  do
  {
    __imp_sprintf(Buffer_1, "%s%d_00.tm2", v3, result);
    v5 = 0;
    if ( v7[0] <= 0 )
    {
LABEL_10:
      result = v9;
    }
    else
    {
      while ( 1 )
      {
        v6 = strcmp(*(const char **)(v8 + 4 * v5), Buffer_1);
        if ( v6 )
          v6 = v6 < 0 ? -1 : 1;
        if ( !v6 )
          break;
        if ( ++v5 >= v7[0] )
        {
          __imp_sprintf = (void (*)(char *const, const char *const, ...))sprintf;
          goto LABEL_10;
        }
      }
      __imp_sprintf = (void (*)(char *const, const char *const, ...))sprintf;
      result = ++v9;
    }
    v3 = a2;
  }
  while ( v5 != v7[0] );
  return result;
}

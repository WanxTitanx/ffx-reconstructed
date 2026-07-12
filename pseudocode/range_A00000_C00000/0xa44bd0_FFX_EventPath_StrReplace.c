// Function: FFX_EventPath_StrReplace
// Address: 0xa44bd0
// Size: 0xfc
// Prototype: int __cdecl(char *Str, char *SubStr, const char *Src)

int __cdecl FFX_EventPath_StrReplace(char *Str, char *SubStr, const char *Src)
{
  char *Str_1; // esi
  unsigned int v4; // ebx
  int result; // eax
  int v6; // edi
  char *v7; // eax
  unsigned int v8; // ecx
  int v9; // eax
  char *v10; // edi
  char *v11; // edi
  int v12; // edi
  char v13; // al
  int v14; // [esp+0h] [ebp-20h]
  int v15; // [esp+0h] [ebp-20h]
  size_t v16; // [esp+10h] [ebp-10h]
  unsigned int Size_1; // [esp+14h] [ebp-Ch]
  size_t Size; // [esp+18h] [ebp-8h]
  int v19; // [esp+1Ch] [ebp-4h]

  Str_1 = Str;
  v16 = strlen(Str) + 1;
  v4 = strlen(SubStr);
  Size_1 = strlen(Src);
  result = FFX_Memory_Alloc(v16, v14);
  v19 = result;
  v6 = result;
  if ( result )
  {
    v7 = strstr(Str, SubStr);
    if ( v7 )
    {
      v8 = Size_1 - v4;
      while ( 1 )
      {
        Size = v7 - Str_1;
        v16 += v8;
        v9 = sub_687200(v19, v16);
        if ( !v9 )
          break;
        v10 = (char *)(v9 - v19 + v6);
        v19 = v9;
        memmove(v10, Str_1, Size);
        v11 = &v10[Size];
        memmove(v11, Src, Size_1);
        v6 = (int)&v11[Size_1];
        Str_1 += v4 + Size;
        v7 = strstr(Str_1, SubStr);
        v8 = Size_1 - v4;
        if ( !v7 )
          goto LABEL_6;
      }
      FFX_Memory_Delete(v19, v15);
      return 0;
    }
    else
    {
LABEL_6:
      v12 = v6 - (_DWORD)Str_1;
      do
      {
        v13 = *Str_1;
        Str_1[v12] = *Str_1;
        ++Str_1;
      }
      while ( v13 );
      return v19;
    }
  }
  return result;
}


// Function: sub_93BEB0
// Address: 0x93beb0
int __cdecl sub_93BEB0(int a1, const char *Buffer_1, char *Str2, int n3)
{
  void (*__imp_sprintf)(char *const, const char *const, ...); // edi
  int i_2; // esi
  int i; // ebx
  unsigned __int16 n16_2; // cx
  unsigned __int16 n16_3; // ax
  void *v9; // eax
  const void *src; // esi
  size_t Size; // [esp-8h] [ebp-270h]
  int n16_4; // [esp-4h] [ebp-26Ch]
  int i_3; // [esp+10h] [ebp-258h]
  int i_1[9]; // [esp+14h] [ebp-254h] BYREF
  __int16 n16; // [esp+38h] [ebp-230h]
  int n16_1; // [esp+3Ah] [ebp-22Eh]
  int v18; // [esp+58h] [ebp-210h]
  char Buffer[256]; // [esp+64h] [ebp-204h] BYREF
  char Buffer_2[256]; // [esp+164h] [ebp-104h] BYREF

  i_3 = sub_93ACB0((int)Buffer_1, Str2, n3);
  sub_9237E0(i_1);
  __imp_sprintf = (void (*)(char *const, const char *const, ...))sprintf;
  sprintf(Buffer, "host:%s/%s%%0%dd.tm2", Buffer_1, Str2, n3);
  i_2 = i_3;
  for ( i = 0; i < i_2; ++i )
  {
    __imp_sprintf(Buffer_2, Buffer, i);
    if ( sub_923800(i_1, (int)Buffer_2) )
    {
      if ( i )
      {
        n16_3 = n16_1;
        n16_2 = n16;
      }
      else
      {
        sub_92D3E0(a1 + 32, 19, n16, n16_1, i_2);
        sub_92D3E0(a1 + 96, 0, 16, 16, i_2);
        n16_2 = n16;
        n16_3 = n16_1;
        *(_WORD *)(a1 + 16) = n16;
        *(_WORD *)(a1 + 18) = n16_3;
      }
      n16_4 = n16_3;
      Size = n16_2;
      v9 = (void *)sub_92D4F0(a1 + 32, i);
      sub_923AE0((int)i_1, v9, 0, 0, Size, n16_4);
      src = (const void *)unknown_libname_741(v18);
      qmemcpy((void *)sub_92D4F0(a1 + 96, i), src, 0x400u);
      i_2 = i_3;
      __imp_sprintf = (void (*)(char *const, const char *const, ...))sprintf;
    }
    else
    {
      nullsub_171("Error in %s, line %d: ", "..\\program\\src\\rcBg\\rcbgLoadText.c", 1558);
      nullsub_171("File not found.");
    }
  }
  return sub_923470(i_1);
}

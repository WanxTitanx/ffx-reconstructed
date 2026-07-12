// Function: sub_A42AB0
// Address: 0xa42ab0
// Size: 0xb6
// Prototype: 

void *__cdecl sub_A42AB0(int a1, DWORD *a2)
{
  int v2; // esi
  DWORD nNumberOfBytesToRead; // ebx
  void *lpBuffer; // edi
  int v6; // [esp+0h] [ebp-Ch]

  v2 = sub_62FBE0(a1, 1);
  if ( !v2 )
  {
    nullsub_34();
    sub_76F0B0("fd != 0", "..\\program\\lib\\src\\read_debug.c", 551);
  }
  nNumberOfBytesToRead = sub_62FA90(v2, 0, 2);
  sub_62FA90(v2, 0, 0);
  sub_887BD0();
  lpBuffer = (void *)FFX_Memory_Alloc(
                       ((((int)(nNumberOfBytesToRead + 3) >> 31) & 3) + nNumberOfBytesToRead + 3) & 0xFFFFFFFC,
                       v6);
  nullsub_33(0);
  IopDevice_ReadFile(v2, lpBuffer, nNumberOfBytesToRead);
  FFX_FileIO_IopDevice_Close(v2);
  nullsub_33(0);
  if ( a2 )
    *a2 = nNumberOfBytesToRead;
  return lpBuffer;
}


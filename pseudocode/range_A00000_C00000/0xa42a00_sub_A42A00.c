// Function: sub_A42A00
// Address: 0xa42a00
// Size: 0xab
// Prototype: 

void *__cdecl sub_A42A00(int a1, DWORD *a2)
{
  int v2; // edi
  DWORD nNumberOfBytesToRead; // ebx
  void *lpBuffer; // esi
  int v6; // [esp-18h] [ebp-24h]

  v2 = sub_62FBE0(a1, 1);
  if ( !v2 )
  {
    nullsub_34();
    sub_76F0B0("fd != 0", "..\\program\\lib\\src\\read_debug.c", 551);
  }
  nNumberOfBytesToRead = sub_62FA90(v2, 0, 2);
  sub_62FA90(v2, 0, 0);
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


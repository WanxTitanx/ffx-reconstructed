// Function: sub_8509E0
// Address: 0x8509e0
int __cdecl sub_8509E0(_DWORD *a1, int a2, int a3)
{
  char *j_1; // ebx
  const void *v4; // eax
  size_t Size_1; // esi
  int i; // esi
  char n10; // al
  int v8; // esi
  char *j; // ecx
  int v10; // eax
  int v11; // ecx
  int v13; // [esp-Ch] [ebp-64h]
  int v14; // [esp-Ch] [ebp-64h]
  int v15; // [esp+0h] [ebp-58h]
  int v16; // [esp+0h] [ebp-58h]
  int v17; // [esp+Ch] [ebp-4Ch]
  size_t Size; // [esp+10h] [ebp-48h] BYREF
  char Buffer[64]; // [esp+14h] [ebp-44h] BYREF

  Size = 0;
  j_1 = (char *)FFX_Memory_Alloc(0x10000u, v15);
  *j_1 = 0;
  nullsub_34();
  sub_62FBE0(a2, 0);
  nullsub_34();
  v4 = (const void *)sub_84F1C0("host0:sugilist.tmp", &Size);
  v17 = (int)v4;
  if ( v4 )
  {
    Size_1 = Size;
    if ( (int)Size < 0x10000 )
    {
      memcpy(j_1, v4, Size);
      j_1[Size_1] = 0;
      FFX_Memory_Delete(v17, v13);
    }
  }
  sprintf(Buffer, "host0:EXEC:cmd /c move /Y \\%s \\%s.prev", "sugilist.tmp", "sugilist.tmp");
  sub_62FBE0(Buffer, 0);
  if ( a1[2] )
  {
    for ( i = 0; i < a1[1]; ++i )
    {
      if ( *(_DWORD *)(a1[2] + 4 * i) )
        FFX_Memory_Delete(*(_DWORD *)(a1[2] + 4 * i), v16);
    }
    FFX_Memory_Delete(a1[2], v16);
    a1[2] = 0;
    a1[1] = 0;
  }
  n10 = *j_1;
  v8 = 0;
  for ( j = j_1; n10; ++j )
  {
    if ( n10 == 10 )
      ++v8;
    n10 = j[1];
  }
  a1[1] = v8;
  v10 = FFX_Memory_Alloc(4 * v8, v16);
  v11 = 0;
  for ( a1[2] = v10; v11 < v8; *(_DWORD *)(a1[2] + 4 * v11 - 4) = 0 )
    ++v11;
  *a1 = sub_850590(j_1, a1[2], a3);
  return FFX_Memory_Delete((int)j_1, v14);
}

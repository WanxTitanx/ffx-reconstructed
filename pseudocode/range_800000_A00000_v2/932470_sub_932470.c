// Function: sub_932470
// Address: 0x932470
int sub_932470()
{
  int result; // eax
  int v1; // esi
  int v2; // eax
  int v3; // eax
  int v4; // [esp+0h] [ebp-4h]

  result = *(_DWORD *)(unk_193C0F0 + 2224);
  v1 = *(_DWORD *)(unk_193C0F0 + 4 * result + 2160);
  if ( v1 != -1 )
  {
    *(_DWORD *)(unk_193C0F0 + 2232) = sub_830470(*(_DWORD *)(unk_193C0F0 + 4 * result + 2160));
    *(_DWORD *)(unk_193C0F0 + 2236) = 0;
    *(_DWORD *)(unk_193C0F0 + 2240) = 0;
    *(_DWORD *)(unk_193C0F0 + 2244) = 0;
    v2 = unknown_libname_741(*(_DWORD *)(unk_193C0F0 + 2248));
    if ( v2 )
      j_FFX_Memory_Delete_2(v2, v4);
    *(_DWORD *)(unk_193C0F0 + 2248) = unknown_libname_742(0);
    v3 = sub_9258A0(16 * *(_DWORD *)(unk_193C0F0 + 2232));
    *(_DWORD *)(unk_193C0F0 + 2248) = unknown_libname_742(v3);
    *(_DWORD *)(unk_193C0F0 + 2252) = 22;
    *(_DWORD *)(unk_193C0F0 + 2256) = 0;
    sub_82B400(v1, 256);
    result = unk_193C0F0;
    *(_DWORD *)(unk_193C0F0 + 2260) = 256;
  }
  return result;
}

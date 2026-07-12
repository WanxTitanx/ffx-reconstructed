// Function: sub_939040
// Address: 0x939040
int sub_939040()
{
  int *v0; // ebx
  int v1; // esi
  _DWORD *v3; // eax
  int v4; // edi
  int v5; // esi
  int v6; // eax
  int v7; // [esp+8h] [ebp-318h]
  _DWORD v8[4]; // [esp+Ch] [ebp-314h] BYREF
  char v9[256]; // [esp+1Ch] [ebp-304h] BYREF
  char Buffer_1[256]; // [esp+11Ch] [ebp-204h] BYREF
  char Buffer[5]; // [esp+21Ch] [ebp-104h] BYREF
  char v12[251]; // [esp+221h] [ebp-FFh] BYREF

  if ( unk_193BF80 )
    v0 = *(int **)unk_193BF80;
  else
    v0 = 0;
  sprintf(Buffer, "host:%s/bin/map2d.bin", (const char *)(unk_193C0F0 + 372));
  v1 = sub_62FBE0(Buffer, 2);
  v7 = v1;
  if ( v1 == -1 )
  {
    nullsub_171("Error in %s, line %d: ", "..\\program\\src\\rcBg\\rcbgSave.c", 89);
    return nullsub_171("Save(Bin.) Failed.");
  }
  else
  {
    memset(v8, 0, sizeof(v8));
    v8[0] = *(_DWORD *)std::_Get_future_error_what(0);
    sub_62FF70(v1, v8);
    if ( unk_193BF80 )
      v3 = *(_DWORD **)unk_193BF80;
    else
      v3 = 0;
    sub_938F40(*v3, v1);
    v4 = 0;
    if ( *v0 > 0 )
    {
      v5 = 0;
      do
      {
        sub_9397F0(v5 + v0[1], v7);
        ++v4;
        v5 += 272;
      }
      while ( v4 < *v0 );
      v1 = v7;
    }
    v8[0] = *(_DWORD *)std::_Get_future_error_what(12);
    sub_62FF70(v1, v8);
    FFX_FileIO_IopDevice_Close(v1);
    sprintf(Buffer_1, "chmod 666 %s", v12);
    v6 = sub_84EDE0((int)Buffer_1, v9);
    return nullsub_171("system %s ret:%d", Buffer_1, v6);
  }
}

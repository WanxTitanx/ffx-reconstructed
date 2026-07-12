// Function: sub_9391D0
// Address: 0x9391d0
int __cdecl sub_9391D0(int i_1, int a2, int a3)
{
  int v3; // esi
  char *v4; // ecx
  char *v5; // edx
  char v6; // al
  char *v7; // ecx
  char v8; // al
  int v9; // ebx
  int i; // esi
  char v11; // bl
  unsigned int v12; // ecx
  unsigned int v13; // eax
  int v14; // eax
  char *v15; // ecx
  _BYTE *v16; // edx
  char v17; // al
  char *v18; // ecx
  _BYTE *v19; // edx
  char v20; // al
  void *v21; // eax
  int v22; // eax
  int v24; // [esp+Ch] [ebp-534h]
  int v25; // [esp+10h] [ebp-530h]
  _BYTE v26[272]; // [esp+14h] [ebp-52Ch] BYREF
  _DWORD v27[4]; // [esp+124h] [ebp-41Ch] BYREF
  _BYTE v28[256]; // [esp+134h] [ebp-40Ch] BYREF
  char v29[256]; // [esp+234h] [ebp-30Ch] BYREF
  char Buffer_1[256]; // [esp+334h] [ebp-20Ch] BYREF
  char Buffer[5]; // [esp+434h] [ebp-10Ch] BYREF
  char v32[251]; // [esp+439h] [ebp-107h] BYREF
  _BYTE v33[8]; // [esp+534h] [ebp-Ch] BYREF

  v3 = unk_193C0F0;
  v4 = (char *)(unk_193C0F0 + 372);
  v5 = &v29[-unk_193C0F0 - 372];
  do
  {
    v6 = *v4;
    v4[(_DWORD)v5] = *v4;
    ++v4;
  }
  while ( v6 );
  v7 = (char *)(v3 + 636);
  do
  {
    v8 = *v7;
    v33[(_DWORD)v7 - 636 - v3] = *v7;
    ++v7;
  }
  while ( v8 );
  sub_937F70(a3);
  sprintf(Buffer, "host:%s/bin/map2d.bin", (const char *)(unk_193C0F0 + 372));
  v9 = sub_62FBE0(Buffer, 2);
  v24 = v9;
  memset(v27, 0, sizeof(v27));
  v27[0] = *(_DWORD *)std::_Get_future_error_what(0);
  sub_62FF70(v9, v27);
  sub_938F40(i_1, v9);
  for ( i = 0; i < i_1; ++i )
  {
    v25 = *(unsigned __int8 *)(i + a2) / 10 + 48;
    v11 = *(unsigned __int8 *)(i + a2) % 10 + 48;
    v12 = unk_193C0F0 + 372 + strlen((const char *)(unk_193C0F0 + 372)) + 1 - (unk_193C0F0 + 373);
    *(_BYTE *)(unk_193C0F0 + v12 + 370) = v25;
    *(_BYTE *)(unk_193C0F0 + v12 + 371) = v11;
    v13 = unk_193C0F0 + 636 + strlen((const char *)(unk_193C0F0 + 636)) + 1 - (unk_193C0F0 + 637);
    *(_BYTE *)(unk_193C0F0 + v13 + 634) = v25;
    *(_BYTE *)(unk_193C0F0 + v13 + 635) = v11;
    sub_9209E0(v26);
    sub_93AEC0((int)v26);
    v9 = v24;
    sub_9397F0((int)v26, v24);
    sub_920870(v26);
  }
  v27[0] = *(_DWORD *)std::_Get_future_error_what(12);
  sub_62FF70(v9, v27);
  FFX_FileIO_IopDevice_Close(v9);
  sprintf(Buffer_1, "chmod 666 %s", v32);
  v14 = sub_84EDE0((int)Buffer_1, v28);
  nullsub_171("system %s ret:%d", Buffer_1, v14);
  v15 = v29;
  v16 = (_BYTE *)(unk_193C0F0 + 372);
  do
  {
    v17 = *v15;
    *v16++ = *v15++;
  }
  while ( v17 );
  v18 = v33;
  v19 = (_BYTE *)(unk_193C0F0 + 636);
  do
  {
    v20 = *v18;
    *v19++ = *v18++;
  }
  while ( v20 );
  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 )
    v21 = *(void **)(*(_DWORD *)unk_193BF80 + 8);
  else
    v21 = 0;
  sub_9209E0(v21);
  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 )
    v22 = *(_DWORD *)(*(_DWORD *)unk_193BF80 + 8);
  else
    v22 = 0;
  return sub_93AEC0(v22);
}

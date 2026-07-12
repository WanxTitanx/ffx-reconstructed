// Function: sub_938350
// Address: 0x938350
int __cdecl sub_938350(int a1)
{
  int v1; // esi
  int i_3; // ecx
  int i_1; // eax
  _DWORD *v5; // ebx
  int v6; // esi
  size_t Size; // edi
  signed int v8; // eax
  int v9; // eax
  int i_2; // [esp+0h] [ebp-340h]
  int v11; // [esp+4h] [ebp-33Ch]
  int i; // [esp+8h] [ebp-338h]
  int v13; // [esp+Ch] [ebp-334h] BYREF
  int v14; // [esp+10h] [ebp-330h]
  int v15; // [esp+14h] [ebp-32Ch]
  int v16; // [esp+18h] [ebp-328h]
  _DWORD v17[4]; // [esp+1Ch] [ebp-324h] BYREF
  _BYTE v18[256]; // [esp+2Ch] [ebp-314h] BYREF
  char Buffer_1[256]; // [esp+12Ch] [ebp-214h] BYREF
  char Buffer[5]; // [esp+22Ch] [ebp-114h] BYREF
  char v21[251]; // [esp+231h] [ebp-10Fh] BYREF
  _BYTE v22[16]; // [esp+32Ch] [ebp-14h] BYREF

  if ( (sub_908F10() & 0x1000) != 0 )
    sprintf(Buffer, "host:/ffx/proj/map/f_particle/b%03d.fpd", a1);
  else
    sprintf(Buffer, "host:/ffx/proj/map/f_particle/m%03d.fpd", a1);
  v1 = sub_62FBE0(Buffer, 2);
  v11 = v1;
  if ( v1 == -1 )
  {
    nullsub_171("Error in %s, line %d: ", "..\\program\\src\\rcBg\\rcbgSave.c", 614);
    return nullsub_171("Save(FP) Failed.");
  }
  else
  {
    memset(v17, 0, sizeof(v17));
    v17[0] = *(_DWORD *)std::_Get_future_error_what(0);
    sub_62FF70(v1, v17);
    i_3 = sub_921C20(131078);
    i_1 = 0;
    i_2 = i_3;
    for ( i = 0; i_1 < i_2; i = i_1 )
    {
      v5 = (_DWORD *)sub_921BE0(131078, i_1);
      v6 = v5[36] * v5[37] + 80 + v5[20] * v5[21];
      Size = sub_92B2C0(v6);
      v13 = 0;
      v14 = 0;
      v15 = 0;
      v16 = 0;
      v13 = *(_DWORD *)std::_Get_future_error_what(10);
      v8 = Size + v6;
      v1 = v11;
      v14 = v8 / 16;
      sub_62FF70(v11, &v13);
      sub_9399F0(v5, v11);
      memset(v22, 0, Size);
      sub_62FF70(v11, v22);
      i_1 = i + 1;
    }
    v17[0] = *(_DWORD *)std::_Get_future_error_what(12);
    sub_62FF70(v1, v17);
    FFX_FileIO_IopDevice_Close(v1);
    sprintf(Buffer_1, "chmod 666 %s", v21);
    v9 = sub_84EDE0((int)Buffer_1, v18);
    return nullsub_171("system %s ret:%d", Buffer_1, v9);
  }
}

// Function: sub_A43740
// Address: 0xa43740
// Size: 0x476
// Prototype: int __cdecl(size_t Size)

void *__cdecl sub_A43740(int Size)
{
  int *CoreWorkPtr; // ebx
  void *Src_1; // eax
  char *v4; // edi
  size_t Sizea_1; // eax
  int v6; // esi
  signed int v7; // esi
  DWORD v8; // eax
  int v9; // ecx
  int v10; // esi
  size_t Size_1; // esi
  char *Src_2; // esi
  char *v13; // esi
  int v14; // eax
  int v15; // eax
  int v16; // [esp-8h] [ebp-20h]
  int v17; // [esp+8h] [ebp-10h]
  _BYTE v18[4]; // [esp+Ch] [ebp-Ch] BYREF
  void *Src; // [esp+10h] [ebp-8h]
  int v20; // [esp+14h] [ebp-4h] BYREF
  size_t Sizea; // [esp+20h] [ebp+8h]
  size_t Sizeb; // [esp+20h] [ebp+8h]

  v20 = 0;
  CoreWorkPtr = (int *)FFX_Btl_GetCoreWorkPtr();
  Src_1 = (void *)sub_76DD60();
  Src = Src_1;
  if ( !*((_BYTE *)&unk_1127CB1 + 56 * Size) || *((_BYTE *)&unk_1127CB2 + 56 * Size) )
    return Src_1;
  v4 = (char *)&unk_1127C80 + 56 * Size;
  *((_BYTE *)&unk_1127CB2 + 56 * Size) = 1;
  if ( v4[51] )
    return (void *)sub_76D640(Size);
  CoreWorkPtr[29] = Size;
  CoreWorkPtr[28] = 1;
  Sizea_1 = sub_76D710(*((_DWORD *)v4 + 10), *((_DWORD *)v4 + 2));
  Sizea = Sizea_1;
  if ( Sizea_1 )
  {
    sprintf(Buffer_5, "pfs0:/ex/%s", (const char *)(Sizea_1 + 36));
    v6 = sub_62FBE0(Buffer_5, 1);
    if ( !v6 )
      nullsub_34();
    sub_62FA50(v6, 1, &v20);
    while ( v20 )
    {
      sub_77A5D0(1);
      sub_62FA50(v6, 1, &v20);
    }
    sub_62FA90(v6, *(_DWORD *)(Sizea + 12), 0);
    sub_62FA50(v6, 1, &v20);
    while ( v20 )
    {
      sub_77A5D0(1);
      sub_62FA50(v6, 1, &v20);
    }
    nullsub_33(0);
    IopDevice_ReadFile(v6, *((LPVOID *)v4 + 1), *(_DWORD *)(Sizea + 16));
    sub_62FA50(v6, 1, &v20);
    while ( v20 )
    {
      sub_77A5D0(1);
      sub_62FA50(v6, 1, &v20);
    }
    FFX_FileIO_IopDevice_Close(v6);
LABEL_41:
    Src_1 = (void *)nullsub_33(0);
    goto LABEL_42;
  }
  if ( unk_133C8D3 )
  {
    v7 = *((_DWORD *)v4 + 11);
    if ( v4[52] )
    {
      v8 = *(_DWORD *)v4;
      Sizeb = *(_DWORD *)v4;
      if ( *(_DWORD *)v4 < (unsigned int)v7 )
      {
        v9 = v8 + 5;
        v10 = (int)(v8 + 5) / 2048;
        v17 = v10;
        if ( v10 && v9 > 0 )
        {
          sub_76D310(*((_DWORD *)v4 + 7), v9, *((_DWORD *)v4 + 1), v18, *((_DWORD *)v4 + 10));
          nullsub_33(0);
          Size_1 = v10 << 11;
          memcpy(*((void **)v4 + 1), (const void *)(*((_DWORD *)v4 + 1) + 5), Size_1);
          sub_76D310(v17 + *((_DWORD *)v4 + 7), 2048, Src, v18, *((_DWORD *)v4 + 10));
          nullsub_33(0);
          Src_1 = memcpy((void *)(Size_1 + *((_DWORD *)v4 + 1)), Src, Sizeb - Size_1);
        }
        else
        {
          Src_2 = (char *)Src;
          sub_76D310(*((_DWORD *)v4 + 7), 2048, Src, v18, *((_DWORD *)v4 + 10));
          nullsub_33(0);
          Src_1 = memcpy(*((void **)v4 + 1), Src_2 + 5, Sizeb);
        }
        goto LABEL_42;
      }
    }
    v16 = *((_DWORD *)v4 + 10);
    if ( v7 / 2048 )
    {
      sub_76D310(*((_DWORD *)v4 + 7), v7, *((_DWORD *)v4 + 1), v18, v16);
      if ( (v7 & 0x7FF) == 0 )
      {
        Src_1 = (void *)nullsub_33(0);
        goto LABEL_28;
      }
      sub_76D310(v7 / 2048 + *((_DWORD *)v4 + 7), 2048, Src, v18, *((_DWORD *)v4 + 10));
    }
    else
    {
      sub_76D310(*((_DWORD *)v4 + 7), 2048, Src, v18, v16);
    }
    nullsub_33(0);
    Src_1 = memcpy((void *)(v7 + *((_DWORD *)v4 + 1) - (v7 & 0x7FF)), Src, v7 & 0x7FF);
LABEL_28:
    if ( v4[52] )
    {
      if ( *(_BYTE *)(sub_88D550() + 16) )
      {
        while ( unk_1128AAD )
          sub_77A5D0(1);
        unk_1128AAD = 1;
        unk_2310C2C = v4;
        for ( Src_1 = (void *)sub_888790(); unk_1128AAD; Src_1 = (void *)sub_77A5D0(1) )
          ;
      }
      else
      {
        Src_1 = (void *)sub_76D550(v4);
      }
    }
    goto LABEL_42;
  }
  v13 = (char *)&unk_22FB6C0 + 128 * Size;
  if ( !*((_DWORD *)v4 + 7) )
  {
    v15 = sub_62FBE0(v13, 1);
    CoreWorkPtr[23] = v15;
    sub_A42F50(v15);
    nullsub_33(0);
    IopDevice_ReadFile(CoreWorkPtr[23], *((LPVOID *)v4 + 1), *(_DWORD *)v4);
    sub_62FA50(CoreWorkPtr[23], 1, &v20);
    while ( v20 )
    {
      sub_77A5D0(1);
      sub_62FA50(CoreWorkPtr[23], 1, &v20);
    }
    FFX_FileIO_IopDevice_Close(CoreWorkPtr[23]);
    goto LABEL_41;
  }
  v14 = sub_62FBE0(v13, 1);
  CoreWorkPtr[23] = v14;
  sub_A42F50(v14);
  sub_62FA90(CoreWorkPtr[23], *((_DWORD *)v4 + 7) << 11, 0);
  nullsub_33(0);
  IopDevice_ReadFile(CoreWorkPtr[23], *((LPVOID *)v4 + 1), *(_DWORD *)v4);
  FFX_FileIO_IopDevice_Close(CoreWorkPtr[23]);
  Src_1 = (void *)nullsub_33(0);
LABEL_42:
  if ( *((_DWORD *)v4 + 8) )
    Src_1 = (void *)sub_642B30(v4);
  else
    *(_WORD *)(v4 + 49) = 0;
  CoreWorkPtr[29] = -1;
  CoreWorkPtr[28] = 0;
  CoreWorkPtr[23] = -1;
  return Src_1;
}


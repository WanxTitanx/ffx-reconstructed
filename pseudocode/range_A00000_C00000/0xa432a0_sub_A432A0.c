// Function: sub_A432A0
// Address: 0xa432a0
// Size: 0x498
// Prototype: 

int sub_A432A0()
{
  int *CoreWorkPtr; // ebx
  int result; // eax
  char *v2; // edi
  _DWORD *v3; // esi
  int v4; // eax
  int v5; // edi
  signed int v6; // edi
  unsigned int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // eax
  int v11; // [esp-4h] [ebp-2Ch]
  unsigned int v12; // [esp+Ch] [ebp-1Ch]
  int v13; // [esp+10h] [ebp-18h]
  int v14; // [esp+10h] [ebp-18h]
  int v15; // [esp+14h] [ebp-14h]
  char v16[4]; // [esp+18h] [ebp-10h] BYREF
  void *Src; // [esp+1Ch] [ebp-Ch]
  char *v18; // [esp+20h] [ebp-8h]
  int v19; // [esp+24h] [ebp-4h] BYREF

  v19 = 0;
  CoreWorkPtr = (int *)FFX_Btl_GetCoreWorkPtr();
  Src = (void *)sub_76DD60();
  result = 0;
  v2 = (char *)&unk_22FB6C0;
  v15 = 0;
  v18 = (char *)&unk_22FB6C0;
  v3 = &unk_1127CA8;
  do
  {
    if ( *((_BYTE *)v3 + 9) && !*((_BYTE *)v3 + 10) )
    {
      *((_BYTE *)v3 + 10) = 1;
      if ( *((_BYTE *)v3 + 11) )
      {
        sub_76D640(result);
LABEL_20:
        result = v15;
        goto LABEL_21;
      }
      CoreWorkPtr[29] = result;
      CoreWorkPtr[28] = 1;
      v4 = sub_76D710(*v3, *(v3 - 8));
      v13 = v4;
      if ( v4 )
      {
        sprintf(Buffer_5, "pfs0:/ex/%s", (const char *)(v4 + 36));
        v5 = sub_62FBE0(Buffer_5, 1);
        if ( !v5 )
          nullsub_34();
        sub_62FA50(v5, 1, &v19);
        while ( v19 )
        {
          sub_77A5D0(1);
          sub_62FA50(v5, 1, &v19);
        }
        sub_62FA90(v5, *(_DWORD *)(v13 + 12), 0);
        sub_62FA50(v5, 1, &v19);
        while ( v19 )
        {
          sub_77A5D0(1);
          sub_62FA50(v5, 1, &v19);
        }
        nullsub_33(0);
        IopDevice_ReadFile(v5, (LPVOID)*(v3 - 9), *(_DWORD *)(v13 + 16));
        sub_62FA50(v5, 1, &v19);
        while ( v19 )
        {
          sub_77A5D0(1);
          sub_62FA50(v5, 1, &v19);
        }
        FFX_FileIO_IopDevice_Close(v5);
        nullsub_33(0);
        goto LABEL_16;
      }
      if ( !unk_133C8D3 )
      {
        if ( *(v3 - 3) )
        {
          v9 = sub_62FBE0(v2, 1);
          CoreWorkPtr[23] = v9;
          sub_A42F50(v9);
          sub_62FA90(CoreWorkPtr[23], *(v3 - 3) << 11, 0);
          nullsub_33(0);
          IopDevice_ReadFile(CoreWorkPtr[23], (LPVOID)*(v3 - 9), *(v3 - 10));
          FFX_FileIO_IopDevice_Close(CoreWorkPtr[23]);
          nullsub_33(0);
        }
        else
        {
          v10 = sub_62FBE0(v2, 1);
          CoreWorkPtr[23] = v10;
          sub_A42F50(v10);
          nullsub_33(0);
          IopDevice_ReadFile(CoreWorkPtr[23], (LPVOID)*(v3 - 9), *(v3 - 10));
          sub_62FA50(CoreWorkPtr[23], 1, &v19);
          while ( v19 )
          {
            sub_77A5D0(1);
            sub_62FA50(CoreWorkPtr[23], 1, &v19);
          }
          FFX_FileIO_IopDevice_Close(CoreWorkPtr[23]);
          nullsub_33(0);
        }
        goto LABEL_17;
      }
      v6 = v3[1];
      if ( *((_BYTE *)v3 + 12) )
      {
        v7 = *(v3 - 10);
        if ( v7 < v6 )
        {
          v8 = v7 + 5;
          v12 = v7 + 5;
          v14 = (int)(v7 + 5) / 2048;
          if ( v14 && v8 > 0 )
          {
            sub_76D310(*(v3 - 3), v8, *(v3 - 9), v16, *v3);
            nullsub_33(0);
            memcpy((void *)*(v3 - 9), (const void *)(*(v3 - 9) + 5), v14 << 11);
            sub_76D310(v14 + *(v3 - 3), 2048, Src, v16, *v3);
            nullsub_33(0);
            memcpy((void *)((v14 << 11) + *(v3 - 9)), Src, v12 - (v14 << 11) - 5);
          }
          else
          {
            sub_76D310(*(v3 - 3), 2048, Src, v16, *v3);
            nullsub_33(0);
            memcpy((void *)*(v3 - 9), (char *)Src + 5, v8 - 5);
          }
LABEL_16:
          v2 = v18;
LABEL_17:
          if ( *(v3 - 2) )
            sub_76E750(v3 - 10);
          CoreWorkPtr[29] = -1;
          CoreWorkPtr[28] = 0;
          CoreWorkPtr[23] = -1;
          *(_WORD *)((char *)v3 + 9) = 0;
          goto LABEL_20;
        }
      }
      v11 = *v3;
      if ( v6 / 2048 )
      {
        sub_76D310(*(v3 - 3), v6, *(v3 - 9), v16, v11);
        if ( (v6 & 0x7FF) == 0 )
        {
          nullsub_33(0);
          goto LABEL_36;
        }
        sub_76D310(v6 / 2048 + *(v3 - 3), 2048, Src, v16, *v3);
      }
      else
      {
        sub_76D310(*(v3 - 3), 2048, Src, v16, v11);
      }
      nullsub_33(0);
      memcpy((void *)(v6 + *(v3 - 9) - (v6 & 0x7FF)), Src, v6 & 0x7FF);
LABEL_36:
      if ( *((_BYTE *)v3 + 12) )
      {
        if ( *(_BYTE *)(sub_88D550() + 16) )
        {
          while ( unk_1128AAD )
            sub_77A5D0(1);
          unk_1128AAD = 1;
          unk_2310C2C = v3 - 10;
          sub_888790();
          while ( unk_1128AAD )
            sub_77A5D0(1);
        }
        else
        {
          sub_76D550(v3 - 10);
        }
      }
      goto LABEL_16;
    }
LABEL_21:
    ++result;
    v3 += 14;
    v2 += 128;
    v15 = result;
    v18 = v2;
  }
  while ( (int)v3 < (int)&dword_1128AA8 );
  return result;
}


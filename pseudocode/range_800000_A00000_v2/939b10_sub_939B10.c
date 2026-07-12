// Function: sub_939B10
// Address: 0x939b10
int sub_939B10()
{
  int *v0; // esi
  void (*__imp_sprintf)(char *const, const char *const, ...); // ebx
  int v2; // edi
  _DWORD *v4; // eax
  float *v5; // esi
  unsigned __int8 *v6; // esi
  int i; // ebx
  int v8; // eax
  int *v9; // [esp+2Ch] [ebp-214h]
  int v10; // [esp+30h] [ebp-210h]
  _DWORD *v11; // [esp+34h] [ebp-20Ch]
  float *v12; // [esp+38h] [ebp-208h]
  char Buffer[5]; // [esp+3Ch] [ebp-204h] BYREF
  char v14[251]; // [esp+41h] [ebp-1FFh] BYREF
  char Buffer_1[256]; // [esp+13Ch] [ebp-104h] BYREF

  if ( unk_193BF80 && *(_DWORD *)unk_193BF80 )
    v0 = *(int **)(*(_DWORD *)unk_193BF80 + 8);
  else
    v0 = 0;
  __imp_sprintf = (void (*)(char *const, const char *const, ...))sprintf;
  v9 = v0;
  sprintf(Buffer, "host:%s/txt/%s.2d", (const char *)(unk_193C0F0 + 372), (const char *)(unk_193C0F0 + 636));
  v2 = sub_62FBE0(Buffer, 2);
  if ( v2 == -1 )
  {
    nullsub_171("Error in %s, line %d: ", "..\\program\\src\\rcBg\\rcbgSaveText.c", 52);
    return nullsub_171("Save(Text) Failed.");
  }
  else
  {
    sprintf(Buffer_1, "BG {\n");
    strlen(Buffer_1);
    sub_62FF70(v2, Buffer_1);
    sprintf(Buffer_1, "\tOffX %d\n", v0[23]);
    strlen(Buffer_1);
    sub_62FF70(v2, Buffer_1);
    sprintf(Buffer_1, "\tOffY %d\n", v0[24]);
    strlen(Buffer_1);
    sub_62FF70(v2, Buffer_1);
    sprintf(Buffer_1, "\tAdjY %d\n", v0[25]);
    strlen(Buffer_1);
    sub_62FF70(v2, Buffer_1);
    sprintf(Buffer_1, "}\n\n");
    strlen(Buffer_1);
    sub_62FF70(v2, Buffer_1);
    v4 = (_DWORD *)v0[2];
    v11 = v4;
    v10 = 0;
    if ( v0[1] > 0 )
    {
      v5 = (float *)(v4 + 38);
      v12 = (float *)(v4 + 38);
      do
      {
        __imp_sprintf(Buffer_1, "Layer {\n");
        strlen(Buffer_1);
        sub_62FF70(v2, Buffer_1);
        *v11 &= ~2u;
        __imp_sprintf(Buffer_1, "\tFlag %d\n", *v11);
        strlen(Buffer_1);
        sub_62FF70(v2, Buffer_1);
        __imp_sprintf(Buffer_1, "\tX %d\n", *((_DWORD *)v5 - 35));
        strlen(Buffer_1);
        sub_62FF70(v2, Buffer_1);
        __imp_sprintf(Buffer_1, "\tY %d\n", *((_DWORD *)v5 - 34));
        strlen(Buffer_1);
        sub_62FF70(v2, Buffer_1);
        __imp_sprintf(Buffer_1, "\tZ %f %f %f %f\n", *(v5 - 33), *(v5 - 32), *(v5 - 31), *(v5 - 30));
        strlen(Buffer_1);
        sub_62FF70(v2, Buffer_1);
        __imp_sprintf(Buffer_1, "\tSpeedX %d\n", *((_DWORD *)v5 - 27));
        strlen(Buffer_1);
        sub_62FF70(v2, Buffer_1);
        __imp_sprintf(Buffer_1, "\tSpeedY %d\n", *((_DWORD *)v5 - 26));
        strlen(Buffer_1);
        sub_62FF70(v2, Buffer_1);
        __imp_sprintf(Buffer_1, "\tAlpha %d\n", *((_DWORD *)v5 - 24));
        strlen(Buffer_1);
        sub_62FF70(v2, Buffer_1);
        if ( *(int *)v5 > 0 )
        {
          __imp_sprintf(Buffer_1, "\t\n\tAnime {\n");
          strlen(Buffer_1);
          sub_62FF70(v2, Buffer_1);
          __imp_sprintf(Buffer_1, "\t\tDataCnt %d\n", *(_DWORD *)v5);
          strlen(Buffer_1);
          sub_62FF70(v2, Buffer_1);
          if ( *(int *)v5 > 0 )
          {
            __imp_sprintf(Buffer_1, "\t\tData {\n");
            strlen(Buffer_1);
            sub_62FF70(v2, Buffer_1);
            v6 = (unsigned __int8 *)*((_DWORD *)v5 + 1);
            for ( i = 0; i < *(_DWORD *)v12; v6 += 4 )
            {
              sprintf(Buffer_1, "\t\t\t%d %d %d %d\n", *v6, v6[1], (char)v6[2], (char)v6[3]);
              strlen(Buffer_1);
              sub_62FF70(v2, Buffer_1);
              ++i;
            }
            __imp_sprintf = (void (*)(char *const, const char *const, ...))sprintf;
            sprintf(Buffer_1, "\t\t}\n");
            strlen(Buffer_1);
            sub_62FF70(v2, Buffer_1);
            v5 = v12;
          }
          __imp_sprintf(Buffer_1, "\t}\n");
          strlen(Buffer_1);
          sub_62FF70(v2, Buffer_1);
        }
        if ( *((_BYTE *)v5 + 34) )
        {
          __imp_sprintf(Buffer_1, "\t\n\tPal {\n");
          strlen(Buffer_1);
          sub_62FF70(v2, Buffer_1);
          __imp_sprintf(Buffer_1, "\t\tType %d\n", *((unsigned __int8 *)v5 + 34));
          strlen(Buffer_1);
          sub_62FF70(v2, Buffer_1);
          __imp_sprintf(Buffer_1, "\t\tTime %d\n", *((unsigned __int8 *)v5 + 35));
          strlen(Buffer_1);
          sub_62FF70(v2, Buffer_1);
          __imp_sprintf(Buffer_1, "\t}\n");
          strlen(Buffer_1);
          sub_62FF70(v2, Buffer_1);
        }
        __imp_sprintf(Buffer_1, "}\n\n");
        strlen(Buffer_1);
        sub_62FF70(v2, Buffer_1);
        v11 += 48;
        v5 += 48;
        v12 = v5;
        ++v10;
      }
      while ( v10 < v9[1] );
    }
    FFX_FileIO_IopDevice_Close(v2);
    __imp_sprintf(Buffer_1, "chmod 666 %s", v14);
    v8 = sub_84EDE0((int)Buffer_1, off_C498DC);
    return nullsub_171("system %s ret:%d", Buffer_1, v8);
  }
}

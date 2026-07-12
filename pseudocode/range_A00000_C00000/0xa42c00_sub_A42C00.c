// Function: sub_A42C00
// Address: 0xa42c00
// Size: 0x321
// Prototype: 

char *__cdecl sub_A42C00(int a1)
{
  _DWORD *v1; // ecx
  int v2; // edx
  char *v3; // esi
  int v4; // eax
  int v5; // ecx
  char *v6; // edi
  int v7; // ebx
  int v8; // ecx
  char *v9; // edx
  char v10; // al
  int n64; // eax
  int v12; // edi
  char *v13; // esi
  int v14; // edx
  char v15; // al
  _BYTE *v16; // esi
  int v17; // ecx
  char v18; // al
  char v19; // al
  char *v20; // esi
  char *v21; // esi
  char *v22; // esi
  char *v24; // [esp+4h] [ebp-110h]
  char *v25; // [esp+8h] [ebp-10Ch]
  int n64_1; // [esp+Ch] [ebp-108h]
  char Destination; // [esp+10h] [ebp-104h] BYREF
  _BYTE v28[255]; // [esp+11h] [ebp-103h] BYREF

  v1 = (_DWORD *)*((_DWORD *)FFX_Btl_GetCoreWorkPtr() + 12);
  if ( !v1 )
    goto LABEL_43;
  if ( a1 >= *v1 )
  {
    nullsub_34();
    goto LABEL_43;
  }
  v2 = v1[a1 + 1];
  if ( v1[a1 + 2] - v2 <= 0 )
  {
LABEL_43:
    v3 = 0;
    goto LABEL_44;
  }
  v3 = (char *)v1 + v2;
  v25 = (char *)v1 + v2;
  if ( !(_DWORD *)((char *)v1 + v2) )
  {
LABEL_44:
    nullsub_34();
    return v3;
  }
  v4 = sub_820730();
  v5 = 0;
  v6 = (char *)v4;
  v7 = 0;
  Source_0[0] = *v3;
  v24 = (char *)v4;
  if ( *v3 )
  {
    do
    {
      if ( v3[v7] == 36
        && v3[v7 + 1] == 85
        && v3[v7 + 2] == 83
        && v3[v7 + 3] == 69
        && v3[v7 + 4] == 82
        && v3[v7 + 5] == 36 )
      {
        if ( v6 )
        {
          Source_0[v5] = *v6;
          v8 = v5 + 1;
          if ( *v6 )
          {
            v9 = v6;
            do
            {
              v10 = *++v9;
              Source_0[v8++] = v10;
            }
            while ( *v9 );
          }
          v5 = v8 - 2;
          v7 += 5;
        }
      }
      else
      {
        n64 = 0;
        n64_1 = 0;
        do
        {
          v12 = *(_DWORD *)((char *)&unk_1A85BB0 + n64);
          if ( v12 )
          {
            v13 = &v3[v7];
            v14 = 0;
            if ( *v13 )
            {
              do
              {
                v15 = *(_BYTE *)(v12 + v14);
                if ( !v15 )
                  break;
                if ( v13[v14] != v15 )
                  break;
                ++v14;
              }
              while ( v13[v14] );
              n64 = n64_1;
            }
            if ( !*(_BYTE *)(v12 + v14) )
            {
              v16 = *(_BYTE **)((char *)&unk_1A85BF0 + n64);
              v17 = v5 + 1;
              for ( *((_BYTE *)&unk_1A85C2F + v17) = *v16; *v16; ++v17 )
              {
                v18 = *++v16;
                Source_0[v17] = v18;
              }
              n64 = n64_1;
              v5 = v17 - 2;
              v7 = v14 + v7 - 1;
            }
            v3 = v25;
          }
          n64 += 4;
          n64_1 = n64;
        }
        while ( n64 < 64 );
        v6 = v24;
      }
      v19 = v3[++v7];
      Source_0[++v5] = v19;
    }
    while ( v3[v7] );
  }
  if ( sub_6BCAA0() )
  {
    v20 = strstr(Source_0, "nagi0000.ebp");
    Destination = 0;
    memset(v28, 0, sizeof(v28));
    if ( v20 )
    {
      strncpy(&Destination, Source_0, v20 - Source_0);
      sprintf(Source_0, "%s%s%s", &Destination, "dbg_", "nagi0000.ebp");
    }
  }
  if ( unk_1A85BA4 )
  {
    v21 = strstr(Source_0, "kami0400.ebp");
    Destination = 0;
    memset(v28, 0, sizeof(v28));
    if ( v21 )
    {
      strncpy(&Destination, Source_0, v21 - Source_0);
      sprintf(Source_0, "%s%s%s", &Destination, "200thunder_", "kami0400.ebp");
    }
  }
  if ( unk_1A85BA8 )
  {
    v22 = strstr(Source_0, "nagi0700.ebp");
    Destination = 0;
    memset(v28, 0, sizeof(v28));
    if ( v22 )
    {
      strncpy(&Destination, Source_0, v22 - Source_0);
      sprintf(Source_0, "%s%s%s", &Destination, "full_", "nagi0700.ebp");
    }
  }
  return Source_0;
}


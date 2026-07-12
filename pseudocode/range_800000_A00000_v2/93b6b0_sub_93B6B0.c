// Function: sub_93B6B0
// Address: 0x93b6b0
int __cdecl sub_93B6B0(int a1)
{
  int v1; // esi
  int i; // edi
  int Str1; // ebx
  char n95; // cl
  char v5; // dl
  int v6; // eax
  int result; // eax
  int v8; // ecx
  float v9; // edi
  int v10; // ebx
  double v11; // st7
  int n26; // edi
  int v13; // ebx
  int v14; // esi
  float v15; // esi
  _DWORD v16[2]; // [esp+Ch] [ebp-118h] BYREF
  int v17; // [esp+14h] [ebp-110h]
  int v18; // [esp+18h] [ebp-10Ch]
  float v19; // [esp+1Ch] [ebp-108h]
  char Buffer[256]; // [esp+20h] [ebp-104h] BYREF

  v18 = a1;
  v16[0] = 0;
  v16[1] = 0;
  v17 = 0;
  sprintf(Buffer, "%s/2d/tex", (const char *)(unk_193C0F0 + 372));
  sub_8498E0(v16, Buffer);
  v1 = 0;
  for ( i = 0; i < v16[0]; ++i )
  {
    Str1 = *(_DWORD *)(v17 + 4 * i);
    LODWORD(v19) = unk_193C0F0 + 637;
    if ( !strncmp(
            (const char *)Str1,
            (const char *)(unk_193C0F0 + 636),
            unk_193C0F0 + 636 + strlen((const char *)(unk_193C0F0 + 636)) + 1 - (unk_193C0F0 + 637)) )
    {
      n95 = *(_BYTE *)(Str1 + 6);
      v5 = *(_BYTE *)(Str1 + 7);
      if ( (unsigned __int8)(n95 - 97) <= 0x19u )
      {
        v6 = n95 - 96;
        goto LABEL_8;
      }
      if ( n95 == 95 && (unsigned __int8)(v5 - 97) <= 0x19u )
      {
        v6 = v5 - 70;
LABEL_8:
        if ( v1 < v6 )
          v1 = v6;
      }
    }
  }
  *(_DWORD *)(v18 + 4) = v1;
  result = sub_9258A0(192 * v1);
  v8 = v18;
  v9 = 0.0;
  *(_DWORD *)(v18 + 8) = result;
  v19 = 0.0;
  if ( v1 > 0 )
  {
    v10 = 0;
    do
    {
      sub_92AD20((void *)(v10 + *(_DWORD *)(v8 + 8)));
      v8 = v18;
      ++LODWORD(v9);
      v19 = (float)SLODWORD(v19);
      result = *(_DWORD *)(v18 + 8);
      v10 += 192;
      v19 = 100.0 - v19;
      v11 = v19;
      v19 = v9;
      *(float *)(v10 + result - 172) = v11;
    }
    while ( SLODWORD(v9) < v1 );
  }
  n26 = 0;
  if ( *(int *)(v8 + 4) > 0 )
  {
    v13 = v18;
    v19 = 0.0;
    do
    {
      if ( n26 >= 26 )
        sprintf(Buffer, "%s_%c.tm2", unk_193C0F0 + 636, n26 + 71);
      else
        sprintf(Buffer, "%s%c.tm2", unk_193C0F0 + 636, n26 + 97);
      v14 = 0;
      if ( v16[0] <= 0 )
      {
LABEL_23:
        sub_93B930(v13, n26);
      }
      else
      {
        while ( strncmp(*(const char **)(v17 + 4 * v14), Buffer, strlen(Buffer)) )
        {
          if ( ++v14 >= v16[0] )
            goto LABEL_22;
        }
        if ( v14 >= v16[0] )
        {
LABEL_22:
          v13 = v18;
          goto LABEL_23;
        }
        v13 = v18;
        sub_93BD10(v18, n26);
      }
      v15 = v19;
      result = sub_92B270(LODWORD(v19) + *(_DWORD *)(v13 + 8));
      ++n26;
      LODWORD(v19) = LODWORD(v15) + 192;
    }
    while ( n26 < *(_DWORD *)(v13 + 4) );
  }
  return result;
}

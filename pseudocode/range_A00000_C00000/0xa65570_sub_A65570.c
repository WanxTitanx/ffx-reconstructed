// Function: sub_A65570
// Address: 0xa65570
// Size: 0x1e0
// Prototype: int __cdecl(char *Buffer, int)

int __cdecl sub_A65570(char *Buffer, _WORD *a2)
{
  __int16 v2; // bx
  int v3; // eax
  char *Buffer_1; // esi
  int v5; // eax
  char *Buffer_2; // esi
  int v7; // eax
  char *Buffer_3; // esi
  int v9; // ebx
  int v10; // eax
  int v11; // eax
  char *Buffer_4; // esi
  int v13; // eax
  char *Buffer_5; // esi
  int v15; // eax
  char *Buffer_6; // esi
  char *Buffer_7; // esi
  unsigned __int16 *v18; // eax
  char *Buffer_8; // esi
  unsigned __int16 *v20; // eax
  char *Buffer_9; // esi
  unsigned __int16 *v22; // eax
  __int16 v24; // [esp+Ch] [ebp-Ch]
  __int16 v25; // [esp+10h] [ebp-8h]
  __int16 v26; // [esp+14h] [ebp-4h]
  unsigned __int16 *v27; // [esp+24h] [ebp+Ch]

  v2 = *a2;
  v27 = a2 + 1;
  if ( (v2 & 1) != 0 )
  {
    v26 = v2 & 0x1000;
    if ( (v2 & 0x1000) != 0 )
      v3 = sprintf(Buffer, "x");
    else
      v3 = sprintf(Buffer, ".");
    Buffer_1 = &Buffer[v3];
    v25 = v2 & 0x2000;
    if ( (v2 & 0x2000) != 0 )
      v5 = sprintf(Buffer_1, "y");
    else
      v5 = sprintf(Buffer_1, ".");
    Buffer_2 = &Buffer_1[v5];
    v24 = v2 & 0x4000;
    if ( (v2 & 0x4000) != 0 )
      v7 = sprintf(Buffer_2, "z");
    else
      v7 = sprintf(Buffer_2, ".");
    Buffer_3 = &Buffer_2[v7];
    v9 = v2 & 0x8000;
    if ( v9 )
    {
      v10 = sprintf(Buffer_3, "t");
      goto LABEL_25;
    }
  }
  else
  {
    v26 = v2 & 0x1000;
    if ( (v2 & 0x1000) != 0 )
      v11 = sprintf(Buffer, "u");
    else
      v11 = sprintf(Buffer, ".");
    Buffer_4 = &Buffer[v11];
    v25 = v2 & 0x2000;
    if ( (v2 & 0x2000) != 0 )
      v13 = sprintf(Buffer_4, "v");
    else
      v13 = sprintf(Buffer_4, ".");
    Buffer_5 = &Buffer_4[v13];
    v24 = v2 & 0x4000;
    if ( (v2 & 0x4000) != 0 )
      v15 = sprintf(Buffer_5, "w");
    else
      v15 = sprintf(Buffer_5, ".");
    Buffer_3 = &Buffer_5[v15];
    v9 = v2 & 0x8000;
    if ( v9 )
    {
      v10 = sprintf(Buffer_3, "s");
      goto LABEL_25;
    }
  }
  v10 = sprintf(Buffer_3, ".");
LABEL_25:
  Buffer_6 = &Buffer_3[v10 + sprintf(&Buffer_3[v10], ")")];
  if ( v26 )
  {
    Buffer_7 = &Buffer_6[sprintf(Buffer_6, ".%04x", *v27)];
    v18 = ++v27;
  }
  else
  {
    Buffer_7 = &Buffer_6[sprintf(Buffer_6, ".    ")];
    v18 = v27;
  }
  if ( v25 )
  {
    Buffer_8 = &Buffer_7[sprintf(Buffer_7, ".%04x", *v18)];
    v20 = ++v27;
  }
  else
  {
    Buffer_8 = &Buffer_7[sprintf(Buffer_7, ".    ")];
    v20 = v27;
  }
  if ( v24 )
  {
    Buffer_9 = &Buffer_8[sprintf(Buffer_8, ".%04x", *v20)];
    v22 = v27 + 1;
  }
  else
  {
    Buffer_9 = &Buffer_8[sprintf(Buffer_8, ".    ")];
    v22 = v27;
  }
  if ( (_WORD)v9 )
    return sprintf(Buffer_9, ".%04x", *v22);
  else
    return sprintf(Buffer_9, ".    ");
}


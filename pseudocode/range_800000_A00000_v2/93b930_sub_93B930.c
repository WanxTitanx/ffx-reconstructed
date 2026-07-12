// Function: sub_93B930
// Address: 0x93b930
int __cdecl sub_93B930(int a1, int n26)
{
  int v2; // ecx
  int *v3; // ebx
  int *v4; // edi
  int v5; // eax
  int v6; // esi
  int v7; // edi
  unsigned int v8; // esi
  unsigned int v9; // edi
  int v10; // ebx
  int v11; // eax
  int v12; // ebx
  int v13; // edi
  int i_1; // eax
  int v15; // ebx
  int *i_2; // esi
  int v17; // eax
  const void *src; // esi
  int v19; // ecx
  int v20; // edx
  void *v21; // eax
  int v22; // [esp-10h] [ebp-154h]
  const char *%s_%c; // [esp-Ch] [ebp-150h]
  int v24; // [esp-Ch] [ebp-150h]
  int v25; // [esp-8h] [ebp-14Ch]
  size_t Size; // [esp-8h] [ebp-14Ch]
  int v27; // [esp-4h] [ebp-148h]
  int v28; // [esp-4h] [ebp-148h]
  int *v29; // [esp+Ch] [ebp-138h]
  int i; // [esp+10h] [ebp-134h]
  int *v31; // [esp+14h] [ebp-130h]
  int v32; // [esp+18h] [ebp-12Ch] BYREF
  int v33; // [esp+1Ch] [ebp-128h]
  int *v34; // [esp+20h] [ebp-124h]
  size_t *v35; // [esp+24h] [ebp-120h]
  int v36; // [esp+28h] [ebp-11Ch]
  int v37; // [esp+2Ch] [ebp-118h]
  char Buffer_1[256]; // [esp+30h] [ebp-114h] BYREF
  char Buffer[16]; // [esp+130h] [ebp-14h] BYREF

  v2 = *(_DWORD *)(a1 + 8) + 192 * n26;
  v3 = (int *)(v2 + 8);
  v36 = v2 + 144;
  v4 = (int *)(v2 + 4);
  v33 = v2 + 176;
  v34 = (int *)(v2 + 8);
  v35 = (size_t *)(v2 + 4);
  v29 = (int *)(v2 + 16);
  v31 = (int *)(v2 + 12);
  sub_93BBC0(n26, v2 + 12, v2 + 16, v2 + 4, v2 + 8);
  if ( n26 >= 26 )
  {
    v27 = n26 + 71;
    v25 = unk_193C0F0 + 636;
    %s_%c = "%s_%c";
  }
  else
  {
    v27 = n26 + 97;
    v25 = unk_193C0F0 + 636;
    %s_%c = "%s%c";
  }
  sprintf(Buffer, %s_%c, v25, v27);
  sprintf(Buffer_1, "%s/2d/tex/%s", (const char *)(unk_193C0F0 + 372), Buffer);
  v5 = sub_93ACB0((int)Buffer_1, Buffer, 3);
  v6 = *v3;
  v7 = *v4;
  v37 = v5;
  v8 = (v6 + 1) & 0xFFFFFFFE;
  v9 = (v7 + 7) & 0xFFFFFFF8;
  sub_920050(v9, v8, 0, 0, &v32);
  v10 = v36;
  sub_9308D0(v36, v37);
  v11 = sub_92D580();
  *(_DWORD *)(v10 + 16) = v11;
  v12 = v37;
  sub_92D320(v11, 15360, v32, 19, 0, 0, v9, v8, v37);
  v13 = v33;
  sub_929950(v33, v12);
  i_1 = sub_923B40();
  v15 = 0;
  i_2 = (int *)i_1;
  for ( i = i_1; v15 < v37; ++v15 )
  {
    sprintf(Buffer_1, "host:%s/2d/tex/%s/%s%03d.tm2", (const char *)(unk_193C0F0 + 372), Buffer, Buffer, v15);
    if ( sub_923800(i_2, (int)Buffer_1) )
    {
      v17 = *(_DWORD *)(v36 + 12);
      *(_BYTE *)(v17 + 4 * v15) = v15;
      *(_BYTE *)(v17 + 4 * v15 + 1) = 1;
      src = (const void *)unknown_libname_741(i_2[17]);
      qmemcpy((void *)sub_929990(v13, v15), src, 0x400u);
      v19 = *v31;
      i_2 = (int *)i;
      v20 = *v29;
      if ( *v35 == *(unsigned __int16 *)(i + 36) && *v34 == *(unsigned __int16 *)(i + 38) )
      {
        v20 = 0;
        v19 = 0;
      }
      v28 = *v34;
      Size = *v35;
      v24 = v20;
      v22 = v19;
      v21 = (void *)sub_92D4F0(*(_DWORD *)(v36 + 16), v15);
      i_1 = sub_923AE0(i, v21, v22, v24, Size, v28);
      v13 = v33;
    }
    else
    {
      nullsub_171("Error in %s, line %d: ", "..\\program\\src\\rcBg\\rcbgLoadText.c", 331);
      i_1 = nullsub_171("File not found.");
    }
  }
  if ( i_2 )
    return sub_923450(i_2);
  return i_1;
}

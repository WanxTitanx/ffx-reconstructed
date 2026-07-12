// Function: sub_934BC0
// Address: 0x934bc0
int __usercall sub_934BC0@<eax>(int a1@<edi>, int a2, int a3)
{
  int result; // eax
  int v4; // eax
  signed int v5; // edi
  int v6; // ebx
  int v7; // eax
  signed int v8; // eax
  int *v9; // ecx
  int v10; // ebx
  char *v11; // ecx
  _BYTE *v12; // edx
  char v13; // al
  _BYTE *v14; // edx
  char v15; // al
  int v16; // ecx
  int v17; // eax
  int v18; // eax
  int v19; // edx
  int v20; // esi
  signed int v21; // ebx
  int v22; // edi
  int v24; // [esp+0h] [ebp-11Ch]
  int v25; // [esp+4h] [ebp-118h]
  signed int v26; // [esp+8h] [ebp-114h]
  int v27; // [esp+Ch] [ebp-110h]
  int v28; // [esp+10h] [ebp-10Ch]
  int *v29; // [esp+14h] [ebp-108h]
  char Buffer[256]; // [esp+18h] [ebp-104h] BYREF

  result = unk_193C0F0;
  if ( !unk_193C0F0 || !unk_193BF80 )
    return result;
  v29 = (int *)(unk_193C0F0 + 104);
  v27 = sub_84AFA0(a2) / 80;
  v4 = sub_84AF30(a2);
  v5 = ((int)((unsigned __int64)(1717986919LL * v4) >> 32) >> 2)
     - 1
     + ((unsigned int)((unsigned __int64)(1717986919LL * v4) >> 32) >> 31);
  v26 = v5;
  v6 = sub_849AA0(a2) / 80;
  v7 = sub_849AC0(a2);
  v8 = ((int)((unsigned __int64)(1717986919LL * v7) >> 32) >> 2)
     + ((unsigned int)((unsigned __int64)(1717986919LL * v7) >> 32) >> 31)
     - 1;
  if ( v6 < 0 || v6 >= v27 || v8 < 0 || v8 >= v5 )
  {
    v9 = v29;
LABEL_10:
    v10 = -1;
    v28 = -1;
    goto LABEL_11;
  }
  v9 = v29;
  v10 = v8 + v5 * v6;
  v28 = v10;
  if ( v10 >= *v29 )
    goto LABEL_10;
LABEL_11:
  result = a3 - 32769;
  switch ( a3 )
  {
    case 32769:
    case 32778:
      goto LABEL_13;
    case 32771:
      result = unk_193C0F0;
      *(_DWORD *)(unk_193C0F0 + 4) = 0;
      return result;
    case 32774:
      if ( v10 >= 0 )
      {
        v11 = *(char **)(v9[2] + 4 * v10);
        v12 = (_BYTE *)(unk_193C0F0 + 628);
        if ( *(_BYTE *)(unk_193C0F0 + 628) )
        {
          v14 = (_BYTE *)(unk_193C0F0 + 636);
          do
          {
            v15 = *v11;
            *v14++ = *v11++;
          }
          while ( v15 );
          sub_937B20(v11, v14);
          sub_936570();
          v16 = unk_193C0F0;
          if ( *(_DWORD *)(unk_193C0F0 + 96) )
          {
            if ( !*(_DWORD *)(unk_193BF80 + 24) )
            {
              *(_DWORD *)(unk_193BF80 + 24) = sub_92B900();
              v16 = unk_193C0F0;
            }
            sprintf(Buffer, "host:%s/bin/map2d.bin", (const char *)(v16 + 372));
            if ( sub_92B880(*(_DWORD *)(unk_193BF80 + 24), Buffer) )
              sub_91AA60(**(char ***)(unk_193BF80 + 24));
          }
          else
          {
            sub_93AE60();
          }
          v17 = unknown_libname_741(*(_DWORD *)(unk_193C0F0 + 3072));
          if ( v17 )
            j_FFX_Memory_Delete_2(v17, a1);
          *(_DWORD *)(unk_193C0F0 + 3072) = unknown_libname_742(0);
          v18 = sub_925730();
          *(_DWORD *)(unk_193C0F0 + 3072) = unknown_libname_742(v18);
          sub_937B70();
          *(_DWORD *)(unk_193C0F0 + 92) = 1;
          return sub_937F50(unk_193C0F0 + 4);
        }
        else
        {
          do
          {
            v13 = *v11;
            *v12++ = *v11++;
          }
          while ( v13 );
          sprintf(Buffer, "%s%s", (const char *)(unk_193C0F0 + 116), (const char *)(unk_193C0F0 + 628));
          return sub_8498E0(v29, Buffer);
        }
      }
      return result;
    case 32782:
      *(_DWORD *)(unk_193C0F0 + 100) ^= 1u;
      sub_937AF0();
      sub_934FB0();
LABEL_13:
      sub_8498E0(v29, unk_193C0F0 + 116);
      *(_BYTE *)(unk_193C0F0 + 628) = 0;
      result = unk_193C0F0;
      *(_BYTE *)(unk_193C0F0 + 636) = 0;
      return result;
    case 32785:
      v19 = 0;
      v20 = 0;
      v24 = 0;
      if ( v27 <= 0 )
        return result;
      result = 0;
      v25 = 0;
      break;
    default:
      return result;
  }
  while ( 1 )
  {
    v21 = 0;
    if ( v5 > 0 )
      break;
LABEL_37:
    v9 = v29;
    ++v19;
    result += 80;
    v24 = v19;
    v25 = result;
    if ( v19 >= v27 )
      return result;
  }
  v22 = 0;
  while ( v20 < *v9 )
  {
    sub_848820(result);
    sub_848860(v22);
    sub_848720(v20 == v28);
    sub_848880(*(const char **)(v29[2] + 4 * v20));
    v9 = v29;
    result = v25;
    ++v21;
    ++v20;
    v22 += 10;
    if ( v21 >= v26 )
    {
      v5 = v26;
      v19 = v24;
      goto LABEL_37;
    }
  }
  return result;
}

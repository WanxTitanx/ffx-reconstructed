// Function: sub_A5C130
// Address: 0xa5c130
// Size: 0x234
// Prototype: 

int __cdecl sub_A5C130(__int64 a1, int a2, int a3, unsigned __int64 a4, unsigned __int64 a5, int n2_1)
{
  int v6; // ebx
  int n2; // edx
  int v8; // ecx
  int v9; // esi
  int v10; // edi
  unsigned __int64 v11; // kr00_8
  int v13; // [esp+Ch] [ebp-1F78h]
  int v14; // [esp+10h] [ebp-1F74h]
  char *Source_1; // [esp+14h] [ebp-1F70h]
  int v16[30]; // [esp+18h] [ebp-1F6Ch] BYREF
  int v17[30]; // [esp+90h] [ebp-1EF4h] BYREF
  int v18[30]; // [esp+108h] [ebp-1E7Ch] BYREF
  char Source[7680]; // [esp+180h] [ebp-1E04h] BYREF

  memset(v17, 0, sizeof(v17));
  memset(v18, 0, sizeof(v18));
  v16[0] = 1;
  memset(&v16[1], 0, 0x74u);
  v6 = *(__int16 *)(a2 + 16);
  n2 = n2_1;
  v8 = 0;
  v9 = a2 + *(_DWORD *)(a2 + 4);
  v14 = 0;
  if ( v6 <= 0 )
  {
LABEL_12:
    FFX_MagicCoreOp_CreateModelTexturedVtxFormat(a1, 2 * (n2 != 0) + 8);
    FFX_Ps3Data_BuildTextureSlotRecord_LoadTime(a1, v14, (int)v17, v18, Source, (int)v16);
    return 1;
  }
  v10 = v13;
  Source_1 = Source;
  while ( *(_BYTE *)(v9 + 1) != 3 )
  {
LABEL_11:
    Source_1 += 256;
    v6 -= *(__int16 *)(v9 + 2);
    ++v8;
    v9 = v10;
    v14 = v8;
    if ( v6 <= 0 )
      goto LABEL_12;
  }
  v17[v8] = 3 * *(__int16 *)(v9 + 2);
  v18[v8] = 3 * *(__int16 *)(v9 + 2);
  if ( n2 == 1 )
  {
    v11 = a4;
  }
  else if ( n2 == 2 )
  {
    v11 = a5;
  }
  else
  {
    v11 = *(_QWORD *)(v9 + 8);
  }
  if ( sub_645600(v11 & 0x3FFF, (v11 >> 20) & 0x3F, 0, 0, 1 << ((v11 >> 26) & 0xF), 1 << ((v11 >> 30) & 0xF), Source_1) )
  {
    v8 = v14;
    n2 = n2_1;
    v10 = v9 + 8 * (*(__int16 *)(v9 + 2) + 4 * *(__int16 *)(v9 + 2) + 2);
    goto LABEL_11;
  }
  nullsub_34();
  return 0;
}


// Function: sub_A73C20
// Address: 0xa73c20
// Size: 0x170
// Prototype: 

int __cdecl sub_A73C20(__int64 a1, _DWORD *a2, int a3)
{
  unsigned int v3; // esi
  unsigned int v4; // edx
  int v5; // eax
  int v7; // eax
  int v8; // [esp+8h] [ebp-320h] BYREF
  int v9; // [esp+Ch] [ebp-31Ch] BYREF
  int v10; // [esp+10h] [ebp-318h] BYREF
  int v11; // [esp+14h] [ebp-314h] BYREF
  int v12; // [esp+18h] [ebp-310h] BYREF
  int v13; // [esp+1Ch] [ebp-30Ch] BYREF
  int v14; // [esp+20h] [ebp-308h] BYREF
  char v15[256]; // [esp+24h] [ebp-304h] BYREF
  char Source[256]; // [esp+124h] [ebp-204h] BYREF
  char Buffer[256]; // [esp+224h] [ebp-104h] BYREF

  v3 = a2[2];
  v4 = a2[3];
  v5 = 1 << ((*((_QWORD *)a2 + 1) >> 30) & 0xF);
  v14 = 0;
  v13 = 0;
  v12 = 1;
  sprintf(
    Buffer,
    "%d_%d_0_0_%d_%d.dds.phyre",
    v3 & 0x3FFF,
    (unsigned __int8)(__PAIR64__(v4, v3) >> 20) & 0x3F,
    1 << ((__PAIR64__(v4, v3) >> 26) & 0xF),
    v5);
  if ( sub_6455B0(Buffer, v15, (int)&v8, (int)&v10, (int)&v11, (int)&v9) )
  {
    sprintf(Source, "%s", v15);
    v7 = a2[1];
    v12 = 1;
    v14 = 3 * v7;
    v13 = 3 * v7;
    FFX_MagicCoreOp_CreateModelTexturedVtxFormat(a1, a3);
    FFX_Ps3Data_BuildTextureSlotRecord_LoadTime(a1, 1, (int)&v14, &v13, Source, (int)&v12);
    return 1;
  }
  else
  {
    printf("Virtuos Error: Have not load the vfx texture %s!\n", Buffer);
    return 0;
  }
}


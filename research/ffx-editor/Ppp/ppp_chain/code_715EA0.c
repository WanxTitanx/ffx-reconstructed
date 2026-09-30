// FFX Magic: PPP build texture path from opcode
int __cdecl FFX_Magic_PPP_BuildTexturePathFromOpcode(__int64 n11, int a2, int a3, int a4)
{
  int n30; // ebx
  int v5; // eax
  int v6; // ecx
  int *Buffer_1; // esi
  int v8; // edi
  int v9; // esi
  bool v10; // zf
  int v11; // eax
  unsigned __int64 v12; // kr00_8
  unsigned int v13; // ecx
  char *RWTT_1; // eax
  char v15; // cl
  int v16; // edx
  char *Buffer; // [esp+Ch] [ebp-2364h]
  int v19; // [esp+10h] [ebp-2360h] BYREF
  int v20; // [esp+14h] [ebp-235Ch] BYREF
  int v21; // [esp+18h] [ebp-2358h] BYREF
  int v22; // [esp+1Ch] [ebp-2354h] BYREF
  int v23; // [esp+20h] [ebp-2350h]
  int v24; // [esp+24h] [ebp-234Ch]
  int v25; // [esp+28h] [ebp-2348h]
  int v26; // [esp+2Ch] [ebp-2344h]
  int v27; // [esp+30h] [ebp-2340h]
  int v28[91]; // [esp+A8h] [ebp-22C8h]
  int v29[30]; // [esp+214h] [ebp-215Ch] BYREF
  int v30[30]; // [esp+28Ch] [ebp-20E4h] BYREF
  int v31[30]; // [esp+304h] [ebp-206Ch] BYREF
  char Source[7680]; // [esp+37Ch] [ebp-1FF4h] BYREF
  _BYTE RWTT[496]; // [esp+217Ch] [ebp-1F4h] BYREF

  n30 = 0; /*0x715ebd*/
  memset(v31, 0, sizeof(v31)); /*0x715ec9*/
  memset(v30, 0, sizeof(v30)); /*0x715ede*/
  v29[0] = 1; /*0x715ef3*/
  memset(&v29[1], 0, 0x74u); /*0x715efd*/
  v5 = Std_IdentityFunc(*(_DWORD *)(a2 + 28)); /*0x715f05*/
  v6 = v5 + *(_DWORD *)(v5 + 4); /*0x715f11*/
  v24 = *(__int16 *)(v5 + 16); /*0x715f16*/
  v25 = v6; /*0x715f1c*/
  if ( v24 <= 0 )
  {
LABEL_11:
    FFX_TextureSlot_MatrixInit(n11, a4 | 8); /*0x7160ae*/
    FFX_Ps3Data_BuildTextureSlotRecord_LoadTime(n30, SHIDWORD(n11), n11, n30, (int)v31, v30, Source, (int)v29); /*0x7160e1*/
    return 1; /*0x7160e9*/
  }
  else
  {
    Buffer_1 = &v29[26]; /*0x715f3e*/
    v8 = -7936; /*0x715f44*/
    while ( 1 )
    {
      ++n30; /*0x715f50*/
      Buffer = (char *)(Buffer_1 + 64); /*0x715f57*/
      v8 += 256; /*0x715f5d*/
      if ( n30 >= 30 ) /*0x715f66*/
        return 0; /*0x716117*/
      v9 = 0; /*0x715f6c*/
      v10 = *(_BYTE *)(v6 + 1) == 3; /*0x715f6e*/
      v27 = 0; /*0x715f72*/
      if ( !v10 ) /*0x715f78*/
        return 0; /*0x716117*/
      v11 = *(__int16 *)(v6 + 2); /*0x715f7e*/
      v26 = v6 + 16; /*0x715f85*/
      if ( v11 > 0 ) /*0x715f8d*/
      {
        v9 = 3 * v11; /*0x715f8f*/
        v27 = 3 * v11; /*0x715f97*/
        v26 = 32 * v11 + v6 + 16; /*0x715f9d*/
      }
      v29[n30 + 29] = v27; /*0x715fa9*/
      v30[n30 + 29] = v9; /*0x715fb0*/
      v12 = *(_QWORD *)(v6 + 8); /*0x715fbf*/
      v13 = *(_DWORD *)(v6 + 8); /*0x715fd7*/
      v27 = 1 << ((v12 >> 26) & 0xF); /*0x715fd9*/
      v23 = 1 << ((__PAIR64__(HIDWORD(v12), v13) >> 30) & 0xF); /*0x715ff9*/
      Buffer_1 = (int *)Buffer; /*0x716010*/
      sprintf( /*0x71601f*/
        Buffer,
        "%d_%d_0_0_%d_%d.dds.phyre",
        (unsigned __int16)v12 & 0x3FFF,
        (unsigned __int8)(v12 >> 20) & 0x3F,
        v27,
        v23);
      if ( !FFX_Ps3Data_ResolveTexturePathByName_Wrapper(Buffer, RWTT, (int)&v21, (int)&v19, (int)&v22, (int)&v20) )
      {
        nullsub_34("Virtuos Error: Have not load the vfx texture %s!\n", (const char *)&v29[64 * n30 + 26]);
        return 0; /*0x71610f*/
      }
      RWTT_1 = RWTT; /*0x716059*/
      do /*0x71606a*/
      {
        v15 = *RWTT_1; /*0x716060*/
        RWTT_1[v8] = *RWTT_1; /*0x716062*/
        ++RWTT_1; /*0x716065*/
      }
      while ( v15 ); /*0x71606a*/
      v6 = v26; /*0x71607c*/
      v16 = v24 - *(__int16 *)(v25 + 2); /*0x716082*/
      v28[n30] = 0; /*0x716084*/
      v28[n30 + 30] = 0; /*0x71608f*/
      v24 = v16; /*0x71609a*/
      v25 = v6; /*0x7160a0*/
      if ( v16 <= 0 ) /*0x7160a8*/
        goto LABEL_11; /*0x7160a8*/
    }
  }
}
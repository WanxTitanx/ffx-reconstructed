// Function: sub_80B0D0
// Address: 0x80b0d0
int __cdecl sub_80B0D0(int a1, int a2)
{
  int v2; // esi
  __int16 v3; // ax
  int v4; // edi
  char *v5; // ecx
  int n0x4000; // eax
  _DWORD *n0xFF80; // esi
  int v9; // edx
  char *v10; // eax
  int v11; // ecx
  bool v12; // cc
  _BYTE dst[76]; // [esp-4Ch] [ebp-CCh] BYREF
  int v14; // [esp+Ch] [ebp-74h]
  char *v15; // [esp+10h] [ebp-70h]
  int v16; // [esp+14h] [ebp-6Ch]
  int n0x8000; // [esp+18h] [ebp-68h]
  int v18; // [esp+1Ch] [ebp-64h]
  char *v19; // [esp+20h] [ebp-60h]
  int v20; // [esp+24h] [ebp-5Ch]
  int v21; // [esp+28h] [ebp-58h]
  _DWORD *n0xFF80_1; // [esp+2Ch] [ebp-54h]
  _DWORD src[19]; // [esp+30h] [ebp-50h] BYREF

  v2 = *(_DWORD *)(a1 + 544);
  v3 = *(_WORD *)(a1 + 538);
  v4 = a2;
  v5 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v2 + 20);
  v14 = a2;
  v15 = v5;
  n0x4000 = v3 & 0xC000;
  if ( n0x4000 )
  {
    if ( n0x4000 == 0x4000 )
    {
      FFX_MagicCoreOp_32_LoadedByOPURecordSpawn(a1, a2);
      *(_WORD *)(*(_DWORD *)a1 + 26) = *(_WORD *)(v2 + 26) + *(_WORD *)(a2 + 4);
      return a2 + 6;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    n0xFF80 = (_DWORD *)((*(_WORD *)(a1 + 770) + 16) & 0xFFF0);
    n0x8000 = (int)n0xFF80;
    if ( (unsigned __int16)n0xFF80 >= 0xFF80u )
    {
      LOWORD(n0xFF80) = 0x8000;
      n0x8000 = 0x8000;
    }
    v9 = 0;
    v21 = 0;
    if ( v5[8] )
    {
      v10 = v5 + 16;
      v19 = v5 + 16;
      do
      {
        if ( *(_WORD *)(a1 + 530) )
        {
          *(_DWORD *)a1 = a1;
        }
        else
        {
          v20 = *(_DWORD *)(a1 + 544);
          v16 = (*(__int16 *)(a1 + 538) >> 12) & 3;
          v18 = sub_801620(a1 + 768, v16);
          n0xFF80_1 = (_DWORD *)(*(_DWORD *)(a1 + 800) + (v18 << 8));
          sub_801120(n0xFF80_1);
          sub_800DD0(a1 + 768, (int)n0xFF80_1, v20);
          n0xFF80 = n0xFF80_1;
          *((_WORD *)n0xFF80_1 + 13) = (*(_WORD *)(a1 + 770))++;
          if ( *(_WORD *)(a1 + 770) >= 0xFFF0u )
            *(_WORD *)(a1 + 770) = 0x8000;
          *n0xFF80 = unknown_libname_742(v4 + *(__int16 *)(v4 + 2));
          src[0] = v20;
          src[3] = v18;
          src[1] = n0xFF80;
          src[2] = 0;
          src[5] = 0;
          sprintf((char *const)&src[6], "LoadedByOPU_UNIT");
          if ( v16 == 1 )
          {
            qmemcpy(dst, src, sizeof(dst));
            nullsub_106(v18);
            v4 = v14;
            n0xFF80 = n0xFF80_1;
          }
          v9 = v21;
          v10 = v19;
          *(_DWORD *)a1 = n0xFF80;
          LOWORD(n0xFF80) = n0x8000;
        }
        v11 = *(_DWORD *)a1;
        *(_BYTE *)(v11 + 24) = v10[v9];
        *(_WORD *)(v11 + 26) = v9++ + (_WORD)n0xFF80;
        v12 = v9 < (unsigned __int8)v15[8];
        v10 = v19;
        v21 = v9;
      }
      while ( v12 );
    }
    *(_WORD *)(a1 + 770) = (_WORD)n0xFF80 + 16;
    return v4 + 4;
  }
}

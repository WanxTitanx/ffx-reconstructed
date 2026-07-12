// Function: sub_80B2E0
// Address: 0x80b2e0
__int16 *__cdecl sub_80B2E0(int a1, __int16 *a2)
{
  __int16 v2; // dx
  __int16 *v3; // ebx
  int v4; // esi
  unsigned int n20480; // eax
  __int16 v7; // cx
  __int16 *v8; // eax
  __int16 v9; // si
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  __int16 v13; // ax
  int v14; // esi
  int v15; // edi
  __int16 v16; // cx
  int v17; // eax
  __int16 dst[38]; // [esp-4Ch] [ebp-B8h] BYREF
  __int16 *v19; // [esp+10h] [ebp-5Ch]
  int v20; // [esp+14h] [ebp-58h]
  int v21; // [esp+18h] [ebp-54h]
  _DWORD src[19]; // [esp+1Ch] [ebp-50h] BYREF

  v2 = *(_WORD *)(a1 + 538);
  v3 = a2;
  v4 = *(_DWORD *)(a1 + 544);
  n20480 = v2 & 0xF000;
  v20 = a1;
  v19 = a2;
  v21 = v4;
  if ( n20480 > 0x3000 )
  {
    if ( n20480 == 0x4000 )
    {
      v16 = a2[1];
      v17 = *(_DWORD *)(*(_DWORD *)(a1 + 848) + 116);
      if ( v16 )
      {
        switch ( v16 )
        {
          case 1:
            sub_7EB230(v17, 0, 0, 1);
            break;
          case 2:
            sub_7EB2D0(v17, 0, 0, 1);
            break;
          case 3:
            sub_7EB320(v17, 0, 0, 1);
            break;
        }
      }
      else
      {
        sub_7EB280(v17, 0, 0, 1);
      }
      return a2 + 2;
    }
    else if ( n20480 == 20480 )
    {
      sub_7EC6F0(v2 & 0x800);
      return a2 + 1;
    }
    return v3;
  }
  if ( n20480 == 12288 )
  {
    v13 = *(_WORD *)(a2[1] + v4);
    if ( v13 )
    {
      v14 = a2[2] & 3;
      v15 = *(_DWORD *)(a1 + 800) + (v13 << 8);
      *(_DWORD *)(v15 + 4 * v14) = unknown_libname_742((char *)a2 + a2[3] + (*(_DWORD *)(v15 + 4 * v14) & 0x80000000));
      *(_BYTE *)(v14 + v15 + 16) = 1;
    }
    return a2 + 4;
  }
  else if ( (v2 & 0xF000) != 0 )
  {
    if ( n20480 != 4096 )
    {
      if ( n20480 == 0x2000 )
      {
        *(_WORD *)(a2[2] + sub_800F80((_DWORD *)(a1 + 768), v4, a2[1])) = *(_WORD *)(v20 + 532);
        return a2 + 3;
      }
      return v3;
    }
    v7 = (unsigned int)(v4 - *(_DWORD *)(a1 + 800)) >> 8;
    v8 = *(__int16 **)(a1 + 784);
    v9 = *v8;
    if ( *v8 >= 0 )
    {
      while ( v9 != v7 )
      {
        v9 = v8[1];
        ++v8;
        if ( v9 < 0 )
          return a2 + 1;
      }
      sub_8013E0(a1 + 768, v9);
      sub_8016A0(a1 + 768, v9, 1);
      nullsub_105(v9);
      src[1] = v21;
      src[3] = v9;
      src[0] = 0;
      src[2] = a1 + 768;
      src[5] = 0;
      sprintf((char *const)&src[6], "LoadedByOPU_UNIT_ETC");
      qmemcpy(dst, src, sizeof(dst));
      nullsub_106(v9);
      v10 = v20;
      v3 = v19;
      --*(_WORD *)(v20 + 536);
      *(_WORD *)(v10 + 534) = 0;
      *(_BYTE *)(v10 + 528) = 1;
    }
    return v3 + 1;
  }
  else
  {
    v11 = (unsigned __int16)a2[2];
    dst[36] = a2[1];
    v19 = (__int16 *)(unsigned __int16)dst[36];
    v21 = v11;
    v12 = sub_800F80((_DWORD *)(a1 + 768), v4, dst[36]);
    if ( v12 == *(_DWORD *)(a1 + 800) )
    {
      if ( (_WORD)v19 || v4 == v12 || *(_WORD *)(v12 + 26) )
        return a2 + 3;
    }
    else if ( v4 == v12 )
    {
      return a2 + 3;
    }
    return (__int16 *)((char *)a2 + (__int16)v21);
  }
}

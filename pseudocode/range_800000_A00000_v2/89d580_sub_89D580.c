// Function: sub_89D580
// Address: 0x89d580
void __cdecl sub_89D580(int a1)
{
  char v1; // al
  int v2; // ecx
  __int16 v3; // dx
  __int16 n4096; // ax
  __int16 v5; // cx
  __int16 v6; // bx
  __int16 v7; // cx
  __int16 v8; // ax
  __int16 v9; // si
  __int16 v10; // ax
  __int16 v11; // ax
  __int16 v12; // dx
  int v13; // ecx
  int v14; // eax
  __int16 v15; // cx
  int v16; // eax
  int v17; // [esp+0h] [ebp-4h]

  if ( unk_23CC08C && *(int (**)())(a1 + 136) == nullsub_136 )
  {
    if ( unk_133D6A0 == 1 )
      n32 = 64;
    if ( (n32 & 0x40) != 0 )
    {
      v1 = *(_BYTE *)(a1 + 11);
      if ( v1 <= 0 )
      {
        if ( unk_23CC092[0] > 0 )
        {
          FFX_Btl_MenuPopSubmenuEntry();
          ++*(_BYTE *)(a1 + 1);
          FFX_Btl_MenuDispatchSfx(4);
        }
      }
      else
      {
        *(_WORD *)(a1 + 2 * v1 + 22) = 255;
        *(_WORD *)(a1 + 2 * (char)(*(_BYTE *)(a1 + 11))-- + 14) = 255;
        v2 = *(char *)(a1 + 11);
        *(_WORD *)(a1 + 66) = *(_WORD *)(a1 + 2 * v2 + 14);
        *(_WORD *)(a1 + 30) = *(_WORD *)(a1 + 2 * v2 + 22);
        FFX_Btl_MenuCursorUpdateCurrent(0);
        FFX_Btl_MenuDispatchSfx(4);
      }
      return;
    }
    if ( (n32 & 0x20) != 0 )
    {
      if ( sub_89AC10(*(__int16 *)(a1 + 8), *(__int16 *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66))) >= 0 )
      {
        *(_WORD *)(a1 + 2 * *(char *)(a1 + 11) + 22) = *(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66));
        *(_WORD *)(a1 + 2 * (char)(*(_BYTE *)(a1 + 11))++ + 14) = *(_WORD *)(a1 + 66);
        if ( *(_BYTE *)(a1 + 11) < *(_BYTE *)(a1 + 10) )
        {
          FFX_Btl_MenuCursorUpdateCurrent(*(_WORD *)(a1 + 22));
          FFX_Btl_MenuDispatchSfx(1);
          return;
        }
        if ( sub_89A2A0(*(__int16 *)(a1 + 8), *(__int16 *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66))) == 1 )
        {
          FFX_Btl_MenuDispatchSfx(1);
          return;
        }
      }
      goto LABEL_17;
    }
    if ( (n32 & 4) != 0 )
    {
LABEL_17:
      FFX_Btl_MenuDispatchSfx(3);
      return;
    }
    v3 = *(_WORD *)(a1 + 66);
    v17 = v3;
    if ( (unk_25D09D2 & 0x9000) != 0x9000
      && (unk_25D09D2 & 0x3000) != 0x3000
      && (unk_25D09D2 & 0xC000) != 0xC000
      && (unk_25D09D2 & 0x6000) != 0x6000 )
    {
      n4096 = n4096;
      if ( n4096 == 4096 )
      {
        *(_WORD *)(a1 + 66) = v3 - *(_WORD *)(a1 + 56);
        n4096 = n4096;
      }
      if ( n4096 == 0x4000 )
      {
        *(_WORD *)(a1 + 66) += *(_WORD *)(a1 + 56);
        n4096 = n4096;
      }
      if ( n4096 == (__int16)0x8000 )
      {
        --*(_WORD *)(a1 + 66);
        n4096 = n4096;
      }
      if ( n4096 == 0x2000 )
      {
        ++*(_WORD *)(a1 + 66);
        n4096 = n4096;
      }
      if ( n4096 == 4096 || n4096 == 0x4000 )
      {
        v5 = *(_WORD *)(a1 + 66);
        if ( v5 < 0 )
        {
          *(_WORD *)(a1 + 66) = v5 + *(_WORD *)(a1 + 56);
          n4096 = n4096;
        }
        v6 = *(_WORD *)(a1 + 66);
        v7 = *(_WORD *)(a1 + 68);
        if ( v6 >= v7 )
        {
          if ( v6 / *(__int16 *)(a1 + 56) <= (v7 - 1) / *(__int16 *)(a1 + 56) )
            *(_WORD *)(a1 + 66) = *(_WORD *)(a1 + 68) - 1;
          else
            *(_WORD *)(a1 + 66) = v6 - *(_WORD *)(a1 + 56);
          n4096 = n4096;
        }
      }
      if ( n4096 == (__int16)0x8000 || n4096 == 0x2000 )
      {
        if ( *(__int16 *)(a1 + 66) < 0 )
          *(_WORD *)(a1 + 66) = 0;
        v8 = *(_WORD *)(a1 + 68);
        if ( *(__int16 *)(a1 + 66) >= v8 )
          *(_WORD *)(a1 + 66) = v8 - 1;
      }
    }
    *(_WORD *)(a1 + 2 * *(char *)(a1 + 11) + 22) = *(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66));
    *(_WORD *)(a1 + 2 * *(char *)(a1 + 11) + 14) = *(_WORD *)(a1 + 66);
    v9 = *(_WORD *)(a1 + 66);
    v10 = *(_WORD *)(a1 + 64);
    if ( v9 < v10 )
    {
      v11 = v10 - *(_WORD *)(a1 + 56);
      *(_DWORD *)(a1 + 136) = FFX_BtlMenu_ScrollDown;
      *(_WORD *)(a1 + 64) = v11;
    }
    v12 = *(_WORD *)(a1 + 56);
    v13 = v12 * *(__int16 *)(a1 + 58);
    if ( v9 >= v13 + *(__int16 *)(a1 + 64) )
    {
      *(_WORD *)(a1 + 64) += v12;
      *(_DWORD *)(a1 + 136) = FFX_BtlMenu_ScrollUp;
    }
    v14 = *(__int16 *)(a1 + 68);
    if ( v14 <= v13 )
    {
      LOWORD(v16) = 0;
    }
    else
    {
      v15 = *(_WORD *)(a1 + 64);
      v16 = v12 * ((v12 + v14 - 1) / v12 - *(__int16 *)(a1 + 58));
      if ( v15 <= v16 )
        LOWORD(v16) = v15 < 0 ? 0 : v15;
    }
    *(_WORD *)(a1 + 64) = v16;
    if ( v9 != v17 )
    {
      *(_WORD *)(a1 + 30) = *(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * v9);
      FFX_Btl_MenuDispatchSfx(1);
    }
  }
}

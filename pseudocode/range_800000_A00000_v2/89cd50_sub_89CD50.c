// Function: sub_89CD50
// Address: 0x89cd50
void __cdecl sub_89CD50(int a1)
{
  int v1; // esi
  char v2; // al
  unsigned __int16 ActorUsableCommandCount; // di
  unsigned __int8 v4; // al
  __int16 n32; // ax
  __int16 v6; // ax
  float *PartyDataArray; // eax
  int v8; // ecx
  bool v9; // zf
  __int16 v10; // dx
  __int16 n4096; // ax
  __int16 v12; // cx
  __int16 v13; // bx
  __int16 v14; // cx
  __int16 v15; // ax
  char v16; // al
  int v17; // ecx
  __int16 v18; // di
  __int16 v19; // ax
  __int16 v20; // ax
  int v21; // ebx
  int v22; // edx
  __int16 v23; // ax
  int v24; // eax
  int v25; // eax
  __int16 v26; // cx
  int v27; // [esp+0h] [ebp-10h]
  __int16 v28; // [esp+8h] [ebp-8h]
  int v29; // [esp+Ch] [ebp-4h] BYREF

  if ( !unk_23CC08C )
    return;
  v1 = a1;
  if ( *(int (**)())(a1 + 136) != nullsub_136 )
    return;
  v2 = unk_23CC092[0];
  if ( !unk_23CC092[0] && (n32 & 0x10) != 0 )
  {
    ActorUsableCommandCount = FFX_Btl_GetActorUsableCommandCount(*(_WORD *)(a1 + 8));
    if ( ActorUsableCommandCount )
    {
      FFX_Btl_MenuDispatchSfx(1);
      v4 = *(_BYTE *)(a1 + 8);
      unk_23CC048[0] = ActorUsableCommandCount;
      unk_23CC040[0] = v4;
      MEMORY[0x23CC043] = 1;
      MEMORY[0x23CC04A][0] = 255;
      unk_23CC050 = 1 << *(_BYTE *)(a1 + 8);
      unk_133D138 = 1 << *(_BYTE *)(a1 + 8);
      FFX_Battle_ConfirmTargetSelection(unk_23CC040, 0.0, 0);
      FFX_Btl_MenuCursorResetGlobals();
      unk_133C8FC = 0;
      sub_8AE550(2);
      unk_23CC088[0] = 255;
      return;
    }
    FFX_Btl_MenuDispatchSfx(3);
    v2 = unk_23CC092[0];
  }
  if ( (n32 & 4) != 0 )
  {
    if ( !v2 && !sub_7850B0(*(__int16 *)(a1 + 8)) && sub_89A2A0(*(__int16 *)(a1 + 8), 12290) == 1 )
    {
      FFX_Btl_MenuDispatchSfx(1);
      return;
    }
    goto LABEL_24;
  }
  if ( v2 )
    goto LABEL_26;
  n32 = n32;
  if ( n32 < 0 )
  {
    if ( FFX_Btl_CheckActorCommandAvailabilityMask(*(__int16 *)(a1 + 8)) > 0 )
    {
      sub_89A2A0(*(__int16 *)(a1 + 8), 0xFFFF);
      FFX_Btl_MenuDispatchSfx(1);
      return;
    }
    n32 = n32;
  }
  if ( (n32 & 0x2000) == 0 )
  {
LABEL_26:
    v10 = *(_WORD *)(a1 + 66);
    v27 = v10;
    if ( (unk_25D09D2 & 0x9000) != 0x9000
      && (unk_25D09D2 & 0x3000) != 0x3000
      && (unk_25D09D2 & 0xC000) != 0xC000
      && (unk_25D09D2 & 0x6000) != 0x6000 )
    {
      n4096 = n4096;
      if ( n4096 == 4096 )
      {
        *(_WORD *)(a1 + 66) = v10 - *(_WORD *)(a1 + 56);
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
        v12 = *(_WORD *)(a1 + 66);
        if ( v12 < 0 )
        {
          *(_WORD *)(a1 + 66) = v12 + *(_WORD *)(a1 + 56);
          n4096 = n4096;
        }
        v13 = *(_WORD *)(a1 + 66);
        v14 = *(_WORD *)(a1 + 68);
        if ( v13 >= v14 )
        {
          if ( v13 / *(__int16 *)(a1 + 56) <= (v14 - 1) / *(__int16 *)(a1 + 56) )
            *(_WORD *)(a1 + 66) = *(_WORD *)(a1 + 68) - 1;
          else
            *(_WORD *)(a1 + 66) = v13 - *(_WORD *)(a1 + 56);
          n4096 = n4096;
        }
      }
      if ( n4096 == (__int16)0x8000 || n4096 == 0x2000 )
      {
        if ( *(__int16 *)(a1 + 66) < 0 )
          *(_WORD *)(a1 + 66) = 0;
        v15 = *(_WORD *)(a1 + 68);
        if ( *(__int16 *)(a1 + 66) >= v15 )
          *(_WORD *)(a1 + 66) = v15 - 1;
      }
    }
    *(_WORD *)(a1 + 2 * *(char *)(a1 + 11) + 22) = *(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66));
    *(_WORD *)(a1 + 2 * *(char *)(a1 + 11) + 14) = *(_WORD *)(a1 + 66);
    if ( unk_133D6A0 == 1 )
    {
      if ( unk_133D6A4 != 1 && unk_133D6AC != 1 )
        unk_133D6A4 = 1;
      n32 = 64;
    }
    if ( (n32 & 0x40) != 0 )
    {
      v16 = *(_BYTE *)(a1 + 11);
      if ( v16 <= 0 )
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
        *(_WORD *)(a1 + 2 * v16 + 22) = 255;
        *(_WORD *)(a1 + 2 * (char)(*(_BYTE *)(a1 + 11))-- + 14) = 255;
        v17 = *(char *)(a1 + 11);
        *(_WORD *)(a1 + 66) = *(_WORD *)(a1 + 2 * v17 + 14);
        *(_WORD *)(a1 + 30) = *(_WORD *)(a1 + 2 * v17 + 22);
        FFX_Btl_MenuCursorUpdateCurrent(0);
        FFX_Btl_MenuDispatchSfx(4);
      }
      return;
    }
    if ( (n32 & 0x20) != 0 )
    {
      if ( sub_89AC10(*(__int16 *)(a1 + 8), *(unsigned __int16 *)(a1 + 2 * *(char *)(a1 + 11) + 22)) < 0 )
      {
        FFX_Btl_MenuDispatchSfx(3);
        unk_133D6A4 = 1;
        return;
      }
      *(_WORD *)(a1 + 2 * *(char *)(a1 + 11) + 22) = *(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66));
      *(_WORD *)(a1 + 2 * (char)(*(_BYTE *)(a1 + 11))++ + 14) = *(_WORD *)(a1 + 66);
      if ( *(_BYTE *)(a1 + 11) < *(_BYTE *)(a1 + 10) )
      {
        FFX_Btl_MenuCursorUpdateCurrent(*(_WORD *)(a1 + 22));
        FFX_Btl_MenuDispatchSfx(1);
        return;
      }
      if ( sub_89A2A0(*(__int16 *)(a1 + 8), *(__int16 *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66))) != 1 )
      {
        FFX_Btl_MenuDispatchSfx(3);
        return;
      }
    }
    else
    {
      v18 = *(_WORD *)(a1 + 66);
      v19 = *(_WORD *)(a1 + 64);
      if ( v18 < v19 )
      {
        v20 = v19 - *(_WORD *)(a1 + 56);
        *(_DWORD *)(a1 + 136) = FFX_BtlMenu_ScrollDown;
        *(_WORD *)(a1 + 64) = v20;
      }
      v21 = *(__int16 *)(a1 + 58);
      v22 = *(__int16 *)(a1 + 56);
      v29 = *(unsigned __int16 *)(a1 + 56);
      v28 = *(_WORD *)(a1 + 64);
      if ( v18 >= v21 * v22 + v28 )
      {
        v23 = v28 + v29;
        *(_DWORD *)(a1 + 136) = FFX_BtlMenu_ScrollUp;
        *(_WORD *)(a1 + 64) = v23;
      }
      v24 = *(__int16 *)(a1 + 68);
      if ( v24 <= v21 * v22 )
      {
        LOWORD(v25) = 0;
      }
      else
      {
        v1 = a1;
        v25 = (__int16)v29 * ((v22 - 1 + v24) / (__int16)v29 - v21);
        v26 = *(_WORD *)(a1 + 64);
        if ( v26 <= v25 )
          LOWORD(v25) = v26 < 0 ? 0 : v26;
      }
      *(_WORD *)(v1 + 64) = v25;
      if ( v18 == v27 )
        return;
      *(_WORD *)(v1 + 30) = *(_WORD *)(*(_DWORD *)(v1 + 32) + 2 * v18);
      *(_WORD *)(v1 + 2 * *(char *)(v1 + 11) + 14) = v18;
      *(_WORD *)(v1 + 2 * *(char *)(v1 + 11) + 22) = *(_WORD *)(*(_DWORD *)(v1 + 32) + 2 * *(__int16 *)(v1 + 66));
    }
    FFX_Btl_MenuDispatchSfx(1);
    return;
  }
  v6 = *(_WORD *)(a1 + 8);
  v29 = 0;
  PartyDataArray = FFX_Btl_GetPartyDataArray(v6, 13, &v29);
  v8 = v29;
  v9 = v29 == 0;
  if ( v29 > 0 )
  {
    do
    {
      if ( *((_WORD *)PartyDataArray + v8 - 1) != 255 )
        break;
      v29 = --v8;
    }
    while ( v8 > 0 );
    v9 = v8 == 0;
  }
  if ( v9 )
  {
LABEL_24:
    FFX_Btl_MenuDispatchSfx(3);
    return;
  }
  sub_89A2A0(*(__int16 *)(a1 + 8), 65534);
  FFX_Btl_MenuDispatchSfx(1);
}

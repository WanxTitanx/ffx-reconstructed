// Function: FFX_Btl_MenuCursorNavigate
// Address: 0x89c870
void __cdecl FFX_Btl_MenuCursorNavigate(int a1)
{
  int v1; // esi
  unsigned __int16 ActorUsableCommandCount; // cx
  __int16 n32; // ax
  __int16 v4; // ax
  float *PartyDataArray; // eax
  int v6; // ecx
  bool v7; // zf
  __int16 v8; // ax
  __int16 v9; // cx
  __int16 v10; // cx
  __int16 v11; // ax
  __int16 v12; // bx
  char v13; // al
  int v14; // ecx
  __int16 v15; // di
  __int16 v16; // ax
  __int16 v17; // ax
  int v18; // edx
  __int16 v19; // ax
  int v20; // eax
  int v21; // eax
  __int16 v22; // cx
  int v23; // [esp+0h] [ebp-10h]
  int v24; // [esp+4h] [ebp-Ch]
  __int16 v25; // [esp+8h] [ebp-8h]
  int v26; // [esp+Ch] [ebp-4h] BYREF

  if ( !unk_23CC08C )
    return;
  v1 = a1;
  if ( *(int (**)())(a1 + 136) != nullsub_136 )
    return;
  if ( unk_133D6A0 == 1 && unk_133D6AC == 1 )
    n32 = 16;
  if ( (n32 & 0x10) != 0 )
  {
    ActorUsableCommandCount = FFX_Btl_GetActorUsableCommandCount(*(_WORD *)(a1 + 8));
    if ( ActorUsableCommandCount )
    {
      unk_23CC040[0] = *(_BYTE *)(a1 + 8);
      MEMORY[0x23CC043] = 1;
      unk_23CC048[0] = ActorUsableCommandCount;
      MEMORY[0x23CC04A][0] = 255;
      unk_23CC050 = 1 << *(_BYTE *)(a1 + 8);
      unk_133D138 = 1 << *(_BYTE *)(a1 + 8);
      FFX_Battle_ConfirmTargetSelection(unk_23CC040, 0.0, 0);
      FFX_Btl_MenuCursorResetGlobals();
      unk_133C8FC = 0;
      sub_8AE550(2);
      unk_23CC088[0] = 255;
      FFX_Btl_MenuDispatchSfx(1);
      return;
    }
    FFX_Btl_MenuDispatchSfx(3);
  }
  if ( FFX_Input_ReadButtonBit(0x8000000) )
  {
    if ( !sub_7850B0(*(__int16 *)(a1 + 8)) && sub_89A2A0(*(__int16 *)(a1 + 8), 12290) == 1 )
    {
      FFX_Btl_MenuDispatchSfx(1);
      return;
    }
    goto LABEL_24;
  }
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
    v8 = *(_WORD *)(a1 + 66);
    v23 = v8;
    v9 = unk_25D09D6;
    if ( (unk_25D09D6 & 0x1000) != 0 )
    {
      *(_WORD *)(a1 + 66) = v8 - *(_WORD *)(a1 + 56);
      v9 = unk_25D09D6;
    }
    if ( (v9 & 0x4000) != 0 )
      *(_WORD *)(a1 + 66) += *(_WORD *)(a1 + 56);
    v10 = *(_WORD *)(a1 + 66);
    if ( v10 < 0 )
      *(_WORD *)(a1 + 66) = v10 + *(_WORD *)(a1 + 56);
    v11 = *(_WORD *)(a1 + 68);
    v12 = *(_WORD *)(a1 + 66);
    if ( v12 >= v11 )
    {
      if ( v12 / *(__int16 *)(a1 + 56) <= (v11 - 1) / *(__int16 *)(a1 + 56) )
        *(_WORD *)(a1 + 66) = *(_WORD *)(a1 + 68) - 1;
      else
        *(_WORD *)(a1 + 66) = v12 - *(_WORD *)(a1 + 56);
    }
    *(_WORD *)(a1 + 2 * *(char *)(a1 + 11) + 22) = *(_WORD *)(*(_DWORD *)(a1 + 32) + 2 * *(__int16 *)(a1 + 66));
    *(_WORD *)(a1 + 2 * *(char *)(a1 + 11) + 14) = *(_WORD *)(a1 + 66);
    if ( unk_133D6A0 == 1 )
    {
      unk_133D6A4 = 0;
      if ( *(__int16 *)(a1 + 66) > 0 )
        *(_WORD *)(a1 + 66) = 0;
      if ( sub_89AC10(unk_23CC088[0], 12288) < 0 )
        FFX_Btl_Death_TryTriggerPostDeathEvent();
      n32 = 32;
    }
    if ( (n32 & 0x40) != 0 )
    {
      v13 = *(_BYTE *)(a1 + 11);
      if ( v13 <= 0 )
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
        *(_WORD *)(a1 + 2 * v13 + 22) = 255;
        *(_WORD *)(a1 + 2 * (char)(*(_BYTE *)(a1 + 11))-- + 14) = 255;
        v14 = *(char *)(a1 + 11);
        *(_WORD *)(a1 + 66) = *(_WORD *)(a1 + 2 * v14 + 14);
        *(_WORD *)(a1 + 30) = *(_WORD *)(a1 + 2 * v14 + 22);
        FFX_Btl_MenuCursorUpdateCurrent(0);
        FFX_Btl_MenuDispatchSfx(4);
      }
      return;
    }
    if ( (n32 & 0x20) != 0 )
    {
      if ( sub_89AC10(*(__int16 *)(a1 + 8), *(unsigned __int16 *)(a1 + 2 * *(char *)(a1 + 11) + 22)) < 0 )
        goto LABEL_52;
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
LABEL_52:
        FFX_Btl_MenuDispatchSfx(3);
        return;
      }
    }
    else
    {
      v15 = *(_WORD *)(a1 + 66);
      v16 = *(_WORD *)(a1 + 64);
      if ( v15 < v16 )
      {
        v17 = v16 - *(_WORD *)(a1 + 56);
        *(_DWORD *)(a1 + 136) = FFX_BtlMenu_ScrollDown;
        *(_WORD *)(a1 + 64) = v17;
      }
      v18 = *(__int16 *)(a1 + 56);
      v24 = *(__int16 *)(a1 + 58);
      v26 = *(unsigned __int16 *)(a1 + 56);
      v25 = *(_WORD *)(a1 + 64);
      if ( v15 >= v18 * v24 + v25 )
      {
        v19 = v25 + v26;
        *(_DWORD *)(a1 + 136) = FFX_BtlMenu_ScrollUp;
        *(_WORD *)(a1 + 64) = v19;
      }
      v20 = *(__int16 *)(a1 + 68);
      if ( v20 <= v18 * v24 )
      {
        LOWORD(v21) = 0;
      }
      else
      {
        v1 = a1;
        v21 = (__int16)v26 * ((v18 - 1 + v20) / (__int16)v26 - v24);
        v22 = *(_WORD *)(a1 + 64);
        if ( v22 <= v21 )
          LOWORD(v21) = v22 < 0 ? 0 : v22;
      }
      *(_WORD *)(v1 + 64) = v21;
      if ( v15 == v23 )
        return;
      *(_WORD *)(v1 + 30) = *(_WORD *)(*(_DWORD *)(v1 + 32) + 2 * v15);
      *(_WORD *)(v1 + 2 * *(char *)(v1 + 11) + 14) = v15;
      *(_WORD *)(v1 + 2 * *(char *)(v1 + 11) + 22) = *(_WORD *)(*(_DWORD *)(v1 + 32) + 2 * *(__int16 *)(v1 + 66));
    }
    FFX_Btl_MenuDispatchSfx(1);
    return;
  }
  v4 = *(_WORD *)(a1 + 8);
  v26 = 0;
  PartyDataArray = FFX_Btl_GetPartyDataArray(v4, 13, &v26);
  v6 = v26;
  v7 = v26 == 0;
  if ( v26 > 0 )
  {
    do
    {
      if ( *((_WORD *)PartyDataArray + v6 - 1) != 255 )
        break;
      v26 = --v6;
    }
    while ( v6 > 0 );
    v7 = v6 == 0;
  }
  if ( v7 )
  {
LABEL_24:
    FFX_Btl_MenuDispatchSfx(3);
    return;
  }
  sub_89A2A0(*(__int16 *)(a1 + 8), 65534);
  FFX_Btl_MenuDispatchSfx(1);
}

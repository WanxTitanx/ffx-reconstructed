// Function: sub_8D0430
// Address: 0x8d0430
int __cdecl sub_8D0430(int a1)
{
  int n8; // ebx
  int n3; // eax
  int v4; // ecx
  int v5; // edx
  int v6; // edi
  int MenuSlotIndex; // eax
  __int16 v8; // ax
  _WORD *v9; // edx
  int v10; // eax
  __int16 v11; // ax
  _WORD *v12; // ecx
  bool v13; // sf
  int n255_1; // eax
  int n255; // edi
  char v16; // al
  int v17; // esi
  int v18; // edx
  int v19; // ecx
  int v20; // esi
  int v21; // edx
  int v22; // esi
  int v23; // edx
  int v24; // esi
  __int16 v25; // ax
  _WORD *v26; // ecx
  int v27; // edx
  int v28; // esi
  int v29; // edx
  int v30; // esi
  int v31; // edx
  int v32; // esi
  __int16 v33; // ax
  _WORD *v34; // ecx
  int v35; // [esp-8h] [ebp-18h]
  int v36; // [esp-8h] [ebp-18h]
  int n3_1; // [esp+8h] [ebp-8h]
  int n3_2; // [esp+Ch] [ebp-4h]
  int MenuSlotIndex_1; // [esp+18h] [ebp+8h]
  int v40; // [esp+18h] [ebp+8h]

  n8 = (unsigned __int16)sub_8BE3E0();
  n3_2 = (unsigned __int16)sub_8BE440();
  sub_8BE480();
  n3 = *(_DWORD *)(a1 + 28);
  v4 = unk_186A6D4;
  v5 = unk_186A6D8;
  while ( 2 )
  {
    switch ( n3 )
    {
      case 0:
        *(_DWORD *)(a1 + 28) = 7;
        goto LABEL_4;
      case 1:
LABEL_4:
        *(_DWORD *)(a1 + 28) = 3;
        n3 = 3;
        continue;
      case 2:
        sub_8E49D0(v4, v5);
        v4 = unk_186A6D4;
        v5 = unk_186A6D8;
        *(_DWORD *)(a1 + 28) = 3;
        n3 = 3;
        continue;
      case 3:
        v6 = *(__int16 *)(MEMORY[0x23CC128] + 72);
        n3_1 = *(char *)(MEMORY[0x23CC128] + 69);
        if ( *(_WORD *)(MEMORY[0x23CC128] + 72) )
        {
          if ( v6 == 1 )
          {
            MenuSlotIndex = FFX_Party_GetMenuSlotIndex();
            MenuSlotIndex_1 = MenuSlotIndex;
            if ( unk_186A6D8 )
            {
              sub_8C2340(1);
            }
            else
            {
              sub_8D0DA0(MenuSlotIndex);
              *(_BYTE *)(unk_186A6D8 + 69) = -1;
            }
            v8 = sub_8C1B90();
            v9 = (_WORD *)unk_186A6D8;
            *(_WORD *)(unk_186A6D8 + 48) = v8;
            v9[25] = dword_186A760[MenuSlotIndex_1];
            v9[26] = dword_186A760[MenuSlotIndex_1];
            v9[36] = dword_186A7A0[MenuSlotIndex_1];
            sub_8D0C60();
            v4 = unk_186A6D4;
          }
        }
        else
        {
          v10 = FFX_Party_GetMenuSlotIndex();
          v40 = v10;
          if ( unk_186A6D4 )
          {
            sub_8C2340(0);
          }
          else
          {
            sub_8D0D20(v10);
            *(_BYTE *)(unk_186A6D4 + 69) = -1;
          }
          v11 = sub_8C1B90();
          v12 = (_WORD *)unk_186A6D4;
          *(_WORD *)(unk_186A6D4 + 48) = v11;
          v12[25] = dword_186A6E0[v40];
          v12[26] = dword_186A6E0[v40];
          v12[36] = dword_186A720[v40];
          sub_8D0C80();
          v5 = unk_186A6D8;
        }
        n3 = n3_1;
        v13 = n3_1 < 0;
        if ( n3_1 <= 0 )
          goto LABEL_22;
        if ( !v6 )
        {
          n3 = 8;
          continue;
        }
        if ( v6 == 1 )
        {
          n3 = 4;
          continue;
        }
        v13 = n3_1 < 0;
LABEL_22:
        if ( v13 )
        {
          n3 = 10;
          continue;
        }
        return n3;
      case 4:
        sub_8D1B40(v4, v5);
        *(_DWORD *)(a1 + 28) = 6;
        goto LABEL_25;
      case 5:
LABEL_25:
        sub_8D1B40(v4, v5);
        *(_DWORD *)(a1 + 28) = 6;
        goto LABEL_26;
      case 6:
LABEL_26:
        if ( !v5 )
          goto LABEL_34;
        n255_1 = FFX_Party_GetMenuSlotIndex();
        v4 = unk_186A6D8;
        n255 = n255_1;
        v16 = *(_BYTE *)(unk_186A6D8 + 69);
        if ( v16 <= 0 )
        {
          if ( v16 < 0 )
          {
            dword_186A760[n255] = *(__int16 *)(unk_186A6D8 + 50);
            n3 = *(__int16 *)(v4 + 72);
            dword_186A7A0[n255] = n3;
            *(_DWORD *)(a1 + 28) = 2;
            return n3;
          }
LABEL_34:
          n3 = sub_8A9AE0(v4);
          if ( n3 > 1 )
          {
            n3 = sub_8AB1D0();
            if ( n3 )
            {
              n3 = n3_2;
              if ( (n3_2 & 4) != 0 && n8 == 4 )
              {
                v20 = FFX_Party_GetMenuSlotIndex();
                FFX_BtlEffect_Enable(-2147483644);
                v21 = unk_186A6D8;
                dword_186A760[v20] = *(__int16 *)(unk_186A6D8 + 50);
                dword_186A7A0[v20] = *(__int16 *)(v21 + 72);
                sub_8AAF50();
              }
              else
              {
                if ( (n3_2 & 8) == 0 || n8 != 8 )
                  return n3;
                v22 = FFX_Party_GetMenuSlotIndex();
                FFX_BtlEffect_Enable(-2147483644);
                v23 = unk_186A6D8;
                dword_186A760[v22] = *(__int16 *)(unk_186A6D8 + 50);
                dword_186A7A0[v22] = *(__int16 *)(v23 + 72);
                sub_8AAEC0();
              }
              v24 = FFX_Party_GetMenuSlotIndex();
              n3 = sub_8C2340(1);
              if ( unk_186A6D8 )
              {
                v25 = sub_8C1B90();
                v26 = (_WORD *)unk_186A6D8;
                v35 = unk_186A6D8;
                *(_WORD *)(unk_186A6D8 + 48) = v25;
                v26[25] = dword_186A760[v24];
                v26[26] = dword_186A760[v24];
                v26[36] = dword_186A7A0[v24];
                return sub_8D19F0(v35);
              }
            }
          }
        }
        else
        {
          nullsub_34();
          v17 = LOWORD(MEMORY[0x1597730][*(__int16 *)(unk_186A6D8 + 72)]);
          if ( sub_8C1BD0(n255) == v17 )
          {
            FFX_BtlEffect_Enable(-2147483645);
          }
          else
          {
            sub_8C1BD0(n255);
            nullsub_34();
            FFX_BtlEffect_Enable(-2147483548);
          }
          sub_8C2340(1);
          sub_8C2C70(n255, MEMORY[0x1597730][*(__int16 *)(unk_186A6D8 + 72)]);
          return sub_8D1B40(v19, v18);
        }
        return n3;
      case 7:
        sub_8D1B20(v4, v5);
        *(_DWORD *)(a1 + 28) = 9;
        goto LABEL_45;
      case 8:
LABEL_45:
        sub_8D1B20(v4, v5);
        *(_DWORD *)(a1 + 28) = 9;
        goto LABEL_46;
      case 9:
LABEL_46:
        if ( v4 && *(_BYTE *)(v4 + 69) )
        {
          n3 = FFX_Party_GetMenuSlotIndex();
          v27 = unk_186A6D4;
          dword_186A6E0[n3] = *(__int16 *)(unk_186A6D4 + 50);
          dword_186A720[n3] = *(__int16 *)(v27 + 72);
          *(_BYTE *)(v27 + 69) = -1;
          *(_DWORD *)(a1 + 28) = 2;
          return n3;
        }
        n3 = ((int (*)(void))sub_8A9AE0)();
        if ( n3 <= 1 )
          return n3;
        n3 = sub_8AB1D0();
        if ( !n3 )
          return n3;
        n3 = n3_2;
        if ( (n3_2 & 4) != 0 && n8 == 4 )
        {
          v28 = FFX_Party_GetMenuSlotIndex();
          FFX_BtlEffect_Enable(-2147483644);
          v29 = unk_186A6D4;
          dword_186A6E0[v28] = *(__int16 *)(unk_186A6D4 + 50);
          dword_186A720[v28] = *(__int16 *)(v29 + 72);
          sub_8AAF50();
        }
        else
        {
          if ( (n3_2 & 8) == 0 || n8 != 8 )
            return n3;
          v30 = FFX_Party_GetMenuSlotIndex();
          FFX_BtlEffect_Enable(-2147483644);
          v31 = unk_186A6D4;
          dword_186A6E0[v30] = *(__int16 *)(unk_186A6D4 + 50);
          dword_186A720[v30] = *(__int16 *)(v31 + 72);
          sub_8AAEC0();
        }
        v32 = FFX_Party_GetMenuSlotIndex();
        n3 = sub_8C2340(0);
        if ( unk_186A6D4 )
        {
          v33 = sub_8C1B90();
          v34 = (_WORD *)unk_186A6D4;
          v36 = unk_186A6D4;
          *(_WORD *)(unk_186A6D4 + 48) = v33;
          v34[25] = dword_186A6E0[v32];
          v34[26] = dword_186A6E0[v32];
          v34[36] = dword_186A720[v32];
          return sub_8D19F0(v36);
        }
        return n3;
      case 10:
        *(_DWORD *)(a1 + 28) = 11;
        goto LABEL_60;
      case 11:
LABEL_60:
        *(_DWORD *)(a1 + 28) = 12;
        goto LABEL_61;
      case 12:
LABEL_61:
        sub_8AAD20(21);
        return sub_8AA0B0(1, 0);
      default:
        return n3;
    }
  }
}

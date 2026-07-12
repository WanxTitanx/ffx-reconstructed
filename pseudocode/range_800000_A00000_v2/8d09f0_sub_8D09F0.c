// Function: sub_8D09F0
// Address: 0x8d09f0
int __cdecl sub_8D09F0(int a1, int a2)
{
  int v2; // ebx
  int *v3; // esi
  int v4; // edi
  int v5; // ebx
  int v6; // ecx
  int n7; // eax
  int v8; // ecx
  int v9; // eax
  int MenuSlotIndex; // eax
  float v12; // [esp+0h] [ebp-24h]
  float v13; // [esp+4h] [ebp-20h]
  float v14; // [esp+8h] [ebp-1Ch]
  float v15; // [esp+Ch] [ebp-18h]
  int v16; // [esp+14h] [ebp-10h] BYREF
  int v17; // [esp+18h] [ebp-Ch]
  int v18; // [esp+1Ch] [ebp-8h] BYREF
  int v19; // [esp+20h] [ebp-4h]
  int v20; // [esp+2Ch] [ebp+8h]
  int v21; // [esp+30h] [ebp+Ch]

  *(_DWORD *)(a1 + 32) = a2;
  *(_DWORD *)(a1 + 28) = 0;
  dword_186A720[0] = 0;
  unk_186A724 = 0;
  unk_186A728 = 0;
  unk_186A72C = 0;
  unk_186A730 = 0;
  unk_186A734 = 0;
  unk_186A738 = 0;
  unk_186A73C = 0;
  unk_186A740 = 0;
  unk_186A744 = 0;
  unk_186A748 = 0;
  unk_186A74C = 0;
  unk_186A750 = 0;
  unk_186A754 = 0;
  unk_186A758 = 0;
  unk_186A75C = 0;
  dword_186A6E0[0] = 0;
  unk_186A6E4 = 0;
  unk_186A6E8 = 0;
  unk_186A6EC = 0;
  unk_186A6F0 = 0;
  unk_186A6F4 = 0;
  unk_186A6F8 = 0;
  unk_186A6FC = 0;
  unk_186A700 = 0;
  unk_186A704 = 0;
  unk_186A708 = 0;
  unk_186A70C = 0;
  unk_186A710 = 0;
  unk_186A714 = 0;
  unk_186A718 = 0;
  unk_186A71C = 0;
  v17 = sub_8A9820();
  v2 = 0;
  v19 = sub_8A9B00();
  v20 = 0;
  if ( v19 > 0 )
  {
    do
    {
      v3 = MEMORY[0x1597730];
      sub_8AAE30(v2);
      v4 = sub_8A9AB0(v2);
      v21 = sub_8C1BB0(v4);
      sub_8C2340(1);
      v5 = sub_8C1B90();
      v6 = 0;
      dword_186A7A0[v4] = 0;
      if ( v5 > 0 )
      {
        while ( v21 != *(unsigned __int16 *)v3 )
        {
          ++v6;
          ++v3;
          if ( v6 >= v5 )
            goto LABEL_7;
        }
        dword_186A7A0[v4] = v6;
      }
LABEL_7:
      n7 = dword_186A7A0[v4];
      dword_186A760[v4] = 0;
      if ( n7 < 7
        || (v8 = n7 / 2 - 3, dword_186A760[v4] = v8, v9 = (v5 + 1) / 2, v8 + 7 >= v9)
        && (dword_186A760[v4] = v9 - 7, v9 - 7 < 0) )
      {
        dword_186A760[v4] = 0;
      }
      v2 = v20 + 1;
      v20 = v2;
    }
    while ( v2 < v19 );
  }
  sub_8AAE30(v17);
  sub_8C2340(0);
  v18 = sub_8BEE40(2);
  v19 = sub_8BEE40(3);
  v16 = sub_8BEE20(2);
  v17 = sub_8BEE20(3);
  v15 = FFX_Menu2D_ScaleY_1080to416(54.0);
  v14 = FFX_Menu2D_ScaleX_1920to512(1500.0);
  v13 = FFX_Menu2D_ScaleY_1080to416(155.0);
  v12 = FFX_Menu2D_ScaleX_1920to512(210.0);
  sub_8E4930(0, (int)&v18, (int)&v16, 2, 0, v12, v13, v14, v15);
  sub_8E4AB0();
  MenuSlotIndex = FFX_Party_GetMenuSlotIndex();
  sub_8D0D20(MenuSlotIndex);
  return sub_8E3B80(0);
}

// Function: sub_89D300
// Address: 0x89d300
char __cdecl sub_89D300(int a1)
{
  unsigned __int8 v1; // al
  __int16 v2; // di
  unsigned __int8 v3; // cl
  __int16 v4; // ax
  __int16 v5; // si
  int v6; // ecx
  __int16 v7; // si
  int sWithSelfOverride; // esi
  int i; // ecx
  int v10; // ecx
  int n0x1C; // eax
  char n32; // al
  __int16 v13; // [esp+Ch] [ebp-2Ch]
  __int16 v14; // [esp+10h] [ebp-28h]
  int n1073745920; // [esp+14h] [ebp-24h]
  _DWORD v16[7]; // [esp+18h] [ebp-20h]

  n1073745920 = 1073745920;
  v16[0] = 536903680;
  v16[1] = 268451840;
  v16[2] = 536903680;
  v16[3] = -2147475456;
  v16[4] = 1073745920;
  v16[5] = 536903680;
  v16[6] = 1073745920;
  v1 = sub_780DB0();
  v2 = unk_133D1C0;
  v3 = v1;
  v4 = unk_133D1BC;
  v5 = unk_133D1C0;
  v13 = unk_133D1BC;
  v6 = 2 * v3;
  v14 = unk_133D1C0;
  if ( (n4096 & v16[v6 - 1]) != 0 )
    v4 = --unk_133D1BC;
  if ( (n4096 & *(_WORD *)((_BYTE *)&n1073745920 + v6 * 4 + 2)) != 0 )
    unk_133D1BC = ++v4;
  if ( v4 < 0 )
  {
    v4 = word_133D1B6 - 1;
    unk_133D1BC = word_133D1B6 - 1;
  }
  if ( v4 >= word_133D1B6 )
  {
    v4 = 0;
    unk_133D1BC = 0;
  }
  if ( (((unsigned __int16)n32 & v16[v6]) != 0 || ((unsigned __int16)n32 & HIWORD(v16[v6])) != 0) && unk_133D1BE == 1 )
  {
    if ( unk_133D1C0 )
    {
      if ( word_133D13C[0] > 0 )
      {
        v7 = v4;
        word_133D1B6 = word_133D13C[0];
        src_0 = dst_1;
        v4 = sub_899060();
        v2 = 0;
        goto LABEL_17;
      }
    }
    else if ( word_133D190[0] > 0 )
    {
      v7 = v4;
      word_133D1B6 = word_133D190[0];
      src_0 = src;
      v4 = sub_899060();
      v2 = 1;
LABEL_17:
      unk_133D1C2 = v7;
      v5 = v14;
      unk_133D1C0 = v2;
      unk_133D1BC = v4;
    }
  }
  if ( v4 != v13 || v2 != v5 )
  {
    FFX_Btl_MenuDispatchSfx(1);
    v2 = unk_133D1C0;
    v4 = unk_133D1BC;
  }
  sWithSelfOverride = *(_DWORD *)(src_0 + 4 * v4);
  sWithSelfOverride_0 = sWithSelfOverride;
  if ( !n3_9 || n3_9 == 3 )
  {
    for ( i = 0; i < 28; ++i )
    {
      if ( ((1 << i) & sWithSelfOverride) != 0 )
        i_5 = i;
    }
  }
  else
  {
    i_5 = 255;
  }
  v10 = 240 * unk_23CC092[0];
  *(_WORD *)((char *)&unk_133C952 + v10) = v4;
  n0x1C = n0x1C;
  *(_DWORD *)((char *)&unk_133C9E8 + v10) = sWithSelfOverride;
  *(_WORD *)((char *)&unk_133C9E4 + v10) = v2;
  sub_792DF0(n0x1C, sWithSelfOverride);
  if ( unk_133D6A0 == 1 )
    n32 = 32;
  n32 = n32;
  if ( (n32 & 0x40) != 0 )
  {
    sub_792A60(*(__int16 *)(a1 + 8));
    FFX_Btl_MenuPopSubmenuEntry();
    return FFX_Btl_MenuDispatchSfx(4);
  }
  else if ( (n32 & 0x20) != 0 )
  {
    if ( sub_89A2A0(*(__int16 *)(a1 + 8), 12565) < 0 )
      return FFX_Btl_MenuDispatchSfx(3);
    else
      return FFX_Btl_MenuDispatchSfx(1);
  }
  return n32;
}

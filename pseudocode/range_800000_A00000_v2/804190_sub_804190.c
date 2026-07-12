// Function: sub_804190
// Address: 0x804190
int __cdecl sub_804190(int a1, int a2)
{
  int v2; // ebx
  int v3; // esi
  __int16 v4; // ax
  int n0x2000; // eax
  int v6; // esi
  char i; // al
  int v9; // esi
  unsigned __int8 v10; // cl
  char v11; // al
  int n3; // ebx
  _DWORD *v13; // eax
  int n8; // ecx
  unsigned __int8 *v15; // ecx
  int v16; // edi
  void *v17; // eax
  unsigned __int8 *v18; // ebx
  int v19; // edi
  __int64 v20; // [esp-3Ch] [ebp-70h]
  int v21; // [esp-20h] [ebp-54h]
  int v22; // [esp-10h] [ebp-44h]
  __int64 v23; // [esp+8h] [ebp-2Ch]
  _DWORD v24[3]; // [esp+1Ch] [ebp-18h] BYREF
  void *v25; // [esp+28h] [ebp-Ch]
  int v26; // [esp+2Ch] [ebp-8h]
  unsigned __int8 *v27; // [esp+30h] [ebp-4h]

  v2 = *(_DWORD *)(a1 + 544);
  v27 = (unsigned __int8 *)v2;
  v3 = LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]);
  v4 = *(_WORD *)(a1 + 538);
  v26 = v3;
  n0x2000 = v4 & 0xF000;
  if ( n0x2000 )
  {
    if ( n0x2000 == 4096 )
    {
      v9 = *(_DWORD *)(v2 + 168);
      sub_831380(v26, -1);
      sub_831250(v26, -1);
      sub_805430(v9, v27, a1 + 640, a1 + 704, *(__int16 *)(a1 + 530));
      sub_788BE0(1);
      v27[178] |= 1u;
      return a2 + 2;
    }
    else if ( n0x2000 == 0x2000 )
    {
      sub_831440(v3, -1, -1);
      sub_831410(v3, -1, -1);
      sub_645430(0, v2);
      v6 = *(char *)(v2 + 173);
      sub_687180(*(&unk_12F2064 + v6), v22);
      *(&unk_12F2064 + v6) = 0;
      for ( i = 1; v6 > 0; i *= 2 )
        --v6;
      *(_BYTE *)(a1 + 827) &= ~i;
      *(_BYTE *)(v2 + 178) &= ~1u;
      if ( !*(_BYTE *)(a1 + 827) )
        sub_788BE0(0);
      return a2 + 2;
    }
    else
    {
      return a2;
    }
  }
  else
  {
    v10 = *(_BYTE *)(a1 + 827);
    v11 = 1;
    n3 = 0;
    while ( (v10 & (unsigned __int8)v11) != 0 )
    {
      ++n3;
      v11 *= 2;
      if ( n3 >= 3 )
      {
        *(_BYTE *)(a1 + 528) = 1;
        return a2;
      }
    }
    *(_BYTE *)(a1 + 827) = v11 | v10;
    v25 = (void *)sub_687190(0x120000u, (void *)0x10);
    *(&unk_12F2064 + n3) = v25;
    sub_831440(v3, -1, 15360);
    sub_831410(v3, -1, 12000);
    FFX_BtlMenu_ResetActorModelCommandState(v3, 1u);
    sub_803280((int)&unk_1640830, v3, 0, *(_DWORD *)(a1 + 808));
    v13 = &unk_11A11C0;
    n8 = 0;
    while ( *v13 != v3 )
    {
      ++n8;
      v13 += 4;
      if ( n8 >= 8 )
        goto LABEL_20;
    }
    *v13 = 0;
LABEL_20:
    v15 = v27;
    v16 = a2 + *(__int16 *)(a2 + 2);
    v17 = v25;
    v27[173] = n3;
    *((_DWORD *)v15 + 42) = v17;
    sub_8061E0(a1, v15[24], *((float *)v15 + 15), v15 + 48, v15 + 144, *(char *)(a1 + 542));
    sub_835570(v26, 16, a1 + 64);
    v24[0] = a1;
    v18 = v27;
    v24[1] = a1 + 64;
    *(float *)&v24[2] = sub_794FC0(v27[24]);
    v21 = v16;
    v19 = (int)v25;
    sub_8058E0(&unk_1640830, v25, v21, v24);
    HIDWORD(v20) = v18;
    LODWORD(v20) = 0;
    if ( FFX_MagicCoreOp_ResolveChrMeshTexturePath(v20, v19, v26, 0x4000) )
    {
      HIDWORD(v23) = v18;
      LODWORD(v23) = 0;
      sub_645930(v23);
    }
    return a2 + 4;
  }
}

// Function: FFX_Magic_RunAuxRuntimeRootPass_structural
// Address: 0x80bea0
// [Jarvis naming goal 2026-06-17] Auxiliary/side runtime pass called from phase1 wrapper; xrefs include side-pass table and Virtuos opp_main warning path.
int __cdecl FFX_Magic_RunAuxRuntimeRootPass_structural(unsigned __int16 a1)
{
  int v1; // esi
  _DWORD *v2; // ebx
  int v3; // edi
  _BOOL2 v4; // ax
  __int16 i; // ax
  int v6; // edi
  char v7; // al
  void (__cdecl *v8)(int, _DWORD *); // eax
  int result; // eax
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+18h] [ebp+8h]

  if ( a1 == 1 )
    unk_113335C = 1;
  v1 = sub_7E6910(1024);
  v2 = (_DWORD *)dword_12A4080[a1];
  v3 = v2[8];
  *(_DWORD *)(v1 + 528) = word_C8F508[0];
  *(_DWORD *)(v1 + 532) = *(_DWORD *)&word_C8F50C;
  *(_DWORD *)(v1 + 536) = *(_DWORD *)&word_C8F510;
  *(_DWORD *)(v1 + 540) = *(_DWORD *)&word_C8F514;
  v10 = v3;
  v4 = (unk_2322780 & unk_2322781) != 0 || sub_82D860() == 0;
  *(_WORD *)(v1 + 530) = v4;
  if ( sub_780D80() )
    *(_BYTE *)(v1 + 542) = 1;
  unk_C8F52C = unk_113FCB4;
  unk_C8F530 = unk_113FCB8;
  unk_C8F534 = unk_113FCBC;
  n3_11 = n3_12;
  unk_C8F53C = unk_113FCC4;
  unk_C8F540 = unk_113FCC8;
  unk_C8F544 = unk_113FCCC;
  unk_C8F548 = unk_113FCD0;
  unk_C8F54C = unk_113FCD4;
  unk_C8F550 = unk_113FCD8;
  unk_C8F554 = unk_113FCDC;
  MEMORY[0xC8F558] = unk_113FCE0;
  unk_C8F55C = unk_113FCE4;
  unk_C8F560 = unk_113FCE8;
  unk_C8F564 = unk_113FCEC;
  *(_DWORD *)(v1 + 640) = unk_113FCB0;
  *(_DWORD *)(v1 + 644) = unk_C8F52C;
  *(_DWORD *)(v1 + 648) = unk_C8F530;
  *(_DWORD *)(v1 + 652) = unk_C8F534;
  *(_DWORD *)(v1 + 656) = n3_11;
  *(_DWORD *)(v1 + 660) = unk_C8F53C;
  *(_DWORD *)(v1 + 664) = unk_C8F540;
  *(_DWORD *)(v1 + 668) = unk_C8F544;
  *(_DWORD *)(v1 + 672) = unk_C8F548;
  *(_DWORD *)(v1 + 676) = unk_C8F54C;
  *(_DWORD *)(v1 + 680) = unk_C8F550;
  *(_DWORD *)(v1 + 684) = unk_C8F554;
  *(_DWORD *)(v1 + 688) = MEMORY[0xC8F558];
  *(_DWORD *)(v1 + 692) = unk_C8F55C;
  *(_DWORD *)(v1 + 696) = unk_C8F560;
  *(_DWORD *)(v1 + 700) = unk_C8F564;
  unk_C8F52C = unk_113FCF4;
  unk_C8F530 = unk_113FCF8;
  unk_C8F534 = unk_113FCFC;
  n3_11 = n3_13;
  unk_C8F53C = unk_113FD04;
  unk_C8F540 = unk_113FD08;
  unk_C8F544 = unk_113FD0C;
  unk_C8F548 = unk_113FD10;
  n1065353216 = n1065353216_0;
  unk_C8F54C = unk_113FD14;
  unk_C8F550 = unk_113FD18;
  unk_C8F554 = unk_113FD1C;
  MEMORY[0xC8F558] = unk_113FD20;
  unk_C8F55C = unk_113FD24;
  unk_C8F560 = unk_113FD28;
  unk_C8F564 = unk_113FD2C;
  *(_DWORD *)(v1 + 704) = n1065353216_0;
  *(_DWORD *)(v1 + 708) = unk_C8F52C;
  *(_DWORD *)(v1 + 712) = unk_C8F530;
  *(_DWORD *)(v1 + 716) = unk_C8F534;
  *(_DWORD *)(v1 + 720) = n3_11;
  *(_DWORD *)(v1 + 724) = unk_C8F53C;
  *(_DWORD *)(v1 + 728) = unk_C8F540;
  *(_DWORD *)(v1 + 732) = unk_C8F544;
  *(_DWORD *)(v1 + 736) = unk_C8F548;
  *(_DWORD *)(v1 + 740) = unk_C8F54C;
  *(_DWORD *)(v1 + 744) = unk_C8F550;
  *(_DWORD *)(v1 + 748) = unk_C8F554;
  *(_DWORD *)(v1 + 752) = MEMORY[0xC8F558];
  *(_DWORD *)(v1 + 756) = unk_C8F55C;
  *(_DWORD *)(v1 + 760) = unk_C8F560;
  *(_DWORD *)(v1 + 764) = unk_C8F564;
  v11 = v2[7];
  for ( i = *(_WORD *)(v11 + 2 * *(__int16 *)(v1 + 536)); i >= 0; i = *(_WORD *)(v11 + 2 * *(__int16 *)(v1 + 536)) )
  {
    *(_WORD *)(v1 + 532) = i;
    v6 = (i << 8) + v3;
    *(_DWORD *)(v1 + 544) = v6;
    if ( *(char *)(v6 + 25) < 0 )
    {
      unk_C8F52C = unk_113FD34;
      unk_C8F530 = unk_113FD38;
      unk_C8F534 = unk_113FD3C;
      n3_11 = n3_14;
      unk_C8F53C = unk_113FD44;
      unk_C8F540 = unk_113FD48;
      unk_C8F544 = unk_113FD4C;
      unk_C8F548 = unk_113FD50;
      unk_C8F54C = unk_113FD54;
      unk_C8F550 = unk_113FD58;
      unk_C8F554 = unk_113FD5C;
      MEMORY[0xC8F558] = unk_113FD60;
      unk_C8F55C = unk_113FD64;
      unk_C8F560 = unk_113FD68;
      unk_C8F564 = unk_113FD6C;
      n1065353216 = n1065353216_1;
      *(_DWORD *)(v1 + 704) = n1065353216_1;
      *(_DWORD *)(v1 + 708) = unk_C8F52C;
      *(_DWORD *)(v1 + 712) = unk_C8F530;
      *(_DWORD *)(v1 + 716) = unk_C8F534;
      *(_DWORD *)(v1 + 720) = n3_11;
      *(_DWORD *)(v1 + 724) = unk_C8F53C;
      *(_DWORD *)(v1 + 728) = unk_C8F540;
      *(_DWORD *)(v1 + 732) = unk_C8F544;
      *(_DWORD *)(v1 + 736) = unk_C8F548;
      *(_DWORD *)(v1 + 740) = unk_C8F54C;
      *(_DWORD *)(v1 + 744) = unk_C8F550;
      *(_DWORD *)(v1 + 748) = unk_C8F554;
      *(_DWORD *)(v1 + 752) = MEMORY[0xC8F558];
      *(_DWORD *)(v1 + 756) = unk_C8F55C;
      *(_DWORD *)(v1 + 760) = unk_C8F560;
      *(_DWORD *)(v1 + 764) = unk_C8F564;
    }
    v7 = *(_BYTE *)(v6 + 187);
    if ( v7 >= 0 )
    {
      v8 = (void (__cdecl *)(int, _DWORD *))g_FFX_MagicSidePassTable[(unsigned __int8)v7];
      if ( !v8 )
      {
        nullsub_34();
        goto LABEL_14;
      }
    }
    else
    {
      v8 = *(void (__cdecl **)(int, _DWORD *))(*(_DWORD *)(v2[20] + 120) + 4 * (v7 & 0x7F));
    }
    v8(v1, v2);
LABEL_14:
    ++*(_WORD *)(v1 + 536);
    if ( *(char *)(v6 + 25) < 0 )
    {
      unk_C8F52C = unk_113FCF4;
      unk_C8F530 = unk_113FCF8;
      unk_C8F534 = unk_113FCFC;
      n3_11 = n3_13;
      unk_C8F53C = unk_113FD04;
      unk_C8F540 = unk_113FD08;
      unk_C8F544 = unk_113FD0C;
      unk_C8F548 = unk_113FD10;
      unk_C8F54C = unk_113FD14;
      unk_C8F550 = unk_113FD18;
      unk_C8F554 = unk_113FD1C;
      MEMORY[0xC8F558] = unk_113FD20;
      unk_C8F55C = unk_113FD24;
      unk_C8F560 = unk_113FD28;
      unk_C8F564 = unk_113FD2C;
      n1065353216 = n1065353216_0;
      *(_DWORD *)(v1 + 704) = n1065353216_0;
      *(_DWORD *)(v1 + 708) = unk_C8F52C;
      *(_DWORD *)(v1 + 712) = unk_C8F530;
      *(_DWORD *)(v1 + 716) = unk_C8F534;
      *(_DWORD *)(v1 + 720) = n3_11;
      *(_DWORD *)(v1 + 724) = unk_C8F53C;
      *(_DWORD *)(v1 + 728) = unk_C8F540;
      *(_DWORD *)(v1 + 732) = unk_C8F544;
      *(_DWORD *)(v1 + 736) = unk_C8F548;
      *(_DWORD *)(v1 + 740) = unk_C8F54C;
      *(_DWORD *)(v1 + 744) = unk_C8F550;
      *(_DWORD *)(v1 + 748) = unk_C8F554;
      *(_DWORD *)(v1 + 752) = MEMORY[0xC8F558];
      *(_DWORD *)(v1 + 756) = unk_C8F55C;
      *(_DWORD *)(v1 + 760) = unk_C8F560;
      *(_DWORD *)(v1 + 764) = unk_C8F564;
    }
    v3 = v10;
  }
  result = sub_7E6970(1024);
  unk_113335C = 0;
  return result;
}

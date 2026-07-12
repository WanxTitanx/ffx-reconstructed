// Function: sub_80CA90
// Address: 0x80ca90
int __cdecl sub_80CA90(int a1, int a2)
{
  int v3; // ecx
  int v4; // esi
  int v5; // eax
  int v6; // edi
  __int16 v7; // dx
  unsigned int n20480; // eax
  int v9; // eax
  double v10; // st7
  __int16 v12; // [esp+Ch] [ebp-4h]
  int v13; // [esp+18h] [ebp+8h]
  float v14; // [esp+18h] [ebp+8h]

  v3 = *(_DWORD *)(a1 + 544);
  v4 = a2;
  v13 = v3;
  if ( (*(_WORD *)(a1 + 538) & 0x400) != 0 )
  {
    v4 = a2 + 2;
    v5 = sub_800F80((_DWORD *)(a1 + 768), v3, *(_WORD *)(a2 + 2));
    v3 = v13;
    v6 = v5;
  }
  else
  {
    v6 = v3;
  }
  v7 = *(_WORD *)(v4 + 2);
  v12 = *(_WORD *)(v4 + 4);
  n20480 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n20480 > 0x3000 )
  {
    if ( n20480 == 0x4000 )
    {
      v9 = HIBYTE(v7);
      v10 = *(float *)((unsigned __int8)v7 + v13);
    }
    else
    {
      if ( n20480 != 20480 )
        goto LABEL_19;
      v9 = (unsigned __int8)v7;
      v10 = -*(float *)((unsigned __int8)v7 + v3);
    }
    goto LABEL_17;
  }
  if ( n20480 == 12288 )
  {
    *(float *)((unsigned __int8)v7 + v13) = *(float *)(HIBYTE(v7) + v6);
  }
  else
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
    {
      v4 += 6;
      *(float *)(v7 + v6) = (float)v12;
      goto LABEL_19;
    }
    if ( n20480 != 4096 )
    {
      if ( n20480 != 0x2000 )
        goto LABEL_19;
      v9 = HIBYTE(v7);
      v14 = *(float *)((unsigned __int8)v7 + v6);
      *(float *)((unsigned __int8)v7 + v6) = *(float *)(HIBYTE(v7) + v6);
      v10 = v14;
LABEL_17:
      *(float *)(v9 + v6) = v10;
      goto LABEL_18;
    }
    *(float *)((unsigned __int8)v7 + v6) = *(float *)(HIBYTE(v7) + v6);
  }
LABEL_18:
  v4 += 4;
LABEL_19:
  if ( (*(_WORD *)(a1 + 538) & 0x200) != 0 )
    g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v6 + 186)](a1, v4);
  return v4;
}

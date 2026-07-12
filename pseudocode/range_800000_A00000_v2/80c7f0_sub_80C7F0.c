// Function: sub_80C7F0
// Address: 0x80c7f0
int __cdecl sub_80C7F0(int a1, unsigned __int8 *a2)
{
  unsigned __int8 *v2; // esi
  __int16 v4; // cx
  int v5; // eax
  int v6; // edx
  int v7; // ebx
  double v8; // st7
  int v9; // edx
  double v10; // st7
  int n12288; // ecx
  float *v12; // edx
  double v13; // st7
  int v14; // esi
  float v16; // [esp+14h] [ebp+8h]
  float v17; // [esp+18h] [ebp+Ch]

  v2 = a2;
  v4 = *(_WORD *)(a1 + 538);
  if ( (v4 & 0x400) != 0 )
  {
    v2 = a2 + 2;
    v5 = sub_800F80((_DWORD *)(a1 + 768), *(_DWORD *)(a1 + 544), *((_WORD *)a2 + 1));
    v4 = *(_WORD *)(a1 + 538);
    v6 = v5;
    if ( (_BYTE)v4 != 0xA9 )
    {
      v7 = *(_DWORD *)(a1 + 544);
      goto LABEL_6;
    }
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 544);
  }
  v7 = v6;
LABEL_6:
  if ( (v4 & 0x800) != 0 )
  {
    v16 = *(float *)(v2[3] + v7);
    v8 = *(float *)(v2[4] + v6);
    v9 = v2[2];
    v17 = v8;
  }
  else
  {
    v17 = (float)*((__int16 *)v2 + 1);
    v10 = *(float *)(v2[5] + v6);
    v9 = v2[4];
    v16 = v10;
  }
  n12288 = v4 & 0xF000;
  v12 = (float *)(v7 + v9);
  if ( n12288 > 0x2000 )
  {
    if ( n12288 != 12288 )
      goto LABEL_21;
    if ( 0.0 == v17 )
      v13 = 0.0;
    else
      v13 = v16 / v17;
  }
  else if ( n12288 == 0x2000 )
  {
    v13 = v17 * v16;
  }
  else if ( n12288 )
  {
    if ( n12288 != 4096 )
      goto LABEL_21;
    v13 = v16 - v17;
  }
  else
  {
    v13 = v17 + v16;
  }
  *v12 = v13;
LABEL_21:
  v14 = (int)(v2 + 6);
  if ( (*(_WORD *)(a1 + 538) & 0x200) != 0 )
    g_FFX_MagicPostProcTable[*(unsigned __int8 *)(v7 + 186)](a1, v14);
  return v14;
}

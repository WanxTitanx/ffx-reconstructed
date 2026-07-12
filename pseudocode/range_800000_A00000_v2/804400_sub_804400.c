// Function: sub_804400
// Address: 0x804400
int __cdecl sub_804400(int a1, int a2)
{
  int v2; // edi
  unsigned int n20480; // eax
  unsigned __int8 n0x20; // al
  int n32_2; // ebx
  float v8; // edi
  int v9; // esi
  int n32_1; // ebx
  float v11; // edi
  float v13; // ebx
  float v14; // esi
  int v15; // ebx
  float v16; // edi
  __int16 v17; // [esp+Ch] [ebp-4h]
  int n32; // [esp+18h] [ebp+8h]
  int v19; // [esp+1Ch] [ebp+Ch]
  int v20; // [esp+1Ch] [ebp+Ch]
  int v21; // [esp+1Ch] [ebp+Ch]

  v2 = *(_DWORD *)(a1 + 544);
  n20480 = *(_WORD *)(a1 + 538) & 0xF000;
  if ( n20480 > 0x3000 )
  {
    if ( n20480 != 0x4000 )
    {
      if ( n20480 != 20480 )
        return a2;
      v14 = flt_12A80C0[*(unsigned __int8 *)(v2 + 24)];
      sub_82B090(LODWORD(v14), 0);
      sub_824700(LODWORD(v14));
      return a2 + 2;
    }
    v9 = a2;
    v15 = *(unsigned __int16 *)(a2 + 2) + (*(unsigned __int16 *)(a2 + 4) << 16);
    v16 = flt_12A80C0[*(unsigned __int8 *)(v2 + 24)];
    if ( !sub_780D80() && v16 != 0.0 )
    {
      sub_82B100(LODWORD(v16));
      sub_837B40(LODWORD(v16), v15);
      sub_836B70(LODWORD(v16));
    }
    return v9 + 6;
  }
  if ( n20480 == 12288 )
  {
    v17 = *(_WORD *)(a2 + 4);
    v21 = *(unsigned __int16 *)(a2 + 2);
    n32 = *(unsigned __int8 *)(v2 + 24);
    v13 = flt_12A80C0[n32];
    if ( sub_780D80() )
    {
      if ( n32 >= 32 )
      {
        if ( v13 == 0.0 )
        {
          *(float *)(v17 + v2) = (float)v21;
        }
        else
        {
          sub_82B100(LODWORD(v13));
          sub_837D80(LODWORD(v13), 1, v21);
          *(float *)(v17 + v2) = (float)(int)sub_836B70(LODWORD(v13));
        }
        return a2 + 6;
      }
      else
      {
        *(float *)(v17 + v2) = (float)(int)sub_788380(n32, v21);
        return a2 + 6;
      }
    }
    else
    {
      *(float *)(v17 + v2) = (float)0;
      return a2 + 6;
    }
  }
  if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
  {
    v9 = a2;
    n32_1 = *(unsigned __int8 *)(v2 + 24);
    v11 = flt_12A80C0[n32_1];
    v20 = *(unsigned __int16 *)(a2 + 4);
    if ( sub_780D80() )
    {
      if ( n32_1 < 32 )
      {
        sub_788380(n32_1, v20);
        return v9 + 6;
      }
      if ( v11 != 0.0 )
      {
        sub_82B100(LODWORD(v11));
        sub_837D80(LODWORD(v11), 1, v20);
        sub_836B70(LODWORD(v11));
        return v9 + 6;
      }
    }
    return v9 + 6;
  }
  if ( n20480 != 4096 )
  {
    if ( n20480 != 0x2000 )
      return a2;
    if ( *(_BYTE *)(a1 + 542) )
    {
      n0x20 = *(_BYTE *)(v2 + 24);
      if ( n0x20 < 0x20u )
      {
        if ( sub_787960(n0x20) )
          return a2 + 2;
        goto LABEL_11;
      }
    }
    if ( sub_839340(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)])) )
    {
LABEL_11:
      *(_BYTE *)(a1 + 528) = 1;
      return a2;
    }
    return a2 + 2;
  }
  n32_2 = *(unsigned __int8 *)(v2 + 24);
  v8 = flt_12A80C0[n32_2];
  v19 = *(unsigned __int16 *)(a2 + 2);
  if ( sub_780D80() )
  {
    if ( n32_2 < 32 )
    {
      sub_788380(n32_2, v19);
      return a2 + 4;
    }
    if ( v8 != 0.0 )
    {
      sub_82B100(LODWORD(v8));
      sub_837D80(LODWORD(v8), 1, v19);
      sub_836B70(LODWORD(v8));
    }
  }
  return a2 + 4;
}

// Function: sub_819220
// Address: 0x819220
int __cdecl sub_819220(int a1, float a2)
{
  int v2; // edi
  unsigned int n45056; // eax
  char *v4; // ebx
  double v5; // st7
  int v8; // eax
  float v9; // esi
  int v10; // eax
  int v12; // ecx
  float v13; // [esp+1Ch] [ebp-18h]
  float v14; // [esp+3Ch] [ebp+8h]
  float v15; // [esp+40h] [ebp+Ch]
  float v16; // [esp+40h] [ebp+Ch]

  v2 = *(_DWORD *)(a1 + 544);
  n45056 = *(_WORD *)(a1 + 538) & 0xF000;
  v4 = (char *)&unk_12A40C0 + 32 * *(unsigned __int16 *)(v2 + 20);
  if ( n45056 > 0x6000 )
  {
    if ( (*(_WORD *)(a1 + 538) & 0xF000u) <= 0x9000 )
    {
      switch ( n45056 )
      {
        case 0x9000u:
          v9 = a2;
          if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
            sub_795EC0((unsigned __int8)v4[24], 1, 0, v4[16], 0, (int)a2);
          else
            sub_795EC0((unsigned __int8)v4[24], 1, 0, v4[16], 0, *(__int16 *)(LODWORD(a2) + 2));
          break;
        case 0x7000u:
          v16 = (double)*(__int16 *)(LODWORD(a2) + 4) * 0.0625;
          if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
            v12 = (int)*(float *)(*(__int16 *)(LODWORD(a2) + 2) + v2);
          else
            v12 = *(__int16 *)(LODWORD(a2) + 2);
          sub_7AB560((unsigned __int8)v4[24], 1, v4[24], 0.0, v12, 0, 0, v16, 1.0, 0.0, 0.0);
          return LODWORD(a2) + 6;
        case 0x8000u:
          v9 = a2;
          v10 = *(__int16 *)(LODWORD(a2) + 2);
          if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
            v10 = (int)*(float *)(v10 + v2);
          sub_795EC0((unsigned __int8)v4[24], 2, 0, v4[16], 0, v10);
          break;
        default:
          return LODWORD(a2);
      }
      return LODWORD(v9) + 4;
    }
    if ( n45056 != 40960 )
    {
      if ( n45056 == 45056 )
      {
        sub_7AB010(*(_DWORD *)v4);
        return LODWORD(a2) + 2;
      }
      return LODWORD(a2);
    }
    sub_7961E0(*(unsigned __int8 *)(v2 + 24), v2 + 144);
    return LODWORD(a2) + 2;
  }
  else if ( n45056 == 24576 )
  {
    v8 = *(__int16 *)(LODWORD(a2) + 2);
    v15 = (double)*(__int16 *)(LODWORD(a2) + 4) * 0.0625;
    if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
      v8 = (int)*(float *)(v8 + v2);
    sub_7AB560((unsigned __int8)v4[24], 2, v4[16], 0.0, v8, 0, 0, v15, 1.0, 0.0, 0.0);
    return LODWORD(a2) + 6;
  }
  else if ( (*(_WORD *)(a1 + 538) & 0xF000u) > 0x3000 )
  {
    if ( n45056 != 0x4000 )
    {
      if ( n45056 == 20480 )
      {
        sub_7948F0(*(unsigned __int8 *)(v2 + 24), a1);
        sub_81B3C0(*(unsigned __int8 *)(v2 + 24), a1);
        v14 = sub_7948B0(*(unsigned __int8 *)(v2 + 24));
        sub_81B380(*(unsigned __int8 *)(v2 + 24), v14);
        return LODWORD(a2) + 2;
      }
      return LODWORD(a2);
    }
    if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
      sub_796120((unsigned __int8)v4[24], 0);
    else
      sub_796120(*(unsigned __int8 *)(v2 + 24), 0);
    return LODWORD(a2) + 2;
  }
  else
  {
    if ( n45056 != 12288 )
    {
      if ( (*(_WORD *)(a1 + 538) & 0xF000) == 0 )
      {
        sub_81B3C0(*(unsigned __int8 *)(v2 + 24), v2 + 144);
        return LODWORD(a2) + 2;
      }
      if ( n45056 == 0x2000 )
      {
        v5 = *(float *)(v2 + 52);
        sub_81B340(*(float *)(v2 + 52));
        v13 = v5;
        sub_81B380(*(unsigned __int8 *)(v2 + 24), v13);
        return LODWORD(a2) + 2;
      }
      return LODWORD(a2);
    }
    if ( (*(_WORD *)(a1 + 538) & 0x800) != 0 )
      sub_796120((unsigned __int8)v4[24], 1);
    else
      sub_796120(*(unsigned __int8 *)(v2 + 24), 1);
    return LODWORD(a2) + 2;
  }
}

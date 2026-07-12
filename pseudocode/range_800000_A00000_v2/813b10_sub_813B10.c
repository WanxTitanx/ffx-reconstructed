// Function: sub_813B10
// Address: 0x813b10
int __cdecl sub_813B10(int a1, int a2)
{
  int v2; // ebx
  double n8_3; // st7
  unsigned __int16 n8; // cx
  int v5; // eax
  int result; // eax
  unsigned __int8 n0x14; // al
  int v8; // esi
  unsigned __int8 n8_1; // al
  unsigned __int8 n8_2; // al
  __int16 v11; // [esp-Ch] [ebp-1Ch]

  v2 = *(_DWORD *)(a1 + 544);
  switch ( *(unsigned __int16 *)(a1 + 538) >> 12 )
  {
    case 0:
      n8_3 = *(float *)(v2 + 64);
      *(_BYTE *)(v2 + 187) = *(_BYTE *)(a2 + 2);
      n8 = (int)n8_3;
      if ( !n8 )
        n8 = 8;
      *(_WORD *)(v2 + 208) = n8;
      *(_WORD *)(v2 + 210) = *(_WORD *)(a2 + 4);
      *(_WORD *)(v2 + 212) = *(_WORD *)(a2 + 6);
      v5 = sub_7FF6A0(*(_DWORD *)(a1 + 936), (n8 << 9) + 288);
      v11 = *(_WORD *)(v2 + 208);
      *(_DWORD *)(v2 + 188) = v5;
      sub_813AB0(v5, 8, 16, v11);
      sub_800C80(a1 + 768, *(_WORD *)(a1 + 532));
      result = a2 + 8;
      break;
    case 1:
      if ( !*(_WORD *)(a1 + 530) )
      {
        n0x14 = *(_BYTE *)(v2 + 24);
        v8 = n0x14 >= 0x14u ? LODWORD(flt_12A80C0[n0x14]) : sub_795B50(n0x14, 0);
        if ( v8 )
        {
          sub_834000(v8, a1);
          sub_805350((_DWORD *)(a1 + 64), v8, *(unsigned __int16 *)(v2 + 210));
          sub_805350((_DWORD *)(a1 + 160), v8, *(unsigned __int16 *)(v2 + 212));
          sub_7E82C0(a1 + 64, a1, a1 + 64);
          sub_7E82C0(a1 + 160, a1, a1 + 160);
          sub_8135E0(*(_DWORD *)(v2 + 188), a1 + 112, a1 + 208);
        }
      }
      result = a2 + 2;
      break;
    case 2:
      *(_DWORD *)(v2 + 168) = sub_7FC8D0(LODWORD(flt_12A80C0[*(unsigned __int8 *)(v2 + 24)]));
      if ( *(_DWORD *)(a1 + 804) == dword_12A4080[0] )
        ++*(_WORD *)(a1 + 824);
      result = a2 + 18;
      break;
    case 3:
      sub_7FC960(*(_DWORD *)(v2 + 168));
      result = a2 + 2;
      break;
    case 4:
      n8_1 = *(_BYTE *)(v2 + 24);
      if ( n8_1 < 8u )
        sub_793F20(n8_1, 0);
      goto LABEL_18;
    case 5:
      n8_2 = *(_BYTE *)(v2 + 24);
      if ( n8_2 < 8u )
        sub_793F20(n8_2, 1);
LABEL_18:
      result = a2 + 2;
      break;
    case 6:
      sub_7962C0(*(unsigned __int8 *)(v2 + 24), 2);
      result = a2 + 2;
      break;
    case 7:
      sub_7962C0(*(unsigned __int8 *)(v2 + 24), 0);
      result = a2 + 2;
      break;
    default:
      result = a2;
      break;
  }
  return result;
}

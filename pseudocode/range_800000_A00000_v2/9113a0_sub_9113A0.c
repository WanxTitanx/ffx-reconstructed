// Function: sub_9113A0
// Address: 0x9113a0
int __cdecl sub_9113A0(int a1, _DWORD *a2, unsigned int a3)
{
  _DWORD *v3; // ebx
  _DWORD *v4; // esi
  _DWORD *v5; // ecx
  int n96; // edx
  char n96_1; // al
  int v8; // eax
  int v9; // ecx
  int v10; // ecx
  int v12; // edx

  v3 = a2;
  v4 = a2;
  if ( a3 )
  {
    while ( 2 )
    {
      v5 = (_DWORD *)*v4;
      n96 = HIBYTE(*v4) & 0x7F;
      n96_1 = HIBYTE(*v4++) & 0x60;
      a2 = v5;
      if ( n96_1 == 96 )
        n96 = 96;
      switch ( n96 )
      {
        case 1:
          *(_BYTE *)(a1 + 16516) = BYTE1(v5);
          *(_BYTE *)(a1 + 16517) = (_BYTE)v5;
          goto LABEL_18;
        case 2:
          v8 = *(_DWORD *)(a1 + 16500);
          *(_DWORD *)(a1 + 0x4000) &= ~0x80u;
          *(_DWORD *)(a1 + 16504) = (unsigned __int16)v5 & 0x3FF;
          *(_DWORD *)(a1 + 16496) = v8;
          goto LABEL_18;
        case 3:
          v9 = (unsigned __int16)v5 & 0x3FF;
          *(_DWORD *)(a1 + 0x4000) &= ~0x80u;
          *(_DWORD *)(a1 + 16500) = v9;
          *(_DWORD *)(a1 + 16496) = v9;
          goto LABEL_18;
        case 4:
          *(_DWORD *)(a1 + 16496) = (unsigned __int16)v5 & 0x3FF;
          goto LABEL_18;
        case 5:
          *(_DWORD *)(a1 + 16508) = (unsigned __int8)v5 & 3;
          goto LABEL_18;
        case 7:
          *(_DWORD *)(a1 + 16512) = (unsigned __int16)v5;
          goto LABEL_18;
        case 20:
        case 21:
        case 23:
          v12 = *(_DWORD *)(a1 + 0x4000);
          *(_DWORD *)(a1 + 16492) = *(_DWORD *)(a1 + 16496);
          if ( (v12 & 0x80u) != 0 )
          {
            *(_DWORD *)(a1 + 16496) = *(_DWORD *)(a1 + 16500);
            *(_DWORD *)(a1 + 0x4000) = v12 & 0xFFFFFF7F;
            return v4 - v3;
          }
          *(_DWORD *)(a1 + 16496) = *(_DWORD *)(a1 + 16500) + *(_DWORD *)(a1 + 16504);
          *(_DWORD *)(a1 + 0x4000) = v12 | 0x80;
          break;
        case 32:
          *(_DWORD *)(a1 + 16488) = *v4++;
          goto LABEL_18;
        case 48:
          *(_DWORD *)(a1 + 16456) = *v4;
          *(_DWORD *)(a1 + 16460) = v4[1];
          *(_DWORD *)(a1 + 16464) = v4[2];
          *(_DWORD *)(a1 + 16468) = v4[3];
          v4 += 4;
          goto LABEL_18;
        case 49:
          *(_DWORD *)(a1 + 16472) = *v4;
          *(_DWORD *)(a1 + 16476) = v4[1];
          *(_DWORD *)(a1 + 16480) = v4[2];
          *(_DWORD *)(a1 + 16484) = v4[3];
          v4 += 4;
          goto LABEL_18;
        case 74:
          v10 = BYTE2(v5);
          if ( v10 )
            v4 += 2 * v10;
          goto LABEL_18;
        case 80:
        case 81:
          v4 += 4 * (unsigned __int16)v5;
          goto LABEL_18;
        case 96:
          v4 += sub_911620(a1, v4, &a2);
          goto LABEL_18;
        default:
LABEL_18:
          if ( v4 - v3 < a3 )
            continue;
          return v4 - v3;
      }
      break;
    }
  }
  return v4 - v3;
}

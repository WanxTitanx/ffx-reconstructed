// Function: sub_911620
// Address: 0x911620
int __cdecl sub_911620(int a1, unsigned int *a2, unsigned int a3)
{
  unsigned int *v3; // eax
  int v4; // esi
  int v5; // edi
  unsigned int v6; // ebx
  int v7; // ecx
  _DWORD *v8; // edi
  _DWORD *v9; // edx
  int v10; // esi
  int v11; // ecx
  int result; // eax
  unsigned int v13; // esi
  unsigned int *v14; // edx
  unsigned int v15; // ecx
  int n16; // edx
  int v17; // ecx
  unsigned int v18; // esi
  _DWORD *v19; // edi
  _DWORD *v20; // ebx
  unsigned int v21; // ebx
  _DWORD *v22; // esi
  unsigned int v23; // edi
  int n24; // edx
  unsigned int v25; // ebx
  _DWORD *v26; // edi
  _DWORD *v27; // esi
  unsigned int v28; // ebx
  _DWORD *v29; // esi
  unsigned int v30; // edi
  unsigned int v31; // ebx
  int n16_1; // esi
  int *v33; // edi
  unsigned int v34; // edx
  int v35; // [esp+Ch] [ebp-Ch]
  int v36; // [esp+10h] [ebp-8h]
  unsigned int v37; // [esp+10h] [ebp-8h]
  int v38; // [esp+10h] [ebp-8h]
  int v39; // [esp+14h] [ebp-4h]
  unsigned int v40; // [esp+14h] [ebp-4h]

  v3 = a2;
  v4 = ((unsigned __int8)(HIBYTE(*(_DWORD *)a3) & 0x7F) >> 2) & 3;
  v5 = *(_DWORD *)a3 & 0x3FF;
  if ( (*(_DWORD *)a3 & 0x8000) != 0 )
    v5 += *(_DWORD *)(a1 + 16496);
  switch ( HIBYTE(*(_DWORD *)a3) & 3 )
  {
    case 0:
      if ( v4 )
      {
        if ( (unsigned int)(v4 - 1) > 2 )
          goto LABEL_58;
        v6 = 0;
        if ( !*(_BYTE *)(a3 + 2) )
          goto LABEL_58;
        v7 = v4 + 1;
        v36 = v4 + 1;
        v8 = (_DWORD *)(a1 + 16 * v5);
        do
        {
          v9 = v8;
          v10 = v7;
          do
          {
            v11 = *v3++;
            *v9++ = v11;
            --v10;
          }
          while ( v10 );
          ++v6;
          v8 += 4;
          v7 = v36;
        }
        while ( v6 < *(unsigned __int8 *)(a3 + 2) );
        result = v3 - a2;
      }
      else
      {
        v13 = 0;
        if ( !*(_BYTE *)(a3 + 2) )
          goto LABEL_58;
        v14 = (unsigned int *)(16 * v5 + a1 + 8);
        do
        {
          v15 = *v3;
          *(v14 - 2) = *v3;
          *(v14 - 1) = v15;
          *v14 = v15;
          v14[1] = v15;
          ++v13;
          ++v3;
          v14 += 4;
        }
        while ( v13 < *(unsigned __int8 *)(a3 + 2) );
        result = v3 - a2;
      }
      break;
    case 1:
      n16 = 0;
      if ( v4 )
      {
        if ( (unsigned int)(v4 - 1) > 2 )
          goto LABEL_58;
        v37 = 0;
        if ( !*(_BYTE *)(a3 + 2) )
          goto LABEL_58;
        v17 = v4 + 1;
        v18 = a3;
        v19 = (_DWORD *)(a1 + 16 * v5);
        do
        {
          v20 = v19;
          v39 = v17;
          do
          {
            if ( n16 )
            {
              v18 >>= 16;
              n16 -= 16;
            }
            else
            {
              v18 = *v3++;
              n16 = 16;
            }
            *v20++ = (unsigned __int16)v18;
            --v39;
          }
          while ( v39 );
          v19 += 4;
          ++v37;
        }
        while ( v37 < *(unsigned __int8 *)(a3 + 2) );
        result = v3 - a2;
      }
      else
      {
        v21 = 0;
        if ( !*(_BYTE *)(a3 + 2) )
          goto LABEL_58;
        v22 = (_DWORD *)(16 * v5 + a1 + 8);
        v23 = a3;
        do
        {
          if ( n16 )
          {
            v23 >>= 16;
            n16 -= 16;
          }
          else
          {
            v23 = *v3++;
            n16 = 16;
          }
          *(v22 - 2) = (unsigned __int16)v23;
          *(v22 - 1) = (unsigned __int16)v23;
          *v22 = (unsigned __int16)v23;
          v22[1] = (unsigned __int16)v23;
          ++v21;
          v22 += 4;
        }
        while ( v21 < *(unsigned __int8 *)(a3 + 2) );
        result = v3 - a2;
      }
      break;
    case 2:
      n24 = 0;
      if ( v4 )
      {
        if ( (unsigned int)(v4 - 1) > 2 )
          goto LABEL_58;
        v40 = 0;
        if ( !*(_BYTE *)(a3 + 2) )
          goto LABEL_58;
        v25 = a3;
        v26 = (_DWORD *)(a1 + 16 * v5);
        v35 = v4 + 1;
        do
        {
          v27 = v26;
          v38 = v35;
          do
          {
            if ( n24 )
            {
              v25 >>= 8;
              n24 -= 8;
            }
            else
            {
              v25 = *v3++;
              n24 = 24;
            }
            *v27++ = (unsigned __int8)v25;
            --v38;
          }
          while ( v38 );
          v26 += 4;
          ++v40;
        }
        while ( v40 < *(unsigned __int8 *)(a3 + 2) );
        result = v3 - a2;
      }
      else
      {
        v28 = 0;
        if ( !*(_BYTE *)(a3 + 2) )
          goto LABEL_58;
        v29 = (_DWORD *)(16 * v5 + a1 + 8);
        v30 = a3;
        do
        {
          if ( n24 )
          {
            v30 >>= 8;
            n24 -= 8;
          }
          else
          {
            v30 = *v3++;
            n24 = 24;
          }
          *(v29 - 2) = (unsigned __int8)v30;
          *(v29 - 1) = (unsigned __int8)v30;
          *v29 = (unsigned __int8)v30;
          v29[1] = (unsigned __int8)v30;
          ++v28;
          v29 += 4;
        }
        while ( v28 < *(unsigned __int8 *)(a3 + 2) );
        result = v3 - a2;
      }
      break;
    case 3:
      v31 = 0;
      n16_1 = 0;
      if ( *(_BYTE *)(a3 + 2) )
      {
        v33 = (int *)(a1 + 8 + 16 * v5);
        v34 = a3;
        do
        {
          if ( n16_1 )
          {
            v34 >>= 16;
            n16_1 -= 16;
          }
          else
          {
            v34 = *v3++;
            n16_1 = 16;
          }
          *(v33 - 2) = 8 * (v34 & 0x1F);
          *(v33 - 1) = (v34 >> 2) & 0xF8;
          *v33 = (v34 >> 7) & 0xF8;
          v33[1] = (v34 >> 8) & 0x80;
          ++v31;
          v33 += 4;
        }
        while ( v31 < *(unsigned __int8 *)(a3 + 2) );
      }
      goto LABEL_58;
    default:
LABEL_58:
      result = v3 - a2;
      break;
  }
  return result;
}

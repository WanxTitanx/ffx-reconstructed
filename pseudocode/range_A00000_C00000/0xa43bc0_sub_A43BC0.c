// Function: sub_A43BC0
// Address: 0xa43bc0
// Size: 0xdc
// Prototype: 

_BYTE *__cdecl sub_A43BC0(int a1, unsigned __int8 *a2, _DWORD *a3)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // esi
  int n126; // ebx
  int v7; // ecx
  int v8; // edx
  int v9; // ebx
  int v10; // ecx
  unsigned __int8 *v11; // edi
  unsigned __int8 *v12; // edi
  int v13; // edx
  int v14; // ecx
  int v15; // ecx
  int v16; // edx
  unsigned __int8 v17; // cl
  _BYTE *result; // eax
  int v19; // [esp+Ch] [ebp-4h]
  unsigned __int8 *v20; // [esp+18h] [ebp+8h]
  unsigned int v21; // [esp+1Ch] [ebp+Ch]

  v3 = a2;
  v4 = a2;
  v5 = (unsigned __int8 *)(a1 + 5);
  v21 = (unsigned int)(a2 + 2047);
  v20 = v4;
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
        n126 = *v5++;
        if ( (n126 & 0x80u) == 0 )
          break;
        v7 = *v5;
        v8 = ((n126 >> 3) & 0xF) + 3;
        ++v5;
        v9 = (v7 | ((n126 & 7) << 8)) + 1;
        if ( (unsigned int)v3 >= v21 )
        {
          v12 = &v3[-v9];
          do
          {
            *v3++ = *v12++;
            --v8;
          }
          while ( v8 );
        }
        else
        {
          v10 = (int)&v4[v9];
          v19 = (int)&v4[v9];
          v11 = &v3[-v9];
          while ( 1 )
          {
            while ( (int)v3 < v10 )
            {
              *v3++ = 0;
              ++v11;
              if ( !--v8 )
                goto LABEL_2;
            }
            *v3++ = *v11++;
            if ( !--v8 )
              break;
            v10 = v19;
          }
        }
LABEL_2:
        v4 = v20;
      }
      if ( n126 - 126 < 0 )
        break;
      v13 = v5[1];
      v14 = *v5;
      if ( n126 == 126 )
      {
        v15 = v14 + 4;
        do
        {
          *v3++ = v13;
          --v15;
        }
        while ( v15 );
        v5 += 2;
      }
      else
      {
        v16 = v14 | (v13 << 8);
        v17 = v5[2];
        do
        {
          *v3++ = v17;
          --v16;
        }
        while ( v16 );
        v5 += 3;
      }
    }
    if ( !n126 )
      break;
    do
    {
      *v3++ = *v5++;
      --n126;
    }
    while ( n126 );
  }
  result = (_BYTE *)(v3 - v4);
  *a3 = result;
  return result;
}


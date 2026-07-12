// Function: sub_A7B510
// Address: 0xa7b510
// Size: 0x25e
// Prototype: _DWORD __cdecl(int n15a, int *, _DWORD *, int, int)

int __cdecl sub_A7B510(int n15a, int *a2, int *a3, int a4, int a5)
{
  __int16 v6; // dx
  int v7; // edi
  _WORD *v8; // ebx
  unsigned __int16 v9; // dx
  int v11; // ecx
  int v12; // eax
  __int16 v13; // ax
  __int16 v14; // ax
  int v15; // eax
  __int16 v16; // dx
  __int16 v17; // ax
  __int16 v18; // ax
  int v19; // eax
  int v20; // [esp-8h] [ebp-20h]
  int v21; // [esp+Ch] [ebp-Ch]
  _DWORD *v22; // [esp+10h] [ebp-8h]
  int v23; // [esp+14h] [ebp-4h]
  int v24; // [esp+28h] [ebp+10h]
  int v25; // [esp+2Ch] [ebp+14h]

  v6 = *((_WORD *)a3 + 2);
  v21 = *a3 & 0x3FFFFFFF;
  v22 = (_DWORD *)(a4 + 4 * *a3);
  v7 = 1;
  v25 = n15a + *v22;
  v8 = (_WORD *)(v25 + 2 * *((unsigned __int16 *)a3 + 4));
  v24 = 1;
  v23 = 1;
  if ( v6 )
  {
    v20 = *((__int16 *)a3 + 3);
    v9 = v6 - 1;
    *((_WORD *)a3 + 2) = v9;
    sub_A7B290(v25, (int)a3, v9, v20, a5);
    return 1;
  }
  else
  {
    do
    {
      v11 = *v8 & 0x7FF;
      switch ( *v8 & 0x7FF )
      {
        case 0:
          *((_WORD *)a3 + 2) = 0;
          *((_WORD *)a3 + 3) = -1;
          *a3 = v21;
          v23 = 0;
          goto LABEL_33;
        case 1:
          v8 += (unsigned __int8)byte_C89C41;
          *((_WORD *)a3 + 5) = *((_WORD *)a3 + 4);
          v14 = (unsigned __int8)byte_C89C41;
          goto LABEL_29;
        case 2:
          *((_WORD *)a3 + 2) = 0;
          *((_WORD *)a3 + 3) = -1;
          if ( *((__int16 *)a3 + 6) >= 0 )
            goto LABEL_11;
          v12 = 0;
          if ( *a2 <= 0 )
            goto LABEL_10;
          break;
        case 3:
          v15 = (unsigned __int16)v8[1];
          *((_WORD *)a3 + 2) = v15;
          *((_WORD *)a3 + 3) = -1;
          if ( v15 )
          {
            v7 = 0;
            v24 = 0;
            *((_WORD *)a3 + 2) = v15 - 1;
          }
          v8 += (unsigned __int8)byte_C89C43;
          *((_WORD *)a3 + 5) = *((_WORD *)a3 + 4);
          v14 = (unsigned __int8)byte_C89C43;
          goto LABEL_29;
        case 4:
        case 5:
        case 6:
        case 7:
        case 0xA:
          v16 = v8[1];
          v8 += (unsigned __int8)byte_C89C40[v11];
          *((_WORD *)a3 + 5) = *((_WORD *)a3 + 4);
          *((_WORD *)a3 + 4) += (unsigned __int8)byte_C89C40[v11];
          *((_WORD *)a3 + 2) = v16;
          *((_WORD *)a3 + 3) = v16;
          if ( !v16 )
            continue;
          *((_WORD *)a3 + 2) = v16 - 1;
          goto LABEL_33;
        case 8:
          if ( (*v8 & 0x800) != 0 )
          {
            v18 = 1;
          }
          else
          {
            v17 = *((_WORD *)a3 + 8);
            if ( v17 > 0 )
              v18 = v17 - 1;
            else
              v18 = v8[1];
          }
          *((_WORD *)a3 + 8) = v18;
          if ( v18 <= 0 )
          {
            v8 += (unsigned __int8)byte_C89C48;
            *((_WORD *)a3 + 4) += (unsigned __int8)byte_C89C48;
            *((_WORD *)a3 + 8) = 0;
          }
          else
          {
            v19 = *((unsigned __int16 *)a3 + 7);
            *((_WORD *)a3 + 4) = v19;
            v8 = (_WORD *)(*v22 + n15a + 2 * v19);
          }
          continue;
        case 9:
          v8 += (unsigned __int8)byte_C89C49;
          *((_WORD *)a3 + 4) += (unsigned __int8)byte_C89C49;
          *((_WORD *)a3 + 7) = *((_WORD *)a3 + 4);
          continue;
        default:
          continue;
      }
      while ( (__int16)v8[1] != (a2[1] & 0x3FFFFFFF) )
      {
        if ( ++v12 >= *a2 )
          goto LABEL_10;
      }
      *((_WORD *)a3 + 6) = v12;
LABEL_10:
      v7 = v24;
LABEL_11:
      v13 = *((_WORD *)a3 + 6);
      if ( v13 >= 0 && a2[5 * v13 + 1] < 0 )
        break;
      *((_WORD *)a3 + 6) = -1;
      *((_WORD *)a3 + 3) = 0;
      v8 += (unsigned __int8)byte_C89C42;
      v14 = (unsigned __int8)byte_C89C42;
LABEL_29:
      *((_WORD *)a3 + 4) += v14;
    }
    while ( v7 );
LABEL_33:
    sub_A7B290(v25, (int)a3, *((unsigned __int16 *)a3 + 2), *((__int16 *)a3 + 3), a5);
    return v23;
  }
}


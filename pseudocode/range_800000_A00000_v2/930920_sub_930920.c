// Function: sub_930920
// Address: 0x930920
int __cdecl sub_930920(int *a1)
{
  bool v3; // zf
  int v4; // edi
  int n256; // esi
  __int16 v6; // dx
  unsigned __int8 v7; // bl
  int v8; // edi
  __int16 v9; // si
  __int16 v10; // ax
  int v12; // [esp+0h] [ebp-4h]
  int v13; // [esp+Ch] [ebp+8h]

  if ( !a1[2] )
    return 0;
  v3 = (*(_BYTE *)a1 & 1) == 0;
  v4 = a1[3] + 4 * *((__int16 *)a1 + 3);
  v13 = v4;
  if ( v3 )
  {
    a1[6] += a1[5];
    n256 = a1[6];
    if ( n256 >= 256 )
    {
      *((_WORD *)a1 + 2) += n256 / 256;
      v6 = *((_WORD *)a1 + 2);
      a1[6] = n256 % 256;
      v7 = *(_BYTE *)(v4 + 1);
      if ( v6 > v7 )
      {
        v8 = *a1;
        v12 = *a1 & 2;
        v9 = v6;
        while ( 1 )
        {
          v9 += -1 - v7;
          *((_WORD *)a1 + 2) = v9;
          if ( v12 )
            break;
          if ( (__int16)++*((_WORD *)a1 + 3) >= a1[2] )
          {
            if ( (v8 & 0xF00) == 0 )
              goto LABEL_19;
            if ( (v8 & 0xF00) == 0x100 )
              goto LABEL_11;
          }
LABEL_13:
          v7 = *(_BYTE *)(v13 + 1);
          if ( v9 <= v7 )
            return v13;
        }
        if ( (__int16)--*((_WORD *)a1 + 3) >= 0 )
          goto LABEL_13;
        if ( (v8 & 0xF00) != 0 )
        {
          if ( (v8 & 0xF00) != 0x100 )
            goto LABEL_13;
LABEL_19:
          v10 = 0;
        }
        else
        {
LABEL_11:
          v10 = *((_WORD *)a1 + 4) - 1;
        }
        *((_WORD *)a1 + 3) = v10;
        goto LABEL_13;
      }
    }
  }
  return v4;
}

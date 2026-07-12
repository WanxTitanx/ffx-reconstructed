// Function: sub_807AE0
// Address: 0x807ae0
int __cdecl sub_807AE0(int a1, _WORD *a2)
{
  int v2; // esi
  int result; // eax
  int v4; // edi
  _WORD *v5; // ebx
  int v6; // esi
  _WORD *v7; // eax
  int v8; // eax
  unsigned __int8 *v9; // eax
  int v10; // edi
  int v11; // esi
  int v12; // eax
  int v13; // ecx
  int v14; // edx
  __int16 v15; // dx
  int v16; // eax
  int v17; // eax
  int v18; // [esp+1Ch] [ebp-20h]
  int v19; // [esp+24h] [ebp-18h]
  int v20; // [esp+28h] [ebp-14h]
  _WORD *v21; // [esp+2Ch] [ebp-10h]
  unsigned __int8 *v22; // [esp+30h] [ebp-Ch]
  int v23; // [esp+34h] [ebp-8h]
  int v24; // [esp+38h] [ebp-4h]

  v2 = a1;
  result = sub_7FCBA0(a1);
  if ( !result )
  {
    v4 = 0;
    v18 = sub_83C9A0(a1);
    *a2 = v18;
    v5 = a2 + 16;
    v19 = 0;
    if ( v18 > 0 )
    {
      v21 = a2 + 1;
      do
      {
        v6 = sub_83C9F0(v2, v4);
        v7 = v21;
        v20 = v6;
        *v21 = v6;
        if ( v6 )
        {
          v8 = sub_83C9B0(a1, v4);
          if ( v6 > 0 )
          {
            v9 = (unsigned __int8 *)(v8 + 2);
            v22 = v9;
            do
            {
              if ( *(_DWORD *)(v9 - 2) )
              {
                v10 = *(v9 - 2);
                v11 = *(v9 - 1);
                v12 = *v9;
                v13 = v10;
                if ( v10 < v11 )
                  v13 = v11;
                if ( v12 > v13 )
                  v13 = v12;
                v14 = v10;
                if ( v10 > v11 )
                  v14 = v11;
                if ( v12 < v14 )
                  v14 = v12;
                v24 = v13 - v14;
                if ( v13 == v14 )
                {
                  v15 = 0;
                  LOWORD(v12) = 0;
                }
                else
                {
                  if ( v13 )
                    v23 = (v24 << 8) / v13;
                  else
                    LOWORD(v23) = 0;
                  if ( v10 == v13 )
                  {
                    v12 = ((v11 - v12) << 7) / v24;
                  }
                  else if ( v11 == v13 )
                  {
                    LOWORD(v12) = ((v12 - v10) << 7) / v24 + 256;
                  }
                  else
                  {
                    v12 = ((v10 - v11) << 7) / v24 + 512;
                  }
                  v15 = v23;
                }
                v6 = v20;
                *v5 = v12;
                v5[1] = v15;
                v5[2] = v13;
                v5[3] = v22[1];
                v9 = v22;
              }
              else
              {
                *(_DWORD *)v5 = 0;
              }
              --v6;
              v9 += 4;
              v5 += 4;
              v22 = v9;
              v20 = v6;
            }
            while ( v6 > 0 );
            v4 = v19;
          }
          v7 = v21;
        }
        v2 = a1;
        v19 = ++v4;
        v21 = v7 + 1;
      }
      while ( v4 < v18 );
    }
    v16 = sub_826BF0(v2);
    sub_6402B0(v16, 1);
    v17 = sub_826BF0(v2);
    return sub_6434F0(v17, 0.0, 0.0, 0.0, -1.0);
  }
  return result;
}

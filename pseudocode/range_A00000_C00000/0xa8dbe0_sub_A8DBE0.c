// Function: sub_A8DBE0
// Address: 0xa8dbe0
// Size: 0x2df
// Prototype: 

_DWORD *__thiscall sub_A8DBE0(_DWORD *this, int a2, int a3, int a4)
{
  _DWORD *this_1; // esi
  int v5; // esi
  int v6; // eax
  _DWORD *result; // eax
  int i_3; // edi
  int i_1; // ecx
  int i_2; // ebx
  int v11; // edx
  int v12; // eax
  int v13; // edx
  int v14; // ecx
  int v15; // eax
  int v16; // ebx
  int v17; // eax
  int v18; // edi
  int v19; // edx
  _DWORD *v20; // ecx
  _DWORD *v21; // eax
  int n2; // eax
  int v23; // edi
  int v24; // ecx
  int v25; // ebx
  int v26; // ecx
  int v27; // eax
  int v28; // eax
  int v29; // esi
  int v30; // ecx
  int v31; // eax
  int v32; // edi
  int v33; // ecx
  int v35; // [esp+10h] [ebp-20h]
  int i_4; // [esp+14h] [ebp-1Ch]
  int v37; // [esp+18h] [ebp-18h]
  int v38; // [esp+1Ch] [ebp-14h]
  int v39; // [esp+20h] [ebp-10h]
  int v40; // [esp+24h] [ebp-Ch]
  int v41; // [esp+28h] [ebp-8h]
  int i; // [esp+2Ch] [ebp-4h]
  char v43; // [esp+3Bh] [ebp+Bh]

  this_1 = this;
  sub_A8DEC0(a2, a3);
  i_4 = this_1[2];
  if ( *((_BYTE *)this_1 + 64) )
  {
    v38 = this_1[7];
    result = (_DWORD *)v38;
    LOBYTE(a2) = 0;
    if ( v38 > 1 )
      result = (_DWORD *)sub_A8D8F0(this_1 + 6, a2, 0, v38 - 1);
    i_3 = i_4;
    i_1 = 0;
    v40 = 0;
    v41 = 1;
    if ( i_4 > 0 )
    {
      do
      {
        i_2 = i_1;
        v11 = *(_DWORD *)(this_1[4] + 8 * i_1);
        v39 = v11;
        v43 = 0;
        for ( i = i_1; i_2 < i_3; i = ++i_2 )
        {
          v12 = this_1[4];
          if ( *(_DWORD *)(v12 + 8 * i_2) != v11 )
            break;
          v13 = *(_DWORD *)(*(_DWORD *)(a3 + 16) + 4 * *(_DWORD *)(v12 + 8 * i_2 + 4));
          v14 = this_1[13];
          v15 = this_1[12];
          v35 = v13;
          if ( v15 == v14 )
          {
            v16 = 2 * v15;
            if ( !v15 )
              v16 = 1;
            if ( v14 < v16 )
            {
              if ( v16 )
                v17 = sub_9D4CE0(4 * v16, 16);
              else
                v17 = 0;
              v18 = this_1[12];
              v19 = 0;
              v37 = v17;
              if ( v18 > 0 )
              {
                v20 = (_DWORD *)v17;
                do
                {
                  if ( v20 )
                    *v20 = *(_DWORD *)(this_1[14] + 4 * v19);
                  ++v19;
                  ++v20;
                }
                while ( v19 < v18 );
              }
              if ( this_1[14] )
              {
                if ( *((_BYTE *)this_1 + 60) )
                  sub_9D4D50(this_1[14]);
                this_1[14] = 0;
              }
              v13 = v35;
              i_3 = i_4;
              *((_BYTE *)this_1 + 60) = 1;
              this_1[14] = v37;
              this_1[13] = v16;
            }
            i_2 = i;
          }
          v21 = (_DWORD *)(this_1[14] + 4 * this_1[12]);
          if ( v21 )
            *v21 = v13;
          ++this_1[12];
          n2 = *(_DWORD *)(v13 + 228);
          if ( n2 == 2 || n2 == 5 )
            v43 = 1;
          v11 = v39;
        }
        v23 = 0;
        v24 = 0;
        if ( v40 < v38 )
        {
          v25 = this_1[9];
          v26 = *(_DWORD *)(v25 + 4 * v40);
          v27 = *(_DWORD *)(*(_DWORD *)(v26 + 1168) + 220);
          if ( v27 < 0 )
            v27 = *(_DWORD *)(*(_DWORD *)(v26 + 1172) + 220);
          if ( v27 == v39 )
          {
            v28 = v40 + 1;
            v24 = v25 + 4 * v40;
            v41 = v40 + 1;
            if ( v40 + 1 < v38 )
            {
              v29 = v40 + 1;
              v30 = v25 + 4 * v28;
              do
              {
                v31 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v30 + 1168) + 220);
                if ( v31 < 0 )
                  v31 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v30 + 1172) + 220);
                if ( v39 != v31 )
                  break;
                ++v29;
                v30 += 4;
              }
              while ( v29 < v38 );
              v24 = v25 + 4 * v40;
              v41 = v29;
              this_1 = this;
              v28 = v41;
            }
            v23 = v28 - v40;
          }
          else
          {
            v24 = 0;
          }
          i_2 = i;
        }
        if ( !v43 )
          (*(void (__thiscall **)(int, _DWORD, _DWORD, int, int, int))(*(_DWORD *)a4 + 4))(
            a4,
            this_1[14],
            this_1[12],
            v24,
            v23,
            v39);
        result = (_DWORD *)v40;
        if ( v23 )
          result = (_DWORD *)v41;
        v32 = this_1[12];
        v40 = (int)result;
        if ( v32 < 0 )
        {
          if ( (int)this_1[13] < 0 )
          {
            if ( this_1[14] )
            {
              if ( *((_BYTE *)this_1 + 60) )
                sub_9D4D50(this_1[14]);
              this_1[14] = 0;
            }
            *((_BYTE *)this_1 + 60) = 1;
            this_1[14] = 0;
            this_1[13] = 0;
          }
          v33 = 4 * v32;
          do
          {
            result = (_DWORD *)(v33 + this_1[14]);
            if ( result )
              *result = 0;
            v33 += 4;
          }
          while ( v33 < 0 );
        }
        i_3 = i_4;
        this_1[12] = 0;
        i_1 = i_2;
      }
      while ( i_2 < i_4 );
    }
  }
  else
  {
    v5 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 40))(a2);
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 32))(a2);
    return (_DWORD *)(*(int (__thiscall **)(int, _DWORD, _DWORD, int, int, int))(*(_DWORD *)a4 + 4))(
                       a4,
                       *(_DWORD *)(a3 + 16),
                       *(_DWORD *)(a3 + 8),
                       v5,
                       v6,
                       -1);
  }
  return result;
}


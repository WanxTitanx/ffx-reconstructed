// Function: sub_9B7050
// Address: 0x9b7050
int __thiscall sub_9B7050(int this, int a2, int i_3, int a4, int j_3, int a6)
{
  int v6; // ebx
  int this_1; // esi
  int v8; // edx
  int result; // eax
  int v10; // ecx
  int v11; // edx
  int v12; // edi
  int v13; // eax
  int v14; // ecx
  int v15; // edi
  int k_4; // esi
  int v17; // eax
  int v18; // edx
  int i_2; // ebx
  int i_1; // edx
  int v21; // ecx
  int v22; // eax
  int v23; // ebx
  int v24; // eax
  int v25; // edi
  int v26; // edx
  _DWORD *v27; // ecx
  _DWORD *v28; // ecx
  int j_2; // ebx
  int j_1; // edx
  int v31; // ecx
  int v32; // eax
  int v33; // ebx
  int v34; // eax
  int v35; // edi
  int v36; // edx
  _DWORD *v37; // ecx
  _DWORD *v38; // ecx
  int k_2; // ebx
  int k_1; // edx
  int v41; // ecx
  int v42; // eax
  int v43; // ebx
  int v44; // eax
  int v45; // edi
  int v46; // edx
  _DWORD *v47; // ecx
  _DWORD *v48; // ecx
  int i; // [esp+Ch] [ebp-Ch]
  int v51; // [esp+10h] [ebp-8h]
  int k_3; // [esp+14h] [ebp-4h]
  int j; // [esp+20h] [ebp+8h]
  int v54; // [esp+24h] [ebp+Ch]
  int v55; // [esp+24h] [ebp+Ch]
  int k; // [esp+2Ch] [ebp+14h]
  int v57; // [esp+30h] [ebp+18h]

  v6 = a6;
  this_1 = this;
  if ( a6 >= 0 )
  {
    v10 = *(_DWORD *)(this + 16);
    v11 = 0;
    v51 = 0;
    k_3 = 0;
    if ( v10 > 0 )
    {
      v12 = *(_DWORD *)(this_1 + 12);
      while ( 1 )
      {
        v13 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v12 + 20) + 220);
        if ( v13 < 0 )
          v13 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v12 + 24) + 220);
        v6 = a6;
        if ( v13 == a6 )
          break;
        ++v11;
        v12 += 4;
        if ( v11 >= v10 )
          goto LABEL_12;
      }
      v51 = *(_DWORD *)(this_1 + 12) + 4 * v11;
    }
LABEL_12:
    if ( v11 < v10 )
    {
      v14 = v10 - v11;
      v15 = *(_DWORD *)(this_1 + 12) + 4 * v11;
      k_4 = 0;
      do
      {
        v17 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v15 + 20) + 220);
        if ( v17 < 0 )
          v17 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v15 + 24) + 220);
        if ( v17 == v6 )
          ++k_4;
        v15 += 4;
        --v14;
      }
      while ( v14 );
      k_3 = k_4;
      this_1 = this;
    }
    v18 = *(_DWORD *)(this_1 + 4);
    if ( *(int *)(v18 + 68) > 1 )
    {
      i_2 = i_3;
      i_1 = 0;
      for ( i = 0; i_1 < i_2; i = i_1 )
      {
        v21 = *(_DWORD *)(this_1 + 40);
        v22 = *(_DWORD *)(this_1 + 36);
        if ( v22 == v21 )
        {
          v23 = 2 * v22;
          if ( !v22 )
            v23 = 1;
          if ( v21 < v23 )
          {
            if ( v23 )
              v24 = sub_9D4CE0(4 * v23, 16);
            else
              v24 = 0;
            v25 = *(_DWORD *)(this_1 + 36);
            v26 = 0;
            v57 = v24;
            if ( v25 > 0 )
            {
              v27 = (_DWORD *)v24;
              do
              {
                if ( v27 )
                  *v27 = *(_DWORD *)(*(_DWORD *)(this_1 + 44) + 4 * v26);
                ++v26;
                ++v27;
              }
              while ( v26 < v25 );
            }
            if ( *(_DWORD *)(this_1 + 44) )
            {
              if ( *(_BYTE *)(this_1 + 48) )
                sub_9D4D50(*(_DWORD *)(this_1 + 44));
              *(_DWORD *)(this_1 + 44) = 0;
            }
            i_1 = i;
            *(_BYTE *)(this_1 + 48) = 1;
            *(_DWORD *)(this_1 + 44) = v57;
            *(_DWORD *)(this_1 + 40) = v23;
          }
          i_2 = i_3;
        }
        v28 = (_DWORD *)(*(_DWORD *)(this_1 + 44) + 4 * *(_DWORD *)(this_1 + 36));
        if ( v28 )
          *v28 = *(_DWORD *)(a2 + 4 * i_1);
        ++*(_DWORD *)(this_1 + 36);
        ++i_1;
      }
      j_2 = j_3;
      j_1 = 0;
      for ( j = 0; j_1 < j_2; j = j_1 )
      {
        v31 = *(_DWORD *)(this_1 + 60);
        v32 = *(_DWORD *)(this_1 + 56);
        if ( v32 == v31 )
        {
          v33 = 2 * v32;
          if ( !v32 )
            v33 = 1;
          if ( v31 < v33 )
          {
            if ( v33 )
              v34 = sub_9D4CE0(4 * v33, 16);
            else
              v34 = 0;
            v35 = *(_DWORD *)(this_1 + 56);
            v36 = 0;
            v54 = v34;
            if ( v35 > 0 )
            {
              v37 = (_DWORD *)v34;
              do
              {
                if ( v37 )
                  *v37 = *(_DWORD *)(*(_DWORD *)(this_1 + 64) + 4 * v36);
                ++v36;
                ++v37;
              }
              while ( v36 < v35 );
            }
            if ( *(_DWORD *)(this_1 + 64) )
            {
              if ( *(_BYTE *)(this_1 + 68) )
                sub_9D4D50(*(_DWORD *)(this_1 + 64));
              *(_DWORD *)(this_1 + 64) = 0;
            }
            j_1 = j;
            *(_BYTE *)(this_1 + 68) = 1;
            *(_DWORD *)(this_1 + 64) = v54;
            *(_DWORD *)(this_1 + 60) = v33;
          }
          j_2 = j_3;
        }
        v38 = (_DWORD *)(*(_DWORD *)(this_1 + 64) + 4 * *(_DWORD *)(this_1 + 56));
        if ( v38 )
          *v38 = *(_DWORD *)(a4 + 4 * j_1);
        ++*(_DWORD *)(this_1 + 56);
        ++j_1;
      }
      k_2 = k_3;
      k_1 = 0;
      for ( k = 0; k_1 < k_2; k = k_1 )
      {
        v41 = *(_DWORD *)(this_1 + 80);
        v42 = *(_DWORD *)(this_1 + 76);
        if ( v42 == v41 )
        {
          v43 = 2 * v42;
          if ( !v42 )
            v43 = 1;
          if ( v41 < v43 )
          {
            if ( v43 )
              v44 = sub_9D4CE0(4 * v43, 16);
            else
              v44 = 0;
            v45 = *(_DWORD *)(this_1 + 76);
            v46 = 0;
            v55 = v44;
            if ( v45 > 0 )
            {
              v47 = (_DWORD *)v44;
              do
              {
                if ( v47 )
                  *v47 = *(_DWORD *)(*(_DWORD *)(this_1 + 84) + 4 * v46);
                ++v46;
                ++v47;
              }
              while ( v46 < v45 );
            }
            if ( *(_DWORD *)(this_1 + 84) )
            {
              if ( *(_BYTE *)(this_1 + 88) )
                sub_9D4D50(*(_DWORD *)(this_1 + 84));
              *(_DWORD *)(this_1 + 84) = 0;
            }
            k_1 = k;
            *(_BYTE *)(this_1 + 88) = 1;
            *(_DWORD *)(this_1 + 84) = v55;
            *(_DWORD *)(this_1 + 80) = v43;
          }
          k_2 = k_3;
        }
        v48 = (_DWORD *)(*(_DWORD *)(this_1 + 84) + 4 * *(_DWORD *)(this_1 + 76));
        if ( v48 )
          *v48 = *(_DWORD *)(v51 + 4 * k_1);
        ++*(_DWORD *)(this_1 + 76);
        ++k_1;
      }
      result = *(_DWORD *)(this_1 + 4);
      if ( *(_DWORD *)(this_1 + 56) + *(_DWORD *)(this_1 + 76) > *(_DWORD *)(result + 68) )
        return sub_9BB660(this_1);
    }
    else
    {
      result = k_3 + j_3;
      if ( k_3 + j_3 )
        return (*(int (__thiscall **)(_DWORD, int, int, int, int, int, int, int, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(this_1 + 8) + 8))(
                 *(_DWORD *)(this_1 + 8),
                 a2,
                 i_3,
                 a4,
                 j_3,
                 v51,
                 k_3,
                 v18,
                 *(_DWORD *)(this_1 + 20),
                 *(_DWORD *)(this_1 + 24),
                 *(_DWORD *)(this_1 + 28));
    }
  }
  else
  {
    v8 = *(_DWORD *)(this + 16);
    result = v8 + j_3;
    if ( v8 + j_3 )
      return (*(int (__thiscall **)(_DWORD, int, int, int, int, _DWORD, int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)(this + 8) + 8))(
               *(_DWORD *)(this + 8),
               a2,
               i_3,
               a4,
               j_3,
               *(_DWORD *)(this + 12),
               v8,
               *(_DWORD *)(this + 4),
               *(_DWORD *)(this + 20),
               *(_DWORD *)(this + 24),
               *(_DWORD *)(this + 28));
  }
  return result;
}

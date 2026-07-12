// Function: sub_A8DEC0
// Address: 0xa8dec0
// Size: 0x334
// Prototype: 

int __thiscall sub_A8DEC0(int this, int a2, int a3)
{
  int this_1; // ebx
  int v4; // esi
  int v5; // ecx
  _DWORD *v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // ecx
  int v10; // edi
  int v11; // edx
  _DWORD *v12; // eax
  int v13; // ebx
  int v14; // ecx
  _DWORD *v15; // ebx
  int v16; // eax
  int n4; // ecx
  char v18; // al
  bool v19; // zf
  int v20; // eax
  int v21; // esi
  int i_3; // ecx
  int i_1; // eax
  int v24; // eax
  int v25; // edi
  int v26; // esi
  int v27; // ecx
  int v28; // eax
  int v29; // edi
  int v30; // eax
  int v31; // esi
  int v32; // edx
  _DWORD *v33; // ecx
  int *v34; // eax
  int v36; // [esp+Ch] [ebp-1Ch]
  int v37; // [esp+10h] [ebp-18h]
  int i_2; // [esp+10h] [ebp-18h]
  int v39; // [esp+14h] [ebp-14h]
  int i; // [esp+14h] [ebp-14h]
  int v41; // [esp+18h] [ebp-10h]
  int v42; // [esp+1Ch] [ebp-Ch]
  int v43; // [esp+20h] [ebp-8h]
  char v44; // [esp+24h] [ebp-4h]
  int v45; // [esp+34h] [ebp+Ch]

  this_1 = this;
  v4 = *(_DWORD *)(this + 28);
  if ( v4 < 0 )
  {
    if ( *(int *)(this + 32) < 0 )
    {
      if ( *(_DWORD *)(this + 36) )
      {
        if ( *(_BYTE *)(this + 40) )
          sub_9D4D50(*(_DWORD *)(this + 36));
        *(_DWORD *)(this_1 + 36) = 0;
      }
      *(_BYTE *)(this_1 + 40) = 1;
      *(_DWORD *)(this_1 + 36) = 0;
      *(_DWORD *)(this_1 + 32) = 0;
    }
    v5 = 4 * v4;
    do
    {
      v6 = (_DWORD *)(v5 + *(_DWORD *)(this_1 + 36));
      if ( v6 )
        *v6 = 0;
      v5 += 4;
    }
    while ( v5 < 0 );
  }
  *(_DWORD *)(this_1 + 28) = 0;
  sub_A8EB30(this_1 + 4);
  v7 = *(_DWORD *)(this_1 + 8);
  v8 = 0;
  v39 = v7;
  if ( v7 > 0 )
  {
    do
    {
      v9 = *(_DWORD *)(this_1 + 16);
      v10 = v8 + 1;
      v11 = *(_DWORD *)(v9 + 8 * v8);
      v41 = v11;
      v42 = v8 + 1;
      if ( v8 + 1 < v7 )
      {
        v12 = (_DWORD *)(v9 + 8 * v10);
        do
        {
          if ( *v12 != v11 )
            break;
          ++v10;
          v12 += 2;
        }
        while ( v10 < v39 );
        v42 = v10;
      }
      v44 = 1;
      if ( v8 < v10 )
      {
        v13 = v9 + 4;
        v14 = v10 - v8;
        v15 = (_DWORD *)(v13 + 8 * v8);
        v43 = v10 - v8;
        do
        {
          v16 = *(_DWORD *)(*(_DWORD *)(a3 + 16) + 4 * *v15);
          if ( *(_DWORD *)(v16 + 220) == v11 )
          {
            n4 = *(_DWORD *)(v16 + 228);
            v18 = v44;
            if ( n4 == 1 )
              v18 = 0;
            v19 = n4 == 4;
            v14 = v43;
            if ( v19 )
              v18 = 0;
            v44 = v18;
          }
          else
          {
            v18 = v44;
          }
          v15 += 2;
          v43 = --v14;
        }
        while ( v14 );
        v10 = v42;
        this_1 = this;
        if ( v18 )
        {
          for ( ; v8 < v42; ++v8 )
          {
            if ( *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a3 + 16) + 4 * *(_DWORD *)(*(_DWORD *)(this + 16) + 8 * v8 + 4))
                           + 220) == v11 )
            {
              sub_97A440(2);
              v11 = v41;
            }
          }
        }
        else
        {
          do
          {
            v20 = *(_DWORD *)(*(_DWORD *)(a3 + 16) + 4 * *(_DWORD *)(*(_DWORD *)(this + 16) + 8 * v8 + 4));
            v37 = v20;
            if ( *(_DWORD *)(v20 + 220) == v11 && *(_DWORD *)(v20 + 228) == 2 )
            {
              sub_97A440(3);
              v11 = v41;
              *(_DWORD *)(v37 + 232) = 0;
            }
            ++v8;
          }
          while ( v8 < v42 );
        }
      }
      v7 = v39;
      v8 = v10;
    }
    while ( v10 < v39 );
  }
  v21 = a2;
  i_3 = (*(int (__thiscall **)(int))(*(_DWORD *)a2 + 32))(a2);
  i_1 = 0;
  i_2 = i_3;
  for ( i = 0; i_1 < i_2; i = i_1 )
  {
    v24 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v21 + 36))(v21, i_1);
    v25 = *(_DWORD *)(v24 + 1168);
    v26 = *(_DWORD *)(v24 + 1172);
    v36 = v24;
    if ( v25 && *(_DWORD *)(v25 + 228) != 2 || v26 && *(_DWORD *)(v26 + 228) != 2 )
    {
      if ( (*(_DWORD *)(v25 + 216) & 2) != 0 && *(_DWORD *)(v25 + 228) != 2 )
        sub_97A080(0);
      if ( (*(_DWORD *)(v26 + 216) & 2) != 0 && *(_DWORD *)(v26 + 228) != 2 )
        sub_97A080(0);
      if ( *(_BYTE *)(this_1 + 64)
        && (*(unsigned __int8 (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 24))(a2, v25, v26) )
      {
        v27 = *(_DWORD *)(this_1 + 32);
        v28 = *(_DWORD *)(this_1 + 28);
        if ( v28 == v27 )
        {
          v29 = 2 * v28;
          if ( !v28 )
            v29 = 1;
          if ( v27 < v29 )
          {
            if ( v29 )
              v30 = sub_9D4CE0(4 * v29, 16);
            else
              v30 = 0;
            v31 = *(_DWORD *)(this_1 + 28);
            v32 = 0;
            v45 = v30;
            if ( v31 > 0 )
            {
              v33 = (_DWORD *)v30;
              do
              {
                if ( v33 )
                  *v33 = *(_DWORD *)(*(_DWORD *)(this_1 + 36) + 4 * v32);
                ++v32;
                ++v33;
              }
              while ( v32 < v31 );
            }
            if ( *(_DWORD *)(this_1 + 36) )
            {
              if ( *(_BYTE *)(this_1 + 40) )
                sub_9D4D50(*(_DWORD *)(this_1 + 36));
              *(_DWORD *)(this_1 + 36) = 0;
            }
            *(_BYTE *)(this_1 + 40) = 1;
            *(_DWORD *)(this_1 + 36) = v45;
            *(_DWORD *)(this_1 + 32) = v29;
          }
        }
        v34 = (int *)(*(_DWORD *)(this_1 + 36) + 4 * *(_DWORD *)(this_1 + 28));
        if ( v34 )
          *v34 = v36;
        ++*(_DWORD *)(this_1 + 28);
      }
    }
    v21 = a2;
    i_1 = i + 1;
  }
  return i_1;
}


// Function: sub_A25AB0
// Address: 0xa25ab0
// Size: 0x261
// Prototype: 

char __thiscall sub_A25AB0(_DWORD *this)
{
  int v2; // edi
  char v3; // bl
  int (__thiscall *v4)(int, int); // edx
  char v5; // al
  int (__thiscall *v6)(int, int); // edx
  char v7; // al
  bool v8; // zf
  int n5; // edx
  char *v10; // ecx
  int v11; // eax
  _DWORD *v12; // edx
  int v13; // edx
  int v14; // eax
  int i; // edx
  char *v16; // eax
  char v17; // cl
  int n5_1; // edi
  char *v19; // ecx
  int v20; // eax
  _DWORD *v21; // edi
  int v22; // edi
  int v23; // eax
  int n5_2; // edi
  int v25; // eax
  int v26; // edi
  int v27; // eax
  int n5_3; // edx
  char *v29; // ecx
  int v30; // eax
  _DWORD *v31; // edx
  int v32; // edx
  int v33; // eax
  char result; // al
  float v35; // [esp+Ch] [ebp-10h]
  float v36; // [esp+10h] [ebp-Ch]
  float v37; // [esp+14h] [ebp-8h]
  char v38; // [esp+18h] [ebp-4h] BYREF
  char v39; // [esp+19h] [ebp-3h]
  char v40; // [esp+1Ah] [ebp-2h]

  *(this + 29) = 0;
  *(this + 3) = 0;
  v2 = sub_623E50(0, 0);
  v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 12))(v2, 11);
  v4 = *(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 12);
  v38 = v3;
  v5 = v4(v2, 12);
  v6 = *(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 12);
  v39 = v5;
  v7 = v6(v2, 13);
  v8 = *((_BYTE *)this + 120) == 0;
  v40 = v7;
  if ( !v8 )
  {
    v40 = v3;
    v38 = v7;
  }
  v37 = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v2 + 16))(v2, 1);
  v36 = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v2 + 16))(v2, 2);
  v35 = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v2 + 16))(v2, 3);
  n5 = *(this + 29);
  v10 = 0;
  if ( n5 < 5 )
  {
    v10 = (char *)(this + 4 * n5 + n5 + 4);
    *(this + 29) = n5 + 1;
    *((_DWORD *)v10 + 4) = 0;
  }
  *(_DWORD *)v10 = 6;
  *((float *)v10 + 1) = v37;
  *((float *)v10 + 2) = v36;
  v11 = *(this + 3);
  if ( v11 )
  {
    v12 = (_DWORD *)(v11 + 16);
    if ( *(_DWORD *)(v11 + 16) )
    {
      v13 = *(_DWORD *)(v11 + 16);
      v14 = *(_DWORD *)(v13 + 16);
      v12 = (_DWORD *)(v13 + 16);
      while ( v14 )
        ;
    }
    *((_DWORD *)v10 + 4) = 0;
    *v12 = v10;
  }
  else
  {
    *(this + 3) = v10;
    *((_DWORD *)v10 + 4) = 0;
  }
  for ( i = 0; i < 3; ++i )
  {
    if ( i == 1 )
      continue;
    v16 = &v38 + i;
    v17 = *(&v38 + i + (char *)this - &v38);
    if ( !v17 && *v16 == 1 )
    {
      n5_1 = *(this + 29);
      v19 = 0;
      if ( n5_1 < 5 )
      {
        v19 = (char *)(this + 4 * n5_1 + n5_1 + 4);
        *(this + 29) = n5_1 + 1;
        *((_DWORD *)v19 + 4) = 0;
      }
      *((float *)v19 + 1) = v37;
      *(_DWORD *)v19 = 2 * i;
      *((float *)v19 + 2) = v36;
      v20 = *(this + 3);
      if ( !v20 )
      {
        *(this + 3) = v19;
        *((_DWORD *)v19 + 4) = 0;
        continue;
      }
      v21 = (_DWORD *)(v20 + 16);
      if ( *(_DWORD *)(v20 + 16) )
      {
        v22 = *(_DWORD *)(v20 + 16);
        v23 = *(_DWORD *)(v22 + 16);
        v21 = (_DWORD *)(v22 + 16);
        while ( v23 )
          ;
      }
LABEL_32:
      *((_DWORD *)v19 + 4) = 0;
      *v21 = v19;
      continue;
    }
    if ( v17 == 1 && !*v16 )
    {
      n5_2 = *(this + 29);
      v19 = 0;
      if ( n5_2 < 5 )
      {
        v19 = (char *)(this + 4 * n5_2 + n5_2 + 4);
        *(this + 29) = n5_2 + 1;
        *((_DWORD *)v19 + 4) = 0;
      }
      *((float *)v19 + 1) = v37;
      *(_DWORD *)v19 = 2 * i + 1;
      *((float *)v19 + 2) = v36;
      v25 = *(this + 3);
      if ( !v25 )
      {
        *(this + 3) = v19;
        *((_DWORD *)v19 + 4) = 0;
        continue;
      }
      v21 = (_DWORD *)(v25 + 16);
      if ( *(_DWORD *)(v25 + 16) )
      {
        v26 = *(_DWORD *)(v25 + 16);
        v27 = *(_DWORD *)(v26 + 16);
        v21 = (_DWORD *)(v26 + 16);
        while ( v27 )
          ;
      }
      goto LABEL_32;
    }
  }
  if ( 0.0 != v35 )
  {
    n5_3 = *(this + 29);
    v29 = 0;
    if ( n5_3 < 5 )
    {
      v29 = (char *)(this + 4 * n5_3 + n5_3 + 4);
      *(this + 29) = n5_3 + 1;
      *((_DWORD *)v29 + 4) = 0;
    }
    *((float *)v29 + 3) = v35;
    *(_DWORD *)v29 = 7;
    v30 = *(this + 3);
    if ( v30 )
    {
      v31 = (_DWORD *)(v30 + 16);
      if ( *(_DWORD *)(v30 + 16) )
      {
        v32 = *(_DWORD *)(v30 + 16);
        v33 = *(_DWORD *)(v32 + 16);
        v31 = (_DWORD *)(v32 + 16);
        while ( v33 )
          ;
      }
      *((_DWORD *)v29 + 4) = 0;
      *v31 = v29;
    }
    else
    {
      *(this + 3) = v29;
      *((_DWORD *)v29 + 4) = 0;
    }
  }
  *(_BYTE *)this = v38;
  *((_BYTE *)this + 1) = v39;
  result = v40;
  *((_BYTE *)this + 2) = v40;
  return result;
}


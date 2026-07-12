// Function: sub_A27170
// Address: 0xa27170
// Size: 0x234
// Prototype: 

bool __thiscall sub_A27170(int this, _WORD *a2, int a3)
{
  int v5; // ebx
  int v6; // eax
  int v7; // edx
  int v8; // eax
  int *v9; // eax
  int v10; // edx
  bool v11; // bl
  bool v12; // cf
  int v13; // ecx
  int v14; // edi
  _WORD *v15; // eax
  _WORD *v16; // ebx
  int i_1; // eax
  int v18; // edi
  int n0x7FFF; // eax
  FILE *v20; // eax
  int v21; // edi
  int X_4; // [esp+4h] [ebp-30h]
  int i; // [esp+14h] [ebp-20h]
  float X; // [esp+18h] [ebp-1Ch]
  float n0x7FFF_1; // [esp+18h] [ebp-1Ch]
  int v26; // [esp+1Ch] [ebp-18h] BYREF
  _WORD *v27; // [esp+20h] [ebp-14h]
  int v28; // [esp+24h] [ebp-10h]
  int v29; // [esp+28h] [ebp-Ch]
  int v30; // [esp+2Ch] [ebp-8h]
  int v31; // [esp+30h] [ebp-4h]

  if ( *(_BYTE *)(this + 680) )
    return 0;
  v5 = *(_DWORD *)(this + 676);
  v31 = v5;
  while ( v5 > 0 )
  {
    if ( *(_DWORD *)(this + 216) == 1 )
      break;
    v6 = sub_A90A10(this + 432, &v26);
    v7 = v6;
    v29 = v6;
    if ( v6 )
    {
      v13 = 0;
      v30 = 0;
      if ( v6 >= v5 )
      {
        v7 = v5;
        v29 = v5;
      }
      v14 = 0;
      v28 = 0;
      if ( *(int *)(this + 388) > 0 )
      {
        v15 = a2;
        v27 = a2;
        do
        {
          v16 = v15;
          i_1 = *(_DWORD *)(v26 + 4 * v14);
          v18 = 0;
          for ( i = i_1; v18 < v7; i_1 = i )
          {
            X = *(float *)(i_1 + 4 * v18) * 32767.0 + 0.5;
            n0x7FFF_1 = floor(X);
            n0x7FFF = (int)n0x7FFF_1;
            if ( n0x7FFF <= 0x7FFF )
            {
              if ( n0x7FFF >= -32768 )
              {
                v13 = v30;
              }
              else
              {
                v13 = 1;
                LOWORD(n0x7FFF) = 0x8000;
                v30 = 1;
              }
            }
            else
            {
              v13 = 1;
              LOWORD(n0x7FFF) = 0x7FFF;
              v30 = 1;
            }
            v7 = v29;
            *v16 = n0x7FFF;
            ++v18;
            v16 += *(_DWORD *)(this + 388);
          }
          v14 = v28 + 1;
          v15 = v27 + 1;
          v28 = v14;
          ++v27;
        }
        while ( v14 < *(_DWORD *)(this + 388) );
        if ( v13 )
        {
          X_4 = *(_DWORD *)(this + 496);
          v20 = __iob_func();
          fprintf(v20 + 2, "Clipping in frame %ld\n", X_4);
        }
        v5 = v31;
      }
      v21 = v29;
      sub_A909E0(this + 432, v29);
      v5 -= v21;
      a2 += v21 * *(_DWORD *)(this + 388);
      v31 = v5;
    }
    else if ( *(_DWORD *)(this + 216) != 1 )
    {
      v8 = this + 128;
      do
      {
        v9 = (int *)sub_A3DD90(v8);
        if ( !v9 )
          break;
        v10 = *v9;
        v11 = 0;
        v12 = __CFADD__((*(_DWORD *)(this + 376))++, 1);
        *(_DWORD *)(this + 380) += v12;
        *(_DWORD *)(this + 352) = v9 + 1;
        *(_DWORD *)(this + 356) = v10;
        if ( !sub_A92460(this + 544, this + 352) )
          v11 = sub_A90A70(this + 432, this + 544) == 0;
        sub_A3DDC0(this + 128);
        if ( v11 )
          break;
        v8 = this + 128;
      }
      while ( *(_DWORD *)(this + 216) != 1 );
      v5 = v31;
    }
  }
  if ( !*(_BYTE *)(this + 240) )
    v5 = v5 > 0 ? 0 : v5;
  return v5 == 0;
}


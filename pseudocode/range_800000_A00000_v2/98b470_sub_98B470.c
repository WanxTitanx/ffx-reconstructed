// Function: sub_98B470
// Address: 0x98b470
int __thiscall sub_98B470(int this, float *a2, int a3, int a4)
{
  double v5; // st6
  float *v6; // ecx
  float *v7; // ecx
  float *v8; // ecx
  float *v9; // edx
  double v10; // st7
  double v11; // st6
  float *v12; // ecx
  float *v13; // edx
  double v14; // st7
  double v15; // st6
  int result; // eax
  float v17; // [esp+4h] [ebp-10h]
  float v18; // [esp+8h] [ebp-Ch]
  float v19; // [esp+8h] [ebp-Ch]
  float v20; // [esp+Ch] [ebp-8h]

  v20 = *a2;
  v5 = a2[4];
  v6 = a2;
  if ( v5 <= v20 )
    v6 = a2 + 4;
  v18 = a2[8];
  if ( v18 <= (double)*v6 )
    v6 = a2 + 8;
  if ( *v6 <= (double)*(float *)(this + 32) )
  {
    v7 = a2;
    if ( v20 <= v5 )
      v7 = a2 + 4;
    if ( *v7 <= (double)v18 )
      v7 = a2 + 8;
    if ( *(float *)(this + 16) <= (double)*v7 )
    {
      v8 = a2 + 2;
      v9 = a2 + 2;
      v10 = a2[2];
      v11 = a2[6];
      if ( v11 <= v10 )
        v9 = a2 + 6;
      v19 = a2[10];
      if ( v19 <= (double)*v9 )
        v9 = a2 + 10;
      if ( *v9 <= (double)*(float *)(this + 40) )
      {
        if ( v10 <= v11 )
          v8 = a2 + 6;
        if ( *v8 <= (double)v19 )
          v8 = a2 + 10;
        if ( *(float *)(this + 24) <= (double)*v8 )
        {
          v12 = a2 + 1;
          v13 = a2 + 1;
          v14 = a2[1];
          v15 = a2[5];
          if ( v15 <= v14 )
            v13 = a2 + 5;
          v17 = a2[9];
          if ( v17 <= (double)*v13 )
            v13 = a2 + 9;
          if ( *v13 <= (double)*(float *)(this + 36) )
          {
            if ( v14 <= v15 )
              v12 = a2 + 5;
            if ( *v12 <= (double)v17 )
              v12 = a2 + 9;
            if ( *(float *)(this + 20) <= (double)*v12 )
              return (*(int (__thiscall **)(_DWORD, float *, int, int))(**(_DWORD **)(this + 4) + 4))(
                       *(_DWORD *)(this + 4),
                       a2,
                       a3,
                       a4);
          }
        }
      }
    }
  }
  return result;
}

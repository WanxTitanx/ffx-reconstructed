// Function: sub_98F310
// Address: 0x98f310
const char *__thiscall sub_98F310(int this, int a2, int a3)
{
  _DWORD *v3; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // edx
  int v11; // eax
  float *v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // edx
  int v16; // ebx
  int v17; // ecx
  int v18; // eax
  int v19; // ebx
  int v20; // eax
  int v21; // edx
  int v22; // ecx
  int v24; // [esp+Ch] [ebp-4h]
  int v25; // [esp+1Ch] [ebp+Ch]
  int v26; // [esp+1Ch] [ebp+Ch]

  v3 = (_DWORD *)a2;
  *(float *)(a2 + 16) = *(float *)(this + 32);
  *(float *)(a2 + 20) = *(float *)(this + 36);
  *(float *)(a2 + 24) = *(float *)(this + 40);
  *(float *)(a2 + 28) = *(float *)(this + 44);
  *(float *)a2 = *(float *)(this + 16);
  *(float *)(a2 + 4) = *(float *)(this + 20);
  *(float *)(a2 + 8) = *(float *)(this + 24);
  *(float *)(a2 + 12) = *(float *)(this + 28);
  *(float *)(a2 + 32) = *(float *)(this + 48);
  *(float *)(a2 + 36) = *(float *)(this + 52);
  *(float *)(a2 + 40) = *(float *)(this + 56);
  *(float *)(a2 + 44) = *(float *)(this + 60);
  *(_DWORD *)(a2 + 48) = *(_DWORD *)(this + 68);
  *(_DWORD *)(a2 + 52) = *(unsigned __int8 *)(this + 72);
  *(_DWORD *)(a2 + 56) = *(_DWORD *)(this + 100);
  if ( *(_DWORD *)(this + 100) )
    v6 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)a3 + 24))(a3, *(_DWORD *)(this + 108));
  else
    v6 = 0;
  *(_DWORD *)(a2 + 64) = v6;
  if ( v6 )
  {
    v25 = *(_DWORD *)(this + 100);
    v7 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a3 + 12))(a3, 48, v25);
    v8 = *(_DWORD *)(v7 + 8);
    v24 = v7;
    if ( v25 > 0 )
    {
      v9 = v25;
      v10 = 0;
      do
      {
        v11 = *(_DWORD *)(this + 108);
        v8 += 48;
        *(float *)(v8 - 32) = *(float *)(v10 + v11 + 16);
        *(float *)(v8 - 28) = *(float *)(v10 + v11 + 20);
        *(float *)(v8 - 24) = *(float *)(v10 + v11 + 24);
        *(float *)(v8 - 20) = *(float *)(v10 + v11 + 28);
        v12 = (float *)(v10 + *(_DWORD *)(this + 108));
        v10 += 64;
        *(float *)(v8 - 48) = *v12;
        *(float *)(v8 - 44) = v12[1];
        *(float *)(v8 - 40) = v12[2];
        *(float *)(v8 - 36) = v12[3];
        *(_DWORD *)(v8 - 16) = *(_DWORD *)(v10 + *(_DWORD *)(this + 108) - 32);
        *(_DWORD *)(v8 - 12) = *(_DWORD *)(v10 + *(_DWORD *)(this + 108) - 28);
        *(_DWORD *)(v8 - 8) = *(_DWORD *)(v10 + *(_DWORD *)(this + 108) - 24);
        --v9;
      }
      while ( v9 );
      v3 = (_DWORD *)a2;
    }
    (*(void (__thiscall **)(int, int, const char *, int, _DWORD))(*(_DWORD *)a3 + 16))(
      a3,
      v24,
      "btOptimizedBvhNodeData",
      1497453121,
      *(_DWORD *)(this + 108));
  }
  v3[15] = *(_DWORD *)(this + 140);
  if ( *(_DWORD *)(this + 140) )
    v13 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)a3 + 24))(a3, *(_DWORD *)(this + 148));
  else
    v13 = 0;
  v3[17] = v13;
  if ( v13 )
  {
    v26 = *(_DWORD *)(this + 140);
    v14 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a3 + 12))(a3, 16, v26);
    v15 = *(_DWORD *)(v14 + 8);
    if ( v26 > 0 )
    {
      v16 = v26;
      v17 = 0;
      do
      {
        v17 += 16;
        *(_DWORD *)(v15 + 12) = *(_DWORD *)(v17 + *(_DWORD *)(this + 148) - 4);
        v15 += 16;
        *(_WORD *)(v15 - 10) = *(_WORD *)(v17 + *(_DWORD *)(this + 148) - 10);
        *(_WORD *)(v15 - 8) = *(_WORD *)(v17 + *(_DWORD *)(this + 148) - 8);
        *(_WORD *)(v15 - 6) = *(_WORD *)(v17 + *(_DWORD *)(this + 148) - 6);
        *(_WORD *)(v15 - 16) = *(_WORD *)(v17 + *(_DWORD *)(this + 148) - 16);
        *(_WORD *)(v15 - 14) = *(_WORD *)(v17 + *(_DWORD *)(this + 148) - 14);
        *(_WORD *)(v15 - 12) = *(_WORD *)(v17 + *(_DWORD *)(this + 148) - 12);
        --v16;
      }
      while ( v16 );
      v3 = (_DWORD *)a2;
    }
    (*(void (__thiscall **)(int, int, const char *, int, _DWORD))(*(_DWORD *)a3 + 16))(
      a3,
      v14,
      "btQuantizedBvhNodeData",
      1497453121,
      *(_DWORD *)(this + 148));
  }
  v3[19] = *(_DWORD *)(this + 156);
  v3[20] = *(_DWORD *)(this + 164);
  if ( *(_DWORD *)(this + 164) )
    v18 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)a3 + 24))(a3, *(_DWORD *)(this + 172));
  else
    v18 = 0;
  v3[18] = v18;
  if ( v18 )
  {
    v19 = *(_DWORD *)(this + 164);
    v20 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)a3 + 12))(a3, 20, v19);
    v21 = *(_DWORD *)(v20 + 8);
    if ( v19 > 0 )
    {
      v22 = 0;
      do
      {
        v22 += 32;
        *(_WORD *)(v21 + 14) = *(_WORD *)(v22 + *(_DWORD *)(this + 172) - 26);
        v21 += 20;
        *(_WORD *)(v21 - 4) = *(_WORD *)(v22 + *(_DWORD *)(this + 172) - 24);
        *(_WORD *)(v21 - 2) = *(_WORD *)(v22 + *(_DWORD *)(this + 172) - 22);
        *(_WORD *)(v21 - 12) = *(_WORD *)(v22 + *(_DWORD *)(this + 172) - 32);
        *(_WORD *)(v21 - 10) = *(_WORD *)(v22 + *(_DWORD *)(this + 172) - 30);
        *(_WORD *)(v21 - 8) = *(_WORD *)(v22 + *(_DWORD *)(this + 172) - 28);
        *(_DWORD *)(v21 - 20) = *(_DWORD *)(v22 + *(_DWORD *)(this + 172) - 20);
        *(_DWORD *)(v21 - 16) = *(_DWORD *)(v22 + *(_DWORD *)(this + 172) - 16);
        --v19;
      }
      while ( v19 );
    }
    (*(void (__thiscall **)(int, int, const char *, int, _DWORD))(*(_DWORD *)a3 + 16))(
      a3,
      v20,
      "btBvhSubtreeInfoData",
      1497453121,
      *(_DWORD *)(this + 172));
  }
  return "btQuantizedBvhFloatData";
}

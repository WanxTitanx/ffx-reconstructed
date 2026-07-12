// Function: sub_9BC180
// Address: 0x9bc180
int __thiscall sub_9BC180(int *this, int a2)
{
  int v3; // edi
  int i_1; // ebx
  int i; // eax
  _DWORD *v6; // ecx
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int *v10; // ebx
  int v11; // edx
  int v12; // ecx
  int *v13; // edi
  int v14; // eax
  int v15; // esi
  int v16; // edi
  int v17; // eax
  int *this_2; // ebx
  int result; // eax
  _DWORD v20[12]; // [esp+10h] [ebp-84h] BYREF
  char v21; // [esp+40h] [ebp-54h]
  int v22; // [esp+48h] [ebp-4Ch]
  int v23; // [esp+4Ch] [ebp-48h]
  int v24; // [esp+50h] [ebp-44h]
  char v25; // [esp+54h] [ebp-40h]
  int v26; // [esp+5Ch] [ebp-38h]
  int v27; // [esp+60h] [ebp-34h]
  int v28; // [esp+64h] [ebp-30h]
  char v29; // [esp+68h] [ebp-2Ch]
  int v30; // [esp+6Ch] [ebp-28h] BYREF
  int i_2; // [esp+70h] [ebp-24h]
  int i_4; // [esp+74h] [ebp-20h]
  int v33; // [esp+78h] [ebp-1Ch]
  char v34; // [esp+7Ch] [ebp-18h]
  int i_3; // [esp+80h] [ebp-14h]
  int *this_1; // [esp+84h] [ebp-10h]
  int v37; // [esp+90h] [ebp-4h]

  this_1 = this;
  v3 = 0;
  v34 = 1;
  v33 = 0;
  i_2 = 0;
  i_4 = 0;
  i_1 = *(this + 47);
  v37 = 0;
  if ( i_1 >= 0 )
  {
    if ( i_1 > 0 )
    {
      v3 = sub_9D4CE0(4 * i_1, 16);
      i_3 = i_2;
      v34 = 1;
      v33 = v3;
      i_4 = i_1;
    }
    for ( i = 0; i < i_1; ++i )
    {
      v6 = (_DWORD *)(v3 + 4 * i);
      if ( v6 )
      {
        *v6 = 0;
        v3 = v33;
      }
    }
  }
  v7 = *this;
  i_2 = i_1;
  v8 = 0;
  if ( (*(int (__thiscall **)(int *))(v7 + 92))(this) > 0 )
  {
    do
    {
      ++v8;
      *(_DWORD *)(v33 + 4 * v8 - 4) = *(_DWORD *)(*(this + 49) + 4 * v8 - 4);
    }
    while ( v8 < (*(int (__thiscall **)(int *))(*this + 92))(this) );
  }
  LOBYTE(i_3) = 0;
  if ( i_2 > 1 )
    sub_9B6660(&v30, i_3, 0, i_2 - 1);
  v9 = (*(int (__thiscall **)(int *))(*this + 92))(this);
  v10 = (int *)*(this + 6);
  v11 = *(this + 19);
  v12 = *(this + 21);
  v13 = (int *)*(this + 44);
  v20[0] = &`btDiscreteDynamicsWorld::solveConstraints'::`2'::InplaceSolverIslandCallback::`vftable';
  v20[3] = v9 != 0 ? v33 : 0;
  v20[1] = a2;
  v20[2] = v13;
  v20[4] = i_2;
  v20[5] = v12;
  v20[6] = v11;
  v20[7] = v10;
  v21 = 1;
  memset(&v20[9], 0, 12);
  v25 = 1;
  v24 = 0;
  v22 = 0;
  v23 = 0;
  v29 = 1;
  v28 = 0;
  v26 = 0;
  v27 = 0;
  v14 = *v10;
  v15 = this_1[2];
  v16 = *v13;
  LOBYTE(v37) = 1;
  v17 = (*(int (__thiscall **)(int *))(v14 + 32))(v10);
  this_2 = this_1;
  (*(void (__thiscall **)(int, int, int))(v16 + 4))(this_1[44], v15, v17);
  sub_A8DBE0(this_2[6], this_2, v20);
  sub_9BB660((int)v20);
  (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)this_2[44] + 12))(this_2[44], a2, this_2[21], this_2[19]);
  LOBYTE(v37) = 0;
  sub_9B6C10(v20);
  result = v33;
  v37 = -1;
  if ( v33 )
  {
    if ( v34 )
      return sub_9D4D50(v33);
  }
  return result;
}

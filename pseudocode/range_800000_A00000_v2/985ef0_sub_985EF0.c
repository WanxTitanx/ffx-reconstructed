// Function: sub_985EF0
// Address: 0x985ef0
int __thiscall sub_985EF0(_DWORD *this, int a2)
{
  int i; // esi
  _DWORD *v4; // ecx
  int v5; // edx
  int v6; // edi
  int j_1; // ecx
  int v8; // esi
  int v9; // ecx
  unsigned int v10; // eax
  int v11; // eax
  _BYTE v13[4]; // [esp+10h] [ebp-6Ch] BYREF
  unsigned int v14; // [esp+14h] [ebp-68h]
  int v15; // [esp+18h] [ebp-64h]
  int v16; // [esp+1Ch] [ebp-60h]
  char v17; // [esp+20h] [ebp-5Ch]
  int v18; // [esp+28h] [ebp-54h]
  int v19; // [esp+2Ch] [ebp-50h]
  int v20; // [esp+30h] [ebp-4Ch]
  char v21; // [esp+34h] [ebp-48h]
  int v22; // [esp+3Ch] [ebp-40h]
  int v23; // [esp+40h] [ebp-3Ch]
  int v24; // [esp+44h] [ebp-38h]
  char v25; // [esp+48h] [ebp-34h]
  int v26; // [esp+50h] [ebp-2Ch]
  int v27; // [esp+54h] [ebp-28h]
  int v28; // [esp+58h] [ebp-24h]
  char v29; // [esp+5Ch] [ebp-20h]
  int v30; // [esp+60h] [ebp-1Ch] BYREF
  int v31; // [esp+68h] [ebp-14h] BYREF
  int j; // [esp+6Ch] [ebp-10h]
  int v33; // [esp+78h] [ebp-4h]

  for ( i = 0; i < *(this + 2); ++i )
  {
    v4 = *(_DWORD **)(*(this + 4) + 4 * i);
    if ( v4[61] == 1 )
      (*(void (__thiscall **)(_DWORD *, int))(*v4 + 20))(v4, a2);
  }
  v5 = 0;
  v6 = 0;
  v17 = 1;
  v16 = 0;
  v14 = 0;
  v15 = 0;
  v21 = 1;
  v20 = 0;
  v18 = 0;
  v19 = 0;
  v25 = 1;
  v24 = 0;
  v22 = 0;
  v23 = 0;
  v29 = 1;
  v28 = 0;
  v26 = 0;
  v27 = 0;
  j_1 = 0;
  v33 = 0;
  for ( j = 0; j_1 < *(this + 2); j = j_1 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(*(this + 4) + 4 * j_1) + 204);
    v31 = v8;
    v9 = ((9 * (((v8 + ~(v8 << 15)) >> 10) ^ (v8 + ~(v8 << 15)))) >> 6)
       ^ (9 * (((v8 + ~(v8 << 15)) >> 10) ^ (v8 + ~(v8 << 15))));
    v10 = (((~(v9 << 11) + v9) >> 16) ^ (~(v9 << 11) + v9)) & (v23 - 1);
    if ( v10 >= v14 )
      goto LABEL_12;
    v11 = *(_DWORD *)(v16 + 4 * v10);
    if ( v11 == -1 )
      goto LABEL_12;
    while ( v8 != *(_DWORD *)(v6 + 8 * v11) )
    {
      v11 = *(_DWORD *)(v5 + 4 * v11);
      if ( v11 == -1 )
        goto LABEL_12;
    }
    if ( !(v24 + 4 * v11) )
    {
LABEL_12:
      v30 = v8;
      sub_982450((int)v13, &v30, &v31);
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v8 + 52))(v8, a2);
      v6 = v28;
      v5 = v20;
    }
    j_1 = j + 1;
  }
  v33 = -1;
  return sub_97C270();
}

// Function: sub_A3EED0
// Address: 0xa3eed0
// Size: 0x107
// Prototype: 

int __thiscall sub_A3EED0(_DWORD *this, int a2, _DWORD *a3, _DWORD *a4, int a5)
{
  _DWORD *this_1; // ebx
  _DWORD *v6; // ecx
  _DWORD *v7; // edi
  int *v8; // eax
  bool v9; // dl
  bool v10; // zf
  _DWORD *v11; // esi
  unsigned int v12; // ecx
  _DWORD *v13; // eax
  _DWORD *v14; // eax
  int v16; // [esp+0h] [ebp-2Ch] BYREF
  _DWORD *this_2; // [esp+10h] [ebp-1Ch]
  _DWORD *v18; // [esp+14h] [ebp-18h]
  int v19; // [esp+18h] [ebp-14h]
  int *v20; // [esp+1Ch] [ebp-10h]
  int v21; // [esp+28h] [ebp-4h]

  v20 = &v16;
  this_1 = this;
  this_2 = this;
  v6 = (_DWORD *)*this;
  v7 = a4;
  v8 = (int *)v6[1];
  v9 = 1;
  v10 = *((_BYTE *)v8 + 13) == 0;
  v21 = 0;
  v18 = v6;
  v11 = v6;
  LOBYTE(v19) = 1;
  if ( v10 )
  {
    v12 = *a4;
    do
    {
      v11 = v8;
      if ( (_BYTE)a3 )
        v9 = v8[4] >= v12;
      else
        v9 = v12 < v8[4];
      LOBYTE(v19) = v9;
      if ( v9 )
        v8 = (int *)*v8;
      else
        v8 = (int *)v8[2];
    }
    while ( !*((_BYTE *)v8 + 13) );
    v6 = v18;
    this_1 = this_2;
  }
  v13 = v11;
  a3 = v11;
  if ( v9 )
  {
    if ( v11 == (_DWORD *)*v6 )
    {
      v14 = sub_A3ECD0(this_1, &a3, 1, v11, (int)a4, a5);
LABEL_14:
      *(_DWORD *)a2 = *v14;
      *(_BYTE *)(a2 + 4) = 1;
      return a2;
    }
    sub_A3FF80(&a3);
    v13 = a3;
  }
  if ( v13[4] < *v7 )
  {
    v14 = sub_A3ECD0(this_1, &a4, v19, v11, (int)v7, a5);
    goto LABEL_14;
  }
  *(_DWORD *)a2 = v13;
  *(_BYTE *)(a2 + 4) = 0;
  return a2;
}


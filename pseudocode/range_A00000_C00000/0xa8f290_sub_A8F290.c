// Function: sub_A8F290
// Address: 0xa8f290
// Size: 0x225
// Prototype: 

int __fastcall sub_A8F290(int a1, int a2)
{
  _DWORD *v2; // edi
  int v5; // ebx
  _DWORD *v6; // eax
  _DWORD *v7; // ebx
  void (__cdecl *v8)(_DWORD, int); // eax
  _DWORD *v9; // ebx
  _DWORD *v10; // ebx
  _DWORD **v11; // ebx
  _DWORD *v13; // [esp+Ch] [ebp-4h]
  int v14; // [esp+Ch] [ebp-4h]
  int v15; // [esp+Ch] [ebp-4h]
  int v16; // [esp+Ch] [ebp-4h]
  int v17; // [esp+Ch] [ebp-4h]

  v2 = *(_DWORD **)(a2 + 28);
  if ( !v2 )
    return -129;
  sub_42E350(a1, 5, 8);
  sub_A90540(6);
  sub_42E350(a1, v2[6] - 1, 8);
  v5 = 0;
  if ( (int)v2[6] > 0 )
  {
    v6 = v2 + 456;
    v13 = v2 + 456;
    while ( !sub_A943E0(*v6, a1) )
    {
      ++v5;
      v6 = ++v13;
      if ( v5 >= v2[6] )
        goto LABEL_7;
    }
    return -1;
  }
LABEL_7:
  sub_42E350(a1, 0, 6);
  sub_42E350(a1, 0, 16);
  sub_42E350(a1, v2[4] - 1, 6);
  v14 = 0;
  if ( (int)v2[4] > 0 )
  {
    v7 = v2 + 200;
    do
    {
      sub_42E350(a1, *v7, 16);
      v8 = *(void (__cdecl **)(_DWORD, int))*(&off_B81500 + *v7);
      if ( !v8 )
        return -1;
      v8(v7[64], a1);
      ++v7;
    }
    while ( ++v14 < v2[4] );
  }
  sub_42E350(a1, v2[5] - 1, 6);
  v15 = 0;
  if ( (int)v2[5] > 0 )
  {
    v9 = v2 + 328;
    do
    {
      sub_42E350(a1, *v9, 16);
      (*(void (__cdecl **)(_DWORD, int))*(&off_B814F0 + *v9))(v9[64], a1);
      ++v15;
      ++v9;
    }
    while ( v15 < v2[5] );
  }
  sub_42E350(a1, v2[3] - 1, 6);
  v16 = 0;
  if ( (int)v2[3] > 0 )
  {
    v10 = v2 + 72;
    do
    {
      sub_42E350(a1, *v10, 16);
      (*(&off_B814FC)[*v10])(a2, v10[64], a1);
      ++v16;
      ++v10;
    }
    while ( v16 < v2[3] );
  }
  sub_42E350(a1, v2[2] - 1, 6);
  v17 = 0;
  if ( (int)v2[2] > 0 )
  {
    v11 = (_DWORD **)(v2 + 8);
    do
    {
      sub_42E350(a1, **v11, 1);
      sub_42E350(a1, (*v11)[1], 16);
      sub_42E350(a1, (*v11)[2], 16);
      sub_42E350(a1, (*v11)[3], 8);
      ++v17;
      ++v11;
    }
    while ( v17 < v2[2] );
  }
  sub_42E350(a1, 1, 1);
  return 0;
}


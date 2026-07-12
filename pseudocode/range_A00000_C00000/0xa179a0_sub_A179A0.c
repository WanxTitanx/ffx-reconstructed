// Function: sub_A179A0
// Address: 0xa179a0
// Size: 0x226
// Prototype: 

int __thiscall sub_A179A0(_DWORD *this, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // esi
  unsigned int v5; // ebx
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // esi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  int v12; // eax
  int v13; // esi
  bool v14; // zf
  int v15; // edi
  int v16; // eax
  int v17; // esi
  int n3; // [esp+18h] [ebp-1Ch]
  _DWORD *v20; // [esp+1Ch] [ebp-18h]
  unsigned int v21; // [esp+20h] [ebp-14h]

  v4 = a4 >> 2;
  v5 = a3 >> 2;
  v21 = a4 >> 2;
  v20 = this + 39;
  n3 = 3;
  do
  {
    v6 = (_DWORD *)sub_4410E0(1, (int)&unk_CA37D0, 0);
    v7 = v6;
    if ( v6
      && !sub_4C41C0(v6, v5, v4, (int)&unk_CA310C, 0)
      && (v7[5] &= ~2u, *((_BYTE *)v7 + 5) = 0, sub_4C4350(v7), (v8 = sub_440C40(1, (int)&unk_CA4200, 0)) != 0)
      && (v9 = *(_DWORD *)(v8 + 52)) != 0 )
    {
      sub_583BF0(v7);
      *(_BYTE *)(v9 + 5) = 0;
      *(_DWORD *)(v9 + 12) = "PPostProcessUtils";
    }
    else
    {
      v9 = 0;
    }
    *(v20 - 3) = v9;
    v10 = (_DWORD *)sub_4410E0(1, (int)&unk_CA37D0, 0);
    v11 = v10;
    if ( v10
      && !sub_4C41C0(v10, v5, v21, (int)&unk_CA310C, 0)
      && (v11[5] &= ~2u, *((_BYTE *)v11 + 5) = 0, sub_4C4350(v11), (v12 = sub_440C40(1, (int)&unk_CA4200, 0)) != 0)
      && (v13 = *(_DWORD *)(v12 + 52)) != 0 )
    {
      sub_583BF0(v11);
      *(_BYTE *)(v13 + 5) = 0;
      *(_DWORD *)(v13 + 12) = "PPostProcessUtils";
    }
    else
    {
      v13 = 0;
    }
    *v20 = v13;
    v4 = v21 >> 1;
    v5 >>= 1;
    v14 = n3-- == 1;
    v21 >>= 1;
    ++v20;
  }
  while ( !v14 );
  v15 = sub_4410E0(1, (int)&unk_CA37D0, 0);
  if ( v15
    && !sub_4C41C0((_DWORD *)v15, a3 >> 1, a4 >> 1, (int)&unk_CA310C, 0)
    && (*(_DWORD *)(v15 + 20) &= ~2u,
        *(_BYTE *)(v15 + 5) = 0,
        sub_4C4350(v15),
        (v16 = sub_440C40(1, (int)&unk_CA4200, 0)) != 0)
    && (v17 = *(_DWORD *)(v16 + 52)) != 0 )
  {
    sub_583BF0(v15);
    *(_BYTE *)(v17 + 5) = 0;
    *(_DWORD *)(v17 + 12) = "PPostProcessUtils";
    *(this + 42) = v17;
  }
  else
  {
    *(this + 42) = 0;
  }
  return 0;
}


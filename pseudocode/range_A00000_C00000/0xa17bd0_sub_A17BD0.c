// Function: sub_A17BD0
// Address: 0xa17bd0
// Size: 0x19c
// Prototype: 

int __thiscall sub_A17BD0(_DWORD *this, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v4; // ebx
  unsigned int v5; // esi
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // esi
  _DWORD *v10; // eax
  _DWORD *v11; // edi
  int v12; // eax
  int v13; // esi
  bool v14; // zf
  int n3; // [esp+18h] [ebp-10h]
  _DWORD *v17; // [esp+34h] [ebp+Ch]
  unsigned int v18; // [esp+38h] [ebp+10h]

  v4 = a3 >> 2;
  v5 = a4 >> 2;
  v18 = a4 >> 2;
  v17 = this + 33;
  n3 = 3;
  do
  {
    v6 = (_DWORD *)sub_4410E0(1, (int)&unk_CA37D0, 0);
    v7 = v6;
    if ( v6
      && !sub_4C41C0(v6, v4, v5, (int)&unk_CA310C, 0)
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
    *(v17 - 3) = v9;
    *(_DWORD *)(v9 + 12) = "PLegacyGlowGPUBase_glowX";
    v10 = (_DWORD *)sub_4410E0(1, (int)&unk_CA37D0, 0);
    v11 = v10;
    if ( v10
      && !sub_4C41C0(v10, v4, v18, (int)&unk_CA310C, 0)
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
    *v17 = v13;
    *(_DWORD *)(v13 + 12) = "PLegacyGlowGPUBase_glowY";
    v5 = v18 >> 1;
    v4 >>= 1;
    v14 = n3-- == 1;
    v18 >>= 1;
    ++v17;
  }
  while ( !v14 );
  return 0;
}


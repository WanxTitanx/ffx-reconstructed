// Function: sub_A0FE60
// Address: 0xa0fe60
// Size: 0xea
// Prototype: 

int __thiscall sub_A0FE60(_DWORD *this, unsigned int a2, unsigned int a3, int a4)
{
  int n2; // eax
  _DWORD *v5; // ebx
  _DWORD *v6; // eax
  _DWORD *v7; // edi
  int v8; // eax
  int v9; // esi
  int n2_1; // [esp+18h] [ebp-10h]

  n2 = 2;
  v5 = this + 2;
  n2_1 = 2;
  do
  {
    if ( !*v5 )
    {
      v6 = (_DWORD *)sub_4410E0(1, (int)&unk_CA37D0, 0);
      v7 = v6;
      if ( v6
        && !sub_4C41C0(v6, a2, a3, a4, 0)
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
      n2 = n2_1;
      *v5 = v9;
    }
    ++v5;
    n2_1 = --n2;
  }
  while ( n2 );
  return 0;
}


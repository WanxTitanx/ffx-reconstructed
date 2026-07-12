// Function: sub_A176D0
// Address: 0xa176d0
// Size: 0xa1
// Prototype: 

int __thiscall sub_A176D0(_DWORD *this, int a2, int a3, int a4)
{
  int n13; // eax
  int v7; // eax
  int v8; // esi
  bool v9; // zf
  int v10; // [esp+20h] [ebp+10h]

  n13 = sub_A1A190(a2, a3, a4);
  if ( !n13 )
  {
    v10 = sub_A0FF50(a3, a4, 7, 1.0);
    v7 = sub_4410E0(1, (int)&unk_CA37D0, 0);
    v8 = v7;
    if ( v7 )
    {
      if ( sub_4C41C0((_DWORD *)v7, a3, a4, (int)&unk_CA310C, 0) )
      {
        v7 = 0;
      }
      else
      {
        *(_DWORD *)(v8 + 20) &= ~2u;
        *(_BYTE *)(v8 + 5) = 0;
        sub_4C4350(v8);
        v7 = sub_64AFA0(v8);
        if ( v7 )
        {
          *(_BYTE *)(v7 + 5) = 0;
          *(_DWORD *)(v7 + 12) = "PPostProcessUtils";
        }
      }
    }
    *(this + 1004) = v7;
    v9 = v7 == 0;
    n13 = 13;
    if ( !v9 )
      return v10;
  }
  return n13;
}


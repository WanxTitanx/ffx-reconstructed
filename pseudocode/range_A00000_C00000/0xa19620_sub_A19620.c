// Function: sub_A19620
// Address: 0xa19620
// Size: 0x2ae
// Prototype: 

int __thiscall sub_A19620(_DWORD *this, int a2, _DWORD *a3)
{
  unsigned int v3; // edi
  unsigned int v4; // ebx
  int v6; // esi
  _DWORD *v7; // eax
  _DWORD *v8; // ecx
  int v9; // eax
  int n2__2; // ecx
  int n2__5; // eax
  _DWORD *v12; // eax
  int n2__6; // eax
  int n2__7; // eax
  int v15; // eax
  int v16; // eax
  int this_2; // edi
  int n2_; // [esp+10h] [ebp-34h] BYREF
  _DWORD *v19; // [esp+14h] [ebp-30h]
  int n2__9; // [esp+18h] [ebp-2Ch]
  int n2__8; // [esp+1Ch] [ebp-28h]
  int v22; // [esp+20h] [ebp-24h]
  int v23; // [esp+24h] [ebp-20h]
  int n2__3; // [esp+28h] [ebp-1Ch]
  int n2__4; // [esp+2Ch] [ebp-18h]
  int n2__1; // [esp+30h] [ebp-14h]
  _DWORD *this_1; // [esp+34h] [ebp-10h]
  int v28; // [esp+40h] [ebp-4h]

  this_1 = this;
  if ( (unk_C9628C[0] & 1) == 0 )
  {
    unk_C9628C[0] |= 1u;
    PhyreSingleton_RegisterAtExit(byte_C94F00);
    atexit(PhyreSingleton_AtExit_C94F00_Cleanup);
    this = this_1;
    v28 = -1;
  }
  v3 = a2;
  if ( !a2 )
    v3 = unk_C95100;
  v4 = (unsigned int)a3;
  if ( !a3 )
    v4 = unk_C95104;
  if ( *(this + 4021) )
    return 22;
  v6 = 0;
  n2_ = 0;
  v19 = 0;
  n2__9 = 0;
  n2__8 = 0;
  v22 = 0;
  v23 = 0;
  v7 = (_DWORD *)sub_4410E0(1, (int)&unk_CA37D0, 0);
  a3 = v7;
  if ( !v7 )
    goto LABEL_24;
  v6 = sub_4C41C0(v7, v3, v4, (int)&unk_CA310C, 0);
  a2 = v6;
  if ( v6 )
    goto LABEL_24;
  v8 = a3;
  a3[5] &= ~2u;
  *((_BYTE *)v8 + 5) = 0;
  sub_4C4350(v8);
  v9 = sub_440C40(1, (int)&unk_CA4200, 0);
  if ( !v9 )
    goto LABEL_24;
  n2__2 = *(_DWORD *)(v9 + 52);
  n2__1 = n2__2;
  n2__3 = n2__2;
  if ( !n2__2 )
    goto LABEL_24;
  n2__4 = n2__2;
  sub_583BF0(a3);
  n2__5 = n2__1;
  v28 = -1;
  *(_BYTE *)(n2__1 + 5) = 0;
  *(_DWORD *)(n2__5 + 12) = "PPostProcessUtils";
  v12 = (_DWORD *)sub_A06A30(&unk_1943DA0, v3, v4, &unk_CA3274, 0, 0, &a2);
  v6 = a2;
  a3 = v12;
  if ( !v12 )
    goto LABEL_24;
  if ( a2 )
    goto LABEL_24;
  n2__6 = sub_A06A30(&unk_1943DA0, v3, v4, &unk_CA310C, 0, 0, &a2);
  v6 = a2;
  n2__4 = n2__6;
  if ( !n2__6 )
    goto LABEL_24;
  if ( a2 )
    goto LABEL_24;
  n2__7 = sub_A06A30(&unk_1943DA0, v3, v4, &unk_CA310C, 0, 0, &a2);
  v6 = a2;
  n2__3 = n2__7;
  if ( !n2__7 )
    goto LABEL_24;
  if ( a2 )
    goto LABEL_24;
  v15 = sub_A06A30(&unk_1943DA0, v3, v4, &unk_CA310C, 0, 0, &a2);
  v6 = a2;
  if ( !v15 )
    goto LABEL_24;
  if ( !a2
    && (v22 = v15,
        n2_ = n2__1,
        v19 = a3,
        n2__8 = n2__4,
        n2__9 = n2__3,
        v16 = sub_A06A30(&unk_1943DA0, v3, v4, &unk_CA347C, 0, 0, &a2),
        v6 = a2,
        v16)
    && !a2 )
  {
    this_2 = (int)this_1;
    v23 = v16;
    v6 = sub_A191F0((int)this_1, v4, (int)this_1, (int)&unk_1943DA0, &n2_);
  }
  else
  {
LABEL_24:
    this_2 = (int)this_1;
  }
  if ( v6 )
    return v6;
  *(_BYTE *)(this_2 + 16) = 1;
  return 0;
}


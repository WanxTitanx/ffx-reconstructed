// Function: sub_9A1430
// Address: 0x9a1430
_DWORD *__thiscall sub_9A1430(_DWORD *this, int a2, int a3)
{
  _DWORD *this_1; // eax
  int v4; // edi
  _DWORD *v5; // esi
  int v6; // ecx
  int v7; // edx
  int v8; // esi
  _DWORD *v9; // eax
  int v10; // [esp-1Ch] [ebp-28h]
  int v11; // [esp-18h] [ebp-24h]
  int v12; // [esp-10h] [ebp-1Ch]
  int v13; // [esp-Ch] [ebp-18h]
  int v15; // [esp-4h] [ebp-10h]

  this_1 = this;
  v12 = 0;
  if ( (int)*(this + 2) > 0 )
  {
    v4 = 0;
    v13 = 0;
    do
    {
      v5 = (_DWORD *)(v4 + this_1[4]);
      if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD *))(*(_DWORD *)a2 + 4))(a2, v5) )
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD *, int))(*this + 28))(this, v5, a3);
        *v5 = 0;
        v5[1] = 0;
        v6 = *(this + 4);
        v7 = *(_DWORD *)(v4 + v6);
        v8 = *(_DWORD *)(v4 + v6 + 4);
        v11 = *(_DWORD *)(v4 + v6 + 8);
        v10 = *(_DWORD *)(v13 + v6 + 12);
        v15 = 16 * (*(this + 2) - 1);
        *(_DWORD *)(v13 + v6) = *(_DWORD *)(v6 + v15);
        *(_DWORD *)(v13 + v6 + 4) = *(_DWORD *)(v6 + v15 + 4);
        *(_DWORD *)(v13 + v6 + 8) = *(_DWORD *)(v6 + v15 + 8);
        *(_DWORD *)(v13 + v6 + 12) = *(_DWORD *)(v6 + v15 + 12);
        v9 = (_DWORD *)(v15 + *(this + 4));
        *v9 = v7;
        v9[1] = v8;
        v9[2] = v11;
        v4 = v13;
        v9[3] = v10;
        this_1 = this;
        --*(this + 2);
        --unk_193F640;
      }
      else
      {
        ++v12;
        this_1 = this;
        v4 += 16;
        v13 = v4;
      }
    }
    while ( v12 < this_1[2] );
  }
  return this_1;
}

// Function: sub_9A13D0
// Address: 0x9a13d0
void __thiscall sub_9A13D0(_DWORD *this, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  _DWORD *v6; // ebx
  int v7; // [esp+8h] [ebp-4h]

  v4 = 0;
  if ( (int)*(this + 2) > 0 )
  {
    v5 = 0;
    v7 = 0;
    do
    {
      v6 = (_DWORD *)(v5 + *(this + 4));
      if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD *))(*(_DWORD *)a2 + 4))(a2, v6) )
      {
        (*(void (__thiscall **)(_DWORD *, _DWORD, _DWORD, int))(*this + 8))(this, *v6, v6[1], a3);
        --unk_193F640;
        v5 = v7;
      }
      else
      {
        ++v4;
        v5 = v7 + 16;
        v7 += 16;
      }
    }
    while ( v4 < *(this + 2) );
  }
}

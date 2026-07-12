// Function: sub_9A0780
// Address: 0x9a0780
int __thiscall sub_9A0780(_DWORD *this, int a2, int a3)
{
  int v3; // ecx
  char v4; // al

  ++unk_193F638;
  v3 = *(this + 6);
  if ( v3 )
    v4 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)v3 + 4))(v3, a2, a3);
  else
    v4 = (*(_WORD *)(a2 + 4) & *(_WORD *)(a3 + 6)) != 0 && (*(_WORD *)(a2 + 6) & *(_WORD *)(a3 + 4)) != 0;
  if ( v4 )
    return sub_9A1080(a2, a3);
  else
    return 0;
}

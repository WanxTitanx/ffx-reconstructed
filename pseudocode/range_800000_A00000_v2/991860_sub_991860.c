// Function: sub_991860
// Address: 0x991860
void __thiscall sub_991860(_DWORD *this, int a2, _WORD *a3, _WORD *a4)
{
  int v5; // esi
  int v6; // ebx
  int v7; // eax

  v5 = 0;
  if ( (int)*(this + 41) > 0 )
  {
    v6 = 0;
    do
    {
      v7 = v6 + *(this + 43);
      if ( (*a4 >= *(_WORD *)v7
         && *(_WORD *)(v7 + 6) >= *a3
         && *(_WORD *)(v7 + 10) >= a3[2]
         && a4[1] >= *(_WORD *)(v7 + 2)
         && a4[2] >= *(_WORD *)(v7 + 4)
         && *(_WORD *)(v7 + 8) >= a3[1]
          ? -1
          : *a4 >= *(_WORD *)v7
         && *(_WORD *)(v7 + 6) >= *a3
         && *(_WORD *)(v7 + 10) >= a3[2]
         && a4[1] >= *(_WORD *)(v7 + 2)
         && a4[2] >= *(_WORD *)(v7 + 4)
         && *(_WORD *)(v7 + 8) >= a3[1]) < 0 )
        sub_990C40(this, a2, a3, a4, *(_DWORD *)(v7 + 12), *(_DWORD *)(v7 + 12) + *(_DWORD *)(v7 + 16));
      ++v5;
      v6 += 32;
    }
    while ( v5 < *(this + 41) );
  }
}

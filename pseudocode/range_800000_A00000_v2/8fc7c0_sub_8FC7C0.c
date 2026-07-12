// Function: sub_8FC7C0
// Address: 0x8fc7c0
void __cdecl sub_8FC7C0(int a1, int a2)
{
  int v2; // esi

  if ( *(_BYTE *)(a1 + 26) == 1 )
  {
    v2 = a2;
    sub_8FC870(a1, a2);
    sub_8FCAD0(a1, a2, 0);
  }
  else
  {
    if ( *(_BYTE *)(a1 + 26) != 3 )
    {
      sub_643CA0(1);
      sub_640F80(0);
      sub_8FCCA0(a1, a2, 0);
      sub_640F80(1);
      sub_8FCAD0(a1, a2, 0);
      sub_643CA0(0);
      sub_8E8ED0(a1, a2, 0.77999997);
      return;
    }
    v2 = a2;
    sub_8FCE90(a1, a2);
    sub_8FD0A0(a1, a2);
  }
  sub_8E8ED0(a1, v2, flt_C5D784);
}

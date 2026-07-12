// Function: sub_A10590
// Address: 0xa10590
// Size: 0x14a
// Prototype: 

int __thiscall sub_A10590(int *this, int a2, int a3)
{
  int v4; // esi
  int v5; // esi
  int v6; // esi
  int v7; // esi
  int v8; // esi
  int result; // eax
  int v10; // esi

  v4 = *(this + 4084);
  if ( v4 )
  {
    if ( (unsigned __int8)sub_596110(*(this + 4084)) )
      sub_59CBF0(v4);
    v5 = *(this + 4084);
    if ( v5 )
    {
      sub_501E30();
      Phyre_Memory_AlignedFree(v5);
    }
  }
  v6 = *(this + 4085);
  if ( v6 )
  {
    if ( (unsigned __int8)sub_596110(*(this + 4085)) )
      sub_59CBF0(v6);
    v7 = *(this + 4085);
    if ( v7 )
    {
      sub_501E30();
      Phyre_Memory_AlignedFree(v7);
    }
  }
  if ( !a2 || !a3 )
    return 0;
  v8 = sub_42FC20(72);
  if ( v8 )
    sub_584330();
  else
    v8 = 0;
  *(this + 4084) = v8;
  result = sub_58F440(a3 * a2, 8, 8, 0);
  if ( !result )
  {
    v10 = sub_42FC20(72);
    if ( v10 )
      sub_584330();
    else
      v10 = 0;
    *(this + 4085) = v10;
    result = sub_58F440(a3 * a2, 8, 8, 0);
    if ( !result )
      return 0;
  }
  return result;
}


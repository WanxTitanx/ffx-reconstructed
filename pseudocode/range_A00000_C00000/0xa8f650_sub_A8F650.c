// Function: sub_A8F650
// Address: 0xa8f650
// Size: 0x11b
// Prototype: _DWORD __cdecl(int, _DWORD *, int *this)

int __cdecl sub_A8F650(int a1, _DWORD *a2, int *this)
{
  int v3; // eax
  int v4; // esi
  int v5; // esi
  int n2; // esi
  int v7; // eax
  __int64 v9; // [esp+4h] [ebp-1Ch] BYREF
  int v10; // [esp+Ch] [ebp-14h]
  int v11; // [esp+10h] [ebp-10h]
  int v12; // [esp+14h] [ebp-Ch]
  int n1651666806; // [esp+18h] [ebp-8h]
  __int16 n29545; // [esp+1Ch] [ebp-4h]

  if ( !this )
    return -133;
  v11 = *this;
  v10 = v11;
  v3 = *(this + 1);
  v9 = 0;
  v12 = v3;
  v4 = sub_42EB10(&v9, 8);
  n1651666806 = 0;
  n29545 = 0;
  sub_A90440(6);
  if ( n1651666806 != 1651666806 || n29545 != 29545 )
    return -132;
  v5 = v4 - 1;
  if ( v5 )
  {
    n2 = v5 - 2;
    if ( n2 )
    {
      if ( n2 == 2 && *(_DWORD *)(a1 + 8) && a2[3] )
      {
        v7 = *(_DWORD *)(a1 + 28);
        if ( !v7 )
          return -129;
        if ( *(int *)(v7 + 24) <= 0 )
          return sub_A8F7F0();
      }
    }
    else if ( *(_DWORD *)(a1 + 8) && !a2[3] )
    {
      return sub_A8FAC0();
    }
    return -133;
  }
  if ( !*(this + 2) || *(_DWORD *)(a1 + 8) )
    return -133;
  return sub_A8FC80() + 7;
}


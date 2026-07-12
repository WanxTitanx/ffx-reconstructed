// Function: sub_A045D0
// Address: 0xa045d0
// Size: 0x17b
// Prototype: int __cdecl(int, int, float, char)

int __cdecl sub_A045D0(int *a1, int a2, float a3, char a4)
{
  int v4; // ebx
  int v6; // [esp+18h] [ebp-13Ch]
  _BYTE v7[4]; // [esp+1Ch] [ebp-138h] BYREF
  int v8; // [esp+20h] [ebp-134h]
  _BYTE v9[4]; // [esp+B0h] [ebp-A4h] BYREF
  int v10; // [esp+B4h] [ebp-A0h]
  int v11; // [esp+150h] [ebp-4h]

  if ( *(_DWORD *)(*(_DWORD *)a2 + 8) != 12
    || *(_DWORD *)(a2 + 28) != a1[7]
    || *(_DWORD *)(a2 + 32) != a1[8]
    || *(_DWORD *)(a2 + 36) != a1[9] )
  {
    return 5;
  }
  sub_583600(v9);
  v11 = 0;
  v4 = sub_A1B300(v9);
  if ( !v4 )
  {
    v6 = v10;
    if ( v10 )
    {
      sub_583600(v7);
      LOBYTE(v11) = 1;
      v4 = sub_A1B390(v7);
      if ( v4 || !v8 )
      {
        if ( !sub_59DCE0(*(_DWORD *)(a2 + 8), v9) )
          *(_BYTE *)(a2 + 4) = 0;
      }
      else
      {
        v4 = sub_A04920(v8, v6, *(_DWORD *)(a2 + 28), *(_DWORD *)(a2 + 32), *(_DWORD *)(a2 + 36), *a1, a3, a4);
        if ( !sub_59DCE0(*(_DWORD *)(a2 + 8), v9) )
          *(_BYTE *)(a2 + 4) = 0;
        sub_A250A0(v7);
      }
      LOBYTE(v11) = 0;
      nullsub_20(v7);
    }
  }
  v11 = -1;
  nullsub_20(v9);
  return v4;
}


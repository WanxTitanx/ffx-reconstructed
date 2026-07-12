// Function: sub_9BABF0
// Address: 0x9babf0
int __usercall sub_9BABF0@<eax>(int *a1@<ecx>, _BYTE *a2@<ebp>, int a3@<edi>)
{
  int v4; // eax
  int i; // edi
  int v6; // eax
  int result; // eax
  int v8; // eax
  int v9; // eax
  int j; // edi
  int v11; // ecx

  sub_981B80(a1, (int)a2, a3, (int)a1);
  if ( (*(int (__thiscall **)(int *))(*a1 + 12))(a1) )
  {
    v4 = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
    if ( ((*(int (__thiscall **)(int))(*(_DWORD *)v4 + 44))(v4) & 0x1800) != 0 )
    {
      for ( i = (*(int (__thiscall **)(int *))(*a1 + 92))(a1) - 1; i >= 0; --i )
      {
        v6 = (*(int (__thiscall **)(int *, int))(*a1 + 100))(a1, i);
        sub_9B7E00(a1, a2, i, (int)a1, v6);
      }
    }
  }
  result = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
  if ( result )
  {
    v8 = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
    result = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 44))(v8);
    if ( (result & 3) != 0 )
    {
      result = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
      if ( result )
      {
        v9 = (*(int (__thiscall **)(int *))(*a1 + 12))(a1);
        result = (*(int (__thiscall **)(int))(*(_DWORD *)v9 + 44))(v9);
        if ( result )
        {
          for ( j = 0; j < a1[63]; ++j )
          {
            v11 = *(_DWORD *)(a1[65] + 4 * j);
            result = (*(int (__thiscall **)(int, int))(*(_DWORD *)v11 + 8))(v11, a1[21]);
          }
        }
      }
    }
  }
  return result;
}

// Function: sub_98AAE0
// Address: 0x98aae0
int __thiscall sub_98AAE0(int *this, int a2)
{
  int *this_1; // ebx
  int v3; // edi
  int v4; // esi
  int i_2; // ecx
  int i; // edi
  int *this_3; // ebx
  int v8; // esi
  int i_4; // eax
  int v10; // ebx
  int i_5; // esi
  int i_7; // eax
  int i_8; // eax
  int result; // eax
  char v15[4]; // [esp+10h] [ebp-2Ch] BYREF
  int i_1; // [esp+14h] [ebp-28h]
  int v17; // [esp+18h] [ebp-24h]
  int v18; // [esp+1Ch] [ebp-20h]
  char v19; // [esp+20h] [ebp-1Ch]
  int i_6; // [esp+24h] [ebp-18h]
  int *this_2; // [esp+28h] [ebp-14h]
  int i_3; // [esp+2Ch] [ebp-10h]
  int v23; // [esp+38h] [ebp-4h]

  this_1 = this;
  this_2 = this;
  v19 = 1;
  v18 = 0;
  i_1 = 0;
  v17 = 0;
  v3 = 2 * *(this + 3);
  v23 = 0;
  if ( v3 > 0 )
  {
    v18 = sub_9D4CE0(4 * v3, 16);
    this_1 = this_2;
    v19 = 1;
    v17 = v3;
  }
  v4 = *this_1;
  sub_987C00((int)v15, *this_1);
  if ( *(_DWORD *)(v4 + 40) )
  {
    sub_987660(*(_DWORD *)(v4 + 36), (int)v15);
    sub_987660(*(_DWORD *)(v4 + 40), (int)v15);
  }
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 4))(a2, *this_1, i_1);
  i_2 = i_1;
  for ( i = 0; i < i_1; ++i )
  {
    i_3 = -1;
    this_3 = *(int **)(v18 + 4 * i);
    this_2 = this_3;
    v8 = this_3[8];
    if ( v8 )
    {
      i_4 = 0;
      i_3 = i_2;
      if ( i_2 > 0 )
      {
        while ( *(_DWORD *)(v18 + 4 * i_4) != v8 )
        {
          if ( ++i_4 >= i_2 )
            goto LABEL_12;
        }
        i_3 = i_4;
      }
    }
LABEL_12:
    v10 = this_3[10];
    if ( v10 )
    {
      i_5 = i_2;
      i_7 = 0;
      i_6 = i_2;
      if ( i_2 > 0 )
      {
        while ( *(_DWORD *)(v18 + 4 * i_7) != *(_DWORD *)(*(_DWORD *)(v18 + 4 * i) + 36) )
        {
          if ( ++i_7 >= i_2 )
          {
            i_5 = i_6;
            goto LABEL_18;
          }
        }
        i_5 = i_7;
      }
LABEL_18:
      i_8 = 0;
      if ( i_2 > 0 )
      {
        while ( *(_DWORD *)(v18 + 4 * i_8) != v10 )
        {
          if ( ++i_8 >= i_2 )
            goto LABEL_23;
        }
        i_2 = i_8;
      }
LABEL_23:
      (*(void (__thiscall **)(int, int *, int, int, int, int))(*(_DWORD *)a2 + 8))(a2, this_2, i, i_3, i_5, i_2);
    }
    else
    {
      (*(void (__thiscall **)(int, int *, int, int))(*(_DWORD *)a2 + 12))(a2, this_2, i, i_3);
    }
    i_2 = i_1;
  }
  result = v18;
  v23 = -1;
  if ( v18 )
  {
    if ( v19 )
      return sub_9D4D50(v18);
  }
  return result;
}

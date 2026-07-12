// Function: sub_A69FE0
// Address: 0xa69fe0
// Size: 0xd7
// Prototype: _DWORD __cdecl(int, unsigned __int16 *i)

int __cdecl sub_A69FE0(unsigned __int16 *a1, unsigned __int16 *i)
{
  unsigned __int16 *v3; // esi
  int v4; // edx
  __int16 *v5; // ecx
  unsigned __int16 *v6; // esi
  int v7; // edx
  __int16 *v8; // ecx
  unsigned __int16 *v9; // edi
  int v10; // edx
  __int16 *v11; // ecx
  int result; // eax
  __int16 v13; // [esp+Ch] [ebp-4h]
  __int16 v14; // [esp+Ch] [ebp-4h]
  int v15; // [esp+18h] [ebp+8h]
  int v16; // [esp+18h] [ebp+8h]

  v3 = &i[32 * *a1];
  v4 = 0;
  v13 = *v3;
  v5 = (__int16 *)(v3 + 1);
  if ( (__int16)*v3 <= 0 )
  {
LABEL_5:
    *v5 = a1[10];
    *v3 = v13 + 1;
  }
  else
  {
    v15 = a1[10];
    while ( *v5 != v15 )
    {
      ++v4;
      ++v5;
      if ( v4 >= (__int16)*v3 )
        goto LABEL_5;
    }
  }
  v6 = &i[32 * a1[1]];
  v7 = 0;
  v14 = *v6;
  v8 = (__int16 *)(v6 + 1);
  if ( (__int16)*v6 <= 0 )
  {
LABEL_9:
    *v8 = a1[11];
    *v6 = v14 + 1;
  }
  else
  {
    while ( *v8 != a1[11] )
    {
      ++v7;
      ++v8;
      if ( v7 >= (__int16)*v6 )
        goto LABEL_9;
    }
  }
  v9 = &i[32 * a1[2]];
  v10 = 0;
  v16 = *v9;
  v11 = (__int16 *)(v9 + 1);
  if ( (__int16)*v9 <= 0 )
  {
LABEL_13:
    *v11 = a1[12];
    *v9 = v16 + 1;
    return v16 + 1;
  }
  else
  {
    while ( 1 )
    {
      result = *v11;
      if ( result == a1[12] )
        break;
      ++v10;
      ++v11;
      if ( v10 >= (__int16)*v9 )
        goto LABEL_13;
    }
  }
  return result;
}


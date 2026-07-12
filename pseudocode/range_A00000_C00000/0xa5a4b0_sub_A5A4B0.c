// Function: sub_A5A4B0
// Address: 0xa5a4b0
// Size: 0x18d
// Prototype: int(void)

int sub_A5A4B0()
{
  int v0; // edi
  int i; // esi
  int v2; // ecx
  int v3; // eax
  float *v4; // ebx
  int n7_3; // esi
  float *v6; // edi
  int v7; // edx
  int n7_2; // ecx
  int result; // eax
  float *v10; // ebx
  int n7_1; // esi
  float *v12; // edi
  int v13; // [esp+Ch] [ebp-80h]
  int v14; // [esp+Ch] [ebp-80h]
  int v15; // [esp+10h] [ebp-7Ch]
  int n7_4; // [esp+10h] [ebp-7Ch]
  int n7; // [esp+14h] [ebp-78h]
  int v18; // [esp+14h] [ebp-78h]
  _BYTE v19[112]; // [esp+18h] [ebp-74h] BYREF

  v0 = 0;
  for ( i = 0; i < 560; i += 80 )
  {
    *(_BYTE *)(i + dword_2305834[0] + 69846) = 0;
    sub_A58080(v0++);
  }
  v2 = dword_2305834[0];
  n7 = 0;
  v3 = *(unsigned __int8 *)(dword_2305834[0] + 71100);
  v15 = v3;
  v4 = (float *)v19;
  while ( 2 )
  {
    v13 = v2 + 80 * v3 + 69768;
    sub_A482D0(v13, v4);
LABEL_5:
    n7_3 = 0;
    v6 = (float *)v19;
    while ( n7_3 < n7 )
    {
      if ( sub_A49270(v4, v6) )
      {
        ++*(_BYTE *)(v13 + 78);
        sub_A58080(v15);
        sub_A482D0(v13, v4);
        if ( *(_BYTE *)(v13 + 78) < 7u )
          goto LABEL_5;
        break;
      }
      ++n7_3;
      v6 += 4;
    }
    v4 += 4;
    ++n7;
    v3 = v15 + 1 > 6 ? 0 : v15 + 1;
    v15 = v3;
    if ( n7 < 7 )
    {
      v2 = dword_2305834[0];
      continue;
    }
    break;
  }
  v7 = dword_2305834[0];
  n7_2 = 0;
  result = *(unsigned __int8 *)(dword_2305834[0] + 71100);
  v18 = result;
  n7_4 = 0;
  v10 = (float *)v19;
  while ( 2 )
  {
    v14 = v7 + 80 * result + 69768;
LABEL_14:
    n7_1 = 0;
    v12 = (float *)v19;
    while ( n7_1 < 7 )
    {
      if ( n7_2 != n7_1 )
      {
        if ( sub_A49270(v10, v12) )
        {
          ++*(_BYTE *)(v14 + 78);
          sub_A58080(v18);
          sub_A482D0(v14, v10);
          n7_2 = n7_4;
          if ( *(_BYTE *)(v14 + 78) < 7u )
            goto LABEL_14;
          break;
        }
        n7_2 = n7_4;
      }
      ++n7_1;
      v12 += 4;
    }
    ++n7_2;
    v10 += 4;
    n7_4 = n7_2;
    result = v18 + 1 > 6 ? 0 : v18 + 1;
    v18 = result;
    if ( n7_2 < 7 )
    {
      v7 = dword_2305834[0];
      continue;
    }
    return result;
  }
}


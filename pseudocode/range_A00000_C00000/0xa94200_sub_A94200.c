// Function: sub_A94200
// Address: 0xa94200
// Size: 0x11a
// Prototype: int __fastcall(_DWORD, _DWORD)

int __fastcall sub_A94200(_DWORD *a1, int a2)
{
  int v3; // ebx
  int v4; // esi
  int v5; // eax
  int v6; // ecx
  int v7; // edi
  int v8; // eax
  int v10; // eax
  int v11; // eax
  int v12; // edx
  unsigned int v13; // ecx
  int v14; // ebx
  int v15; // edx
  int v16; // ecx
  int v17; // eax
  int v18; // edx
  int v20; // [esp+10h] [ebp-10h]
  int v21; // [esp+14h] [ebp-Ch]
  int v22; // [esp+18h] [ebp-8h]
  int v23; // [esp+18h] [ebp-8h]

  v3 = a2;
  v4 = a1[10];
  v21 = v4;
  v5 = sub_42E840(a2, a1[9]);
  if ( v5 < 0 )
  {
    v7 = 0;
    v8 = a1[2];
  }
  else
  {
    v6 = *(_DWORD *)(a1[8] + 4 * v5);
    v22 = v6;
    if ( v6 >= 0 )
    {
      sub_42EA30(v3, *(char *)(a1[7] + v6 - 1));
      return v22 - 1;
    }
    v7 = (v6 >> 15) & 0x7FFF;
    v8 = a1[2] - (v6 & 0x7FFF);
  }
  v23 = v8;
  v10 = sub_42E840(v3, v4);
  if ( v10 >= 0 )
  {
LABEL_9:
    v11 = sub_A94320(v10);
    v12 = v23 - v7;
    v13 = v11;
    v20 = v11;
    if ( v23 - v7 > 1 )
    {
      v14 = v23;
      do
      {
        v15 = v12 >> 1;
        v16 = v13 < *(_DWORD *)(a1[5] + 4 * (v15 + v7));
        v17 = v15 & (v16 - 1);
        v14 -= v15 & -v16;
        v13 = v20;
        v7 += v17;
        v12 = v14 - v7;
      }
      while ( v14 - v7 > 1 );
      v4 = v21;
      v3 = a2;
    }
    v18 = *(char *)(a1[7] + v7);
    if ( v18 <= v4 )
    {
      sub_42EA30(v3, v18);
      return v7;
    }
    sub_42EA30(v3, v4);
  }
  else
  {
    while ( v4 > 1 )
    {
      v21 = --v4;
      v10 = sub_42E840(v3, v4);
      if ( v10 >= 0 )
        goto LABEL_9;
    }
  }
  return -1;
}


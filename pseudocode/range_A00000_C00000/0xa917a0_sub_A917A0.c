// Function: sub_A917A0
// Address: 0xa917a0
// Size: 0x2cf
// Prototype: int __cdecl(void *)

void __cdecl sub_A917A0(void **a1)
{
  void **v1; // ebx
  _DWORD *v2; // eax
  _DWORD *v3; // edi
  char *v4; // esi
  _DWORD *v5; // ecx
  _DWORD *v6; // ecx
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  _QWORD *v10; // eax
  int v11; // edi
  int v12; // [esp+8h] [ebp-8h]
  _DWORD *v13; // [esp+Ch] [ebp-4h]

  v1 = a1;
  if ( a1 )
  {
    v2 = a1[1];
    v13 = v2;
    if ( v2 )
      v3 = (_DWORD *)v2[7];
    else
      v3 = 0;
    v4 = (char *)a1[26];
    if ( v4 )
    {
      if ( *(_DWORD *)v4 )
      {
        sub_A9B7A0(*(void **)v4);
        free_1(*(void **)v4);
      }
      v5 = (_DWORD *)*((_DWORD *)v4 + 3);
      if ( v5 )
      {
        sub_A9D640(*v5);
        free_1(**((void ***)v4 + 3));
        free_1(*((void **)v4 + 3));
      }
      v6 = (_DWORD *)*((_DWORD *)v4 + 4);
      if ( v6 )
      {
        sub_A9D640(*v6);
        free_1(**((void ***)v4 + 4));
        free_1(*((void **)v4 + 4));
      }
      if ( *((_DWORD *)v4 + 12) )
      {
        if ( v3 && (int)v3[4] > 0 )
        {
          v7 = 0;
          do
          {
            (*((void (__cdecl **)(_DWORD))*(&off_B81500 + v3[v7 + 200]) + 4))(*(_DWORD *)(*((_DWORD *)v4 + 12) + 4 * v7));
            ++v7;
          }
          while ( v7 < v3[4] );
          v1 = a1;
        }
        free_1(*((void **)v4 + 12));
      }
      if ( *((_DWORD *)v4 + 13) )
      {
        if ( v3 && (int)v3[5] > 0 )
        {
          v8 = 0;
          do
          {
            (*((void (__cdecl **)(_DWORD))*(&off_B814F0 + v3[v8 + 328]) + 4))(*(_DWORD *)(*((_DWORD *)v4 + 13) + 4 * v8));
            ++v8;
          }
          while ( v8 < v3[5] );
          v1 = a1;
        }
        free_1(*((void **)v4 + 13));
      }
      if ( *((_DWORD *)v4 + 14) )
      {
        if ( v3 )
        {
          v12 = 0;
          if ( (int)v3[7] > 0 )
          {
            v9 = 0;
            do
            {
              sub_A97330((void *)(v9 + *((_DWORD *)v4 + 14)));
              v9 += 52;
              ++v12;
            }
            while ( v12 < v3[7] );
            v1 = a1;
          }
        }
        free_1(*((void **)v4 + 14));
      }
      v10 = (_QWORD *)*((_DWORD *)v4 + 15);
      if ( v10 )
      {
        *v10 = 0;
        v10[1] = 0;
        v10[2] = 0;
        v10[3] = 0;
        *((_DWORD *)v10 + 8) = 0;
        free_1(v10);
      }
      memset(v4 + 80, 0, 0x30u);
      if ( v4 != (char *)-20 )
      {
        if ( *((_DWORD *)v4 + 6) )
          free_1(*((void **)v4 + 6));
        if ( *((_DWORD *)v4 + 7) )
          free_1(*((void **)v4 + 7));
        *(_QWORD *)(v4 + 20) = 0;
        *((_DWORD *)v4 + 7) = 0;
      }
      if ( v4 != (char *)-32 )
      {
        if ( *((_DWORD *)v4 + 9) )
          free_1(*((void **)v4 + 9));
        if ( *((_DWORD *)v4 + 10) )
          free_1(*((void **)v4 + 10));
        *((_QWORD *)v4 + 4) = 0;
        *((_DWORD *)v4 + 10) = 0;
      }
      v2 = v13;
    }
    if ( v1[2] )
    {
      if ( v2 )
      {
        v11 = 0;
        if ( (int)v2[1] > 0 )
        {
          do
          {
            if ( *((_DWORD *)v1[2] + v11) )
              free_1(*((void **)v1[2] + v11));
            ++v11;
          }
          while ( v11 < v13[1] );
        }
      }
      free_1(v1[2]);
      if ( v1[3] )
        free_1(v1[3]);
    }
    if ( v4 )
    {
      if ( *((_DWORD *)v4 + 16) )
        free_1(*((void **)v4 + 16));
      if ( *((_DWORD *)v4 + 17) )
        free_1(*((void **)v4 + 17));
      if ( *((_DWORD *)v4 + 18) )
        free_1(*((void **)v4 + 18));
      free_1(v4);
    }
    memset(v1, 0, 0x70u);
  }
}


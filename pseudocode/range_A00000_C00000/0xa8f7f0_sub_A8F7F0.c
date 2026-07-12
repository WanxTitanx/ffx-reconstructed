// Function: sub_A8F7F0
// Address: 0xa8f7f0
// Size: 0x2cc
// Prototype: int(void)

int __fastcall sub_A8F7F0(int a1, int a2)
{
  _DWORD *v3; // edi
  int v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int *v9; // ebx
  unsigned int v10; // eax
  int v11; // eax
  int v12; // eax
  int *v13; // ebx
  unsigned int n2; // eax
  int v15; // eax
  int v16; // eax
  int *v17; // ebx
  int v18; // eax
  int v19; // eax
  int v20; // eax
  _DWORD *i; // ebx
  _QWORD *v22; // eax
  int v23; // eax
  int v24; // eax
  int *v26; // [esp+Ch] [ebp-8h]
  int v27; // [esp+Ch] [ebp-8h]
  int v28; // [esp+Ch] [ebp-8h]
  int v29; // [esp+Ch] [ebp-8h]
  int v30; // [esp+Ch] [ebp-8h]
  int v31; // [esp+Ch] [ebp-8h]

  v3 = *(_DWORD **)(a1 + 28);
  v4 = sub_42EB10(a2, 8) + 1;
  v3[6] = v4;
  if ( v4 > 0 )
  {
    v5 = 0;
    v26 = v3 + 456;
    while ( 1 )
    {
      v6 = sub_A946E0(a2);
      *v26 = v6;
      if ( !v6 )
        break;
      ++v5;
      ++v26;
      if ( v5 >= v3[6] )
      {
        v27 = sub_42EB10(a2, 6) + 1;
        if ( v27 > 0 )
        {
          v7 = 0;
          while ( !sub_42EB10(a2, 16) )
          {
            if ( ++v7 >= v27 )
            {
              v8 = sub_42EB10(a2, 6) + 1;
              v3[4] = v8;
              if ( v8 > 0 )
              {
                v28 = 0;
                v9 = v3 + 264;
                while ( 1 )
                {
                  v10 = sub_42EB10(a2, 16);
                  *(v9 - 64) = v10;
                  if ( v10 > 1 )
                    break;
                  v11 = (*((int (__cdecl **)(int, int))*(&off_B81500 + v10) + 1))(a1, a2);
                  *v9 = v11;
                  if ( !v11 )
                    break;
                  ++v9;
                  if ( ++v28 >= v3[4] )
                  {
                    v12 = sub_42EB10(a2, 6) + 1;
                    v3[5] = v12;
                    if ( v12 > 0 )
                    {
                      v29 = 0;
                      v13 = v3 + 392;
                      while ( 1 )
                      {
                        n2 = sub_42EB10(a2, 16);
                        *(v13 - 64) = n2;
                        if ( n2 > 2 )
                          break;
                        v15 = (*((int (__cdecl **)(int, int))*(&off_B814F0 + n2) + 1))(a1, a2);
                        *v13 = v15;
                        if ( !v15 )
                          break;
                        ++v13;
                        if ( ++v29 >= v3[5] )
                        {
                          v16 = sub_42EB10(a2, 6) + 1;
                          v3[3] = v16;
                          if ( v16 > 0 )
                          {
                            v30 = 0;
                            v17 = v3 + 136;
                            while ( 1 )
                            {
                              v18 = sub_42EB10(a2, 16);
                              *(v17 - 64) = v18;
                              if ( v18 )
                                break;
                              v19 = sub_AA15F0(a1, a2);
                              *v17 = v19;
                              if ( !v19 )
                                break;
                              ++v17;
                              if ( ++v30 >= v3[3] )
                              {
                                v20 = sub_42EB10(a2, 6) + 1;
                                v3[2] = v20;
                                if ( v20 > 0 )
                                {
                                  v31 = 0;
                                  for ( i = v3 + 8; ; ++i )
                                  {
                                    v22 = calloc_0(1u, 0x10u);
                                    *v22 = 0;
                                    v22[1] = 0;
                                    *i = v22;
                                    *(_DWORD *)*i = sub_42EB10(a2, 1);
                                    *(_DWORD *)(*i + 4) = sub_42EB10(a2, 16);
                                    *(_DWORD *)(*i + 8) = sub_42EB10(a2, 16);
                                    *(_DWORD *)(*i + 12) = sub_42EB10(a2, 8);
                                    v23 = *i;
                                    if ( *(int *)(*i + 4) >= 1 )
                                      break;
                                    if ( *(int *)(v23 + 8) >= 1 )
                                      break;
                                    v24 = *(_DWORD *)(v23 + 12);
                                    if ( v24 >= v3[3] || v24 < 0 )
                                      break;
                                    if ( ++v31 >= v3[2] )
                                      return 0;
                                  }
                                }
                                goto LABEL_32;
                              }
                            }
                          }
                          goto LABEL_32;
                        }
                      }
                    }
                    goto LABEL_32;
                  }
                }
              }
              goto LABEL_32;
            }
          }
        }
        break;
      }
    }
  }
LABEL_32:
  sub_A8FD80(a1);
  return -133;
}


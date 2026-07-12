// Function: sub_AA15F0
// Address: 0xaa15f0
// Size: 0x235
// Prototype: 

int *__cdecl sub_AA15F0(int a1, int a2)
{
  int *v2; // esi
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v7; // eax
  int v8; // eax
  int v9; // edx
  unsigned int v10; // eax
  int v11; // edi
  int v12; // edx
  unsigned int v13; // ecx
  int v14; // eax
  int v15; // ecx
  int v16; // edi
  int *v17; // ebx
  int v18; // eax
  int v19; // ebx
  int *i; // edi
  int v21; // eax
  int v22; // eax
  int v23; // [esp+Ch] [ebp-Ch]
  int v24; // [esp+10h] [ebp-8h]
  int *v25; // [esp+14h] [ebp-4h]

  v2 = (int *)calloc_0(1u, 0xC88u);
  memset(v2, 0, 0xC88u);
  v3 = a1;
  v23 = *(_DWORD *)(a1 + 28);
  memset(v2, 0, 0xC88u);
  if ( *(int *)(a1 + 4) > 0 )
  {
    v4 = sub_42EB10(a2, 1);
    if ( v4 >= 0 )
    {
      if ( v4 )
      {
        v5 = sub_42EB10(a2, 4) + 1;
        *v2 = v5;
        if ( v5 <= 0 )
          goto LABEL_5;
      }
      else
      {
        *v2 = 1;
      }
      v7 = sub_42EB10(a2, 1);
      if ( v7 >= 0 )
      {
        if ( v7 )
        {
          v8 = sub_42EB10(a2, 8) + 1;
          v2[289] = v8;
          if ( v8 > 0 )
          {
            v24 = 0;
            v25 = v2 + 546;
            while ( 1 )
            {
              v9 = 0;
              v10 = *(_DWORD *)(v3 + 4) - 1;
              if ( *(_DWORD *)(v3 + 4) != 1 )
              {
                do
                {
                  ++v9;
                  v10 >>= 1;
                }
                while ( v10 );
              }
              v11 = sub_42EB10(a2, v9);
              v12 = 0;
              *(v25 - 256) = v11;
              v13 = *(_DWORD *)(a1 + 4) - 1;
              if ( *(_DWORD *)(a1 + 4) != 1 )
              {
                do
                {
                  ++v12;
                  v13 >>= 1;
                }
                while ( v13 );
              }
              v14 = sub_42EB10(a2, v12);
              *v25 = v14;
              if ( v11 < 0 )
                break;
              if ( v14 < 0 )
                break;
              if ( v11 == v14 )
                break;
              v15 = *(_DWORD *)(a1 + 4);
              if ( v11 >= v15 || v14 >= v15 )
                break;
              ++v24;
              ++v25;
              if ( v24 >= v2[289] )
                goto LABEL_24;
              v3 = a1;
            }
          }
        }
        else
        {
LABEL_24:
          if ( !sub_42EB10(a2, 2) )
          {
            if ( *v2 <= 1 || (v16 = 0, *(int *)(a1 + 4) <= 0) )
            {
LABEL_31:
              v19 = 0;
              if ( *v2 <= 0 )
                return v2;
              for ( i = v2 + 273; ; ++i )
              {
                sub_42EB10(a2, 8);
                v21 = sub_42EB10(a2, 8);
                *(i - 16) = v21;
                if ( v21 >= *(_DWORD *)(v23 + 16) )
                  break;
                if ( v21 < 0 )
                  break;
                v22 = sub_42EB10(a2, 8);
                *i = v22;
                if ( v22 >= *(_DWORD *)(v23 + 20) || v22 < 0 )
                  break;
                if ( ++v19 >= *v2 )
                  return v2;
              }
            }
            else
            {
              v17 = v2 + 1;
              while ( 1 )
              {
                v18 = sub_42EB10(a2, 4);
                *v17 = v18;
                if ( v18 >= *v2 || v18 < 0 )
                  break;
                ++v16;
                ++v17;
                if ( v16 >= *(_DWORD *)(a1 + 4) )
                  goto LABEL_31;
              }
            }
          }
        }
      }
    }
  }
LABEL_5:
  if ( v2 )
  {
    memset(v2, 0, 0xC88u);
    free_1(v2);
  }
  return 0;
}


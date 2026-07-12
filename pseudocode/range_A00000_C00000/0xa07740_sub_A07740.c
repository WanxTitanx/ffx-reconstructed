// Function: sub_A07740
// Address: 0xa07740
// Size: 0x8a
// Prototype: int __cdecl(void *, int, size_t Size, int, int)

int __cdecl sub_A07740(char *a1, int a2, size_t Size, int a4, int a5)
{
  _DWORD *v5; // esi
  int result; // eax
  _DWORD *v7; // edi
  char *v8; // esi
  int v9; // eax
  int v10; // ebx
  _DWORD v12[2]; // [esp+8h] [ebp-14h] BYREF
  _DWORD *v13; // [esp+10h] [ebp-Ch]
  int v14; // [esp+14h] [ebp-8h]
  _DWORD *v15; // [esp+18h] [ebp-4h] BYREF

  v15 = 0;
  v5 = (_DWORD *)sub_4891A0(&v15, a5);
  if ( !v5 || !v15 )
    return 0;
  result = sub_638230(v12);
  if ( !result )
  {
    v7 = v15;
    v8 = (char *)(v12[0] + *v5);
    v9 = *v15;
    v10 = v15[1];
    v13 = v15;
    v14 = v9;
    if ( v10 )
    {
      do
      {
        memcpy(a1, v8, Size);
        a1 += a2;
        v8 += v14;
        --v10;
      }
      while ( v10 );
      v7 = v13;
    }
    result = sub_564C10(v7[4], v12);
    if ( !result )
    {
      *((_BYTE *)v7 + 20) = 0;
      return 0;
    }
  }
  return result;
}


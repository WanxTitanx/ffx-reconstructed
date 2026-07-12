// Function: sub_803530
// Address: 0x803530
void sub_803530()
{
  int *v0; // eax
  int n8; // edx
  int v2; // ebx
  int v3; // esi
  int v4; // edi
  int v5; // eax
  int v6; // [esp+0h] [ebp-10h]
  int n8_1; // [esp+4h] [ebp-Ch]
  int *v8; // [esp+8h] [ebp-8h]
  int v9; // [esp+Ch] [ebp-4h]

  if ( unk_11A004A )
  {
    v0 = (int *)&unk_11A11C0;
    n8 = 8;
    v8 = (int *)&unk_11A11C0;
    n8_1 = 8;
    do
    {
      v2 = *v0;
      if ( *v0 )
      {
        v6 = v0[1];
        v3 = v6 + 16;
        v9 = 0;
        if ( *(_WORD *)(v6 + 4) )
        {
          do
          {
            v4 = unknown_libname_741(*(_DWORD *)v3);
            *(_DWORD *)(v4 + 8) = sub_82AE90(v2, *(unsigned __int16 *)(v3 + 10)) - v4;
            *(_DWORD *)(v4 + 12) = sub_82AE70(v2, *(unsigned __int16 *)(v3 + 10)) - v4;
            v5 = sub_830580(v2, *(unsigned __int16 *)(v3 + 10), 0);
            *(_DWORD *)(v3 + 4) = unknown_libname_742(v5);
            v3 += 16;
            ++v9;
          }
          while ( v9 < *(unsigned __int16 *)(v6 + 4) );
          v0 = v8;
          n8 = n8_1;
        }
      }
      v0 += 4;
      --n8;
      v8 = v0;
      n8_1 = n8;
    }
    while ( n8 );
  }
}

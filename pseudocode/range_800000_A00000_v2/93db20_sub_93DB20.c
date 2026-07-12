// Function: sub_93DB20
// Address: 0x93db20
int __cdecl sub_93DB20(int a1, int a2)
{
  int v2; // eax
  int v3; // edi
  int v4; // ebx
  int v5; // esi
  int v7; // [esp+0h] [ebp-14h]
  int v8; // [esp+Ch] [ebp-8h]
  int v9; // [esp+10h] [ebp-4h] BYREF

  v2 = *(_DWORD *)(a2 + 329028);
  v3 = 0;
  v4 = 0;
  v5 = 0;
  v9 = -1;
  v8 = v2;
  if ( v2 >= 0 )
  {
    nullsub_34();
    v9 = -1;
    sub_62FA50(v8, 1, &v9, "Sync\n");
    while ( v9 )
    {
      if ( !v4 )
      {
        v4 = 1;
        nullsub_34();
      }
      sub_77DB90();
      ++v5;
      if ( a1 )
      {
        if ( !v3 )
        {
          v3 = 1;
          sub_77B260(a2);
        }
        sub_77D6D0();
        j_FFX_Btl_Nullsub_Return0();
      }
      v9 = -1;
      sub_62FA50(v8, 1, &v9, v7);
    }
    nullsub_34();
    return v9;
  }
  else
  {
    nullsub_34();
    return 0;
  }
}

// Function: sub_936340
// Address: 0x936340
void __cdecl sub_936340(int a1)
{
  int v1; // edi
  int v2; // edx
  int v3; // ecx
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // eax
  int v8; // [esp-10h] [ebp-18h]
  int v9; // [esp+4h] [ebp-4h]

  v1 = unk_1B0003C;
  if ( unk_1B0003C )
  {
    v2 = unk_193C0F0;
    v3 = *(_DWORD *)(unk_193C0F0 + 2336);
    v9 = *(_DWORD *)(unk_193C0F0 + 4 * *(_DWORD *)(unk_193C0F0 + 2224) + 2096);
    if ( v3 )
      v4 = 1 << (v3 + 3);
    else
      v4 = 0;
    if ( *(_DWORD *)(unk_193C0F0 + 2228) )
    {
      v8 = *(_DWORD *)(unk_193C0F0 + 2256);
      v6 = sub_92E1C0(*(_DWORD *)(unk_193C0F0 + 4 * *(_DWORD *)(unk_193C0F0 + 2224) + 2096));
      v7 = sub_8356E0(v6, v8, 0);
      v2 = unk_193C0F0;
      v5 = v7;
    }
    else
    {
      v5 = *(_DWORD *)(unk_193C0F0 + 2244);
    }
    sub_9253A0(v1, *(_DWORD *)(v2 + 2324), *(_DWORD *)(v2 + 2328), v9, v5, v2 + 2340, v2 + 2356, v2 + 2372, v4, a1);
  }
}

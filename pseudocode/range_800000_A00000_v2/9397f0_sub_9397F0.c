// Function: sub_9397F0
// Address: 0x9397f0
int __cdecl sub_9397F0(int a1, int a2)
{
  int v2; // esi
  int v3; // esi
  int v4; // edi
  int v5; // esi
  size_t Size; // [esp+10h] [ebp-2Ch]
  _DWORD v8[4]; // [esp+18h] [ebp-24h] BYREF
  int v9; // [esp+28h] [ebp-14h] BYREF
  int v10; // [esp+2Ch] [ebp-10h]
  int v11; // [esp+30h] [ebp-Ch]
  int v12; // [esp+34h] [ebp-8h]

  memset(v8, 0, sizeof(v8));
  v2 = sub_9396A0(a1);
  Size = sub_92B2C0(v2);
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v12 = 0;
  v9 = *(_DWORD *)std::_Get_future_error_what(2);
  v10 = (int)(Size + v2) / 16;
  sub_62FF70(a2, &v9);
  v3 = a1;
  sub_62FF70(a2, a1 + 4);
  sub_62FF70(a2, v8);
  v4 = 0;
  if ( *(int *)(a1 + 4) > 0 )
  {
    v5 = 0;
    do
    {
      sub_938D20((_DWORD *)(v5 + *(_DWORD *)(a1 + 8)), a2);
      ++v4;
      v5 += 192;
    }
    while ( v4 < *(_DWORD *)(a1 + 4) );
    v3 = a1;
  }
  sub_62FF70(a2, v3 + 104);
  sub_62FF70(a2, v3 + 120);
  sub_62FF70(a2, v3 + 136);
  sub_62FF70(a2, v3 + 168);
  sub_62FF70(a2, v3 + 100);
  memset(&v9, 0, Size);
  return sub_62FF70(a2, &v9);
}

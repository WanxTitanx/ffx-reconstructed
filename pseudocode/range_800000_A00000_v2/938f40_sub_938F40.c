// Function: sub_938F40
// Address: 0x938f40
int __cdecl sub_938F40(char a1, int a2)
{
  size_t Size; // edi
  const char *future_error_what; // eax
  int v4; // esi
  int v6; // [esp+8h] [ebp-14h] BYREF
  int v7; // [esp+Ch] [ebp-10h]
  int v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]

  Size = sub_92B2C0(4);
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v9 = 0;
  future_error_what = std::_Get_future_error_what(1);
  v4 = a2;
  v6 = *(_DWORD *)future_error_what;
  v7 = (int)(Size + 4) / 16;
  sub_62FF70(a2, &v6);
  sub_62FF70(v4, &a1);
  memset(&v6, 0, Size);
  return sub_62FF70(v4, &v6);
}

// Function: sub_938D20
// Address: 0x938d20
int __cdecl sub_938D20(_DWORD *a1, int a2)
{
  int v2; // ebx
  _DWORD v4[4]; // [esp+Ch] [ebp-14h] BYREF

  memset(v4, 0, sizeof(v4));
  sub_62FF70(a2, a1);
  sub_62FF70(a2, a1 + 38);
  sub_62FF70(a2, v4);
  if ( (int)a1[38] > 0 )
  {
    sub_62FF70(a2, a1[39]);
    if ( ((4 * (unsigned __int8)a1[38]) & 0xF) != 0 )
      sub_62FF70(a2, v4);
    sub_939950(a1[40], a2);
  }
  sub_62FF70(a2, (char *)a1 + 186);
  sub_62FF70(a2, (char *)a1 + 187);
  sub_62FF70(a2, v4);
  v2 = a1[47];
  sub_62FF70(a2, v2 + 24);
  sub_62FF70(a2, v2 + 32);
  sub_62FF70(a2, v2 + 40);
  sub_62FF70(a2, v2 + 48);
  sub_62FF70(a2, v2 + 52);
  return sub_62FF70(a2, *(_DWORD *)(v2 + 56));
}

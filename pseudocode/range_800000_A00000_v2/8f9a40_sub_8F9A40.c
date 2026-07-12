// Function: sub_8F9A40
// Address: 0x8f9a40
_DWORD *__cdecl sub_8F9A40(int a1, int a2, int n16, int a4)
{
  int v4; // eax
  int v5; // ebx
  int v7; // [esp+10h] [ebp-4h]

  v4 = sub_8FA4F0(200);
  v5 = *(unsigned __int16 *)(v4 + 10);
  v7 = *(unsigned __int16 *)(v4 + 8);
  if ( n16 >= 16 )
  {
    sub_903B70(200, a1, a2, 0, 0, unk_25D16B4, unk_25D16B4);
    sub_903B70(201, a1 + v7, a2, n16 - v7, 0, unk_25D16B4, unk_25D16B0);
    sub_903B70(202, a1, v5 + a2, 0, a4 - v5, unk_25D16B4, unk_25D16B4);
    sub_903B70(203, a1 + v7, v5 + a2, n16 - v7, a4 - v5, unk_25D16B4, unk_25D16B0);
  }
  else
  {
    sub_8FA4F0(200);
    nullsub_161(200, a1, a2, n16, v5, unk_25D16B4, unk_25D16B4);
    nullsub_161(202, a1, v5 + a2, n16, a4 - v5, unk_25D16B4, unk_25D16B4);
  }
  return sub_8F3A30();
}

// Function: sub_805350
// Address: 0x805350
int __cdecl sub_805350(_DWORD *a1, int a2, int a3)
{
  int v3; // eax
  int result; // eax
  _BYTE v5[16]; // [esp+4h] [ebp-14h] BYREF

  if ( (a3 & 0x8000) != 0 )
  {
    v3 = sub_8356E0(a2, (unsigned __int8)a3, v5);
    sub_833C00(a2, v3, a1);
    return sub_7E78B0(a1 + 12, a1, v5);
  }
  else
  {
    sub_833C00(a2, a3, a1);
    a1[16] = unk_C8F508[0];
    a1[17] = unk_C8F50C;
    a1[18] = unk_C8F510;
    result = unk_C8F514;
    a1[19] = unk_C8F514;
  }
  return result;
}

// Function: sub_93CC90
// Address: 0x93cc90
int __cdecl sub_93CC90(int a1, int a2, int a3, int a4)
{
  _BYTE v5[16]; // [esp+Ch] [ebp-54h] BYREF
  _BYTE v6[16]; // [esp+1Ch] [ebp-44h] BYREF
  _BYTE v7[16]; // [esp+2Ch] [ebp-34h] BYREF
  _BYTE v8[32]; // [esp+3Ch] [ebp-24h] BYREF

  sub_93D900(v6);
  sub_93D440(v5, a4, a3);
  sub_93D3D0(v6, v5);
  sub_93D3D0(v8, a3);
  sub_93D440(v7, v8, v6);
  sub_93D8A0(v6, v6);
  sub_93D830(v6, v6, a2);
  return sub_93D090(a1, v6);
}

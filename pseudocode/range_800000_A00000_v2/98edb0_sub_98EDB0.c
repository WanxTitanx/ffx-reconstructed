// Function: sub_98EDB0
// Address: 0x98edb0
int __userpurge sub_98EDB0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3, float *a4, float *a5)
{
  bool v5; // zf
  int v7; // [esp-24h] [ebp-30h]
  float v8[4]; // [esp-20h] [ebp-2Ch] BYREF
  float v9[4]; // [esp-10h] [ebp-1Ch] BYREF
  _DWORD v10[3]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v10[0] = a2;
  v10[1] = retaddr;
  v5 = *(_BYTE *)(a1 + 72) == 0;
  v7 = *(_DWORD *)(a1 + 68);
  memset(v9, 0, sizeof(v9));
  memset(v8, 0, sizeof(v8));
  if ( v5 )
    return sub_991A10(a3, a4, a5, v8, v9, 0, v7);
  else
    return sub_990D40(a1, (int)v10, a3, a4, a5, v8, v9, 0, v7);
}

// Function: sub_9BC5E0
// Address: 0x9bc5e0
unsigned int __userpurge sub_9BC5E0@<eax>(int a1@<ecx>, int a2@<ebp>, int a3)
{
  unsigned int result; // eax
  float v4; // [esp+14h] [ebp-60h]
  _BYTE v5[80]; // [esp+18h] [ebp-5Ch] BYREF
  _DWORD v6[3]; // [esp+68h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+74h] [ebp+0h]

  v6[0] = a2;
  v6[1] = retaddr;
  result = (unsigned int)v6 ^ __security_cookie;
  if ( *(_DWORD *)(a3 + 500) )
  {
    if ( (*(_BYTE *)(a3 + 216) & 3) == 0 )
    {
      v4 = *(float *)(a3 + 252) * *(float *)(a1 + 240);
      sub_9A7AC0((int)v6, (float *)(a3 + 80), (float *)(a3 + 144), (float *)(a3 + 160), v4, (int)v5);
      return (*(int (__thiscall **)(_DWORD, _BYTE *))(**(_DWORD **)(a3 + 500) + 8))(*(_DWORD *)(a3 + 500), v5);
    }
  }
  return result;
}

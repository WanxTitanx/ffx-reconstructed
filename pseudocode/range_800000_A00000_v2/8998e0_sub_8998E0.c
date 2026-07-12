// Function: sub_8998E0
// Address: 0x8998e0
int __cdecl sub_8998E0(unsigned __int16 a1)
{
  float *v1; // eax
  _BYTE *v2; // esi
  int v3; // ecx
  char v4; // al
  int v6; // [esp+4h] [ebp-4h] BYREF

  v1 = FFX_Btl_LookupCommandDataById(a1, &v6);
  v2 = (_BYTE *)(v6 + *((unsigned __int16 *)v1 + 4));
  sub_8B9600(0, v2, &unk_133F4F4, &unk_133F4F0, 0, 0);
  memset(&unk_133F4F8, 0, 0x80u);
  v3 = &unk_133F4F8 - (_UNKNOWN *)v2;
  do
  {
    v4 = *v2;
    v2[v3] = *v2;
    ++v2;
  }
  while ( v4 );
  return sub_8B9600(0, &unk_133F4F8, &unk_133F4F4, &unk_133F4F0, 0, 0);
}

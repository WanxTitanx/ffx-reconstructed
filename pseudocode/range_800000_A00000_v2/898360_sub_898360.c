// Function: sub_898360
// Address: 0x898360
int __thiscall sub_898360(void *this)
{
  float *v1; // ecx
  int v2; // eax
  int result; // eax
  void *this_1; // [esp+0h] [ebp-4h] BYREF

  this_1 = this;
  v1 = FFX_Btl_LookupCommandDataById(n255_3, &this_1);
  if ( (*((_BYTE *)v1 + 26) & 0x40) != 0 )
    unk_133D128 = -1;
  unk_133D12C = -1;
  v2 = *(_DWORD *)&word_133D130;
  if ( (*((_WORD *)v1 + 13) & 0x800) != 0 )
  {
    v2 = unk_133D118 | *(_DWORD *)&word_133D130;
    *(_DWORD *)&word_133D130 |= unk_133D118;
  }
  if ( (*((_WORD *)v1 + 13) & 0x400) != 0 )
    *(_DWORD *)&word_133D130 = unk_133D11C | v2;
  unk_133D120 = (*((_BYTE *)v1 + 26) & 2) != 0 ? -1048576 : 0xFFFFF;
  result = -((*((_BYTE *)v1 + 26) & 0x20) != 0);
  LODWORD(unk_133D124) = result;
  return result;
}

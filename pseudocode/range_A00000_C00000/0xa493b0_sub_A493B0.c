// Function: sub_A493B0
// Address: 0xa493b0
// Size: 0x87
// Prototype: 

int __cdecl sub_A493B0(int a1, int a2, int a3)
{
  int result; // eax
  unsigned __int8 v4; // al
  char *EntryByIdRange; // eax
  _DWORD v6[5]; // [esp+0h] [ebp-18h] BYREF
  int v7; // [esp+14h] [ebp-4h] BYREF

  result = FFX_Inventory_GetItemCount(a3);
  if ( result )
  {
    v6[1] = a1;
    v6[3] = 0;
    v6[2] = 1 << a1;
    v4 = FFX_Battle_GetMagicEntryById(a3, &v7)[93];
    if ( v4 == 0xFF )
      EntryByIdRange = 0;
    else
      EntryByIdRange = FFX_Table_GetEntryByIdRange(v4, (__int16 *)unk_1A860E4, &v7);
    v6[0] = EntryByIdRange;
    return sub_A49440(dword_2305834[0] + 40 * a2 + 2056, (int)v6);
  }
  return result;
}


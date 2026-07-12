// Function: sub_A49310
// Address: 0xa49310
// Size: 0x97
// Prototype: 

int __cdecl sub_A49310(int a1, __int16 a2, int a3)
{
  int result; // eax
  unsigned __int8 v4; // al
  char *EntryByIdRange; // eax
  _DWORD v6[3]; // [esp+0h] [ebp-18h] BYREF
  int v7; // [esp+Ch] [ebp-Ch]
  int v8; // [esp+14h] [ebp-4h] BYREF

  result = FFX_Inventory_GetItemCount(a3);
  if ( result )
  {
    v6[1] = a1;
    v7 = 0;
    v6[2] = 1 << a1;
    v4 = FFX_Battle_GetMagicEntryById(a3, &v8)[93];
    if ( v4 == 0xFF )
      EntryByIdRange = 0;
    else
      EntryByIdRange = FFX_Table_GetEntryByIdRange(v4, (__int16 *)unk_1A860E4, &v8);
    v6[0] = EntryByIdRange;
    if ( EntryByIdRange )
    {
      if ( EntryByIdRange[12] == 32 )
      {
        sub_A59710(sub_A49440, v6);
        return v7;
      }
      sub_A59760(a2, sub_A49440, v6);
    }
    return v7;
  }
  return result;
}


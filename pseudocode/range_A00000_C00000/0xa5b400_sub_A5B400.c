// Function: sub_A5B400
// Address: 0xa5b400
// Size: 0x8a
// Prototype: 

int __cdecl sub_A5B400(int a1, unsigned __int16 a2, __int16 a3, char a4)
{
  unsigned __int8 v4; // al
  char *EntryByIdRange; // eax
  _DWORD v7[3]; // [esp+0h] [ebp-14h] BYREF
  int v8; // [esp+Ch] [ebp-8h]
  char v9; // [esp+10h] [ebp-4h]

  v7[1] = a1;
  v8 = 0;
  v7[2] = 1 << a1;
  v9 = a4;
  v4 = FFX_Battle_GetMagicEntryById(a3, &a4)[93];
  if ( v4 == 0xFF )
    EntryByIdRange = 0;
  else
    EntryByIdRange = FFX_Table_GetEntryByIdRange(v4, (__int16 *)unk_1A860E4, &a4);
  v7[0] = EntryByIdRange;
  if ( EntryByIdRange )
  {
    if ( EntryByIdRange[12] == 32 )
    {
      sub_A59710(sub_A5B490, v7);
      return v8;
    }
    sub_A59760(a2, sub_A5B490, v7);
  }
  return v8;
}


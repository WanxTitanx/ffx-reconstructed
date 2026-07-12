// Function: sub_A44D30
// Address: 0xa44d30
// Size: 0x10d
// Prototype: int(void)

int sub_A44D30()
{
  int v0; // ecx
  int v1; // edi
  int result; // eax
  int v3; // esi
  unsigned __int16 v4; // bx
  unsigned __int8 v5; // al
  char *v6; // eax
  _DWORD v7[3]; // [esp+4h] [ebp-24h] BYREF
  int v8; // [esp+10h] [ebp-18h]
  int v9; // [esp+18h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-Ch]
  int v11; // [esp+20h] [ebp-8h] BYREF
  int v12; // [esp+24h] [ebp-4h]

  v0 = unk_2305834;
  v1 = 0;
  v10 = *(unsigned __int16 *)(unk_2305834 + 80 * *(unsigned __int8 *)(unk_2305834 + 71100) + 69836);
  result = 0;
  v9 = unk_1A86108;
  if ( *(__int16 *)(unk_1A86108 + 6686) > 0 )
  {
    v3 = unk_1A86108 + 6724;
    while ( 1 )
    {
      v4 = *(_WORD *)(v3 + 4);
      v12 = *(unsigned __int8 *)(v0 + 71100);
      if ( !FFX_Inventory_GetItemCount(v4) )
        goto LABEL_13;
      v7[1] = v12;
      v8 = 0;
      v7[2] = 1 << v12;
      v5 = FFX_Battle_GetMagicEntryById(v4, &v11)[93];
      v6 = v5 == 0xFF ? 0 : FFX_Table_GetEntryByIdRange(v5, (__int16 *)unk_1A860E4, &v11);
      v7[0] = v6;
      if ( v6 )
      {
        if ( v6[12] == 32 )
          sub_A59710(sub_A49440, v7);
        else
          sub_A59760(v10, sub_A49440, v7);
      }
      if ( v8 )
        *(_BYTE *)v3 = 0;
      else
LABEL_13:
        *(_BYTE *)v3 = 1;
      ++v1;
      result = *(__int16 *)(v9 + 6686);
      v3 += 12;
      if ( v1 >= result )
        break;
      v0 = unk_2305834;
    }
  }
  return result;
}


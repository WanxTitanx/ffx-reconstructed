// Function: sub_80AB60
// Address: 0x80ab60
int __cdecl sub_80AB60(int a1, int a2)
{
  char *v2; // esi
  int result; // eax
  int v4; // eax
  int v5; // [esp+14h] [ebp-424h]
  float v6; // [esp+18h] [ebp-420h]
  float v7; // [esp+18h] [ebp-420h]
  float v8; // [esp+18h] [ebp-420h]
  float v9; // [esp+1Ch] [ebp-41Ch]
  float v10; // [esp+20h] [ebp-418h]
  float v11; // [esp+24h] [ebp-414h]

  v2 = (char *)&unk_12A2280 + 32 * sub_7FE890(a1, 0, 0);
  v5 = *((unsigned __int16 *)v2 + 7);
  v6 = (float)((unsigned __int8)v2[16] * (unsigned int)(unsigned __int8)v2[24]);
  v9 = v6 * 0.00006103515625;
  v7 = (float)((unsigned __int8)v2[17] * (unsigned int)(unsigned __int8)v2[25]);
  v10 = v7 * 0.00006103515625;
  v8 = (float)((unsigned __int8)v2[18] * (unsigned int)(unsigned __int8)v2[26]);
  v11 = 0.00006103515625 * v8;
  result = sub_82B760(a1, v9, v10, v11);
  if ( a2 )
  {
    v4 = sub_795B50(v5, 0);
    if ( v4 )
      sub_82B760(v4, v9, v10, v11);
    result = sub_795B50(v5, 1);
    if ( result )
      return sub_82B760(result, v9, v10, v11);
  }
  return result;
}

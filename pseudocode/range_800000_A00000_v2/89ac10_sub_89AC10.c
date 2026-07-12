// Function: sub_89AC10
// Address: 0x89ac10
int __cdecl sub_89AC10(unsigned __int8 a1, int n254)
{
  int n254_1; // esi
  float *v4; // edi
  int n8; // esi
  int v6; // [esp+4h] [ebp-4h] BYREF

  n254_1 = n254;
  if ( n254 == 254 )
    return 0;
  if ( n254 == 255 )
    return -2;
  v4 = FFX_Btl_LookupCommandDataById(n254, &v6);
  if ( FFX_Btl_CmdState_IsCommandAvailableToActor(a1, n254_1) == 1 )
    return -1;
  if ( FFX_Btl_Ctb_CanActorExecuteCommand(a1, (int)v4, unk_133F0C6) == -1 )
    return -2;
  n8 = *((_BYTE *)v4 + 22) & 0xF8;
  if ( n8 == 8 || n8 == 16 )
  {
    sub_89B510(a1, *((unsigned __int8 *)v4 + 23), &n254);
    if ( n254 )
      return *((unsigned __int8 *)v4 + 23);
    else
      return (n8 != 8) - 4;
  }
  else if ( (*((_BYTE *)v4 + 26) & 1) != 0 )
  {
    return 254;
  }
  else
  {
    return (n256_0 != 256) + 254;
  }
}
